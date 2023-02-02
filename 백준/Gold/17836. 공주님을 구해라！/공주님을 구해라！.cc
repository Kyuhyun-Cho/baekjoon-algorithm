#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

struct pose {
	int y;
	int x;
	int cnt;
	int gram;
};

queue<pose> q;

int n, m, t;
int map[101][101];
int visited[101][101][2];
int answer;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validCheck(int y, int x) {
	if (0 <= y && y < n && 0 <= x && x < m) {
		return true;
	}
	return false;
} 

void bfs() {
	while(!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		int gram = q.front().gram;
		q.pop();

		if (map[y][x] == 2) {
			gram = 1;
		}

		if (y == n-1 && x == m-1) {
			answer = cnt;
			return;
		}		
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (gram == 1) {
				if (validCheck(ny,nx) && visited[ny][nx][gram] == 0) {
					visited[ny][nx][gram] = cnt + 1;
					q.push({ny, nx, cnt+1, gram});
				}
			}
			else {
				if (validCheck(ny, nx) && visited[ny][nx][0] == 0 && map[ny][nx] != 1) {
					visited[ny][nx][0] = cnt + 1;
					q.push({ny, nx, cnt+1, gram});
				}
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n >> m >> t;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
	
	visited[0][0][0] = 1;
	q.push({0, 0, 0, 0});

	bfs();

	if (0 < answer && answer <=t) {
		cout << answer << '\n';
	}
	else {
		cout << "Fail" << '\n';
	}
	return 0;
} 
