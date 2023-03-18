#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <deque>
#include <set>

using namespace std;

int arr[1001];
int dp[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        dp [i] = arr[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + arr[i]);
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