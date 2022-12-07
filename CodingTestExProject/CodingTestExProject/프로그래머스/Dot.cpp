/*
점찍기

https://school.programmers.co.kr/learn/courses/30/lessons/140107#qna

거리 공식으로  풀면 시간초과가  뜬다.
*/
#include <string>
#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0;i<=d; i +=k)
    {
        for(int j = 0;j<=d; j +=k)
        {
            if(d>=sqrt((long)i*i+(long)j*j))
                answer++;
        }
    }
    return answer;
}

#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    for(int i = 0;i<=d; i +=k)
    {
        // a^2 + b^2 = r^2 이며 a,r값을 알고 있으므로 n 으로 풀이가 가능하다.
        long long maxB = sqrt((long long)d*d - (long long)i*i)/k +1 ;    
        answer += maxB;
    }
    return answer;
}