#define MinBiasAna_cxx
// The class definition in AnaOpenData.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("AnaOpenData.C")
// root> T->Process("AnaOpenData.C","some options")
// root> T->Process("AnaOpenData.C+")
//


#include "MinBiasAna.h"
#include <TH2.h>
#include <TStyle.h>
//Additional headers:
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <string>

using namespace std;

void MinBiasAna::Begin(TTree * /*tree*/)
{
  // The Begin() function is called at the start of the query.
  // When running with PROOF Begin() is only called on the client.
  // The tree argument is deprecated (on PROOF 0 is passed).

  TString option = GetOption();
}

void MinBiasAna::SlaveBegin(TTree * /*tree*/)
{
  // The SlaveBegin() function is called after the Begin() function.
  // When running with PROOF SlaveBegin() is called on each slave server.
  // The tree argument is deprecated (on PROOF 0 is passed).

  //Initialization of some global variables:
  time(&start);
  nEvtTotal = 0;
  //nEvtRan = 0;
  //nEvtTrigger=0;

  //Creating the output file:
  _HstFile = new TFile(_HstFileName,"recreate");
  BookHistograms();

  TString option = GetOption();

}

void MinBiasAna::SlaveTerminate()
{
  // The SlaveTerminate() function is called after all entries or objects
  // have been processed. When running with PROOF SlaveTerminate() is called
  // on each slave server.

  //Writing the saving the output file:
  _HstFile->Write();
  _HstFile->Close();

  //Printing out some information using the event counters after the event loop has run.
  cout<<"---------------------------------------------"<<endl;
  // cout<<"Summary:"                    <<endl;
  cout<<"nEvtTotal = "  <<nEvtTotal   <<endl;
  //cout<<"nEvtRan = "    <<nEvtRan     <<endl;
  //cout<<"nEvtTrigger = "<<nEvtTrigger <<endl;
  time(&end);
    
  double time_taken = double(end-start);
  cout<<"\nTime taken by the program is : "<<(int)time_taken<<" seconds "<<endl;
  cout<<"---------------------------------------------"<<endl;

  //You can also create a text file here as a summary, keeping the same information.
  //For example, the text file can take the name _SumFileName
  
}

void MinBiasAna::Terminate()
{
  // The Terminate() function is the last function to be called during
  // a query. It always runs on the client, it can be used to present
  // the results graphically or save the results to file.

}

//--------------------------------------------------------------------------------------
//                                  The event loop:
//--------------------------------------------------------------------------------------

