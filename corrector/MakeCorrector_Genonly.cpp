#define MakeCorrector_cxx
#include "MakeCorrector.h"
#include <TH2.h>
#include <TStyle.h>
#include <TCanvas.h>

void MakeCorrector_v2(const char *mc, const char *type){
  //TString Mc = mc; TString Type = type;
  char openTree[500];   sprintf(openTree, "rootuple/oniaTree");
  char openFile[500];   sprintf(openFile, "/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/%sToJJ_13TeV_pythia8_%s.root",mc,type); 
  //TFile *file_SPS_off = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/SPSToJJ_13TeV_pythia8_official.root");
  //TFile *file_SPS_pri = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/SPSToJJ_13TeV_pythia8_private.root");
  //TFile *file_DPS_off = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/DPSToJJ_13TeV_pythia8_official.root");
  //TFile *file_DPS_pri = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/DPSToJJ_13TeV_pythia8_private.root");
  TFile *file = TFile::Open(openFile);
  TTree *Tree = (TTree*)file->Get(openTree);
  Init(Tree);
  if (fChain == 0) return;
  const int N = 10;  Double_t xbins[N] = {6.,7.,8.,9.,10.,12.,15.,20.,25.,40.};
  //const int N = 24;  Double_t xbins[N] = {6.,7.,8.,9.,10.,11.,12.,13.,14.,15.,16.,17.,18.,19.,20.,21.,22.,23.,24.,26.,28.,30.,35.,40.};
  const int M = 11;   Double_t ybins[M] = {-2.,-1.75,-1.5,-1.0,-0.5,0,0.5,1.0,1.5,1.75,2.};
  TH2F *h_total_Jpsi = new TH2F("h_total_Jpsi","h_total_Jpsi",N-1 , xbins, M-1, ybins);
  TH2F *h_acc_eta_Jpsi = new TH2F("h_acc_eta_Jpsi","h_acc_eta_Jpsi",N-1 , xbins, M-1, ybins);
  TH2F *h_acc_pt_Jpsi = new TH2F("h_acc_pt_Jpsi","h_acc_pt_Jpsi",N-1 , xbins, M-1, ybins);

  Long64_t nentries = fChain->GetEntries();
  for (Long64_t jentry=0; jentry<nentries;jentry++) {
    //nb = fChain->GetEntry(jentry);   nbytes += nb;
    fChain->GetEntry(jentry);
    bool FindJpsi = false;
    if (GENdimu_pt->size()<2) continue;
    if (fabs(GENdimu_y->at(0))<2){
       h_total_Jpsi->Fill(GENdimu_pt->at(0),GENdimu_y->at(0));
       if (abs(GENmu_eta->at(GEN_ups1_mu1_index))<2.4 && abs(GENmu_eta->at(GEN_ups1_mu2_index))<2.4) h_acc_eta_Jpsi->Fill(GENdimu_pt->at(0),GENdimu_y->at(0));
       if (abs(GENmu_eta->at(GEN_ups1_mu1_index))<2.4 && abs(GENmu_eta->at(GEN_ups1_mu2_index))<2.4 && abs(GENmu_pt->at(GEN_ups1_mu1_index))>3.5 && abs(GENmu_pt->at(GEN_ups1_mu2_index))>3.5){ 
          h_acc_pt_Jpsi->Fill(GENdimu_pt->at(0),GENdimu_y->at(0));
          FindJpsi = true;
       }
    }
    if (fabs(GENdimu_y->at(1))<2){
       h_total_Jpsi->Fill(GENdimu_pt->at(1),GENdimu_y->at(1));
       if (abs(GENmu_eta->at(GEN_ups2_mu1_index))<2.4 && abs(GENmu_eta->at(GEN_ups2_mu2_index))<2.4) h_acc_eta_Jpsi->Fill(GENdimu_pt->at(1),GENdimu_y->at(1));
       if (abs(GENmu_eta->at(GEN_ups2_mu1_index))<2.4 && abs(GENmu_eta->at(GEN_ups2_mu2_index))<2.4 && abs(GENmu_pt->at(GEN_ups2_mu1_index))>3.5 && abs(GENmu_pt->at(GEN_ups2_mu2_index))>3.5){
          h_acc_pt_Jpsi->Fill(GENdimu_pt->at(1),GENdimu_y->at(1));
          FindJpsi = true;
       }
    }
    
    
      // if (Cut(ientry) < 0) continue;
  }
  char NewFileName[500]; sprintf(NewFileName, "Gen_Event_%s_%s_genonly.root",mc,type);
  TFile f(NewFileName,"new");
  h_total_Jpsi->Write();
  h_acc_eta_Jpsi->Write();
  h_acc_pt_Jpsi->Write();
  f.Close();
  cout<<"Job Finish"<<endl;
  
}
