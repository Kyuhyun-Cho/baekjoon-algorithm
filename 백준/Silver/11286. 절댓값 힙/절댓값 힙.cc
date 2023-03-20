#include <iostream>
#include <vector>
#include <cmath>
#include <queue>

using namespace std;

struct cmp {
	bool operator() (int x, int y) {
		if (abs(x) == abs(y)) {
			return x > y;
		}
		else {
			return abs(x) > abs(y);
		}
	}
};

priority_queue<int, vector<int>, cmp> pq;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;

	while(n--) {
		int x;
		cin >> x;

		if (x != 0) {
			pq.push(x);
		}
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
	}
}