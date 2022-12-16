#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;

    int area[h][w]{};
    
    string tmp;
    for (int i = 0; i < h; i++) {
        cin >> tmp;
        for (int j = 0; j < w; j++) {
            if (tmp[j] == '.') {
                area[i][j] = -1;
            }
        }
    }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (j != w-1 && area[i][j] != -1 && area[i][j+1] != 0) {
                area[i][j+1] = area[i][j] + 1;
            }
        }
    }
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cout << area[i][j] << ' ';
        }
        cout << '\n';
    }
}