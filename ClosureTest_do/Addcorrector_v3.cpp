#include "Addcorrector.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Addcorrector_v3(const char *mctest, const char *typetest, const char *mc, const char *type){
  //TString Mc = mc; TString Type = type;
  //Read input root file
  char Filecorrector[500]; sprintf(Filecorrector, "corrector_%s_%s.root",mctest,typetest);
  filecorrector = new TFile(Filecorrector);
  h_w_acc_eta_Jpsi1 = (TH2F*) filecorrector->Get("h_w_acc_eta_Jpsi1");
  h_w_acc_eta_Jpsi2 = (TH2F*) filecorrector->Get("h_w_acc_eta_Jpsi2");
  h_w_acc_pt_Jpsi1  = (TH2F*) filecorrector->Get("h_w_acc_pt_Jpsi1");
  h_w_acc_pt_Jpsi2  = (TH2F*) filecorrector->Get("h_w_acc_pt_Jpsi2");
  h_w_reco_Jpsi1    = (TH2F*) filecorrector->Get("h_w_reco_Jpsi1");
  h_w_reco_Jpsi2    = (TH2F*) filecorrector->Get("h_w_reco_Jpsi2");
  h_w_eff_Jpsi1     = (TH2F*) filecorrector->Get("h_w_eff_Jpsi1");
  h_w_eff_Jpsi2     = (TH2F*) filecorrector->Get("h_w_eff_Jpsi2");
  h_w_vtx_Jpsi1     = (TH2F*) filecorrector->Get("h_w_vtx_Jpsi1");
  h_w_vtx_Jpsi2     = (TH2F*) filecorrector->Get("h_w_vtx_Jpsi2");
  h_w_HLT     = (TH2F*) filecorrector->Get("h_w_HLT");
  h_w_evt     = (TH2F*) filecorrector->Get("h_w_evt");

  char openFile[500];   sprintf(openFile, "/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/%sToJJ_13TeV_pythia8_%s.root",mc,type); 
  char openTree[500];   sprintf(openTree, "rootuple/oniaTree");
  TFile *file = TFile::Open(openFile);
  TTree *Tree = (TTree*)file->Get(openTree);
  Init(Tree);
  if (fChain == 0) return;
  Long64_t nentries = fChain->GetEntries();
  //Creat output root file
  char NewFileName[500]; sprintf(NewFileName, "test_%s%s_corrector_output_%s_%s.root",mctest,typetest,mc,type);
  TFile f(NewFileName,"new");
  TTree *NewTree = new TTree("Events","Events");
  SetNewTree(NewTree);
 
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    fChain->GetEntry(jentry);
    initialVal(); 
    if (GENdimu_pt->size()<2) continue;
    if (!(fabs(GENdimu_y->at(0))<2 && fabs(GENdimu_y->at(1))<2)) continue;
    if (!(GENdimu_pt->at(0)>6 && GENdimu_pt->at(0)<40 && GENdimu_pt->at(1)>6 && GENdimu_pt->at(1)<40)) continue; 

    Jpsi1_pt = GENdimu_pt->at(0);
    Jpsi1_y  = GENdimu_y->at(0);
    Jpsi1_mass  = GENdimu_mass->at(0);

    Jpsi2_pt = GENdimu_pt->at(1);
    Jpsi2_y  = GENdimu_y->at(1);
    Jpsi2_mass  = GENdimu_mass->at(1);
    vector<float> Jpsi1_corr_list; vector<float> Jpsi1_corr_list_err; vector<float> Jpsi2_corr_list; vector<float> Jpsi2_corr_list_err; 
    GetCorrector(Jpsi1_corr_list, Jpsi1_corr_list_err, Jpsi2_corr_list, Jpsi2_corr_list_err, Jpsi1_pt, Jpsi1_y, Jpsi2_pt, Jpsi2_y);  
   
    w_acc_eta_Jpsi1 = Jpsi1_corr_list.at(0);
    w_acc_pt_Jpsi1  = Jpsi1_corr_list.at(1);
    w_reco_Jpsi1    = Jpsi1_corr_list.at(2);
    w_eff_Jpsi1     = Jpsi1_corr_list.at(3);
    w_vtx_Jpsi1     = Jpsi1_corr_list.at(4);

    w_acc_eta_Jpsi1_err = Jpsi1_corr_list_err.at(0);
    w_acc_pt_Jpsi1_err  = Jpsi1_corr_list_err.at(1);
    w_reco_Jpsi1_err    = Jpsi1_corr_list_err.at(2);
    w_eff_Jpsi1_err     = Jpsi1_corr_list_err.at(3);
    w_vtx_Jpsi1_err     = Jpsi1_corr_list_err.at(4);

    w_acc_eta_Jpsi2 = Jpsi2_corr_list.at(0);
    w_acc_pt_Jpsi2  = Jpsi2_corr_list.at(1);
    w_reco_Jpsi2    = Jpsi2_corr_list.at(2);
    w_eff_Jpsi2     = Jpsi2_corr_list.at(3);
    w_vtx_Jpsi2     = Jpsi2_corr_list.at(4);
    w_HLT    = Jpsi2_corr_list.at(5);
    w_evt    = Jpsi2_corr_list.at(6);

    w_acc_eta_Jpsi2_err = Jpsi2_corr_list_err.at(0);
    w_acc_pt_Jpsi2_err  = Jpsi2_corr_list_err.at(1);
    w_reco_Jpsi2_err    = Jpsi2_corr_list_err.at(2);
    w_eff_Jpsi2_err     = Jpsi2_corr_list_err.at(3);
    w_vtx_Jpsi2_err     = Jpsi2_corr_list_err.at(4);
    w_HLT_err    = Jpsi2_corr_list_err.at(5);
    w_evt_err    = Jpsi2_corr_list_err.at(6);

    float w_acc_eta = w_acc_eta_Jpsi1 * w_acc_eta_Jpsi2;
    float w_acc_eta_err = CalculateError(w_acc_eta_Jpsi1 ,w_acc_eta_Jpsi2 ,w_acc_eta_Jpsi1_err ,w_acc_eta_Jpsi2_err);
    
    float w_acc_pt  = w_acc_pt_Jpsi1 * w_acc_pt_Jpsi2;
    float w_acc_pt_err = CalculateError(w_acc_pt_Jpsi1 ,w_acc_pt_Jpsi2 ,w_acc_pt_Jpsi1_err ,w_acc_pt_Jpsi2_err);

    float w_reco  = w_reco_Jpsi1 * w_reco_Jpsi2;
    float w_reco_err = CalculateError(w_reco_Jpsi1 ,w_reco_Jpsi2 ,w_reco_Jpsi1_err ,w_reco_Jpsi2_err);

    float w_eff  = w_eff_Jpsi1 * w_eff_Jpsi2;
    float w_eff_err = CalculateError(w_eff_Jpsi1 ,w_eff_Jpsi2 ,w_eff_Jpsi1_err ,w_eff_Jpsi2_err);

    float w_vtx  = w_vtx_Jpsi1 * w_vtx_Jpsi2;
    float w_vtx_err = CalculateError(w_vtx_Jpsi1 ,w_vtx_Jpsi2 ,w_vtx_Jpsi1_err ,w_vtx_Jpsi2_err);

    w_acceta = w_acc_eta;
    w_acceta_err = w_acc_eta_err;

    w_acceta_accpt = w_acc_eta * w_acc_pt;
    w_acceta_accpt_err = CalculateError(w_acc_eta, w_acc_pt, w_acc_eta_err, w_acc_pt_err);

    w_acceta_accpt_reco = w_acceta_accpt * w_reco;
    w_acceta_accpt_reco_err = CalculateError(w_acceta_accpt, w_reco, w_acceta_accpt_err, w_reco_err);

    w_acceta_accpt_reco_eff = w_acceta_accpt_reco * w_eff;
    w_acceta_accpt_reco_eff_err = CalculateError(w_acceta_accpt_reco, w_eff, w_acceta_accpt_reco_err, w_eff_err);

    w_acceta_accpt_reco_eff_vtx =  w_acceta_accpt_reco_eff * w_vtx;
    w_acceta_accpt_reco_eff_vtx_err = CalculateError(w_acceta_accpt_reco_eff, w_vtx, w_acceta_accpt_reco_eff_err, w_vtx_err);

    w_acceta_accpt_reco_eff_vtx_HLT = w_acceta_accpt_reco_eff_vtx * w_HLT;
    w_acceta_accpt_reco_eff_vtx_HLT_err = CalculateError(w_acceta_accpt_reco_eff_vtx, w_HLT, w_acceta_accpt_reco_eff_vtx_err, w_HLT_err);

    w_acceta_accpt_reco_eff_vtx_HLT_evt = w_acceta_accpt_reco_eff_vtx_HLT * w_evt;
    w_acceta_accpt_reco_eff_vtx_HLT_evt_err = CalculateError(w_acceta_accpt_reco_eff_vtx_HLT, w_evt, w_acceta_accpt_reco_eff_vtx_HLT_err, w_evt_err);


    NewTree->Fill();
      
   
  }
  NewTree->Write();
  f.Close();
  cout<<"Job Finish"<<endl;
  
}


