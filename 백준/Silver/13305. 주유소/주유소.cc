#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>

using namespace std;

int n, tmp;
int start, end;
long long total_cost;
long long now_cost;
int dist[100000];
int cost[100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> dist[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> cost[i];
    }
   
    now_cost = cost[0];
    total_cost = now_cost * dist[1];

    for (int i = 1; i < n; i++) {
        if (cost[i] < now_cost) {
            now_cost = cost[i];
            total_cost += now_cost * dist[i+1];
        }
        else {
            total_cost += now_cost * dist[i+1];
        }
    }

    cout << total_cost << '\n';
    return 0;
}    