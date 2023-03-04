#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
char map[101][101];
bool visited[101][101];
char color;
int w_cnt = 1;
int b_cnt = 1;
int total_w, total_b;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    visited[y][x] = true;
    
    color = map[y][x];

    if (color == 'W') {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] == 'W') {
                w_cnt++;
                bfs(ny, nx);
            }
        }
    }
    else if (color == 'B') {
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] == 'B') {
                b_cnt++;
                bfs(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j]) {
                bfs(i, j);
                if (color == 'W') {
                    total_w += w_cnt * w_cnt;
                }
                else if (color == 'B') {
                    total_b += b_cnt * b_cnt;
                }
                w_cnt = 1;
                b_cnt = 1;
            }
        }
    }

    cout << total_w << ' ' << total_b << '\n';
}