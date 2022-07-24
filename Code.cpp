#include <iostream>
#include <cstdio>
#include <cmath>
#include <string>
#include <cstring>
void Test(int n) {
	for (int i = 0; i < n; i++)
	{
		printf("This is a  test.\n");
	}
}
int main(void) {
	/*
	printf("HelloWorld.\n");
	printf("--------------------------------\n");
	printf("HelloWorld.\n");
	printf("--------------------------------\n");
	printf("HelloWorld.\n");
	printf("--------------------------------\n");
	*/
	//Test1:
	printf("This is a test.\n");
	printf("Test 1:\n");
	int n;
	std::cin >> n;
	Test(n);
	printf("--------------------------------\n");
	printf("Done!\n");
	return 0;
}