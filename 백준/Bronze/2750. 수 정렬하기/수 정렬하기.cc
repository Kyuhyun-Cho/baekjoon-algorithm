#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> vec;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		vec.emplace_back(tmp);
	}
	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; i++) {
		cout << vec[i] << '\n';
	}
}