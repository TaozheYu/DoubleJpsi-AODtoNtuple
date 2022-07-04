#include "RooFit_data_Jpsi.h"
//#ifndef __CINT__
//#include "RooGlobalFunc.h"
//#endif
#include "RooRealVar.h"
#include "RooDataSet.h"
#include "RooDataHist.h"
#include "RooFFTConvPdf.h"
//#include "RooCBShape.h"
//#include "RooGaussian.h"
//#include "TCanvas.h"
//#include "RooPlot.h"
//#include "TTree.h"
//#include "TH1D.h"
//#include "TRandom.h"
using namespace RooFit;

void RooFit_data_Jpsi(){
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location
  gStyle->SetTitleY(0.96); //title Y location
  gStyle->SetPaintTextFormat(".2f");
  gErrorIgnoreLevel = kError;
  //using namespace std;
  TCanvas* canvas = new TCanvas("canvas","canvas",0,0,900,600);
  TH1F *data; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  TH1F *data_up; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  TH1F *data_do; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  RooRealVar x("x", "x", 2.80, 3.40);
  x.setBins(1000,"cache");

  //Construct Jpsi Jpsi pdf
  RooRealVar PDGmZ("PDGmZ","PDGmZ",3.092);
  RooRealVar PDGwZ("PDGwZ","PDGwZ",0.03,0.01,0.08);
  RooBreitWigner PDGBW("PDGBW","PDGBW",x,PDGmZ,PDGwZ);
  PDGmZ.setConstant(kTRUE);
  PDGwZ.setConstant(kTRUE);
  //Jpsi+Jpsi
  RooRealVar Jpsi_mean("Jpsi_mean", "Jpsi mean", 3.092); 
  RooRealVar Jpsi_width("Jpsi_width", "Jpsi width",0.03,0.01,0.1);
  RooRealVar alpha_1("alpha_1", "",1,0,10);
  RooRealVar alpha_2("alpha_2", "",1,0,10);
  RooRealVar n_1("n_1","",10,0,70);
  RooRealVar n_2("n_2","",10,0,500);
  RooDoubleCB DCB("DCB","DCB",x,Jpsi_mean,Jpsi_width,alpha_1,n_1,alpha_2,n_2);
  //RooRealVar g1frac("g1frac","",0.5);
  //RooRealVar g2frac("g2frac","",0,1.0);
  //RooCBShape CB_1("CB_1","CB_1",x,Jpsi_mean,Jpsi_width,alpha_1,n_1);
  //RooCBShape CB_2("CB_2","CB_2",x,Jpsi_mean,Jpsi_width,alpha_2,n_2);
  //RooAddPdf  DCB("DCB","CB_1+CB_2",RooArgList(CB_1,CB_2),RooArgList(g1frac));
  //RooAddPdf  BW_DCB("BW_DCB","BW+CB_1+CB_2",RooArgList(PDGBW,DCB),RooArgList(g2frac));
  //RooFFTConvPdf BW_DCB("BW_DCB","BW_DCB",x,PDGBW,DCB);
  //RooFFTConvPdf BW_DCB("BW_DCB","BW_DCB",x,PDGBW,CB_1);
 
  //Jpsi+comb
  //RooGaussian gauss("gauss","gaussian PDF",x,Jpsi_mean,Jpsi_width); 

 
  //Construct combinatorial pdf
  RooRealVar a0("a0","a0",0.01,-1,1);
  RooRealVar a1("a1","a1",0.01,-1,1);
  RooChebychev comb("comb","comb",x,RooArgList(a0,a1));

  //construct composite pdf
  RooRealVar gfrac1("gfrac1","",0.8,0.6,0.9);
  //RooRealVar gfrac2("gfrac2","",0.5,0.4,0.6);
  //RooAddPdf model("model","model",RooArgList(DCB,gauss,comb),RooArgList(gfrac1,gfrac2));
  RooAddPdf model("model","model",RooArgList(DCB,comb),RooArgList(gfrac1));
  //RooAddPdf model("model","model",RooArgList(BW_DCB,comb),RooArgList(gfrac));


  vector<TString> name;         vector<int> bin;   vector<float> Min;  vector<float> Max;  vector<TString> axis;
  name.push_back("Jpsi1_mass"); bin.push_back(60); Min.push_back(2.8); Max.push_back(3.4); axis.push_back("m_{muon12}");
  name.push_back("Jpsi2_mass"); bin.push_back(60); Min.push_back(2.8); Max.push_back(3.4); axis.push_back("m_{muon34}");


  for(int i=0; i<name.size(); i++){
    const char *plot = name[i];
    char CUTpre[1000];
    char CUT[1000];
    char CUT1[1000];
    char CUT2[1000];
    //sprintf(CUT,"");
    sprintf(CUTpre,"(((Jpsi1_pt>6 && abs(Jpsi1_eta)>1)||(Jpsi1_pt>7 && abs(Jpsi1_eta)<1)) && ((Jpsi2_pt>6 && abs(Jpsi2_eta)>1)||(Jpsi2_pt>7 && abs(Jpsi2_eta)<1)))");
    //sprintf(CUT,"(1./((w_acc_Jpsi1*w_acc_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) *w_trig_Jpsi12)) * *%s ", CUTpre);
    sprintf(CUT,"1 *%s ", CUTpre);
    sprintf(CUT1,"(1./((w_acc_Jpsi1_do*w_acc_Jpsi2_do) * (w_reco_Jpsi1_do*w_reco_Jpsi2_do) * (w_eff_Jpsi1_do*w_eff_Jpsi2_do) *w_trig_Jpsi12_do)) *%s", CUTpre);
    sprintf(CUT2,"(1./((w_acc_Jpsi1_up*w_acc_Jpsi2_up) * (w_reco_Jpsi1_up*w_reco_Jpsi2_up) * (w_eff_Jpsi1_up*w_eff_Jpsi2_up) *w_trig_Jpsi12_up)) *%s", CUTpre);

    GetHisto(CUT, Tree, data ,plot,bin[i],Min[i],Max[i]);
    GetHisto(CUT1, Tree, data_up ,plot,bin[i],Min[i],Max[i]);
    GetHisto(CUT2, Tree, data_do ,plot,bin[i],Min[i],Max[i]);
       


    for(int j=1; j<data->GetNbinsX()+1; j++){
      //MakeHistoErrors(j,data,data_up,data_do);
      data->SetBinContent(j,data->GetBinContent(j));
      data->SetBinError(j,sqrt(data->GetBinContent(j)));
    }
    //DPS->Draw();
    //canvas->SaveAs("DPS.pdf") ;

    TH1F *h_DCB; h_DCB = (TH1F*)data->Clone(); h_DCB->SetLineColor(kBlue); h_DCB->SetLineWidth(1); 
    TH1F *h_gauss; h_gauss = (TH1F*)data->Clone(); h_gauss->SetFillStyle(3005); h_gauss->SetFillColor(kRed); h_gauss->SetLineStyle(3005); h_gauss->SetMarkerSize(0); h_gauss->SetLineColor(0); h_gauss->SetLineWidth(0);
    TH1F *h_comb; h_comb = (TH1F*)data->Clone(); h_comb->SetFillStyle(3005); h_comb->SetFillColor(12); h_comb->SetLineStyle(3005); h_comb->SetMarkerSize(0); h_comb->SetLineColor(0); h_comb->SetLineWidth(0);
    TH1F *h_total; h_total = (TH1F*)data->Clone(); h_total->SetLineColor(kRed); h_total->SetLineWidth(1);


    RooDataHist roohist_data("roohist_data","roohist_data",x,data);
    RooPlot* frame_data = x.frame();
    model.fitTo(roohist_data,SumW2Error(kTRUE),PrintLevel(-1));
    roohist_data.plotOn(frame_data);
    model.plotOn(frame_data,LineColor(kRed),LineWidth(1)); 
    model.plotOn(frame_data,Components(DCB),LineColor(kBlue),LineWidth(1)); 
    //model.plotOn(frame_data,Components(gauss),FillStyle(3005),FillColor(kRed),LineColor(kRed),LineWidth(1),DrawOption("F")); 
    model.plotOn(frame_data,Components(comb),FillStyle(3005),FillColor(12),LineColor(1),LineWidth(1),DrawOption("F")); 
    frame_data->SetTitle(""); 
    frame_data->GetXaxis()->SetTitle(axis[i]); 
    frame_data->GetYaxis()->SetTitle("Events/(0.01 GeV)"); 
    frame_data->GetYaxis()->SetTitleOffset(1.30);
    frame_data->Draw();



    TPad *pad = new TPad("pad","pad",0.01,0.01,0.99,0.99);
    gPad->RedrawAxis();
    TString channelText = "";
    float channelTextFont   = 42;
    float channelTextSize   = 0.060;
    TString cmsText     = "CMS";
    float cmsTextFont   = 61;  // default is helvetic-bold
    bool writeExtraText = true;
    TString extraText   = "Simulation";
    //TString extraText   = "";
    float extraTextFont = 52;  // default is helvetica-italics
    // text sizes and text offsets with respect to the top frame in unit of the top margin size
    float lumiTextSize     = 0.7;
    float lumiTextOffset   = 0.2;
    float cmsTextSize      = 0.75;
    float cmsTextOffset    = 0.1;  // only used in outOfFrame version
    float relPosX    = 0.045;
    float relPosY    = 0.035;
    float relExtraDY = 1.2;
    // ratio of "CMS" and extra text size
    float extraOverCmsTextSize  = 0.65;
    TString lumi_13TeV;
    lumi_13TeV = "36.3 fb^{-1}";
    TString lumiText;
    lumiText += lumi_13TeV;
    lumiText += " (13 TeV)";
    float t = pad->GetTopMargin();
    float b = pad->GetBottomMargin();
    float r = pad->GetRightMargin();
    float l = pad->GetLeftMargin();
    TLatex latex;
    latex.SetNDC();
    latex.SetTextAngle(0);
    latex.SetTextColor(kBlack);
    float extraTextSize = extraOverCmsTextSize*cmsTextSize;
    latex.SetTextFont(42);
    latex.SetTextAlign(31);
    latex.SetTextSize(lumiTextSize*t);
    latex.DrawLatex(1-r,0.92,lumiText);
    latex.SetTextFont(cmsTextFont);
    latex.SetTextAlign(11);
    latex.SetTextSize(cmsTextSize*t);
    latex.DrawLatex(l+0.08, 1-t+lumiTextOffset*t-0.12,cmsText);//0.075
    latex.SetTextFont(extraTextFont);
    latex.SetTextSize(extraTextSize*t);
    //latex.DrawLatex(l+0.08, 1-t+lumiTextOffset*t-0.19, extraText);
    //latex.SetTextFont(channelTextFont);
    //latex.SetTextSize(channelTextSize);
    //latex.DrawLatex(l+0.165, 1-t+lumiTextOffset*t-0.19, channelText1);
    //latex.DrawLatex(l+0.165, 1-t+lumiTextOffset*t-0.28, channelText2);




    TLegend *pl2 = new TLegend(0.60,0.60,0.88,0.87);
    pl2->SetTextSize(0.030);
    pl2->SetTextFont(62);
    pl2->SetFillColor(0);
    TLegendEntry *ple2 = pl2->AddEntry(&roohist_data, "Observed",  "PE");
    pl2->AddEntry(h_total, "total fit model", "L");
    pl2->AddEntry(h_DCB, "Jpsi", "L");
    //pl2->AddEntry(h_gauss, "Jpsi+comb", "F");
    pl2->AddEntry(h_comb, "Comb.", "F");
    pl2->SetBorderSize(0);
    pl2->Draw();

    //delete h_total; delete h_DCB; delete h_gauss; delete h_comb;
    Double_t frac1 = gfrac1.getVal();
    Double_t frac1_err = gfrac1.getError();

    //Double_t frac2 = gfrac2.getVal();
    //Double_t frac2_err = gfrac2.getError();

    Double_t frac2 = 1-frac1;
    Double_t frac2_err = frac1_err;


    float data_num = data->Integral();  
    cout<<"number of event is "<<data_num<<endl;

    cout<<"J/psi frac is "<<frac1<<" +- "<<frac1_err<<endl;
    cout<<"J/psi number is "<<data_num*frac1<<" +- "<<data_num*frac1_err<<endl;

    //cout<<"J/psi + comb frac is "<<frac2<<" +- "<<frac2_err<<endl;
    //cout<<"J/psi + comb number is "<<data_num*frac2<<" +- "<<data_num*frac2_err<<endl;

    cout<<"comb frac is "<<frac2<<" +- "<<frac2_err<<endl;
    cout<<"comb number is "<<data_num*frac2<<" +- "<<data_num*frac2_err<<endl;

    TString NAME = name[i];
    cout<<"Finished "<<NAME<<endl;

    canvas->SaveAs("data_fit_"+NAME+".pdf");
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

void MakeHistoErrors(int m, TH1F* &histo, TH1F* histo_up, TH1F* histo_do){
  float ErrStat = histo->GetBinError(m);
  float ErrCorr = max(fabs(histo->GetBinContent(m)-histo_up->GetBinContent(m)),fabs(histo->GetBinContent(m)-histo_do->GetBinContent(m)));
  float TOTAL = sqrt(ErrStat*ErrStat + ErrCorr*ErrCorr);
  histo ->SetBinError(m,TOTAL);

}
