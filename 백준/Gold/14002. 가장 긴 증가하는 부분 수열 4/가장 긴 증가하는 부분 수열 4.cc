#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <set>

using namespace std;

int arr[1001];
int dp[1001];
vector<vector<int>> vec(1001);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        vec[i].emplace_back(arr[i]);
        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && vec[j].size() + 1 > vec[i].size()) {
                vec[i].clear();
                vec[i].emplace_back(arr[i]);
                for (int k = 0; k < vec[j].size(); k++) {
                    vec[i].emplace_back(vec[j][k]);
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < vec[i].size(); j++) {
    //         cout << vec[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
    int cnt = 0;
    int idx = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i].size() > cnt) {
            cnt = vec[i].size();
            idx = i;
        }
    }

    cout << cnt << '\n';
    for (int i = vec[idx].size() - 1; i >= 0; i--) {
        cout << vec[idx][i] << ' ';
    } 
}