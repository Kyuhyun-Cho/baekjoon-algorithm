#include <iostream>
#include <algorithm>
#include <queue>
#include <string.h>

using namespace std;

struct Tomato {
	int x;
	int y;
	int f;
};

int m, n, h, answer;
int map[101][101][101];
queue<Tomato> q;

int dx[6] = {0, -1, 0, 1, 0, 0};
int dy[6] = {-1, 0, 1, 0, 0, 0};
int df[6] = {0, 0, 0, 0, 1, -1};

void bfs() {
	while(!q.empty()) {
		Tomato t;
		t.f = q.front().f;
		t.y = q.front().y;
		t.x = q.front().x;
		q.pop();

		for (int i = 0; i < 6; i++) {
			int next_f = t.f + df[i];
			int next_y = t.y + dy[i];
			int next_x = t.x + dx[i];
			
			if (0 <= next_f && next_f <= h && 0 <= next_x && next_x <= m && 0 <= next_y && next_y <= n &&  map[next_f][next_y][next_x] == 0) {
				map[next_f][next_y][next_x] = map[t.f][t.y][t.x] + 1;
				Tomato t;
				t.f = next_f;
				t.y = next_y;
				t.x = next_x;
				q.push(t);
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(map, -1, sizeof(map));
	cin >> m >> n >> h;
	
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					Tomato t;
					t.f = i;
					t.y = j;
					t.x = k;
					q.push(t);
				}
			}
		}
	}
		
	bfs();
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				// cout << map[i][j][k] << ' ';
				if (map[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				if (map[i][j][k] > answer) {
					answer = map[i][j][k];
				}
			}
			// cout << '\n';
		}
	}

	cout << answer - 1 << '\n';
}