#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int cost; cin >> cost;
	cost = 1000 - cost;
	
	int cnt = 0;
	int coin[6] = {500, 100, 50, 10, 5, 1};
	for (int i = 0; i < 6; i++) {
		if (cost / coin[i] > 0) {
			int tmp = cost / coin[i];
			cnt += tmp;
			cost -= coin[i] * tmp;
		}
	}
	cout << cnt << '\n';
}