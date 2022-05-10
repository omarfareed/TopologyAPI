#include "Component.h"


bool Component::validComponentValues(map<string, double>& info)
{
	// count returns 1 if the key exist else it returns 0
	if (!info.count("min") || !info.count("max") || !info.count("default"))
		return false;
	// min < default < max && min >= 0
	return info["default"] >= info["min"] && info["defualt"] <= info["max"] && info["min"] >= 0;
}

Component::Component( string id, map<string,double> &componentValues)
{
	this->setID(id);
	this->setComponentValues(componentValues);
}
void Component::setComponentValues(map<string, double>& componentValues)
{
	if (!validComponentValues(componentValues))
		printf("invalid component values\n");
	this->defaultValue = componentValues["default"];
	this->minValue = componentValues["min"];
	this->maxValue = componentValues["max"];
}

void Component::setID(string id)
{
	if(id == "")
	{
		printf("invalid component ID\n");
		return;
	}
	this->id = id;
}

string Component::getID()
{
	return id;
}

void Component::setMaxValue(double val)
{
	if (val < this->minValue)
	{
		printf("wrong max value %d\n" , val);
		return;
	}
	this->maxValue = val;
}

double Component::getMaxValue()
{
	return this->maxValue;
}

void Component::setMinValue(double val)
{
	if (val > 0 && this->defaultValue < val)
		printf("wrong min value %d\n" , val);
	this->minValue = val;
}

double Component::getMinValue()
{
	return this->minValue;
}

void Component::setDefaultValue(double val)
{
	if (val > this->maxValue || val < this->minValue)
		printf("wrong default value %d\n" , val);
	this->defaultValue = val;
}

double Component::getDefaultValue()
{
	return this->defaultValue;
}

void Component::setSingleNetlistTerminal(string terminal, string value)
{
	if (value == "" || terminal == "")
		printf("wrong terminal value\n");
	this->netlist[terminal] = value;
}

