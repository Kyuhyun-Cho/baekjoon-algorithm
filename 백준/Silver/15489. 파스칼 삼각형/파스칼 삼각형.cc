#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, w;
    cin >> r >> c >> w;
    int board[r-1+w][r-1+w]{};
    int level = 0;
    for (int i = 0; i < (r-1)+w; i++) {
        level++;
        for (int j = 0; j < level; j++) {
            if (j == 0 || j == (level-1) ) {
                board[i][j] = 1;
            }
            else {
                board[i][j] = board[i-1][j-1] + board[i-1][j];
            }
       }
    }

    int answer = 0;

    level = 0;
    for (int i = r-1; i < (r-1)+w; i++) {
        level++;
        for (int j = c-1; j < (c-1)+level; j++) {
            answer += board[i][j];
        }
    }

    cout << answer << '\n';

    return 0;
}