#pragma once
#include "Component.h"
class ThreeTerminal : public Component {
protected:
	bool validNetlist( map<string, string>& netlist);
	void setNetlist( map<string, string>& netlist);
public:
	ThreeTerminal(const ThreeTerminal& other) ;
	ThreeTerminal( string id, map<string, string>& netlist, map<string, double>& info);	
	bool connectedTo(Component* component) const;
	void setDrain(string terminal);
	void setGate(string terminal);
	void setSource(string terminal);
	string getDrain() const ;
	string getGate() const;
	string getSource() const ;
	virtual void printComponentInfo() const = 0  ;
};