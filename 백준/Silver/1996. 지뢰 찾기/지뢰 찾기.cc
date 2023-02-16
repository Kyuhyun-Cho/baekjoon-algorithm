#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;
char map[1001][1001];
char answer[1001][1001];

int dx[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
int dy[8] = {-1, -1, -1, 0, 1, 1, 1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n; cin >> n;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            if (map[y][x] != '.') {
                answer[y][x] = '*';
            }
            else {
                int cnt = 0;
                for (int i = 0; i < 8; i++) {
                    int ny = y + dy[i];
                    int nx = x + dx[i];
                    if (0 <= nx && nx < n && 0 <= ny && ny < n && map[ny][nx] != '.') {
                        cnt += map[ny][nx] - '0';
                    }
                }
                if (cnt < 10) {
                    answer[y][x] = cnt + '0';
                }
                else {
                    answer[y][x] = 'M';
                }
            }
        }
    }

    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < n; j++) {
            cout << answer[i][j];
        }
        cout << '\n';
    }
    
    return 0;
}    