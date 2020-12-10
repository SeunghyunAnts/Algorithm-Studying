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
	
	while(tc--) {
		int n, stop;
		cin >> n;

		bool turn = false, t = false;
		int prev;
		vector<int> a;

		for(int i = 0; i < n; i++) {
			int num;
			cin >> num;
			a.push_back(num);
		}

		for(int i = a.size() - 1; 0 <= i; i--) {
			if(i == a.size() - 1) {
				prev = a[i];
			} else if(!turn) {
				if(prev > a[i]) {
					turn = true;
					if(i == a.size() - 2) t = true;
					if(i == 0) stop = -1;
				}
				prev = a[i];
			} else {
				if(prev < a[i]) {
					stop = i;
					t = false;
					break;
				} else if(i == 0) {
					stop = -1;
				}
				prev = a[i];
			}
		}

		if(!turn) {
			// 전체가 내림차순
			cout << "0\n";
		} else {
			if(t) {
				// 전체가 오름차순
				cout << "0\n";
			} else {
				cout << stop + 1 <<"\n";
			}
		}
	}

	return 0;
}