#include "Component.h"
class TwoTerminal : public Component {
protected:
	bool validNetlist(map<string, string>& netlist);
	void setNetlist(map<string, string>& netlist);
public:
	void setT1(string terminal)
	{
		if (netlist["t1"] == "")
		{
			printf("error in termianl value");
			return;
		}
		this->netlist["t1"] = terminal;
	}
	void setT2(string terminal)
	{
		if (netlist["t2"] == "")
		{
			printf("error in terminal value");
			return;
		}
		this->netlist["t2"] = terminal;
	}
	string getT1()
	{
		return this->netlist["t1"];
	}
	string getT2()
	{
		return this->netlist["t2"];
	}
	TwoTerminal( string id, map<string, string>& netlist, map<string, int>& info);
};