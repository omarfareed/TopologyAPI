#include "Component.h"


bool Component::validComponentValues(map<string, int>& info)
{
	// count returns 1 if the key exist else it returns 0
	if (info.count("min") || info.count("max") || info.count("default"))
	{
		return false;
	}
	// min < default < max && min >= 0
	return info["default"] >= info["min"] && info["defualt"] <= info["max"] && info["min"] >= 0;
}

Component::Component( string id, map<string,int> &componentValues)
{
	this->setID(id);
	this->setComponentValues(componentValues);
}
void Component::setComponentValues(map<string, int>& componentValues)
{

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

void Component::setMaxValue(int val)
{
	if (val < this->minValue)
	{
		printf("Wrong max value\n");
		return;
	}
	this->maxValue = val;
}

int Component::getMaxValue()
{
	return maxValue;
}

void Component::setMinValue(int val)
{
	if (this->maxValue > val && val > 0 && this->defaultValue > val)
		printf("error in setting the component min value");
	this->minValue = val;
}

int Component::getMinValue()
{
	return this->minValue;
}

void Component::setDefaultValue(int val)
{
	if (val > this->maxValue || val < this->minValue)
		printf("error in setting the component default value");
	this->defaultValue = val;
}

int Component::getDefaultValue()
{
	return this->defaultValue;
}

