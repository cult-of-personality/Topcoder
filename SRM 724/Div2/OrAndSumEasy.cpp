#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define pii pair<int,int>
#define vi vector<int>
#define vii vector<vector<int> >
#define pb push_back

class OrAndSumEasy {
public:
    string isPossible(long long pairOr, long long pairSum) {
        //(a+b) = (a&b) + (a|b)
        long long pairAnd = pairSum - pairOr;
        if(pairAnd >= 0) {
            return ((pairOr == (pairAnd|pairOr)) && (pairSum == (pairOr+pairAnd))) ? "Possible" : "Impossible";
        }
        return "Impossible";
    }
};

