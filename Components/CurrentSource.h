#include "TwoTerminal.h"
class CurrentSource : public TwoTerminal
{
private:
public:
	CurrentSource(string id, map<string, string>& CurrentSourceNetlist, map<string, int>& CurrentSourceValues);
	string getType();
	void printComponentInfo();
};