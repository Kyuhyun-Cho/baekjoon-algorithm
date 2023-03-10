#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

char map[101][101];
int visited[101][101];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

int t, h, w, cnt;

void bfs(int y, int x) {
    visited[y][x] = true;
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < h && 0 <= nx && nx < w && !visited[ny][nx] && map[ny][nx] == '#') {
            bfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    for (int test_case = 0; test_case < t; test_case++) {
        memset(visited, false, sizeof(visited));
        memset(map, ' ', sizeof(map));
        cnt = 0;
        
        cin >> h >> w;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if(!visited[i][j] && map[i][j] == '#') {
                    bfs(i,j);
                    cnt++;
                }
            }
        }
        cout << cnt << '\n';
    }
}