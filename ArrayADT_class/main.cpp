#include "ArrayADT_class.h"

int main() {
	Array<int> a;
	int B[] = { 6, 7, 8, 9, 11, 14, 15, 16, 18, 19 };
	int C[] = {4, 1, 6, 3, 8, 13, 21, 20, 5, 7};
	int* ptr = B;

	a.addSimple(ptr, 10, 10);
	a.printArray();
	cout << "\n------MISSING NUMBER-----\n";
	a.MissingNumbers();
	Array<int> b;
	ptr = C;
	b.addSimple(ptr, 10, 10);
	b.FindMissingUsingHashing();

	return 0;
}