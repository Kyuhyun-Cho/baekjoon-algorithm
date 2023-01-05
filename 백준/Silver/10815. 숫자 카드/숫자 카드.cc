#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int n; cin >> n;
	int cards[n];
	for (int i = 0; i < n; i++) {
		cin >> cards[i];
	}
	sort(cards, cards+n);
	
	int m; cin >> m;

	for (int i = 0; i < m; i++) {
		int start = 0;
		int end = n-1;

		int target; cin >> target;
		bool answer = false;
		while(start <= end) {
			int mid = (start+end) / 2;
			if (cards[mid] > target) {
				end = mid - 1;
			}
			else if (cards[mid] == target) {
				answer = true;
				break;
			}
			else {
				start = mid + 1;
			}
		}
		if (answer) cout << 1 << ' ';
		else cout << 0 << ' ';
	}
}