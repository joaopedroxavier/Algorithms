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

string s[N];
int n, ans;
map<string, int> dom, kattis;
set<string> verd;

int main(){
  ios_base::sync_with_stdio(false);
  cin >> n;

  for(int i=0;i<n;i++){
    cin >> s[i];
    verd.insert(s[i]);
    dom[s[i]]++;
  }

  for(int i=0;i<n;i++){
    cin >> s[i];
    verd.insert(s[i]);
    kattis[s[i]]++;
  }

  for(auto it : verd) ans += min(dom[it], kattis[it]);

  cout << ans << endl;

	return 0;
}

