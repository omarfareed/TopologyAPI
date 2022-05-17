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
	virtual void _copyComponentValues(const Component& other);
public:
	Component(const Component& other);
	Component( string id, map<string, double>& componentValues);
	bool operator==(const Component& other) const;
	virtual void setComponentValues(map<string, double>&);
	virtual string getType() const = 0;
	virtual void setID(string id) ;
	virtual string getID() const;
	virtual void setMaxValue(double val);
	virtual double getMaxValue() const;
	virtual	void setMinValue(double val);
	virtual double getMinValue() const;
	virtual void setDefaultValue(double val);
	virtual double getDefaultValue() const;
	virtual void printComponentInfo() const= 0;
	virtual map<string, string> getNetlist() const;
	virtual bool connectedTo(Component* component) const = 0;
};

