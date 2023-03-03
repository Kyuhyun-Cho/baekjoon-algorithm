#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int map[501][501];
bool visited[501][501];
vector<int> picture;
int pic_size;
int max_size = -1;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void bfs(int y, int x) {
    pic_size++;
    visited[y][x] = true;

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (0 <= ny && ny < n && 0 <= nx && nx < m && !visited[ny][nx] && map[ny][nx] == 1) {
            bfs(ny, nx);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if(!visited[i][j] && map[i][j] == 1) {
                bfs(i, j);
                picture.emplace_back(pic_size);
                pic_size = 0;
            }
        }
    }

    if (picture.size() == 0) {
        cout << 0 << '\n';
        cout << 0 << '\n';
        return 0;
    }
    
    for (int i = 0; i < picture.size(); i++) {
        if (picture[i] > max_size) {
            max_size = picture[i];
        }
    }
    
    cout << picture.size() << '\n';
    cout << max_size << '\n';
}