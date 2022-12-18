#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>

using namespace std;

int dp[50001];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m;
	cin >> n >> m;

	set<string> a;
	vector<string> b;

	string tmp;
	for(int i=0; i<n; i++) {
		cin >> tmp;
		a.insert(tmp);
	}
	for(int i=0; i<m; i++) {
		cin >> tmp;
		b.emplace_back(tmp);
	} 
	sort(b.begin(), b.end());

	vector<string> answer;

	for(int i=0; i<m; i++) {
		if(a.count(b[i]) == 1) {
			answer.emplace_back(b[i]);
		}
	}
	cout << answer.size() << '\n';
	for (int i=0; i<answer.size(); i++) {
		cout << answer[i] << '\n';
	}
}