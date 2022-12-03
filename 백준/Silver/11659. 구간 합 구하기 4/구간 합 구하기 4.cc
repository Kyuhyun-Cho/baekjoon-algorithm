#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, m;
	cin >> n >> m;

	int arr[n+1] = {0,};
	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		arr[i] = tmp;
	}

	int sum[n+1] = {0, };
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i-1] + arr[i];
	}	

	int start, end;
	for (int i = 0; i < m; i++) {
		cin >> start >> end;
		cout << sum[end] - sum[start-1] << '\n';
	}
} 