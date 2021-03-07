#ifndef __ARRAY_H
#define __ARRAY_H

template<class T>
class Array
{
	int physicalSize, logicalSize;
	char delimiter;
	T* arr;
public:
	Array(int size, char delimiter = ' ');
	Array(const Array& other);
	~Array();
	const Array& operator=(const Array& other);
	const Array& operator+=(const T& newVal);
	void enlargeArray();
	friend ostream& operator<<(ostream& os, const Array& arr);
	T& operator[](int index)   const;
	int getLogicalSize()	const;
	int getPhysicalSize()	const;
};

//ctor
template<class T>
Array<T>::Array(int maxSize, char delimiter)
	: physicalSize(maxSize), logicalSize(0), delimiter(delimiter)
{
	arr = new T[maxSize];
}

//copy c'tor
template<class T>
Array<T>::Array(const Array& other) : arr(NULL)
{
	*this = other;
}

//d'tor
template<class T>
Array<T>::~Array()
{
	delete[]arr;
}

//operator =
template<class T>
const Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[]arr;
		physicalSize = other.physicalSize;
		logicalSize = other.logicalSize;
		delimiter = other.delimiter;
		arr = new T[physicalSize];
		for (int i = 0; i < logicalSize; i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

//operator <<
template<class T>
ostream& operator<<(ostream& os, const Array<T>& arr)
{
	for (int i = 0; i < arr.logicalSize; i++)
		os << arr.arr[i] << arr.delimiter;
	return os;
}

//operator +=
template<class T>
const Array<T>& Array<T>::operator+=(const T& newVal)
{
	if (logicalSize < physicalSize)
	{
		arr[logicalSize++] = newVal;
	}
	return *this;
}

template<class T>
void Array<T>::enlargeArray()
{
	physicalSize *= 2;
	T* newArr = new T[physicalSize];
	memcpy(newArr, arr, sizeof(T)* (logicalSize + 1));
	delete[] arr;
	arr = newArr;
}

//returns the logical size
template<class T>
int Array<T>::getLogicalSize()	const
{
	return logicalSize;
}

//returns the physical size
template<class T>
int Array<T>::getPhysicalSize()	 const
{
	return physicalSize;
}

//operator []
template<class T>
T& Array<T>::operator[](int index)  const
{
	return arr[index];
}

#endif // __ARRAY_H