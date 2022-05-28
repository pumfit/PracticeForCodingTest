/*
정렬 H-Index

H-Index는 과학자의 생산성과 영향력을 나타내는 지표입니다. 어느 과학자의 H-Index를 나타내는 값인 h를 구하려고 합니다. 
위키백과1에 따르면, H-Index는 다음과 같이 구합니다.

어떤 과학자가 발표한 논문 n편 중, h번 이상 인용된 논문이 h편 이상이고 
나머지 논문이 h번 이하 인용되었다면 h의 최댓값이 이 과학자의 H-Index입니다.

어떤 과학자가 발표한 논문의 인용 횟수를 담은 배열 citations가 매개변수로 주어질 때,
이 과학자의 H-Index를 return 하도록 solution 함수를 작성해주세요.

https://en.wikipedia.org/wiki/H-index "위키백과"

테스트 케이스 추가해보고 왜 틀렸는지 알 수 있었던 문제 h가 꼭 제시된 인용 수라고
생각했는데 아니였었다.
*/
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
	int answer = 0;
	sort(citations.begin(), citations.end());
	for (int i = 0; i < citations.size(); i++)
	{
		for (int h = 0; h <= citations[i]; h++)
		{
			if (h <= citations.size() - i && i <= h)
			{
				int Hidx = h;
				if (answer < Hidx)
					answer = Hidx;
			}
		}


	}
	return answer;
}