//============================================================================
// Name        : KMReadGenerator.cpp
// Author      : AmirHossein Kamali
// Version     :
// Copyright   : This project is part of a study in Victor Chang Cardiac Institue
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "VCFModel.h"
using namespace std;

int main(int argc, char* argv[]) {
	cout <<endl<< "Random Read Generator initializing" << endl;
	//ReadKeys(argc,argv);
	//GetVCFContent();
	CheckSingleVariantRatio(45,95,"/Users/Amir/Desktop/GATK/EXP/GATK\ Testing\ Scripts/2-SNPCall/raw_variants.vcf");
	return 0;
}
