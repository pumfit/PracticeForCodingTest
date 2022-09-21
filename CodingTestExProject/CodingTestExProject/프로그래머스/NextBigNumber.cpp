/*
* ���� ū ����
* https://school.programmers.co.kr/learn/courses/30/lessons/12911
* 
�ڿ��� n�� �־����� ��, n�� ���� ū ���ڴ� ������ ���� ���� �մϴ�.

���� 1. n�� ���� ū ���ڴ� n���� ū �ڿ��� �Դϴ�.
���� 2. n�� ���� ū ���ڿ� n�� 2������ ��ȯ���� �� 1�� ������ �����ϴ�.
���� 3. n�� ���� ū ���ڴ� ���� 1, 2�� �����ϴ� �� �� ���� ���� �� �Դϴ�.
���� �� 78(1001110)�� ���� ū ���ڴ� 83(1010011)�Դϴ�.

�ڿ��� n�� �Ű������� �־��� ��, n�� ���� ū ���ڸ� return �ϴ� solution �Լ��� �ϼ����ּ���.

���� 2�� Ȯ���ϱ� ���� 1�� ������ ���ϴ� �Լ��� ���� �� �̰��� ���� ���� ���ö����� Ȯ�����ָ� ������ �����ϴ� �ּҰ��� ã�� �� �ִ�.

������� ��κ� �̷��� Ǯ���ʾ����� �����ߴµ� �ǿܷ� �ٸ� Ǯ�̵��� ���Ҵ�.
bitset STL�� ����Ͽ� �̿��ϴ� Ǯ�̵� �־���. num = bitset<20>(n).count();
���� ��Ʈ����ũ�� ���ؼ��� 1�� ������ ���� �� ������ �˰ԵǾ���.
int getCntNum1(int n)
{
  int nCnt = 0;
  for (int i=0; i<31; i++)
  {
    if (n & 0x01 << i)
      nCnt++;
  }
  return nCnt;
}
n & 0x01 << i �̺κ��� ����Ʈ �����ڸ� �̿��Ͽ� �ش��ڸ��� 1���� �Ǵ��ϴ� ����̴�.
*/
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int CheckNumber(int n)
{
    int k = 0;
    while (n > 0)
    {
        if (n % 2 == 1)
            k++;
        n /= 2;
    }
    return k;
}

int solution(int n) {
    int one = CheckNumber(n);
    while (true)
    {
        if (one == CheckNumber(++n))
            return n;
    }
}