#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int a, b, c;
	cin >> a >> b >> c;
	vector<int> vec;
	vec.emplace_back(a);
	vec.emplace_back(b);
	vec.emplace_back(c);
	sort(vec.begin(), vec.end());
	for(int i = 0; i < 3; i++) {
		cout << vec[i] << ' ';
	}
	cout << '\n';
	return 0;
} 
