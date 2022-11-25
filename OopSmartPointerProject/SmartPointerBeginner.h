#pragma once
template <class T>
class SmartPointerBeginner
{
	T* pointer;
public:
	SmartPointerBeginner(T* pointer) : pointer{ pointer } {}
	~SmartPointerBeginner() { delete pointer; }

	T& operator*()
	{
		return pointer;
	}
	T* operator->()
	{
		return *pointer;
	}
};

