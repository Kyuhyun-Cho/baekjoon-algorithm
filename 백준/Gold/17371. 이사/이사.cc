#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<pair<int, int>> vec;

double calcDis(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		vec.push_back({ x,y });
	}
	
	int idx;
	double mindis = INFINITY;
	
	for (int i = 0; i < n; i++) {
		double maxdis = -INFINITY;
		for (int j = 0; j < n; j++) {
			if (maxdis < calcDis(vec[i].first, vec[i].second, vec[j].first, vec[j].second))
				maxdis = calcDis(vec[i].first, vec[i].second, vec[j].first, vec[j].second);
		}
		if (mindis > maxdis) {
			mindis = maxdis;
			idx = i;
		}
	}
	cout << vec[idx].first << ' ' << vec[idx].second << '\n';
}
