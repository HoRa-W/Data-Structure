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
	int length;

	void swap(T& A, T& B);
public:
	Array()
	{
		A = nullptr;
		size = 0;
		length = 0;
	}

	void Add();
	bool checkError();
	void createArray();
	void addSimple(T* B, int sizeB, int lengthB);
	void printArray();
	void insertNumber(T);
	void insertInto(T, int);
	void deleteLocation(int);
	void deleteNumber(T);
	void sorted(bool reverse);
	void MissingNumbers();
	T maxOfADT();
	void FindMissingUsingHashing();
	void FindDuplicate();
	void FindTimeDuplicate();
	void FindDuplicateUsingHashing();
	void FindDuplicate_NoSorted();
	void FindPairUsingHashing(T k);
	void FindPairUsignIandJ(T k);
	void FindMaxAndMinInSingle();
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
	for (i = 0; i < length; ++i)
	{
		cout << "Nhap so thu: " << i + 1 << ": "; cin >> write;
		A[i] = write;
	}
}

template<class T>
bool Array<T>::checkError()
{
	if (size <= 0 || length <= 0)
	{
		cout << "Loi nhap do dai so";
		return true;
	}

	if (length > size) return true;

	return false;
}

template<class T>
void Array<T>::createArray()
{
	cout << "Nhap size cho ADT: "; cin >> size;
	cout << "Nhap length cho ADT: "; cin >> length;
	A = new T[size];
	Add();
}

template<class T>
void Array<T>::addSimple(T* B, int sizeB, int lengthB)
{
	int i;
	this->size = sizeB;
	this->length = lengthB;
	A = new T[size];
	for (i = 0; i < lengthB; ++i)
	{
		A[i] = B[i];
	}
}

template<class T>
void Array<T>::printArray()
{
	int i;
	if (checkError()) return;
	for (i = 0; i < length; ++i)
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
		A[length++] = X;
}

template<class T>
void Array<T>::insertInto(T X, int location)
{
	int i;
	if (checkError()) return;

	for (i = length - 1; i >= location; --i)
		A[i + 1] = A[i];
	A[location] = X;
	length++;
}

template<class T>
void Array<T>::deleteLocation(int location)
{
	int i;
	if (checkError()) return;

	for (i = location; i < length; ++i)
		A[i] = A[i + 1];
	length--;
}

template<class T>
void Array<T>::deleteNumber(T number)
{
	int i;
	if (checkError()) return;
	else

		for (i = 0; i < length; ++i)

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

			for (i = 0; i < length; ++i)
				for (j = i + 1; j < length; ++j)
				{
					if (A[i] > A[j])
						swap(A[i], A[j]);
				}

		else

			for (i = 0; i < length; ++i)
				for (j = i + 1; j < length; ++j)
					if (A[i] < A[j])
						swap(A[i], A[j]);
	}
}

