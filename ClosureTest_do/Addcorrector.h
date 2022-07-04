//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May 16 09:40:47 2022 by ROOT version 6.20/06
// from TTree oniaTree/Tree of MuMuGamma
// found on file: DPSToJJ_13TeV_pythia8_official.root
//////////////////////////////////////////////////////////

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"
#include "vector"
#include "TLorentzVector.h"
void SetNewTree(TTree* NewTree);
void initialVal();
void GetCorrector(vector<float> & Jpsi1_corr_list, vector<float> & Jpsi1_corr_list_err, vector<float> & Jpsi2_corr_list, vector<float> & Jpsi2_corr_list_err,  float Jpsi1_pt, float Jpsi1_y, float Jpsi2_pt, float Jpsi_y);
float CalculateError(float factor1, float factor2, float factor1_err, float factor2_err);

TFile *filecorrector; 
TH2F  *h_w_acc_eta; 
TH2F  *h_w_acc_pt;  
TH2F  *h_w_reco;    
TH2F  *h_w_eff;     
TH2F  *h_w_vtx;     
TH2F  *h_w_HLT;     
TH2F  *h_w_evt;     

TH2F  *h_w_acc_eta_Jpsi1; 
TH2F  *h_w_acc_eta_Jpsi2; 
TH2F  *h_w_acc_pt_Jpsi1;  
TH2F  *h_w_acc_pt_Jpsi2;  
TH2F  *h_w_reco_Jpsi1;    
TH2F  *h_w_reco_Jpsi2;    
TH2F  *h_w_eff_Jpsi1;     
TH2F  *h_w_eff_Jpsi2;     
TH2F  *h_w_vtx_Jpsi1;     
TH2F  *h_w_vtx_Jpsi2;     
TH2F  *h_w_HLT_Jpsi1;     
TH2F  *h_w_HLT_Jpsi2;     
TH2F  *h_w_evt_Jpsi1;     
TH2F  *h_w_evt_Jpsi2;     

TTree          *fChain;   //!pointer to the analyzed TTree or TChain
Int_t           fCurrent; //!current Tree number in a TChain


// Declaration of leaf types
ULong64_t       run;
ULong64_t       lumi;
ULong64_t       event;
Int_t           irank;
Int_t           trigger;
Int_t           numPrimaryVertices;
Float_t         pv_x;
Float_t         pv_y;
Float_t         pv_z;
Float_t         ups1_mass_GenMatched;
Float_t         ups2_mass_GenMatched;
Float_t         ups1_y_GenMatched;
Float_t         ups2_y_GenMatched;
Float_t         ups1_pt_GenMatched;
Float_t         ups2_pt_GenMatched;
Float_t         ups1_mass_GenMatched_ID;
Float_t         ups1_pt_GenMatched_ID;
Float_t         ups1_y_GenMatched_ID;
Float_t         ups2_mass_GenMatched_ID;
Float_t         ups2_pt_GenMatched_ID;
Float_t         ups2_y_GenMatched_ID;
Float_t         ups1_mass_GenMatched_ID_OS_VTX;
Float_t         ups1_pt_GenMatched_ID_OS_VTX;
Float_t         ups1_y_GenMatched_ID_OS_VTX;
Float_t         ups2_mass_GenMatched_ID_OS_VTX;
Float_t         ups2_pt_GenMatched_ID_OS_VTX;
Float_t         ups2_y_GenMatched_ID_OS_VTX;
Float_t         fourmu_mass_allcuts;
Float_t         fourmu_mass_trigger;
vector<int>     *All_ups_muindex1;
vector<int>     *All_ups_muindex2;
Int_t           GEN_ups1_mu1_index;
Int_t           GEN_ups1_mu2_index;
Int_t           GEN_ups2_mu1_index;
Int_t           GEN_ups2_mu2_index;
Int_t           RECO_ups1_mu1_index;
Int_t           RECO_ups1_mu2_index;
Int_t           RECO_ups2_mu1_index;
Int_t           RECO_ups2_mu2_index;
vector<int>     *v_mu1Charge;
vector<int>     *v_mu2Charge;
vector<float>   *v_mu1_d0;
vector<float>   *v_mu1_d0err;
vector<float>   *v_mu2_d0;
vector<float>   *v_mu2_d0err;
vector<float>   *v_mu1_dz;
vector<float>   *v_mu1_dzerr;
vector<float>   *v_mu2_dz;
vector<float>   *v_mu2_dzerr;
vector<float>   *v_mu1_vz;
vector<float>   *v_mu2_vz;
vector<float>   *mu1_trg_dR;
vector<float>   *mu2_trg_dR;
vector<float>   *v_mumufit_Mass;
vector<float>   *v_mumufit_MassErr;
vector<float>   *v_mumufit_Mass_noMC;
vector<float>   *v_mumufit_MassErr_noMC;
vector<float>   *v_mumu_Pt;
vector<float>   *v_mumu_Rapidity;
vector<float>   *v_mumufit_VtxCL;
vector<float>   *v_mumufit_VtxCL_noMC;
vector<float>   *v_mumufit_VtxCL2;
vector<double>  *v_mumufit_DecayVtxX;
vector<double>  *v_mumufit_DecayVtxY;
vector<double>  *v_mumufit_DecayVtxZ;
vector<double>  *v_mumufit_DecayVtxXE;
vector<double>  *v_mumufit_DecayVtxYE;
vector<double>  *v_mumufit_DecayVtxZE;
vector<string>  *mu1_filtersMatched;
vector<string>  *mu2_filtersMatched;
TLorentzVector  *mu1_p4;
TLorentzVector  *mu2_p4;
Int_t           mu1charge;
Int_t           mu2charge;
Float_t         mu1_d0;
Float_t         mu1_d0err;
Float_t         mu2_d0;
Float_t         mu2_d0err;
Float_t         mu1_dz;
Float_t         mu1_dzerr;
Float_t         mu2_dz;
Float_t         mu2_dzerr;
Float_t         mu1_vz;
Float_t         mu2_vz;
TLorentzVector  *dimuon_p4;
Float_t         mumufit_Mass;
Float_t         mumufit_MassErr;
Float_t         mumufit_VtxCL;
Float_t         mumufit_VtxCL2;
Double_t        mumufit_DecayVtxX;
Double_t        mumufit_DecayVtxY;
Double_t        mumufit_DecayVtxZ;
Double_t        mumufit_DecayVtxXE;
Double_t        mumufit_DecayVtxYE;
Double_t        mumufit_DecayVtxZE;
TLorentzVector  *mumufit_p4;
vector<float>   *fourMuFit_Mass_allComb_mix;
Float_t         fourMuFit_Mass_mix;
Float_t         fourMuFit_MassErr_mix;
Float_t         fourMuFit_VtxX_mix;
Float_t         fourMuFit_VtxY_mix;
Float_t         fourMuFit_VtxZ_mix;
Float_t         fourMuFit_VtxProb_mix;
Float_t         fourMuFit_Chi2_mix;
Int_t           fourMuFit_ndof_mix;
Int_t           fourMuFit_3plus1_mix;
TLorentzVector  *fourMuFit_p4_mix;
TLorentzVector  *fourMuFit_mu1p4_mix;
TLorentzVector  *fourMuFit_mu2p4_mix;
TLorentzVector  *fourMuFit_mu3p4_mix;
TLorentzVector  *fourMuFit_mu4p4_mix;
Int_t           mu3Charge_mix;
Int_t           mu4Charge_mix;
TLorentzVector  *mu3_p4_mix;
TLorentzVector  *mu4_p4_mix;
Float_t         mu3_d0_mix;
Float_t         mu3_d0err_mix;
Float_t         mu4_d0_mix;
Float_t         mu4_d0err_mix;
Float_t         mu3_dz_mix;
Float_t         mu3_dzerr_mix;
Float_t         mu4_dz_mix;
Float_t         mu4_dzerr_mix;
Float_t         fourMuFit_Mass_mix3evts;
Float_t         fourMuFit_VtxProb_mix3evts;
TLorentzVector  *fourMuFit_p4_mix3evts;
Int_t           GENfinalState;
Bool_t          passedFiducialSelection;
vector<double>  *GENmu_pt;
vector<double>  *GENmu_eta;
vector<double>  *GENmu_phi;
vector<double>  *GENmu_mass;
vector<int>     *GENmu_id;
vector<int>     *GENmu_status;
vector<int>     *GENmu_MomId;
vector<int>     *GENmu_MomMomId;
vector<int>     *GENups_DaughtersId;
vector<double>  *GENups_Daughter_mupt;
vector<double>  *GENups_Daughter_mueta;
vector<double>  *GENups_Daughter_muphi;
vector<double>  *GENups_Daughter_mumass;
vector<double>  *GENups_Daughter_mustatus;
vector<int>     *GENups_MomId;
vector<double>  *GENups_pt;
vector<double>  *GENdimu_mass;
vector<double>  *GENdimu_pt;
vector<double>  *GENdimu_eta;
vector<double>  *GENdimu_y;
vector<double>  *GENdimu_phi;
vector<double>  *GENups_eta;
vector<double>  *GENups_y;
vector<double>  *GENups_phi;
vector<double>  *GENups_mass;
vector<double>  *GENX_mass;
vector<double>  *GENX_pt;
vector<double>  *GENX_eta;
vector<double>  *GENX_y;
vector<double>  *GENX_phi;
vector<float>   *fourMuFit_Mass_allComb;
vector<float>   *fourMuFit_Mass;
vector<float>   *fourMuFit_MassErr;
vector<float>   *fourMuFit_Pt;
vector<float>   *fourMuFit_Eta;
vector<float>   *fourMuFit_Phi;
vector<double>  *fourMuFit_VtxX;
vector<double>  *fourMuFit_VtxY;
vector<double>  *fourMuFit_VtxZ;
vector<double>  *fourMuFit_VtxXE;
vector<double>  *fourMuFit_VtxYE;
vector<double>  *fourMuFit_VtxZE;
vector<double>  *fourMuFit_PVX;
vector<double>  *fourMuFit_PVY;
vector<double>  *fourMuFit_PVZ;
vector<double>  *fourMuFit_PVXE;
vector<double>  *fourMuFit_PVYE;
vector<double>  *fourMuFit_PVZE;
vector<double>  *fourMuFit_PV_XYE;
vector<double>  *fourMuFit_PV_XZE;
vector<double>  *fourMuFit_PV_YZE;
vector<double>  *fourMuFit_PV_CL;
vector<float>   *fourMuFit_VtxProb;
vector<float>   *fourMuFit_Double_ups_VtxProb;
vector<float>   *fourMuFit_ups1_VtxProb;
vector<float>   *fourMuFit_ups2_VtxProb;
vector<float>   *fourMuFit_ups1_VtxProb_noMC;
vector<float>   *fourMuFit_ups2_VtxProb_noMC;
vector<float>   *fourMuFit_ups1_pt;
vector<float>   *fourMuFit_ups2_pt;
vector<float>   *fourMuFit_ups1_rapidity;
vector<float>   *fourMuFit_ups2_rapidity;
vector<float>   *fourMuFit_ups1_mass;
vector<float>   *fourMuFit_ups2_mass;
vector<float>   *fourMuFit_ups1_massError;
vector<float>   *fourMuFit_ups2_massError;
vector<double>  *fourMuFit_ups1_VtxX;
vector<double>  *fourMuFit_ups1_VtxY;
vector<double>  *fourMuFit_ups1_VtxZ;
vector<double>  *fourMuFit_ups1_VtxXE;
vector<double>  *fourMuFit_ups1_VtxYE;
vector<double>  *fourMuFit_ups1_VtxZE;
vector<double>  *fourMuFit_ups2_VtxX;
vector<double>  *fourMuFit_ups2_VtxY;
vector<double>  *fourMuFit_ups2_VtxZ;
vector<double>  *fourMuFit_ups2_VtxXE;
vector<double>  *fourMuFit_ups2_VtxYE;
vector<double>  *fourMuFit_ups2_VtxZE;
vector<float>   *fourMuFit_wrong_ups1_mass;
vector<float>   *fourMuFit_wrong_ups2_mass;
vector<float>   *fourMuFit_wrong_ups1_massError;
vector<float>   *fourMuFit_wrong_ups2_massError;
vector<float>   *fourMuFit_Chi2;
vector<int>     *fourMuFit_ndof;
vector<float>   *fourMuFit_Double_ups_Chi2;
vector<int>     *fourMuFit_Double_ups_ndof;
vector<float>   *fourMuFit_mu1Pt;
vector<float>   *fourMuFit_mu1Eta;
vector<float>   *fourMuFit_mu1Phi;
vector<float>   *fourMuFit_mu1E;
vector<int>     *fourMuFit_mu1frompv;
vector<float>   *fourMuFit_mu2Pt;
vector<float>   *fourMuFit_mu2Eta;
vector<float>   *fourMuFit_mu2Phi;
vector<float>   *fourMuFit_mu2E;
vector<int>     *fourMuFit_mu2frompv;
vector<float>   *fourMuFit_mu3Pt;
vector<float>   *fourMuFit_mu3Eta;
vector<float>   *fourMuFit_mu3Phi;
vector<float>   *fourMuFit_mu3E;
vector<int>     *fourMuFit_mu3frompv;
vector<float>   *fourMuFit_mu4Pt;
vector<float>   *fourMuFit_mu4Eta;
vector<float>   *fourMuFit_mu4Phi;
vector<float>   *fourMuFit_mu4E;
vector<int>     *fourMuFit_mu4frompv;
vector<float>   *fourMuFit_mu3_trg_dR;
vector<float>   *fourMuFit_mu4_trg_dR;
vector<double>  *AllRecoMuons_Pt;
vector<double>  *AllRecoMuons_Eta;
vector<float>   *mu1_Pt;
vector<float>   *mu1_Eta;
vector<float>   *mu1_Phi;
vector<float>   *mu1_E;
vector<int>     *mu1_genindex;
vector<float>   *mu2_Pt;
vector<float>   *mu2_Eta;
vector<float>   *mu2_Phi;
vector<float>   *mu2_E;
vector<int>     *mu2_genindex;
vector<float>   *mu3_Pt;
vector<float>   *mu3_Eta;
vector<float>   *mu3_Phi;
vector<float>   *mu3_E;
vector<float>   *mu4_Pt;
vector<float>   *mu4_Eta;
vector<float>   *mu4_Phi;
vector<float>   *mu4_E;
vector<int>     *mu1Charge;
vector<int>     *mu2Charge;
vector<int>     *mu3Charge;
vector<int>     *mu4Charge;
vector<float>   *mu3_d0;
vector<float>   *mu3_d0err;
vector<float>   *mu4_d0;
vector<float>   *mu4_d0err;
vector<float>   *mu3_dz;
vector<float>   *mu3_dzerr;
vector<float>   *mu4_dz;
vector<float>   *mu4_dzerr;
vector<int>     *mu1_Soft;
vector<int>     *mu2_Soft;
vector<int>     *mu3_Soft;
vector<int>     *mu4_Soft;
vector<int>     *mu1_Tight;
vector<int>     *mu2_Tight;
vector<int>     *mu3_Tight;
vector<int>     *mu4_Tight;
vector<int>     *mu1_Medium;
vector<int>     *mu2_Medium;
vector<int>     *mu3_Medium;
vector<int>     *mu4_Medium;
vector<int>     *mu1_Loose;
vector<int>     *mu2_Loose;
vector<int>     *mu3_Loose;
vector<int>     *mu4_Loose;
vector<int>     *mu1_pdgID;
vector<int>     *mu2_pdgID;
vector<int>     *mu3_pdgID;
vector<int>     *mu4_pdgID;
vector<int>     *fourMuFit_mu12overlap;
vector<int>     *fourMuFit_mu13overlap;
vector<int>     *fourMuFit_mu14overlap;
vector<int>     *fourMuFit_mu23overlap;
vector<int>     *fourMuFit_mu24overlap;
vector<int>     *fourMuFit_mu34overlap;
vector<int>     *fourMuFit_mu12SharedSeg;
vector<int>     *fourMuFit_mu13SharedSeg;
vector<int>     *fourMuFit_mu14SharedSeg;
vector<int>     *fourMuFit_mu23SharedSeg;
vector<int>     *fourMuFit_mu24SharedSeg;
vector<int>     *fourMuFit_mu34SharedSeg;
TLorentzVector  *mu1_p4_bestYMass;
TLorentzVector  *mu2_p4_bestYMass;
Int_t           mu1Charge_bestYMass;
Int_t           mu2Charge_bestYMass;
Float_t         mu1_d0_bestYMass;
Float_t         mu1_d0err_bestYMass;
Float_t         mu2_d0_bestYMass;
Float_t         mu2_d0err_bestYMass;
Float_t         mu1_dz_bestYMass;
Float_t         mu1_dzerr_bestYMass;
Float_t         mu2_dz_bestYMass;
Float_t         mu2_dzerr_bestYMass;
TLorentzVector  *dimuon_p4_bestYMass;
Float_t         mumufit_Mass_bestYMass;
Float_t         mumufit_MassErr_bestYMass;
Float_t         mumufit_VtxCL_bestYMass;
Float_t         mumufit_VtxCL2_bestYMass;
Float_t         mumufit_DecayVtxX_bestYMass;
Float_t         mumufit_DecayVtxY_bestYMass;
Float_t         mumufit_DecayVtxZ_bestYMass;
Float_t         mumufit_DecayVtxXE_bestYMass;
Float_t         mumufit_DecayVtxYE_bestYMass;
Float_t         mumufit_DecayVtxZE_bestYMass;
TLorentzVector  *mumufit_p4_bestYMass;
Int_t           bestVertex_and_bestYMass;
vector<float>   *fourMuFit_Mass_allComb_mix_bestYMass;
Float_t         fourMuFit_Mass_mix_bestYMass;
Float_t         fourMuFit_MassErr_mix_bestYMass;
Float_t         fourMuFit_VtxX_mix_bestYMass;
Float_t         fourMuFit_VtxY_mix_bestYMass;
Float_t         fourMuFit_VtxZ_mix_bestYMass;
Float_t         fourMuFit_VtxProb_mix_bestYMass;
Float_t         fourMuFit_Chi2_mix_bestYMass;
Int_t           fourMuFit_ndof_mix_bestYMass;
Int_t           fourMuFit_3plus1_mix_bestYMass;
TLorentzVector  *fourMuFit_p4_mix_bestYMass;
TLorentzVector  *fourMuFit_mu1p4_mix_bestYMass;
TLorentzVector  *fourMuFit_mu2p4_mix_bestYMass;
TLorentzVector  *fourMuFit_mu3p4_mix_bestYMass;
TLorentzVector  *fourMuFit_mu4p4_mix_bestYMass;
Int_t           mu3Charge_mix_bestYMass;
Int_t           mu4Charge_mix_bestYMass;
TLorentzVector  *mu3_p4_mix_bestYMass;
TLorentzVector  *mu4_p4_mix_bestYMass;
Float_t         mu3_d0_mix_bestYMass;
Float_t         mu3_d0err_mix_bestYMass;
Float_t         mu4_d0_mix_bestYMass;
Float_t         mu4_d0err_mix_bestYMass;
Float_t         mu3_dz_mix_bestYMass;
Float_t         mu3_dzerr_mix_bestYMass;
Float_t         mu4_dz_mix_bestYMass;
Float_t         mu4_dzerr_mix_bestYMass;
vector<float>   *fourMuFit_Mass_allComb_bestYMass;
Float_t         fourMuFit_Mass_bestYMass;
Float_t         fourMuFit_MassErr_bestYMass;
Float_t         fourMuFit_VtxX_bestYMass;
Float_t         fourMuFit_VtxY_bestYMass;
Float_t         fourMuFit_VtxZ_bestYMass;
Float_t         fourMuFit_VtxProb_bestYMass;
Float_t         fourMuFit_Chi2_bestYMass;
Int_t           fourMuFit_ndof_bestYMass;
TLorentzVector  *fourMuFit_p4_bestYMass;
TLorentzVector  *fourMuFit_mu1p4_bestYMass;
TLorentzVector  *fourMuFit_mu2p4_bestYMass;
TLorentzVector  *fourMuFit_mu3p4_bestYMass;
TLorentzVector  *fourMuFit_mu4p4_bestYMass;
Int_t           mu3Charge_bestYMass;
Int_t           mu4Charge_bestYMass;
TLorentzVector  *mu3_p4_bestYMass;
TLorentzVector  *mu4_p4_bestYMass;
Float_t         mu3_d0_bestYMass;
Float_t         mu3_d0err_bestYMass;
Float_t         mu4_d0_bestYMass;
Float_t         mu4_d0err_bestYMass;
Float_t         mu3_dz_bestYMass;
Float_t         mu3_dzerr_bestYMass;
Float_t         mu4_dz_bestYMass;
Float_t         mu4_dzerr_bestYMass;
Int_t           mu1_Tight_bestYMass;
Int_t           mu2_Tight_bestYMass;
Int_t           mu3_Tight_bestYMass;
Int_t           mu4_Tight_bestYMass;
Int_t           mu3_pdgID_bestYMass;
Int_t           mu4_pdgID_bestYMass;
Int_t           mu1_Medium_bestYMass;
Int_t           mu2_Medium_bestYMass;
Int_t           mu3_Medium_bestYMass;
Int_t           mu4_Medium_bestYMass;
Int_t           mu1_Loose_bestYMass;
Int_t           mu2_Loose_bestYMass;
Int_t           mu3_Loose_bestYMass;
Int_t           mu4_Loose_bestYMass;
Int_t           mother_pdgId;
Int_t           dimuon_pdgId;
TLorentzVector  *gen_dimuon_p4;
TLorentzVector  *gen_mu1_p4;
TLorentzVector  *gen_mu2_p4;

