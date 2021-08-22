#include "Vector.h"


//copy constructor
Vector::Vector(const Vector& theOther)
{
	elementNum = theOther.elementNum;
	pData = new int[elementNum];

	for (unsigned int i = 0;i < elementNum;i++)
	{
		pData[i] = theOther.pData[i];
	}
}

// clears the array
void Vector::clear()
{
	delete[] pData;
	pData = NULL;
}

// erases (deletes) the array element with the given index;
// valid indices: from 0 to size-1
void Vector::erase(unsigned int position)
{
	if (position>INT_MAX)
	{
		std::cout << "Given element is not present!";
	}

	int* tempPtr;
	tempPtr = new int[elementNum - 1];
	for (unsigned int i = 0;i < elementNum;i++)
	{
		if (i == position)
		{
			continue;
		}

		tempPtr[i] = pData[i];
	}
	elementNum--;
	delete[] pData;
	pData = tempPtr;
}

// returns the array element with the given index, making possible to modify the element;
// valid indices: between 0 and size()-1
int& Vector::at(unsigned int position)
{
	if (position > INT_MAX)
	{
		int element =-1;
		return element;
	}

	int& element = pData[position];
	return element;
}

// returns the array element with the given index, without possibility to modify the element (see const keyword)
// valid indices: between 0 and size()-1
const int& Vector::at(unsigned int position)const
{
	if (position > INT_MAX)
	{
		int element = -1;
		return element;
	}

	const int& element = pData[position];
	return element;
}



// inserts a new element into a place with the given index;
// if the index exceeds the array size, then the size should be increased, and the empty places should be filled with 0 (zero)
bool Vector::insert(unsigned int position, int element)
{
	int* ptrTemp;

	if (position > UINT32_MAX)
	{
		return false;
	}

	if (position >= elementNum)
	{
		ptrTemp = new int[position + 1];
		for (unsigned int i = 0;i < position;i++)
		{
			if (i < elementNum)
			{
				ptrTemp[i] = pData[i];
			}
			else
			{
				ptrTemp[i] = 0;
			}
		}
		ptrTemp[position] = element;
		elementNum = position+1;
	}
	else
	{
		ptrTemp = new int[elementNum + 1];
		for (unsigned int i = 0, j = 0;i < elementNum;i++, j++)
		{
			if (i == position)
			{
				ptrTemp[j] = element;
				ptrTemp[j + 1] = pData[i];
				j++;
				continue;
			}
			ptrTemp[j] = pData[i];
		}
		elementNum++;
	}

	delete[] pData;
	pData = ptrTemp;
	return true;
}


// Operator=
const Vector& Vector::operator= (const Vector& theOther)
{
	elementNum = theOther.elementNum;
	pData = new int[elementNum];

	for (unsigned int i = 0;i < elementNum;i++)
	{
		pData[i] = theOther.pData[i];
	}
	return *this;
}

// operator[]
int& Vector::operator [](unsigned int position)
{
	int& element = pData[position];
	return element;
}

// operator[] with const keyword
const int& Vector::operator [](unsigned int position)const
{
	const int& element = pData[position];
	return element;
}


// global function for printing vector data
std::ostream& operator << (std::ostream& os, const Vector& v)
{
	os << "[";

	for (unsigned int i = 0;i < v.elementNum;i++)
	{
		os << v.pData[i] << " ";
	}

	os << "]";
	return os;
}

//sorting the array in ascending order
void Vector::sort()const
{
	for (unsigned int i = 0;i < elementNum;i++)
	{
		for (int j = i + 1;j < elementNum;j++)
		{
			if (pData[i] > pData[j])
			{
				int temp = pData[i];
				pData[i] = pData[j];
				pData[j] = temp;
			}
		}
	}
}
