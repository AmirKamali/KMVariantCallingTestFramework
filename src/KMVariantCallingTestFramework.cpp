//============================================================================
// Name        : KMReadGenerator.cpp
// Author      : AmirHossein Kamali
// Version     :
// Copyright   : This project is part of a study in Victor Chang Cardiac Institue
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "string.h"
#include "VCFModel.h"
using namespace std;
void ReadKeys(int argc, char* argv[])
{
	string FileAddress="";
	int TotalReads=0;
	int TotalVariants=0;

	 if (argc < 3) { // Check the value of argc. If not enough parameters have been passed, inform user and exit.
	        std::cout << "Usage is -vcf <refrence>  -t <total reads> -v<total variants>"<<endl<<endl; // Inform the user of how to use the program
	    } else { // if we got enough parameters...
	        char* myFile, myPath, myOutPath;
	        std::cout << argv[0];
	        for (int i = 1; i < argc; i+=2) { /* We will iterate over argv[] to get the parameters stored inside.
	                                          * Note that we're starting on 1 because we don't need to know the
	                                          * path of the program, which is stored in argv[0] */
	            if (i + 1 != argc) // Check that we haven't finished parsing already
	                if (strcmp(argv[i] ,"-vcf")==0) {
	                    // We know the next argument *should* be the filename:
	                    FileAddress = argv[i + 1];
	                }
	                else if (strcmp(argv[i] , "-r")==0) {
	                    TotalReads = stoi( argv[i + 1]);
	                }
	                else if (strcmp(argv[i], "-v")==0) {
	                    TotalVariants = stoi(argv[i + 1]);
	                }
	                else {
	                    std::cout << "Not enough or invalid arguments, please try again."<<endl;
	                    std::cout <<"PARAMETERS:"<< argv[i] << " "<<endl;
	            }

	        }
	    }
	 if (FileAddress.length()==0)
	 {
		 cout <<"Reference address is not specified."<<endl;
		 return;
	 }
	 else if (TotalReads<1)
	 {
		 cout <<"Reads should be more than 0";
		 return;
	 }
	 else if (TotalVariants<0)
	 {
		 cout <<"Variants should be 0+";
		 return;
	 }

	 cout <<"Preparing to check :"<<TotalReads<<" - "<<TotalVariants<<endl;
	 CheckSingleVariantRatio(TotalVariants,TotalReads,FileAddress);
}

int main(int argc, char* argv[]) {
	cout <<endl<< "Random Read Generator initializing" << endl;
	ReadKeys(argc,argv);

	return 0;
}
