#include "UnitTest.h"

UnitTest::UnitTest()
{
	this->failedTests = 0;
	this->passedTests = 0;
}

int UnitTest::getNumOfTests()
{
	return this->failedTests + this->passedTests;
}

UnitTest::~UnitTest()
{
	std::cout << "# Passed Test Cases : " << this->passedTests << ", Failed : " << this->failedTests << std::endl;
}
