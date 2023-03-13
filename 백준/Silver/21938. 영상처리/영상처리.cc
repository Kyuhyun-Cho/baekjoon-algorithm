#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int r, g, b;
int t;
int cnt;
int map[1001][1001];
bool visited[1001][1001];

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] == 255) {
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
			cin >> r >> g >> b;
			map[i][j] = (r+g+b) / 3;
		}
	}

	cin >> t;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] >= t) {
				map[i][j] = 255;
			}
			else {
				map[i][j] = 0;
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 255) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	cout << cnt << '\n';
}