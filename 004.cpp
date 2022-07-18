#include <iostream>
#include <algorithm>
#include <cmath>
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
const int N = 1e6;

//learning variadic functions :D
void print(){cout  <<"}"<<  endl;}
template <typename T, typename... Types>
void print(T x,Types ...args){
   cout << " " << x;
   print(args...);
}
#define error(args...) {cout <<"DBG: "<< #args << " = {";print(args);}

int lcm(int a, int b) {return a * __gcd(a,b) * b;}
int f(int n) {return n * (n+1) >> 1;}

bool ispalindrome(int k){
   string a = to_string(k);
   string b = a;
   reverse(b.begin(),b.end());
   return a == b;
}

int main(){
   int maxi = 1;
   for(int i = 999 ;i >= 100 ;i--){
      for(int j = i ;j >= 100 ;j--){
         int k = i*j;
         if(ispalindrome(k)){
            maxi = max(maxi, k);
         }
      }
   }
   cout << maxi << endl;
   return 0;
}