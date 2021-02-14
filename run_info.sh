#!/bin/bash -f

if [[ "$1" == "" ]]; then
    echo "Please specify signal sample name"
    exit 0;

elif [[ "$2" == "" ]]; then
    echo "Please specify background sample name"
    exit 0;

elif [[ "$3" == "" ]]; then
    echo "Please specify JEC file name"
    exit 0;
fi

if [[ "$4" == "" ]]; then
    echo "Please specify process type. DY? or VBF?"
    echo "Automatically set as DY..."
    prox="DY"
elif [[ "$4" != "" ]]; then
    prox="$4"
fi

if [[ "$5" == "" ]]; then
    echo "Please specify output directory name.. automatically set as txts_DY.."
    outdir="txts_DY"

elif [[ "$5" != "" ]]; then
    outdir="$5"
fi

if [ ! -d mets ]; then
    mkdir mets
fi

if [[ $prox == "DY" ]]; then
    python jetHtSuite_corrMET_DY.py ../$1 ../$2 mets -w newcomp -v corrMet -j ../$3  -P roc
elif [[ $prox == "VBF" ]]; then
    python jetHtSuite_corrMET_VBF.py ../$1 ../$2 mets -w newcomp -v corrMet -j ../$3  -P roc
elif [[ $prox != "VBF" && $prox != "DY" ]]; then
    echo "No matching signal name"
    exit 0;
fi

rm -rf $outdir
mv ./mets ./$outdir

