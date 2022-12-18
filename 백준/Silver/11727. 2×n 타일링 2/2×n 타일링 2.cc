#include <iostream>

using namespace std;

int dp[1001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n;
	cin >> n;

	dp[0] = 0; 
	dp[1] = 1;
	dp[2] = 3;

	for (int i = 3; i <= n; i++) {
		if (i % 2 == 1) {
			for (int j = 1; j < i; j++) {
				dp[i] += dp[j];
			}
			dp[i] = (dp[i] + 1) % 10007;
		}
		if (i % 2 == 0) {
			for (int j = 1; j < i; j++) {
				dp[i] += dp[j];
			}
			dp[i] = (dp[i] + 2) % 10007;
		}
		
	}

	cout << dp[n] << '\n';
}