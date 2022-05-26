/*
* 프렌즈4블록
* 2018 KAKAO BLIND RECRUITMENT

왜맞틀 꽤나 했던 문제

자꾸 시간초과나서 그런 곳 없을 텐데 하다가 생각해보니 블록 체크해줄때 빈칸일때도 계속 체크하고 있어서
당연히 시간초과날 수 밖에 없었다 30번째 라인쯤에서 이부분

빈 배열 세로 배열을 벡터로 가져가서 풀면 더 쉬우려나 
*/

#include <string>
#include <cstring>
#include <vector>
#include <iostream>

using namespace std;

int dx[4] = { 0,1,1,0 };
int dy[4] = { 1,0,1,0 };

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool isContinue = true;
    while (isContinue) {
        //초기화
        int visited[31][31] = { 0, };
        isContinue = false;
        //블록 제거
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                char c = board[i][j];
                if (c == ' ')
                    continue;
                bool isSquare = true;
                for (int k = 0; k < 3; k++)
                {
                    int nx = j + dx[k];
                    int ny = i + dy[k];

                    if (nx >= n || ny >= m)
                    {
                        isSquare = false;
                        break;
                    }
                    if (c != board[ny][nx])
                    {
                        isSquare = false;
                        break;
                    }
                }
                if (isSquare)
                {
                    isContinue = true;
                    for (int k = 0; k < 4; k++)
                    {
                        int nx = j + dx[k];
                        int ny = i + dy[k];
                        if (!visited[ny][nx])
                        {
                            visited[ny][nx] = 1;
                        }
                    }
                }
            }
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j])
                {
                    board[i][j] = ' ';
                    answer++;
                }
            }

        }
        //블록 빈공간 채우기
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == ' ')//빈 경우
                {
                    for (int k = i; k > 0; k--)// Y값아래로 내려가기
                    {
                        if (board[k - 1][j] == ' ')
                            break;
                        board[k][j] = board[k - 1][j];//위에 있는 블럭이랑 교환
                        board[k - 1][j] = ' ';
                    }
                }
            }
        }

    }

    return answer;
}