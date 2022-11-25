#pragma once
template <class T>
class SmartPointerCopy
{
	T* pointer;
public:
	SmartPointerCopy(T* pointer = nullptr) : pointer{ pointer } {}
	~SmartPointerCopy() { delete pointer; }

	SmartPointerCopy(const SmartPointerCopy& smartPtr)
	{
		pointer = new T;
		*pointer = *smartPtr.pointer;
	}

	SmartPointerCopy operator=(const SmartPointerCopy& smartPtr)
	{
		if (&smartPtr == this)
			return *this;

		if (pointer)
			delete pointer;

		pointer = new T;
		*pointer = *smartPtr.pointer;

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

