#include "RooFit_data_Jpsi.h"
#include "CalculateCS.h"
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

void RooFit2D_data_Jpsi(){
  gROOT->Reset();
  gStyle->SetCanvasColor(0);
  gStyle->SetFrameBorderMode(0);
  gStyle->SetOptStat(0);
  gStyle->SetPalette(1,0);
  gStyle->SetTitleX(0.5); //title X location
  gStyle->SetTitleY(0.96); //title Y location
  gStyle->SetPaintTextFormat(".2f");
  gErrorIgnoreLevel = kError;
  using namespace std;
  TCanvas* canvas = new TCanvas("canvas","canvas",0,0,900,600);
  TH2F *data_2D; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  TH1F *data; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  TH1F *data_x; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  TH1F *data_y; //= new TH1F("DPS",  "DPS",  30,2.8,3.4);
  RooRealVar x("x", "x", 2.80, 3.40);
  RooRealVar y("y", "y", 2.80, 3.40);
  x.setBins(1000,"cache");

  //Construct Jpsi Jpsi pdf
  RooRealVar PDGmZ("PDGmZ","PDGmZ",3.092);
  RooRealVar PDGwZ("PDGwZ","PDGwZ",0.05,0.01,0.08);
  RooBreitWigner PDGBW("PDGBW","PDGBW",x,PDGmZ,PDGwZ);
  PDGmZ.setConstant(kTRUE);
  PDGwZ.setConstant(kTRUE);
  //Jpsi+Jpsi
  RooRealVar Jpsi_mean_x("Jpsi_mean_x", "Jpsi mean", 3.092); 
  RooRealVar Jpsi_width_x("Jpsi_width_x", "Jpsi width",0.03,0.01,0.1);
  RooRealVar alpha_1_x("alpha_1_x", "",1,0,10);
  RooRealVar alpha_2_x("alpha_2_x", "",1,0,10);
  RooRealVar n_1_x("n_1_x","",10,0,70);
  RooRealVar n_2_x("n_2_x","",10,0,70);

  RooRealVar Jpsi_mean_y("Jpsi_mean_x", "Jpsi mean", 3.092); 
  RooRealVar Jpsi_width_y("Jpsi_width_x", "Jpsi width",0.03,0.01,0.1);
  RooRealVar alpha_1_y("alpha_1_x", "",1,0,10);
  RooRealVar alpha_2_y("alpha_2_x", "",1,0,10);
  RooRealVar n_1_y("n_1_x","",10,0,70);
  RooRealVar n_2_y("n_2_x","",10,0,70);

  RooRealVar Jpsi_mean("Jpsi_mean", "Jpsi mean", 3.092); 
  RooRealVar Jpsi_width("Jpsi_width", "Jpsi width",0.03,0.02,0.04);
  RooRealVar alpha_1("alpha_1", "",1,0,10);
  RooRealVar alpha_2("alpha_2", "",1,0,10);
  RooRealVar n_1("n_1","",24,0,70);
  RooRealVar n_2("n_2","",10,0,70);

  //RooDoubleCB DCB_x("DCB_x","DCB_x",x,Jpsi_mean_x,Jpsi_width_x,alpha_1_x,n_1_x,alpha_2_x,n_2_x);
  //RooDoubleCB DCB_y("DCB_y","DCB_y",y,Jpsi_mean_y,Jpsi_width_y,alpha_1_y,n_1_y,alpha_2_y,n_2_y);
  
  RooDoubleCB DCB_x("DCB_x","DCB_x",x,Jpsi_mean,Jpsi_width,alpha_1,n_1,alpha_2,n_2);
  RooDoubleCB DCB_y("DCB_y","DCB_y",y,Jpsi_mean,Jpsi_width,alpha_1,n_1,alpha_2,n_2);

  //RooCBShape CB_1("CB_1","CB_1",x,Jpsi_mean,Jpsi_width,alpha_1,n_1);
  //RooCBShape CB_2("CB_2","CB_2",x,Jpsi_mean,Jpsi_width,alpha_2,n_2);
  //RooAddPdf  DCB("DCB","CB_1+CB_2",RooArgList(CB_1,CB_2),RooArgList(g1frac));
  //RooAddPdf  BW_DCB("BW_DCB","BW+CB_1+CB_2",RooArgList(PDGBW,DCB),RooArgList(g2frac));

  //RooFFTConvPdf BW_DCB("BW_DCB","BW_DCB",x,PDGBW,DCB);
  //RooFFTConvPdf BW_DCB("BW_DCB","BW_DCB",x,PDGBW,CB_1);
 
 
  //Construct combinatorial pdf
  RooRealVar a0("a0","a0",-0.365,-1,-0.001);
  RooRealVar a1("a1","a1",-0.0734,-1,1);

  RooChebychev comb_x("comb_x","comb_x",x,RooArgList(a0,a1));
  RooChebychev comb_y("comb_y","comb_y",y,RooArgList(a0,a1));

  //construct composite pdf
  RooRealVar gfrac1("gfrac1","",0.6,0.5,0.85);
  RooRealVar gfrac2("gfrac2","",0.2,0.1,0.3);
  
  RooAddPdf model_x("model_x","model_x",RooArgList(DCB_x,comb_x),RooArgList(gfrac1));
  RooAddPdf model_y("model_y","model_y",RooArgList(DCB_y,comb_y),RooArgList(gfrac1));
  RooProdPdf model_total1("model_total1","model_x*model_y",RooArgList(model_x,model_y));
  
  //same pdf function but different component
  RooProdPdf model_signal("model_signal","DCB_x*DCB_y",RooArgList(DCB_x,DCB_y));
  RooProdPdf model_DCB1_comb2("model_bkg1","DCB_x*comb_y",RooArgList(DCB_x,comb_y));
  RooProdPdf model_comb1_DCB2("model_bkg2","comb_x*DCB_y",RooArgList(comb_x,DCB_y));
  RooProdPdf model_comb1_comb2("model_bkg3","comb_x*comb_y",RooArgList(comb_x,comb_y));

  //RooAddPdf model_xy("model_xy","model_xy", RooArgList(model_signal,model_DCB1_comb2, model_comb1_DCB2,model_comb1_comb2),RooArgList(gfrac1,gfrac2,gfrac2));


  vector<TString> name;         vector<int> bin;   vector<float> Min;  vector<float> Max;  vector<TString> axis;
  name.push_back("Jpsi1_mass"); bin.push_back(60); Min.push_back(2.8); Max.push_back(3.4); axis.push_back("m_{muon12}");
  name.push_back("Jpsi2_mass"); bin.push_back(60); Min.push_back(2.8); Max.push_back(3.4); axis.push_back("m_{muon34}");


  for(int i=0; i<name.size(); i++){
    for(int j=i+1; j<name.size(); j++){
      const char *plotX = name[i];
      const char *plotY = name[j];
      int XBIN = bin[i];  int YBIN = bin[j];
      float XMIN = Min[i]; float YMIN = Min[j];
      float XMAX = Max[i]; float YMAX = Max[j];
      char CUTpre[1000];
      char CUT[1000];
      sprintf(CUTpre,"(((Jpsi1_pt>6 && abs(Jpsi1_eta)>1)||(Jpsi1_pt>7 && abs(Jpsi1_eta)<1)) && ((Jpsi2_pt>6 && abs(Jpsi2_eta)>1)||(Jpsi2_pt>7 && abs(Jpsi2_eta)<1)))");
      sprintf(CUT,"1 *%s ", CUTpre);
      //sprintf(CUT,"(1./((w_acc_Jpsi1*w_acc_Jpsi2) * (w_reco_Jpsi1*w_reco_Jpsi2) * (w_eff_Jpsi1*w_eff_Jpsi2) *w_trig_Jpsi12)) * *%s ", CUTpre);
      GetHisto(CUT, Tree, data_x ,plotX,bin[i],Min[i],Max[i]);
      GetHisto(CUT, Tree, data_y ,plotY,bin[j],Min[j],Max[j]);
      GetHisto(CUT, Tree, data ,plotX,bin[i],Min[i],Max[i]);
       
      GetHisto2D(CUT, Tree, data_2D ,plotX,plotY,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);

      for(int n=1; n<data_2D->GetNbinsX()+1; n++){
         for(int m=1; m<data_2D->GetNbinsY()+1; m++){
	    //data->SetBinContent(j,data_pre->GetBinContent(j));

           data_2D->SetBinContent(n,m,data_2D->GetBinContent(n,m));
           data_2D->SetBinError(n,m,sqrt(data_2D->GetBinContent(n,m)));
         }
      }
   }
  }
      //data->Draw("LEGO");
      //canvas->SaveAs("data.pdf") ;
  data->SetMarkerColor(1); data->SetMarkerStyle(20); data->SetMarkerSize(1.3);
  TH1F *h_DCB_DCB; h_DCB_DCB = (TH1F*)data->Clone(); h_DCB_DCB->SetLineColor(kBlue); h_DCB_DCB->SetLineWidth(1); 
  TH1F *h_DCB_comb; h_DCB_comb = (TH1F*)data->Clone(); h_DCB_comb->SetLineStyle(9); h_DCB_comb->SetMarkerSize(0); h_DCB_comb->SetLineColor(1); h_DCB_comb->SetLineWidth(1);
  TH1F *h_comb_DCB; h_comb_DCB = (TH1F*)data->Clone(); h_comb_DCB->SetLineStyle(7); h_comb_DCB->SetLineColor(kViolet-2); h_comb_DCB->SetLineWidth(1);
  TH1F *h_comb_comb; h_comb_comb = (TH1F*)data->Clone(); h_comb_comb->SetFillStyle(3144); h_comb_comb->SetFillColor(12); h_comb_comb->SetLineWidth(1);  h_comb_comb->SetMarkerSize(0); h_comb_comb->SetLineColor(0);
  TH1F *h_total; h_total = (TH1F*)data->Clone(); h_total->SetLineColor(kRed); h_total->SetLineWidth(1);


  RooDataHist roohist_data_2D("roohist_data","roohist_data",RooArgSet(x,y),data_2D);
  RooDataHist roohist_data_x("roohist_data","roohist_data",x,data_x);
  RooDataHist roohist_data_y("roohist_data","roohist_data",y,data_y);
  RooPlot* xframe_data = x.frame();
  RooPlot* yframe_data = y.frame();

  //2D fit
  model_total1.fitTo(roohist_data_2D,SumW2Error(kTRUE));
  Double_t frac1 = gfrac1.getVal();
  Double_t frac1_err = gfrac1.getError(); 
  Double_t frac2 = 1-frac1; 

  Double_t frac1_squ = frac1*frac1;
  Double_t frac12_mul = frac1*(1-frac1);  

  RooRealVar gfrac1_squ("gfrac1_squre","",frac1_squ);
  RooRealVar gfrac12_mul("gfrac12_multiply","",frac12_mul);

  RooAddPdf model_total2("model_total2","model_total2", RooArgList(model_signal,model_DCB1_comb2, model_comb1_DCB2,model_comb1_comb2),RooArgList(gfrac1_squ,gfrac12_mul,gfrac12_mul));

  for(int k=0; k<name.size(); k++){
    if(k==0){
      roohist_data_2D.plotOn(xframe_data);
      model_total2.plotOn(xframe_data,LineColor(kRed),LineWidth(1)); 
      model_total2.plotOn(xframe_data,Components(model_signal),LineColor(kBlue),LineWidth(1)); 
      model_total2.plotOn(xframe_data,Components(model_DCB1_comb2),LineStyle(9),LineColor(1),LineWidth(1)); 
      model_total2.plotOn(xframe_data,Components(model_comb1_DCB2),LineStyle(7),LineColor(kViolet-2),LineWidth(1)); 
      model_total2.plotOn(xframe_data,Components(model_comb1_comb2),FillStyle(3144),FillColor(12),LineColor(1),LineWidth(1),DrawOption("F")); 
      xframe_data->SetTitle(""); 
      xframe_data->GetXaxis()->SetTitle(axis[k]); 
      xframe_data->GetYaxis()->SetTitle("Events/(0.01 GeV)"); 
      xframe_data->GetYaxis()->SetTitleOffset(1.30);
      xframe_data->Draw();
      } 

    if(k==1){
      roohist_data_2D.plotOn(yframe_data);
      model_total2.plotOn(yframe_data,LineColor(kRed),LineWidth(1)); 
      model_total2.plotOn(yframe_data,Components(model_signal),FillStyle(3144),FillColor(kOrange),LineColor(kBlue),LineWidth(1)); 
      model_total2.plotOn(yframe_data,Components(model_DCB1_comb2),LineStyle(9),LineColor(1),LineWidth(1)); 
      model_total2.plotOn(yframe_data,Components(model_comb1_DCB2),LineStyle(7),LineColor(kViolet-2),LineWidth(1)); 
      model_total2.plotOn(yframe_data,Components(model_comb1_comb2),FillStyle(3144),FillColor(12),LineColor(1),LineWidth(1),DrawOption("F")); 
      yframe_data->SetTitle(""); 
      yframe_data->GetXaxis()->SetTitle(axis[k]); 
      yframe_data->GetYaxis()->SetTitle("Events/(0.01 GeV)"); 
      yframe_data->GetYaxis()->SetTitleOffset(1.30);
      yframe_data->Draw();
    }
    
    if(k==1){ 
      Double_t data_num = data_2D->Integral();
      CalculateCS(frac1, frac1_err, data_num); 
    }
    //TH2D* model2D = model_xy.createHistogram("model2D",x,YVar(y));
    //model2D->Draw(); 

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
    TLegendEntry *ple2 = pl2->AddEntry(data, "Observed",  "PE");
    pl2->AddEntry(h_total, "total fit model", "L");
    pl2->AddEntry(h_DCB_DCB, "Jpsi1+Jpsi2", "L");
    pl2->AddEntry(h_DCB_comb, "Jpsi1+comb", "L");
    pl2->AddEntry(h_comb_DCB, "comb.+Jpsi2", "L");  
    pl2->AddEntry(h_comb_comb, "comb.+comb.", "F");  
    pl2->SetBorderSize(0);
    pl2->Draw();

    TString NAME = name[k];
    cout<<"Finished "<<NAME<<endl;
    canvas->SaveAs("data2D_fit_"+NAME+".pdf");
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

void GetHisto2D(char CUT[1000], TTree *Tree, TH2F* & histo, const char *plotX,const char *plotY, int XBIN, float XMIN, float XMAX, int YBIN, float YMIN, float YMAX){
  char input[50]; sprintf(input,"%s:%s>>h(%i,%f,%f,%i,%f,%f)",plotY,plotX,XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  TH2F *temp = new TH2F("", "", XBIN,XMIN,XMAX,YBIN,YMIN,YMAX);
  if(Tree->Draw(input,CUT)){ Tree->Draw(input,CUT); TH2F* h=(TH2F*)gDirectory->Get("h"); histo = (TH2F*)h->Clone(); delete h; } else { histo = (TH2F*)temp->Clone(); }
  histo->SetDirectory(0);
  histo->SetName("histo");
  delete temp;
}
 
