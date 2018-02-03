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
  int n, a;
  scanf("%d %d", &n, &a);
  vector<int> lft, rgt;
  for(int i=0;i<n;i++){
    int u;
    scanf("%d", &u);
    if(u < a) lft.pb(a-u);
    if(u > a) rgt.pb(u-a);
  }
  int s1 = lft.size(), s2 = rgt.size();
  sort(lft.begin(), lft.end());
  sort(rgt.begin(), rgt.end());

  if(s2 + s1 <= 1) return printf("%d\n", 0), 0;
  if(s1 == 0) return printf("%d\n", rgt[s2-2]), 0;
  if(s2 == 0) return printf("%d\n", lft[s1-2]), 0;
  if(s1 == 1 and s2 == 1) return printf("%d\n", min(lft[0], rgt[0])), 0;

  if(s1 == 1) return printf("%d\n", min(min(2*lft[0] + rgt[s2-2], rgt[s2-1]),
                                        lft[0] + 2*rgt[s2-2])), 0;

  if(s2 == 1) return printf("%d\n", min(min(2*rgt[0] + lft[s1-2], lft[s1-1]),
                                        rgt[0] + 2*lft[s1-2])), 0;

  printf("%d\n", min(min(2*lft[s1-1] + rgt[s2-2], 2*rgt[s2-1] + lft[s1-2]),
                     min(2*lft[s1-2] + rgt[s2-1], 2*rgt[s2-2] + lft[s1-1])));

	return 0;
}

