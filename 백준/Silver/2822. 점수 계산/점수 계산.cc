#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	map<int, int> scores;
	int score;
	for (int i = 1; i <= 8; i++) {
		cin >> score;
		scores.insert({score, i});
	}

	vector<int> answer;
	vector<int> seq;
	vector<int> total_scores;
	int total_score = 0;
	for (auto iter = scores.begin(); iter != scores.end(); iter++) {
		total_scores.emplace_back(iter->first);
		answer.emplace_back(iter->second);
	}

	for (int i = 7; i > 2; i--) {
		total_score += total_scores[i];
	}

	for (int i = 3; i < 8; i++) {
		seq.emplace_back(answer[i]);
	}
	sort(seq.begin(), seq.end());

	cout << total_score << '\n';
	for (int i = 0; i < seq.size(); i++) {
		cout << seq[i] << ' ';
	}	
	
	cout << '\n';	
	return 0;
}