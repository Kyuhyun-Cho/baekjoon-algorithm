#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char map[1001][1001];
bool visited[1001][1001];

int n, m;
bool answer = false;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	if (y == n-1) {
		answer = true;
		return;
	}
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] == '0')
			bfs(ny, nx);
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

	for (int j = 0; j < m; j++) {
		if (!visited[0][j] && map[0][j] == '0') {
			bfs(0, j);
		}
		if (answer) {
			cout << "YES" << '\n';
			return 0;
		}
	}
	cout << "NO" << '\n';
}