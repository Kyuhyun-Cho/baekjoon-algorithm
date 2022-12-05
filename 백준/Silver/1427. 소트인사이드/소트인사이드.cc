#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;

	vector<int> v;
	
	while(n > 0) {
		v.emplace_back(n % 10);
		n = n / 10;
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i];
	}
} 