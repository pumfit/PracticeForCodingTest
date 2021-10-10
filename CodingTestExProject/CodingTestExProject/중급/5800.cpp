/*
5800 성적 통계
첫째 줄에 중덕 고등학교에 있는 반의 수 K (1 ≤ K ≤ 100)가 주어진다. 다음 K개 줄에는 각 반의 학생수 N (2 ≤ N ≤ 50)과 각 학생의 수학 성적이 주어진다.
시험 성적은 0보다 크거나 같고, 100보다 작거나 같은 정수이고, 공백으로 나누어져 있다.

정렬한 뒤 성적을 내림차순으로 정렬했을 때 가장 큰 인접한 점수 차이를 예제 출력과 같은 형식으로 출력한다.
점수 차이를 반복문을 총해 최대값을 구해주었다.
*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int N[52] = {0,};

int main()
{
	int K;
	cin >> K;

	for (int i = 0; i < K; i++)
	{
		int k ;
		int max = 0;
		vector<int> arr;
		cin >> k;

		for (int j = 0; j < k; j++)
		{
			int n;
			cin >> n;
			arr.push_back(n);
		}
		sort(arr.begin(), arr.end());

		for (int j = k; j > 1; j--)
		{
			int z = arr[j-1] - arr[j-2];
			if (max < z)
				max = z;
		}

		cout << "Class " << i + 1<<endl;
		cout << "Max " << arr[k-1]<<", Min "<< arr[0]<<", Largest gap "<<max<<endl;
	}
}