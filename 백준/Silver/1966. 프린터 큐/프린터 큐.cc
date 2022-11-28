#include <iostream>
#include <queue>

using namespace std;

int main() {
	int testCase;
	cin >> testCase;

	int docCnt, targetDoc, importancy;
	for (int t = 0; t < testCase; t++) {
		int cnt = 0;
		cin >> docCnt >> targetDoc;
		queue<pair<int, int>> q;
		priority_queue<int> pq;

		for (int i = 0; i < docCnt; i++) {
			cin >> importancy;
			q.push({i, importancy});
			pq.push(importancy);
		}
		while(!q.empty()) {
			int idx = q.front().first;
			int val = q.front().second;
			q.pop();
			if (pq.top() == val) {
				pq.pop();
				++cnt;
				if (idx == targetDoc) {
					cout << cnt << '\n';
					break;
				}
			}
			else q.push({idx, val});
		}
		

	}
}