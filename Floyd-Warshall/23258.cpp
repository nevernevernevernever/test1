#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define INF 987654321

int N, Q, C, s, e, n;
int map[301][301][301];// x y 

int main() { // 0도 입력 된다 내가 한 방식으로 하면 INF가 없음
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            if (i == j) {continue;}
            else {map[i][j][0] = INF;}
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> n; // 거리 정보
            if (n == 0) {continue;}
            else {map[i][j][0] = n;}
        }
    }
    for (int k = 1; k <= N; k++) {
        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= N; j++) {
                if (map[i][j][k-1] > map[i][k][k-1] + map[k][j][k-1]) {
                    map[i][j][k] = map[i][k][k-1] + map[k][j][k-1];
                }
                else {
                    map[i][j][k] = map[i][j][k-1];
                }
                
                //map[i][j][k] = min(map[i][j][k - 1], map[i][k][k - 1] + map[k][j][k - 1]);
            }
        }
    }
    for (int i = 0; i < Q; i++) {
        cin >> C >> s >> e; // C미만으로 s 에서 e로 가는 길의 최소길이
        if (map[s][e][C - 1] == INF) {
            cout << -1 << "\n";
        }
        else {
            cout << map[s][e][C - 1] << "\n";
        }
    }
}
