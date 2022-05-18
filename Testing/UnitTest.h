#pragma once
#include <iostream>
#include <string>
#include <Windows.h>
using std::cout;
using std::endl;
using std::string;
enum COLORS {
	GREEN=2,
	RED=12,
	WHITE=15
};
class UnitTest {
private:
	int passedTests;
	int failedTests;
	void testPassed();
	void testFailed();
	HANDLE hConsole;
public:
	UnitTest();
	int getNumOfTests();
	template<typename T>
	void assertEqual(const T& element1, const T& element2);
	template <typename T>
	void assertNotEqual(const T& element1, const T& element2);
	~UnitTest();
};

template<typename T>
inline void UnitTest::assertEqual(const T& element1, const T& element2)
{
	if (element1 == element2) {
		this->testPassed();
		return;
	}
	this->testFailed();
}

template<typename T>
inline void UnitTest::assertNotEqual(const T& element1, const T& element2)
{
	if (element1 == element2)
	{
		this->testFailed();
		return;
	}
	this->testPassed();
}

