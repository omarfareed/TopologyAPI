#include "Component.h"


bool Component::validComponentValues(map<string, double>& info)
{
	// count returns 1 if the key exist else it returns 0
	if (!info.count("min") || !info.count("max") || !info.count("default"))
		return false;
	// min < default < max && min >= 0
	return info["default"] >= info["min"] && info["defualt"] <= info["max"] && info["min"] >= 0;
}

void Component::_copyComponentValues(const Component& other)
{
	this->id = other.id;
	this->defaultValue = other.defaultValue;
	this->minValue = other.minValue;
	this->maxValue = other.maxValue;
	this->netlist = other.netlist;
}
Component::Component(const Component& other)
{
	this->_copyComponentValues(other);
}


Component::Component( string id, map<string,double> &componentValues)
{
	this->setID(id);
	this->setComponentValues(componentValues);
}
bool Component::operator==(const Component& other)const
{
	return this->getType() == other.getType() &&
		this->netlist == other.netlist &&
		this->defaultValue == other.defaultValue &&
		this->minValue == other.minValue &&
		this->maxValue == other.maxValue;
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

string Component::getID() const
{
	return id;
}

void Component::setMaxValue(double val)
{
	if (val < this->minValue)
	{
		cout << "Wrong Max value " << val << endl;
		return;
	}
	this->maxValue = val;
}

double Component::getMaxValue() const
{
	return this->maxValue;
}

void Component::setMinValue(double val)
{
	if (val > 0 && this->defaultValue < val)
		cout << "Wrong Min value : " << val << endl;
	this->minValue = val;
}

double Component::getMinValue() const
{
	return this->minValue;
}

void Component::setDefaultValue(double val)
{
	if (val > this->maxValue || val < this->minValue)
		cout << "Wrong default Value";
	this->defaultValue = val;
}

double Component::getDefaultValue() const
{
	return this->defaultValue;
}

map<string, string> Component::getNetlist() const
{
	return this->netlist;
}

void Component::setSingleNetlistTerminal(string terminal, string value)
{
	if (value == "" || terminal == "")
		cout << "Wrong Terminal Value" << endl;
	this->netlist[terminal] = value;
}

