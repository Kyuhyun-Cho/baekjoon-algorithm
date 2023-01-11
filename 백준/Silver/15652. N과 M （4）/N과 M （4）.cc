#include <iostream>

using namespace std;

int n, m;
int arr[9];

void dfs(int num, int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
        
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
        if (i < arr[v-1]) continue;
		arr[v] = i;
		dfs(num, v+1);
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}