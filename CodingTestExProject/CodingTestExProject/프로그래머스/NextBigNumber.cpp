/*
* 다음 큰 숫자
* https://school.programmers.co.kr/learn/courses/30/lessons/12911
* 
자연수 n이 주어졌을 때, n의 다음 큰 숫자는 다음과 같이 정의 합니다.

조건 1. n의 다음 큰 숫자는 n보다 큰 자연수 입니다.
조건 2. n의 다음 큰 숫자와 n은 2진수로 변환했을 때 1의 갯수가 같습니다.
조건 3. n의 다음 큰 숫자는 조건 1, 2를 만족하는 수 중 가장 작은 수 입니다.
예를 들어서 78(1001110)의 다음 큰 숫자는 83(1010011)입니다.

자연수 n이 매개변수로 주어질 때, n의 다음 큰 숫자를 return 하는 solution 함수를 완성해주세요.

조건 2를 확인하기 위해 1의 개수를 구하는 함수를 만든 후 이값과 같은 수가 나올때까지 확인해주면 조건을 만족하는 최소값을 찾을 수 있다.

쉬운문제라 대부분 이렇게 풀지않았을까 생각했는데 의외로 다른 풀이들이 많았다.
bitset STL을 사용하여 이용하는 풀이도 있었다. num = bitset<20>(n).count();
또한 비트마스크를 통해서도 1의 개수를 구할 수 있음을 알게되었다.
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
n & 0x01 << i 이부분이 쉬프트 연산자를 이용하여 해당자리가 1인지 판단하는 방식이다.
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