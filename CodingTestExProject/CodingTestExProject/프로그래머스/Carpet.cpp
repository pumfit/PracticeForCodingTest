/*
ī��
https://school.programmers.co.kr/learn/courses/30/lessons/42842


���� �ణ�� ���й���

�ٸ� Ǯ�� ���� �������������� Ǫ�� Ǯ�̵� �־ �ű��ߴ�.
���� �ٸ� Ǯ�̵麸�� ���� �Ǵ� �� ���� ���صΰ� ã�� Ǯ���ε� ���� �ݴ�� sum�� ��� ���� �Ǵ� ���� sum/N, N���� ã�ư��� �����̿���.

+) ���ϰ� answer�� �߰������ʰ� {N,sum/N}���� ǥ���ص� �ȴ�.
*/
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    //brown+yellow �� �Ǵ� �� ��� ã��
    int sum = brown + yellow;
    int N = sum;
    while (sum > 0)
    {
        if (sum % N == 0)
        {
            if ((sum / N + N) * 2 - 4 == brown)
            {
                answer.push_back(N);
                answer.push_back(sum / N);
                break;
            }
        }
        N--;
    }
    return answer;
}