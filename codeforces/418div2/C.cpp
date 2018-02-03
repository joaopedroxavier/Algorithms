//
//
//
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
const int N=2e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

int v[50][N];
int n;
string garland;
int save[50][N];

int get_ans(int w, char c){
  int ans=1;
  int p = c-'a';
  int l=w, r=n;
  while(l<=r){
    int m = (l+r)/2;
    if(m == 0){
      ans = 1;
      break;
    }
    for(int j=m;j<=n;++j){
      if(v[p][j] - v[p][j-m] + w >= m){
        ans = max(m, 1);
        l = m+1;
      }
    }
    if(l != m+1) r = m-1;
  }
  return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  cin >> garland;
  for(int i=1;i<=n;++i) v[garland[i-1]-'a'][i] = 1;
  for(int i=0;i<26;++i) for(int j=2;j<=n;++j) v[i][j]+=v[i][j-1];
  int q;
  cin >> q;
  for(char c='a';c<='z';++c){
    for(int m=1;m<=n;++m) save[c-'a'][m] = get_ans(m, c);
  }
  for(int i=0;i<q;++i){
    int m;
    char fav;
    cin >> m >> fav;
    cout << save[fav-'a'][m] << endl;
  }
	return 0;
}

