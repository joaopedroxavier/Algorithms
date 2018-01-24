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

int v[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
string d[] = { "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };

map<string, int> month_to_int;

int day(int d, int m, int y) {
  y -= m<3;
  return (y + y/4 - y/100 + y/400 + v[m-1] + d)%7;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  month_to_int["January"] = 1;
  month_to_int["February"] = 2;
  month_to_int["March"] = 3;
  month_to_int["April"] = 4;
  month_to_int["May"] = 5;
  month_to_int["June"] = 6;
  month_to_int["July"] = 7;
  month_to_int["August"] = 8;
  month_to_int["September"] = 9;
  month_to_int["October"] = 10;
  month_to_int["November"] = 11;
  month_to_int["December"] = 12;

  int qry_d;
  string qry_m, qry_y;

  while(1) {
    cin >> qry_d;
    if(cin.eof()) break;
    cin >> qry_m >> qry_y;

    ll yr = 0;
    for(auto i : qry_y) {
      yr = ((10 * yr) + (i - '0')) % 2800;
    }

    cout << d[day(qry_d, month_to_int[qry_m], yr)] << endl;
  }

  return 0;
}

