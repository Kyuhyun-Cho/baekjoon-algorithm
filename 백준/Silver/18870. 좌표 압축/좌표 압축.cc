#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
	
int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);

	int n; cin >> n;
	map<int, int> m;
	vector<int> vec;
	vector<int> v;
	
	int k;
	for (int i = 0; i < n; i++) {
		cin >> k;
		m[k] = 0;
		vec.emplace_back(k);
		v.emplace_back(k);
	}
	
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(),v.end()),v.end());
	
	for (int i = 0; i < v.size(); i++) {
		int start = 0;
		int end = v.size();
		int cnt = 0;
		
		while(start <= end) {
			int mid = (start+end)/2;
			if (v[mid] == v[i]) {
				cnt += mid - start;
				m[v[i]] += cnt;
				break;
			}
			else if (v[mid] > v[i]) {
				end = mid - 1;
			}
			else if (v[mid] < v[i]) {
				cnt += mid + 1 - start;
				start = mid + 1;
			}
		}
	}

	for (int i = 0; i < vec.size(); i++) {
		cout << m[vec[i]] << ' ';
	}
}