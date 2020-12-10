#include <bits/stdc++.h>
// 2의 제곱수 판정
#define POW2(X) (X) == ((X)&(-(X)))

// 기본설정
typedef long long ll;
using namespace std;
int dirx[4] = {1, 0, -1, 0};
int diry[4] = {0, 1, 0, -1};

// 전역변수

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int maxnum = 1000000;
	bool prime[1000000 + 1];
	memset(prime, 1, sizeof(prime));
	prime[0] = prime[1] = false;
	vector<int> pnum;
	for(int i = 2; i < 1000000 + 1; i++) {
		if(!prime[i]) continue;
		pnum.push_back(i);
		for(int j = 2; i * j < 1000000 + 1; j++) {
			prime[i * j] = false;
		}
	}

	int tc;
	cin >> tc;
	while(tc--) {
		int n;
		bool nprime = true;
		cin >> n;

		for(int i = 0; i < pnum.size(); i++) {
			if((int)sqrt(n) < pnum[i]) break;
			if(n % pnum[i] == 0) {
				nprime = false;
				break;
			}
		}
		if(n == 1) {
			cout << "FastestFinger\n";
		} else if(nprime) {
			cout << "Ashishgup\n";
		} else if(n % 2 == 1) {
			cout << "Ashishgup\n";
		} else {
			if(POW2(n)) {
				cout << "FastestFinger\n";
			} else {
				int cur = n;
				int tcnt = 0;
				while(1 < cur && cur % 2 == 0) {
					cur /= 2;
					tcnt++;
				}
				if(1 < tcnt) {
					// n에 2가 2개이상 있음. - n을 2의 배수로 만듬
					cout << "Ashishgup\n";
				} else {
					// n에 2가 1개만 있음.
					n = n / 2;
					bool nextisprime = true;

					for(int i = 0; i < pnum.size(); i++) {
						if((int)sqrt(n) < pnum[i]) break;
						if(n % pnum[i] == 0) {
							if(n / pnum[i] == 1) {
								nextisprime = true;
							} else {
								nextisprime = false;
							}
							break;
						}
					}

					if(nextisprime) {
						cout << "FastestFinger\n";
					} else {
						cout << "Ashishgup\n";
					}
				}
			}
		}
	}
	
	
	return 0;
}