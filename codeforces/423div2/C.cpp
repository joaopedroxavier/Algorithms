#include <bits/stdc++.h>

using namespace std;

#define topper top //XDDDDDDD

#define mp make_pair
#define pb push_back
#define db(x) cerr << #x << " == " <<  x << endl;
#define _ << " " <<
#define fst first
#define snd second

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;

const long double EPS = 1e-9;
const int N=1e6+5;
const int MOD=1e9+7;
const int INF=0x3f3f3f3f;

vector<pair<int, string> > inp;
int st[N];
int n, m;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;
  for(int i=0;i<n;++i){
    string s; int k; vi v;
    cin >> s >> k;
    for(int j=0;j<k;++j){
      int x;
      cin >> x;
      inp.pb(mp(x, s));
    }
  }

  sort(inp.begin(), inp.end());

  string ans; int last = -1;
  for(pair<int, string> q : inp){
    int i = q.fst-1;
    string s = q.snd;
    if(i > last){
      for(int j=last+1;j<i;++j) ans = ans + "a";
      ans = ans + s;
      last = i + s.size() - 1;
    }
    else{
      if(i + (int)s.size() - 1 > last){
        for(int j=last-i+1;j<(int)s.size();++j) ans = ans + s[j];
        last = i + s.size() - 1;
      }
    }
  }
  //    cerr << ans _ i _ last << endl;
  //    cerr << "current writer: " << writer << ". Switch: " << ((swt) ? "on" : "off") << endl;

  cout << ans << endl;
  return 0;
}

