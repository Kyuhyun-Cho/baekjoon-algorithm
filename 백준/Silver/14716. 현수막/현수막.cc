#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int map[251][251];
bool visited[251][251];

int m, n;
int cnt;

int dy[8] = {-1, 0, 1, 0, -1, 1, 1, -1};
int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};

void bfs(int y, int x) {
	visited[y][x] = true;

	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < m && 0 <= nx && nx < n && !visited[ny][nx] && map[ny][nx] == 1)
			bfs(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(!visited[i][j] && map[i][j] == 1) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << '\n';
}