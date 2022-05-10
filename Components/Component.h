#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>
using std::string;
using std::endl;
using std::cin;
using std::cout;
using std::vector;
using std::map;
class Component
{
protected:
	string id;
	double defaultValue;
	double minValue;
	double maxValue;
	map<string , string> netlist;
	virtual bool validNetlist(map<string,string>&) = 0;
	virtual void setNetlist(map<string, string>&) = 0;
	virtual bool validComponentValues(map<string, double>& componentInfo);
	virtual void setSingleNetlistTerminal(string terminal , string value);
public:
	Component( string id, map<string, double>& componentValues);
	virtual void setComponentValues(map<string, double>&);
	virtual string getType() = 0;
	virtual void setID(string id);
	virtual string getID();
	virtual void setMaxValue(double val);
	virtual double getMaxValue();
	virtual	void setMinValue(double val);
	virtual double getMinValue();
	virtual void setDefaultValue(double val);
	virtual double getDefaultValue();
	virtual void printComponentInfo() = 0;
	virtual bool connectedTo(Component* component) = 0;
};

