#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=4e1+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

map<ll, ll> suml;
map<ll, ll> sumr;
int n, t, v[N];

void do_sum(int mask, int flag){
  ll sum = 0, i = ((flag) ? 0 : (n/2));
  while(mask){
    int a = mask%2;
    sum += a*v[i];
    i++, mask/=2;
  }
  ((flag) ? suml[sum]++ : sumr[sum]++);
}

int main(){
	ios_base::sync_with_stdio(false);
  while(1){
    cin >> n >> t;
    if(cin.eof()) break;
    suml.clear();
    sumr.clear();
    for(int i=0;i<n;++i) cin >> v[i];
    int sz1 = (1<<(n/2))-1, sz2 = (1<<((n+1)/2))-1;
    for(int i=1;i<=sz1;++i) do_sum(i, 1);
    for(int i=1;i<=sz2;++i) do_sum(i, 0);
    ll ans = 0;
    for(auto it : suml) if(it.first == t) ans += it.second;
    for(auto it : sumr) if(it.first == t) ans += it.second;
    for(auto it : suml){
      ll sum = it.first;
      if(sumr.count(t-sum)) ans += suml[sum]*sumr[t-sum];
    }
    cout << ans << endl;
  }
	return 0;
}

