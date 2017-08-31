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

pair<ll, ll> sp[N];
ll n, r, w, h;
ll lis[N];

int main(){
  while(scanf("%lld %lld %lld %lld", &n, &r, &w, &h) != EOF){
    memset(lis, 0, sizeof(lis));
    for(int i=0;i<n;i++){
      ll x, y;
      scanf("%lld %lld", &x, &y);
      sp[i] = mp(y - r*x, y + r*x);
    }
    sort(sp, sp+n);
    lis[0] = sp[0].second;
    int length = 1;
    for(int i=1;i<n;i++){
      if(sp[i].second < lis[0]) lis[0] = sp[i].second;
      else if(sp[i].second > lis[length-1]){
        lis[length] = sp[i].second;
        length++;
      }
      else{
        lis[upper_bound(lis, lis+length, sp[i].second) - lis] = sp[i].second;
      }
    }
    printf("%d\n", length);
  }
  return 0;
}

