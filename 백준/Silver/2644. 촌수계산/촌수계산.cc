#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int start, arrived;
int cnt;
vector<int> vec[101];
bool visited[101];

void dfs(int now, int depth) {
	visited[now] = true;
	if (now == arrived) {
		cnt = depth;
	}
	for (int i = 0; i < vec[now].size(); i++) {
		int next = vec[now][i];
		if (!visited[next]) {
			dfs(next, depth+1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	cin >> start >> arrived;
	cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		vec[a].emplace_back(b);
		vec[b].emplace_back(a);
	}

	dfs(start, 0);
	if (cnt != 0) {
		cout << cnt << '\n';
	}
	else {
		cout << -1 << '\n';
	}
}
	