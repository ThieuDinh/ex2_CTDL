#include "thuVien_Ex2_CTDL.h"

int main()
{
	CL m,a,b;
	init(m);
	init(a);
	init(b);
	inputCL(m);
	cout << "\nList m: ";
	outputCL(m);
	insert(m, 2, 15);
	cout << "\nList m: ";
	outputCL(m);
	return 0;
}