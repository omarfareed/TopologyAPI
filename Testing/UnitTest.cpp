#include "UnitTest.h"

void UnitTest::testPassed()
{
	SetConsoleTextAttribute(hConsole, GREEN);
	this->passedTests++;
	cout << "Test case # " << this->getNumOfTests() << " Passed" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

void UnitTest::testFailed()
{
	SetConsoleTextAttribute(hConsole, RED);
	this->failedTests++;
	cout << "Test case # " << this->getNumOfTests() << " Failed" << endl;
	SetConsoleTextAttribute(hConsole, WHITE);
}

UnitTest::UnitTest()
{
	this->failedTests = 0;
	this->hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
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
