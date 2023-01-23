#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>


using namespace std;

int m, n, answer;
int map[1001][1001];
queue<pair<int, int>>q;

int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1 ,0};

void bfs() {
	while(!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int next_y = y + dy[i];
			int next_x = x + dx[i];

			if (0 <= next_x && next_x <= m && 0 <= next_y && next_y <= n && map[next_y][next_x] == 0) {
				map[next_y][next_x] = map[y][x] + 1;
				q.push({next_y, next_x});
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(map, -1, sizeof(map));
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({i, j});
			}
		}
	}
		
	bfs();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// cout << map[i][j] << ' ';
			if (map[i][j] == 0) {
				cout << -1 << '\n';
				return 0;
			}
			if (map[i][j] > answer) {
				answer = map[i][j];
			}
		}
		// cout << '\n';
	}

	cout << answer - 1 << '\n';
}