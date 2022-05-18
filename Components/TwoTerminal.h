#pragma once
#include "Component.h"
class TwoTerminal : public Component {
protected:
	bool validNetlist(map<string, string>& netlist);
	void setNetlist(map<string, string>& netlist);
public:
	TwoTerminal(const TwoTerminal& other);
	TwoTerminal( string id, map<string, string>& netlist, map<string, double>& info);
	void setT1(string terminal);
	void setT2(string terminal);
	bool connectedTo(Component* component) const;
	string getT1() const;
	string getT2() const;
	virtual void printComponentInfo() const = 0;
};