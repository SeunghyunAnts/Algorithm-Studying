#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))
// int pair 간단히
#define pii pair<int, int>
#define mp(X, Y) make_pair(X, Y)

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int n, m, k;
int price[10000 + 1] = {0};
int friends[10000 + 1] = {0};
bool check[10000 + 1] = {false};

int find_parent(int node) {
	if(friends[node] == node) {
		return node;
	} else {
		return friends[node] = find_parent(friends[node]);
	}
}

void make_friends(int p1, int p2) {
	p1 = find_parent(p1);
	p2 = find_parent(p2);

	if(price[p1] < price[p2]) friends[p2] = p1;
	else if(price[p1] == price[p2]) {
		if(p1 < p2) {
			friends[p2] = p1;
		} else {
			friends[p1] = p2;
		}
	} else {
		friends[p1] = p2;
	}
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) {
		cin >> price[i];
		friends[i] = i;
	}
	for(int i = 0; i < m; i++) {
		int p1, p2;
		cin >> p1 >> p2;
		make_friends(p1, p2);
	}

	int needs = 0;
	for(int i = 1; i <= n; i++) {
		int p = find_parent(i);
		if(!check[p]) {
			needs += price[p];
			check[p] = true;
		}
	}

	if(needs <= k) {
		cout << needs << "\n";
	} else {
		cout << "Oh no\n";
	}

	return 0;
}