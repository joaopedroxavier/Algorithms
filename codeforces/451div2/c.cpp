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
map<string, set<string>> m;

bool suffix(string a, string b) {
  if(b.size() > a.size()) return false; 
  if(b == a) return false;

  int p1 = (int)b.size()-1, p2 = (int)a.size()-1;
  bool is = true;
  while(p1 >= 0) {
    is = is and b[p1] == a[p2];
    p1--, p2--;
  }
  return is;
}

int main(){
	ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(int i=0; i<n; i++) {
    string s; int t;
    cin >> s >> t;
    for(int j=0; j<t; j++) {
      string nb;
      cin >> nb;
      set<string> todelete;
      for(auto it : m[s]) if(suffix(it, nb)) todelete.insert(nb);
      for(auto it : m[s]) if(suffix(nb, it)) todelete.insert(it);
      m[s].insert(nb);
      for(auto it : todelete) m[s].erase(it);
    }
  }

  cout << m.size() << endl;
  for(auto it : m) {
    cout << it.first << " ";
    cout << it.second.size() << " ";
    for(auto jt : it.second) cout << jt << " ";
    cout << endl;
  }

	return 0;
}

