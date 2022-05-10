#include "TwoTerminal.h"
class Resistor : public TwoTerminal
{
private:
public:
	Resistor(string id, map<string, string>& ResistorNetlist, map<string, int>& ResistorValues);
	string getType();
	void printComponentInfo();
};