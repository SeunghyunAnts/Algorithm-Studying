#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

struct sse {
	int size, stt, end;
	sse(int a, int b, int c) {
		size = a;
		stt = b;
		end = c;
	}
};

struct comp {
	bool operator()(const sse &u, const sse &v) {
		if(u.size == v.size) {
			return u.stt > v.end;
		} else {
			return u.size < v.size;
		}
	}
};

int arr[2 * 100000 + 1];
priority_queue<sse, vector<sse>, comp> pq;
int n;

void bfs(int cnt) {
	if(pq.empty()) return;	// stop

	int s = pq.top().stt;
	int e = pq.top().end;
	int sze = pq.top().size;
	
	pq.pop();

	if(s > e) return;

	if(sze == 1) {
		// s == e
		if(arr[s] == 0) arr[s] = cnt;
		bfs(cnt + 1);
	} else if(sze % 2 == 0) {
		// size is even
		int mid = (s + e - 1) / 2;
		if(arr[mid] == 0) arr[mid] = cnt;

		if(s <= mid - 1) pq.push(sse(sze / 2 - 1, s, mid - 1));
		if(mid + 1 <= e) pq.push(sse(sze / 2, mid + 1, e));
		bfs(cnt + 1);
	} else {
		// size is odd
		int mid = (s + e) / 2;
		if(arr[mid] == 0) arr[mid] = cnt;

		if(s <= mid - 1) pq.push(sse(sze / 2, s, mid - 1));
		if(mid + 1 <= e) pq.push(sse(sze / 2, mid + 1, e));
		bfs(cnt + 1);
	}

	return;
}

int main(void) {
	// For fast IO
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);

	int tc;	// <= 10^4

	cin >> tc;

	while(tc--) {
		cin >> n;

		memset(arr, 0, sizeof(arr));
		pq.push(sse(n, 1, n));
		bfs(1);
		for(int i = 1; i <= n; i++) {
			cout << arr[i] << " ";
		}
		cout << "\n";
	}
	return 0;
}