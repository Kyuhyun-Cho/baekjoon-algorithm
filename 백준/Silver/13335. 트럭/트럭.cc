#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <algorithm>

using namespace std;

int n, w, l;
int cnt = 1;
vector<pair<int,int>> vec;
vector<int> truck;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> w >> l;

	for (int i = 0; i < n; i++) {
		int weight; cin >> weight;
		truck.push_back(weight);
	}

	vec.push_back({truck[0], 1});
	truck.erase(truck.begin());
	
	while(!vec.empty()) {
		cnt += 1;
		for (int i = 0; i < vec.size(); i++) {
			vec[i].second = vec[i].second + 1;
		}

		if (vec[0].second > w) {
			vec.erase(vec.begin());
		}
		
		int total_weight = 0;
		for (int i = 0; i < vec.size(); i++) {
			total_weight += vec[i].first;
		} 

		if (!truck.empty()) {
			if(total_weight + truck[0] <= l) {
				vec.push_back({truck[0], 1});
				truck.erase(truck.begin());
			}
		}
	}

	cout << cnt << '\n';
}