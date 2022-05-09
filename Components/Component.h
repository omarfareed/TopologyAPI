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
	int defaultValue;
	int minValue;
	int maxValue;
	map<string , string> netlist;
	bool validComponentValues(map<string, int>& componentInfo);
	virtual bool validNetlist(map<string,string>&) = 0;
	virtual void setNetlist(map<string, string>&) = 0;
public:
	Component( string id, map<string, int>& componentValues);
	virtual void setComponentValues(map<string, int>&);
	virtual string getType() = 0;
	virtual void setID(string id);
	virtual string getID();
	virtual void setMaxValue(int val);
	virtual int getMaxValue();
	virtual	void setMinValue(int val);
	virtual int getMinValue();
	virtual void setDefaultValue(int val);
	virtual int getDefaultValue();
	virtual void printComponentInfo() = 0;
};

