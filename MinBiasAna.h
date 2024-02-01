//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Thu Dec 28 16:09:45 2023 by ROOT version 6.26/10
// from TTree Events/Events
// found on file: sample_input.root
//////////////////////////////////////////////////////////

#ifndef MinBiasAna_h
#define MinBiasAna_h

#include <TROOT.h> 
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include <vector>

//Additional headers
#include <TH1.h>
#include <TH2.h>
#include <TMath.h>
#include "TLorentzVector.h"
#include <fstream>
#include <iostream>
#include "TString.h"
#include <bitset>
#include <time.h>

class MinBiasAna : public TSelector {
public :
  TTreeReader     fReader;  //!the tree reader
  TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

  // Readers to access the data (delete the ones you do not need).
  TTreeReaderValue<Int_t> nJet= {fReader, "nJet"};
  TTreeReaderArray<Float_t> Jet_e = {fReader, "Jet_e"};
  TTreeReaderArray<Float_t> Jet_pt = {fReader, "Jet_pt"};
  TTreeReaderArray<Float_t> Jet_eta = {fReader, "Jet_eta"};
  TTreeReaderArray<Float_t> Jet_phi = {fReader, "Jet_phi"};
  TTreeReaderArray<Float_t> Jet_mass = {fReader, "Jet_mass"};
  TTreeReaderArray<Float_t> Jet_area = {fReader, "Jet_area"};
  TTreeReaderArray<Float_t> Jet_chEmEF = {fReader, "Jet_chEmEF"};
  TTreeReaderArray<Float_t> Jet_chHEF = {fReader, "Jet_chHEF"};
  TTreeReaderArray<Float_t> Jet_neEmEF = {fReader, "Jet_neEmEF"};
  TTreeReaderArray<Float_t> Jet_neHEF = {fReader, "Jet_neHEF"};
  TTreeReaderArray<Int_t> Jet_nConstituents = {fReader, "Jet_nConstituents"};

  //Muons
  TTreeReaderArray<Int_t> nMuon = {fReader, "nMuon"};
  TTreeReaderArray<Float_t> Muon_e = {fReader, "Muon_e"};
  TTreeReaderArray<Float_t> Muon_pt = {fReader, "Muon_pt"};
  TTreeReaderArray<Float_t> Muon_eta = {fReader, "Muon_eta"};
  TTreeReaderArray<Float_t> Muon_phi = {fReader, "Muon_phi"};
  TTreeReaderArray<Float_t> Muon_mass = {fReader, "Muon_mass"};
  TTreeReaderArray<Int_t> Muon_pdgId = {fReader, "Muon_pdgId"};
  TTreeReaderArray<Int_t> Muon_charge = {fReader, "Muon_charge"};
  TTreeReaderArray<Float_t> Muon_px = {fReader, "Muon_px"};
  TTreeReaderArray<Float_t> Muon_py = {fReader, "Muon_py"};
  TTreeReaderArray<Float_t> Muon_pz = {fReader, "Muon_pz"};

  //Electrons
  TTreeReaderArray<Int_t> nElectron = {fReader, "nElectron"};
  TTreeReaderArray<Float_t> Electron_e = {fReader, "Electron_e"};
  TTreeReaderArray<Float_t> Electron_pt = {fReader, "Electron_pt"};
  TTreeReaderArray<Float_t> Electron_eta = {fReader, "Electron_eta"};
  TTreeReaderArray<Float_t> Electron_phi = {fReader, "Electron_phi"};
  TTreeReaderArray<Float_t> Electron_mass = {fReader, "Electron_mass"};
  TTreeReaderArray<Int_t> Electron_pdgId = {fReader, "Electron_pdgId"};
  TTreeReaderArray<Int_t> Electron_charge = {fReader, "Electron_charge"};
  TTreeReaderArray<Float_t> Electron_px = {fReader, "Electron_px"};
  TTreeReaderArray<Float_t> Electron_py = {fReader, "Electron_py"};
  TTreeReaderArray<Float_t> Electron_pz = {fReader, "Electron_pz"};

  //Photons
  TTreeReaderArray<Int_t> nPhoton = {fReader, "nPhoton"};
  TTreeReaderArray<Float_t> Photon_e = {fReader, "Photon_e"};
  TTreeReaderArray<Float_t> Photon_pt = {fReader, "Photon_pt"};
  TTreeReaderArray<Float_t> Photon_eta = {fReader, "Photon_eta"};
  TTreeReaderArray<Float_t> Photon_phi = {fReader, "Photon_phi"};
  TTreeReaderArray<Float_t> Photon_mass = {fReader, "Photon_mass"};
  TTreeReaderArray<Int_t> Photon_pdgId = {fReader, "Photon_pdgId"};
  TTreeReaderArray<Int_t> Photon_charge = {fReader, "Photon_charge"};
  TTreeReaderArray<Float_t> Photon_px = {fReader, "Photon_px"};
  TTreeReaderArray<Float_t> Photon_py = {fReader, "Photon_py"};
  TTreeReaderArray<Float_t> Photon_pz = {fReader, "Photon_pz"};


  MinBiasAna(TTree * /*tree*/ =0) { }
  virtual ~MinBiasAna() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();
  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual TList  *GetOutputList() const { return fOutput; }
  virtual void    SlaveTerminate();
  virtual void    Terminate();

  //User defined functions are declared here
  void SetHstFileName(const char *HstFileName){ _HstFileName = HstFileName;}
  void SetSumFileName(const char *SumFileName){ _SumFileName = SumFileName;}
  void SetVerbose(int verbose){ _verbosity = verbose; }
  void SetData(int data){_data = data;}
  void SetYear(int year){_year = year;}
  void BookHistograms();

  public:
  struct Hists {
    //Histograms are declared here.
    TH1F *njets;
    TH1F *jpt;
    TH1F *jprop[10];
    TH1F *jsub[10];
    TH1F *hist[10];
  };

  //Each particle is represented as a struct
  //with the following properties.
  struct Particle {
    TLorentzVector v;
    int id;
    int ind;
    float wt;
    int momid;
    int status;
    int pdgid;
    int charge;
  };

  void Sortpt(vector<Particle> vec);

protected:
  Hists h;

private:
  //Global variables are declared here.
  //Those whose valued as not assigned need to be initialized in the Begin() part.
  TFile *_HstFile; //The output file
  const char *_HstFileName;
  const char *_SumFileName;
  int _verbosity,_data, _lep, _year; //These values are assigned by the functions defined above.
  float metpt, metphi;

  //Vectors to keep the particles in each event:
  vector<Particle> goodJ;

  //Event counters: (needs to be initialized in the main code)
  int nEvtTotal,nEvtRan,nEvtTrigger;

  time_t start, end;
  
  ClassDef(MinBiasAna,0);

};

#endif

#ifdef MinBiasAna_cxx
void MinBiasAna::Init(TTree *tree)
{
  // The Init() function is called when the selector needs to initialize
  // a new tree or chain. Typically here the reader is initialized.
  // It is normally not necessary to make changes to the generated
  // code, but the routine can be extended by the user if needed.
  // Init() will be called many times when running on PROOF
  // (once per file to be processed).

  fReader.SetTree(tree);
}

Bool_t MinBiasAna::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.

  return kTRUE;
}


#endif // #ifdef MinBiasAna_cxx
