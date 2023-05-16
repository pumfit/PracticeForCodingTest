/*
4995 원과 점

테케 기준으로 

6
7.15296 4.08328
6.50827 2.69466
5.91219 3.86661
5.29853 4.16097
6.10838 3.46039
6.34060 2.41599

일때 n = 5 여야하는 n = 4
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

struct Point {
    double x, y;
};

int main() {
    int N;
    
    while(true) {
        cin >> N;
        if(N==0)
            return 0;
        
        vector<Point> points(N);
        for (int i = 0; i < N; i++) {
            cin >> points[i].x >> points[i].y;
        }

        int max_points = 0;
        for (int i = 0; i < N; i++) {
            for (int j = i+1; j < N; j++) {
                int count = 0;
                double dx = points[j].x - points[i].x;
                double dy = points[j].y - points[i].y;
                double dist = sqrt(dx*dx + dy*dy);

                if (dist > 2.0) 
                    continue;

                // 두 점에 대한 중점
                double mx = (points[j].x + points[i].x)/2.0;
                double my = (points[j].y + points[i].y)/2.0;

                // 중점으로 부터의 거리
                for (int k = 0; k < N; k++) {
                    double dx = points[k].x - mx;
                    double dy = points[k].y - my;
                    double dist2 = sqrt(dx*dx + dy*dy);
                    if(dist2<=1.0)
                        count++;
                }
                max_points = max(max_points, count);
            }
        }
        cout << max_points << '\n';
    }
    return 0;
}