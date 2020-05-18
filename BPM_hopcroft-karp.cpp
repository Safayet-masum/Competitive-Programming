#include<bits/stdc++.h>
using namespace std;
int tree[1000006];
void update(int ii, int vv) {
    while(ii<1000006) {
        tree[ii]+=vv;
        ii+=(ii&(-ii));
    }
    return;
}
int read(int ii) {
    int ret=0;
    while(ii>0) {
        ret+=tree[ii];
        ii-=(ii&(-ii));
    }
    return ret;
}
int kth(int k) {
    int l=1, h=1000006, m;
    while((h-l)>4) {
        m=(h+l)>>1;
        if(read(m)>=k) h=m;
        else l=m;
    }
    for(; l<=h; l++) {
        if(read(l)>=k) return l;
    }
    return 0;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, a, q;
    cin>>n>>q;
    for(int i=0; i<n; i++) {
        cin>>a;
        update(a, 1);
    }
    while(q--) {
        cin>>a;
        if(a>0) {
            update(a, 1);
        } else {
            int k=kth(-a);
            if(k) update(k, -1);
        }
    }
    a=kth(1);
    cout<<a<<"\n";
    return 0;
}
