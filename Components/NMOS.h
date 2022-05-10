#include "ThreeTerminal.h"
class NMOS : public ThreeTerminal
{

public:
	NMOS(string id , map<string,double>&info , map<string,string>&netlist);
	string getType();
	void printComponentInfo();
};