void GetCorrector(vector<float> & Jpsi1_corr_list, vector<float> & Jpsi1_corr_list_err, vector<float> & Jpsi2_corr_list, vector<float> & Jpsi2_corr_list_err,  float Jpsi1_pt, float Jpsi1_y, float Jpsi2_pt, float Jpsi2_y){
  if (Jpsi1_pt<40 && Jpsi1_pt>5 && fabs(Jpsi1_y)<2){
    int pt_bin_Jpsi1 = h_w_acc_eta_Jpsi1->GetXaxis()->FindFixBin(Jpsi1_pt);
    int y_bin_Jpsi1 = h_w_acc_eta_Jpsi1->GetYaxis()->FindFixBin(Jpsi1_y);

    float w_acc_eta_Jpsi1 = h_w_acc_eta_Jpsi1->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_acc_pt_Jpsi1 = h_w_acc_pt_Jpsi1->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_reco_Jpsi1 = h_w_reco_Jpsi1->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_eff_Jpsi1 = h_w_eff_Jpsi1->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_vtx_Jpsi1 = h_w_vtx_Jpsi1->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);

    float w_acc_eta_Jpsi1_err = h_w_acc_eta_Jpsi1->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_acc_pt_Jpsi1_err = h_w_acc_pt_Jpsi1->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_reco_Jpsi1_err = h_w_reco_Jpsi1->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_eff_Jpsi1_err = h_w_eff_Jpsi1->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_vtx_Jpsi1_err = h_w_vtx_Jpsi1->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);

    if (w_acc_eta_Jpsi1==0||w_acc_pt_Jpsi1==0||w_reco_Jpsi1==0||w_eff_Jpsi1==0||w_vtx_Jpsi1==0 ){ 
       w_acc_eta_Jpsi1=1;
       w_acc_eta_Jpsi1_err=0;

       w_acc_pt_Jpsi1=1;
       w_acc_pt_Jpsi1_err=0;

       w_reco_Jpsi1=1;
       w_reco_Jpsi1_err=0;

       w_eff_Jpsi1=1;
       w_eff_Jpsi1_err=0;

       w_vtx_Jpsi1=1;
       w_vtx_Jpsi1_err=0;
    }
    Jpsi1_corr_list.push_back(w_acc_eta_Jpsi1);
    Jpsi1_corr_list.push_back(w_acc_pt_Jpsi1);
    Jpsi1_corr_list.push_back(w_reco_Jpsi1);
    Jpsi1_corr_list.push_back(w_eff_Jpsi1);
    Jpsi1_corr_list.push_back(w_vtx_Jpsi1);

    Jpsi1_corr_list_err.push_back(w_acc_eta_Jpsi1_err);
    Jpsi1_corr_list_err.push_back(w_acc_pt_Jpsi1_err);
    Jpsi1_corr_list_err.push_back(w_reco_Jpsi1_err);
    Jpsi1_corr_list_err.push_back(w_eff_Jpsi1_err);
    Jpsi1_corr_list_err.push_back(w_vtx_Jpsi1_err);
  } else{
    Jpsi1_corr_list.push_back(1);
    Jpsi1_corr_list.push_back(1);
    Jpsi1_corr_list.push_back(1);
    Jpsi1_corr_list.push_back(1);
    Jpsi1_corr_list.push_back(1);

    Jpsi1_corr_list_err.push_back(0);
    Jpsi1_corr_list_err.push_back(0);
    Jpsi1_corr_list_err.push_back(0);
    Jpsi1_corr_list_err.push_back(0);
    Jpsi1_corr_list_err.push_back(0);

  }
 
  if (Jpsi2_pt<40 && Jpsi2_pt>5 && fabs(Jpsi2_y)<2){
    int pt_bin_Jpsi2 = h_w_acc_eta_Jpsi2->GetXaxis()->FindFixBin(Jpsi2_pt);
    int y_bin_Jpsi2 = h_w_acc_eta_Jpsi2->GetYaxis()->FindFixBin(Jpsi2_y);

    float w_acc_eta_Jpsi2 = h_w_acc_eta_Jpsi2->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_acc_pt_Jpsi2 = h_w_acc_pt_Jpsi2->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_reco_Jpsi2 = h_w_reco_Jpsi2->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_eff_Jpsi2 = h_w_eff_Jpsi2->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_vtx_Jpsi2 = h_w_vtx_Jpsi2->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);

    float w_acc_eta_Jpsi2_err = h_w_acc_eta_Jpsi2->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_acc_pt_Jpsi2_err = h_w_acc_pt_Jpsi2->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_reco_Jpsi2_err = h_w_reco_Jpsi2->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_eff_Jpsi2_err = h_w_eff_Jpsi2->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_vtx_Jpsi2_err = h_w_vtx_Jpsi2->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);

    if (w_acc_eta_Jpsi2==0||w_acc_pt_Jpsi2==0||w_reco_Jpsi2==0||w_eff_Jpsi2==0||w_vtx_Jpsi2==0 ){ 
       w_acc_eta_Jpsi2=1;
       w_acc_eta_Jpsi2_err=0;

       w_acc_pt_Jpsi2=1;
       w_acc_pt_Jpsi2_err=0;

       w_reco_Jpsi2=1;
       w_reco_Jpsi2_err=0;

       w_eff_Jpsi2=1;
       w_eff_Jpsi2_err=0;

       w_vtx_Jpsi2=1;
       w_vtx_Jpsi2_err=0;
    }
    Jpsi2_corr_list.push_back(w_acc_eta_Jpsi2);
    Jpsi2_corr_list.push_back(w_acc_pt_Jpsi2);
    Jpsi2_corr_list.push_back(w_reco_Jpsi2);
    Jpsi2_corr_list.push_back(w_eff_Jpsi2);
    Jpsi2_corr_list.push_back(w_vtx_Jpsi2);

    Jpsi2_corr_list_err.push_back(w_acc_eta_Jpsi2_err);
    Jpsi2_corr_list_err.push_back(w_acc_pt_Jpsi2_err);
    Jpsi2_corr_list_err.push_back(w_reco_Jpsi2_err);
    Jpsi2_corr_list_err.push_back(w_eff_Jpsi2_err);
    Jpsi2_corr_list_err.push_back(w_vtx_Jpsi2_err);
  } else{
    Jpsi2_corr_list.push_back(1);
    Jpsi2_corr_list.push_back(1);
    Jpsi2_corr_list.push_back(1);
    Jpsi2_corr_list.push_back(1);
    Jpsi2_corr_list.push_back(1);

    Jpsi2_corr_list_err.push_back(0);
    Jpsi2_corr_list_err.push_back(0);
    Jpsi2_corr_list_err.push_back(0);
    Jpsi2_corr_list_err.push_back(0);
    Jpsi2_corr_list_err.push_back(0);
  } 
  if (Jpsi1_pt<40 && Jpsi1_pt>5 && Jpsi2_pt<40 && Jpsi2_pt>5){
    int pt_bin_Jpsi1 = h_w_HLT->GetXaxis()->FindFixBin(Jpsi1_pt);
    int pt_bin_Jpsi2 = h_w_HLT->GetXaxis()->FindFixBin(Jpsi2_pt);
 
    float w_HLT = h_w_HLT->GetBinContent(pt_bin_Jpsi1, pt_bin_Jpsi2);
    float w_evt = h_w_evt->GetBinContent(pt_bin_Jpsi1, pt_bin_Jpsi2);

    float w_HLT_err = h_w_HLT->GetBinError(pt_bin_Jpsi1, pt_bin_Jpsi2);
    float w_evt_err = h_w_evt->GetBinError(pt_bin_Jpsi1, pt_bin_Jpsi2); 
    if (w_HLT==0||w_evt==0){
      w_HLT =1;    
      w_evt =1;    

      w_HLT_err =0;    
      w_evt_err =0;    
    }
    Jpsi2_corr_list.push_back(w_HLT);
    Jpsi2_corr_list.push_back(w_evt);

    Jpsi2_corr_list_err.push_back(w_HLT_err);
    Jpsi2_corr_list_err.push_back(w_evt_err); 
  } else {
    Jpsi2_corr_list.push_back(1);
    Jpsi2_corr_list.push_back(1);

    Jpsi2_corr_list_err.push_back(0);
    Jpsi2_corr_list_err.push_back(0);  
  }
}


