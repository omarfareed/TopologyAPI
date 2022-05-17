#pragma once
#include "TwoTerminal.h"
class VoltageSource : public TwoTerminal
{
private:
public:
	VoltageSource(const VoltageSource& other);
	VoltageSource operator=(const VoltageSource& other);
	VoltageSource(string id, map<string, string>& VoltageSourceNetlist, map<string, double>& VoltageSourceValues);
	string getType();
	void printComponentInfo();
};