#include "CurrentSource.h"

CurrentSource::CurrentSource(string id, map<string, string>& CurrentSourceNetlist, map<string, int>& CurrentSourceValues):TwoTerminal(id , CurrentSourceNetlist , CurrentSourceValues)
{

}

string CurrentSource::getType()
{
	return "CurrentSource";
}

void CurrentSource::printComponentInfo()
{
	printf("CurrentSource with default value : %d, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
}