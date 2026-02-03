#include "ArrayADT_class.h"

int main() {
	Array<int> a;
	int B[] = { 6, 7, 8, 9, 11, 14, 15, 16, 18, 19 };
	int C[] = { 4, 1, 6, 3, 8, 13, 21, 20, 5, 7 };
	int D[] = { 3, 6, 8 ,8, 10, 12, 15, 15, 15, 20 };
	int E[] = { 4, 1, 21, 3, 12, 13, 21, 20, 3, 3 };
	int* ptr = B;

	a.addSimple(ptr, 10, 10);
	a.printArray();
	cout << "\n------MISSING NUMBER-----\n";
	a.MissingNumbers();
	Array<int> b;
	ptr = C;
	b.addSimple(ptr, 10, 10);
	b.FindMissingUsingHashing();
	cout << "\n------DUPLICATE NUMBER------\n";
	Array<int> c;
	ptr = D;
	c.addSimple(D, 10, 10);
	c.FindDuplicate();
	c.FindTimeDuplicate();
	Array<int> d;
	ptr = E;
	d.addSimple(E, 10, 10);
	d.FindDuplicateUsingHashing();
	d.FindDuplicate_NoSorted();
	d.FindPairUsingHashing(25);
	cout << "\n";
	a.FindPairUsignIandJ(24);
	b.FindMaxAndMinInSingle();
	return 0;
}