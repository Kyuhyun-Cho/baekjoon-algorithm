#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int n, k;
queue<pair<int, int>> q;
bool visited[100001];
int answer = 100001;
int cnt;


void bfs(int n) {
	while(!q.empty()) {
		int pose = q.front().first;
		int turn = q.front().second;
		q.pop();
		visited[pose] = true;

		if (turn > answer) {
			break;
		}
		if (pose == k) {
			answer = turn;
			cnt++;
			
		}
		if ((0 <= pose-1 && pose-1 <= 100000) && !visited[pose-1]) {
			q.push({pose-1, turn+1});
		}
		if ((0 <= pose+1 && pose+1 <= 100000) && !visited[pose+1]) {
			q.push({pose+1, turn+1});
		}
		if ((0 <= pose*2 && pose*2 <= 100000) && !visited[pose*2]) {
			q.push({pose*2, turn+1});
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL), cout.tie(NULL);

	cin >> n >> k;

	q.push({n, 0});
	visited[n] = true;
	bfs(n);

	cout << answer << '\n' << cnt << '\n';
} 