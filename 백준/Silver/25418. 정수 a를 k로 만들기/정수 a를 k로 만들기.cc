#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int a, k;
int num, idx;
queue<pair<int,int>> q;
pair<int,int> p;
pair<int,int> p_;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> a >> k;
	int cnt = 0;
	p = make_pair(k, cnt);
	q.push(p);
	while(true) {
		num = q.front().first;
		idx = q.front().second;
		q.pop();
		// cout << num << ' ' << idx << '\n';
		if (num == a) {
			cout << idx << '\n';
			break;
		}
		
		if(num % 2 == 0 && num >= a*2) {
			p_ = make_pair(num/2, idx+1);
		}
		else {
			p_ = make_pair(num-1, idx+1);
		}
		q.push(p_);
	}
}