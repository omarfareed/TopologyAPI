#include "VoltageSource.h"

VlotageSource::VlotageSource(string id, map<string, string>& VlotageSourceNetlist, map<string, int>& VlotageSourceValues):TwoTerminal(id , VlotageSourceNetlist , VlotageSourceValues)
{

}

string VlotageSource::getType()
{
	return "VlotageSource";
}

void VlotageSource::printComponentInfo()
{
	printf("VlotageSource with default value : %d, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
}