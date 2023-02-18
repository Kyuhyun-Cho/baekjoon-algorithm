#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <deque>

using namespace std;

int t, n;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> t;
	for (int test_case = 0; test_case < t; test_case++) {
		cin >> n;
		vector<int> vec;
		deque<int> dq;
		for (int i = 0; i < n; i++) {
			int tmp; cin >> tmp;
			vec.emplace_back(tmp);
		}
		sort(vec.begin(), vec.end());

		if (vec.size() % 2 == 1) {
			dq.push_front(vec.back());
			vec.pop_back();
		}
		int vec_size = vec.size() / 2;
		for (int i = 0; i < vec_size; i++) {
			dq.push_front(vec.back());
			vec.pop_back();
			dq.push_back(vec.back());
			vec.pop_back();
		}

		vector<int> gap;
		for (int i = 0; i < dq.size() - 1; i++) {
			gap.emplace_back(abs(dq[i+1]-dq[i]));
		}
		gap.emplace_back(abs(dq.front()-dq.back()));
		int max = -1;
		for (int i = 0; i < gap.size(); i++) {
			if (gap[i] > max) {
				max = gap[i];
			}
		}
		cout << max << '\n';
	}
	
}