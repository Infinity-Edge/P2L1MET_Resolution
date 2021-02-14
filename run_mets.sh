#!/bin/bash -f

if [[ "$1" == "" ]]; then
    echo "Please specify input directory name"
    echo "Automatically set as txt_DY..."
    indir="txt_DY"

elif [[ "$1" != "" ]]; then
	indir="$1"
fi

if [[ "$2" == "" ]]; then
    echo "Please specify output directory name"
    oudir="met_res_DY"
elif [[ "$2" != "" ]]; then
	oudir="$2"
fi

if [[ "$3" == "" ]]; then
    echo "Please specify process type. DY? or VBF?"
    echo "Automatically set as DY..."
    prox="DY"
elif [[ "$3" != "" ]]; then
    prox="$3"
fi

if [ ! -d outputs ]; then
    mkdir outputs
fi

if [[ $prox == "DY" ]]; then
	root -b -l <<-EOF
	.L graphs_res_DY.C
	graphs_res_DY("$indir", "outputs", "$prox")
	.q
	EOF
elif [[ $prox == "VBF" ]]; then
	root -b -l <<-EOF
	.L graphs_res_VBF.C
	graphs_res_VBF("$indir", "outputs", "$prox")
	.q
	EOF
elif [[ $prox != "VBF" && $prox != "DY" ]]; then
    echo "No matching signal name"
    exit 0;
fi

rm -rf $oudir
mv outputs $oudir

