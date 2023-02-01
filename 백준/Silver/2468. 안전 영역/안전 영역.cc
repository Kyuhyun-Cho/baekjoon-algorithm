#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int n;
int max_num = -999;
int map[101][101];
bool visited[101][101];
int cnt = 0;
vector<int> safety_area;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

bool validCheck(int y, int x) {
	if (0 <= y && y < n && 0 <= x && x < n && !visited[y][x]) {
		return true;
	}
	return false;
} 

void bfs(int y, int x, int height) {
	visited[y][x] = true;

	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (validCheck(ny, nx)) {
			if (map[ny][nx] > height) {
				bfs(ny, nx, height);
			} 
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
			if (map[i][j] > max_num) {
				max_num = map[i][j];
			} 
		}
	}
	
	for (int h = 1; h <= max_num; h++) {
		memset(visited, false, sizeof(visited));
		cnt = 0;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j] && map[i][j] > h) {
					bfs(i, j, h);
					cnt++;
				}
			}
		}
		safety_area.emplace_back(cnt);
	}
	
	// for (int i = 0; i < safety_area.size(); i++) {
	// 	cout << safety_area[i] << ' ';
	// }
	int max_answer = *max_element(safety_area.begin(), safety_area.end());
	if (max_answer == 0) max_answer = 1;
	cout << max_answer << '\n';
	
	return 0;
} 
