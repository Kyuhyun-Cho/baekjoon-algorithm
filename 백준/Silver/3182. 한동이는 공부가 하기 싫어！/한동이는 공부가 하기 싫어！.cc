#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int n;
vector<int> vec[1001];
bool visited[1001];
int answer[1001];
int cnt;

void dfs(int x) {
	cnt++;
	visited[x] = true;

	int next_x = vec[x][0];
	if (!visited[next_x]) {
		dfs(next_x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		vec[i].emplace_back(tmp);
	}
	
	for (int i = 1; i <= n; i++) {
		dfs(i);
		answer[i] = cnt;
		cnt = 0;
		memset(visited, false, sizeof(visited));
	}

	int max = -1;
	int idx = 0;
	for (int i = 1; i <= n; i++) {
		if (answer[i] > max) {
			max = answer[i];
			idx = i;
		}
	}
	cout << idx << '\n';
}