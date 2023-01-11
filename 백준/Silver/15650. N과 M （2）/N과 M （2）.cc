#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool visited[9];

void dfs(int num, int v) {
	if (v == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = num; i <= n; i++) {
		if(!visited[i]) {
			visited[i] = true;
			arr[v] = i;
			dfs(i+1, v+1);
			visited[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	dfs(1, 0);
}