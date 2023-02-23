#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n, m;
char map[51][51];
bool visited[51][51];
int cnt;

int dy[2] = {-1 ,1};
int dx[2] = {-1, 1};

void bfs(int y, int x) {
    visited[y][x] = true;

    if (map[y][x] == '-') {
        for (int i = 0; i < 2; i++) {
            int nx = x + dx[i]; 
            if (0 <= nx && nx < m && !visited[y][nx] && map[y][nx] == '-') {
                bfs(y, nx);
            }
        }
        
    }
    else if (map[y][x] == '|') {
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i]; 
            if (0 <= ny && ny < n && !visited[ny][x] && map[ny][x] == '|') {
                bfs(ny, x);
            }
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
            if (!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }
    cout << cnt << '\n';
}    