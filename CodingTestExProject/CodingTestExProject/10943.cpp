/*
10943 ��������
*/
#include<iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	printf("%d", rand() % 10);
}