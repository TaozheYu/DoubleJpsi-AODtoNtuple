void Calculate_corrector_v3(const char *mc, const char *type){
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
 
  TH2F *h_w_acc_eta_Jpsi1   = new TH2F("h_w_acc_eta_Jpsi1",  "h_w_acc_eta_Jpsi1", N-1, xbins, M-1, ybins);
  TH2F *h_w_acc_eta_Jpsi2   = new TH2F("h_w_acc_eta_Jpsi2",  "h_w_acc_eta_Jpsi2", N-1, xbins, M-1, ybins);
  TH2F *h_w_acc_pt_Jpsi1   = new TH2F("h_w_acc_pt_Jpsi1",  "h_w_acc_pt_Jpsi1", N-1, xbins, M-1, ybins);
  TH2F *h_w_acc_pt_Jpsi2   = new TH2F("h_w_acc_pt_Jpsi2",  "h_w_acc_pt_Jpsi2", N-1, xbins, M-1, ybins);
  TH2F *h_w_reco_Jpsi1   = new TH2F("h_w_reco_Jpsi1",  "h_w_reco_Jpsi1", N-1, xbins, M-1, ybins);
  TH2F *h_w_reco_Jpsi2   = new TH2F("h_w_reco_Jpsi2",  "h_w_reco_Jpsi2", N-1, xbins, M-1, ybins);
  TH2F *h_w_eff_Jpsi1   = new TH2F("h_w_eff_Jpsi1",  "h_w_eff_Jpsi1", N-1, xbins, M-1, ybins);
  TH2F *h_w_eff_Jpsi2   = new TH2F("h_w_eff_Jpsi2",  "h_w_eff_Jpsi2", N-1, xbins, M-1, ybins);
  TH2F *h_w_vtx_Jpsi1   = new TH2F("h_w_vtx_Jpsi1",  "h_w_vtx_Jpsi1", N-1, xbins, M-1, ybins);
  TH2F *h_w_vtx_Jpsi2   = new TH2F("h_w_vtx_Jpsi2",  "h_w_vtx_Jpsi2", N-1, xbins, M-1, ybins);

  const int pt_bin = 6; Double_t pt_bins[pt_bin] = {6.,9.,12.,15.,25.,40.}; 
  TH2F *h_w_HLT   = new TH2F("h_w_HLT",  "h_w_HLT", pt_bin-1, pt_bins, pt_bin-1, pt_bins);
  TH2F *h_w_evt   = new TH2F("h_w_evt",  "h_w_evt", pt_bin-1, pt_bins, pt_bin-1, pt_bins);


  char openFile[500];  sprintf(openFile, "Gen_Event_%s_%s.root",mc,type);
  TFile *fileJpsi_gen = new TFile(openFile);
  
  TH2F *h_total_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_total_Jpsi1");
  TH2F *h_total_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_total_Jpsi2");
  TH2F *h_acc_eta_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_acc_eta_Jpsi1");
  TH2F *h_acc_eta_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_acc_eta_Jpsi2");
  TH2F *h_acc_pt_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_acc_pt_Jpsi1");
  TH2F *h_acc_pt_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_acc_pt_Jpsi2");
  TH2F *h_reco_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_reco_Jpsi1");
  TH2F *h_reco_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_reco_Jpsi2");
  TH2F *h_eff_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_eff_Jpsi1");
  TH2F *h_eff_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_eff_Jpsi2");
  TH2F *h_vtx_Jpsi1 = (TH2F*) fileJpsi_gen->Get("h_vtx_Jpsi1");
  TH2F *h_vtx_Jpsi2 = (TH2F*) fileJpsi_gen->Get("h_vtx_Jpsi2");
  
  TH2F *h_JpsiPair = (TH2F*) fileJpsi_gen->Get("h_JpsiPair");
  TH2F *h_HLT_JpsiPair = (TH2F*) fileJpsi_gen->Get("h_HLT_JpsiPair");
  TH2F *h_evt_JpsiPair = (TH2F*) fileJpsi_gen->Get("h_evt_JpsiPair");

  cout<<h_total_Jpsi1->GetXaxis()->GetNbins()<<endl;
  cout<<h_total_Jpsi2->GetYaxis()->GetNbins()<<endl;


  for(int i=1; i<h_total_Jpsi1->GetXaxis()->GetNbins()+1; i++){
    for(int j=1; j<h_total_Jpsi1->GetYaxis()->GetNbins()+1; j++){
    
    float N_total_Jpsi1   = h_total_Jpsi1   ->GetBinContent(i,j);
    float N_total_Jpsi2   = h_total_Jpsi2   ->GetBinContent(i,j);
    float N_acc_eta_Jpsi1 = h_acc_eta_Jpsi1 ->GetBinContent(i,j);
    float N_acc_eta_Jpsi2 = h_acc_eta_Jpsi2 ->GetBinContent(i,j);
    float N_acc_pt_Jpsi1  = h_acc_pt_Jpsi1  ->GetBinContent(i,j);
    float N_acc_pt_Jpsi2  = h_acc_pt_Jpsi2  ->GetBinContent(i,j);
    float N_reco_Jpsi1  = h_reco_Jpsi1 ->GetBinContent(i,j);
    float N_reco_Jpsi2  = h_reco_Jpsi2 ->GetBinContent(i,j);
    float N_eff_Jpsi1   = h_eff_Jpsi1  ->GetBinContent(i,j);
    float N_eff_Jpsi2   = h_eff_Jpsi2  ->GetBinContent(i,j);
    float N_vtx_Jpsi1   = h_vtx_Jpsi1  ->GetBinContent(i,j);
    float N_vtx_Jpsi2   = h_vtx_Jpsi2  ->GetBinContent(i,j);

    if (N_total_Jpsi1!=0&&N_acc_pt_Jpsi1!=0&&N_reco_Jpsi1!=0&&N_eff_Jpsi1!=0&&N_vtx_Jpsi1!=0){ 
      float N_total_Jpsi1_err = sqrt(N_total_Jpsi1);
      float N_total_Jpsi2_err = sqrt(N_total_Jpsi2);
      float N_acc_eta_Jpsi1_err = sqrt(N_acc_eta_Jpsi1);
      float N_acc_eta_Jpsi2_err = sqrt(N_acc_eta_Jpsi2);
      float N_acc_pt_Jpsi1_err = sqrt(N_acc_pt_Jpsi1);
      float N_acc_pt_Jpsi2_err = sqrt(N_acc_pt_Jpsi2);
      float N_reco_Jpsi1_err = sqrt(N_reco_Jpsi1);
      float N_reco_Jpsi2_err = sqrt(N_reco_Jpsi2);
      float N_eff_Jpsi1_err = sqrt(N_eff_Jpsi1);
      float N_eff_Jpsi2_err = sqrt(N_eff_Jpsi2);

      float w_acc_eta_Jpsi1 = N_acc_eta_Jpsi1/N_total_Jpsi1;
      float w_acc_eta_Jpsi2 = N_acc_eta_Jpsi2/N_total_Jpsi2;
      float w_acc_pt_Jpsi1 = N_acc_pt_Jpsi1/N_acc_eta_Jpsi1;
      float w_acc_pt_Jpsi2 = N_acc_pt_Jpsi2/N_acc_eta_Jpsi2;
      float w_reco_Jpsi1= N_reco_Jpsi1/N_acc_pt_Jpsi1;
      float w_reco_Jpsi2= N_reco_Jpsi2/N_acc_pt_Jpsi2;
      float w_eff_Jpsi1 = N_eff_Jpsi1/N_reco_Jpsi1;
      float w_eff_Jpsi2 = N_eff_Jpsi2/N_reco_Jpsi2;
      float w_vtx_Jpsi1 = N_vtx_Jpsi1/N_eff_Jpsi1;
      float w_vtx_Jpsi2 = N_vtx_Jpsi2/N_eff_Jpsi2;

      float w_acc_eta_Jpsi1_err = Cal_stat_err(N_acc_eta_Jpsi1,N_total_Jpsi1); 
      float w_acc_eta_Jpsi2_err = Cal_stat_err(N_acc_eta_Jpsi2,N_total_Jpsi2); 
      float w_acc_pt_Jpsi1_err = Cal_stat_err(N_acc_pt_Jpsi1,N_acc_eta_Jpsi1);
      float w_acc_pt_Jpsi2_err = Cal_stat_err(N_acc_pt_Jpsi2,N_acc_eta_Jpsi2);
      float w_reco_Jpsi1_err= Cal_stat_err(N_reco_Jpsi1,N_acc_pt_Jpsi1);
      float w_reco_Jpsi2_err= Cal_stat_err(N_reco_Jpsi2,N_acc_pt_Jpsi2);
      float w_eff_Jpsi1_err = Cal_stat_err(N_eff_Jpsi1,N_reco_Jpsi1);
      float w_eff_Jpsi2_err = Cal_stat_err(N_eff_Jpsi2,N_reco_Jpsi2);
      float w_vtx_Jpsi1_err = Cal_stat_err(N_vtx_Jpsi1,N_eff_Jpsi1);
      float w_vtx_Jpsi2_err = Cal_stat_err(N_vtx_Jpsi2,N_eff_Jpsi2);

      h_w_acc_eta_Jpsi1->SetBinContent(i,j,w_acc_eta_Jpsi1);
      h_w_acc_eta_Jpsi2->SetBinContent(i,j,w_acc_eta_Jpsi2);
      h_w_acc_pt_Jpsi1->SetBinContent(i,j,w_acc_pt_Jpsi1);
      h_w_acc_pt_Jpsi2->SetBinContent(i,j,w_acc_pt_Jpsi2);
      h_w_reco_Jpsi1->SetBinContent(i,j,w_reco_Jpsi1);
      h_w_reco_Jpsi2->SetBinContent(i,j,w_reco_Jpsi2);
      h_w_eff_Jpsi1->SetBinContent(i,j,w_eff_Jpsi1);
      h_w_eff_Jpsi2->SetBinContent(i,j,w_eff_Jpsi2);
      h_w_vtx_Jpsi1->SetBinContent(i,j,w_vtx_Jpsi1);
      h_w_vtx_Jpsi2->SetBinContent(i,j,w_vtx_Jpsi2);

      h_w_acc_eta_Jpsi1->SetBinError(i,j,w_acc_eta_Jpsi1_err);
      h_w_acc_eta_Jpsi2->SetBinError(i,j,w_acc_eta_Jpsi2_err);
      h_w_acc_pt_Jpsi1->SetBinError(i,j,w_acc_pt_Jpsi1_err);
      h_w_acc_pt_Jpsi2->SetBinError(i,j,w_acc_pt_Jpsi2_err);
      h_w_reco_Jpsi1->SetBinError(i,j,w_reco_Jpsi1_err);
      h_w_reco_Jpsi2->SetBinError(i,j,w_reco_Jpsi2_err);
      h_w_eff_Jpsi1->SetBinError(i,j,w_eff_Jpsi1_err);
      h_w_eff_Jpsi2->SetBinError(i,j,w_eff_Jpsi2_err);
      h_w_vtx_Jpsi1->SetBinError(i,j,w_vtx_Jpsi1_err);
      h_w_vtx_Jpsi2->SetBinError(i,j,w_vtx_Jpsi2_err);
      }
    }
  }

  for(int i=1; i<h_HLT_JpsiPair->GetXaxis()->GetNbins()+1; i++){
    for(int j=1; j<h_HLT_JpsiPair->GetYaxis()->GetNbins()+1; j++){
    
    float N_JpsiPair = (h_JpsiPair ->GetBinContent(i,j)+h_JpsiPair ->GetBinContent(j,i))/2;
    float N_HLT_JpsiPair = (h_HLT_JpsiPair ->GetBinContent(i,j)+h_HLT_JpsiPair ->GetBinContent(j,i))/2;
    float N_evt_JpsiPair = (h_evt_JpsiPair ->GetBinContent(i,j)+h_evt_JpsiPair ->GetBinContent(j,i))/2;
 
    //float N_betri = h_betri_Jpsi ->GetBinContent(i,j);
    //float N_patri = h_patri_Jpsi ->GetBinContent(i,j);
 
    if(N_JpsiPair!=0&&N_HLT_JpsiPair!=0&&N_evt_JpsiPair!=0){

     
      float w_HLT = N_HLT_JpsiPair/N_JpsiPair;
      float w_evt = N_evt_JpsiPair/N_HLT_JpsiPair;
      
      float w_HLT_err = Cal_stat_err(N_HLT_JpsiPair,N_JpsiPair);
      float w_evt_err = Cal_stat_err(N_evt_JpsiPair,N_HLT_JpsiPair);    
 
      h_w_HLT->SetBinContent(i,j,w_HLT);
      h_w_evt->SetBinContent(i,j,w_evt);

      h_w_HLT->SetBinError(i,j,w_HLT_err);
      h_w_evt->SetBinError(i,j,w_evt_err);

      }
    } 
  }

  TCanvas* canvas = new TCanvas("canvas","canvas",0,0,1000,600);
  h_w_acc_eta_Jpsi1->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_eta_Jpsi1->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_eta_Jpsi1->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_eta_Jpsi1->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_eta_Jpsi1->SetMinimum(0.6);
  h_w_acc_eta_Jpsi1->SetMaximum(1.0);
  h_w_acc_eta_Jpsi1->SetTitle("Jpsi1 acceptance eta probability");
  h_w_acc_eta_Jpsi1->GetYaxis()->SetTitle("Jpsi1 repidity");
  h_w_acc_eta_Jpsi1->GetXaxis()->SetTitle("Jpsi1 pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_eta_Jpsi1->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta_Jpsi1.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta_Jpsi1.pdf");

  h_w_acc_eta_Jpsi2->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_eta_Jpsi2->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_eta_Jpsi2->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_eta_Jpsi2->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_eta_Jpsi2->SetMinimum(0.6);
  h_w_acc_eta_Jpsi2->SetMaximum(1.0);
  h_w_acc_eta_Jpsi2->SetTitle("Jpsi2 acceptance eta probability");
  h_w_acc_eta_Jpsi2->GetYaxis()->SetTitle("Jpsi2 repidity");
  h_w_acc_eta_Jpsi2->GetXaxis()->SetTitle("Jpsi2 pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_eta_Jpsi2->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta_Jpsi2.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_eta_Jpsi2.pdf");

  h_w_acc_pt_Jpsi1->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_pt_Jpsi1->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_pt_Jpsi1->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_pt_Jpsi1->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_pt_Jpsi1->SetMinimum(0.0);
  h_w_acc_pt_Jpsi1->SetMaximum(0.7);
  h_w_acc_pt_Jpsi1->SetTitle("Jpsi1 acceptance pt probability");
  h_w_acc_pt_Jpsi1->GetYaxis()->SetTitle("Jpsi1 repidity");
  h_w_acc_pt_Jpsi1->GetXaxis()->SetTitle("Jpsi1 pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_pt_Jpsi1->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt_Jpsi1.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt_Jpsi1.pdf");
    
  h_w_acc_pt_Jpsi2->GetYaxis()->SetTitleSize(0.040);
  h_w_acc_pt_Jpsi2->GetXaxis()->SetTitleSize(0.040);
  h_w_acc_pt_Jpsi2->GetYaxis()->SetLabelSize(0.040);
  h_w_acc_pt_Jpsi2->GetXaxis()->SetLabelSize(0.040);
  h_w_acc_pt_Jpsi2->SetMinimum(0.0);
  h_w_acc_pt_Jpsi2->SetMaximum(0.7);
  h_w_acc_pt_Jpsi2->SetTitle("Jpsi2 acceptance pt probability");
  h_w_acc_pt_Jpsi2->GetYaxis()->SetTitle("Jpsi2 repidity");
  h_w_acc_pt_Jpsi2->GetXaxis()->SetTitle("Jpsi2 pt [GeV]");
  //h_w_acc->Draw("COLZ");
  //h_w_acc->Draw("COLZTEXTE");
  h_w_acc_pt_Jpsi2->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt_Jpsi2.png");
  canvas->SaveAs(Mc+"_"+Type+"/acc_pt_Jpsi2.pdf");
    
  h_w_reco_Jpsi1->GetYaxis()->SetTitleSize(0.040);
  h_w_reco_Jpsi1->GetXaxis()->SetTitleSize(0.040);
  h_w_reco_Jpsi1->GetYaxis()->SetLabelSize(0.040);
  h_w_reco_Jpsi1->GetXaxis()->SetLabelSize(0.040);
  h_w_reco_Jpsi1->SetMinimum(0.4);
  h_w_reco_Jpsi1->SetMaximum(1.0);
  h_w_reco_Jpsi1->SetTitle("Jpsi1 reconstruct probability");
  h_w_reco_Jpsi1->GetYaxis()->SetTitle("Jpsi1 rapidity");
  h_w_reco_Jpsi1->GetXaxis()->SetTitle("Jpsi1 pt [GeV]");
  //h_w_reco->Draw("COLZ");
  //h_w_reco->Draw("COLZTEXTE");
  h_w_reco_Jpsi1->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/reco_Jpsi1.png");
  canvas->SaveAs(Mc+"_"+Type+"/reco_Jpsi1.pdf");

  h_w_reco_Jpsi2->GetYaxis()->SetTitleSize(0.040);
  h_w_reco_Jpsi2->GetXaxis()->SetTitleSize(0.040);
  h_w_reco_Jpsi2->GetYaxis()->SetLabelSize(0.040);
  h_w_reco_Jpsi2->GetXaxis()->SetLabelSize(0.040);
  h_w_reco_Jpsi2->SetMinimum(0.4);
  h_w_reco_Jpsi2->SetMaximum(1.0);
  h_w_reco_Jpsi2->SetTitle("Jpsi2 reconstruct probability");
  h_w_reco_Jpsi2->GetYaxis()->SetTitle("Jpsi2 rapidity");
  h_w_reco_Jpsi2->GetXaxis()->SetTitle("Jpsi2 pt [GeV]");
  //h_w_reco->Draw("COLZ");
  //h_w_reco->Draw("COLZTEXTE");
  h_w_reco_Jpsi2->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/reco_Jpsi2.png");
  canvas->SaveAs(Mc+"_"+Type+"/reco_Jpsi2.pdf");

  h_w_eff_Jpsi1->GetYaxis()->SetTitleSize(0.040);
  h_w_eff_Jpsi1->GetXaxis()->SetTitleSize(0.040);
  h_w_eff_Jpsi1->GetYaxis()->SetLabelSize(0.040);
  h_w_eff_Jpsi1->GetXaxis()->SetLabelSize(0.040);
  h_w_eff_Jpsi1->SetMinimum(0.4);
  h_w_eff_Jpsi1->SetMaximum(1.0);
  h_w_eff_Jpsi1->SetTitle("Jpsi1 selection probability");
  h_w_eff_Jpsi1->GetYaxis()->SetTitle("Jpsi1 rapidity");
  h_w_eff_Jpsi1->GetXaxis()->SetTitle("Jpsi1 pt [GeV]");
  //h_w_eff->Draw("COLZ");
  //h_w_eff->Draw("COLZTEXTE");
  h_w_eff_Jpsi1->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/eff_Jpsi1.png");
  canvas->SaveAs(Mc+"_"+Type+"/eff_Jpsi1.pdf");

  h_w_eff_Jpsi2->GetYaxis()->SetTitleSize(0.040);
  h_w_eff_Jpsi2->GetXaxis()->SetTitleSize(0.040);
  h_w_eff_Jpsi2->GetYaxis()->SetLabelSize(0.040);
  h_w_eff_Jpsi2->GetXaxis()->SetLabelSize(0.040);
  h_w_eff_Jpsi2->SetMinimum(0.4);
  h_w_eff_Jpsi2->SetMaximum(1.0);
  h_w_eff_Jpsi2->SetTitle("Jpsi2 selection probability");
  h_w_eff_Jpsi2->GetYaxis()->SetTitle("Jpsi2 rapidity");
  h_w_eff_Jpsi2->GetXaxis()->SetTitle("Jpsi2 pt [GeV]");
  //h_w_eff->Draw("COLZ");
  //h_w_eff->Draw("COLZTEXTE");
  h_w_eff_Jpsi2->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/eff_Jpsi2.png");
  canvas->SaveAs(Mc+"_"+Type+"/eff_Jpsi2.pdf");

  h_w_vtx_Jpsi1->GetYaxis()->SetTitleSize(0.040);
  h_w_vtx_Jpsi1->GetXaxis()->SetTitleSize(0.040);
  h_w_vtx_Jpsi1->GetYaxis()->SetLabelSize(0.040);
  h_w_vtx_Jpsi1->GetXaxis()->SetLabelSize(0.040);
  h_w_vtx_Jpsi1->SetMinimum(0.4);
  h_w_vtx_Jpsi1->SetMaximum(1.0);
  h_w_vtx_Jpsi1->SetTitle("Jpsi1 vertex probability");
  h_w_vtx_Jpsi1->GetYaxis()->SetTitle("Jpsi1 rapidity");
  h_w_vtx_Jpsi1->GetXaxis()->SetTitle("Jpsi1 pt [GeV]");
  //h_w_vtx->Draw("COLZ");
  //h_w_vtx->Draw("COLZTEXTE");
  h_w_vtx_Jpsi1->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/vtx_Jpsi1.png");
  canvas->SaveAs(Mc+"_"+Type+"/vtx_Jpsi1.pdf");

  h_w_vtx_Jpsi2->GetYaxis()->SetTitleSize(0.040);
  h_w_vtx_Jpsi2->GetXaxis()->SetTitleSize(0.040);
  h_w_vtx_Jpsi2->GetYaxis()->SetLabelSize(0.040);
  h_w_vtx_Jpsi2->GetXaxis()->SetLabelSize(0.040);
  h_w_vtx_Jpsi2->SetMinimum(0.4);
  h_w_vtx_Jpsi2->SetMaximum(1.0);
  h_w_vtx_Jpsi2->SetTitle("Jpsi2 vertex probability");
  h_w_vtx_Jpsi2->GetYaxis()->SetTitle("Jpsi2 rapidity");
  h_w_vtx_Jpsi2->GetXaxis()->SetTitle("Jpsi2 pt [GeV]");
  //h_w_vtx->Draw("COLZ");
  //h_w_vtx->Draw("COLZTEXTE");
  h_w_vtx_Jpsi2->Draw("COLZTEXT");
  canvas->Draw();
  canvas->SaveAs(Mc+"_"+Type+"/vtx_Jpsi2.png");
  canvas->SaveAs(Mc+"_"+Type+"/vtx_Jpsi2.pdf");

  TCanvas* canvas2 = new TCanvas("canvas","canvas",0,0,600,600);
  h_w_HLT->GetYaxis()->SetTitleSize(0.040);
  h_w_HLT->GetXaxis()->SetTitleSize(0.040);
  h_w_HLT->GetYaxis()->SetLabelSize(0.040);
  h_w_HLT->GetXaxis()->SetLabelSize(0.040);
  h_w_HLT->SetMinimum(0.);
  h_w_HLT->SetMaximum(1.0);
  h_w_HLT->SetTitle("pass HLT probability");
  h_w_HLT->GetYaxis()->SetTitle("Jpsi pt [GeV]");
  h_w_HLT->GetXaxis()->SetTitle("Jpsi pt [GeV]");
  //h_w_HLT->Draw("COLZ");
  //h_w_HLT->Draw("COLZTEXTE");
  h_w_HLT->Draw("COLZTEXT");
  canvas2->Draw();
  canvas2->SaveAs(Mc+"_"+Type+"/HLT.png");
  canvas2->SaveAs(Mc+"_"+Type+"/HLT.pdf");

  h_w_evt->GetYaxis()->SetTitleSize(0.040);
  h_w_evt->GetXaxis()->SetTitleSize(0.040);
  h_w_evt->GetYaxis()->SetLabelSize(0.040);
  h_w_evt->GetXaxis()->SetLabelSize(0.040);
  h_w_evt->SetMinimum(0.);
  h_w_evt->SetMaximum(1.0);
  h_w_evt->SetTitle(" pass evt probability");
  h_w_evt->GetYaxis()->SetTitle("Jpsi pt [GeV]");
  h_w_evt->GetXaxis()->SetTitle("Jpsi pt [GeV]");
  //h_w_evt->Draw("COLZ");
  //h_w_evt->Draw("COLZTEXTE");
  h_w_evt->Draw("COLZTEXT");
  canvas2->Draw();
  canvas2->SaveAs(Mc+"_"+Type+"/evt.png");
  canvas2->SaveAs(Mc+"_"+Type+"/evt.pdf");

  char NewFileName[500]; sprintf(NewFileName, "corrector_%s_%s.root", mc,type);
  TFile f(NewFileName,"new");
  h_w_acc_eta_Jpsi1->Write();
  h_w_acc_eta_Jpsi2->Write();
  h_w_acc_pt_Jpsi1->Write();
  h_w_acc_pt_Jpsi2->Write();
  h_w_reco_Jpsi1->Write();
  h_w_reco_Jpsi2->Write();
  h_w_eff_Jpsi1->Write();
  h_w_eff_Jpsi2->Write();
  h_w_vtx_Jpsi1->Write();
  h_w_vtx_Jpsi2->Write();
  h_w_HLT->Write();
  h_w_evt->Write();
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





