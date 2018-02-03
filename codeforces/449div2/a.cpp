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

string s;
int n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;

  cin >> s;

  for(int q=0; q<m; q++) {
    int i, j;
    char c1, c2;
    cin >> i >> j >> c1 >> c2;
    for(int k=i; k<=j; k++) if(s[k-1] == c1) s[k-1] = c2;
  }

  cout << s << endl;

	return 0;
}

