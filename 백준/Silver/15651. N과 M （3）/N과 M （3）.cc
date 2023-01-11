#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		arr[v] = i;
		dfs(v+1);
	}
}

int main() {
	cin >> n >> m;
	dfs(0);
}