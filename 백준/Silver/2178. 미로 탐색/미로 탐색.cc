#include <iostream>
#include <queue>
#include <string>

using namespace std;

int n, m;
int maze[101][101];
bool visited[101][101];
int dist[101][101];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

queue<pair<int, int>> q;

void bfs(int first_x, int first_y) {
	visited[first_x][first_y] = true;
	q.push(make_pair(first_x, first_y));
	dist[first_x][first_y]++;

	while(!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((0 <= nx && nx < n) && (0 <= ny && ny < m) && !visited[nx][ny] && maze[nx][ny] == 1) {
				visited[nx][ny] = true;
				q.push(make_pair(nx, ny));
				dist[nx][ny] = dist[x][y] + 1;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string road;
		cin >> road;
		for (int j = 0; j < m; ++j) {
			maze[i][j] = road[j] -'0';
		}
	}
	bfs (0,0);
	cout << dist[n-1][m-1] << '\n';
}