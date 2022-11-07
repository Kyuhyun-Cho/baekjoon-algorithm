#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n, t;
	cin >> n >> t;

	queue<int> q;
	vector<int> answer;
	for (int i = 1; i < n+1; i++) {
		q.push(i);
	}
	
	while(!q.empty()) {
		for (int i = 0; i < t-1; i++) {
			q.push(q.front());
			q.pop();
		}
	
		answer.push_back(q.front());
		q.pop();
	}

	cout << "<";
	for (int i = 0; i < answer.size() - 1; i++) {
		cout << answer[i] << ", ";
	}
	cout << answer.back() << ">";
}