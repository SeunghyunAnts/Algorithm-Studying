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

	int n;
	cin >> n;
	int a[n + 1];
	vector<int> ans;
	bool check[1000000 + 1] = {false};
	bool checkprev[1000000 + 1] = {false};
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		check[a[i]] = true;
	}

	for(int i = 1; i <= n; i++) {
		if(i == 1 && !check[0]) {
			ans.push_back(0);
			check[0] = true;
			checkprev[0] = true;
		} else {
			
		}
	}

	return 0;
}