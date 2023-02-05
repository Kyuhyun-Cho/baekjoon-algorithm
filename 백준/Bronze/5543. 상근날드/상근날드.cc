#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <queue>
#include <string.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int min_a = 100000;
	int min_b = 100000;
	for (int i = 0; i < 3; i++) {
		int tmp; cin >> tmp;
		if (tmp < min_a) min_a = tmp;
	}
	for (int i = 0; i < 2; i++) {
		int tmp; cin >> tmp;
		if (tmp < min_b) min_b = tmp;
	}
	cout << min_a + min_b - 50 << '\n';
}   
