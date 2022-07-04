#include "Addcorrector.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void Addcorrector(const char *mctest, const char *typetest, const char *mc, const char *type){
  //TString Mc = mc; TString Type = type;
  //Read input root file
  char Filecorrector[500]; sprintf(Filecorrector, "corrector_%s_%s.root",mctest,typetest);
  filecorrector = new TFile(Filecorrector);
  h_w_acc_eta = (TH2F*) filecorrector->Get("h_w_acc_eta");
  h_w_acc_pt  = (TH2F*) filecorrector->Get("h_w_acc_pt");
  h_w_reco    = (TH2F*) filecorrector->Get("h_w_reco");
  h_w_eff     = (TH2F*) filecorrector->Get("h_w_eff");
  h_w_vtx     = (TH2F*) filecorrector->Get("h_w_vtx");
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
    int FindNJpsi;
    FindNJpsi = 0; 
    for (int i=0; i<GENups_pt->size(); i++){
      if(!(fabs(GENups_y->at(i))<2)) continue;
      if(!((GENups_DaughtersId->at(2*i)==13)&&(GENups_DaughtersId->at(2*i+1)==13))) continue; 
      if(!((fabs(GENups_Daughter_mueta->at(2*i))<2.4)&&(fabs(GENups_Daughter_mueta->at(2*i+1))<2.4))) continue; 
      if(!((GENups_Daughter_mupt->at(2*i)>3.5)&&(GENups_Daughter_mupt->at(2*i+1)>3.5))) continue; 
      FindNJpsi = FindNJpsi+1;
      }
    if (FindNJpsi < 2) continue;
    if (!((trigger&16)==0)){
       if (!(fourMuFit_ups1_pt->size()>0&&fourMuFit_ups2_pt->size()>0&&fourMuFit_VtxProb->at(0)>0.05)) continue;
       if (!(mu1_Pt->at(0)>3.5&&mu2_Pt->at(0)>3.5&&mu3_Pt->at(0)>3.5&&mu4_Pt->at(0)>3.5)) continue;
       //h_evt_JpsiPair->Fill(fourMuFit_ups1_pt->at(0),fourMuFit_ups2_pt->at(0));
       Jpsi1_pt = fourMuFit_ups1_pt->at(0);
       Jpsi1_y  = fourMuFit_ups1_rapidity->at(0);
       Jpsi1_mass  = fourMuFit_ups1_mass->at(0);

       Jpsi2_pt = fourMuFit_ups1_pt->at(0);
       Jpsi2_y  = fourMuFit_ups1_rapidity->at(0);
       Jpsi2_mass  = fourMuFit_ups1_mass->at(0);
    } else continue;
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


    NewTree->Fill();
      
  }
  NewTree->Write();
  f.Close();
  cout<<"Job Finish"<<endl;
  
}


void GetCorrector(vector<float> & Jpsi1_corr_list, vector<float> & Jpsi1_corr_list_err, vector<float> & Jpsi2_corr_list, vector<float> & Jpsi2_corr_list_err,  float Jpsi1_pt, float Jpsi1_y, float Jpsi2_pt, float Jpsi2_y){
  if (Jpsi1_pt<40 && Jpsi1_pt>5 && fabs(Jpsi1_y)<2){
    int pt_bin_Jpsi1 = h_w_acc_eta->GetXaxis()->FindFixBin(Jpsi1_pt);
    int y_bin_Jpsi1 = h_w_acc_eta->GetYaxis()->FindFixBin(Jpsi1_y);

    float w_acc_eta_Jpsi1 = h_w_acc_eta->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_acc_pt_Jpsi1 = h_w_acc_pt->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_reco_Jpsi1 = h_w_reco->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_eff_Jpsi1 = h_w_eff->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_vtx_Jpsi1 = h_w_vtx->GetBinContent(pt_bin_Jpsi1, y_bin_Jpsi1);

    float w_acc_eta_Jpsi1_err = h_w_acc_eta->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_acc_pt_Jpsi1_err = h_w_acc_pt->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_reco_Jpsi1_err = h_w_reco->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_eff_Jpsi1_err = h_w_eff->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);
    float w_vtx_Jpsi1_err = h_w_vtx->GetBinError(pt_bin_Jpsi1, y_bin_Jpsi1);

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
    int pt_bin_Jpsi2 = h_w_acc_eta->GetXaxis()->FindFixBin(Jpsi2_pt);
    int y_bin_Jpsi2 = h_w_acc_eta->GetYaxis()->FindFixBin(Jpsi2_y);

    float w_acc_eta_Jpsi2 = h_w_acc_eta->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_acc_pt_Jpsi2 = h_w_acc_pt->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_reco_Jpsi2 = h_w_reco->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_eff_Jpsi2 = h_w_eff->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_vtx_Jpsi2 = h_w_vtx->GetBinContent(pt_bin_Jpsi2, y_bin_Jpsi2);

    float w_acc_eta_Jpsi2_err = h_w_acc_eta->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_acc_pt_Jpsi2_err = h_w_acc_pt->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_reco_Jpsi2_err = h_w_reco->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_eff_Jpsi2_err = h_w_eff->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);
    float w_vtx_Jpsi2_err = h_w_vtx->GetBinError(pt_bin_Jpsi2, y_bin_Jpsi2);

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
}
