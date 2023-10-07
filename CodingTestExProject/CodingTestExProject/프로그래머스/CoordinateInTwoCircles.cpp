/*
두 원 사이의 정수 쌍

https://school.programmers.co.kr/learn/courses/30/lessons/181187

어떻게 시간 내에 풀 수 있을까?
각 점을 확인하는 방식이 아닌 해당되는 좌표 x값 내 조건에 만족하는 y 좌표를 구해 가면 시간 초과를 해결할 수 있다.
*/
#include <cmath>
#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    // 시간 내 풀려면 n^2 로는 풀 수 없음
    for(long long x = 1 ;x<=r2;x++)
    {
        long long maxY = floor(sqrt(pow(r2,2) - pow(x,2)));
        long long minY = x >= r1 ? 0 : ceil(sqrt(pow(r1,2) - pow(x,2)));
        
        answer += (maxY - minY + 1); 
    }
    return answer * 4;
}

// 시간 초과
#include <string>
#include <vector>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    
    for(int x = 0 ;x<=r2;x++)
    {
        for(int y = 0 ;y<=r2;y++)
        {
            if(x*x+y*y<=r2*r2 && r1*r1<=x*x+y*y)
                answer++;
        }    
    }
    return (answer - r2 + r1 - 1 )*4;
}