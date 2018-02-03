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
const int N=1e2+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int lft, mid, rgt, one;
int n, k;
int group[N];

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n >> k;
  lft = n, mid = n, rgt = n;
  for(int i=0;i<k;i++) cin >> group[i];

  bool cont = true;
  while(cont){
    cont = false;
    for(int i=0;i<k;i++) if(group[i] >= 4){
      cont = true;
      if(mid > 0) mid--, group[i] -= 4;
      else if(lft > 1) lft-=2, group[i] -= 4;
      else if(lft > 0 and rgt > 0) lft--, rgt--, group[i] -= 4;
      else if(rgt > 1) rgt-=2, group[i] -= 4;
      else{ cout << "NO" << endl; return 0; }
    }
  }
  for(int i=0;i<k;i++) if(group[i] >= 3){
    if(mid > 0) mid--, group[i] = 0;
    else if(lft > 1) lft-=2, group[i] = 0;
    else if(lft > 0 and rgt > 0) lft--, rgt--, group[i] = 0;
    else if(rgt > 0) rgt-=2, group[i] = 0;
    else{ cout << "NO" << endl; return 0; }
  }

  for(int i=0;i<k;i++) if(group[i] >= 2){
    if(mid > 0) mid--, one++, group[i] = 0;
    else if(lft > 0) lft--, group[i] = 0;
    else if(rgt > 0) rgt--, group[i] = 0;
    else if(one > 1) one -= 2, group[i] = 0;
    else{ cout << "NO" << endl; return 0; }
  }
  int p = 0;
  for(int i=0;i<k;i++) if(group[i] >= 1) p++;

  if(p > lft+rgt+2*mid+one){ cout << "NO" << endl; return 0; }

  cout << "YES" << endl;

  return 0;
}

