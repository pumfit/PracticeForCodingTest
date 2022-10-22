/*
 ǥ��

https://school.programmers.co.kr/learn/courses/30/lessons/12924

�����̵� ������� Ǯ���� ������ ǥ���̴�.
n�� �־����� n�� ������� �� �ִ� ��� �����ϴ� ���� ���ϸ� �ȴ�.

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

//�����̵� ������ 
int solution(int n) {
    int answer = 0;
    int sum = 0;
    for (int left = 1; left <= n; left++)
    {
        sum = 0;
        for (int right = left; right <= n; right++)
        {
            sum += right;
            if (sum == n)
            {
                answer++;
            }
            if (sum >= n)
                break;
        }
    }
    return answer;
}