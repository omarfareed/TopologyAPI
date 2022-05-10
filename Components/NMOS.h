#include "ThreeTerminal.h"
class NMOS : public ThreeTerminal
{

public:
	NMOS(string id , map<string,int>&info , map<string,string>&netlist);
	string getType();
	void printComponentInfo();
};