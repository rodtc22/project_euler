#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;

template <typename A,typename B> ostream& operator <<(ostream& os, pair<A,B>& p) { return os << "(" << p.first << ", " << p.second << ")";}
template <typename T> ostream& operator <<(ostream& os, vector<T>& v) {    os << "[" ;    for(int i = 0 ;i < v.size(); i++){      if(i) os <<", ";      os <<v[i];    }    os << "]";return os;}
template <typename T> istream& operator >>(istream& is, vector<T>& v){ for(auto &x : v) is >> x; return is;}
#define fastio ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);

typedef long long ll;
typedef pair<int,int> pii;
const int inf = 2e9;
const int mod = 1e9+7;
const int N = 2e6;

void printe(){}
template <typename H, typename ...T>
void printe(H x, T... y){
   cout << ", " << x;
   printe(y...);
}

#define er(args...) { cout << "DBG: " << #args << " = {"; printe(args); cout << "}\n"; } 

/*k = 2(a+b-(ab/2))   =>   c = k - a - b*/

int main(){
   int k = 1000;
   for(int a = 1; a  <= k ; a++){
      for(int b = a + 1 ; b <= k ;b++){
         if(k == 2*(a+b - a*b/k)){
            int c = k - a - b;

            if(a < b && b < c && a+b+c == k && a*a + b*b == c*c){
                  cout << 1ll*a*b*c <<endl;
            }
         } 
      }
   }
   return 0;
}