float  Jpsi1_pt;
float  Jpsi1_y;
float  Jpsi1_mass;

float  Jpsi2_pt;
float  Jpsi2_y;
float  Jpsi2_mass;

float  w_acc_eta_Jpsi1;
float  w_acc_pt_Jpsi1;
float  w_reco_Jpsi1;
float  w_eff_Jpsi1;
float  w_vtx_Jpsi1;

float  w_acc_eta_Jpsi1_err;
float  w_acc_pt_Jpsi1_err;
float  w_reco_Jpsi1_err;
float  w_eff_Jpsi1_err;
float  w_vtx_Jpsi1_err;

float  w_acc_eta_Jpsi2;
float  w_acc_pt_Jpsi2;
float  w_reco_Jpsi2;
float  w_eff_Jpsi2;
float  w_vtx_Jpsi2;
float  w_HLT;
float  w_evt;

float  w_acc_eta_Jpsi2_err;
float  w_acc_pt_Jpsi2_err;
float  w_reco_Jpsi2_err;
float  w_eff_Jpsi2_err;
float  w_vtx_Jpsi2_err;
float  w_HLT_err;
float  w_evt_err;

float  w_acceta;
float  w_acceta_accpt;
float  w_acceta_accpt_reco;
float  w_acceta_accpt_reco_eff;
float  w_acceta_accpt_reco_eff_vtx;
float  w_acceta_accpt_reco_eff_vtx_HLT;
float  w_acceta_accpt_reco_eff_vtx_HLT_evt;

float  w_acceta_err;
float  w_acceta_accpt_err;
float  w_acceta_accpt_reco_err;
float  w_acceta_accpt_reco_eff_err;
float  w_acceta_accpt_reco_eff_vtx_err;
float  w_acceta_accpt_reco_eff_vtx_HLT_err;
float  w_acceta_accpt_reco_eff_vtx_HLT_evt_err;

