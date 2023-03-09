#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

char map[601][601];
bool visited[601][601];

int n, m;
int my, mx;
int cnt;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
	visited[y][x] = true;
	
	if(map[y][x] == 'P') {
		cnt++;
	}

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (0 <= ny && ny < m && 0 <= nx && nx < n && !visited[ny][nx] && map[ny][nx] != 'X')
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
			if (map[i][j] == 'I') {
				my = i;
				mx = j;
			}
		}
	}

	bfs(my, mx);

	if (cnt == 0) {
		cout << "TT" << '\n';
		return 0;
	}
	cout << cnt << '\n';
}