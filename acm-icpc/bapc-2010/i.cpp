//
// 내가 나인 게 싫은 날
// 영영 사라지고 싶은 날
// 문을 하나 만들자 너의 맘 속에다
// 그 문을 열고 들어가면
// 이 곳이 기다릴 거야
// 믿어도 괜찮아 널 위로해줄 magic shop
//
#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define st first
#define nd second

typedef long long ll;
typedef long double ld;
typedef pair<int,int> ii;

const ld EPS = 1e-9;
const ld PI = acos(-1);

const int N = 1e5+5;
const int MOD = 1e9+7;
const int INF = 0x3f3f3f3f;

struct node {
  char c;
  node* l;
  node* r;

  node(): c(0), l(NULL), r(NULL) {}
  node(char c): c(c), l(NULL), r(NULL) {}
};

void create(node* u, char c) {
  node* v = u -> r;

  node* x = new node(c);
  x -> r = v;
  x -> l = u;
  u -> r = x;
  v -> l = x;
}

node *head, *tail, *cur;

void destroy(node* u) {
  if(u == head) return;

  node* ul = u -> l;
  node* ur = u -> r;

  ul -> r = ur;
  ur -> l = ul;

  delete u;
}

void print() {
  node* p = head -> r;
  while(p != tail) { printf("%c", p -> c); p = p -> r; }
  printf("\n");
}

void cl() {
  node* p = head -> r;
  while(p != tail and p != head) { destroy(p); p = head -> r; }
  delete head;
  delete tail;
}

int t;
string s;

int main(){
  //freopen("in", "r", stdin);
  //freopen("out", "w", stdout);

  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> t;

  while(t--) {
    string s; cin >> s;
    head = new node(); tail = new node(); cur = tail;
    head -> l = head; head -> r = tail;
    tail -> l = head; tail -> r = tail;
    head -> c = 'H';
    tail -> c = 'T';

    for(char c : s) {
      if(c == '<') {
        if(cur -> l != head) cur = cur -> l;
      }
      else if(c == '>') {
        cur = cur -> r;
      }
      else if(c == '-') {
        node* p = cur -> l;
        destroy(p);
      }
      else {
        create(cur -> l, c);
      }
    }

    print();
    cl();
  }
	return 0;
}