template<class T>
void Array<T>::MissingNumbers()
{
	T diff = A[0];
	int i;
	for (i = 0; i < length; ++i)
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
T Array<T>::maxOfADT()
{
	try {
		int i;
		T max = 0.0;
		for (i = 0; i < length; ++i)
		{
			if (A[i] > max)
				max = A[i];
		}
		return max;
	}
	catch (const std::exception &e) {
		cerr << "Error: " << e.what() << "\n";
		return 0;
	}
}

template <class T>
void Array<T>::FindMissingUsingHashing()
{
	T max = maxOfADT();
	int i;
	T* arraySub = new T[max];
	for (i = 0; i < length; ++i)
		arraySub[A[i]]++;

	for (i = 0; i < max; ++i)
	{
		if (arraySub[i] == 0)
			cout << i << " ";
	}
	cout << "\n";
}

template <class T>
void Array<T>::FindDuplicate()
{
	//Thuat toan nay can phai sap xep truoc tien
	//Do phuc tap thuat toan ghi cac so bi lap nay la O(n)
	//Khi nao gap so lap lastDup se ghi lai so day
	//Neu gap lai lan 3 thi tranh tinh trang do se co dong lenh continue
	//i cu tiep tuc duoc cong len
	T lastDuplicate = 0;
	int i;
	for (i = 0; i < length; ++i)
	{
		if (lastDuplicate == A[i])
			continue;
		if (A[i] == A[i + 1])
			cout << A[i] << " ";
		lastDuplicate = A[i];
	}
	cout << "\n";
}

template <class T>
void Array<T>::FindTimeDuplicate()
{
	//Day la thuat toan dem so lan lap cua 1 day Array co sort tang dan
	//Giai thich: Thuat toan su dung 2 bien i va j trong do j xuat hien khi 
	//i va so tiep theo lap lai, tu do j duoc cong len dan dan
	//Khi nao A[j] khac so phia truoc thi i se nhay len j - 1 buoc
	// => Do phuc tap thuat toan la O(n)
	int i, j;
	for (i = 0; i < length - 1; ++i)
	{
		if (A[i] == A[i + 1])
		{
			j = i + 1;
			while (A[i] == A[j]) j++;

			cout << "Number " << A[i] << " duplicate " << j - i << " times\n";
			i = j - 1;
		}
	}
}

template <class T>
void Array<T>::FindDuplicateUsingHashing()
{
	cout << "\n";
	T max = maxOfADT(); //Tim con so lon nhat
	int i;
	max++;
	T* arraySub = new T[max] {0}; //Khoi tao ham

	for (i = 0; i < length; ++i)
		arraySub[A[i]]++; //Hashing

	for (i = 0; i < max; ++i)
	{
		if (arraySub[i] > 1)
			cout << i << " Loop: " << arraySub[i] << "\n";
	}
	cout << "\n";
}

template <class T>
void Array<T>::FindDuplicate_NoSorted()
{
	int i, j;
	for (i = 0; i < length - 1; ++i)
	{
		int count = 1;
		if (A[i] != -1)
		{
			for (j = i + 1; j < length; ++j)
				if (A[i] == A[j])
				{
					count++;
					A[j] = -1;
				}
			if (count > 1)
				cout << "So " << A[i] << " lap lai " << count << " lan\n";
		}
	}
}

template <class T>
void Array<T>::FindPairUsingHashing(T k)
{
	T max = maxOfADT();
	max++;
	int i;
	T* arraySub = new T[(k > max) ? (k + 1) : max]{ 0 };

	//{ 4, 1, 21, 3, 12, 13, 21, 20, 3, 3 };
	for (i = 0; i < length; ++i)
	{
		if (arraySub[k - A[i]] != 0 && A[i] > 0)
			cout << A[i] << " + " << k - A[i] << " = "<<k<<"\n";
		
		arraySub[A[i]]++;
	}
}

template<class T>
void Array<T>::FindPairUsignIandJ(T k)
{
	//Y tuong bay nay la danh cho bai toan duoc sap xep san
	//Dat i vao bien dau tien va j la bien cuoi cung
	//Neu A[i] + A[j] vi du 1 + 14 ma > 10 thi j buoc phai giam
	//Neu A[i] + A[j] vi du 1 + 8 ma < 10 thi i buoc phai tang
	//Neu A[i] + A[j] vi du 1 + 9 ma = 10 thi in ra ket qua va i tien them 1 buoc va j giam 1 buoc
	int i, j;

	for (i = 0, j = length - 1; i <= j;)
	{
		if (A[i] + A[j] > k)
		{
			j--;
		}
		else if (A[i] + A[j] < k)
		{
			i++;
		}
		else
		{
			cout << A[i] << " + " << A[j] << " = " << k << "\n";
			i++; j--;
		}
	}
}

template<class T>
void Array<T>::FindMaxAndMinInSingle()
{
	int min = A[0];
	int max = A[0];

	int i;
	for (i = 1; i < length; ++i)
	{
		if (A[i] < min) min = A[i];
		else if (A[i] > max) max = A[i];
	}
	cout << "Min: " << min << "\nMax: " << max << "\n";

}
