void CalculateEvents(const char *mctest, const char *typetest, const char *mc, const char *type){
  void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX); 
  char openFile[500];  sprintf(openFile, "test_%s%s_corrector_output_%s_%s.root",mctest,typetest,mc,type);
  char openTree[500];   sprintf(openTree, "Events");
  TFile *file = TFile::Open(openFile);
  TTree *Tree = (TTree*)file->Get(openTree);

  vector<TString> name;         vector<int> bin;   vector<float> Min;  vector<float> Max;  vector<TString> axis;
  name.push_back("Jpsi1_pt"); bin.push_back(30); Min.push_back(6); Max.push_back(40); axis.push_back("m_{12}[GeV]");
  //name.push_back("Jpsi1_mass"); bin.push_back(30); Min.push_back(2.8); Max.push_back(3.4); axis.push_back("m_{12}[GeV]");

  TH1F* his_total;
  TH1F* his_acc_eta; TH1F* his_acc_eta_err; //TH1F* his_acc_eta_do; 
  TH1F* his_acc_pt;  TH1F* his_acc_pt_err;  //TH1F* his_acc_pt_do;  
  TH1F* his_reco;    TH1F* his_reco_err;    //TH1F* his_reco_do;   
  TH1F* his_eff;     TH1F* his_eff_err;     //TH1F* his_eff_do;    
  TH1F* his_vtx;     TH1F* his_vtx_err;     //TH1F* his_vtx_do;     
  TH1F* his_HLT;     TH1F* his_HLT_err;     //TH1F* his_HLT_do;       
  TH1F* his_evt;     TH1F* his_evt_err;     //TH1F* his_evt_do;     

  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUT[1000];
    char Weight[1000];
    char W_acceta[1000];                            char W_acceta_err[1000];                            //char W_acceta_do[1000];                                                                
    char W_accpt_acceta[1000];                      char W_accpt_acceta_err[1000];                      //char W_accpt_acceta_do[1000];                       
    char W_reco_accpt_acceta[1000];                 char W_reco_accpt_acceta_err[1000];                 //char W_reco_accpt_acceta_do[1000];                   
    char W_eff_reco_accpt_acceta[1000];             char W_eff_reco_accpt_acceta_err[1000];             //char W_eff_reco_accpt_acceta_do[1000];              
    char W_vtx_eff_reco_accpt_acceta[1000];         char W_vtx_eff_reco_accpt_acceta_err[1000];         //char W_vtx_eff_reco_accpt_acceta_do[1000];            
    char W_HLT_vtx_eff_reco_accpt_acceta[1000];     char W_HLT_vtx_eff_reco_accpt_acceta_err[1000];     //char W_HLT_vtx_eff_reco_accpt_acceta_do[1000];       
    char W_evt_HLT_vtx_eff_reco_accpt_acceta[1000]; char W_evt_HLT_vtx_eff_reco_accpt_acceta_err[1000]; //char W_evt_HLT_vtx_eff_reco_accpt_acceta_do[1000];  

    //add Jpsi pt and rapidity cut
    //sprintf(CUT,"((Jpsi1_pt>6 && Jpsi1_pt<40 && fabs(Jpsi1_y)<2) && (Jpsi2_pt>6 && Jpsi2_pt<40 && fabs(Jpsi2_y)<2))");
    sprintf(CUT,"1");

    //multify each weight
    /*
    sprintf(Weight,"1 * %s", CUT);
    sprintf(W_acceta,"((w_acc_eta_Jpsi1*w_acc_eta_Jpsi2))* %s",CUT);
    sprintf(W_accpt_acceta,"((w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2)) * %s",CUT);
    sprintf(W_reco_accpt_acceta,"((w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2)) * %s",CUT);
    sprintf(W_eff_reco_accpt_acceta,"((w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2)) * %s",CUT);
    sprintf(W_vtx_eff_reco_accpt_acceta,"((w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2))* %s",CUT);
    sprintf(W_HLT_vtx_eff_reco_accpt_acceta,"(w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2)) * %s",CUT);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta,"(w_evt * w_HLT * (w_vtx_Jpsi1*w_vtx_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_acc_pt_Jpsi1*w_acc_pt_Jpsi2) * (w_acc_eta_Jpsi1*w_acc_eta_Jpsi2)) * %s",CUT);
   
 
    sprintf(W_acceta_up,"((w_acc_eta_Jpsi1 + w_acc_eta_Jpsi1_err) * (w_acc_eta_Jpsi2 + w_acc_eta_Jpsi2_err))* %s",CUT);
    sprintf(W_accpt_acceta_up,"((w_acc_pt_Jpsi1 + w_acc_pt_Jpsi1_err) * (w_acc_pt_Jpsi2 + w_acc_pt_Jpsi2_err)) * %s",W_acceta_up);
    sprintf(W_reco_accpt_acceta_up,"((w_reco_Jpsi1 + w_reco_Jpsi1_err) * (w_reco_Jpsi2 + w_reco_Jpsi2_err)) * %s",W_accpt_acceta_up);
    sprintf(W_eff_reco_accpt_acceta_up,"((w_eff_Jpsi1 + w_eff_Jpsi1_err) * (w_eff_Jpsi2 + w_eff_Jpsi2_err))* %s",W_reco_accpt_acceta_up);
    sprintf(W_vtx_eff_reco_accpt_acceta_up,"((w_vtx_Jpsi1 + w_vtx_Jpsi1_err) * (w_vtx_Jpsi2 + w_vtx_Jpsi2_err))* %s",W_eff_reco_accpt_acceta_up);
    sprintf(W_HLT_vtx_eff_reco_accpt_acceta_up,"(w_HLT + w_HLT_err) * %s",W_vtx_eff_reco_accpt_acceta_up);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta_up,"(w_evt+w_evt_err)  * %s",W_HLT_vtx_eff_reco_accpt_acceta_up);

    sprintf(W_acceta_do,"((w_acc_eta_Jpsi1 - w_acc_eta_Jpsi1_err) * (w_acc_eta_Jpsi2 - w_acc_eta_Jpsi2_err))* %s",CUT);
    sprintf(W_accpt_acceta_do,"((w_acc_pt_Jpsi1 - w_acc_pt_Jpsi1_err) * (w_acc_pt_Jpsi2 - w_acc_pt_Jpsi2_err)) * %s",W_acceta_do);
    sprintf(W_reco_accpt_acceta_do,"((w_reco_Jpsi1 - w_reco_Jpsi1_err) * (w_reco_Jpsi2 - w_reco_Jpsi2_err)) * %s",W_accpt_acceta_do);
    sprintf(W_eff_reco_accpt_acceta_do,"((w_eff_Jpsi1 - w_eff_Jpsi1_err) * (w_eff_Jpsi2 - w_eff_Jpsi2_err))* %s",W_reco_accpt_acceta_do);
    sprintf(W_vtx_eff_reco_accpt_acceta_do,"((w_vtx_Jpsi1 - w_vtx_Jpsi1_err) * (w_vtx_Jpsi2 - w_vtx_Jpsi2_err))* %s",W_eff_reco_accpt_acceta_do);
    sprintf(W_HLT_vtx_eff_reco_accpt_acceta_do,"(w_HLT - w_HLT_err) * %s",W_vtx_eff_reco_accpt_acceta_do);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta_do,"(w_evt - w_evt_err)  * %s",W_HLT_vtx_eff_reco_accpt_acceta_do);
    */ 
    //calculate each weight and its error //use error propagation fomular
    //add cut
    sprintf(Weight,"1 * %s", CUT);
    sprintf(W_acceta                           ,"w_acceta* %s"                            ,CUT);
    sprintf(W_accpt_acceta                     ,"w_acceta_accpt * %s"                     ,CUT);
    sprintf(W_reco_accpt_acceta                ,"w_acceta_accpt_reco * %s"                ,CUT);
    sprintf(W_eff_reco_accpt_acceta            ,"w_acceta_accpt_reco_eff * %s"            ,CUT);
    sprintf(W_vtx_eff_reco_accpt_acceta        ,"w_acceta_accpt_reco_eff_vtx * %s"        ,CUT);
    sprintf(W_HLT_vtx_eff_reco_accpt_acceta    ,"w_acceta_accpt_reco_eff_vtx_HLT * %s"    ,CUT);
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta,"w_acceta_accpt_reco_eff_vtx_HLT_evt * %s",CUT);
    
    sprintf(W_acceta_err                           ,"w_acceta_err * %s",CUT); 
    sprintf(W_accpt_acceta_err                     ,"w_acceta_accpt_err * %s",CUT); 
    sprintf(W_reco_accpt_acceta_err                ,"w_acceta_accpt_reco_err * %s",CUT); 
    sprintf(W_eff_reco_accpt_acceta_err            ,"w_acceta_accpt_reco_eff_err * %s",CUT); 
    sprintf(W_vtx_eff_reco_accpt_acceta_err        ,"w_acceta_accpt_reco_eff_vtx_err * %s",CUT); 
    sprintf(W_HLT_vtx_eff_reco_accpt_acceta_err    ,"w_acceta_accpt_reco_eff_vtx_HLT_err * %s",CUT); 
    sprintf(W_evt_HLT_vtx_eff_reco_accpt_acceta_err,"w_acceta_accpt_reco_eff_vtx_HLT_evt_err * %s",CUT); 
     
       
    //cout<<Weight<<endl; 
    //printf("%s",Weight);
    GetHisto(Weight                              ,Tree ,his_total   ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_acceta                            ,Tree ,his_acc_eta ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_accpt_acceta                      ,Tree ,his_acc_pt  ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_reco_accpt_acceta                 ,Tree ,his_reco    ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_eff_reco_accpt_acceta             ,Tree ,his_eff     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_vtx_eff_reco_accpt_acceta         ,Tree ,his_vtx     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_HLT_vtx_eff_reco_accpt_acceta     ,Tree ,his_HLT     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco_accpt_acceta ,Tree ,his_evt     ,plot,bin[i],Min[i],Max[i]);

    GetHisto(W_acceta_err                            ,Tree ,his_acc_eta_err ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_accpt_acceta_err                      ,Tree ,his_acc_pt_err  ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_reco_accpt_acceta_err                 ,Tree ,his_reco_err    ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_eff_reco_accpt_acceta_err             ,Tree ,his_eff_err     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_vtx_eff_reco_accpt_acceta_err         ,Tree ,his_vtx_err     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_HLT_vtx_eff_reco_accpt_acceta_err     ,Tree ,his_HLT_err     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco_accpt_acceta_err ,Tree ,his_evt_err     ,plot,bin[i],Min[i],Max[i]);
    /*
    GetHisto(W_acceta_do                            ,Tree ,his_acc_eta_do ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_accpt_acceta_do                      ,Tree ,his_acc_pt_do  ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_reco_accpt_acceta_do                 ,Tree ,his_reco_do    ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_eff_reco_accpt_acceta_do             ,Tree ,his_eff_do     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_vtx_eff_reco_accpt_acceta_do         ,Tree ,his_vtx_do     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_HLT_vtx_eff_reco_accpt_acceta_do     ,Tree ,his_HLT_do     ,plot,bin[i],Min[i],Max[i]);
    GetHisto(W_evt_HLT_vtx_eff_reco_accpt_acceta_do ,Tree ,his_evt_do     ,plot,bin[i],Min[i],Max[i]);
    */
    /*
    cout<<"Observed event number after 4muon vertex: "<<his_evt->Integral()<<" + "<<his_evt_up->Integral()-his_evt->Integral()<<" - "<<his_evt->Integral()-his_evt_do->Integral()<<endl; 
    cout<<"Observed event number after HLT: "         <<his_HLT->Integral()<<" + "<<his_HLT_up->Integral()-his_HLT->Integral()<<" - "<<his_HLT->Integral()-his_HLT_do->Integral()<<endl; 
    cout<<"Observed event number after vertex: "      <<his_vtx->Integral()<<" + "<<his_vtx_up->Integral()-his_vtx->Integral()<<" - "<<his_vtx->Integral()-his_vtx_do->Integral()<<endl; 
    cout<<"Observed event number after selection: "   <<his_eff->Integral()<<" + "<<his_eff_up->Integral()-his_eff->Integral()<<" - "<<his_eff->Integral()-his_eff_do->Integral()<<endl; 
    cout<<"Observed event number after reconstruction: "<<his_reco->Integral()   <<" + "<<his_reco_up->Integral()-   his_reco->Integral()   <<" - "<<his_reco->Integral()-   his_reco_do->Integral()   <<endl;
    cout<<"Observed event number after acception pt: "  <<his_acc_pt->Integral() <<" + "<<his_acc_pt_up->Integral()- his_acc_pt->Integral() <<" - "<<his_acc_pt->Integral()- his_acc_pt_do->Integral() <<endl; 
    cout<<"Observed event number after acception eta: " <<his_acc_eta->Integral()<<" + "<<his_acc_eta_up->Integral()-his_acc_eta->Integral()<<" - "<<his_acc_eta->Integral()-his_acc_eta_do->Integral()<<endl; 
    cout<<"Observed total event number: "<<his_total->Integral()<<endl;
    */
    cout<<"Observed event number after 4muon vertex: "<<his_evt->Integral()<<" +- "<<his_evt_err->Integral()<<endl; 
    cout<<"Observed event number after HLT: "         <<his_HLT->Integral()<<" +- "<<his_HLT_err->Integral()<<endl; 
    cout<<"Observed event number after vertex: "      <<his_vtx->Integral()<<" +- "<<his_vtx_err->Integral()<<endl; 
    cout<<"Observed event number after selection: "   <<his_eff->Integral()<<" +- "<<his_eff_err->Integral()<<endl; 
    cout<<"Observed event number after reconstruction: "<<his_reco->Integral()   <<" +- "<<his_reco_err->Integral()   <<endl;
    cout<<"Observed event number after acception pt: "  <<his_acc_pt->Integral() <<" +- "<<his_acc_pt_err->Integral() <<endl; 
    cout<<"Observed event number after acception eta: " <<his_acc_eta->Integral()<<" +- "<<his_acc_eta_err->Integral()<<endl; 
    cout<<"Observed total event number: "<<his_total->Integral()<<endl;
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
