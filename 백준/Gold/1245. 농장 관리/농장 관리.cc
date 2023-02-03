#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int map[101][71];
bool visited[101][71];
bool top;
int answer;

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool validCheck(int y, int x) {
    if ( 0 <= y && y < n && 0 <= x && x < m && !visited[y][x]) {
        return true;
    }
    return false;
}

void bfs(int y, int x) {
    for (int i = 0; i < 8; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        
        if (0 <= ny && ny < n && 0 <= nx && nx < m) {
            if (map[y][x] < map[ny][nx]) top = false;

            if (!visited[ny][nx] && map[y][x] == map[ny][nx]) {
                visited[ny][nx] = true;
                bfs(ny, nx);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }
   
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j]) {
                // cout << map[i][j] << ' ';
                top = true;
                visited[i][j] = true;
                bfs(i, j);
                if (top) answer++;
            }
        }
    }
    cout << answer << '\n';
}