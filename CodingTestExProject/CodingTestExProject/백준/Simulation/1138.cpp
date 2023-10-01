/*
1138 한 줄로 서기
https://www.acmicpc.net/problem/1138

뒤에서 부터 기억나는 인원을 인덱스로 추가함.
이때, 이미 있는 경우 한칸씩 오른쪽으로 자리 이동
vector insert 를 사용해 푸는 방법도 있다.
*/
#include <iostream>
using namespace std;

int main() {
	int N;
	cin>>N;
	int arr[N] = {0,};
	int line[N] = {0,};
	for(int i = 0;i<N; i++)
		cin>>arr[i];
	for(int i = N-1;i>=0; i--)
	{
		int num = i+1;
		int index = arr[i];
		if(line[index] == 0)
		{
			line[index] = num;
		}else if(num<line[index]){
			int temp = line[index];
			line[index] = num;
			for(int j = index+1;j<N;j++)
			{
				int cur = line[j];
				line[j] = temp;
				temp = cur;
			}
		}
	}
	
	for(int j = 0;j<N;j++)
		cout<<line[j]<<" ";
		
	return 0;
}