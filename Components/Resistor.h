#pragma once
#include "TwoTerminal.h"
class Resistor : public TwoTerminal
{
private:
public:
	Resistor(string id, map<string, string>& ResistorNetlist, map<string, double>& ResistorValues);
	string getType();
	void printComponentInfo();
};