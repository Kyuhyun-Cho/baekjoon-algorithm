#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M, V;
int map[1001][1001];
bool visited[1001]{};
queue<int> q;

void reset() {
    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }
}

void DFS(int v) {
	visited[v] = true;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visited[v] = true;
	cout << v << " ";

	while(!q.empty()) {
		v = q.front();
		q.pop();

		for (int i = 0; i <= N; i++) {
			if (map[v][i] == 1 && visited[i] == false) {
				q.push(i);
				visited[i] = true;
				cout << i << " ";
			}
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}

	reset();
	DFS(V);

	cout << '\n';

	reset();
	BFS(V);
	
	return 0;
}