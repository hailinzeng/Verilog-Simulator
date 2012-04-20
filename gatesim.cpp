/**
* PA5 Part 1
* Chris Li, Grayson Smith
*/
#include "global.h"
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"

using namespace std;

void dumpToFile(string from, string filename, Design* aDesign)
{
  ofstream outfile(filename.c_str());
  outfile << "// Dumped from " << from << endl;
  aDesign->dump(outfile); 
  
  outfile.close();
}

int main (int argc, char const *argv[])
{
  if (argc <= 2)
		{
	 		cout << "Usage: " << argv[0] << " <Input Filename>  <Output Filename>" << endl;
			return 1;
	  }
	string ifile = argv[1];
	string ofile = argv[2];
	
	Design *a;
	try{
		a = parseThatShit(ifile);
	} catch(runtime_error &ex)	{
    stringstream ss;
    ss << "Reason: " << ex.what();
    ERROR(ss.str());
		return -1;
	}
	dumpToFile(ifile, ofile, a);
  
  delete a;
  
  return 0;
}