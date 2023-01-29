#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int m, n, k;
int map[101][101];
bool visited[101][101];
int cnt;
vector<int> answer;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validCheck(int y, int x) {
	if (0 <= y && y < m && 0 <= x && x < n && !visited[y][x]) {
		return true;
	}
	return false;
}

void bfs(int y, int x) {
	visited[y][x] = true;
	cnt++;
	
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (validCheck(ny, nx)) {
			if (map[ny][nx] == 0) {
				bfs(ny, nx);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		
		for (int y = y1; y < y2; y++) {
			for (int x = x1; x < x2; x++) {
				map[y][x] = 1;
			}
		}
	}


	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if(map[i][j] == 0 && !visited[i][j]) {
				bfs(i, j);
				if (cnt > 0) {
					answer.emplace_back(cnt);
				}
				cnt = 0;
			}
		}
	}

	cout << answer.size() << '\n';
	sort(answer.begin(), answer.end());
	for (int i = 0; i < answer.size(); i++) {
		cout << answer[i] << ' '; 
	}

	return 0;
} 
