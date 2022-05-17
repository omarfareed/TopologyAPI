#pragma once
template <typename T>
class UnitTest {
private:
	int passedTests;
	int failedTests;
public:
	UnitTest();
	int getNumOfTests();
	bool isEqual(const T& element1, const T& element2) = 0;
	void assertEqual(const T& element1, const T& element2);
	~UnitTest();
};

template<typename T>
inline UnitTest<T>::UnitTest()
{
	this->testNum = 0;
	this->compare = nullptr;
}


template<typename T>
inline int UnitTest<T>::getNumOfTests()
{
	return this->passedTests + this->failedTests;
}
template<typename T>
inline void UnitTest<T>::assertEqual(const T& element1, const T& element2)
{
	if (this->isEqual(element1, element2)) {
		cout << "Test # " << this->getNumOfTests() << "Passed" << endl;
		this->passedTests++;
		return;
	}
	cout << "Test # " << this->getNumOfTests() << "Failed" << endl;
	this->failedTests++;
}

template<typename T>
inline UnitTest<T>::~UnitTest()
{
	cout << "Test ended " << 
		this->passedTests << " PASSED , " <<
		this->failedTests << " Failed." << endl;
}
