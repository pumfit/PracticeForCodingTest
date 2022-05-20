/*
단체 사진 찍기
https://programmers.co.kr/learn/courses/30/lessons/1835

전체 순열을 구한 뒤 해당 조건에 맞는 지 검사해 answer수룰 체크하면 되는 문제이다.

순열은 next_permutaition함수를 사용하였다.
거리의 차이는 절댓값을 구한 후 진행하였는데 두 사람의 거리가 0인 경우 가 인덱스 상으로는 1차이가 나서 추가적으로 -1을 해주어야 한다.

*/
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, vector<string> data) {
    string s = "ACFJMNRT";
    sort(s.begin(), s.end());
    int answer = 0;
    do {
        int OIdx = 0; int TIdx = 0;
        //data 개수만큼
        for (int i = 0; i < n; i++)
        {
            //인덱스 찾기
            for (int j = 0; j < s.size(); j++)
            {
                if (s[j] == data[i][0])
                    OIdx = j;
                else if (s[j] == data[i][2])
                    TIdx = j;
            }
            int num = data[i][4] - '0';
            if (data[i][3] == '=')
            {
                if (abs(OIdx - TIdx) - 1 != num)
                    break;
            }
            else if (data[i][3] == '>')
            {
                if (abs(OIdx - TIdx) - 1 <= num)
                    break;
            }
            else {
                if (abs(OIdx - TIdx) - 1 >= num)
                    break;
            }
            if (i == n - 1)
                answer++;

        }
    } while (next_permutation(s.begin(), s.end()));
    return answer;
}