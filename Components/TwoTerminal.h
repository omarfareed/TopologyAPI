#pragma once
#include "Component.h"
class TwoTerminal : public Component {
protected:
	bool validNetlist(map<string, string>& netlist);
	void setNetlist(map<string, string>& netlist);
public:
	TwoTerminal( string id, map<string, string>& netlist, map<string, double>& info);
	void setT1(string terminal);
	void setT2(string terminal);
	bool connectedTo(Component* component);
	string getT1();
	string getT2();
	virtual void printComponentInfo() = 0;
};