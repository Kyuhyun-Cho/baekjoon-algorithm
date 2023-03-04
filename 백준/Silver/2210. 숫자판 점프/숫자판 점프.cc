#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int map[5][5];
int visited[1000000];
int answer;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x, int sum, int cnt) {
    if (cnt == 5) {
        if (!visited[sum]) {
            visited[sum] = true;
            answer++;
        }
        return;
    }
    
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < 5 && 0 <= nx && nx < 5) {
            bfs(ny, nx, sum*10+map[ny][nx], cnt+1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            cin >> map[i][j];
        }
    }

        for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            bfs(i, j, map[i][j], 0);
        }
    }

    cout << answer << '\n';
}