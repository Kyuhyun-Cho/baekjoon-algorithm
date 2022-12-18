#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int graph[101][101];
bool visited[101];

int N;

void dfs(int v) {
	for (int i = 0; i < N; i++) {
		if(graph[v][i] == 1 && visited[i] == false) {
			visited[i] = true;
			dfs(i);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> graph[i][j];
		}
	}

	for (int i = 0; i < N; i++) {
		memset(visited, false, sizeof(visited));
		dfs(i);
		for (int j = 0; j < N; j++) {
			if(visited[j] == true) {
				graph[i][j] = 1;
			}
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << graph[i][j] << ' ';
		}
		cout << '\n';
	}
}