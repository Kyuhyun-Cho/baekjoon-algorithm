#include <iostream>
#include <algorithm>
#include <cmath>
#include <string.h>

using namespace std;

int w = -1;
int h = -1;
int map[51][51];
bool visited[51][51];

int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};

bool validCheck(int y, int x) {
	if (0 <= y && y < h && 0 <= x && x < w && !visited[y][x]) {
		return true;
	}
	return false;
}

void bfs(int y, int x) {
	visited[y][x] = true;
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (validCheck(ny, nx)) {
			if (map[ny][nx] == 1) {
				bfs(ny, nx);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while(true) {
		cin >> w >> h;
		if (w == 0 && h == 0) {
			break;
		}

		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		
		int cnt = 0;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> map[i][j];
			}
		} 

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (map[i][j] == 1 && !visited[i][j]) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		
		cout << cnt << '\n';
	}	
}