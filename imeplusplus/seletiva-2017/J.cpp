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
const int N=1e3+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

ll sack[N][N];
ll c, t, a, n;
ll nit[N], oxi[N], wt[N];

int main(){
	ios_base::sync_with_stdio(false);
  cin >> c;
  while(c--){
    cin >> t >> a;
    cin >> n;
    for(int i=0;i<n;++i) cin >> oxi[i] >> nit[i] >> wt[i];
    memset(sack, 63, sizeof(sack));
    sack[0][0] = 0;

    for(int i=0;i<n;++i){
      for(int j=t;j>=0;--j){
        for(int k=a;k>=0;--k){
          int limj = min(j+oxi[i], t);
          int limk = min(k+nit[i], a);
          sack[limj][limk] = min(sack[limj][limk], sack[j][k] + wt[i]);
        }
      }
    }

    cout << sack[t][a] << endl;
  }
	return 0;
}

