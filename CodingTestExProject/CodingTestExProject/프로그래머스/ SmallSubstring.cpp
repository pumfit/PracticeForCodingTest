/*
https://school.programmers.co.kr/learn/courses/30/lessons/147355/solution_groups?language=cpp&type=all

long long 과 stoll 로 가능함 stol만 사용했다가 오버플로 나서 다른 방식으로 풀이 했었는데 이번 기회에 stoll 이 있다는 걸 알았다.
*/
#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    int answer = 0;
    int pSize = p.size();
    long long num = stol(p);
    for(int i = 0; i<t.size()-pSize+1;i++)
    {
        for(int j = 0;j<pSize;j++)
        {
            if(t[i+j]<p[j])
            {
                answer++;
                break;
            }else if(t[i+j]==p[j]){
                if(j==pSize-1)
                    answer++;
            }else{
                break;
            }
        }

    }
    return answer;
}