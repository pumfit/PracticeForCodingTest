/*
나머지 한 점
https://school.programmers.co.kr/learn/courses/18/lessons/1878
*/
#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans;
    map<int, int> X;
    map<int, int> Y;
    for (int i = 0; i < 3; i++)
    {
        X[v[i][0]]++;
        Y[v[i][1]]++;
    }
    for (auto& v : X)
    {
        if (v.second == 1)
        {
            ans.push_back(v.first);
            break;
        }

    }
    for (auto& v : Y)
    {
        if (v.second == 1)
        {
            ans.push_back(v.first);
            break;
        }

    }
    return ans;
}
/*
XOR 풀이법

#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<vector<int> > v) {
    vector<int> ans = {0,0};
    for(int i = 0;i<3;i++)
    {
        ans[0] ^= v[i][0];
        ans[1] ^= v[i][1];
    }
    return ans;
}

*/