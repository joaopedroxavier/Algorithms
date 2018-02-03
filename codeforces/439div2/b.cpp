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

ll a, b;

int main(){
  scanf("%lld %lld", &a, &b);

  if(b - a >= 5) return printf("0\n"), 0;
  
  ll ans = 1, cnt = b-a;
  b = b % 10;
  while(cnt) { 
    ans *= b;
    b = (b + 9) % 10; 
    cnt--; 
  }

  printf("%lld\n", ans % 10);


	return 0;
}

