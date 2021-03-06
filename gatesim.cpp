/**
* PA6
* Chris Li, Grayson Smith
*/
#include "global.h"
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include "logicsim.h"

using namespace std;

int main (int argc, char const *argv[])
{
  if (argc <= 3)
		{
	 		cout << "Usage: " << argv[0] << " <Input Filename> <Input SimFile>  <Output Filename>" << endl;
			return 1;
	  }
	string ifile = argv[1];
	string sfile = argv[2];
	string ofile = argv[3];
	
	Design *a;
	try{
		a = parseThatShit(ifile);
		a->toposort();
		deque<Net *> list = a->get_toposortedList();
		LogicSim sim(sfile, a);
		sim.runSimulation(list);
		sim.outputTheFile(ofile, a);
	} catch(runtime_error &ex)	{
    stringstream ss;
    ss << "Reason: " << ex.what();
    ERROR(ss.str());
		return -1;
	}
	//dumpToFile(ifile, ofile, a);
	
  delete a;
  
  return 0;
}