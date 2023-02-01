#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;
int t, n, start_x, start_y, end_x, end_y;
bool visited[301][301];


int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

bool validCheck(int y, int x) {
	if (0 <= y && y < n && 0 <= x && x < n && !visited[y][x]) {
		return true;
	}
	return false;
} 

void bfs(int y, int x) {
	queue<pair<pair<int, int>, int>> q;
	q.push(make_pair(make_pair(y, x), 0));
	visited[y][x] = true;
	
	while(!q.empty()) {
		int py = q.front().first.first;
		int px = q.front().first.second;
		int cnt = q.front().second;
		q.pop();

		if (px == end_x && py == end_y) {
			cout << cnt << '\n';
			while(!q.empty()) q.pop();
			continue;
		}
		for (int i = 0; i < 8; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];

			if (validCheck(ny, nx)) {
				visited[ny][nx] = true;
				q.push(make_pair(make_pair(ny, nx), cnt+1));
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		memset(visited, false, sizeof(visited));
		cin >> n;
		cin >> start_x >> start_y;
		cin >> end_x >> end_y;
		bfs(start_y, start_x);
	}
	return 0;
} 
