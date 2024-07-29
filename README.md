# CMS-OpenData-AnalysisCodes

## Analysis Codes for CMS-OpenData NTuples

This Repository includes Analysis Codes for Custom Ntuples for CMS-OpenData. This repo will be updated regularly.

## How to use the Muon-Study specific files:

This repository will allow you to make a dimuon invarient mass spectrum at low masses(0-20GeV) by default. Steps to run the analysis and get the plot is:

1. Open ROOT prompt and compile the source code using:
```
.L cmsAna.C+
```
2. After this step, the compiled library is loaded, and it can be used from the ROOT prompt. Next, the driver file is executed to feed the appropriate values to the input-output parameters and run the analysis.

For SingleMuon Dataset:
```
.x driver.C(0)
```

For DoubleMuon Dataset: (Use this one for the dimuon invarient mass spectrum plot)
```
.x driver.C(1)
```

For DYJets2LL_MC Dataset:
```
.x driver.C(2)
```
This will make the histogram files needed to get the final plot.

3. Now, simply run the graphing script to make the plot.
```
.x graphing.C
```

That's it! Now you have a dimuon invarient mass spectrum at loss masses. You can also play around with the files to see where it takes you!
