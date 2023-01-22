#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int T, M, N, K;
int map[51][51];
bool visited[51][51];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0 ,0};

bool dfs(int y, int x) {
	if (visited[y][x]) return false;
	visited[y][x] = true;
	
	for (int i = 0; i < 4; i++) {
		int next_x = x + dx[i];
		int next_y = y + dy[i];

		if (0 <= next_x && next_x < M && 0 <= next_y && next_y < N && map[next_y][next_x]) {
			dfs(next_y, next_x);
		}
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> T;
	for (int t = 0; t < T; t++) {
		int cnt = 0;
		memset(map, 0, sizeof(map));
		memset(visited, 0, sizeof(visited));
		
		cin >> M >> N >> K;
		int x, y;
		for (int k = 0; k < K; k++) {
			cin >> x >> y;
			map[y][x] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (map[i][j] && !visited[i][j]) {
					if (dfs(i, j)) {
						cnt++;
					}
				}
			}
		}
		
		cout << cnt << '\n';
	}

	
} 