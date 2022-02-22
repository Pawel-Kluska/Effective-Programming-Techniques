#include <iostream>
#include "CMySmartPointer.h"
#include "CTable.h"
#include "CNumber.h"

using namespace std;

int main()
{
	
	double* test = new double(5);

	CMySmartPointer<double> smart(test);
	CMySmartPointer<double> smart2 = smart.cDuplicate();

	cout << *smart;
	cout << *smart2;
	
	return 0;
}