float CalculateError(float factor1, float factor2, float factor1_err, float factor2_err){
  float err = sqrt(factor1 * factor1 * factor2_err * factor2_err + factor1_err * factor1_err *factor2 * factor2);
  return err;
}

void SetNewTree(TTree* NewTree){
  NewTree->Branch("Jpsi1_mass",         &Jpsi1_mass,      "Jpsi1_mass/F"      );
  NewTree->Branch("Jpsi1_pt"  ,         &Jpsi1_pt,        "Jpsi1_pt/F"        );
  NewTree->Branch("Jpsi1_y"   ,         &Jpsi1_y,         "Jpsi1_y/F"         );

  NewTree->Branch("Jpsi2_mass",         &Jpsi2_mass,      "Jpsi2_mass/F"      );
  NewTree->Branch("Jpsi2_pt"  ,         &Jpsi2_pt,        "Jpsi2_pt/F"        );
  NewTree->Branch("Jpsi2_y"   ,         &Jpsi2_y,         "Jpsi2_y/F"         );

  NewTree->Branch("w_acc_eta_Jpsi1",    &w_acc_eta_Jpsi1, "w_acc_eta_Jpsi1/F" );
  NewTree->Branch("w_acc_pt_Jpsi1" ,    &w_acc_pt_Jpsi1,  "w_acc_pt_Jpsi1/F"  );
  NewTree->Branch("w_reco_Jpsi1"   ,    &w_reco_Jpsi1,    "w_reco_Jpsi1/F"    );
  NewTree->Branch("w_eff_Jpsi1"    ,    &w_eff_Jpsi1,     "w_eff_Jpsi1/F"     );
  NewTree->Branch("w_vtx_Jpsi1"    ,    &w_vtx_Jpsi1,     "w_vtx_Jpsi1/F"     );

  NewTree->Branch("w_acc_eta_Jpsi1_err",    &w_acc_eta_Jpsi1_err, "w_acc_eta_Jpsi1_err/F" );
  NewTree->Branch("w_acc_pt_Jpsi1_err" ,    &w_acc_pt_Jpsi1_err,  "w_acc_pt_Jpsi1_err/F"  );
  NewTree->Branch("w_reco_Jpsi1_err"   ,    &w_reco_Jpsi1_err,    "w_reco_Jpsi1_err/F"    );
  NewTree->Branch("w_eff_Jpsi1_err"    ,    &w_eff_Jpsi1_err,     "w_eff_Jpsi1_err/F"     );
  NewTree->Branch("w_vtx_Jpsi1_err"    ,    &w_vtx_Jpsi1_err,     "w_vtx_Jpsi1_err/F"     );

  NewTree->Branch("w_acc_eta_Jpsi2",    &w_acc_eta_Jpsi2, "w_acc_eta_Jpsi2/F" );
  NewTree->Branch("w_acc_pt_Jpsi2" ,    &w_acc_pt_Jpsi2,  "w_acc_pt_Jpsi2/F"  );
  NewTree->Branch("w_reco_Jpsi2"   ,    &w_reco_Jpsi2,    "w_reco_Jpsi2/F"    );
  NewTree->Branch("w_eff_Jpsi2"    ,    &w_eff_Jpsi2,     "w_eff_Jpsi2/F"     );
  NewTree->Branch("w_vtx_Jpsi2"    ,    &w_vtx_Jpsi2,     "w_vtx_Jpsi2/F"     );
  NewTree->Branch("w_HLT"    ,    &w_HLT,     "w_HLT/F"     );
  NewTree->Branch("w_evt"    ,    &w_evt,     "w_evt/F"     );

  NewTree->Branch("w_acc_eta_Jpsi2_err",    &w_acc_eta_Jpsi2_err, "w_acc_eta_Jpsi2_err/F" );
  NewTree->Branch("w_acc_pt_Jpsi2_err" ,    &w_acc_pt_Jpsi2_err,  "w_acc_pt_Jpsi2_err/F"  );
  NewTree->Branch("w_reco_Jpsi2_err"   ,    &w_reco_Jpsi2_err,    "w_reco_Jpsi2_err/F"    );
  NewTree->Branch("w_eff_Jpsi2_err"    ,    &w_eff_Jpsi2_err,     "w_eff_Jpsi2_err/F"     );
  NewTree->Branch("w_vtx_Jpsi2_err"    ,    &w_vtx_Jpsi2_err,     "w_vtx_Jpsi2_err/F"     );
  NewTree->Branch("w_HLT_err"    ,    &w_HLT_err,     "w_HLT_err/F"     );
  NewTree->Branch("w_evt_err"    ,    &w_evt_err,     "w_evt_err/F"     );

  NewTree->Branch("w_acceta",                            &w_acceta,                            "w_acceta/F");
  NewTree->Branch("w_acceta_accpt",                      &w_acceta_accpt,                      "w_acceta_accpt/F");
  NewTree->Branch("w_acceta_accpt_reco",                 &w_acceta_accpt_reco,                 "w_acceta_accpt_reco/F");
  NewTree->Branch("w_acceta_accpt_reco_eff",             &w_acceta_accpt_reco_eff,             "w_acceta_accpt_reco_eff/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx",         &w_acceta_accpt_reco_eff_vtx,         "w_acceta_accpt_reco_eff_vtx/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx_HLT",     &w_acceta_accpt_reco_eff_vtx_HLT,     "w_acceta_accpt_reco_eff_vtx_HLT/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx_HLT_evt", &w_acceta_accpt_reco_eff_vtx_HLT_evt, "w_acceta_accpt_reco_eff_vtx_HLT_evt/F");

  NewTree->Branch("w_acceta_err",                            &w_acceta_err,                            "w_acceta_err/F");
  NewTree->Branch("w_acceta_accpt_err",                      &w_acceta_accpt_err,                      "w_acceta_accpt_err/F");
  NewTree->Branch("w_acceta_accpt_reco_err",                 &w_acceta_accpt_reco_err,                 "w_acceta_accpt_reco_err/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_err",             &w_acceta_accpt_reco_eff_err,             "w_acceta_accpt_reco_eff_err/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx_err",         &w_acceta_accpt_reco_eff_vtx_err,         "w_acceta_accpt_reco_eff_vtx_err/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx_HLT_err",     &w_acceta_accpt_reco_eff_vtx_HLT_err,     "w_acceta_accpt_reco_eff_vtx_HLT_err/F");
  NewTree->Branch("w_acceta_accpt_reco_eff_vtx_HLT_evt_err", &w_acceta_accpt_reco_eff_vtx_HLT_evt_err, "w_acceta_accpt_reco_eff_vtx_HLT_evt_err/F");

}

