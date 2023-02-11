#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int coin[4] = {25, 10, 5, 1};
	int t; cin >> t;
	
	for (int test_case = 0; test_case < t; test_case++) {
		int cnt[4] = {0, 0, 0, 0};
		int cost; cin >> cost;
		for (int i = 0; i < 4; i++) {
			if (cost / coin[i] > 0) {
				cnt[i] += cost / coin[i];
				cost -= coin[i] * cnt[i];
			}
		}

		for (int i = 0; i < 4; i++) {
			cout << cnt[i] << ' ';
		}
		cout << '\n';
	} 
}