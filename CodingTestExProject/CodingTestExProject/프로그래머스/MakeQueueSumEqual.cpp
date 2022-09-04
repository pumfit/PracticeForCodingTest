/*
두 큐 합 같게 만들기

https://school.programmers.co.kr/learn/courses/30/lessons/118667

내 처음 풀이는 시간 초과 였고 해당 풀이 방식은 반복문을 통헤 값이 같은 경우를 찾는 거라 개수보고 
시간초과 나겠구나 예상하긴 했다. 그런데 시간초과외에도 틀리는 테케들이 있어서 예외의 경우가 어떤 부분인지 궁금해졌다.

실제로 풀이하는 방식은 문제에서 주어진대로 큐에 넣어보면서 값을 체크해주면 된다.
저 while문의 경우 큐의 2배만큼 돌도록 설정해주었더니 테케 1번에서 통과하지 못해 3으로 설정하였다.

풀이를 보면 "이때, 전체 배열의 길이가 2n이므로, 한 포인터 당 최대 2n번의 이동이 필요합니다. 따라서, 총 4n만큼의 작업을 수행한 뒤에도 두 큐의 합을 같게 만들지 못했다면 
그 이후에는 이미 탐색했던 구간을 다시 탐색하는 것이므로 의미가 없습니다. 이 경우에는 -1을 반환합니다."

4n이 최대인 것 같지만 주어진 테케는 3n만으로 통과가능한 것 같다.

https://tech.kakao.com/2022/07/13/2022-coding-test-summer-internship/

해당 문제는 투포인터 방식 문제로 자주 접하지 않은 문제 유형이라 정리가 필요할 것 같다.
https://www.notion.so/20-3c3d1ff3206b4a22a2f5994f7a45b91a

*/
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    long long sum1 = 0;
    long long sum2 = 0;
    long long goalNum = 0;
    int queueSize = queue1.size();
    for (int i = 0; i < queueSize; i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    goalNum = (sum1 + sum2) / 2;
    long long idx1 = 0; long long idx2 = 0;

    while (answer < queueSize * 3)
    {
        if (sum1 > sum2)
        {
            sum2 += queue1[idx1];
            sum1 -= queue1[idx1];
            queue2.push_back(queue1[idx1]);
            idx1++;
        }
        else if (sum1 < sum2)
        {
            sum1 += queue2[idx2];
            sum2 -= queue2[idx2];
            queue1.push_back(queue2[idx2]);
            idx2++;
        }
        else
        {
            return answer;
        }
        answer++;
    }

    return -1;
}

/*
시간 초과 풀이

#include <string>
#include <vector>
#include <iostream>
#define MAX 1e9

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = MAX;
    long long sum1 = 0;
    long long sum2 = 0; long long goalNum = 0;
    for(int i =0;i<queue1.size();i++)
    {
        sum1 += queue1[i];
        sum2 += queue2[i];
    }
    goalNum = (sum1+sum2)/2;
    vector<int> v = queue1;
    v.insert(v.end(),queue2.begin(),queue2.end());
    for(int i = 0;i<v.size();i++)
    {
        long long arrNum = 0;
        for(int j = i;j<v.size();j++)
        {
            arrNum += v[j];
            if(arrNum>goalNum)//값이 더 커비리면 안됨
                break;
            if(arrNum==goalNum)
            {
                int moveNum = 0;
                moveNum += i ;
                if(queue1.size()<=j)
                    moveNum += (j-queue1.size()+1);
                answer = min(moveNum,answer);
                break;
            }
        }
    }
    if(answer== MAX)
        answer = -1;
    return answer;
}
*/