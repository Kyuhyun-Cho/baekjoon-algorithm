#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
char map[26][26];
bool visited[26][26];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int cnt;
vector<int> cnt_vec;

bool validCheck(int y, int x) {
    if (0 <= y && y < n && 0 <= x && x < n && !visited[y][x]) {
        return true;
    }
    return false;
}

void bfs(int y, int x) {
    visited[y][x] = true;
    cnt++;
    for (int i = 0; i < 4; i++) {
        int next_y = y + dy[i];
        int next_x = x + dx[i];
        if (0 <= next_y && next_y < n && 0 <= next_x && next_x < n && !visited[next_y][next_x]) {
            if (map[next_y][next_x] == '1') {
                bfs(next_y, next_x);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(map[i][j] == '1' && !visited[i][j]) {
                bfs(i, j);
                if(cnt > 0) {
                    cnt_vec.push_back(cnt);
                }
                cnt = 0;
            }
        }
    }
    sort(cnt_vec.begin(), cnt_vec.end());
    cout << cnt_vec.size() << '\n';
    for (int i = 0; i < cnt_vec.size(); i++) {
        cout << cnt_vec[i] << '\n';
    }
}