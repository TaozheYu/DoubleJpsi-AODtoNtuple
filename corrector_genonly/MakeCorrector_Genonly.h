//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul  4 11:45:40 2022 by ROOT version 6.20/06
// from TTree gen_tree/gen tree
// found on file: DPSToJJ_13TeV_pythia8_private_genonly_2016.root
//////////////////////////////////////////////////////////


#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.
#include "vector"
#include "vector"
#include "vector"

   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain


   vector<double>  *GENmu_pt;
   vector<double>  *GENmu_eta;
   vector<double>  *GENmu_phi;
   vector<double>  *GENmu_mass;
   vector<int>     *GENmu_id;
   vector<int>     *GENmu_status;
   vector<int>     *GENmu_MomId;
   vector<int>     *GENmu_MomMomId;
   Int_t           GEN_ups1_mu1_index;
   Int_t           GEN_ups1_mu2_index;
   Int_t           GEN_ups2_mu1_index;
   Int_t           GEN_ups2_mu2_index;
   vector<vector<int> > *GENups_DaughtersId;
   vector<vector<double> > *GENups_Daughter_mupt;
   vector<vector<double> > *GENups_Daughter_mueta;
   vector<vector<double> > *GENups_Daughter_murapidity;
   vector<vector<double> > *GENups_Daughter_muphi;
   vector<vector<double> > *GENups_Daughter_mumass;
   vector<vector<int> > *GENups_Daughter_muid;
   vector<vector<double> > *GENups_Daughter_mustatus;
   vector<vector<int> > *GENups_Daughter_barcode;
   vector<int>     *GENups_barcode;
   vector<int>     *GENups_MomId;
   vector<int>     *GENups_Mom_barcode;
   vector<double>  *GENups_pt;
   vector<double>  *GENups_eta;
   vector<double>  *GENups_y;
   vector<double>  *GENups_phi;
   vector<double>  *GENups_mass;
   vector<int>     *GENups_ID;
   vector<int>     *GENups_NDaughters;
   vector<double>  *GENdimu_mass;
   vector<double>  *GENdimu_pt;
   vector<double>  *GENdimu_eta;
   vector<double>  *GENdimu_y;
   vector<double>  *GENdimu_phi;

   // List of branches
   TBranch        *b_GENmu_pt;   //!
   TBranch        *b_GENmu_eta;   //!
   TBranch        *b_GENmu_phi;   //!
   TBranch        *b_GENmu_mass;   //!
   TBranch        *b_GENmu_id;   //!
   TBranch        *b_GENmu_status;   //!
   TBranch        *b_GENmu_MomId;   //!
   TBranch        *b_GENmu_MomMomId;   //!
   TBranch        *b_GEN_ups1_mu1_index;   //!
   TBranch        *b_GEN_ups1_mu2_index;   //!
   TBranch        *b_GEN_ups2_mu1_index;   //!
   TBranch        *b_GEN_ups2_mu2_index;   //!
   TBranch        *b_GENups_DaughtersId;   //!
   TBranch        *b_GENups_Daughter_mupt;   //!
   TBranch        *b_GENups_Daughter_mueta;   //!
   TBranch        *b_GENups_Daughter_murapidity;   //!
   TBranch        *b_GENups_Daughter_muphi;   //!
   TBranch        *b_GENups_Daughter_mumass;   //!
   TBranch        *b_GENups_Daughter_muid;   //!
   TBranch        *b_GENups_Daughter_mustatus;   //!
   TBranch        *b_GENups_Daughter_barcode;   //!
   TBranch        *b_GENups_barcode;   //!
   TBranch        *b_GENups_MomId;   //!
   TBranch        *b_GENups_Mom_barcode;   //!
   TBranch        *b_GENups_pt;   //!
   TBranch        *b_GENups_eta;   //!
   TBranch        *b_GENups_y;   //!
   TBranch        *b_GENups_phi;   //!
   TBranch        *b_GENups_mass;   //!
   TBranch        *b_GENups_ID;   //!
   TBranch        *b_GENups_NDaughters;   //!
   TBranch        *b_GENdimu_mass;   //!
   TBranch        *b_GENdimu_pt;   //!
   TBranch        *b_GENdimu_eta;   //!
   TBranch        *b_GENdimu_y;   //!
   TBranch        *b_GENdimu_phi;   //!




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
   GENups_Daughter_murapidity = 0;
   GENups_Daughter_muphi = 0;
   GENups_Daughter_mumass = 0;
   GENups_Daughter_muid = 0;
   GENups_Daughter_mustatus = 0;
   GENups_Daughter_barcode = 0;
   GENups_barcode = 0;
   GENups_MomId = 0;
   GENups_Mom_barcode = 0;
   GENups_pt = 0;
   GENups_eta = 0;
   GENups_y = 0;
   GENups_phi = 0;
   GENups_mass = 0;
   GENups_ID = 0;
   GENups_NDaughters = 0;
   GENdimu_mass = 0;
   GENdimu_pt = 0;
   GENdimu_eta = 0;
   GENdimu_y = 0;
   GENdimu_phi = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("GENmu_pt", &GENmu_pt, &b_GENmu_pt);
   fChain->SetBranchAddress("GENmu_eta", &GENmu_eta, &b_GENmu_eta);
   fChain->SetBranchAddress("GENmu_phi", &GENmu_phi, &b_GENmu_phi);
   fChain->SetBranchAddress("GENmu_mass", &GENmu_mass, &b_GENmu_mass);
   fChain->SetBranchAddress("GENmu_id", &GENmu_id, &b_GENmu_id);
   fChain->SetBranchAddress("GENmu_status", &GENmu_status, &b_GENmu_status);
   fChain->SetBranchAddress("GENmu_MomId", &GENmu_MomId, &b_GENmu_MomId);
   fChain->SetBranchAddress("GENmu_MomMomId", &GENmu_MomMomId, &b_GENmu_MomMomId);
   fChain->SetBranchAddress("GEN_ups1_mu1_index", &GEN_ups1_mu1_index, &b_GEN_ups1_mu1_index);
   fChain->SetBranchAddress("GEN_ups1_mu2_index", &GEN_ups1_mu2_index, &b_GEN_ups1_mu2_index);
   fChain->SetBranchAddress("GEN_ups2_mu1_index", &GEN_ups2_mu1_index, &b_GEN_ups2_mu1_index);
   fChain->SetBranchAddress("GEN_ups2_mu2_index", &GEN_ups2_mu2_index, &b_GEN_ups2_mu2_index);
   fChain->SetBranchAddress("GENups_DaughtersId", &GENups_DaughtersId, &b_GENups_DaughtersId);
   fChain->SetBranchAddress("GENups_Daughter_mupt", &GENups_Daughter_mupt, &b_GENups_Daughter_mupt);
   fChain->SetBranchAddress("GENups_Daughter_mueta", &GENups_Daughter_mueta, &b_GENups_Daughter_mueta);
   fChain->SetBranchAddress("GENups_Daughter_murapidity", &GENups_Daughter_murapidity, &b_GENups_Daughter_murapidity);
   fChain->SetBranchAddress("GENups_Daughter_muphi", &GENups_Daughter_muphi, &b_GENups_Daughter_muphi);
   fChain->SetBranchAddress("GENups_Daughter_mumass", &GENups_Daughter_mumass, &b_GENups_Daughter_mumass);
   fChain->SetBranchAddress("GENups_Daughter_muid", &GENups_Daughter_muid, &b_GENups_Daughter_muid);
   fChain->SetBranchAddress("GENups_Daughter_mustatus", &GENups_Daughter_mustatus, &b_GENups_Daughter_mustatus);
   fChain->SetBranchAddress("GENups_Daughter_barcode", &GENups_Daughter_barcode, &b_GENups_Daughter_barcode);
   fChain->SetBranchAddress("GENups_barcode", &GENups_barcode, &b_GENups_barcode);
   fChain->SetBranchAddress("GENups_MomId", &GENups_MomId, &b_GENups_MomId);
   fChain->SetBranchAddress("GENups_Mom_barcode", &GENups_Mom_barcode, &b_GENups_Mom_barcode);
   fChain->SetBranchAddress("GENups_pt", &GENups_pt, &b_GENups_pt);
   fChain->SetBranchAddress("GENups_eta", &GENups_eta, &b_GENups_eta);
   fChain->SetBranchAddress("GENups_y", &GENups_y, &b_GENups_y);
   fChain->SetBranchAddress("GENups_phi", &GENups_phi, &b_GENups_phi);
   fChain->SetBranchAddress("GENups_mass", &GENups_mass, &b_GENups_mass);
   fChain->SetBranchAddress("GENups_ID", &GENups_ID, &b_GENups_ID);
   fChain->SetBranchAddress("GENups_NDaughters", &GENups_NDaughters, &b_GENups_NDaughters);
   fChain->SetBranchAddress("GENdimu_mass", &GENdimu_mass, &b_GENdimu_mass);
   fChain->SetBranchAddress("GENdimu_pt", &GENdimu_pt, &b_GENdimu_pt);
   fChain->SetBranchAddress("GENdimu_eta", &GENdimu_eta, &b_GENdimu_eta);
   fChain->SetBranchAddress("GENdimu_y", &GENdimu_y, &b_GENdimu_y);
   fChain->SetBranchAddress("GENdimu_phi", &GENdimu_phi, &b_GENdimu_phi);
}

