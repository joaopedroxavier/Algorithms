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
int ans = 0, num = 0;

int main(){
  ios_base::sync_with_stdio(false);
  while(1){
    cin >> s;
    if(cin.eof()) break;
    vector<int> has(30); 
    ans = 0, num = 0;
    for(char c : s){
      if(!has[c-'a']) num++;
      has[c-'a']++;
    }
    sort(has.begin(), has.end());
    if(num > 2){
      for(int i : has) if(i != 0){
        ans += i, num--;
        if(num <= 2) break;
      }
    }
    cout << ans << endl;
  }
  return 0;
}

