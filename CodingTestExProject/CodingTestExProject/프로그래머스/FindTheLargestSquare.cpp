/*
���� ū ���簢�� ã��
https://school.programmers.co.kr/learn/courses/30/lessons/12905

1�� 0�� ä���� ǥ(board)�� �ֽ��ϴ�. ǥ 1ĭ�� 1 x 1 �� ���簢������ �̷���� �ֽ��ϴ�. ǥ���� 1�� �̷���� ���� ū ���簢���� ã�� ���̸� return �ϴ� solution �Լ��� �ϼ��� �ּ���. 
(��, ���簢���̶� �࿡ ������ ���簢���� ���մϴ�.)

ù Ǯ�̴� ���� ��ü Ž������ �����ߴ�. 1�� ��쿡�� ���� ���θ� ���� ���簢�� ũ�⸦ ���ϴ� Ǯ�̷� ��Ȯ���� ������ �ƴϾ��� ȿ�������� 0���� ���Դ�.
�ٸ� Ǯ�̹���� ���� �λ���Ʈ�� �����߰� ȿ�����κп��� ��� 3�� for�� ���鼭 �ذ����� ���� �� ���� ���� ���� �ش��� ���� ���ߴ�.

dp �� Ǯ�� �� �� �ִ� ��������.
dp���� Ǯ�̿��� �߿��� �ʱⰪ �ʱ�ȭ�� ��ȭ�� ã�� ������ ������ �ϸ�ȴ�.
dp �ʱ�ȭ ������  i+1,j+1�� ���� �ʴ� ��� ���� ó������ �����ϴµ� [[1]] 1�� ��츦 üũ���� ���Ѵ�.
�ش� ������ 1~size() ���� for���� ��ȸ�ϵ��� �ؾ��Ѵ�.

���� ū ���簢���� ã�� ��쿡 dp�� �� �� �ִٴ� ����� �˰Ե� ����
*/

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;
    int dp[1001][1001] = { 0, };
    //1.dp �ʱⰪ �ʱ�ȭ �ϱ�
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if (board[i][j] == 1)
                dp[i + 1][j + 1] = 1;
        }
    }
    //2. ���簡 1�̶�� ������ġ�� ���� �»��,��,�� ���������� �ּҰ��� ���ϰ� �ش簪���� 1 ũ�� ddp���� ����
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

    // 1�� ��� ���� ���� ���̸� 0�϶����� ���
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
