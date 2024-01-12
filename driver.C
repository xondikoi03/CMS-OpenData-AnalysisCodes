#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
void driver(int sample=0)
{
  const char *hstfilename, *sumfilename; 
  TChain *chain = new TChain("Events/Events");
  MinBiasAna m_selec;//declared an instance of our class.
  
  //--------------------------------------------------------------------------//
  //               Choose the sample you want to run over                     //
  //--------------------------------------------------------------------------//


  if(sample==0){//Jets
    chain->Add("InputFiles/CMS_Run2012A_MinimumBias_AOD_22Jan2013-v1_20000_10Kevts.root");
    hstfilename = "OutputFiles/CMS_Run2012A_MinimumBias_AOD_22Jan2013-v1_20000_10Kevts_hst.root"; 

  }

  std::cout<<"Output : "<<hstfilename<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(0);//set verbosity level for output.
  
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
    
}