Bool_t MinBiasAna::Process(Long64_t entry)
{
  // The Process() function is called for each entry in the tree (or possibly
  // keyed object in the case of PROOF) to be processed. The entry argument
  // specifies which entry in the currently loaded tree is to be processed.
  // When processing keyed objects with PROOF, the object is already loaded
  // and is available via the fObject pointer.
  //
  // This function should contain the \"body\" of the analysis. It can contain
  // simple or elaborate selection criteria, run algorithms on the data
  // of the event and typically fill histograms.
  //
  // The processing can be stopped by calling Abort().
  //
  // Use fStatus to set the return value of TTree::Process().
  //
  // The return value is currently not used.

  fReader.SetLocalEntry(entry);

  //Setting verbosity:
  //Verbosity determines the number of processed events after which
  //the root prompt is supposed to display a status update.
  if(_verbosity==0 && nEvtTotal%100==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;      
  else if(_verbosity>0 && nEvtTotal%100==0)cout<<"Processed "<<nEvtTotal<<" event..."<<endl;

  nEvtTotal++;

  //THE FOLLOWING TAKES PLACE FOR ONE EVENT AT A TIME
  
  //--------------------------------------------
  // Extracting information from the input file
  //--------------------------------------------
  
  //Creating an array of jets per/event.
  //First, clear the arrays from the previous event (if any).
  
  //int nj = 0;
  goodJ.clear();
  
  //Looping over all the jets to pick the objects we want:
  for(int i=0; i< (*nJet); i++){
    Particle temp;
    temp.v.SetPtEtaPhiM(Jet_pt[i],Jet_eta[i],Jet_phi[i],Jet_mass[i]);
    temp.ind = i;
    
    bool passCuts = temp.v.Pt()>20 && fabs(temp.v.Eta())<2.4;
    if(passCuts){
      goodJ.push_back(temp);
    }
  }

  Sortpt(goodJ);
  
  //-------------------
  //  Analysis block
  //-------------------
  
  //Note : All the histograms that are being filled here need to be
  //initialized in the BookHistograms() function.
  //Otherwise the code will show runtime error.
  
  h.njets->Fill((int)goodJ.size());
  
  
  for(int k=0; k<(int)goodJ.size(); k++){
    h.jpt->Fill(goodJ.at(k).v.Pt());
  }
  
  if((int)goodJ.size()>0){
    h.jprop[0]->Fill(goodJ.at(0).v.Pt());
    h.jprop[1]->Fill(goodJ.at(0).v.Phi());
    h.jprop[2]->Fill(goodJ.at(0).v.Eta());
    h.jprop[3]->Fill(Jet_nConstituents[goodJ.at(0).ind]);
    h.jprop[4]->Fill(Jet_chEmEF[goodJ.at(0).ind]);
    h.jprop[5]->Fill(Jet_chHEF[goodJ.at(0).ind]);
    h.jprop[6]->Fill(Jet_neEmEF[goodJ.at(0).ind]);
    h.jprop[7]->Fill(Jet_neHEF[goodJ.at(0).ind]);
  }

  if((int)goodJ.size()>1){
    h.jsub[0]->Fill(goodJ.at(1).v.Pt());
    h.jsub[1]->Fill(goodJ.at(1).v.Phi());
    h.jsub[2]->Fill(goodJ.at(1).v.Eta());
    h.jsub[3]->Fill(Jet_nConstituents[goodJ.at(1).ind]);
    h.jsub[4]->Fill(Jet_chEmEF[goodJ.at(1).ind]);
    h.jsub[5]->Fill(Jet_chHEF[goodJ.at(1).ind]);
    h.jsub[6]->Fill(Jet_neEmEF[goodJ.at(1).ind]);
    h.jsub[7]->Fill(Jet_neHEF[goodJ.at(1).ind]);
  }
  
  return kTRUE;
}


//-------------------------
// USER DEFINED FUNCTIONS
//-------------------------
void MinBiasAna::BookHistograms(){

  //Choose an appropriate binning scheme here.

  //For Jets
  h.njets = new TH1F("nJet", "number of jets", 10, 0, 10);
  
  h.jpt = new TH1F("j_pt", "Jets p_{T}", 200, 0, 200);
  
  h.jprop[0] = new TH1F("j0_pt","Leading jet p_{T}",200,0,200);
  h.jprop[1] = new TH1F("j0_phi","Leading jet phi",64,-3.2,3.2);
  h.jprop[2] = new TH1F("j0_eta","Leading jet eta",60,-3,3);
  h.jprop[3] = new TH1F("jet0_part","Jet0 Parts",10,0,120);
  h.jprop[4] = new TH1F("jet0_chEM", "Charged EM energy fraction",100,0,1);
  h.jprop[5] = new TH1F("jet0_chH", "Charged hadron energy fraction",100,0,1);
  h.jprop[6] = new TH1F("jet0_neEM", "Neutral EM energy fraction",100,0,1);
  h.jprop[7] = new TH1F("jet0_neH", "Neutral hadron energy fraction",100,0,1);
  
  h.jsub[0] = new TH1F("j1_pt","Leading jet p_{T}",200,0,200);
  h.jsub[1] = new TH1F("j1_phi","Leading jet phi",64,-3.2,3.2);
  h.jsub[2] = new TH1F("j1_eta","Leading jet eta",60,-3,3);
  h.jsub[3] = new TH1F("jet1_part","Jet0 Parts",10,0,120);
  h.jsub[4] = new TH1F("jet1_chEM", "Charged EM energy fraction",100,0,1);
  h.jsub[5] = new TH1F("jet1_chH", "Charged hadron energy fraction",100,0,1);
  h.jsub[6] = new TH1F("jet1_neEM", "Neutral EM energy fraction",100,0,1);
  h.jsub[7] = new TH1F("jet1_neH", "Neutral hadron energy fraction",100,0,1);
  
}


void MinBiasAna::Sortpt(vector<Particle> vec)
{
  //This functions sorts an array in the decreasing order of pT.
  for(int i=0; i<(int)vec.size()-1; i++){
    for(int j=i+1; j<(int)vec.size(); j++){
      if(vec.at(i).v.Pt() < vec.at(j).v.Pt()) swap(vec.at(i), vec.at(j));
    }
  }
}
