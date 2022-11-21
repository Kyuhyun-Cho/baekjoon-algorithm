#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int n;
	cin >> n;

	unordered_map<int, int> umap;
	int tmp;
	
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		if (umap.find(tmp) == umap.end()) {
			umap.insert(pair<int, int>(tmp, 1));
		}
		else {
			umap[tmp] += 1;
		}
	}

	int m;
	cin >> m;
	
	for (int i = 0; i < m; i++) {
		cin >> tmp;
		if (umap.find(tmp) == umap.end()) {
			cout << 0 << " ";
		}
		else {
			cout << umap[tmp] << " ";
		}
	}
}