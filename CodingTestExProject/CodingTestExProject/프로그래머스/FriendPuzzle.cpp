/*
* ������4���
* 2018 KAKAO BLIND RECRUITMENT

�ָ�Ʋ �ϳ� �ߴ� ����

�ڲ� �ð��ʰ����� �׷� �� ���� �ٵ� �ϴٰ� �����غ��� ��� üũ���ٶ� ��ĭ�϶��� ��� üũ�ϰ� �־
�翬�� �ð��ʰ��� �� �ۿ� ������ 30��° �����뿡�� �̺κ�

�� �迭 ���� �迭�� ���ͷ� �������� Ǯ�� �� ������� 
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
        //�ʱ�ȭ
        int visited[31][31] = { 0, };
        isContinue = false;
        //��� ����
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
        //��� ����� ä���
        for (int i = 1; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == ' ')//�� ���
                {
                    for (int k = i; k > 0; k--)// Y���Ʒ��� ��������
                    {
                        if (board[k - 1][j] == ' ')
                            break;
                        board[k][j] = board[k - 1][j];//���� �ִ� ���̶� ��ȯ
                        board[k - 1][j] = ' ';
                    }
                }
            }
        }

    }

    return answer;
}