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

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	vector<int> pnum;
	bool isPrime[1000000 + 1];
	memset(isPrime, true, sizeof(isPrime));
	isPrime[1] = isPrime[0] = false;
	for(int i = 2; i <= 1000000; i++) {
		if(!isPrime[i]) continue;
		pnum.push_back(i);
		for(int j = 2; i * j <= 1000000; j++) {
			isPrime[i * j] = false;
		}
	}

	while(tc--) {
		int n;
		cin >> n;
		if(n % 2 == 0) {
			cout << n / 2 << " " << n / 2;
		} else {
			bool curNumisPrime = true;
			int minimunP = 0, pdiv = 0;
			for(int i = 0; i < pnum.size(); i++) {
				if(pnum[i] == n) {
					// 소수인경우
					break;
				} else if(n % pnum[i] == 0) {
					// 소수가 아닌경우
					curNumisPrime = false;
					minimunP = pnum[i];
					pdiv = n / pnum[i];
					break;
				}
			}

			if(curNumisPrime) {
				cout << 1 << " " << n - 1;
			} else {
				if(pdiv % 2 == 0) {
					cout << minimunP * pdiv / 2 << " " << minimunP * pdiv / 2;
				} else {
					cout << n / minimunP << " " << (n / minimunP) * (minimunP - 1);
				}
			}
		}

		cout << "\n";
	}

	return 0;
}