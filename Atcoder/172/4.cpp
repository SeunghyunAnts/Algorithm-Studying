#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수
ll dp[10000000 + 1];
bool isPrime[100000];
map<int, int> pnum;

int main(void) {
	//cin.tie(NULL);
	//ios_base::sync_with_stdio(false);

	ll n, ans = 0;
	
	cin >> n;
	fill(isPrime, isPrime + 100000, true);
	
	dp[0] = 0;
	dp[1] = 1;
	isPrime[0] = isPrime[1] = false;

	for(int i = 2; i < 100000; i++) {
		if(isPrime[i] == true) {
			int temp = i, cnt = 1;
			while(temp < 10000000 + 1) {
				cout << temp << " ";
				dp[temp] = cnt + 1;
				temp = temp * i;
				cnt++;
			}
			cout << "\n";
			pnum.insert(make_pair(i, 1));
			for(int j = 2; i * j < 100000; j++) {
				isPrime[i * j] = false;
			}
		}
	}
	cout << dp[4] << dp[8] << "\n";

	cout << ans;

	return 0;
}