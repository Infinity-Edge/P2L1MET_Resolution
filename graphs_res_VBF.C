#include <stdio.h>
#include <fstream>

	const int n = 49000;
	
	 float agen[n];
	  float apf[n];
	  float apu[n];
	float acopf[n];
	float acopu[n];

	 float agenphi[n];
	  float apfphi[n];
	  float apuphi[n];
	float acopfphi[n];
	float acopuphi[n];


	float aNu1[n][4];
	float aNu2[n][4];
	float aNu3[n][4];
	float aNu4[n][4];

	TString tNum = "";

void graphs_res_VBF(TString inDir = "mets", TString sDir = "met_plots", TString sName =  "VBF")
{

	TH1F *hInv = new TH1F("hInv", "Invariant Mass of 4 #nu PU200;Mass [GeV];Events", 100, 0, 200);


	ifstream gen;
	ifstream   pf;
	ifstream pu;
	ifstream copf;
	ifstream copu;
	

	ifstream  genphi;
	ifstream   pfphi;
	ifstream   puphi;
	ifstream copfphi;
	ifstream copuphi;
	

	ifstream fmu1;
	ifstream fmu2;
	ifstream fmu3;
	ifstream fmu4;

cout << "Reading texts in ./"+inDir+tNum+"..." << endl;
	 gen.open("./"+inDir+tNum+"/GenMET.txt");
	  pf.open("./"+inDir+tNum+"/L1PFMET.txt");
	  pu.open("./"+inDir+tNum+"/L1PuppiMET.txt");
	copf.open("./"+inDir+tNum+"/CoL1PFMET.txt");
	copu.open("./"+inDir+tNum+"/CoL1PuppiMET.txt");

	fmu1.open("./"+inDir+tNum+"/GenNu1.txt");
	fmu2.open("./"+inDir+tNum+"/GenNu2.txt");
	fmu3.open("./"+inDir+tNum+"/GenNu3.txt");
	fmu4.open("./"+inDir+tNum+"/GenNu4.txt");

	for (int i = 0; i < n ; i ++)
	{

	  gen >> agen[i] >> agenphi[i];
	    pf >> apf[i] >> apfphi[i];
	    pu >> apu[i] >> apuphi[i];
	copf >> acopf[i] >> acopfphi[i];
	copu >> acopu[i] >> acopuphi[i];


		fmu1 >> aNu1[i][0] >> aNu1[i][1] >> aNu1[i][2] >> aNu1[i][3];
		fmu2 >> aNu2[i][0] >> aNu2[i][1] >> aNu2[i][2] >> aNu2[i][3];
		fmu3 >> aNu3[i][0] >> aNu3[i][1] >> aNu3[i][2] >> aNu3[i][3];
		fmu4 >> aNu4[i][0] >> aNu4[i][1] >> aNu4[i][2] >> aNu4[i][3];
	}
/*
	for (int i = 0 ; i < 5 ; i++)
	{
	cout << "pt: "<<aNu1[i][0]<<", eta: "<<aNu1[i][1]<<", phi: "<<aNu1[i][2]<<endl;

	}
*/
	const int bin = 10;

	float mini = 0;
	float maxi = 400;
    
	float binning_le = (maxi - mini)/(bin);

	TH1F        *hH[bin];
	TH1F      *hGen[bin];
	TH1F  *hParaGen[bin];
	TH1F  *hPerpGen[bin];
	TH1F   *hParaPF[bin];
	TH1F   *hPerpPF[bin];
	TH1F   *hParaPu[bin];
	TH1F   *hPerpPu[bin];
	TH1F *hParaCoPF[bin];
	TH1F *hPerpCoPF[bin];
	TH1F *hParaCoPu[bin];
	TH1F *hPerpCoPu[bin];


	const int nameN = 100;
	const int titleN = 200;    

	float ext = 400;

	char        nameH[nameN];
	char      nameGen[nameN];
	char  nameParaGen[nameN];
	char  namePerpGen[nameN];
	char   nameParaPF[nameN];
	char   namePerpPF[nameN];
	char   nameParaPu[nameN];
	char   namePerpPu[nameN];
	char nameParaCoPF[nameN];
	char namePerpCoPF[nameN];
	char nameParaCoPu[nameN];
	char namePerpCoPu[nameN];
	
	char		titleH[titleN];
	char      titleGen[titleN];
	char  titleParaGen[titleN];
	char  titlePerpGen[titleN];
	char   titleParaPF[titleN];
	char   titlePerpPF[titleN];
	char   titleParaPu[titleN];
	char   titlePerpPu[titleN];
	char titleParaCoPF[titleN];
	char titlePerpCoPF[titleN];
	char titleParaCoPu[titleN];
	char titlePerpCoPu[titleN];

    for (int i = 0 ; i < bin ; i++)
    {
      sprintf(nameH, "hH%d", i);
      sprintf(nameGen, "hGen%d", i);
      sprintf(nameParaGen, "hParaGen%d", i);
      sprintf(nameParaPF, "hParaPF%d", i);
      sprintf(nameParaPu, "hParaPu%d", i);
      sprintf(nameParaCoPF, "hParaCoPF%d", i);
      sprintf(nameParaCoPu, "hParaCoPu%d", i);
      sprintf(namePerpGen, "hPerpGen%d", i);
      sprintf(namePerpPF,   "hPerpPF%d", i);
      sprintf(namePerpPu,   "hPerpPu%d", i);
      sprintf(namePerpCoPF, "hPerpCoPF%d", i);
      sprintf(namePerpCoPu, "hPerpCoPu%d", i);

      sprintf(titleH, "hH%d", i);
      sprintf(titleGen, "hGen%d", i);
      sprintf(titleParaGen, "hParaGen%d", i);
      sprintf(titleParaPF, "hParaPF%d", i);
      sprintf(titleParaPu, "hParaPu%d", i);
      sprintf(titleParaCoPF, "hParaCoPF%d", i);
      sprintf(titleParaCoPu, "hParaCoPu%d", i);
      sprintf(titlePerpGen, "hPerpGen%d", i);
      sprintf(titlePerpPF,   "hPerpPF%d", i);
      sprintf(titlePerpPu,   "hPerpPu%d", i);
      sprintf(titlePerpCoPF, "hPerpCoPF%d", i);
      sprintf(titlePerpCoPu, "hPerpCoPu%d", i);
      //hGe[i]= new TH1F(nameGe, titleGe, 160, mini+(i*binning_le), mini+((i+1)*binning_le));
          hH[i]= new TH1F(nameH, titleH, 160, -1.*(maxi + ext), (maxi + ext));
        hGen[i]= new TH1F(nameGen, titleGen, 160, -1.*(maxi + ext), (maxi + ext));
        hParaGen[i]= new TH1F(nameParaGen, titleParaGen, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPF[i]= new TH1F(nameParaPF, titleParaPF, 160, -1.*(maxi + ext), (maxi + ext));
          hParaPu[i]= new TH1F(nameParaPu, titleParaPu, 160, -1.*(maxi + ext), (maxi + ext));
      hParaCoPF[i]= new TH1F(nameParaCoPF, titleParaCoPF, 160, -1.*(maxi + ext), (maxi + ext));
      hParaCoPu[i]= new TH1F(nameParaCoPu, titleParaCoPu, 160, -1.*(maxi + ext), (maxi + ext));
        hPerpGen[i]= new TH1F(namePerpGen, titlePerpGen, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPF[i]= new TH1F(namePerpPF, titlePerpPF, 160, -1.*(maxi + ext), (maxi + ext));
          hPerpPu[i]= new TH1F(namePerpPu, titlePerpPu, 160, -1.*(maxi + ext), (maxi + ext));
      hPerpCoPF[i]= new TH1F(namePerpCoPF, titlePerpCoPF, 160, -1.*(maxi + ext), (maxi + ext));
      hPerpCoPu[i]= new TH1F(namePerpCoPu, titlePerpCoPu, 160, -1.*(maxi + ext), (maxi + ext));
    }


// PU200
    for(int j = 0 ; j < n; j++)
    {
		TVector2 vH;
		TVector2 vGen;
		TVector2 vPF;
		TVector2 vPu;
		TVector2 vCoPF;
		TVector2 vCoPu;

		TLorentzVector vNu1;
		TLorentzVector vNu2;
		TLorentzVector vNu3;
		TLorentzVector vNu4;
	
		vNu1.SetPtEtaPhiM(aNu1[j][0], aNu1[j][1], aNu1[j][2], aNu1[j][3]);
		vNu2.SetPtEtaPhiM(aNu2[j][0], aNu2[j][1], aNu2[j][2], aNu2[j][3]);
		vNu3.SetPtEtaPhiM(aNu3[j][0], aNu3[j][1], aNu3[j][2], aNu3[j][3]);
		vNu4.SetPtEtaPhiM(aNu4[j][0], aNu4[j][1], aNu4[j][2], aNu4[j][3]);

		TLorentzVector vH_tmp = vNu1 + vNu2 + vNu3 + vNu4;

		if( aNu1[j][0] == 0 && aNu1[j][1] == 0 && aNu1[j][2] == 0 && aNu1[j][3] == 0) continue;
		hInv->Fill(vH_tmp.M());

		if(fabs(vH_tmp.M()) - 125. > 15. ) continue;

		vH.SetMagPhi(vH_tmp.Pt(), vH_tmp.Phi());
		//cout << "set vH pt: "<< vH.Mod() << ", phi, "<<vH.Phi()<<", true: "<<vH_tmp.Phi() <<endl;		


		 vGen.SetMagPhi(agen[j], agenphi[j]);
		  vPF.SetMagPhi(apf[j], apfphi[j]);
		  vPu.SetMagPhi(apu[j], apuphi[j]);
		vCoPF.SetMagPhi(acopf[j], acopfphi[j]);
		vCoPu.SetMagPhi(acopu[j], acopuphi[j]);
		
		
		TVector2 vRGen   = -1.*(vGen);//+ vH);
		TVector2 vRPF     = -1.*(vPF);//+ vH);
		TVector2 vRPu     = -1.*(vPu);//+ vH);
		TVector2 vRCoPF = -1.*(vCoPF);//+ vH);
		TVector2 vRCoPu = -1.*(vCoPu);//+ vH);

		TVector2 vParaGen	= vRGen.Proj(vH);
		TVector2 vParaPF	= vRPF.Proj(vH);
		TVector2 vParaPu	= vRPu.Proj(vH);
		TVector2 vParaCoPF = vRCoPF.Proj(vH);
		TVector2 vParaCoPu = vRCoPu.Proj(vH);
		TVector2 vPerpGen	= vRGen.Norm(vH);
		TVector2 vPerpPF	= vRPF.Norm(vH);
		TVector2 vPerpPu	= vRPu.Norm(vH);
		TVector2 vPerpCoPF = vRCoPF.Norm(vH);
		TVector2 vPerpCoPu = vRCoPu.Norm(vH);

		for(int i = 0 ; i < bin; i++)
		{
			if( vH.Mod() > mini + (i * binning_le) && vH.Mod() <= mini + ( (i+1) * binning_le) ) 
			{
				  hH[i]->Fill(vH.Mod());
				  hGen[i]->Fill(vGen.Mod());

// Parallel
//                  hParaGen[i]->Fill(vParaGen.Mod());
//                  hParaPF[i]->Fill(vParaPF.Mod());
//                  hParaPu[i]->Fill(vParaPu.Mod());
//                  hParaCoPF[i]->Fill(vParaCoPF.Mod());
//                  hParaCoPu[i]->Fill(vParaCoPu.Mod());

              if (fabs(vParaGen.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hParaGen[i]->Fill(vParaGen.Mod());
              } else {
                  hParaGen[i]->Fill(vParaGen.Mod()*-1.);
              }
              if (fabs(vParaPF.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hParaPF[i]->Fill(vParaPF.Mod());
              } else {
                  hParaPF[i]->Fill(vParaPF.Mod()*-1.);
              }
              if (fabs(vParaPu.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hParaPu[i]->Fill(vParaPu.Mod());
              } else {
                  hParaPu[i]->Fill(vParaPu.Mod()*-1.);
              }
              if (fabs(vParaCoPF.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hParaCoPF[i]->Fill(vParaCoPF.Mod());
              } else {
                  hParaCoPF[i]->Fill(vParaCoPF.Mod()*-1.);
              }
              if (fabs(vParaCoPu.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hParaCoPu[i]->Fill(vParaCoPu.Mod());
              } else {
                  hParaCoPu[i]->Fill(vParaCoPu.Mod()*-1.);
              }

// Perpendicular
//                  hPerpGen[i]->Fill(vPerpGen.Mod());
//                  hPerpPF[i]->Fill(vPerpPF.Mod());
//                  hPerpPu[i]->Fill(vPerpPu.Mod());
//                  hPerpCoPF[i]->Fill(vPerpCoPF.Mod());
//                  hPerpCoPu[i]->Fill(vPerpCoPu.Mod());
              if (fabs(vPerpGen.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hPerpGen[i]->Fill(vPerpGen.Mod());
              } else {
                  hPerpGen[i]->Fill(vPerpGen.Mod()*-1.);
              }
              if (fabs(vPerpPF.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hPerpPF[i]->Fill(vPerpPF.Mod());
              } else {
                  hPerpPF[i]->Fill(vPerpPF.Mod()*-1.);
              }
              if (fabs(vPerpPu.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hPerpPu[i]->Fill(vPerpPu.Mod());
              } else {
                  hPerpPu[i]->Fill(vPerpPu.Mod()*-1.);
              }
              if (fabs(vPerpCoPF.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hPerpCoPF[i]->Fill(vPerpCoPF.Mod());
              } else {
                  hPerpCoPF[i]->Fill(vPerpCoPF.Mod()*-1.);
              }
              if (fabs(vPerpCoPu.DeltaPhi(vH)) > TMath::Pi()/2)
              {
                  hPerpCoPu[i]->Fill(vPerpCoPu.Mod());
              } else {
                  hPerpCoPu[i]->Fill(vPerpCoPu.Mod()*-1.);
              }

			}

		}
	}


	float        aZMean[bin];
	float      aGenMean[bin];
	float   aParaGenMean[bin];
	float   aParaPFMean[bin];
	float   aParaPuMean[bin];
	float aParaCoPFMean[bin];
	float aParaCoPuMean[bin];
	float   aPerpGenMean[bin];
	float   aPerpPFMean[bin];
	float   aPerpPuMean[bin];
	float aPerpCoPFMean[bin];
	float aPerpCoPuMean[bin];
	

	float        aZMeanEr[bin];
	float      aGenMeanEr[bin];
	float   aParaGenMeanEr[bin];
	float   aParaPFMeanEr[bin];
	float   aParaPuMeanEr[bin];
	float aParaCoPFMeanEr[bin];
	float aParaCoPuMeanEr[bin];
	float   aPerpGenMeanEr[bin];
	float   aPerpPFMeanEr[bin];
	float   aPerpPuMeanEr[bin];
	float aPerpCoPFMeanEr[bin];
	float aPerpCoPuMeanEr[bin];
	
	float   aGenRes[bin];
	float   aPFRes[bin];
	float   aPuRes[bin];
	float aCoPFRes[bin];
	float aCoPuRes[bin];

	float   aGenResEr[bin];
	float   aPFResEr[bin];
	float   aPuResEr[bin];
	float aCoPFResEr[bin];
	float aCoPuResEr[bin];



	float    aGenParaSol[bin];
	float     aPFParaSol[bin];
	float     aPuParaSol[bin];
	float   aCoPFParaSol[bin];
	float   aCoPuParaSol[bin];

	float    aGenParaSolEr[bin];
	float     aPFParaSolEr[bin];
	float     aPuParaSolEr[bin];
	float   aCoPFParaSolEr[bin];
	float   aCoPuParaSolEr[bin];


	float    aGenPerpSol[bin];
	float     aPFPerpSol[bin];
	float     aPuPerpSol[bin];
	float   aCoPFPerpSol[bin];
	float   aCoPuPerpSol[bin];

	float    aGenPerpSolEr[bin];
	float     aPFPerpSolEr[bin];
	float     aPuPerpSolEr[bin];
	float   aCoPFPerpSolEr[bin];
	float   aCoPuPerpSolEr[bin];



	//TFile *f1 = new TFile("binHists.root", "RECREATE");
float total;
//cout << "Number of Events" << endl;
	for(int i = 0 ; i < bin ; i++)
	{
//cout <<i<<"th bin: "<< hH[i]->GetEntries() <<endl;
	        aZMean[i] =        hH[i]->GetMean();
	      aGenMean[i] =      hGen[i]->GetMean();
	   aParaGenMean[i] =   hParaGen[i]->GetMean();
	   aParaPFMean[i] =   hParaPF[i]->GetMean();
	   aParaPuMean[i] =   hParaPu[i]->GetMean();
	 aParaCoPFMean[i] =   hParaCoPF[i]->GetMean();
	 aParaCoPuMean[i] =   hParaCoPu[i]->GetMean();
	   aPerpGenMean[i] = hPerpGen[i]->GetMean();
	   aPerpPFMean[i] = hPerpPF[i]->GetMean();
	   aPerpPuMean[i] = hPerpPu[i]->GetMean();
	 aPerpCoPFMean[i] = hPerpCoPF[i]->GetMean();
	 aPerpCoPuMean[i] = hPerpCoPu[i]->GetMean();


	        aZMeanEr[i] =        hH[i]->GetRMS();
	      aGenMeanEr[i] =      hGen[i]->GetRMS();
	   aParaGenMeanEr[i] =   hParaGen[i]->GetRMS();
	   aParaPFMeanEr[i] =   hParaPF[i]->GetRMS();
	   aParaPuMeanEr[i] =   hParaPu[i]->GetRMS();
	 aParaCoPFMeanEr[i] =   hParaCoPF[i]->GetRMS();
	 aParaCoPuMeanEr[i] =   hParaCoPu[i]->GetRMS();
	   aPerpGenMeanEr[i] = hPerpGen[i]->GetRMS();
	   aPerpPFMeanEr[i] = hPerpPF[i]->GetRMS();
	   aPerpPuMeanEr[i] = hPerpPu[i]->GetRMS();
	 aPerpCoPFMeanEr[i] = hPerpCoPF[i]->GetRMS();
	 aPerpCoPuMeanEr[i] = hPerpCoPu[i]->GetRMS();
	
		
	  aGenRes[i] =   aParaGenMean[i] / aZMean[i];
	  aPFRes[i] =   aParaPFMean[i] / aZMean[i];
	  aPuRes[i] =   aParaPuMean[i] / aZMean[i];
//cout << " Pu Mean: "<< aParaPuMean[i] << endl;
	aCoPFRes[i] = aParaCoPFMean[i] / aZMean[i];
	aCoPuRes[i] = aParaCoPuMean[i] / aZMean[i];


	float Hx =  hH[i]->GetRMS() / sqrt(hH[i]->GetEntries());
	float Genx = hParaGen[i]->GetRMS() / sqrt(hParaGen[i]->GetEntries());
	float PFx = hParaPF[i]->GetRMS() / sqrt(hParaPF[i]->GetEntries());
	float Pux = hParaPu[i]->GetRMS() / sqrt(hParaPu[i]->GetEntries());
	float CoPFx = hParaCoPF[i]->GetRMS() / sqrt(hParaCoPF[i]->GetEntries());
	float CoPux = hParaCoPu[i]->GetRMS() / sqrt(hParaCoPu[i]->GetEntries());

		aGenResEr[i] = (aParaGenMean[i]/aZMean[i]) * sqrt( pow( Genx/aParaGenMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aPFResEr[i] = (aParaPFMean[i]/aZMean[i]) * sqrt( pow( PFx/aParaPFMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aPuResEr[i] = (aParaPuMean[i]/aZMean[i]) * sqrt( pow( Pux/aParaPuMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aCoPFResEr[i] = (aParaCoPFMean[i]/aZMean[i]) * sqrt( pow( CoPFx/aParaCoPFMean[i] , 2) + pow( Hx/aZMean[i], 2) );
		aCoPuResEr[i] = (aParaCoPuMean[i]/aZMean[i]) * sqrt( pow( CoPux/aParaCoPuMean[i] , 2) + pow( Hx/aZMean[i], 2) );

// Para Resolution
	    aGenParaSol[i]  = hParaGen[i]->GetRMS();
	     aPFParaSol[i]   = hParaPF[i]->GetRMS();
	     aPuParaSol[i]   = hParaPu[i]->GetRMS();
	   aCoPFParaSol[i] = hParaCoPF[i]->GetRMS();
	   aCoPuParaSol[i] = hParaCoPu[i]->GetRMS();

	    aGenParaSolEr[i]  = hParaGen[i]->GetRMSError();
	     aPFParaSolEr[i]   = hParaPF[i]->GetRMSError();
	     aPuParaSolEr[i]   = hParaPu[i]->GetRMSError();
	   aCoPFParaSolEr[i] = hParaCoPF[i]->GetRMSError();
	   aCoPuParaSolEr[i] = hParaCoPu[i]->GetRMSError();

// Perpendicular Resolution
	    aGenPerpSol[i] = hPerpGen[i]->GetRMS();
	     aPFPerpSol[i] = hPerpPF[i]->GetRMS();
	     aPuPerpSol[i] = hPerpPu[i]->GetRMS();
	   aCoPFPerpSol[i] = hPerpCoPF[i]->GetRMS();
	   aCoPuPerpSol[i] = hPerpCoPu[i]->GetRMS();

	    aGenPerpSolEr[i] = hPerpGen[i]->GetRMSError();
	     aPFPerpSolEr[i] = hPerpPF[i]->GetRMSError();
	     aPuPerpSolEr[i] = hPerpPu[i]->GetRMSError();
	   aCoPFPerpSolEr[i] = hPerpCoPF[i]->GetRMSError();
	   aCoPuPerpSolEr[i] = hPerpCoPu[i]->GetRMSError();


	}

	//f1->Close();

	float linx[2] = {0, maxi};
	float liny[2] = {1, 1};
	

	gStyle->SetPadLeftMargin(0.16);
	gStyle->SetPadBottomMargin(0.16);
	TGraphErrors *gHGen=   new TGraphErrors(bin, aZMean, aGenRes  , 0, aGenResEr  );
	TGraphErrors *gHPF =   new TGraphErrors(bin, aZMean, aPFRes  , 0, aPFResEr  );
	TGraphErrors *gHPu =   new TGraphErrors(bin, aZMean, aPuRes  , 0, aPuResEr  );
	TGraphErrors *gHCoPF = new TGraphErrors(bin, aZMean, aCoPFRes, 0, aCoPFResEr);
	TGraphErrors *gHCoPu = new TGraphErrors(bin, aZMean, aCoPuRes, 0, aCoPuResEr);

	  gHGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gHPu->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	gHCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	  gHGen->GetYaxis()->SetRangeUser(0, 2);
	  gHPF->GetYaxis()->SetRangeUser(0, 2);
	  gHPu->GetYaxis()->SetRangeUser(0, 2);
	gHCoPF->GetYaxis()->SetRangeUser(0, 2);
	gHCoPu->GetYaxis()->SetRangeUser(0, 2);

	  gHGen->SetMarkerStyle(20);
	  gHPF->SetMarkerStyle(20);
	  gHPu->SetMarkerStyle(20);
	gHCoPF->SetMarkerStyle(20);
	gHCoPu->SetMarkerStyle(20);
	  
	gHGen->SetLineColor(kGreen+3);
	  gHPF->SetLineColor(kBlue);
	  gHPu->SetLineColor(kRed);
	gHCoPF->SetLineColor(kBlue);
	gHCoPu->SetLineColor(kRed);
	  gHGen->SetLineWidth(3);
	  gHPF->SetLineWidth(3);
	  gHPu->SetLineWidth(3);
	gHCoPF->SetLineWidth(3);
	gHCoPu->SetLineWidth(3);

   TLegend *lg1 = new TLegend(0.4351753,0.6640816,0.8747914,0.8257143,NULL,"brNDC");
   TLatex *label = new TLatex(165.7277,1.856606,"VBF (H #rightarrow inv) PU200");

	lg1->SetLineWidth(0);
	lg1->AddEntry(gHGen, "Gen MET Response", "l");
	lg1->AddEntry(gHPF, "PF MET Response", "l");
	lg1->AddEntry(gHPu, "Puppi MET Response", "l");
	
	TCanvas *c1 = new TCanvas("c1", "", 1400, 650);
	c1->Divide(2, 1);

	c1->cd(1);
	gHGen->SetTitle("");
	gHGen->GetYaxis()->SetTitle("- <u_{||}> / <q_{T}>");
	gHGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gHGen->GetXaxis()->SetTitleSize(0.045);
	gHGen->GetXaxis()->CenterTitle();
	gHGen->GetYaxis()->SetTitleSize(0.045);
	gHGen->GetYaxis()->CenterTitle();
	gHGen->GetXaxis()->SetTitleOffset(0.9);
	gHGen->GetYaxis()->SetTitleOffset(1.2);
	gHGen->Draw("APL");
	gHPF->Draw("PLSAME");
	gHPu->Draw("PLSAME");
	label->Draw();
	lg1->Draw();

	c1->cd(2);
	gHGen->Draw("APL");
	gHCoPF->Draw("PLSAME");
	gHCoPu->Draw("PLSAME");
	label->Draw();
	lg1->Draw();

	c1->Print(sDir+"/MET_resp_"+sName+".pdf");

	TCanvas *cc0 = new TCanvas("cc0", "", 900, 800);
	gHGen->SetTitle("");
	gHGen->GetYaxis()->SetTitle("- <u_{||}> / <q_{T}>");
	gHGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gHGen->GetXaxis()->SetTitleSize(0.045);
	gHGen->GetXaxis()->CenterTitle();
	gHGen->GetYaxis()->SetTitleSize(0.045);
	gHGen->GetYaxis()->CenterTitle();
	gHGen->GetXaxis()->SetTitleOffset(0.9);
	gHGen->Draw("APL");
	gHPF->Draw("PLSAME");
	gHPu->Draw("PLSAME");
	label->Draw();
	lg1->Draw();

	cc0->Update();
	cc0->Print(sDir+"/MET_resp_"+sName+"_rawMET.pdf");

	
	TCanvas *cc1 = new TCanvas("cc1", "", 900, 800);
	gHGen->Draw("APL");
	gHCoPF->Draw("PLSAME");
	gHCoPu->Draw("PLSAME");
	label->Draw();
	lg1->Draw();

	cc1->Update();
	cc1->Print(sDir+"/MET_resp_"+sName+"_t1MET.pdf");

	float ymax = 200.;

	TGraphErrors *gParaGen  = new TGraphErrors(bin, aZMean,  aGenParaSol, 0,  aGenParaSolEr);
	TGraphErrors *gParaPF   = new TGraphErrors(bin, aZMean,   aPFParaSol, 0,   aPFParaSolEr);
	TGraphErrors *gParaPu   = new TGraphErrors(bin, aZMean,   aPuParaSol, 0,   aPuParaSolEr);
	TGraphErrors *gParaCoPF = new TGraphErrors(bin, aZMean, aCoPFParaSol, 0, aCoPFParaSolEr);
	TGraphErrors *gParaCoPu = new TGraphErrors(bin, aZMean, aCoPuParaSol, 0, aCoPuParaSolEr);
	
      gParaGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaPu->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gParaCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	   gParaGen->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPF->GetYaxis()->SetRangeUser(0, ymax);
	    gParaPu->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPF->GetYaxis()->SetRangeUser(0, ymax);
	  gParaCoPu->GetYaxis()->SetRangeUser(0, ymax);

	  gParaGen->SetMarkerStyle(20);
	  gParaPF->SetMarkerStyle(20);
	  gParaPu->SetMarkerStyle(20);
	  gParaCoPF->SetMarkerStyle(20);
	  gParaCoPu->SetMarkerStyle(20);
	  
	  gParaGen->SetLineColor(kGreen+3);
	  gParaPF->SetLineColor(kBlue);
	  gParaPu->SetLineColor(kRed);
	  gParaCoPF->SetLineColor(kBlue);
	  gParaCoPu->SetLineColor(kRed);
	   gParaGen->SetLineWidth(2);
	    gParaPF->SetLineWidth(2);
	    gParaPu->SetLineWidth(2);
	  gParaCoPF->SetLineWidth(2);
	  gParaCoPu->SetLineWidth(2);

   TLegend *lg_par = new TLegend(0.1773798,0.679377,0.5865314,0.8404941,NULL,"brNDC");
   TLatex *label2 = new TLatex(23.292138,187.2718,"VBF (H #rightarrow inv) PU200");
   TLegend *lg_par2 = new TLegend(0.1901109,0.5008163,0.5969421,0.662449,NULL,"brNDC");

   TLatex *label_par2 = new TLatex(30.42342,143.4694,"VBF (H #rightarrow inv) PU200");
	lg_par->SetLineWidth(0);
	 lg_par->AddEntry(gParaGen, "Gen MET Resolution", "l");
	   lg_par->AddEntry(gParaPF, "PF MET Resolution", "l");
	lg_par->AddEntry(gParaPu, "Puppi MET Resolution", "l");

	lg_par2->SetLineWidth(0);
	 lg_par2->AddEntry(gParaGen, "Gen MET Resolution", "l");
	   lg_par2->AddEntry(gParaPF, "PF MET Resolution", "l");
	lg_par2->AddEntry(gParaPu, "Puppi MET Resolution", "l");
	
	TCanvas *cPa = new TCanvas("cPa", "", 1400, 650);
	cPa->cd();
	cPa->Divide(2, 1);

	cPa->cd(1);
	gParaGen->SetTitle("");
	gParaGen->GetYaxis()->SetTitle("#sigma(u_{||})");
	gParaGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gParaGen->GetXaxis()->SetTitleSize(0.045);
	gParaGen->GetXaxis()->CenterTitle();
	gParaGen->GetYaxis()->SetTitleSize(0.045);
	gParaGen->GetYaxis()->CenterTitle();
	gParaGen->GetXaxis()->SetTitleOffset(0.9);
	gParaGen->GetYaxis()->SetTitleOffset(1.2);
	gParaGen->Draw("APL");
	gParaPF->Draw("PLSAME");
	gParaPu->Draw("PLSAME");
	label2->Draw();
	lg_par->Draw();

	cPa->cd(2);
	gParaGen->Draw("APL");
	gParaCoPF->Draw("PLSAME");
	gParaCoPu->Draw("PLSAME");
	label_par2->Draw();
	lg_par2->Draw();

	cPa->Print(sDir+"/MET_resol_para_"+sName+".pdf");

	TCanvas *ccP0 = new TCanvas("ccP0", "", 900, 800);
	gParaGen->SetTitle("");
	gParaGen->GetYaxis()->SetTitle("#sigma(u_{||})");
	gParaGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gParaGen->GetXaxis()->SetTitleSize(0.045);
	gParaGen->GetXaxis()->CenterTitle();
	gParaGen->GetYaxis()->SetTitleSize(0.045);
	gParaGen->GetYaxis()->CenterTitle();
	gParaGen->GetXaxis()->SetTitleOffset(0.9);
	gParaGen->GetYaxis()->SetTitleOffset(1.2);
	gParaGen->Draw("APL");
	gParaPF->Draw("PLSAME");
	gParaPu->Draw("PLSAME");
	label2->Draw();
	lg_par->Draw();

	ccP0->Update();
	ccP0->Print(sDir+"/MET_resol_para_"+sName+"_rawMET.pdf");


	TCanvas *ccP1 = new TCanvas("ccP1", "", 900, 800);
	gParaGen->Draw("APL");
	gParaCoPF->Draw("PLSAME");
	gParaCoPu->Draw("PLSAME");
	label2->Draw();
	lg_par2->Draw();
	ccP1->Update();
	ccP1->Print(sDir+"/MET_resol_para_"+sName+"_t1MET.pdf");


	TGraphErrors *gPerpGen  = new TGraphErrors(bin, aZMean,  aGenPerpSol, 0,  aGenPerpSolEr);
	TGraphErrors *gPerpPF   = new TGraphErrors(bin, aZMean,   aPFPerpSol, 0,   aPFPerpSolEr);
	TGraphErrors *gPerpPu   = new TGraphErrors(bin, aZMean,   aPuPerpSol, 0,   aPuPerpSolEr);
	TGraphErrors *gPerpCoPF = new TGraphErrors(bin, aZMean, aCoPFPerpSol, 0, aCoPFPerpSolEr);
	TGraphErrors *gPerpCoPu = new TGraphErrors(bin, aZMean, aCoPuPerpSol, 0, aCoPuPerpSolEr);
	
      gPerpGen->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpPu->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPF->GetXaxis()->SetRangeUser(0, maxi+20);
	  gPerpCoPu->GetXaxis()->SetRangeUser(0, maxi+20);

	   gPerpGen->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPF->GetYaxis()->SetRangeUser(0, ymax);
	    gPerpPu->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPF->GetYaxis()->SetRangeUser(0, ymax);
	  gPerpCoPu->GetYaxis()->SetRangeUser(0, ymax);

	  gPerpGen->SetMarkerStyle(20);
	  gPerpPF->SetMarkerStyle(20);
	  gPerpPu->SetMarkerStyle(20);
	  gPerpCoPF->SetMarkerStyle(20);
	  gPerpCoPu->SetMarkerStyle(20);
	  
	  gPerpGen->SetLineColor(kGreen+3);
	  gPerpPF->SetLineColor(kBlue);
	  gPerpPu->SetLineColor(kRed);
	  gPerpCoPF->SetLineColor(kBlue);
	  gPerpCoPu->SetLineColor(kRed);
	   gPerpGen->SetLineWidth(2);
	    gPerpPF->SetLineWidth(2);
	    gPerpPu->SetLineWidth(2);
	  gPerpCoPF->SetLineWidth(2);
	  gPerpCoPu->SetLineWidth(2);

   TLegend *lg_per = new TLegend(0.1848176,0.6314286,0.7242787,0.8404082,NULL,"brNDC");
   TLegend *lg_per2 = new TLegend(0.1826598,0.4061224,0.7221209,0.615102,NULL,"brNDC");

	lg_per->SetLineWidth(0);
	lg_per->AddEntry(gPerpGen, "Gen MET Resolution", "l");
	lg_per->AddEntry(gPerpPF, "PF MET Resolution", "l");
	lg_per->AddEntry(gPerpPu, "Puppi MET Resolution", "l");
	lg_per2->SetLineWidth(0);
	lg_per2->AddEntry(gPerpGen, "Gen MET Resolution", "l");
	lg_per2->AddEntry(gPerpPF, "PF MET Resolution", "l");
	lg_per2->AddEntry(gPerpPu, "Puppi MET Resolution", "l");
	
	TCanvas *cPe = new TCanvas("cPe", "", 1400, 650);
	cPe->Divide(2, 1);

	cPe->cd(1);
	gPerpGen->SetTitle("");
	gPerpGen->GetYaxis()->SetTitle("#sigma(u_{#perp}  )");
	gPerpGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gPerpGen->GetXaxis()->SetTitleSize(0.045);
	gPerpGen->GetXaxis()->CenterTitle();
	gPerpGen->GetYaxis()->SetTitleSize(0.045);
	gPerpGen->GetYaxis()->CenterTitle();
	gPerpGen->GetXaxis()->SetTitleOffset(0.9);
	gPerpGen->GetYaxis()->SetTitleOffset(1.2);
	gPerpGen->Draw("APL");
	gPerpPF->Draw("PLSAME");
	gPerpPu->Draw("PLSAME");
	label2->Draw();
	lg_per->Draw();

   TLatex *label_per2 = new TLatex(24.08616,132.8571,"VBF (H #rightarrow inv) PU200");
	cPe->cd(2);
	gPerpGen->Draw("APL");
	gPerpCoPF->Draw("PLSAME");
	gPerpCoPu->Draw("PLSAME");
	label_per2->Draw();
	lg_per2->Draw();

	cPe->Print(sDir+"/MET_resol_perp_"+sName+".pdf");

	TCanvas *ccPe1 = new TCanvas("ccPe1", "", 900, 800);
	gPerpGen->SetTitle("");
	gPerpGen->GetYaxis()->SetTitle("#sigma(u_{#perp}  )");
	gPerpGen->GetXaxis()->SetTitle("q_{T} [GeV]");
	gPerpGen->GetXaxis()->SetTitleSize(0.045);
	gPerpGen->GetXaxis()->CenterTitle();
	gPerpGen->GetYaxis()->SetTitleSize(0.045);
	gPerpGen->GetYaxis()->CenterTitle();
	gPerpGen->GetXaxis()->SetTitleOffset(0.9);
	gPerpGen->GetYaxis()->SetTitleOffset(1.2);
	gPerpGen->Draw("APL");
	gPerpPF->Draw("PLSAME");
	gPerpPu->Draw("PLSAME");
	label2->Draw();
	lg_per->Draw();

	ccPe1->Update();
	ccPe1->Print(sDir+"/MET_resol_perp_"+sName+"_rawMET.pdf");


	TCanvas *ccPe2 = new TCanvas("ccPe2", "", 900, 800);
	gPerpGen->Draw("APL");
	gPerpCoPF->Draw("PLSAME");
	gPerpCoPu->Draw("PLSAME");
	label2->Draw();
	lg_per->Draw();
	ccPe2->Update();
	ccPe2->Print(sDir+"/MET_resol_perp_"+sName+"_t1MET.pdf");


	


/*
	TCanvas *c3 = new TCanvas("c3", "", 1000, 500);
	c3->Divide(2,1);

	c3->cd(1);
	hInv->Draw();

	c3->cd(2);
	hInv_pu0->Draw();
*/
}
