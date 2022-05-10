#include "ThreeTerminal.h"
class PMOS : public ThreeTerminal
{

public:
	PMOS(string id , map<string,double>&info , map<string,string>&netlist);
	string getType();
	void printComponentInfo();
};