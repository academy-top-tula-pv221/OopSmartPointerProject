#pragma once
template <class T>
class SmartPointerShare
{
	static int count;
	T* pointer;
public:
	SmartPointerShare(T* pointer = nullptr) : pointer{ pointer } {}
	~SmartPointerShare() 
	{ 
		if (count < 2)
			delete pointer;
		count--;
	}

	SmartPointerShare(const SmartPointerShare& smartPtr)
	{
		pointer = smartPtr.pointer;
		count++;
	}

	SmartPointerShare operator=(const SmartPointerShare& smartPtr)
	{
		if (&smartPtr == this)
			return *this;

		if (this->count < 2)
			delete this->pointer;
		else
			this->count--;

		pointer = smartPtr.pointer;
		count = smartPtr.count + 1;

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

;

