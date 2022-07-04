void CalculateEvents(const char *mctest, const char *typetest, const char *mc, const char *type){
  void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX); 
  char openFile[500];  sprintf(openFile, "test_%s%s_corrector_output_%s_%s.root",mctest,typetest,mc,type);
  char openTree[500];   sprintf(openTree, "Events");
  TFile *file = TFile::Open(openFile);
  TTree *Tree = (TTree*)file->Get(openTree);

  vector<TString> name;         vector<int> bin;   vector<float> Min;  vector<float> Max;  vector<TString> axis;
  name.push_back("Jpsi1_mass"); bin.push_back(30); Min.push_back(2.95); Max.push_back(3.25); axis.push_back("m_{12}[GeV]");
  //name.push_back("Jpsi1_mass"); bin.push_back(30); Min.push_back(2.95); Max.push_back(3.25); axis.push_back("m_{12}[GeV]");
  TH1F* his_total;
  TH1F* his_acc_eta;
  TH1F* his_acc_pt;
  TH1F* his_reco;
  TH1F* his_eff;
  TH1F* his_vtx;
  TH1F* his_HLT;
  TH1F* his_evt;

  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000];
    char Weight[1000];
    char W_evt[1000];
    char W_evt_HLT[1000];
    char W_evt_HLT_vtx[1000];
    char W_evt_HLT_vtx_eff[1000];
    char W_evt_HLT_vtx_eff_reco[1000];
    char W_evt_HLT_vtx_eff_reco_accpt[1000];
    char W_evt_HLT_vtx_eff_reco_accpt_acceta[1000];

    sprintf(CUT,"((Jpsi1_pt>6 && Jpsi1_pt<40 && fabs(Jpsi1_y)<2) && (Jpsi2_pt>6 && Jpsi2_pt<40 && fabs(Jpsi2_y)<2))");
    sprintf(Weight,"1 * %s", CUT);
    sprintf(W_evt,"(1./(w_evt)) * %s",CUT);
    sprintf(W_evt_HLT,"(1./(w_evt * w_HLT)) * %s",CUT);
    sprintf(W_evt_HLT_vtx,"(1./(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2))) * %s",CUT);
    sprintf(W_evt_HLT_vtx_eff,"(1./(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2))) * %s",CUT);
    sprintf(W_evt_HLT_vtx_eff_reco,"(1./(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2))) * %s",CUT);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt,"(1./(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2))) * %s",CUT);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta,"(1./(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2))) * %s",CUT);

    printf("%s",Weight);
    GetHisto(Weight                              ,Tree ,his_evt     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt                               ,Tree ,his_HLT     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT                           ,Tree ,his_vtx     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx                       ,Tree ,his_eff     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff                   ,Tree ,his_reco    ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco              ,Tree ,his_acc_pt  ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco_accpt        ,Tree ,his_acc_eta ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco_accpt_acceta ,Tree ,his_total   ,plot,bin[i],Min[i],Max[i]);
       
    cout<<"Observed event number after 4muon vertex: "<<his_evt->Integral()<<endl;; 
    cout<<"Observed event number after HLT: "         <<his_HLT->Integral()<<endl;; 
    cout<<"Observed event number after vertex: "      <<his_vtx->Integral()<<endl;; 
    cout<<"Observed event number after selection: "   <<his_eff->Integral()<<endl;; 
    cout<<"Observed event number after reconstruction: "<<his_reco->Integral()<<endl;; 
    cout<<"Observed event number after acception pt: "<<his_acc_pt->Integral()<<endl;; 
    cout<<"Observed event number after acception eta: "<<his_acc_eta->Integral()<<endl;; 
    cout<<"Observed total event number: "<<his_total->Integral()<<endl;; 
  }

}




void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX){
  char input[50]; sprintf(input,"%s>>h(%i,%f,%f)",plot,BIN,MIN,MAX);
  TH1F *temp = new TH1F("", "", BIN,MIN,MAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH1F* h=(TH1F*)gDirectory->Get("h"); histo = (TH1F*)h->Clone(); delete h; } else { histo = (TH1F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
} 
