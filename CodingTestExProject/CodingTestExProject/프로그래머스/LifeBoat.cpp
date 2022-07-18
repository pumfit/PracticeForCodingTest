/*
구명보트
https://school.programmers.co.kr/learn/courses/30/lessons/42885

처음에 정렬하고 작은 수부터 순서대로 넣었는데 당연히 틀렸다.
이 예외 케이스를 10 90 20 80 30 70 40 60 50 50으로 찾을 수 있는데 작은 수부터 하면 6개가 필요한데 딱맞게 채우면 5개가된다.
따라서 최대한 limit값에 맞추는게 이문제의 핵심이다.

나는 큰 수 하나를 선택하고 남은 자리에 작은 수를 채우는 방식으로 진행했다.
이중 for문에서 i는 큰수로 시작하고 
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    sort(people.begin(), people.end());
    int N = 0; int idx = 0;
    // 큰 수를 하나 선택
    for (int i = people.size() - 1; i >= 0; i--)
    {
        N = people[i];
        //작은 수를 넣을 수 있을때까지 넣음
        for (int j = idx; j < people.size(); j++)
        {
            if (N + people[j] <= limit)
            {
                N += people[j];
                continue;
            }
            else//limit 넘어가면 배 하나 추가
            {
                idx = j;
                answer++;
                break;
            }
        }
        if (idx >= i)//작은 수와 큰 수가 크로스되면 종료
            break;
    }

    return answer;
}