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
const int N=1e5+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int main(){
  ll n, b, d;
  scanf("%lld %lld %lld", &n, &b, &d);
  ll sum = 0, ans = 0;
  for(int i=0;i<n;i++){
    ll u;
    scanf("%lld", &u);
    if(u <= b) sum += u;
    if(sum > d) sum = 0, ans++;
  }
  printf("%lld\n", ans);
  return 0;
}

