#include "TwoTerminal.h"
class VlotageSource : public TwoTerminal
{
private:
public:
	VlotageSource(string id, map<string, string>& VlotageSourceNetlist, map<string, double>& VlotageSourceValues);
	string getType();
	void printComponentInfo();
};