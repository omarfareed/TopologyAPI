#include "VoltageSource.h"

VoltageSource::VoltageSource(const VoltageSource& other):TwoTerminal(other)
{
}

VoltageSource::VoltageSource(string id, map<string, string>& VoltageSourceNetlist, map<string, double>& VoltageSourceValues):TwoTerminal(id , VoltageSourceNetlist , VoltageSourceValues){

}

VoltageSource VoltageSource::operator=(const VoltageSource& other)
{
	this->_copyComponentValues(other);
	return *this;
}

string VoltageSource::getType() const
{
	return "VoltageSource";
}

void VoltageSource::printComponentInfo() const
{
	printf("VoltageSource with default value : %lf, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
}