#include <iostream>
const double* f1(const double ar[], int n);

const double* f2(const double[], int);

const double* f3(const double*, int);
const int ArSize = 8;
int sum_arr(const int* begin, const int* end);
int main(void) {
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = sum_arr(cookies, cookies + 3);			//firest 3 elements
	std::cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);		//last 4 elements
	std::cout << "Last four eaters ate " << sum << " cookies.\n";
	printf("-------------------------------------------\n");

	return 0;
}
int sum_arr(const int* begin, const int* end)
{
	const int* pt;
	int total = 0;
	for (pt = begin; pt != end;pt++)
	{
		total = total + *pt;
	}
	return total;
}
const double* f1(const double* ar, int n)
{
	return ar;
}

const double* f2(const double ar[], int n) {
	return ar + 1;
}

const double* f3(const double ar[], int n) {
	return ar + 2;
}