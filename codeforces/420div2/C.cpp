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

set<int> add;
stack<int> st;
int des, n, tp, ans, btp;

int main(){
	ios_base::sync_with_stdio(false);
  cin >> n;
  des = 1;
  for(int i=0;i<2*n;++i){
    string s; int t;
    cin >> s;
    if(s == "add"){
      cin >> t;
      st.push(t);
      add.insert(t);
    }
    else{
      if(st.empty()) des++;
      else if(st.top() != des){
        ans++;
        while(!st.empty()) st.pop();
        des++;
      }
      else{
        des++;
        st.pop();
      }
    }
  }
  cout << ans << endl;

	return 0;
}

