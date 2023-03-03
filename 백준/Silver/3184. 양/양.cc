#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
char map[251][251];
bool visited[251][251];

int total_sheep, total_wolf;
int sheep_cnt, wolf_cnt;


int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    if (map[y][x] == 'o') {
        sheep_cnt++;
    }
    if (map[y][x] == 'v') {
        wolf_cnt++;
    }
    
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] != '#') {
            bfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && map[i][j] != '#') {
                bfs(i, j);
                if (sheep_cnt > wolf_cnt) {
                    total_sheep += sheep_cnt;
                }
                else {
                    total_wolf += wolf_cnt;
                }
                sheep_cnt = 0;
                wolf_cnt = 0;
            }
        }
    }
    cout << total_sheep << ' ' << total_wolf << '\n';
}