#include <iostream>
#include <algorithm>
#include <memory.h>
#include <random>
#include <unordered_map>
#include <math.h>
#include <string>
#include <cstring>
#include <queue>
#include <stack>
#include <deque>
#include <map>
#include <set>
#define FASTIO() ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define TC() int TEST_CASE;cin>>TEST_CASE;for(int TEST_NUM=1;TEST_NUM<=TEST_CASE;TEST_NUM++)
#define fst first
#define snd second
#define int long long
#define endl '\n'
#define pb push_back
#define mp make_pair
#define MOD 1000000007
#define cont continue
#define str string
#define lb lower_bound
#define ub upper_bound
#define V(T) vector<T>
#define Q(T) queue<T>
#define S(T) stack<T>
#define DQ(T) deque<T>   
#define rep(i, n) for(int i = 0 ; i < (n) ; i++)
#define fup(i,a,b,c) for(int (i)=(a);(i)<=(b);(i)+=(c))
#define fdn(i,a,b,c) for(int (i)=(a);(i)>=(b);(i)-=(c))
#define MEM0(a) memset((a),0,sizeof(a));
#define MEM_1(a) memset((a),-1,sizeof(a));
#define sc(x) int x; cin >> x;
#define sc2(x,y)     int x,y;cin>>x>>y
#define sc3(x,y,z)   int x,y,z;cin>>x>>y>>z
#define sc4(x,y,z,w) int x,y,z,w;cin>>x>>y>>z>>w
#define print(x) cout << x << endl 
#define all(x) (x).begin(), (x).end()
#define PQ(T) priority_queue<T>
#define GPQ(T) priority_queue<T,vector<T>,greater<T>>
#define getprime(sz)vector<int> prime; bool isprime[sz + 1]  = {}; memset(isprime, true, sizeof(isprime)); isprime[1] = false; fup(i, 2, (int)sqrt(sz), 1) {\
        if(isprime[i]) prime.pb(i); fup(j, i * i, sz, i) { isprime[j] = false; } }
using namespace std;
typedef pair<int,int> pii;
const int INF = 1e15;
int gcd(int a, int b) { return b ? gcd(b, a%b) : a; }
int lcm(int a, int b) { if (a == 0 || b == 0)return a + b; return a*(b / gcd(a, b)); }
int dx[4] = {-1, 1, 0, 0}; int dy[4] = {0, 0, -1, 1};


int getsize(int n) {
    int cnt = 0;
    while(n > 0) {
        n /= 10;
        cnt++;
    }
    return cnt;
}

signed main() {
    FASTIO();
    TC() {
        int a;
        int s;
        cin >> a >> s;
        string n = to_string(a);
        int sum = 0;
        rep(i, n.size()) {
            sum += n[i] - '0';
        }
        int zero = 0;
        if(sum <= s) {
            cout << zero << endl;
            continue;
        }
        bool flag = false;
        int ans = 0;
        int cur = stol(n);
        for(int i = n.size() - 1 ; i >= 0 ; i--) {
            int mul = 1;
            int expect = 0;
            string cc = "";
            for(int j = n.size() - 1 ; j >= i ; j--) {
                expect += (int)(n[j] - '0' - 1);
                if(sum - expect <= s) {
                    cc += n[j];
                    reverse(all(cc));
                    int ccc = stol(cc);
                    mul *= 10;
                    ans = mul - ccc;
                    flag = true;
                    break;  
                }
                expect++;
                mul *= 10;
                cc += n[j];
            }
            if(flag) break;
            if(i == 0 && !flag) {
                ans = mul - cur;
            }
        }
        cout << ans << endl;
    }
}