#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
const int ArSize = 8;
#define SQUARE(X) X*X
const double* f1(const double ar[], int n);

const double* f2(const double[], int);

const double* f3(const double*, int);
int sum_arr(const int* begin, const int* end);
inline double square(double x) { return x * x; }
unsigned long left(unsigned long num, unsigned ct);
char* left(const char* str, int n = 1);
template <typename T>
void Swap(T& a, T& b);
template <>void Swap<job>(job& j1, job& j2);
void Show(job& j);
struct free_throws
{
	std::string name;
	int made;
	int attempts;
	float percent;
};
struct job {
	char name[40];
	double salary;
	int floor;
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
	const char* trip = "Hawaii!!";
	unsigned long n = 12345678;
	int i;
	char* temp;
	for (i = 0; i < 10; i++)
	{
		std::cout << left(n, i) << std::endl;
		temp = left(trip, i);
		std::cout << temp << std::endl;
		delete[] temp;
	}
	printf("-------------------------------------------\n");
	std::cout.precision(2);
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	int i = 10, j = 20;
	std::cout << "i, j=" << i << ", " << j << ".\n";
	std::cout << "Using compiler-generated int swapper:\n";
	job sue = { "Susan Yaffee",7300.60,7 };
	job sidney = { "Sidney Taffee",78060.72,9 };
	std::cout << "Before job swapping:\n";
	Show(sue);
	Show(sidney);
	Swap(sue, sidney);
	std::cout << "After job swapping:\n";
	Show(sue);
	Show(sidney);
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
unsigned long left(unsigned long num, unsigned ct) {
	unsigned digits = 1;
	unsigned long n = num;
	if (ct == 0 || num == 0)
	{
		return 0;
	}
	while (n /= 10)
	{
		digits++;
	}
	if (digits > ct)
	{
		ct = digits - ct;
		while (ct--)
		{
			num /= 10;
		}
		return num;
	}
	else
	{
		return num;
	}
}
char* left(const char* str, int n) {
	if (n < 0)
	{
		n = 0;
	}
	char* p = new char[n + 1];
	int i;
	for (i = 0; i < n && str[i]; i++)
	{
		p[i] = str[i];
	}
	while (i <= n)
	{
		p[i++] = '\0';
	}
	return p;
}
template <typename T>
void Swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}
template <>void Swap<job>(job& j1, job& j2) {
	double t1;
	int t2;
	t1 = j1.salary;
	j1.salary = j2.salary;
	j2.salary = t1;
	t2 = j1.floor;
	j1.floor = j2.floor;
	j2.floor = t2;
}
void Show(job& j) {
	std::cout << j.name << ": " << j.salary << " on floor " << j.floor << std::endl;
}