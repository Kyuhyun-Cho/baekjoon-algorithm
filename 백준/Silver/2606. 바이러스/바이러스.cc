#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> answer;
int graph[101][101];
bool visited[101]{};

void dfs(int v) {
	visited[v] = true;
	answer.emplace_back(v);
	// cout << v << '\n';
	for(int i = 1; i <= N; i++) {
		if(graph[v][i] == 1 && visited[i] == false) {
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	dfs(1);

	cout << answer.size() - 1 << '\n';
}