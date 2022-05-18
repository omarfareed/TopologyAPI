#include "PMOS.h"
PMOS::PMOS(const PMOS& other):ThreeTerminal(other)
{
}
PMOS PMOS::operator=(const PMOS& other)
{
	this->_copyComponentValues(other);
	return *this;
}
PMOS::PMOS(string id, map<string, double>& info, map<string, string>& netlist):ThreeTerminal(id , netlist,info)
{
}

string PMOS::getType() const
{
	return string();
}

void PMOS::printComponentInfo() const
{
	//printf("PMOS component with default value : %lf and three terminals : %s %s %s", this->defaultValue, this->getT1().c_str(), this->getT2().c_str(), this->getT3().c_str());
	cout << "PMOS with defualt value : " << this->defaultValue << " Drain : " << getDrain() << ", Gate : " << getGate() << ", Source: " << getSource() << endl;
}