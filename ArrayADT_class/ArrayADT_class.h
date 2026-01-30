#pragma once
#include <iostream>
#include <stdexcept>
using std::cout;
using std::cin;
using std::cerr;

template<class T>
class Array {
private:
	T* A;
	int size;
	int lenght;
	
	void swap(T &A, T &B);
public:
	Array()
	{
		A = nullptr;
		size = 0;
		lenght = 0;
	}

	void Add();
	bool checkError();
	void createArray();
	void addSimple(T* B, int sizeB, int lenghtB);
	void printArray();
	void insertNumber(T);
	void insertInto(T, int);
	void deleteLocation(int);
	void deleteNumber(T);
	void sorted(bool reverse);
	void MissingNumbers();
	T maxOfADT();
	void FindMissingUsingHashing();
};

//These method under here is Private
template<class T>
void Array<T>::swap(T& A, T& B)
{
	T temp = B;
	B = A;
	A = temp;
}

//These method under here is Public
template<class T>
void Array<T>::Add()
{
	int i;
	int write;
	for (i = 0; i < lenght; ++i)
	{
		cout << "Nhap so thu: " << i + 1 << ": "; cin >> write;
		A[i] = write;
	}
}

template<class T>
bool Array<T>::checkError()
{
	if (size <= 0 || lenght <= 0)
	{
		cout << "Loi nhap do dai so";
		return true;
	}

	if (lenght > size) return true;

	return false;
}

template<class T>
void Array<T>::createArray()
{
	cout << "Nhap size cho ADT: "; cin >> size;
	cout << "Nhap lenght cho ADT: "; cin >> lenght;
	A = new T[size];
	Add();
}

template<class T>
void Array<T>::addSimple(T* B, int sizeB, int lenghtB)
{
	int i;
	this->size = sizeB;
	this->lenght = lenghtB;
	A = new T[size];
	for (i = 0; i < lenghtB; ++i)
	{
		A[i] = B[i];
	}
}

template<class T>
void Array<T>::printArray()
{
	int i;
	if (checkError()) return;
	for (i = 0; i < lenght; ++i)
	{
		cout << "So thu " << i + 1 << ": " << A[i] << "\n";
	}
}

template<class T>
void Array<T>::insertNumber(T X)
{
	int i;
	if (checkError()) return;
	else
		A[lenght++] = X;
}

template<class T>
void Array<T>::insertInto(T X, int location)
{
	int i;
	if (checkError()) return;

	for (i = lenght - 1; i >= location; --i)
		A[i + 1] = A[i];
	A[location] = X;
	lenght++;
}

template<class T>
void Array<T>::deleteLocation(int location)
{
	int i;
	if (checkError()) return;

	for (i = location; i < lenght; ++i)
		A[i] = A[i + 1];
	lenght--;
}

template<class T>
void Array<T>::deleteNumber(T number)
{
	int i;
	if (checkError()) return;
	else

		for (i = 0; i < lenght; ++i)

			if (A[i] == number)

				deleteLocation(i--);

}

template<class T>
void Array<T>::sorted(bool reverse)
{
	int i, j;
	if (checkError()) return;
	else
	{
		if (!reverse)

			for (i = 0; i < lenght; ++i)
				for (j = i + 1; j < lenght; ++j)
				{
					if (A[i] > A[j])
						swap(A[i], A[j]);
				}

		else

			for (i = 0; i < lenght; ++i)
				for (j = i + 1; j < lenght; ++j)
					if (A[i] < A[j])
						swap(A[i], A[j]);
	}
}

template<class T>
void Array<T>::MissingNumbers()
{
	T diff = A[0];
	int i;
	for (i = 0; i < lenght; ++i)
	{
		if (i + diff != A[i])
		{
			while (i + diff < A[i])
			{
				cout << i + diff << " ";
				diff++;
			}
		}
	}
	cout << "\n";
}

template <class T>
inline T Array<T>::maxOfADT()
{
	try{
		int i;
	T max = 0.0;
	for (i = 0; i < lenght; ++i)
	{
		if (A[i] > max)
			max = A[i];
	}
	return max;
	}catch (const __EXCEPTION__ e){
		cerr << "Error: " << e <<"\n";
		return 0;
	}
}

template <class T>
void Array<T>::FindMissingUsingHashing()
{
	T max = maxOfADT();
	int i;
	T* arraySub = new T[max];
	for (i = 0; i < lenght; ++i)
		arraySub[A[i]]++;
	
	for (i = 0; i < max; ++i)
	{
		if (arraySub[i] == 0)
			cout <<i <<" ";
	}
	cout <<"\n";
}
