#include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	priority_queue<int, vector<int>, less<int>> pq;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;

		if (num == 0) {
			if(pq.size() > 0) {
				cout << pq.top() << '\n';
				pq.pop();
			}
			else {
				cout << 0 << '\n';
			}
		}
		else {
			pq.push(num);
		}
	}
}