void initialVal(){
    Jpsi1_pt = -99;
    Jpsi1_y  = -99;
    Jpsi1_mass  = -99;

    Jpsi2_pt = -99;
    Jpsi2_y  = -99;
    Jpsi2_mass  = -99;

    w_acc_eta_Jpsi1 = 1;
    w_acc_pt_Jpsi1  = 1;
    w_reco_Jpsi1    = 1;
    w_eff_Jpsi1     = 1;
    w_vtx_Jpsi1     = 1;

    w_acc_eta_Jpsi1_err = 0;
    w_acc_pt_Jpsi1_err  = 0;
    w_reco_Jpsi1_err    = 0;
    w_eff_Jpsi1_err     = 0;
    w_vtx_Jpsi1_err     = 0;

    w_acc_eta_Jpsi2 = 1;
    w_acc_pt_Jpsi2  = 1;
    w_reco_Jpsi2    = 1;
    w_eff_Jpsi2     = 1;
    w_vtx_Jpsi2     = 1;
    w_HLT    = 1;
    w_evt    = 1;

    w_acc_eta_Jpsi2_err = 0;
    w_acc_pt_Jpsi2_err  = 0;
    w_reco_Jpsi2_err    = 0;
    w_eff_Jpsi2_err     = 0;
    w_vtx_Jpsi2_err     = 0;
    w_HLT_err    = 0;
    w_evt_err    = 0;

    w_acceta                            = 1;
    w_acceta_accpt                      = 1;
    w_acceta_accpt_reco                 = 1;
    w_acceta_accpt_reco_eff             = 1;
    w_acceta_accpt_reco_eff_vtx         = 1;
    w_acceta_accpt_reco_eff_vtx_HLT     = 1;
    w_acceta_accpt_reco_eff_vtx_HLT_evt = 1;

    w_acceta_err                            = 0;
    w_acceta_accpt_err                      = 0;
    w_acceta_accpt_reco_err                 = 0;
    w_acceta_accpt_reco_eff_err             = 0;
    w_acceta_accpt_reco_eff_vtx_err         = 0;
    w_acceta_accpt_reco_eff_vtx_HLT_err     = 0;
    w_acceta_accpt_reco_eff_vtx_HLT_evt_err = 0;
}
