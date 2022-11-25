#pragma once
#include <iostream>
using namespace std;

template <class T>
class SmartPointerUnique
{
	T* pointer;
public:
	SmartPointerUnique(T* pointer = nullptr) : pointer{ pointer } 
	{
		cout << "constructor origin\n";
	}
	~SmartPointerUnique() { delete pointer; }

	SmartPointerUnique(SmartPointerUnique& smartPtr) = delete;
	/*{
		pointer = smartPtr.pointer;
		smartPtr.pointer = nullptr;
		cout << "constructor copy\n";
	}*/

	SmartPointerUnique operator=(SmartPointerUnique& smartPtr) = delete;
	/*{
		if (&smartPtr == this)
			return *this;

		if (pointer)
			delete pointer;

		pointer = smartPtr.pointer;
		smartPtr.pointer = nullptr;

		cout << "assign copy\n";

		return *this;
	}*/

	SmartPointerUnique(SmartPointerUnique&& smartPtr) noexcept
	{
		pointer = smartPtr.pointer;
		smartPtr.pointer = nullptr;

		cout << "constructor move\n";
	}

	SmartPointerUnique& operator=(SmartPointerUnique&& smartPtr)
	{
		pointer = smartPtr.pointer;
		smartPtr.pointer = nullptr;

		cout << "assign move\n";

		return *this;
	}

	T& operator*()
	{
		return pointer;
	}
	T* operator->()
	{
		return *pointer;
	}
};

