#pragma once
#include "TwoTerminal.h"
class CurrentSource : public TwoTerminal
{
private:
public:
	CurrentSource(const CurrentSource& other);
	CurrentSource operator=(const CurrentSource& other);
	CurrentSource(string id, map<string, string>& CurrentSourceNetlist, map<string, double>& CurrentSourceValues);
	string getType() const;
	void printComponentInfo() const;
};