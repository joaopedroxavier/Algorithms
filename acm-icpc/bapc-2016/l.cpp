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

int n;
ll s[N];

bool check(int i) {
  return s[i+2] < s[i+1] + s[i];
}

int main(){
  scanf("%d", &n);

  for(int i=0; i<n; i++) scanf("%lld", &s[i]);

  sort(s, s+n);
  for(int i=0; i+2 < n; i++) if(check(i)) return printf("possible\n"), 0;

  printf("impossible\n");

	return 0;
}

