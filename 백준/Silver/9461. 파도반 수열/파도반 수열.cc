#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	long long dp[101] = {0,};
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 1;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		for (int j = 4; j <= num; j++) {
			dp[j] = dp[j-3] + dp[j-2];
		}
		cout << dp[num] << '\n';
	}
} 