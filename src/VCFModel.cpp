#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <libgen.h>
#include <string.h>
#include <sstream>


using namespace std;
inline bool FileExist(const std::string& name)
{
    ifstream file(name);
    if(!file)            // If the file was not found, then file is 0, i.e. !file=1 or true.
        return false;    // The file was not found.
    else                 // If the file was found, then file is non-0.
        return true;     // The file was found.
}
vector<string> GetVCFContent(string FAddress)
{
	vector<string> collection;
	if (!FileExist(FAddress))
	{
		cout <<"Can not locate .vcf file with provided address"<<endl;
		return collection;
	}

	ifstream file(FAddress);
	string line;
	while(getline(file, line))
	{
		if (line.length()>0 && line[0]!='#')
		{
			collection.push_back(line);
		}
	}
	file.close();
	return collection;
}
bool starts_with(const std::string &value1, const std::string &value2)
{
	return value1.find(value2) == 0;
}
void CheckSingleVariantRatio(int Variant,int Total,string FAddress)
{

	vector<string> Res=GetVCFContent(FAddress);
	for(int i = 0; i != Res.size(); i++)
	{
//	    /* std::cout << someVector[i]; ... */
//		cout << Res[i];
//		cout<<endl;

		istringstream ss(Res[i]);
		string CHROM,POS,ID,REF,ALT,QUAL,FILTER,INFO,FORMAT,sample1;
		ss >> CHROM>>POS>>ID>>REF>>ALT>>QUAL>>FILTER>>INFO>>FORMAT>>sample1;
		cout <<sample1;
		////Explode sample1
		stringstream samplestream;
		samplestream<<sample1;

		std::vector<std::string> words;
		string inside1;
		string inside2;
		string inside3;
		string inside4;

		 getline(samplestream, inside1, ',' );
		 getline(samplestream, inside2, ',' );
		 getline(samplestream, inside3, ',' );
		 getline(samplestream, inside4, ',' );

		 ///Data is inside2
		 cout <<"Inside is:"<<inside2<<endl;

		 ///

		 stringstream xss;
		 xss << std::fixed << Variant << ':' << Total ;
		 string CheckRatio = xss.str();

		 cout <<"Check ratio is:"<<CheckRatio<<endl;
		 if (starts_with(inside2,CheckRatio))
			 {
			 cout<<"PASSED"<<endl;
			 }
		 else
		 {
			 cout<<"FAILED"<<endl;
		 }
		 //sprintf(CheckRatio,"%i:%",Variant,Total);





	  }
}
