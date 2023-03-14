#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct Que {
	int f;
	int y;
	int x;
	int cnt;
};

int l, r, c;
char map[31][31][31];
int cnt_map[31][31][31];
bool visited[31][31][31];

int sf, sy, sx;
int ef, ey, ex;

bool arrived = false;

int df[6] = {-1, 1, 0, 0, 0, 0};
int dy[6] = {0, 0, -1, 0, 1, 0};
int dx[6] = {0, 0, 0, 1, 0, -1};

bool validCheck(int nf, int ny, int nx) {
	if (0 <= nf && nf < l && 0 <= ny && ny < r && 0 <= nx && nx < c) {
		if (!visited[nf][ny][nx] && map[nf][ny][nx] != '#') {
			return true;
		}
	}
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	while (true) {
		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			break;
		}
		
		queue<Que> q;
		memset(map, ' ', sizeof(map));
		memset(visited, false, sizeof(visited));
		memset(cnt_map, 0, sizeof(cnt_map));
		arrived = false;
	
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> map[i][j][k];
					if (map[i][j][k] == 'S') {
						sf = i; sy = j; sx = k;
					}
					if (map[i][j][k] == 'E') {
						ef = i; ey = j; ex = k;
					}
				}
			}
		}

		visited[sf][sy][sx] = true;
		q.push({sf, sy, sx, 0});
		cnt_map[sf][sy][sx] = 0;
		
		while(!q.empty()) {
			auto cur = q.front();
			q.pop();
			cnt_map[cur.f][cur.y][cur.x] = cur.cnt;
			if (map[cur.f][cur.y][cur.x] == 'E') {
				arrived = true;
			}
			// cout << f << ' ' << y << ' ' << x <<'\n';
			
		
			for (int i = 0; i < 6; i++) {
				int nf = cur.f + df[i];
				int ny = cur.y + dy[i];
				int nx = cur.x + dx[i];
				
				if (validCheck(nf, ny, nx)) {
					q.push({nf, ny, nx, cur.cnt+1});
					visited[nf][ny][nx] = true;
				}
			}
		}	

		if (arrived) {
			cout << "Escaped in " << cnt_map[ef][ey][ex] << " minute(s)." << '\n';
		}
		else {
			cout << "Trapped!" << '\n';
		}
		// for (int i = 0; i < l; i++) {
		// 	for (int j = 0; j < r; j++) {
		// 		for (int k = 0; k < c; k++) {
		// 			cout << cnt_map[i][j][k] << '\t';
		// 		}
		// 		cout << '\n';
		// 	}
		// 	cout << '\n';
		// }	
	}
}
	