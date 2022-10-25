/*
2개 이하로 다른 비트

https://school.programmers.co.kr/learn/courses/30/lessons/77885

홀수일때 가장 처음 나오는 0을 1로 바꾸고 그 아래 비트의 1을 0으로 바꿔야하는 규칙을 찾아야한다.
*/

//기존 풀이
//테스트 10,11 에서 시간초과 n 값이 10^15이 되며 시간 초과
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for(int i = 0;i<numbers.size();i++)
    {
        long long num = numbers[i]+1;
        while(true)
        {
            long long n = numbers[i] ^ num;
            int count = 0;
            
            while (n > 0) {
            n &= n - 1;
            count++;
            }
            
            if(count==1||count==2)
                break;
            num++;
        }
        answer.push_back(num);
    }
    return answer;
}