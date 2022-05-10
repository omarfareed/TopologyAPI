#include "Component.h"
class ThreeTerminal : public Component {
protected:
	bool validNetlist( map<string, string>& netlist);
	void setNetlist( map<string, string>& netlist);
public:
	ThreeTerminal( string id, map<string, string>& netlist, map<string, int>& info);
	void setT1(string terminal);
	void setT2(string terminal);
	void setT3(string terminal);
	string getT1();
	string getT2();
	string getT3();
	virtual void printComponentInfo() = 0;
};