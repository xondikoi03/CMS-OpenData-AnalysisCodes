#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
void driver(int sample=0)
{
  const char *hstfilename, *sumfilename; 
  TChain *chain = new TChain("Events/Events");
  cmsAna m_selec;//declared an instance of our class.
  
  //--------------------------------------------------------------------------//
  //               Choose the sample you want to run over                     //
  //--------------------------------------------------------------------------//


  if(sample==0){
    chain->Add("InputFiles/singlemuon_sample.root");
    hstfilename = "OutputFiles/SingleMuonData_hist.root"; 
  }

  if(sample==1){
    chain->Add("InputFiles/doublemuon_sample3.root");
    hstfilename = "OutputFiles/DoubleMuonData_hist.root";
  }

  if(sample==2){
    chain->Add("InputFiles/DYJetsToLL_MC_sample.root");
    hstfilename = "OutputFiles/DYJets2LL_MC_hist.root";
  }
  std::cout<<"Output : "<<hstfilename<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(0);//set verbosity level for output.
  
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);

}
