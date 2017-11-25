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

map<string, int> m;
string s;

void calc(string st){
  size_t p = 0;
  //printf("%s\n", st.c_str());
  while(p != string::npos) {
    //printf("%d\n", (int)p);
    m[st]++;
    p = s.find(st, p);
    if(p != string::npos) p++;
  }
}

int main(){
  cin >> s;
  calc("Danil");
  calc("Olya");
  calc("Slava");
  calc("Ann");
  calc("Nikita");

  if(m["Danil"] + m["Olya"] + m["Slava"] + m["Ann"] + m["Nikita"] == 6) {
    printf("YES\n");
  }
  else printf("NO\n");
	return 0;
}

