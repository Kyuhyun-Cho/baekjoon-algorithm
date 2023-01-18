#include <iostream>
#include <algorithm>

using namespace std;

int n; 
int dp[1001][3]{};
int arr[1001][3]{};

int main() {
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> arr[i][0];
        cin >> arr[i][1];
        cin >> arr[i][2];
    }
    for (int i = 1; i <= n; i++) {
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + arr[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + arr[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + arr[i][2]; 
    }
    int answer = min(dp[n][0], dp[n][1]);
    answer = min(answer, dp[n][2]);

    cout << answer << '\n';
}    