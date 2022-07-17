/*
체육복
https://school.programmers.co.kr/learn/courses/30/lessons/42862#qna

체육복을 잃어버린 경우 좌측부터 확인하고 우측을 확인하면 되겠다 해서 아래와같이 이중for문돌렸다. N 이 30밖에 안되어서 통과는 되는데 뭔가 더 효율적인 방법이 있지않을까 생각이 들긴했다.
그리고 예제 테케 말고 몇개 더 틀렸는데 여벌을 가져온 학생이 도난 당한 경우를 따로 생각해두지않아 먼저 처리했다.
이 이후에도 2개가 통과되지않았는데 그 이유는 배열이 정렬되지않아서 였다...분명 예제는 다 정렬된 채로 나와서 그럴 줄 알았는데 아니였다.

중간에 30크기의 2차원 배열로 문제풀이를 할까했었는데 다른 풀이 보니 그럴 필요없이
하나의 배열에서 남은 체육복 + 잃어버린 체육복 - 초기화한 다음에 답을 구하는 풀이가 있었다.
*/
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    answer = n - lost.size();
    sort(lost.begin(), lost.end());
    sort(reserve.begin(), reserve.end());
    for (int i = 0; i < lost.size(); i++)
    {
        //여벌을 가져온 학생이 도난 당한 경우
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                lost[i] = -1;
                break;
            }
        }
    }
    for (int i = 0; i < lost.size(); i++)
    {
        for (int j = 0; j < reserve.size(); j++)
        {
            if (lost[i] - 1 == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                break;
            }
            if (lost[i] + 1 == reserve[j])
            {
                answer++;
                reserve[j] = -1;
                break;
            }
        }
    }
    return answer;
}