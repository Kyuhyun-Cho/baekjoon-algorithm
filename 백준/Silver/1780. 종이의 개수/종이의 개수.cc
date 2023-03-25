#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int cnt1, cnt2, cnt3;
int arr[3000][3000];

void div(int y, int x, int size) {
    bool flag = true;
    for (int i = y; i < y+size; i++) {
        for (int j = x; j < x+size; j++) {
            if(arr[i][j] != arr[y][x]) {
                flag = false;
                break;
            }
        }
        if (!flag) break;
    }
    
    if(!flag) {
        div(y, x, size/3);
        div(y, x+size/3, size/3);
        div(y, x+size/3+size/3, size/3);
        div(y+size/3, x, size/3);
        div(y+size/3+size/3, x, size/3);
        div(y+size/3, x+size/3, size/3);
        div(y+size/3+size/3, x+size/3+size/3, size/3);
        div(y+size/3+size/3, x+size/3, size/3);
        div(y+size/3, x+size/3+size/3, size/3);
    }
    else {
        if (arr[y][x] == -1) cnt1++;
        else if (arr[y][x] == 0) cnt2++;
        else if (arr[y][x] == 1) cnt3++;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }
    div(0, 0, n);
    cout << cnt1 << '\n' << cnt2 << '\n' << cnt3 << '\n';
}