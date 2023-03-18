#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <set>

using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int arr[1001];
    int dp[1001];  fill_n(dp, 1001, 1);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    
    int answer = 0;
    for (int i = 0; i < n; i++) {
        if (dp[i] > answer) {
            answer = dp[i];
        }
    }
    cout << answer << '\n';
}