/*
https://www.acmicpc.net/problem/1927
1927 최소 힙

시간 초과먹어서 충격 먹었는데 c++ 입출력 시 개수가 크면 입출력 시간때문에 시간초과날 수 있다는 점을 간과했다.
머지..?뭐지 해서 분명 자식노드 한번씩이라 logN일텐데...이러다가 질문보고 입출력 수 큰거 보고 문득 깨달았다. 근데 기억이 안나서 검색하고옴
	ios::sync_with_stdio(false);
	cin.tie(NULL);

이 문제는 입력 출력 둘 다 해줘야해서 필수였다.

그리고 처음에 쓰면서 안했더니 pop하고나서 가장 위 값과 아래 값 바꿔서 다시 최소값을 위에 아래로 맞춰주는 걸 생각을 못했다. 그냥 0에서 작은 값으로 바꿔가면 된다고 생각했다가 이상하게 답나와서 그제서야 알아차렸다.
다음엔 최대 힙 풀고 언젠가 js로도 풀어보기
*/
#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N,n,temp;
	cin>>N;
	vector<int> minheap;

	for(int i = 0;i<N;i++)
	{
		cin>>n;
		
		if(n == 0) // pop
		{
			if(minheap.size()==0)
				cout<<0<<'\n';
			else
			{

				cout<<minheap[0]<<"\n";

				minheap[0] = minheap[minheap.size() -1];
				minheap.pop_back();
				
				int index = 0;
				while(true)
				{
                    int leftChild = 2 * index + 1;
                    int rightChild = 2 * index + 2;
                    int minIndex = index;

                    if (leftChild < minheap.size() && minheap[leftChild] < minheap[minIndex])
                        minIndex = leftChild;
                    
                    if (rightChild < minheap.size() && minheap[rightChild] < minheap[minIndex])
                        minIndex = rightChild;
                    
        			if (minIndex == index)
                        break;
                    
					
                    temp = minheap[index];
                    minheap[index] = minheap[minIndex];
                    minheap[minIndex] = temp;

                    index = minIndex;
				}
			}
		}else{
			minheap.push_back(n);
			
        	int index = minheap.size() - 1;
        	while ((index - 1)/2>=0 && minheap[(index - 1)/2] > minheap[index]) 
        	{
            	int parentIndex = (index - 1)/2;
            	
        		temp = minheap[parentIndex];
        		minheap[parentIndex] = minheap[index];
        		minheap[index] = temp;
        		
            	index = parentIndex;
        	}
		}
	}
	return 0;
}
