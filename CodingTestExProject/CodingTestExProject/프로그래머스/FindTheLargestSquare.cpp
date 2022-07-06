/*
가장 큰 정사각형 찾기
https://school.programmers.co.kr/learn/courses/30/lessons/12905

1와 0로 채워진 표(board)가 있습니다. 표 1칸은 1 x 1 의 정사각형으로 이루어져 있습니다. 표에서 1로 이루어진 가장 큰 정사각형을 찾아 넓이를 return 하는 solution 함수를 완성해 주세요. 
(단, 정사각형이란 축에 평행한 정사각형을 말합니다.)

첫 풀이는 거의 전체 탐색으로 진행했다. 1인 경우에만 가로 세로를 구해 정사각형 크기를 구하는 풀이로 정확성도 만점이 아니었고 효율성에서 0점이 나왔다.
다른 풀이방법에 대한 인사이트가 부족했고 효율성부분에서 어떻게 3중 for문 쓰면서 해결하지 않을 수 있을 지에 대해 해답을 얻지 못했다.

dp 로 풀이 할 수 있는 문제였다.
dp문제 풀이에서 중요한 초기값 초기화와 점화식 찾기 순서로 나눠서 하면된다.
dp 초기화 범위를  i+1,j+1로 하지 않는 경우 테케 처음에서 실패하는데 [[1]] 1인 경우를 체크하지 못한다.
해당 이유로 1~size() 까지 for문을 순회하도록 해야한다.

가장 큰 정사각형을 찾는 경우에 dp를 쓸 수 있다는 사실을 알게된 문제
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dp[1001][1001] = { 0, };
    //1.dp 초기값 초기화 하기
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
                dp[i + 1][j + 1] = 1;
        }
    }
    //2. 현재가 1이라면 현재위치에 대해 좌상단,좌,상 세방향으로 최소값을 구하고 해당값보다 1 크게 ddp값을 변경
    for (int i = 1; i <= board.size(); i++)
    {
        for (int j = 1; j <= board[0].size(); j++)
        {
            if (dp[i][j] != 1)
                continue;

            dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            answer = max(dp[i][j] * dp[i][j], answer);
        }
    }

    return answer;
}

/*
#include <iostream>
#include<algorithm>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    // 1인 경우 가로 세로 길이를 0일때까지 계산
    int maxY = board.size(); int maxX = board[0].size();
    for (int i = 0; i < maxY; i++)
    {
        for (int j = 0; j < maxX; j++)
        {
            if (!board[i][j])
                continue;
            int curI = i; int curJ = j; int cnt = 1;
            while (true)
            {
                if (curI + 1 >= maxY)
                    break;
                if (curJ + 1 >= maxX)
                    break;
                if (!board[curI + 1][j])
                    break;
                if (!board[i][curJ + 1])
                    break;
                curJ++; curI++;
            }
            cnt += (curI - i);
            if (cnt * cnt > answer)
            {
                answer = cnt * cnt;
                maxY -= cnt;
                maxX -= cnt;
            }
        }
    }

    return answer;
}
*/
