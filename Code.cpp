#include <iostream>
#include <string>
#define SQUARE(X) X*X
const double* f1(const double ar[], int n);

const double* f2(const double[], int);

const double* f3(const double*, int);
const int ArSize = 8;
int sum_arr(const int* begin, const int* end);
inline double square(double x) { return x * x; }
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};
int main(void) {
	int cookies[ArSize] = { 1,2,4,8,16,32,64,128 };
	int sum = sum_arr(cookies, cookies + ArSize);
	std::cout << "Total cookies eaten: " << sum << std::endl;
	sum = sum_arr(cookies, cookies + 3);			//firest 3 elements
	std::cout << "First three eaters ate " << sum << " cookies.\n";
	sum = sum_arr(cookies + 4, cookies + 8);		//last 4 elements
	std::cout << "Last four eaters ate " << sum << " cookies.\n";
	printf("-------------------------------------------\n");
	double av[3] = { 1112.3,1542.6,2227.9 };
	const double* (*p1)(const double*, int) = f1;
	auto p2 = f2;
	printf("Using pointers to functions:\n");
	printf(" Address Value\n");
	std::cout << (*p1)(av, 3) << ": " << *(*p1)(av, 3) << std::endl;
	std::cout << p2(av, 3) << ": " << *p2(av, 3) << std::endl;
	const double* (*pa[3])(const double*, int) = { f1,f2,f3 };
	auto pb = pa;
	printf("\nUsing an array of pointers to functions:\n");
	printf(" Address Value\n");
	for (int i = 0; i < 3; i++)
	{
		std::cout << pa[i](av, 3) << ": " << *pa[i](av, 3) << std::endl;
	}
	std::cout << "\nUsing a pointer to a pointer to a function:\n";
	std::cout << " Address Value\n";
	for (int i = 0; i < 3; i++)
	{
		std::cout << pb[i](av, 3) << ": " << *pb[i](av, 3) << std::endl;
	}
	std::cout << "\nUsing pointers to an array of pointers:\n";
	std::cout << " Adress Value\n";
	auto pc = &pa;
	std::cout << (*pc)[0](av, 3) << ": " << *(*pc)[0](av, 3) << std::endl;
	const double* (*(*pd)[3])(const double*, int) = &pa;
	const double* pdb = (*pd)[1](av, 3);
	std::cout << pdb << ": " << *pdb << std::endl;
	std::cout << (*(*pd)[2])(av, 3) << ": " << *(*(*pd)[2])(av, 3) << std::endl;
	printf("-------------------------------------------\n");
	double a, b;
	double c = 13.0;
	a = square(5.0);
	b = square(4.5 + 7.5);
	printf("a = %f", a);
	printf(", b = %f", b);
	printf(", c squared = %f\n", square(c++));
	printf("Now c = %f\n", c);
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