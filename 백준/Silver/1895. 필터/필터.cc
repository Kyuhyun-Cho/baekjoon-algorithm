#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <stack>
#include <queue>

using namespace std;

int r, c, t;
int cnt;
int arr[41][41];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    } 
    cin >> t;
    for (int i = 0; i < r-2; i++) {
        for (int j = 0; j < c-2; j++) {
            vector<int> vec;
            vec.emplace_back(arr[i][j]);
            vec.emplace_back(arr[i][j+1]);
            vec.emplace_back(arr[i][j+2]);
            vec.emplace_back(arr[i+1][j]);
            vec.emplace_back(arr[i+1][j+1]);
            vec.emplace_back(arr[i+1][j+2]);
            vec.emplace_back(arr[i+2][j]);
            vec.emplace_back(arr[i+2][j+1]);
            vec.emplace_back(arr[i+2][j+2]);
            sort(vec.begin(), vec.end());
            if (vec[4] >= t) cnt++;
        }
    }
    cout << cnt;
}