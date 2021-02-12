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

Note: Sorry for the dizzy outputs. Unfortunately I did't have enough time to tidy the codes up. It would be better to save all information with TTree and make the outputs as one root file. 
