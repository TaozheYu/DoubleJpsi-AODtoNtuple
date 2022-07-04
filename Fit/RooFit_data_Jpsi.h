//TFile *file = TFile::Open("/eos/user/t/tayu/DoubleJpsi/Skim/2016/Run2016.root");
TFile *file = TFile::Open("/eos/user/t/tayu/DoubleJpsi/Skim/2016/Run2016.root");
TTree *Tree = (TTree*)file->Get("Events");

void GetHisto(char CUT[1000], TTree *Tree, TH1F* & histo, const char *plot, int BIN, float MIN, float MAX);
void GetHisto2D(char CUT[1000], TTree *Tree, TH2F* & histo, const char *plotX,const char *plotY, int XBIN, float XMIN, float XMAX, int YBIN, float YMIN, float YMAX);
void MakeHistoErrors(int m, TH1F* &histo, TH1F* histo_up, TH1F* histo_do);
