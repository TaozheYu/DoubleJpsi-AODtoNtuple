TFile *file_off = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/DPSToJJ_13TeV_pythia8_official.root");
TTree *Tree_off = (TTree*)file_off->Get("rootuple/oniaTree");

TFile *file_pri = TFile::Open("/publicfs/cms/user/yutz/Double_JPci/TsHAODNtuple/DPSToJJ_13TeV_pythia8_private.root");
TTree *Tree_pri = (TTree*)file_pri->Get("rootuple/oniaTree");

void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX);
