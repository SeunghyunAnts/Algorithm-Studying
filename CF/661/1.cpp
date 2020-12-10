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
		int s;
		vector<int> v;

		cin >> s;
		for(int i = 0; i < s; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}

		sort(v.begin(), v.end());

		int le = 0, ri = s - 1;
		for(int i = 0; i < s - 1; i++) {
			if(v[i + 1] - v[i] <= 1) {
				le++;
			} else {
				break;
			}
		}

		for(int i = s - 1; i > 0; i--) {
			if(v[i] - v[i - 1] <= 1) {
				ri--;
			} else {
				break;
			}
		}
		
		if(le == ri || le == s - 1 || ri == 0) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}

	return 0;
}