#include "CNumber.h"
#include <iostream>

using namespace std;

CNumber::CNumber() 
{
	pd_value = new double(0);
}

CNumber::CNumber(double* pd_val)
{
	pd_value = pd_val;
}

CNumber::CNumber(const CNumber& pcOther)
{
	v_copy(pcOther);
	cout << "Konstruktor kopiujacy dla " << *pd_value<<endl;
}

CNumber::CNumber(CNumber&& pcOther) noexcept
{
	v_move(pcOther);
	cout << "Konstruktor przenoszacy dla " << *pd_value << endl;
}

CNumber::~CNumber()
{
	delete pd_value;
	cout << "Destruktor"<<endl;
}

void CNumber::ToString()
{
	cout << "Wartosc doubla = " << *pd_value << endl;
}

void CNumber::operator=(CNumber&& pcOther) noexcept
{
	if (pd_value != NULL) delete pd_value;
	v_move(pcOther);
	cout << "Przenoszenie operator = " << *pd_value << endl;
}

void CNumber::operator=(const CNumber& pcOther)
{
	if (pd_value != NULL) delete pd_value;
	v_copy(pcOther);
	cout << "Kopiowanie operator = " << *pd_value << endl;
}

CNumber CNumber::operator+(CNumber& pcOther)
{
	CNumber new_pd_val = *this;
	*(new_pd_val.pd_value) = *pd_value + *(pcOther.pd_value);
	
	return move(new_pd_val);
}

CNumber CNumber::operator-(CNumber& pcOther)
{
	CNumber new_pd_val = *this;
	*(new_pd_val.pd_value) = *(new_pd_val.pd_value) - *(pcOther.pd_value);

	return move(new_pd_val);
}

void CNumber::v_move(CNumber& pcOther)
{
	pd_value = pcOther.pd_value;
	pcOther.pd_value = NULL;
}
void CNumber::v_copy(const CNumber& pcOther)
{
	pd_value = new double;
	*pd_value = *(pcOther.pd_value);
}