#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	queue<int> q;
	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= n; i++) {
		q.push(i);
	}
	int cnt = 0;
	cout << "<";
	while(!q.empty()) {
		int people = q.front();
		q.pop();
		cnt++;
		if(k <= cnt) {
			cnt = 0;
			cout << people;
			if(!q.empty()) cout << ", ";
		}
		else {
			q.push(people);
		}
	}
	cout << ">";

	return 0;
}