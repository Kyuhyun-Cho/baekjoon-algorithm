#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k;
int map[101][101];
bool visited[101][101];

int cnt;
vector<int> total_cnt;
int max_size = -1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    cnt++;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (1 <= ny && ny <= n && 1 <= nx && nx <= m && !visited[ny][nx] && map[ny][nx] == 1) {
            bfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        int r, c; 
        cin >> r >> c;
        map[r][c] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
                total_cnt.emplace_back(cnt);
                cnt = 0;
            }
        }
    }

    for (int i = 0; i < total_cnt.size(); i++) {
        if (total_cnt[i] > max_size) {
            max_size = total_cnt[i];
        }
    }
    cout << max_size << '\n';
}