// List of branches
TBranch        *b_run;   //!
TBranch        *b_lumi;   //!
TBranch        *b_event;   //!
TBranch        *b_irank;   //!
TBranch        *b_trigger;   //!
TBranch        *b_numPrimaryVertices;   //!
TBranch        *b_pv_x;   //!
TBranch        *b_pv_y;   //!
TBranch        *b_pv_z;   //!
TBranch        *b_ups1_mass_GenMatched;   //!
TBranch        *b_ups2_mass_GenMatched;   //!
TBranch        *b_ups1_y_GenMatched;   //!
TBranch        *b_ups2_y_GenMatched;   //!
TBranch        *b_ups1_pt_GenMatched;   //!
TBranch        *b_ups2_pt_GenMatched;   //!
TBranch        *b_ups1_mass_GenMatched_ID;   //!
TBranch        *b_ups1_pt_GenMatched_ID;   //!
TBranch        *b_ups1_y_GenMatched_ID;   //!
TBranch        *b_ups2_mass_GenMatched_ID;   //!
TBranch        *b_ups2_pt_GenMatched_ID;   //!
TBranch        *b_ups2_y_GenMatched_ID;   //!
TBranch        *b_ups1_mass_GenMatched_ID_OS_VTX;   //!
TBranch        *b_ups1_pt_GenMatched_ID_OS_VTX;   //!
TBranch        *b_ups1_y_GenMatched_ID_OS_VTX;   //!
TBranch        *b_ups2_mass_GenMatched_ID_OS_VTX;   //!
TBranch        *b_ups2_pt_GenMatched_ID_OS_VTX;   //!
TBranch        *b_ups2_y_GenMatched_ID_OS_VTX;   //!
TBranch        *b_fourmu_mass_allcuts;   //!
TBranch        *b_fourmu_mass_trigger;   //!
TBranch        *b_All_ups_muindex1;   //!
TBranch        *b_All_ups_muindex2;   //!
TBranch        *b_GEN_ups1_mu1_index;   //!
TBranch        *b_GEN_ups1_mu2_index;   //!
TBranch        *b_GEN_ups2_mu1_index;   //!
TBranch        *b_GEN_ups2_mu2_index;   //!
TBranch        *b_RECO_ups1_mu1_index;   //!
TBranch        *b_RECO_ups1_mu2_index;   //!
TBranch        *b_RECO_ups2_mu1_index;   //!
TBranch        *b_RECO_ups2_mu2_index;   //!
TBranch        *b_v_mu1Charge;   //!
TBranch        *b_v_mu2Charge;   //!
TBranch        *b_v_mu1_d0;   //!
TBranch        *b_v_mu1_d0err;   //!
TBranch        *b_v_mu2_d0;   //!
TBranch        *b_v_mu2_d0err;   //!
TBranch        *b_v_mu1_dz;   //!
TBranch        *b_v_mu1_dzerr;   //!
TBranch        *b_v_mu2_dz;   //!
TBranch        *b_v_mu2_dzerr;   //!
TBranch        *b_v_mu1_vz;   //!
TBranch        *b_v_mu2_vz;   //!
TBranch        *b_mu1_trg_dR;   //!
TBranch        *b_mu2_trg_dR;   //!
TBranch        *b_v_mumufit_Mass;   //!
TBranch        *b_v_mumufit_MassErr;   //!
TBranch        *b_v_mumufit_Mass_noMC;   //!
TBranch        *b_v_mumufit_MassErr_noMC;   //!
TBranch        *b_v_mumu_Pt;   //!
TBranch        *b_v_mumu_Rapidity;   //!
TBranch        *b_v_mumufit_VtxCL;   //!
TBranch        *b_v_mumufit_VtxCL_noMC;   //!
TBranch        *b_v_mumufit_VtxCL2;   //!
TBranch        *b_v_mumufit_DecayVtxX;   //!
TBranch        *b_v_mumufit_DecayVtxY;   //!
TBranch        *b_v_mumufit_DecayVtxZ;   //!
TBranch        *b_v_mumufit_DecayVtxXE;   //!
TBranch        *b_v_mumufit_DecayVtxYE;   //!
TBranch        *b_v_mumufit_DecayVtxZE;   //!
TBranch        *b_mu1_filtersMatched;   //!
TBranch        *b_mu2_filtersMatched;   //!
TBranch        *b_mu1_p4;   //!
TBranch        *b_mu2_p4;   //!
TBranch        *b_mu1charge;   //!
TBranch        *b_mu2charge;   //!
TBranch        *b_mu1_d0;   //!
TBranch        *b_mu1_d0err;   //!
TBranch        *b_mu2_d0;   //!
TBranch        *b_mu2_d0err;   //!
TBranch        *b_mu1_dz;   //!
TBranch        *b_mu1_dzerr;   //!
TBranch        *b_mu2_dz;   //!
TBranch        *b_mu2_dzerr;   //!
TBranch        *b_mu1_vz;   //!
TBranch        *b_mu2_vz;   //!
TBranch        *b_dimuon_p4;   //!
TBranch        *b_mumufit_Mass;   //!
TBranch        *b_mumufit_MassErr;   //!
TBranch        *b_mumufit_VtxCL;   //!
TBranch        *b_mumufit_VtxCL2;   //!
TBranch        *b_mumufit_DecayVtxX;   //!
TBranch        *b_mumufit_DecayVtxY;   //!
TBranch        *b_mumufit_DecayVtxZ;   //!
TBranch        *b_mumufit_DecayVtxXE;   //!
TBranch        *b_mumufit_DecayVtxYE;   //!
TBranch        *b_mumufit_DecayVtxZE;   //!
TBranch        *b_mumufit_p4;   //!
TBranch        *b_fourMuFit_Mass_allComb_mix;   //!
TBranch        *b_fourMuFit_Mass_mix;   //!
TBranch        *b_fourMuFit_MassErr_mix;   //!
TBranch        *b_fourMuFit_VtxX_mix;   //!
TBranch        *b_fourMuFit_VtxY_mix;   //!
TBranch        *b_fourMuFit_VtxZ_mix;   //!
TBranch        *b_fourMuFit_VtxProb_mix;   //!
TBranch        *b_fourMuFit_Chi2_mix;   //!
TBranch        *b_fourMuFit_ndof_mix;   //!
TBranch        *b_fourMuFit_3plus1_mix;   //!
TBranch        *b_fourMuFit_p4_mix;   //!
TBranch        *b_fourMuFit_mu1p4_mix;   //!
TBranch        *b_fourMuFit_mu2p4_mix;   //!
TBranch        *b_fourMuFit_mu3p4_mix;   //!
TBranch        *b_fourMuFit_mu4p4_mix;   //!
TBranch        *b_mu3Charge_mix;   //!
TBranch        *b_mu4Charge_mix;   //!
TBranch        *b_mu3_p4_mix;   //!
TBranch        *b_mu4_p4_mix;   //!
TBranch        *b_mu3_d0_mix;   //!
TBranch        *b_mu3_d0err_mix;   //!
TBranch        *b_mu4_d0_mix;   //!
TBranch        *b_mu4_d0err_mix;   //!
TBranch        *b_mu3_dz_mix;   //!
TBranch        *b_mu3_dzerr_mix;   //!
TBranch        *b_mu4_dz_mix;   //!
TBranch        *b_mu4_dzerr_mix;   //!
TBranch        *b_fourMuFit_Mass_mix3evts;   //!
TBranch        *b_fourMuFit_VtxProb_mix3evts;   //!
TBranch        *b_fourMuFit_p4_mix3evts;   //!
TBranch        *b_GENfinalState;   //!
TBranch        *b_passedFiducialSelection;   //!
TBranch        *b_GENmu_pt;   //!
TBranch        *b_GENmu_eta;   //!
TBranch        *b_GENmu_phi;   //!
TBranch        *b_GENmu_mass;   //!
TBranch        *b_GENmu_id;   //!
TBranch        *b_GENmu_status;   //!
TBranch        *b_GENmu_MomId;   //!
TBranch        *b_GENmu_MomMomId;   //!
TBranch        *b_GENups_DaughtersId;   //!
TBranch        *b_GENups_Daughter_mupt;   //!
TBranch        *b_GENups_Daughter_mueta;   //!
TBranch        *b_GENups_Daughter_muphi;   //!
TBranch        *b_GENups_Daughter_mumass;   //!
TBranch        *b_GENups_Daughter_mustatus;   //!
TBranch        *b_GENups_MomId;   //!
TBranch        *b_GENups_pt;   //!
TBranch        *b_GENdimu_mass;   //!
TBranch        *b_GENdimu_pt;   //!
TBranch        *b_GENdimu_eta;   //!
TBranch        *b_GENdimu_y;   //!
TBranch        *b_GENdimu_phi;   //!
TBranch        *b_GENups_eta;   //!
TBranch        *b_GENups_y;   //!
TBranch        *b_GENups_phi;   //!
TBranch        *b_GENups_mass;   //!
TBranch        *b_GENX_mass;   //!
TBranch        *b_GENX_pt;   //!
TBranch        *b_GENX_eta;   //!
TBranch        *b_GENX_y;   //!
TBranch        *b_GENX_phi;   //!
TBranch        *b_fourMuFit_Mass_allComb;   //!
TBranch        *b_fourMuFit_Mass;   //!
TBranch        *b_fourMuFit_MassErr;   //!
TBranch        *b_fourMuFit_Pt;   //!
TBranch        *b_fourMuFit_Eta;   //!
TBranch        *b_fourMuFit_Phi;   //!
TBranch        *b_fourMuFit_VtxX;   //!
TBranch        *b_fourMuFit_VtxY;   //!
TBranch        *b_fourMuFit_VtxZ;   //!
TBranch        *b_fourMuFit_VtxXE;   //!
TBranch        *b_fourMuFit_VtxYE;   //!
TBranch        *b_fourMuFit_VtxZE;   //!
TBranch        *b_fourMuFit_PVX;   //!
TBranch        *b_fourMuFit_PVY;   //!
TBranch        *b_fourMuFit_PVZ;   //!
TBranch        *b_fourMuFit_PVXE;   //!
TBranch        *b_fourMuFit_PVYE;   //!
TBranch        *b_fourMuFit_PVZE;   //!
TBranch        *b_fourMuFit_PV_XYE;   //!
TBranch        *b_fourMuFit_PV_XZE;   //!
TBranch        *b_fourMuFit_PV_YZE;   //!
TBranch        *b_fourMuFit_PV_CL;   //!
TBranch        *b_fourMuFit_VtxProb;   //!
TBranch        *b_fourMuFit_Double_ups_VtxProb;   //!
TBranch        *b_fourMuFit_ups1_VtxProb;   //!
TBranch        *b_fourMuFit_ups2_VtxProb;   //!
TBranch        *b_fourMuFit_ups1_VtxProb_noMC;   //!
TBranch        *b_fourMuFit_ups2_VtxProb_noMC;   //!
TBranch        *b_fourMuFit_ups1_pt;   //!
TBranch        *b_fourMuFit_ups2_pt;   //!
TBranch        *b_fourMuFit_ups1_rapidity;   //!
TBranch        *b_fourMuFit_ups2_rapidity;   //!
TBranch        *b_fourMuFit_ups1_mass;   //!
TBranch        *b_fourMuFit_ups2_mass;   //!
TBranch        *b_fourMuFit_ups1_massError;   //!
TBranch        *b_fourMuFit_ups2_massError;   //!
TBranch        *b_fourMuFit_ups1_VtxX;   //!
TBranch        *b_fourMuFit_ups1_VtxY;   //!
TBranch        *b_fourMuFit_ups1_VtxZ;   //!
TBranch        *b_fourMuFit_ups1_VtxXE;   //!
TBranch        *b_fourMuFit_ups1_VtxYE;   //!
TBranch        *b_fourMuFit_ups1_VtxZE;   //!
TBranch        *b_fourMuFit_ups2_VtxX;   //!
TBranch        *b_fourMuFit_ups2_VtxY;   //!
TBranch        *b_fourMuFit_ups2_VtxZ;   //!
TBranch        *b_fourMuFit_ups2_VtxXE;   //!
TBranch        *b_fourMuFit_ups2_VtxYE;   //!
TBranch        *b_fourMuFit_ups2_VtxZE;   //!
TBranch        *b_fourMuFit_wrong_ups1_mass;   //!
TBranch        *b_fourMuFit_wrong_ups2_mass;   //!
TBranch        *b_fourMuFit_wrong_ups1_massError;   //!
TBranch        *b_fourMuFit_wrong_ups2_massError;   //!
TBranch        *b_fourMuFit_Chi2;   //!
TBranch        *b_fourMuFit_ndof;   //!
TBranch        *b_fourMuFit_Double_ups_Chi2;   //!
TBranch        *b_fourMuFit_Double_ups_ndof;   //!
TBranch        *b_fourMuFit_mu1Pt;   //!
TBranch        *b_fourMuFit_mu1Eta;   //!
TBranch        *b_fourMuFit_mu1Phi;   //!
TBranch        *b_fourMuFit_mu1E;   //!
TBranch        *b_fourMuFit_mu1frompv;   //!
TBranch        *b_fourMuFit_mu2Pt;   //!
TBranch        *b_fourMuFit_mu2Eta;   //!
TBranch        *b_fourMuFit_mu2Phi;   //!
TBranch        *b_fourMuFit_mu2E;   //!
TBranch        *b_fourMuFit_mu2frompv;   //!
TBranch        *b_fourMuFit_mu3Pt;   //!
TBranch        *b_fourMuFit_mu3Eta;   //!
TBranch        *b_fourMuFit_mu3Phi;   //!
TBranch        *b_fourMuFit_mu3E;   //!
TBranch        *b_fourMuFit_mu3frompv;   //!
TBranch        *b_fourMuFit_mu4Pt;   //!
TBranch        *b_fourMuFit_mu4Eta;   //!
TBranch        *b_fourMuFit_mu4Phi;   //!
TBranch        *b_fourMuFit_mu4E;   //!
TBranch        *b_fourMuFit_mu4frompv;   //!
TBranch        *b_fourMuFit_mu3_trg_dR;   //!
TBranch        *b_fourMuFit_mu4_trg_dR;   //!
TBranch        *b_AllRecoMuons_Pt;   //!
TBranch        *b_AllRecoMuons_Eta;   //!
TBranch        *b_mu1_Pt;   //!
TBranch        *b_mu1_Eta;   //!
TBranch        *b_mu1_Phi;   //!
TBranch        *b_mu1_E;   //!
TBranch        *b_mu1_genindex;   //!
TBranch        *b_mu2_Pt;   //!
TBranch        *b_mu2_Eta;   //!
TBranch        *b_mu2_Phi;   //!
TBranch        *b_mu2_E;   //!
TBranch        *b_mu2_genindex;   //!
TBranch        *b_mu3_Pt;   //!
TBranch        *b_mu3_Eta;   //!
TBranch        *b_mu3_Phi;   //!
TBranch        *b_mu3_E;   //!
TBranch        *b_mu4_Pt;   //!
TBranch        *b_mu4_Eta;   //!
TBranch        *b_mu4_Phi;   //!
TBranch        *b_mu4_E;   //!
TBranch        *b_mu1Charge;   //!
TBranch        *b_mu2Charge;   //!
TBranch        *b_mu3Charge;   //!
TBranch        *b_mu4Charge;   //!
TBranch        *b_mu3_d0;   //!
TBranch        *b_mu3_d0err;   //!
TBranch        *b_mu4_d0;   //!
TBranch        *b_mu4_d0err;   //!
TBranch        *b_mu3_dz;   //!
TBranch        *b_mu3_dzerr;   //!
TBranch        *b_mu4_dz;   //!
TBranch        *b_mu4_dzerr;   //!
TBranch        *b_mu1_Soft;   //!
TBranch        *b_mu2_Soft;   //!
TBranch        *b_mu3_Soft;   //!
TBranch        *b_mu4_Soft;   //!
TBranch        *b_mu1_Tight;   //!
TBranch        *b_mu2_Tight;   //!
TBranch        *b_mu3_Tight;   //!
TBranch        *b_mu4_Tight;   //!
TBranch        *b_mu1_Medium;   //!
TBranch        *b_mu2_Medium;   //!
TBranch        *b_mu3_Medium;   //!
TBranch        *b_mu4_Medium;   //!
TBranch        *b_mu1_Loose;   //!
TBranch        *b_mu2_Loose;   //!
TBranch        *b_mu3_Loose;   //!
TBranch        *b_mu4_Loose;   //!
TBranch        *b_mu1_pdgID;   //!
TBranch        *b_mu2_pdgID;   //!
TBranch        *b_mu3_pdgID;   //!
TBranch        *b_mu4_pdgID;   //!
TBranch        *b_fourMuFit_mu12overlap;   //!
TBranch        *b_fourMuFit_mu13overlap;   //!
TBranch        *b_fourMuFit_mu14overlap;   //!
TBranch        *b_fourMuFit_mu23overlap;   //!
TBranch        *b_fourMuFit_mu24overlap;   //!
TBranch        *b_fourMuFit_mu34overlap;   //!
TBranch        *b_fourMuFit_mu12SharedSeg;   //!
TBranch        *b_fourMuFit_mu13SharedSeg;   //!
TBranch        *b_fourMuFit_mu14SharedSeg;   //!
TBranch        *b_fourMuFit_mu23SharedSeg;   //!
TBranch        *b_fourMuFit_mu24SharedSeg;   //!
TBranch        *b_fourMuFit_mu34SharedSeg;   //!
TBranch        *b_mu1_p4_bestYMass;   //!
TBranch        *b_mu2_p4_bestYMass;   //!
TBranch        *b_mu1Charge_bestYMass;   //!
TBranch        *b_mu2Charge_bestYMass;   //!
TBranch        *b_mu1_d0_bestYMass;   //!
TBranch        *b_mu1_d0err_bestYMass;   //!
TBranch        *b_mu2_d0_bestYMass;   //!
TBranch        *b_mu2_d0err_bestYMass;   //!
TBranch        *b_mu1_dz_bestYMass;   //!
TBranch        *b_mu1_dzerr_bestYMass;   //!
TBranch        *b_mu2_dz_bestYMass;   //!
TBranch        *b_mu2_dzerr_bestYMass;   //!
TBranch        *b_dimuon_p4_bestYMass;   //!
TBranch        *b_mumufit_Mass_bestYMass;   //!
TBranch        *b_mumufit_MassErr_bestYMass;   //!
TBranch        *b_mumufit_VtxCL_bestYMass;   //!
TBranch        *b_mumufit_VtxCL2_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxX_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxY_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxZ_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxXE_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxYE_bestYMass;   //!
TBranch        *b_mumufit_DecayVtxZE_bestYMass;   //!
TBranch        *b_mumufit_p4_bestYMass;   //!
TBranch        *b_bestVertex_and_bestYMass;   //!
TBranch        *b_fourMuFit_Mass_allComb_mix_bestYMass;   //!
TBranch        *b_fourMuFit_Mass_mix_bestYMass;   //!
TBranch        *b_fourMuFit_MassErr_mix_bestYMass;   //!
TBranch        *b_fourMuFit_VtxX_mix_bestYMass;   //!
TBranch        *b_fourMuFit_VtxY_mix_bestYMass;   //!
TBranch        *b_fourMuFit_VtxZ_mix_bestYMass;   //!
TBranch        *b_fourMuFit_VtxProb_mix_bestYMass;   //!
TBranch        *b_fourMuFit_Chi2_mix_bestYMass;   //!
TBranch        *b_fourMuFit_ndof_mix_bestYMass;   //!
TBranch        *b_fourMuFit_3plus1_mix_bestYMass;   //!
TBranch        *b_fourMuFit_p4_mix_bestYMass;   //!
TBranch        *b_fourMuFit_mu1p4_mix_bestYMass;   //!
TBranch        *b_fourMuFit_mu2p4_mix_bestYMass;   //!
TBranch        *b_fourMuFit_mu3p4_mix_bestYMass;   //!
TBranch        *b_fourMuFit_mu4p4_mix_bestYMass;   //!
TBranch        *b_mu3Charge_mix_bestYMass;   //!
TBranch        *b_mu4Charge_mix_bestYMass;   //!
TBranch        *b_mu3_p4_mix_bestYMass;   //!
TBranch        *b_mu4_p4_mix_bestYMass;   //!
TBranch        *b_mu3_d0_mix_bestYMass;   //!
TBranch        *b_mu3_d0err_mix_bestYMass;   //!
TBranch        *b_mu4_d0_mix_bestYMass;   //!
TBranch        *b_mu4_d0err_mix_bestYMass;   //!
TBranch        *b_mu3_dz_mix_bestYMass;   //!
TBranch        *b_mu3_dzerr_mix_bestYMass;   //!
TBranch        *b_mu4_dz_mix_bestYMass;   //!
TBranch        *b_mu4_dzerr_mix_bestYMass;   //!
TBranch        *b_fourMuFit_Mass_allComb_bestYMass;   //!
TBranch        *b_fourMuFit_Mass_bestYMass;   //!
TBranch        *b_fourMuFit_MassErr_bestYMass;   //!
TBranch        *b_fourMuFit_VtxX_bestYMass;   //!
TBranch        *b_fourMuFit_VtxY_bestYMass;   //!
TBranch        *b_fourMuFit_VtxZ_bestYMass;   //!
TBranch        *b_fourMuFit_VtxProb_bestYMass;   //!
TBranch        *b_fourMuFit_Chi2_bestYMass;   //!
TBranch        *b_fourMuFit_ndof_bestYMass;   //!
TBranch        *b_fourMuFit_p4_bestYMass;   //!
TBranch        *b_fourMuFit_mu1p4_bestYMass;   //!
TBranch        *b_fourMuFit_mu2p4_bestYMass;   //!
TBranch        *b_fourMuFit_mu3p4_bestYMass;   //!
TBranch        *b_fourMuFit_mu4p4_bestYMass;   //!
TBranch        *b_mu3Charge_bestYMass;   //!
TBranch        *b_mu4Charge_bestYMass;   //!
TBranch        *b_mu3_p4_bestYMass;   //!
TBranch        *b_mu4_p4_bestYMass;   //!
TBranch        *b_mu3_d0_bestYMass;   //!
TBranch        *b_mu3_d0err_bestYMass;   //!
TBranch        *b_mu4_d0_bestYMass;   //!
TBranch        *b_mu4_d0err_bestYMass;   //!
TBranch        *b_mu3_dz_bestYMass;   //!
TBranch        *b_mu3_dzerr_bestYMass;   //!
TBranch        *b_mu4_dz_bestYMass;   //!
TBranch        *b_mu4_dzerr_bestYMass;   //!
TBranch        *b_mu1_Tight_bestYMass;   //!
TBranch        *b_mu2_Tight_bestYMass;   //!
TBranch        *b_mu3_Tight_bestYMass;   //!
TBranch        *b_mu4_Tight_bestYMass;   //!
TBranch        *b_mu3_pdgID_bestYMass;   //!
TBranch        *b_mu4_pdgID_bestYMass;   //!
TBranch        *b_mu1_Medium_bestYMass;   //!
TBranch        *b_mu2_Medium_bestYMass;   //!
TBranch        *b_mu3_Medium_bestYMass;   //!
TBranch        *b_mu4_Medium_bestYMass;   //!
TBranch        *b_mu1_Loose_bestYMass;   //!
TBranch        *b_mu2_Loose_bestYMass;   //!
TBranch        *b_mu3_Loose_bestYMass;   //!
TBranch        *b_mu4_Loose_bestYMass;   //!
TBranch        *b_mother_pdgId;   //!
TBranch        *b_dimuon_pdgId;   //!
TBranch        *b_gen_dimuon_p4;   //!
TBranch        *b_gen_mu1_p4;   //!
TBranch        *b_gen_mu2_p4;   //!

void Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   All_ups_muindex1 = 0;
   All_ups_muindex2 = 0;
   v_mu1Charge = 0;
   v_mu2Charge = 0;
   v_mu1_d0 = 0;
   v_mu1_d0err = 0;
   v_mu2_d0 = 0;
   v_mu2_d0err = 0;
   v_mu1_dz = 0;
   v_mu1_dzerr = 0;
   v_mu2_dz = 0;
   v_mu2_dzerr = 0;
   v_mu1_vz = 0;
   v_mu2_vz = 0;
   mu1_trg_dR = 0;
   mu2_trg_dR = 0;
   v_mumufit_Mass = 0;
   v_mumufit_MassErr = 0;
   v_mumufit_Mass_noMC = 0;
   v_mumufit_MassErr_noMC = 0;
   v_mumu_Pt = 0;
   v_mumu_Rapidity = 0;
   v_mumufit_VtxCL = 0;
   v_mumufit_VtxCL_noMC = 0;
   v_mumufit_VtxCL2 = 0;
   v_mumufit_DecayVtxX = 0;
   v_mumufit_DecayVtxY = 0;
   v_mumufit_DecayVtxZ = 0;
   v_mumufit_DecayVtxXE = 0;
   v_mumufit_DecayVtxYE = 0;
   v_mumufit_DecayVtxZE = 0;
   mu1_filtersMatched = 0;
   mu2_filtersMatched = 0;
   mu1_p4 = 0;
   mu2_p4 = 0;
   dimuon_p4 = 0;
   mumufit_p4 = 0;
   fourMuFit_Mass_allComb_mix = 0;
   fourMuFit_p4_mix = 0;
   fourMuFit_mu1p4_mix = 0;
   fourMuFit_mu2p4_mix = 0;
   fourMuFit_mu3p4_mix = 0;
   fourMuFit_mu4p4_mix = 0;
   mu3_p4_mix = 0;
   mu4_p4_mix = 0;
   fourMuFit_p4_mix3evts = 0;
   GENmu_pt = 0;
   GENmu_eta = 0;
   GENmu_phi = 0;
   GENmu_mass = 0;
   GENmu_id = 0;
   GENmu_status = 0;
   GENmu_MomId = 0;
   GENmu_MomMomId = 0;
   GENups_DaughtersId = 0;
   GENups_Daughter_mupt = 0;
   GENups_Daughter_mueta = 0;
   GENups_Daughter_muphi = 0;
   GENups_Daughter_mumass = 0;
   GENups_Daughter_mustatus = 0;
   GENups_MomId = 0;
   GENups_pt = 0;
   GENdimu_mass = 0;
   GENdimu_pt = 0;
   GENdimu_eta = 0;
   GENdimu_y = 0;
   GENdimu_phi = 0;
   GENups_eta = 0;
   GENups_y = 0;
   GENups_phi = 0;
   GENups_mass = 0;
   GENX_mass = 0;
   GENX_pt = 0;
   GENX_eta = 0;
   GENX_y = 0;
   GENX_phi = 0;
   fourMuFit_Mass_allComb = 0;
   fourMuFit_Mass = 0;
   fourMuFit_MassErr = 0;
   fourMuFit_Pt = 0;
   fourMuFit_Eta = 0;
   fourMuFit_Phi = 0;
   fourMuFit_VtxX = 0;
   fourMuFit_VtxY = 0;
   fourMuFit_VtxZ = 0;
   fourMuFit_VtxXE = 0;
   fourMuFit_VtxYE = 0;
   fourMuFit_VtxZE = 0;
   fourMuFit_PVX = 0;
   fourMuFit_PVY = 0;
   fourMuFit_PVZ = 0;
   fourMuFit_PVXE = 0;
   fourMuFit_PVYE = 0;
   fourMuFit_PVZE = 0;
   fourMuFit_PV_XYE = 0;
   fourMuFit_PV_XZE = 0;
   fourMuFit_PV_YZE = 0;
   fourMuFit_PV_CL = 0;
   fourMuFit_VtxProb = 0;
   fourMuFit_Double_ups_VtxProb = 0;
   fourMuFit_ups1_VtxProb = 0;
   fourMuFit_ups2_VtxProb = 0;
   fourMuFit_ups1_VtxProb_noMC = 0;
   fourMuFit_ups2_VtxProb_noMC = 0;
   fourMuFit_ups1_pt = 0;
   fourMuFit_ups2_pt = 0;
   fourMuFit_ups1_rapidity = 0;
   fourMuFit_ups2_rapidity = 0;
   fourMuFit_ups1_mass = 0;
   fourMuFit_ups2_mass = 0;
   fourMuFit_ups1_massError = 0;
   fourMuFit_ups2_massError = 0;
   fourMuFit_ups1_VtxX = 0;
   fourMuFit_ups1_VtxY = 0;
   fourMuFit_ups1_VtxZ = 0;
   fourMuFit_ups1_VtxXE = 0;
   fourMuFit_ups1_VtxYE = 0;
   fourMuFit_ups1_VtxZE = 0;
   fourMuFit_ups2_VtxX = 0;
   fourMuFit_ups2_VtxY = 0;
   fourMuFit_ups2_VtxZ = 0;
   fourMuFit_ups2_VtxXE = 0;
   fourMuFit_ups2_VtxYE = 0;
   fourMuFit_ups2_VtxZE = 0;
   fourMuFit_wrong_ups1_mass = 0;
   fourMuFit_wrong_ups2_mass = 0;
   fourMuFit_wrong_ups1_massError = 0;
   fourMuFit_wrong_ups2_massError = 0;
   fourMuFit_Chi2 = 0;
   fourMuFit_ndof = 0;
   fourMuFit_Double_ups_Chi2 = 0;
   fourMuFit_Double_ups_ndof = 0;
   fourMuFit_mu1Pt = 0;
   fourMuFit_mu1Eta = 0;
   fourMuFit_mu1Phi = 0;
   fourMuFit_mu1E = 0;
   fourMuFit_mu1frompv = 0;
   fourMuFit_mu2Pt = 0;
   fourMuFit_mu2Eta = 0;
   fourMuFit_mu2Phi = 0;
   fourMuFit_mu2E = 0;
   fourMuFit_mu2frompv = 0;
   fourMuFit_mu3Pt = 0;
   fourMuFit_mu3Eta = 0;
   fourMuFit_mu3Phi = 0;
   fourMuFit_mu3E = 0;
   fourMuFit_mu3frompv = 0;
   fourMuFit_mu4Pt = 0;
   fourMuFit_mu4Eta = 0;
   fourMuFit_mu4Phi = 0;
   fourMuFit_mu4E = 0;
   fourMuFit_mu4frompv = 0;
   fourMuFit_mu3_trg_dR = 0;
   fourMuFit_mu4_trg_dR = 0;
   AllRecoMuons_Pt = 0;
   AllRecoMuons_Eta = 0;
   mu1_Pt = 0;
   mu1_Eta = 0;
   mu1_Phi = 0;
   mu1_E = 0;
   mu1_genindex = 0;
   mu2_Pt = 0;
   mu2_Eta = 0;
   mu2_Phi = 0;
   mu2_E = 0;
   mu2_genindex = 0;
   mu3_Pt = 0;
   mu3_Eta = 0;
   mu3_Phi = 0;
   mu3_E = 0;
   mu4_Pt = 0;
   mu4_Eta = 0;
   mu4_Phi = 0;
   mu4_E = 0;
   mu1Charge = 0;
   mu2Charge = 0;
   mu3Charge = 0;
   mu4Charge = 0;
   mu3_d0 = 0;
   mu3_d0err = 0;
   mu4_d0 = 0;
   mu4_d0err = 0;
   mu3_dz = 0;
   mu3_dzerr = 0;
   mu4_dz = 0;
   mu4_dzerr = 0;
   mu1_Soft = 0;
   mu2_Soft = 0;
   mu3_Soft = 0;
   mu4_Soft = 0;
   mu1_Tight = 0;
   mu2_Tight = 0;
   mu3_Tight = 0;
   mu4_Tight = 0;
   mu1_Medium = 0;
   mu2_Medium = 0;
   mu3_Medium = 0;
   mu4_Medium = 0;
   mu1_Loose = 0;
   mu2_Loose = 0;
   mu3_Loose = 0;
   mu4_Loose = 0;
   mu1_pdgID = 0;
   mu2_pdgID = 0;
   mu3_pdgID = 0;
   mu4_pdgID = 0;
   fourMuFit_mu12overlap = 0;
   fourMuFit_mu13overlap = 0;
   fourMuFit_mu14overlap = 0;
   fourMuFit_mu23overlap = 0;
   fourMuFit_mu24overlap = 0;
   fourMuFit_mu34overlap = 0;
   fourMuFit_mu12SharedSeg = 0;
   fourMuFit_mu13SharedSeg = 0;
   fourMuFit_mu14SharedSeg = 0;
   fourMuFit_mu23SharedSeg = 0;
   fourMuFit_mu24SharedSeg = 0;
   fourMuFit_mu34SharedSeg = 0;
   mu1_p4_bestYMass = 0;
   mu2_p4_bestYMass = 0;
   dimuon_p4_bestYMass = 0;
   mumufit_p4_bestYMass = 0;
   fourMuFit_Mass_allComb_mix_bestYMass = 0;
   fourMuFit_p4_mix_bestYMass = 0;
   fourMuFit_mu1p4_mix_bestYMass = 0;
   fourMuFit_mu2p4_mix_bestYMass = 0;
   fourMuFit_mu3p4_mix_bestYMass = 0;
   fourMuFit_mu4p4_mix_bestYMass = 0;
   mu3_p4_mix_bestYMass = 0;
   mu4_p4_mix_bestYMass = 0;
   fourMuFit_Mass_allComb_bestYMass = 0;
   fourMuFit_p4_bestYMass = 0;
   fourMuFit_mu1p4_bestYMass = 0;
   fourMuFit_mu2p4_bestYMass = 0;
   fourMuFit_mu3p4_bestYMass = 0;
   fourMuFit_mu4p4_bestYMass = 0;
   mu3_p4_bestYMass = 0;
   mu4_p4_bestYMass = 0;
   gen_dimuon_p4 = 0;
   gen_mu1_p4 = 0;
   gen_mu2_p4 = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("run", &run, &b_run);
   fChain->SetBranchAddress("lumi", &lumi, &b_lumi);
   fChain->SetBranchAddress("event", &event, &b_event);
   fChain->SetBranchAddress("irank", &irank, &b_irank);
   fChain->SetBranchAddress("trigger", &trigger, &b_trigger);
   fChain->SetBranchAddress("numPrimaryVertices", &numPrimaryVertices, &b_numPrimaryVertices);
   fChain->SetBranchAddress("pv_x", &pv_x, &b_pv_x);
   fChain->SetBranchAddress("pv_y", &pv_y, &b_pv_y);
   fChain->SetBranchAddress("pv_z", &pv_z, &b_pv_z);
   fChain->SetBranchAddress("ups1_mass_GenMatched", &ups1_mass_GenMatched, &b_ups1_mass_GenMatched);
   fChain->SetBranchAddress("ups2_mass_GenMatched", &ups2_mass_GenMatched, &b_ups2_mass_GenMatched);
   fChain->SetBranchAddress("ups1_y_GenMatched", &ups1_y_GenMatched, &b_ups1_y_GenMatched);
   fChain->SetBranchAddress("ups2_y_GenMatched", &ups2_y_GenMatched, &b_ups2_y_GenMatched);
   fChain->SetBranchAddress("ups1_pt_GenMatched", &ups1_pt_GenMatched, &b_ups1_pt_GenMatched);
   fChain->SetBranchAddress("ups2_pt_GenMatched", &ups2_pt_GenMatched, &b_ups2_pt_GenMatched);
   fChain->SetBranchAddress("ups1_mass_GenMatched_ID", &ups1_mass_GenMatched_ID, &b_ups1_mass_GenMatched_ID);
   fChain->SetBranchAddress("ups1_pt_GenMatched_ID", &ups1_pt_GenMatched_ID, &b_ups1_pt_GenMatched_ID);
   fChain->SetBranchAddress("ups1_y_GenMatched_ID", &ups1_y_GenMatched_ID, &b_ups1_y_GenMatched_ID);
   fChain->SetBranchAddress("ups2_mass_GenMatched_ID", &ups2_mass_GenMatched_ID, &b_ups2_mass_GenMatched_ID);
   fChain->SetBranchAddress("ups2_pt_GenMatched_ID", &ups2_pt_GenMatched_ID, &b_ups2_pt_GenMatched_ID);
   fChain->SetBranchAddress("ups2_y_GenMatched_ID", &ups2_y_GenMatched_ID, &b_ups2_y_GenMatched_ID);
   fChain->SetBranchAddress("ups1_mass_GenMatched_ID_OS_VTX", &ups1_mass_GenMatched_ID_OS_VTX, &b_ups1_mass_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("ups1_pt_GenMatched_ID_OS_VTX", &ups1_pt_GenMatched_ID_OS_VTX, &b_ups1_pt_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("ups1_y_GenMatched_ID_OS_VTX", &ups1_y_GenMatched_ID_OS_VTX, &b_ups1_y_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("ups2_mass_GenMatched_ID_OS_VTX", &ups2_mass_GenMatched_ID_OS_VTX, &b_ups2_mass_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("ups2_pt_GenMatched_ID_OS_VTX", &ups2_pt_GenMatched_ID_OS_VTX, &b_ups2_pt_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("ups2_y_GenMatched_ID_OS_VTX", &ups2_y_GenMatched_ID_OS_VTX, &b_ups2_y_GenMatched_ID_OS_VTX);
   fChain->SetBranchAddress("fourmu_mass_allcuts", &fourmu_mass_allcuts, &b_fourmu_mass_allcuts);
   fChain->SetBranchAddress("fourmu_mass_trigger", &fourmu_mass_trigger, &b_fourmu_mass_trigger);
   fChain->SetBranchAddress("All_ups_muindex1", &All_ups_muindex1, &b_All_ups_muindex1);
   fChain->SetBranchAddress("All_ups_muindex2", &All_ups_muindex2, &b_All_ups_muindex2);
   fChain->SetBranchAddress("GEN_ups1_mu1_index", &GEN_ups1_mu1_index, &b_GEN_ups1_mu1_index);
   fChain->SetBranchAddress("GEN_ups1_mu2_index", &GEN_ups1_mu2_index, &b_GEN_ups1_mu2_index);
   fChain->SetBranchAddress("GEN_ups2_mu1_index", &GEN_ups2_mu1_index, &b_GEN_ups2_mu1_index);
   fChain->SetBranchAddress("GEN_ups2_mu2_index", &GEN_ups2_mu2_index, &b_GEN_ups2_mu2_index);
   fChain->SetBranchAddress("RECO_ups1_mu1_index", &RECO_ups1_mu1_index, &b_RECO_ups1_mu1_index);
   fChain->SetBranchAddress("RECO_ups1_mu2_index", &RECO_ups1_mu2_index, &b_RECO_ups1_mu2_index);
   fChain->SetBranchAddress("RECO_ups2_mu1_index", &RECO_ups2_mu1_index, &b_RECO_ups2_mu1_index);
   fChain->SetBranchAddress("RECO_ups2_mu2_index", &RECO_ups2_mu2_index, &b_RECO_ups2_mu2_index);
   fChain->SetBranchAddress("v_mu1Charge", &v_mu1Charge, &b_v_mu1Charge);
   fChain->SetBranchAddress("v_mu2Charge", &v_mu2Charge, &b_v_mu2Charge);
   fChain->SetBranchAddress("v_mu1_d0", &v_mu1_d0, &b_v_mu1_d0);
   fChain->SetBranchAddress("v_mu1_d0err", &v_mu1_d0err, &b_v_mu1_d0err);
   fChain->SetBranchAddress("v_mu2_d0", &v_mu2_d0, &b_v_mu2_d0);
   fChain->SetBranchAddress("v_mu2_d0err", &v_mu2_d0err, &b_v_mu2_d0err);
   fChain->SetBranchAddress("v_mu1_dz", &v_mu1_dz, &b_v_mu1_dz);
   fChain->SetBranchAddress("v_mu1_dzerr", &v_mu1_dzerr, &b_v_mu1_dzerr);
   fChain->SetBranchAddress("v_mu2_dz", &v_mu2_dz, &b_v_mu2_dz);
   fChain->SetBranchAddress("v_mu2_dzerr", &v_mu2_dzerr, &b_v_mu2_dzerr);
   fChain->SetBranchAddress("v_mu1_vz", &v_mu1_vz, &b_v_mu1_vz);
   fChain->SetBranchAddress("v_mu2_vz", &v_mu2_vz, &b_v_mu2_vz);
   fChain->SetBranchAddress("mu1_trg_dR", &mu1_trg_dR, &b_mu1_trg_dR);
   fChain->SetBranchAddress("mu2_trg_dR", &mu2_trg_dR, &b_mu2_trg_dR);
   fChain->SetBranchAddress("v_mumufit_Mass", &v_mumufit_Mass, &b_v_mumufit_Mass);
   fChain->SetBranchAddress("v_mumufit_MassErr", &v_mumufit_MassErr, &b_v_mumufit_MassErr);
   fChain->SetBranchAddress("v_mumufit_Mass_noMC", &v_mumufit_Mass_noMC, &b_v_mumufit_Mass_noMC);
   fChain->SetBranchAddress("v_mumufit_MassErr_noMC", &v_mumufit_MassErr_noMC, &b_v_mumufit_MassErr_noMC);
   fChain->SetBranchAddress("v_mumu_Pt", &v_mumu_Pt, &b_v_mumu_Pt);
   fChain->SetBranchAddress("v_mumu_Rapidity", &v_mumu_Rapidity, &b_v_mumu_Rapidity);
   fChain->SetBranchAddress("v_mumufit_VtxCL", &v_mumufit_VtxCL, &b_v_mumufit_VtxCL);
   fChain->SetBranchAddress("v_mumufit_VtxCL_noMC", &v_mumufit_VtxCL_noMC, &b_v_mumufit_VtxCL_noMC);
   fChain->SetBranchAddress("v_mumufit_VtxCL2", &v_mumufit_VtxCL2, &b_v_mumufit_VtxCL2);
   fChain->SetBranchAddress("v_mumufit_DecayVtxX", &v_mumufit_DecayVtxX, &b_v_mumufit_DecayVtxX);
   fChain->SetBranchAddress("v_mumufit_DecayVtxY", &v_mumufit_DecayVtxY, &b_v_mumufit_DecayVtxY);
   fChain->SetBranchAddress("v_mumufit_DecayVtxZ", &v_mumufit_DecayVtxZ, &b_v_mumufit_DecayVtxZ);
   fChain->SetBranchAddress("v_mumufit_DecayVtxXE", &v_mumufit_DecayVtxXE, &b_v_mumufit_DecayVtxXE);
   fChain->SetBranchAddress("v_mumufit_DecayVtxYE", &v_mumufit_DecayVtxYE, &b_v_mumufit_DecayVtxYE);
   fChain->SetBranchAddress("v_mumufit_DecayVtxZE", &v_mumufit_DecayVtxZE, &b_v_mumufit_DecayVtxZE);
   fChain->SetBranchAddress("mu1_filtersMatched", &mu1_filtersMatched, &b_mu1_filtersMatched);
   fChain->SetBranchAddress("mu2_filtersMatched", &mu2_filtersMatched, &b_mu2_filtersMatched);
   fChain->SetBranchAddress("mu1_p4", &mu1_p4, &b_mu1_p4);
   fChain->SetBranchAddress("mu2_p4", &mu2_p4, &b_mu2_p4);
   fChain->SetBranchAddress("mu1charge", &mu1charge, &b_mu1charge);
   fChain->SetBranchAddress("mu2charge", &mu2charge, &b_mu2charge);
   fChain->SetBranchAddress("mu1_d0", &mu1_d0, &b_mu1_d0);
   fChain->SetBranchAddress("mu1_d0err", &mu1_d0err, &b_mu1_d0err);
   fChain->SetBranchAddress("mu2_d0", &mu2_d0, &b_mu2_d0);
   fChain->SetBranchAddress("mu2_d0err", &mu2_d0err, &b_mu2_d0err);
   fChain->SetBranchAddress("mu1_dz", &mu1_dz, &b_mu1_dz);
   fChain->SetBranchAddress("mu1_dzerr", &mu1_dzerr, &b_mu1_dzerr);
   fChain->SetBranchAddress("mu2_dz", &mu2_dz, &b_mu2_dz);
   fChain->SetBranchAddress("mu2_dzerr", &mu2_dzerr, &b_mu2_dzerr);
   fChain->SetBranchAddress("mu1_vz", &mu1_vz, &b_mu1_vz);
   fChain->SetBranchAddress("mu2_vz", &mu2_vz, &b_mu2_vz);
   fChain->SetBranchAddress("dimuon_p4", &dimuon_p4, &b_dimuon_p4);
   fChain->SetBranchAddress("mumufit_Mass", &mumufit_Mass, &b_mumufit_Mass);
   fChain->SetBranchAddress("mumufit_MassErr", &mumufit_MassErr, &b_mumufit_MassErr);
   fChain->SetBranchAddress("mumufit_VtxCL", &mumufit_VtxCL, &b_mumufit_VtxCL);
   fChain->SetBranchAddress("mumufit_VtxCL2", &mumufit_VtxCL2, &b_mumufit_VtxCL2);
   fChain->SetBranchAddress("mumufit_DecayVtxX", &mumufit_DecayVtxX, &b_mumufit_DecayVtxX);
   fChain->SetBranchAddress("mumufit_DecayVtxY", &mumufit_DecayVtxY, &b_mumufit_DecayVtxY);
   fChain->SetBranchAddress("mumufit_DecayVtxZ", &mumufit_DecayVtxZ, &b_mumufit_DecayVtxZ);
   fChain->SetBranchAddress("mumufit_DecayVtxXE", &mumufit_DecayVtxXE, &b_mumufit_DecayVtxXE);
   fChain->SetBranchAddress("mumufit_DecayVtxYE", &mumufit_DecayVtxYE, &b_mumufit_DecayVtxYE);
   fChain->SetBranchAddress("mumufit_DecayVtxZE", &mumufit_DecayVtxZE, &b_mumufit_DecayVtxZE);
   fChain->SetBranchAddress("mumufit_p4", &mumufit_p4, &b_mumufit_p4);
   fChain->SetBranchAddress("fourMuFit_Mass_allComb_mix", &fourMuFit_Mass_allComb_mix, &b_fourMuFit_Mass_allComb_mix);
   fChain->SetBranchAddress("fourMuFit_Mass_mix", &fourMuFit_Mass_mix, &b_fourMuFit_Mass_mix);
   fChain->SetBranchAddress("fourMuFit_MassErr_mix", &fourMuFit_MassErr_mix, &b_fourMuFit_MassErr_mix);
   fChain->SetBranchAddress("fourMuFit_VtxX_mix", &fourMuFit_VtxX_mix, &b_fourMuFit_VtxX_mix);
   fChain->SetBranchAddress("fourMuFit_VtxY_mix", &fourMuFit_VtxY_mix, &b_fourMuFit_VtxY_mix);
   fChain->SetBranchAddress("fourMuFit_VtxZ_mix", &fourMuFit_VtxZ_mix, &b_fourMuFit_VtxZ_mix);
   fChain->SetBranchAddress("fourMuFit_VtxProb_mix", &fourMuFit_VtxProb_mix, &b_fourMuFit_VtxProb_mix);
   fChain->SetBranchAddress("fourMuFit_Chi2_mix", &fourMuFit_Chi2_mix, &b_fourMuFit_Chi2_mix);
   fChain->SetBranchAddress("fourMuFit_ndof_mix", &fourMuFit_ndof_mix, &b_fourMuFit_ndof_mix);
   fChain->SetBranchAddress("fourMuFit_3plus1_mix", &fourMuFit_3plus1_mix, &b_fourMuFit_3plus1_mix);
   fChain->SetBranchAddress("fourMuFit_p4_mix", &fourMuFit_p4_mix, &b_fourMuFit_p4_mix);
   fChain->SetBranchAddress("fourMuFit_mu1p4_mix", &fourMuFit_mu1p4_mix, &b_fourMuFit_mu1p4_mix);
   fChain->SetBranchAddress("fourMuFit_mu2p4_mix", &fourMuFit_mu2p4_mix, &b_fourMuFit_mu2p4_mix);
   fChain->SetBranchAddress("fourMuFit_mu3p4_mix", &fourMuFit_mu3p4_mix, &b_fourMuFit_mu3p4_mix);
   fChain->SetBranchAddress("fourMuFit_mu4p4_mix", &fourMuFit_mu4p4_mix, &b_fourMuFit_mu4p4_mix);
   fChain->SetBranchAddress("mu3Charge_mix", &mu3Charge_mix, &b_mu3Charge_mix);
   fChain->SetBranchAddress("mu4Charge_mix", &mu4Charge_mix, &b_mu4Charge_mix);
   fChain->SetBranchAddress("mu3_p4_mix", &mu3_p4_mix, &b_mu3_p4_mix);
   fChain->SetBranchAddress("mu4_p4_mix", &mu4_p4_mix, &b_mu4_p4_mix);
   fChain->SetBranchAddress("mu3_d0_mix", &mu3_d0_mix, &b_mu3_d0_mix);
   fChain->SetBranchAddress("mu3_d0err_mix", &mu3_d0err_mix, &b_mu3_d0err_mix);
   fChain->SetBranchAddress("mu4_d0_mix", &mu4_d0_mix, &b_mu4_d0_mix);
   fChain->SetBranchAddress("mu4_d0err_mix", &mu4_d0err_mix, &b_mu4_d0err_mix);
   fChain->SetBranchAddress("mu3_dz_mix", &mu3_dz_mix, &b_mu3_dz_mix);
   fChain->SetBranchAddress("mu3_dzerr_mix", &mu3_dzerr_mix, &b_mu3_dzerr_mix);
   fChain->SetBranchAddress("mu4_dz_mix", &mu4_dz_mix, &b_mu4_dz_mix);
   fChain->SetBranchAddress("mu4_dzerr_mix", &mu4_dzerr_mix, &b_mu4_dzerr_mix);
   fChain->SetBranchAddress("fourMuFit_Mass_mix3evts", &fourMuFit_Mass_mix3evts, &b_fourMuFit_Mass_mix3evts);
   fChain->SetBranchAddress("fourMuFit_VtxProb_mix3evts", &fourMuFit_VtxProb_mix3evts, &b_fourMuFit_VtxProb_mix3evts);
   fChain->SetBranchAddress("fourMuFit_p4_mix3evts", &fourMuFit_p4_mix3evts, &b_fourMuFit_p4_mix3evts);
   fChain->SetBranchAddress("GENfinalState", &GENfinalState, &b_GENfinalState);
   fChain->SetBranchAddress("passedFiducialSelection", &passedFiducialSelection, &b_passedFiducialSelection);
   fChain->SetBranchAddress("GENmu_pt", &GENmu_pt, &b_GENmu_pt);
   fChain->SetBranchAddress("GENmu_eta", &GENmu_eta, &b_GENmu_eta);
   fChain->SetBranchAddress("GENmu_phi", &GENmu_phi, &b_GENmu_phi);
   fChain->SetBranchAddress("GENmu_mass", &GENmu_mass, &b_GENmu_mass);
   fChain->SetBranchAddress("GENmu_id", &GENmu_id, &b_GENmu_id);
   fChain->SetBranchAddress("GENmu_status", &GENmu_status, &b_GENmu_status);
   fChain->SetBranchAddress("GENmu_MomId", &GENmu_MomId, &b_GENmu_MomId);
   fChain->SetBranchAddress("GENmu_MomMomId", &GENmu_MomMomId, &b_GENmu_MomMomId);
   fChain->SetBranchAddress("GENups_DaughtersId", &GENups_DaughtersId, &b_GENups_DaughtersId);
   fChain->SetBranchAddress("GENups_Daughter_mupt", &GENups_Daughter_mupt, &b_GENups_Daughter_mupt);
   fChain->SetBranchAddress("GENups_Daughter_mueta", &GENups_Daughter_mueta, &b_GENups_Daughter_mueta);
   fChain->SetBranchAddress("GENups_Daughter_muphi", &GENups_Daughter_muphi, &b_GENups_Daughter_muphi);
   fChain->SetBranchAddress("GENups_Daughter_mumass", &GENups_Daughter_mumass, &b_GENups_Daughter_mumass);
   fChain->SetBranchAddress("GENups_Daughter_mustatus", &GENups_Daughter_mustatus, &b_GENups_Daughter_mustatus);
   fChain->SetBranchAddress("GENups_MomId", &GENups_MomId, &b_GENups_MomId);
   fChain->SetBranchAddress("GENups_pt", &GENups_pt, &b_GENups_pt);
   fChain->SetBranchAddress("GENdimu_mass", &GENdimu_mass, &b_GENdimu_mass);
   fChain->SetBranchAddress("GENdimu_pt", &GENdimu_pt, &b_GENdimu_pt);
   fChain->SetBranchAddress("GENdimu_eta", &GENdimu_eta, &b_GENdimu_eta);
   fChain->SetBranchAddress("GENdimu_y", &GENdimu_y, &b_GENdimu_y);
   fChain->SetBranchAddress("GENdimu_phi", &GENdimu_phi, &b_GENdimu_phi);
   fChain->SetBranchAddress("GENups_eta", &GENups_eta, &b_GENups_eta);
   fChain->SetBranchAddress("GENups_y", &GENups_y, &b_GENups_y);
   fChain->SetBranchAddress("GENups_phi", &GENups_phi, &b_GENups_phi);
   fChain->SetBranchAddress("GENups_mass", &GENups_mass, &b_GENups_mass);
   fChain->SetBranchAddress("GENX_mass", &GENX_mass, &b_GENX_mass);
   fChain->SetBranchAddress("GENX_pt", &GENX_pt, &b_GENX_pt);
   fChain->SetBranchAddress("GENX_eta", &GENX_eta, &b_GENX_eta);
   fChain->SetBranchAddress("GENX_y", &GENX_y, &b_GENX_y);
   fChain->SetBranchAddress("GENX_phi", &GENX_phi, &b_GENX_phi);
   fChain->SetBranchAddress("fourMuFit_Mass_allComb", &fourMuFit_Mass_allComb, &b_fourMuFit_Mass_allComb);
   fChain->SetBranchAddress("fourMuFit_Mass", &fourMuFit_Mass, &b_fourMuFit_Mass);
   fChain->SetBranchAddress("fourMuFit_MassErr", &fourMuFit_MassErr, &b_fourMuFit_MassErr);
   fChain->SetBranchAddress("fourMuFit_Pt", &fourMuFit_Pt, &b_fourMuFit_Pt);
   fChain->SetBranchAddress("fourMuFit_Eta", &fourMuFit_Eta, &b_fourMuFit_Eta);
   fChain->SetBranchAddress("fourMuFit_Phi", &fourMuFit_Phi, &b_fourMuFit_Phi);
   fChain->SetBranchAddress("fourMuFit_VtxX", &fourMuFit_VtxX, &b_fourMuFit_VtxX);
   fChain->SetBranchAddress("fourMuFit_VtxY", &fourMuFit_VtxY, &b_fourMuFit_VtxY);
   fChain->SetBranchAddress("fourMuFit_VtxZ", &fourMuFit_VtxZ, &b_fourMuFit_VtxZ);
   fChain->SetBranchAddress("fourMuFit_VtxXE", &fourMuFit_VtxXE, &b_fourMuFit_VtxXE);
   fChain->SetBranchAddress("fourMuFit_VtxYE", &fourMuFit_VtxYE, &b_fourMuFit_VtxYE);
   fChain->SetBranchAddress("fourMuFit_VtxZE", &fourMuFit_VtxZE, &b_fourMuFit_VtxZE);
   fChain->SetBranchAddress("fourMuFit_PVX", &fourMuFit_PVX, &b_fourMuFit_PVX);
   fChain->SetBranchAddress("fourMuFit_PVY", &fourMuFit_PVY, &b_fourMuFit_PVY);
   fChain->SetBranchAddress("fourMuFit_PVZ", &fourMuFit_PVZ, &b_fourMuFit_PVZ);
   fChain->SetBranchAddress("fourMuFit_PVXE", &fourMuFit_PVXE, &b_fourMuFit_PVXE);
   fChain->SetBranchAddress("fourMuFit_PVYE", &fourMuFit_PVYE, &b_fourMuFit_PVYE);
   fChain->SetBranchAddress("fourMuFit_PVZE", &fourMuFit_PVZE, &b_fourMuFit_PVZE);
   fChain->SetBranchAddress("fourMuFit_PV_XYE", &fourMuFit_PV_XYE, &b_fourMuFit_PV_XYE);
   fChain->SetBranchAddress("fourMuFit_PV_XZE", &fourMuFit_PV_XZE, &b_fourMuFit_PV_XZE);
   fChain->SetBranchAddress("fourMuFit_PV_YZE", &fourMuFit_PV_YZE, &b_fourMuFit_PV_YZE);
   fChain->SetBranchAddress("fourMuFit_PV_CL", &fourMuFit_PV_CL, &b_fourMuFit_PV_CL);
   fChain->SetBranchAddress("fourMuFit_VtxProb", &fourMuFit_VtxProb, &b_fourMuFit_VtxProb);
   fChain->SetBranchAddress("fourMuFit_Double_ups_VtxProb", &fourMuFit_Double_ups_VtxProb, &b_fourMuFit_Double_ups_VtxProb);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxProb", &fourMuFit_ups1_VtxProb, &b_fourMuFit_ups1_VtxProb);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxProb", &fourMuFit_ups2_VtxProb, &b_fourMuFit_ups2_VtxProb);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxProb_noMC", &fourMuFit_ups1_VtxProb_noMC, &b_fourMuFit_ups1_VtxProb_noMC);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxProb_noMC", &fourMuFit_ups2_VtxProb_noMC, &b_fourMuFit_ups2_VtxProb_noMC);
   fChain->SetBranchAddress("fourMuFit_ups1_pt", &fourMuFit_ups1_pt, &b_fourMuFit_ups1_pt);
   fChain->SetBranchAddress("fourMuFit_ups2_pt", &fourMuFit_ups2_pt, &b_fourMuFit_ups2_pt);
   fChain->SetBranchAddress("fourMuFit_ups1_rapidity", &fourMuFit_ups1_rapidity, &b_fourMuFit_ups1_rapidity);
   fChain->SetBranchAddress("fourMuFit_ups2_rapidity", &fourMuFit_ups2_rapidity, &b_fourMuFit_ups2_rapidity);
   fChain->SetBranchAddress("fourMuFit_ups1_mass", &fourMuFit_ups1_mass, &b_fourMuFit_ups1_mass);
   fChain->SetBranchAddress("fourMuFit_ups2_mass", &fourMuFit_ups2_mass, &b_fourMuFit_ups2_mass);
   fChain->SetBranchAddress("fourMuFit_ups1_massError", &fourMuFit_ups1_massError, &b_fourMuFit_ups1_massError);
   fChain->SetBranchAddress("fourMuFit_ups2_massError", &fourMuFit_ups2_massError, &b_fourMuFit_ups2_massError);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxX", &fourMuFit_ups1_VtxX, &b_fourMuFit_ups1_VtxX);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxY", &fourMuFit_ups1_VtxY, &b_fourMuFit_ups1_VtxY);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxZ", &fourMuFit_ups1_VtxZ, &b_fourMuFit_ups1_VtxZ);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxXE", &fourMuFit_ups1_VtxXE, &b_fourMuFit_ups1_VtxXE);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxYE", &fourMuFit_ups1_VtxYE, &b_fourMuFit_ups1_VtxYE);
   fChain->SetBranchAddress("fourMuFit_ups1_VtxZE", &fourMuFit_ups1_VtxZE, &b_fourMuFit_ups1_VtxZE);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxX", &fourMuFit_ups2_VtxX, &b_fourMuFit_ups2_VtxX);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxY", &fourMuFit_ups2_VtxY, &b_fourMuFit_ups2_VtxY);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxZ", &fourMuFit_ups2_VtxZ, &b_fourMuFit_ups2_VtxZ);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxXE", &fourMuFit_ups2_VtxXE, &b_fourMuFit_ups2_VtxXE);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxYE", &fourMuFit_ups2_VtxYE, &b_fourMuFit_ups2_VtxYE);
   fChain->SetBranchAddress("fourMuFit_ups2_VtxZE", &fourMuFit_ups2_VtxZE, &b_fourMuFit_ups2_VtxZE);
   fChain->SetBranchAddress("fourMuFit_wrong_ups1_mass", &fourMuFit_wrong_ups1_mass, &b_fourMuFit_wrong_ups1_mass);
   fChain->SetBranchAddress("fourMuFit_wrong_ups2_mass", &fourMuFit_wrong_ups2_mass, &b_fourMuFit_wrong_ups2_mass);
   fChain->SetBranchAddress("fourMuFit_wrong_ups1_massError", &fourMuFit_wrong_ups1_massError, &b_fourMuFit_wrong_ups1_massError);
   fChain->SetBranchAddress("fourMuFit_wrong_ups2_massError", &fourMuFit_wrong_ups2_massError, &b_fourMuFit_wrong_ups2_massError);
   fChain->SetBranchAddress("fourMuFit_Chi2", &fourMuFit_Chi2, &b_fourMuFit_Chi2);
   fChain->SetBranchAddress("fourMuFit_ndof", &fourMuFit_ndof, &b_fourMuFit_ndof);
   fChain->SetBranchAddress("fourMuFit_Double_ups_Chi2", &fourMuFit_Double_ups_Chi2, &b_fourMuFit_Double_ups_Chi2);
   fChain->SetBranchAddress("fourMuFit_Double_ups_ndof", &fourMuFit_Double_ups_ndof, &b_fourMuFit_Double_ups_ndof);
   fChain->SetBranchAddress("fourMuFit_mu1Pt", &fourMuFit_mu1Pt, &b_fourMuFit_mu1Pt);
   fChain->SetBranchAddress("fourMuFit_mu1Eta", &fourMuFit_mu1Eta, &b_fourMuFit_mu1Eta);
   fChain->SetBranchAddress("fourMuFit_mu1Phi", &fourMuFit_mu1Phi, &b_fourMuFit_mu1Phi);
   fChain->SetBranchAddress("fourMuFit_mu1E", &fourMuFit_mu1E, &b_fourMuFit_mu1E);
   fChain->SetBranchAddress("fourMuFit_mu1frompv", &fourMuFit_mu1frompv, &b_fourMuFit_mu1frompv);
   fChain->SetBranchAddress("fourMuFit_mu2Pt", &fourMuFit_mu2Pt, &b_fourMuFit_mu2Pt);
   fChain->SetBranchAddress("fourMuFit_mu2Eta", &fourMuFit_mu2Eta, &b_fourMuFit_mu2Eta);
   fChain->SetBranchAddress("fourMuFit_mu2Phi", &fourMuFit_mu2Phi, &b_fourMuFit_mu2Phi);
   fChain->SetBranchAddress("fourMuFit_mu2E", &fourMuFit_mu2E, &b_fourMuFit_mu2E);
   fChain->SetBranchAddress("fourMuFit_mu2frompv", &fourMuFit_mu2frompv, &b_fourMuFit_mu2frompv);
   fChain->SetBranchAddress("fourMuFit_mu3Pt", &fourMuFit_mu3Pt, &b_fourMuFit_mu3Pt);
   fChain->SetBranchAddress("fourMuFit_mu3Eta", &fourMuFit_mu3Eta, &b_fourMuFit_mu3Eta);
   fChain->SetBranchAddress("fourMuFit_mu3Phi", &fourMuFit_mu3Phi, &b_fourMuFit_mu3Phi);
   fChain->SetBranchAddress("fourMuFit_mu3E", &fourMuFit_mu3E, &b_fourMuFit_mu3E);
   fChain->SetBranchAddress("fourMuFit_mu3frompv", &fourMuFit_mu3frompv, &b_fourMuFit_mu3frompv);
   fChain->SetBranchAddress("fourMuFit_mu4Pt", &fourMuFit_mu4Pt, &b_fourMuFit_mu4Pt);
   fChain->SetBranchAddress("fourMuFit_mu4Eta", &fourMuFit_mu4Eta, &b_fourMuFit_mu4Eta);
   fChain->SetBranchAddress("fourMuFit_mu4Phi", &fourMuFit_mu4Phi, &b_fourMuFit_mu4Phi);
   fChain->SetBranchAddress("fourMuFit_mu4E", &fourMuFit_mu4E, &b_fourMuFit_mu4E);
   fChain->SetBranchAddress("fourMuFit_mu4frompv", &fourMuFit_mu4frompv, &b_fourMuFit_mu4frompv);
   fChain->SetBranchAddress("fourMuFit_mu3_trg_dR", &fourMuFit_mu3_trg_dR, &b_fourMuFit_mu3_trg_dR);
   fChain->SetBranchAddress("fourMuFit_mu4_trg_dR", &fourMuFit_mu4_trg_dR, &b_fourMuFit_mu4_trg_dR);
   fChain->SetBranchAddress("AllRecoMuons_Pt", &AllRecoMuons_Pt, &b_AllRecoMuons_Pt);
   fChain->SetBranchAddress("AllRecoMuons_Eta", &AllRecoMuons_Eta, &b_AllRecoMuons_Eta);
   fChain->SetBranchAddress("mu1_Pt", &mu1_Pt, &b_mu1_Pt);
   fChain->SetBranchAddress("mu1_Eta", &mu1_Eta, &b_mu1_Eta);
   fChain->SetBranchAddress("mu1_Phi", &mu1_Phi, &b_mu1_Phi);
   fChain->SetBranchAddress("mu1_E", &mu1_E, &b_mu1_E);
   fChain->SetBranchAddress("mu1_genindex", &mu1_genindex, &b_mu1_genindex);
   fChain->SetBranchAddress("mu2_Pt", &mu2_Pt, &b_mu2_Pt);
   fChain->SetBranchAddress("mu2_Eta", &mu2_Eta, &b_mu2_Eta);
   fChain->SetBranchAddress("mu2_Phi", &mu2_Phi, &b_mu2_Phi);
   fChain->SetBranchAddress("mu2_E", &mu2_E, &b_mu2_E);
   fChain->SetBranchAddress("mu2_genindex", &mu2_genindex, &b_mu2_genindex);
   fChain->SetBranchAddress("mu3_Pt", &mu3_Pt, &b_mu3_Pt);
   fChain->SetBranchAddress("mu3_Eta", &mu3_Eta, &b_mu3_Eta);
   fChain->SetBranchAddress("mu3_Phi", &mu3_Phi, &b_mu3_Phi);
   fChain->SetBranchAddress("mu3_E", &mu3_E, &b_mu3_E);
   fChain->SetBranchAddress("mu4_Pt", &mu4_Pt, &b_mu4_Pt);
   fChain->SetBranchAddress("mu4_Eta", &mu4_Eta, &b_mu4_Eta);
   fChain->SetBranchAddress("mu4_Phi", &mu4_Phi, &b_mu4_Phi);
   fChain->SetBranchAddress("mu4_E", &mu4_E, &b_mu4_E);
   fChain->SetBranchAddress("mu1Charge", &mu1Charge, &b_mu1Charge);
   fChain->SetBranchAddress("mu2Charge", &mu2Charge, &b_mu2Charge);
   fChain->SetBranchAddress("mu3Charge", &mu3Charge, &b_mu3Charge);
   fChain->SetBranchAddress("mu4Charge", &mu4Charge, &b_mu4Charge);
   fChain->SetBranchAddress("mu3_d0", &mu3_d0, &b_mu3_d0);
   fChain->SetBranchAddress("mu3_d0err", &mu3_d0err, &b_mu3_d0err);
   fChain->SetBranchAddress("mu4_d0", &mu4_d0, &b_mu4_d0);
   fChain->SetBranchAddress("mu4_d0err", &mu4_d0err, &b_mu4_d0err);
   fChain->SetBranchAddress("mu3_dz", &mu3_dz, &b_mu3_dz);
   fChain->SetBranchAddress("mu3_dzerr", &mu3_dzerr, &b_mu3_dzerr);
   fChain->SetBranchAddress("mu4_dz", &mu4_dz, &b_mu4_dz);
   fChain->SetBranchAddress("mu4_dzerr", &mu4_dzerr, &b_mu4_dzerr);
   fChain->SetBranchAddress("mu1_Soft", &mu1_Soft, &b_mu1_Soft);
   fChain->SetBranchAddress("mu2_Soft", &mu2_Soft, &b_mu2_Soft);
   fChain->SetBranchAddress("mu3_Soft", &mu3_Soft, &b_mu3_Soft);
   fChain->SetBranchAddress("mu4_Soft", &mu4_Soft, &b_mu4_Soft);
   fChain->SetBranchAddress("mu1_Tight", &mu1_Tight, &b_mu1_Tight);
   fChain->SetBranchAddress("mu2_Tight", &mu2_Tight, &b_mu2_Tight);
   fChain->SetBranchAddress("mu3_Tight", &mu3_Tight, &b_mu3_Tight);
   fChain->SetBranchAddress("mu4_Tight", &mu4_Tight, &b_mu4_Tight);
   fChain->SetBranchAddress("mu1_Medium", &mu1_Medium, &b_mu1_Medium);
   fChain->SetBranchAddress("mu2_Medium", &mu2_Medium, &b_mu2_Medium);
   fChain->SetBranchAddress("mu3_Medium", &mu3_Medium, &b_mu3_Medium);
   fChain->SetBranchAddress("mu4_Medium", &mu4_Medium, &b_mu4_Medium);
   fChain->SetBranchAddress("mu1_Loose", &mu1_Loose, &b_mu1_Loose);
   fChain->SetBranchAddress("mu2_Loose", &mu2_Loose, &b_mu2_Loose);
   fChain->SetBranchAddress("mu3_Loose", &mu3_Loose, &b_mu3_Loose);
   fChain->SetBranchAddress("mu4_Loose", &mu4_Loose, &b_mu4_Loose);
   fChain->SetBranchAddress("mu1_pdgID", &mu1_pdgID, &b_mu1_pdgID);
   fChain->SetBranchAddress("mu2_pdgID", &mu2_pdgID, &b_mu2_pdgID);
   fChain->SetBranchAddress("mu3_pdgID", &mu3_pdgID, &b_mu3_pdgID);
   fChain->SetBranchAddress("mu4_pdgID", &mu4_pdgID, &b_mu4_pdgID);
   fChain->SetBranchAddress("fourMuFit_mu12overlap", &fourMuFit_mu12overlap, &b_fourMuFit_mu12overlap);
   fChain->SetBranchAddress("fourMuFit_mu13overlap", &fourMuFit_mu13overlap, &b_fourMuFit_mu13overlap);
   fChain->SetBranchAddress("fourMuFit_mu14overlap", &fourMuFit_mu14overlap, &b_fourMuFit_mu14overlap);
   fChain->SetBranchAddress("fourMuFit_mu23overlap", &fourMuFit_mu23overlap, &b_fourMuFit_mu23overlap);
   fChain->SetBranchAddress("fourMuFit_mu24overlap", &fourMuFit_mu24overlap, &b_fourMuFit_mu24overlap);
   fChain->SetBranchAddress("fourMuFit_mu34overlap", &fourMuFit_mu34overlap, &b_fourMuFit_mu34overlap);
   fChain->SetBranchAddress("fourMuFit_mu12SharedSeg", &fourMuFit_mu12SharedSeg, &b_fourMuFit_mu12SharedSeg);
   fChain->SetBranchAddress("fourMuFit_mu13SharedSeg", &fourMuFit_mu13SharedSeg, &b_fourMuFit_mu13SharedSeg);
   fChain->SetBranchAddress("fourMuFit_mu14SharedSeg", &fourMuFit_mu14SharedSeg, &b_fourMuFit_mu14SharedSeg);
   fChain->SetBranchAddress("fourMuFit_mu23SharedSeg", &fourMuFit_mu23SharedSeg, &b_fourMuFit_mu23SharedSeg);
   fChain->SetBranchAddress("fourMuFit_mu24SharedSeg", &fourMuFit_mu24SharedSeg, &b_fourMuFit_mu24SharedSeg);
   fChain->SetBranchAddress("fourMuFit_mu34SharedSeg", &fourMuFit_mu34SharedSeg, &b_fourMuFit_mu34SharedSeg);
   fChain->SetBranchAddress("mu1_p4_bestYMass", &mu1_p4_bestYMass, &b_mu1_p4_bestYMass);
   fChain->SetBranchAddress("mu2_p4_bestYMass", &mu2_p4_bestYMass, &b_mu2_p4_bestYMass);
   fChain->SetBranchAddress("mu1Charge_bestYMass", &mu1Charge_bestYMass, &b_mu1Charge_bestYMass);
   fChain->SetBranchAddress("mu2Charge_bestYMass", &mu2Charge_bestYMass, &b_mu2Charge_bestYMass);
   fChain->SetBranchAddress("mu1_d0_bestYMass", &mu1_d0_bestYMass, &b_mu1_d0_bestYMass);
   fChain->SetBranchAddress("mu1_d0err_bestYMass", &mu1_d0err_bestYMass, &b_mu1_d0err_bestYMass);
   fChain->SetBranchAddress("mu2_d0_bestYMass", &mu2_d0_bestYMass, &b_mu2_d0_bestYMass);
   fChain->SetBranchAddress("mu2_d0err_bestYMass", &mu2_d0err_bestYMass, &b_mu2_d0err_bestYMass);
   fChain->SetBranchAddress("mu1_dz_bestYMass", &mu1_dz_bestYMass, &b_mu1_dz_bestYMass);
   fChain->SetBranchAddress("mu1_dzerr_bestYMass", &mu1_dzerr_bestYMass, &b_mu1_dzerr_bestYMass);
   fChain->SetBranchAddress("mu2_dz_bestYMass", &mu2_dz_bestYMass, &b_mu2_dz_bestYMass);
   fChain->SetBranchAddress("mu2_dzerr_bestYMass", &mu2_dzerr_bestYMass, &b_mu2_dzerr_bestYMass);
   fChain->SetBranchAddress("dimuon_p4_bestYMass", &dimuon_p4_bestYMass, &b_dimuon_p4_bestYMass);
   fChain->SetBranchAddress("mumufit_Mass_bestYMass", &mumufit_Mass_bestYMass, &b_mumufit_Mass_bestYMass);
   fChain->SetBranchAddress("mumufit_MassErr_bestYMass", &mumufit_MassErr_bestYMass, &b_mumufit_MassErr_bestYMass);
   fChain->SetBranchAddress("mumufit_VtxCL_bestYMass", &mumufit_VtxCL_bestYMass, &b_mumufit_VtxCL_bestYMass);
   fChain->SetBranchAddress("mumufit_VtxCL2_bestYMass", &mumufit_VtxCL2_bestYMass, &b_mumufit_VtxCL2_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxX_bestYMass", &mumufit_DecayVtxX_bestYMass, &b_mumufit_DecayVtxX_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxY_bestYMass", &mumufit_DecayVtxY_bestYMass, &b_mumufit_DecayVtxY_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxZ_bestYMass", &mumufit_DecayVtxZ_bestYMass, &b_mumufit_DecayVtxZ_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxXE_bestYMass", &mumufit_DecayVtxXE_bestYMass, &b_mumufit_DecayVtxXE_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxYE_bestYMass", &mumufit_DecayVtxYE_bestYMass, &b_mumufit_DecayVtxYE_bestYMass);
   fChain->SetBranchAddress("mumufit_DecayVtxZE_bestYMass", &mumufit_DecayVtxZE_bestYMass, &b_mumufit_DecayVtxZE_bestYMass);
   fChain->SetBranchAddress("mumufit_p4_bestYMass", &mumufit_p4_bestYMass, &b_mumufit_p4_bestYMass);
   fChain->SetBranchAddress("bestVertex_and_bestYMass", &bestVertex_and_bestYMass, &b_bestVertex_and_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Mass_allComb_mix_bestYMass", &fourMuFit_Mass_allComb_mix_bestYMass, &b_fourMuFit_Mass_allComb_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Mass_mix_bestYMass", &fourMuFit_Mass_mix_bestYMass, &b_fourMuFit_Mass_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_MassErr_mix_bestYMass", &fourMuFit_MassErr_mix_bestYMass, &b_fourMuFit_MassErr_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxX_mix_bestYMass", &fourMuFit_VtxX_mix_bestYMass, &b_fourMuFit_VtxX_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxY_mix_bestYMass", &fourMuFit_VtxY_mix_bestYMass, &b_fourMuFit_VtxY_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxZ_mix_bestYMass", &fourMuFit_VtxZ_mix_bestYMass, &b_fourMuFit_VtxZ_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxProb_mix_bestYMass", &fourMuFit_VtxProb_mix_bestYMass, &b_fourMuFit_VtxProb_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Chi2_mix_bestYMass", &fourMuFit_Chi2_mix_bestYMass, &b_fourMuFit_Chi2_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_ndof_mix_bestYMass", &fourMuFit_ndof_mix_bestYMass, &b_fourMuFit_ndof_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_3plus1_mix_bestYMass", &fourMuFit_3plus1_mix_bestYMass, &b_fourMuFit_3plus1_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_p4_mix_bestYMass", &fourMuFit_p4_mix_bestYMass, &b_fourMuFit_p4_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu1p4_mix_bestYMass", &fourMuFit_mu1p4_mix_bestYMass, &b_fourMuFit_mu1p4_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu2p4_mix_bestYMass", &fourMuFit_mu2p4_mix_bestYMass, &b_fourMuFit_mu2p4_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu3p4_mix_bestYMass", &fourMuFit_mu3p4_mix_bestYMass, &b_fourMuFit_mu3p4_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu4p4_mix_bestYMass", &fourMuFit_mu4p4_mix_bestYMass, &b_fourMuFit_mu4p4_mix_bestYMass);
   fChain->SetBranchAddress("mu3Charge_mix_bestYMass", &mu3Charge_mix_bestYMass, &b_mu3Charge_mix_bestYMass);
   fChain->SetBranchAddress("mu4Charge_mix_bestYMass", &mu4Charge_mix_bestYMass, &b_mu4Charge_mix_bestYMass);
   fChain->SetBranchAddress("mu3_p4_mix_bestYMass", &mu3_p4_mix_bestYMass, &b_mu3_p4_mix_bestYMass);
   fChain->SetBranchAddress("mu4_p4_mix_bestYMass", &mu4_p4_mix_bestYMass, &b_mu4_p4_mix_bestYMass);
   fChain->SetBranchAddress("mu3_d0_mix_bestYMass", &mu3_d0_mix_bestYMass, &b_mu3_d0_mix_bestYMass);
   fChain->SetBranchAddress("mu3_d0err_mix_bestYMass", &mu3_d0err_mix_bestYMass, &b_mu3_d0err_mix_bestYMass);
   fChain->SetBranchAddress("mu4_d0_mix_bestYMass", &mu4_d0_mix_bestYMass, &b_mu4_d0_mix_bestYMass);
   fChain->SetBranchAddress("mu4_d0err_mix_bestYMass", &mu4_d0err_mix_bestYMass, &b_mu4_d0err_mix_bestYMass);
   fChain->SetBranchAddress("mu3_dz_mix_bestYMass", &mu3_dz_mix_bestYMass, &b_mu3_dz_mix_bestYMass);
   fChain->SetBranchAddress("mu3_dzerr_mix_bestYMass", &mu3_dzerr_mix_bestYMass, &b_mu3_dzerr_mix_bestYMass);
   fChain->SetBranchAddress("mu4_dz_mix_bestYMass", &mu4_dz_mix_bestYMass, &b_mu4_dz_mix_bestYMass);
   fChain->SetBranchAddress("mu4_dzerr_mix_bestYMass", &mu4_dzerr_mix_bestYMass, &b_mu4_dzerr_mix_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Mass_allComb_bestYMass", &fourMuFit_Mass_allComb_bestYMass, &b_fourMuFit_Mass_allComb_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Mass_bestYMass", &fourMuFit_Mass_bestYMass, &b_fourMuFit_Mass_bestYMass);
   fChain->SetBranchAddress("fourMuFit_MassErr_bestYMass", &fourMuFit_MassErr_bestYMass, &b_fourMuFit_MassErr_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxX_bestYMass", &fourMuFit_VtxX_bestYMass, &b_fourMuFit_VtxX_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxY_bestYMass", &fourMuFit_VtxY_bestYMass, &b_fourMuFit_VtxY_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxZ_bestYMass", &fourMuFit_VtxZ_bestYMass, &b_fourMuFit_VtxZ_bestYMass);
   fChain->SetBranchAddress("fourMuFit_VtxProb_bestYMass", &fourMuFit_VtxProb_bestYMass, &b_fourMuFit_VtxProb_bestYMass);
   fChain->SetBranchAddress("fourMuFit_Chi2_bestYMass", &fourMuFit_Chi2_bestYMass, &b_fourMuFit_Chi2_bestYMass);
   fChain->SetBranchAddress("fourMuFit_ndof_bestYMass", &fourMuFit_ndof_bestYMass, &b_fourMuFit_ndof_bestYMass);
   fChain->SetBranchAddress("fourMuFit_p4_bestYMass", &fourMuFit_p4_bestYMass, &b_fourMuFit_p4_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu1p4_bestYMass", &fourMuFit_mu1p4_bestYMass, &b_fourMuFit_mu1p4_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu2p4_bestYMass", &fourMuFit_mu2p4_bestYMass, &b_fourMuFit_mu2p4_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu3p4_bestYMass", &fourMuFit_mu3p4_bestYMass, &b_fourMuFit_mu3p4_bestYMass);
   fChain->SetBranchAddress("fourMuFit_mu4p4_bestYMass", &fourMuFit_mu4p4_bestYMass, &b_fourMuFit_mu4p4_bestYMass);
   fChain->SetBranchAddress("mu3Charge_bestYMass", &mu3Charge_bestYMass, &b_mu3Charge_bestYMass);
   fChain->SetBranchAddress("mu4Charge_bestYMass", &mu4Charge_bestYMass, &b_mu4Charge_bestYMass);
   fChain->SetBranchAddress("mu3_p4_bestYMass", &mu3_p4_bestYMass, &b_mu3_p4_bestYMass);
   fChain->SetBranchAddress("mu4_p4_bestYMass", &mu4_p4_bestYMass, &b_mu4_p4_bestYMass);
   fChain->SetBranchAddress("mu3_d0_bestYMass", &mu3_d0_bestYMass, &b_mu3_d0_bestYMass);
   fChain->SetBranchAddress("mu3_d0err_bestYMass", &mu3_d0err_bestYMass, &b_mu3_d0err_bestYMass);
   fChain->SetBranchAddress("mu4_d0_bestYMass", &mu4_d0_bestYMass, &b_mu4_d0_bestYMass);
   fChain->SetBranchAddress("mu4_d0err_bestYMass", &mu4_d0err_bestYMass, &b_mu4_d0err_bestYMass);
   fChain->SetBranchAddress("mu3_dz_bestYMass", &mu3_dz_bestYMass, &b_mu3_dz_bestYMass);
   fChain->SetBranchAddress("mu3_dzerr_bestYMass", &mu3_dzerr_bestYMass, &b_mu3_dzerr_bestYMass);
   fChain->SetBranchAddress("mu4_dz_bestYMass", &mu4_dz_bestYMass, &b_mu4_dz_bestYMass);
   fChain->SetBranchAddress("mu4_dzerr_bestYMass", &mu4_dzerr_bestYMass, &b_mu4_dzerr_bestYMass);
   fChain->SetBranchAddress("mu1_Tight_bestYMass", &mu1_Tight_bestYMass, &b_mu1_Tight_bestYMass);
   fChain->SetBranchAddress("mu2_Tight_bestYMass", &mu2_Tight_bestYMass, &b_mu2_Tight_bestYMass);
   fChain->SetBranchAddress("mu3_Tight_bestYMass", &mu3_Tight_bestYMass, &b_mu3_Tight_bestYMass);
   fChain->SetBranchAddress("mu4_Tight_bestYMass", &mu4_Tight_bestYMass, &b_mu4_Tight_bestYMass);
   fChain->SetBranchAddress("mu3_pdgID_bestYMass", &mu3_pdgID_bestYMass, &b_mu3_pdgID_bestYMass);
   fChain->SetBranchAddress("mu4_pdgID_bestYMass", &mu4_pdgID_bestYMass, &b_mu4_pdgID_bestYMass);
   fChain->SetBranchAddress("mu1_Medium_bestYMass", &mu1_Medium_bestYMass, &b_mu1_Medium_bestYMass);
   fChain->SetBranchAddress("mu2_Medium_bestYMass", &mu2_Medium_bestYMass, &b_mu2_Medium_bestYMass);
   fChain->SetBranchAddress("mu3_Medium_bestYMass", &mu3_Medium_bestYMass, &b_mu3_Medium_bestYMass);
   fChain->SetBranchAddress("mu4_Medium_bestYMass", &mu4_Medium_bestYMass, &b_mu4_Medium_bestYMass);
   fChain->SetBranchAddress("mu1_Loose_bestYMass", &mu1_Loose_bestYMass, &b_mu1_Loose_bestYMass);
   fChain->SetBranchAddress("mu2_Loose_bestYMass", &mu2_Loose_bestYMass, &b_mu2_Loose_bestYMass);
   fChain->SetBranchAddress("mu3_Loose_bestYMass", &mu3_Loose_bestYMass, &b_mu3_Loose_bestYMass);
   fChain->SetBranchAddress("mu4_Loose_bestYMass", &mu4_Loose_bestYMass, &b_mu4_Loose_bestYMass);
   fChain->SetBranchAddress("mother_pdgId", &mother_pdgId, &b_mother_pdgId);
   fChain->SetBranchAddress("dimuon_pdgId", &dimuon_pdgId, &b_dimuon_pdgId);
   fChain->SetBranchAddress("gen_dimuon_p4", &gen_dimuon_p4, &b_gen_dimuon_p4);
   fChain->SetBranchAddress("gen_mu1_p4", &gen_mu1_p4, &b_gen_mu1_p4);
   fChain->SetBranchAddress("gen_mu2_p4", &gen_mu2_p4, &b_gen_mu2_p4);
}

