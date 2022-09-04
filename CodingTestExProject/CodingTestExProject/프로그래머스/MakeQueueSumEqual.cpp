/*
�� ť �� ���� �����

https://school.programmers.co.kr/learn/courses/30/lessons/118667

�� ó�� Ǯ�̴� �ð� �ʰ� ���� �ش� Ǯ�� ����� �ݺ����� ���� ���� ���� ��츦 ã�� �Ŷ� �������� 
�ð��ʰ� ���ڱ��� �����ϱ� �ߴ�. �׷��� �ð��ʰ��ܿ��� Ʋ���� ���ɵ��� �־ ������ ��찡 � �κ����� �ñ�������.

������ Ǯ���ϴ� ����� �������� �־������ ť�� �־�鼭 ���� üũ���ָ� �ȴ�.
�� while���� ��� ť�� 2�踸ŭ ������ �������־����� ���� 1������ ������� ���� 3���� �����Ͽ���.

Ǯ�̸� ���� "�̶�, ��ü �迭�� ���̰� 2n�̹Ƿ�, �� ������ �� �ִ� 2n���� �̵��� �ʿ��մϴ�. ����, �� 4n��ŭ�� �۾��� ������ �ڿ��� �� ť�� ���� ���� ������ ���ߴٸ� 
�� ���Ŀ��� �̹� Ž���ߴ� ������ �ٽ� Ž���ϴ� ���̹Ƿ� �ǹ̰� �����ϴ�. �� ��쿡�� -1�� ��ȯ�մϴ�."

4n�� �ִ��� �� ������ �־��� ���ɴ� 3n������ ��������� �� ����.

https://tech.kakao.com/2022/07/13/2022-coding-test-summer-internship/

�ش� ������ �������� ��� ������ ���� ������ ���� ���� �����̶� ������ �ʿ��� �� ����.
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
�ð� �ʰ� Ǯ��

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
            if(arrNum>goalNum)//���� �� Ŀ�񸮸� �ȵ�
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