#include "TwoTerminal.h"
class VlotageSource : public TwoTerminal
{
private:
public:
	VlotageSource(string id, map<string, string>& VlotageSourceNetlist, map<string, int>& VlotageSourceValues);
	string getType();
	void printComponentInfo();
};