#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t, s;
	cin >> t >> s;
	if (t <= 11 || 16 < t || s == 1) {
		cout << 280;
	}
	else {
		cout << 320;
	}
}