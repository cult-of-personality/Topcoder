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

struct node {
	int left;
	int right;
};

class InPrePost {
private:
    vector<string> order;
    map<string,int> m;

    bool checkTraversals(vi a, vi b){
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        if(a.size()!=b.size())
            return false;

        for(int i=0;i<a.size();i++){
            if(a[i] != b[i])
                return false;
        }
        return true;
    }

    bool verifyTree(vi pre, vi in, vi post){
        if(!checkTraversals(pre,in) || !checkTraversals(pre,post)){
            return false;
        }

        if(pre.empty())
            return true;

        int root = pre[0];
        int leftSize=0, rightSize=0,inPivot=-1;
        vii leftT(3), rightT(3);

        for(int i=0;i<in.size();i++){
            if(in[i]==root){
                inPivot = i;
            } else if(inPivot==-1){
                leftT[1].pb(in[i]);
                leftSize++;
            } else {
                rightT[1].pb(in[i]);
                rightSize++;
            }
        }

        for(int i=0;i<pre.size();i++){
            if(i>0 && i<=leftSize){
                leftT[0].pb(pre[i]);
            } else if(i>leftSize){
                rightT[0].pb(pre[i]);
            }
        }

        for(int i=0;i<leftSize;i++)
            leftT[2].pb(post[i]);
        for(int i=leftSize;i<post.size()-1;i++)
            rightT[2].pb(post[i]);

        vii left(3), right(3);

        for(int i=0;i<order.size();i+=2){
            left[m[order[i]]] = leftT[i>>1];
        }
        for(int i=1;i<order.size();i+=2){
            right[m[order[i]]] = rightT[i>>1];
        }

        if(verifyTree(left[0],left[1],left[2]) && verifyTree(right[0],right[1],right[2]))
            return true;
        return false;
    }

public:
	string isPossible(vector <string>, vector <int>, vector <int>, vector <int>);
};

string InPrePost::isPossible(vector <string> s, vector <int> a1, vector <int> a2, vector <int> a3) {
    order = s;
    m["pre"] = 0;
    m["in"] = 1;
    m["post"] = 2;
    if(verifyTree(a1,a2,a3))
        return "Possible";
    return "Impossible";
}


//Powered by [KawigiEdit] 2.0!