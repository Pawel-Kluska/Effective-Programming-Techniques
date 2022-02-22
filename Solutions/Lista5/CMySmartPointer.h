#pragma once
#include "CRefCounter.h"

template <typename T>
class CMySmartPointer
{
public:
	CMySmartPointer(T* pcPointer);
	CMySmartPointer(const CMySmartPointer& pcOther);
	~CMySmartPointer();
	T& operator*();
	T* operator->();
	T operator=(const T& cOther);
	CMySmartPointer cDuplicate();

private:
	T* pc_pointer;
	CRefCounter* pc_counter;
	void v_Copy(const CMySmartPointer& pcOther);
};


template <typename T>
 CMySmartPointer<T>::CMySmartPointer(T* pcPointer)
{
	pc_pointer = pcPointer;
	pc_counter = new CRefCounter();
	pc_counter->iAdd();
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer& pcOther)
{
	v_Copy(pcOther);
}

template <typename T>
CMySmartPointer<T>::~CMySmartPointer()
{
	if (pc_counter->iDec() == 0)
	{
		std::cout << "Delete smart pointer " << *pc_pointer << std::endl;
		delete pc_pointer;
		delete pc_counter;
		
	}
}

template <typename T>
T& CMySmartPointer<T>::operator*()
{
	return(*pc_pointer); 
}

template <typename T>
T* CMySmartPointer<T>::operator->()
{ 
	return(pc_pointer); 
}

template <typename T>
T CMySmartPointer<T>::operator=(const T& cOther)
{
	if (pc_counter->iDec() == 0)
	{
		delete pc_pointer;
		delete pc_counter;
	}

	v_Copy(cOther);
	return(*this);
}

template <typename T>
void CMySmartPointer<T>::v_Copy(const CMySmartPointer& pcOther)
{
	pc_pointer = pcOther.pc_pointer;
	pc_counter = pcOther.pc_counter;
	pc_counter->iAdd();
}

template<typename T>

CMySmartPointer<T> CMySmartPointer<T>::cDuplicate()
{
	T* Newpointer = new T;
	*Newpointer = *pc_pointer;

	CMySmartPointer<T> newSmartPointer(Newpointer);
	
	return newSmartPointer;
}