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
		int n, maxnum = 0, ans = 0;
		cin >> n;
		vector<int> numbers(n + 1, 0);
		for(int i = 0; i < n; i++) {
			int num; cin >> num;
			numbers[num]++;
			if(maxnum < num) {
				maxnum = num;
			}
		}

		for(int i = 2; i <= maxnum * 2; i++) {
			// i : 현재 무게의 합
			int curcnt = 0;
			vector<int> cur;
			cur.resize(n + 1);
			copy(numbers.begin(), numbers.end(), cur.begin());

			cout << "cur : " << i << "\n";
			
			for(int j = 1; j <= n; j++) {
				if(i < j) {
					break;
				}
				int p = i - j;
				while(cur[j] > 0 && cur[p] > 0) {s
					cout << j << " " << p << "\n";
					cur[j]--; cur[p]--;
					curcnt++;
				}
			}

			if(ans < curcnt) {
				ans = curcnt;
			}
		}

		cout << ans << "\n";
	}

	return 0;
}