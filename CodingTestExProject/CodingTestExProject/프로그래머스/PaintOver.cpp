/*
덧칠하기
https://school.programmers.co.kr/learn/courses/30/lessons/161989

첫 덧칠 할 부분 부터 범위 만큼 확인하고 다음 덧칠이 필요한 부분까지 간 뒤 범위만큼 칠하면 되겠다 생각해서 아래와 같은 풀이를 진행했다.
다른 풀이를 보니 생각보다 풀이가 단순했는데 전체 탐색하면서 덧칠이 필요한 부분이 나오면 answer 카운트를 올리고 범위 내를 칠해버린다. 
*/
#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int arr[100002] = {0,};
    for(int i = 0;i<section.size();i++)
        arr[section[i]] = 1;
    
    int endIdx = 0;
    int cnt = 0;
    int i = 1;
    while(i<=n)
    {
        if(cnt==section.size())
            break;
        // 첫 덧칠할 부분이 나올때까지
        while(arr[i]!=1)
            i++;
        // 범위만큼 진행
        for(int j = i;j<i+m;j++)
        {
            if(j>n)
                break;

            if(arr[j]==1)
            {
                cnt++;
                endIdx = j+1;
            }            
        }
        // 탐색 범위 재 지정
        if(endIdx!=i)
        {
            i = endIdx;
            answer++;            
        }else
        {
            i += m;
        }
    }
    return answer;
}
// 다른 풀이
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
    int arr[100002] = {0,};
    for(int i = 0;i<section.size();i++)
        arr[section[i]] = 1;
    int idx = 1;
    while(idx<=n)
    {
        if(arr[idx])
        {
            answer++;
            for(int i = idx;i<idx+m;i++)
            {
                if(i>n)
                    break;
                arr[i]=0;
            }
        }
        idx++;
    }
    return answer;
}