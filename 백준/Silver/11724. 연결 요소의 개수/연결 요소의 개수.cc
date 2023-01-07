#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n , m;
int cnt;
vector<int> board[1001];
bool visited[1001];

void dfs(int x) {
	visited[x] = true;
	for (int i = 0; i < board[x].size(); i++) {
		int y = board[x][i];
		if (!visited[y]) {
			dfs(y);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> m;

	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		board[u].emplace_back(v);
		board[v].emplace_back(u);
	}

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
}