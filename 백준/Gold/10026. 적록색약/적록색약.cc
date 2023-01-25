#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char map[101][101];
bool visited[101][101];
int cnt;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs(int y, int x) {
    visited[y][x] = true;
    for (int i = 0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];

        if (0 <= next_x && next_x <= n && 0 <= next_y && next_y <= n && !visited[next_y][next_x]) {
            if (map[next_y][next_x] == map[y][x]) {
                bfs(next_y, next_x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << ' ';
    cnt = 0;
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (map[i][j] == 'G') {
                map[i][j] = 'R';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    
    cout << cnt << ' ';
    
    
    return 0;
}    