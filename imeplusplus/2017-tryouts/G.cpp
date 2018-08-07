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
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int sparse1[N][20], sparse2[N][20];
int v1[N], v2[N];

int msb(int u){
  int i = 0;
  while(u){
    i++;
    u/=2;
  }
  return i-1;
}

int main(){
  ios_base::sync_with_stdio(false);
  while(1){
    int n; 
    map<int,int> r1, r2, l1, l2;
    cin >> n;
    if(cin.eof()) break;

    for(int i=0;i<n;++i){
      cin >> v1[i];
      (!l1.count(v1[i])) ? l1[v1[i]] = i : r1[v1[i]] = i;
    }
    for(int i=0;i<n;++i){
      cin >> v2[i];
      (!l2.count(v2[i])) ? l2[v2[i]] = i : r2[v2[i]] = i;
    }

    for(int i=0;i<n;++i) sparse1[i][0] = v1[i], sparse2[i][0] = v2[i];
    for(int j=1;j<20;++j){
      for(int i=0;i<=(n-(1<<j));++i){
        sparse1[i][j] = max(sparse1[i][j-1], sparse1[i+(1<<(j-1))][j-1]);
        sparse2[i][j] = max(sparse2[i][j-1], sparse2[i+(1<<(j-1))][j-1]);
      }
    }
    
    int ans = 0;
    for(int i=0;i<n;++i){
      if(l2.count(v1[i])) ans = max(ans, v1[i]);
      else if(i == l1[v1[i]]){
        int l = i, r = r1[v1[i]], j = msb(r-l+1);
        if(v1[i] < max(sparse1[l][j], sparse1[r-(1<<j)+1][j])) ans = max(ans, v1[i]);
      }
    }

    for(int i=0;i<n;++i){
      if(l1.count(v2[i])) ans = max(ans, v2[i]);
      else if(i == l2[v2[i]]){
        int l = i, r = r2[v2[i]], j = msb(r-l+1);
        if(v2[i] < max(sparse2[l][j], sparse2[r-(1<<j)+1][j])) ans = max(ans, v2[i]);
      }
    }
    cout << ans << endl;
  }
  return 0;
}

