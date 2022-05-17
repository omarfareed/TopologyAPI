#pragma once
#include "Component.h"
class ThreeTerminal : public Component {
protected:
	bool validNetlist( map<string, string>& netlist);
	void setNetlist( map<string, string>& netlist);
public:
	ThreeTerminal(const ThreeTerminal& other);
	ThreeTerminal( string id, map<string, string>& netlist, map<string, double>& info);	
	bool connectedTo(Component* component);
	void setDrain(string terminal);
	void setGate(string terminal);
	void setSource(string terminal);
	string getDrain();
	string getGate();
	string getSource();
	virtual void printComponentInfo() = 0;
};