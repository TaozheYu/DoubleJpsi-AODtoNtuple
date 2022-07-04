void Calculate_corrector_genonly(const char *mc, const char *type){
  //gROOT->Reset();
  //gStyle->SetCanvasColor(0);
  //gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPaintTextFormat("2.2f");
  //gStyle->SetOptStat("M");
  //gStyle->SetPalette(1,0);
  //gStyle->SetPaintTextFormat(".2f");
  //gErrorIgnoreLevel = kError;
  using namespace std;
  TString Mc = mc; TString Type=type;

 
  float Cal_stat_err(float N_num, float N_den);
  const int N = 10;  Double_t xbins[N] = {6.,7.,8.,9.,10.,12.,15.,20.,25.,40.};
  //const int N = 24;  Double_t xbins[N] = {6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,17.,18.,19.,20.,21.,22.,23.,24.,26.,28.,30.,35.,40.};
  const int M = 11;   Double_t ybins[M] = {-2.,-1.75,-1.5,-1.0,-0.5,0,0.5,1.0,1.5,1.75,2.};
 
  TH2F *h_w_acc_eta   = new TH2F("h_w_acc_eta",  "h_w_acc_eta", N-1, xbins, M-1, ybins);
  TH2F *h_w_acc_pt   = new TH2F("h_w_acc_pt",  "h_w_acc_pt", N-1, xbins, M-1, ybins);



  char openFile[500];  sprintf(openFile, "Gen_Event_%s_%s_genonly.root",mc,type);
  TFile *fileJpsi_gen = new TFile(openFile);
  
  TH2F *h_total_Jpsi = (TH2F*) fileJpsi_gen->Get("h_total_Jpsi");
  TH2F *h_acc_eta_Jpsi = (TH2F*) fileJpsi_gen->Get("h_acc_eta_Jpsi");
  TH2F *h_acc_pt_Jpsi = (TH2F*) fileJpsi_gen->Get("h_acc_pt_Jpsi");

  cout<<h_total_Jpsi->GetXaxis()->GetNbins()<<endl;
  cout<<h_total_Jpsi->GetYaxis()->GetNbins()<<endl;


  for(int i=1; i<h_total_Jpsi->GetXaxis()->GetNbins()+1; i++){
    for(int j=1; j<h_total_Jpsi->GetYaxis()->GetNbins()+1; j++){
    
    float N_total   = h_total_Jpsi   ->GetBinContent(i,j);
    float N_acc_eta = h_acc_eta_Jpsi ->GetBinContent(i,j);
    float N_acc_pt  = h_acc_pt_Jpsi  ->GetBinContent(i,j);

    if (N_total!=0&&N_acc_pt){ 
      float N_total_err = sqrt(N_total);
      float N_acc_eta_err = sqrt(N_acc_eta);
      float N_acc_pt_err = sqrt(N_acc_pt);

      float w_acc_eta = N_acc_eta/N_total;
      float w_acc_pt = N_acc_pt/N_acc_eta;

      float w_acc_eta_err = Cal_stat_err(N_acc_eta,N_total); 
      float w_acc_pt_err = Cal_stat_err(N_acc_pt,N_acc_eta);

      h_w_acc_eta->SetBinContent(i,j,w_acc_eta);
      h_w_acc_pt->SetBinContent(i,j,w_acc_pt);

      h_w_acc_eta->SetBinError(i,j,w_acc_eta_err);
      h_w_acc_pt->SetBinError(i,j,w_acc_pt_err);
      }
    }
  }


  TCanvas* canvas = new TCanvas("canvas","canvas",0,0,1000,600);
  h_w_acc_eta->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_eta->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_eta->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_eta->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_eta->SetMinimum(0.6);
  h_w_acc_eta->SetMaximum(1.0);
  h_w_acc_eta->SetTitle("acceptance eta probability");
  h_w_acc_eta->GetYaxis()->SetTitle("Jpsi repidity");
  h_w_acc_eta->GetXaxis()->SetTitle("Jpsi pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_eta->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta.pdf");

  h_w_acc_pt->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_pt->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_pt->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_pt->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_pt->SetMinimum(0.0);
  h_w_acc_pt->SetMaximum(0.7);
  h_w_acc_pt->SetTitle("acceptance pt probability");
  h_w_acc_pt->GetYaxis()->SetTitle("Jpsi repidity");
  h_w_acc_pt->GetXaxis()->SetTitle("Jpsi pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_pt->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt.pdf");
    

  char NewFileName[500]; sprintf(NewFileName, "corrector_%s_%s_genonly.root", mc,type);
  TFile f(NewFileName,"new");
  h_w_acc_eta->Write();
  h_w_acc_pt->Write();
  f.Close();

}

float Cal_stat_err(float N_num, float N_den){
  //value=num/den;
  if (N_num==0||N_den==0) return 0;
  float N_num_err = sqrt(N_num);
  float N_den_err = sqrt(N_den);
  float err = sqrt((N_num_err*N_num_err*N_den*N_den + N_den_err*N_den_err*N_num*N_num)/(N_den*N_den*N_den*N_den));
  return err;
}





