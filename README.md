# L1 MET Response/Resolution for CMS Phase-2

It requires CMSSW for Phase-2 Level-1 study

Please follow basic instruction here: 
https://github.com/p2l1pfp/FastPUPPI/tree/11_1_X/NtupleProducer

Once you finish environment setup like below (This command can be changed depending on CMSSW version. Please check p2l1pfp repository),
```
cmsrel CMSSW_11_1_6
cd CMSSW_11_1_6/src
cmsenv
git cms-checkout-topic p2l1pfp:L1PF_11_1_6_X

# scripts
git clone git@github.com:p2l1pfp/FastPUPPI.git -b 11_1_X

scram b -j8
```
move to work directory and clone this repository.
```
cd FastPUPPI/NtupleProducer/python/
git clone https://github.com/Infinity-Edge/P2L1MET_Resolution.git
cd P2L1MET_Resolution
```

We had done MET resolution study for two different signal processes, Drell-Yan and VBF(HtoInv). Since the processes have different final state particles, they require two strategies. Therefore I made two types of scripts. One for DY and another for VBF. Of course you can merge the two scripts and develop them as one, if you use proper options.

L1 samples should be placed in `FastPUPPI/NtupleProducer/python/`

There are 2 steps to produce MET response/resolution plots

1. Produce MET and particle information

Since it had been developed based on trigger performance plotter, it always requires Minbias sample as background.

Here is an example command.
```
./run_info.sh <signal sample name> <Background sample name> <JEC file name> <signal process type (DY or VBF)> <Output directory name (default as txt_DY)>
```
It will produce text files of raw MET, type-1 MET and final state paritlces (2 muons for DY or 4 neutrinos for VBF) information. 

Note 1: If you would like to check trigger performance with Type-1 MET, remove comment-out lines. Then it will give you several plots. e.g. ROC and turn-ons.

Note 2: Originally, the script was designed to work for PU0 and PU200 at the same time, but all lines related to PU0 were deleted to prevent confusion. If you would like to run this script for PU0 sample, I think it's okay to put PU0 sample instead of PU200 sample and it might give PU0 result.

Note 3: Sorry for the dizzy outputs. Unfortunately I did't have enough time to tidy the codes up. It would be better to save all information with TTree and make the outputs as one root file. 

2. Produce MET plots

Before you go though to this step, please be sure you have complete text files.

Here is an example command.
```
./run_mets.sh <text file directory name (default as txt_DY)> <name of directory where you want to save (default as met_res_DY)> <signal process type (DY or VBF)>
```

This will produce MET response, perpendicular and parallel resolution plots as pdf file.
