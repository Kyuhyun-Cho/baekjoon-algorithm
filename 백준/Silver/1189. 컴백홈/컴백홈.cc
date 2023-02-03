#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int r, c, k;
char map[6][6];
bool visited[6][6];
int answer;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool validCheck(int y, int x) {
    if ( 0 <= y && y < r && 0 <= x && x < c && !visited[y][x]) {
        return true;
    }
    return false;
}

void bfs(int y, int x, int cnt) {
        if (y == 0 && x == c-1 && cnt == k) {
            answer++;
            return;
        }        
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (validCheck(ny, nx) && map[ny][nx] != 'T') {
                visited[ny][nx] = true;
                bfs(ny, nx, cnt+1);
                visited[ny][nx] = false;
            }
        }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> map[i][j];
        }
    }
    visited[r-1][0] = true;
    bfs(r-1, 0, 1);

    cout << answer << '\n';
}