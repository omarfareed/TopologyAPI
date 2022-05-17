#pragma once
#include "ThreeTerminal.h"
class PMOS : public ThreeTerminal
{

public:
	PMOS(const PMOS& other);
	PMOS operator=(const PMOS& other);
	PMOS(string id , map<string,double>&info , map<string,string>&netlist);
	string getType();
	void printComponentInfo();
};