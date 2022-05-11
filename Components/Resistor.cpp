#include "Resistor.h"

Resistor::Resistor(string id, map<string, string>& ResistorNetlist, map<string, double>& ResistorValues):TwoTerminal(id , ResistorNetlist , ResistorValues)
{

}

string Resistor::getType()
{
	return "Resistor";
}

void Resistor::printComponentInfo()
{
	//printf("Resistor with default value : %lf, t1 : %s, t2 : %s\n", this->defaultValue, this->getT1().c_str(), this->getT2().c_str());
	cout << "Resistor with defualt value : " << this->defaultValue << " T1 : " << getT1() << ", T2 : " << getT2() << endl;
}
