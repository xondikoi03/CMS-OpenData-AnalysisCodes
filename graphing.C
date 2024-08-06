/* ===========================================
   
   This is a graphing script to make histograms
   look presentable and ready for journal uses.
   Created on: 31 Jul, 2024
   Original Author: Raj Handique

   =========================================== */

// This Graphing script is made for the CMS_Run2011B_DoubleMu_AOD_12Oct2013-v1 //

// user include header files 

#include <iostream>
#include <string>
#include <fstream>
#include <TFile.h>
#include <TH1.h>
#include <TH1F.h>
#include <TPaveText.h>
#include <TString.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <TGraph.h>

// Declaring all the functions necessary. The descriptions can be found commented
// along with them.

void decorate(TH1 *h, int linecolor, double linewidth){
  
  // This functions decorates the histogram with color and linewidth
  
  h->SetLineColor(linecolor);
  h->SetLineWidth(linewidth);
}


void graphing(){

  // The name of the input files (.root files)
  TString filename1 = "OutputFiles/DoubleMuonData_hist.root";
  TString filename2 = "OutputFiles/DYJets2LL_MC_hist.root"; 
  
  // The name of the plot(s) to be accessed from the histogram file
  TString plotname1 = "Dimuon_inv_mass";
  TString plotname2 = "Dimuon_inv_mass_0to200";
  
  // Opening the files using TFile
  TFile *file1 = new TFile(filename1);
  TFile *file2 = new TFile(filename2);
  
  // Opening and Assigning the histograms from the input file(s)
  TH1F *h1 = (TH1F*)file1->Get(plotname1);
  TH1F *h2 = (TH1F*)file1->Get(plotname2);
  
  TH1F *h3 = (TH1F*)file2->Get(plotname1);
  TH1F *h4 = (TH1F*)file2->Get(plotname2);
  
  // Decorating the histogram
  decorate(h1, kOrange-3, 2.5);
  decorate(h2, kOrange-3, 2.5);
  decorate(h3, kOrange-3, 2.5);
  decorate(h4, kOrange-3, 2.5);
  
  //Plot 1
  
  // Declaring a canvas
  TCanvas *c1 = new TCanvas("c1","CMS Open Data", 900, 600);
  
  c1->SetLogy();
  
  h1->SetStats(0);
  h1->Draw();
  
  // Writing the necessary information on the histogram
  TLatex t1, t3, t4;
  t1.SetTextSize(0.05);
  t3.SetTextSize(0.04);
  t4.SetTextSize(0.038);
  t1.DrawLatexNDC(0.66, 0.84, "CMS Open Data");
  t4.DrawLatexNDC(0.66, 0.80, "#it{#bf{Data - 2011 RunB}}");
  t3.DrawLatexNDC(0.4, 0.92, "#bf{L = 3 fb^{-1}, #sqrt{s} = 7 TeV}");
  

  // Plot 2

  //Declaring the Canvas
  TCanvas *c2 = new TCanvas("c2","CMS Open Data", 900, 600);

  c2->SetLogy();
  
  h2->SetStats(0);
  h2->Draw();

  // Writing the necessary information on the histogram
  TLatex t5, t6, t7;
  t5.SetTextSize(0.05);
  t6.SetTextSize(0.04);
  t7.SetTextSize(0.038);
  t5.DrawLatexNDC(0.66, 0.84, "CMS Open Data");
  t6.DrawLatexNDC(0.66, 0.80, "#it{#bf{Data - 2011 RunB}}");
  t7.DrawLatexNDC(0.4, 0.92, "#bf{L = 3 fb^{-1}, #sqrt{s} = 7 TeV}");

  // Plot 3

  //Declaring the Canvas
  TCanvas *c3 = new TCanvas("c3","CMS Open Data", 900, 600);

  c3->SetLogy();

  h3->SetStats(0);
  h3->Draw();

  // Writing the necessary information on the histogram
  TLatex t8, t9, t10;
  t8.SetTextSize(0.05);
  t9.SetTextSize(0.04);
  t10.SetTextSize(0.038);
  t8.DrawLatexNDC(0.66, 0.84, "CMS Open Data");
  t9.DrawLatexNDC(0.66, 0.80, "#it{#bf{Data - 2011 RunB}}");
  t10.DrawLatexNDC(0.4, 0.92, "#bf{L = 3 fb^{-1}, #sqrt{s} = 7 TeV}");


  // Plot 4

  //Declaring the Canvas
  TCanvas *c4 = new TCanvas("c4","CMS Open Data", 900, 600);

  c4->SetLogy();

  h4->SetStats(0);
  h4->Draw();

  // Writing the necessary information on the histogram
  TLatex t11, t12, t13;
  t11.SetTextSize(0.05);
  t12.SetTextSize(0.04);
  t13.SetTextSize(0.038);
  t11.DrawLatexNDC(0.66, 0.84, "CMS Open Data");
  t12.DrawLatexNDC(0.66, 0.80, "#it{#bf{Data - 2011 RunB}}");
  t13.DrawLatexNDC(0.4, 0.92, "#bf{L = 3 fb^{-1}, #sqrt{s} = 7 TeV}");


  
  c1->Update();
  c2->Update();
  c3->Update();
  c4->Update();
  c1->SaveAs("DiMuon_Mass_Spectrum_Data.png");
  c2->SaveAs("Dimuon_Mass_Spectrum_0to200_Data.png");
  c3->SaveAs("Dimuon_Mass_Spectrum_MC.png");
  c4->SaveAs("Dimuon_Mass_Spectrum_0to200_MC.png");
}

