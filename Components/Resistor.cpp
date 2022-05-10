#include "Resistor.h"

Resistor::Resistor(string id, map<string, string>& ResistorNetlist, map<string, int>& ResistorValues):TwoTerminal(id , ResistorNetlist , ResistorValues)
{

}

string Resistor::getType()
{
	return "Resistor";
}

void Resistor::printComponentInfo()
{
	printf("Resistor with default value : %d, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
}
