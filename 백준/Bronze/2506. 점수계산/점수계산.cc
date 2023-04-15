#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;
    int cnt = 1;
    int score = 0;
    cin >> n;
    int tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        if (tmp == 1) {
            score += cnt++;
        }
        else {
            cnt = 1;
        }
    }
    cout << score;
}