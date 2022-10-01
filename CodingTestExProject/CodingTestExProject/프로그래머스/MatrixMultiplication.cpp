/*
행렬의 곱셈

https://school.programmers.co.kr/learn/courses/30/lessons/12949#

생각보다 바로 떠오르지 않았는데 처음에 j 크기를 arr2.size()로 잡아서 틀렸었다 이러면 열의 크기가 정상적으로 잡히지 않는데
테케가 하필 B의 행과 열이 같아서 통과되었었다.
 
행렬의 곱셉은 행과 열을 고정하고 k값만 변경해가며 계산을 진행하면된다.
*/
#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer;
    //열 개수 arr1.size() 행 개수 arr2.size()
    for(int i = 0;i<arr1.size();i++)//3
    {
        vector<int> v;
        for(int j = 0;j<arr2[0].size();j++)//1
        {
            int sum = 0;
            for(int k = 0;k<arr2.size();k++)
            {
                sum += arr1[i][k]*arr2[k][j];
            }
            v.push_back(sum);
        }
        answer.push_back(v);
    }
    return answer;
}