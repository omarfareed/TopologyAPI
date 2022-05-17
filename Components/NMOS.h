#pragma once
#include "ThreeTerminal.h"
class NMOS : public ThreeTerminal
{

public:
	NMOS operator=(const NMOS& other);
	NMOS(const NMOS& other);
	NMOS(string id , map<string,string>&netlist ,  map<string,double>&info );
	string getType();
	void printComponentInfo();
};