#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
char map[65][65];
vector<char> answer;

void div(int y, int x, int size) {
    int same = true;
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if (map[i][j] != map[y][x]) {
                same = false;
                break;
            }
        }
        if (!same) {
            break;
        }
    }
    if (!same) {
        answer.emplace_back('(');
        div(y, x, size/2);
        div(y, x+size/2, size/2);
        div(y+size/2, x, size/2);
        div(y+size/2, x+size/2, size/2);
        answer.emplace_back(')');
    }
    else {
        answer.emplace_back(map[y][x]);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> map[i][j];
        }
    }

    div(0, 0, n);

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i];
    }
}