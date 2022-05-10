#include "NMOS.h"
NMOS::NMOS(string id, map<string, double>& info, map<string, string>& netlist):ThreeTerminal(id , netlist,info)
{
}

string NMOS::getType()
{
	return string();
}

void NMOS::printComponentInfo()
{
	printf("NMOS component with default value : %lf and three terminals : %s %s %s", this->defaultValue, this->getT1().c_str(), this->getT2().c_str(), this->getT3().c_str());
}
