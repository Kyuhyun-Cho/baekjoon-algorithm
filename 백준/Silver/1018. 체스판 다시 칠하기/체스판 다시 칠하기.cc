#include <iostream>
#include <string>

using namespace std;

string WB[8] = {"WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW"};

string BW[8] = {"BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB",
                "BWBWBWBWBW",
                "WBWBWBWBWB"};

string board[50];

int WB_calc(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[x+i][y+j] != WB[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int BW_calc(int x, int y) {
    int cnt = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if(board[x+i][y+j] != BW[i][j]) {
                cnt++;
            }
        }
    }
    return cnt;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
    
    int n, m;
    cin >> n >> m;

    int min_answer = 99999;

    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        board[i] = tmp;
    }
    
    for (int i = 0; i + 8 <= n; i++) {
        for (int j = 0; j + 8 <= m; j++) {
            int answer;
            answer = min(WB_calc(i, j), BW_calc(i, j));
            if (answer < min_answer) {
                min_answer = answer;
            }
        }
    }

    cout << min_answer << '\n';
}
