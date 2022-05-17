#pragma once
#include <iostream>
#include <Windows.h>
using std::cout;
using std::endl;
class UnitTest {
private:
	int passedTests;
	int failedTests;
public:
	UnitTest();
	int getNumOfTests();
	template<typename T>
	void assertEqual(const T& element1, const T& element2);
	~UnitTest();
};

template<typename T>
inline void UnitTest::assertEqual(const T& element1, const T& element2)
{

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	if (element1 == element2) {
		SetConsoleTextAttribute(hConsole, 2);
		this->passedTests++;
		cout << "Test case # " << this->getNumOfTests() << " Passed" << endl;
		SetConsoleTextAttribute(hConsole, 15);
		return;
	}
	SetConsoleTextAttribute(hConsole, 12);
	this->failedTests++;
	cout << "Test case # " << this->getNumOfTests() << " Failed" <<  " assert " << element1 << " == " << element2 << endl;
	SetConsoleTextAttribute(hConsole , 15);
}

