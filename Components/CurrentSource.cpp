#include "CurrentSource.h"

CurrentSource::CurrentSource(const CurrentSource& other):CurrentSource(other)
{
}

CurrentSource CurrentSource::operator=(const CurrentSource& other)
{
	this->_copyComponentValues(other);
	return* this;
}

CurrentSource::CurrentSource(string id, map<string, string>& CurrentSourceNetlist, map<string, double>& CurrentSourceValues):TwoTerminal(id , CurrentSourceNetlist , CurrentSourceValues)
{

}

string CurrentSource::getType()
{
	return "CurrentSource";
}

void CurrentSource::printComponentInfo()
{
	printf("CurrentSource with default value : %lf, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
}