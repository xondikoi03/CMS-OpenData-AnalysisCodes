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
    chain->Add("InputFiles/CMS_Run2011A_MinimumBias_AOD_13Oct2013-v1_250Kevts.root");
    chain->Add("InputFiles/CMS_Run2011B_MinimumBias_AOD_13Oct2013-v1_250Kevts.root");
    chain->Add("InputFiles/CMS_Run2012A_MinimumBias_AOD_22Jan2013-v1_250Kevts.root");
    chain->Add("InputFiles/CMS_Run2012B_MinimumBias_AOD_22Jan2013-v1_250Kevts.root");
    chain->Add("InputFiles/CMS_Run2012C_MinimumBias_AOD_22Jan2013-v1_250Kevts.root");
    chain->Add("InputFiles/CMS_Run2012D_MinimumBias_AOD_22Jan2013-v1_250Kevts.root");
    hstfilename = "OutputFiles/hst_QCD.root"; 

  }

  std::cout<<"Output : "<<hstfilename<<std::endl;
  m_selec.SetHstFileName(hstfilename);
  m_selec.SetSumFileName(sumfilename);
  m_selec.SetVerbose(0);//set verbosity level for output.
  
  //this calls the Process function for each event in the chain
  //and runs the m_selec code over it.
  chain->Process(&m_selec);
    
}
