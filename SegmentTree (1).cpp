#include<bits/stdc++.h>
using namespace std;
#define LLMX 0x7fffffffffffffff

long long  arr[100005];
long long  SegTr[100005*3];
int MAX = INT_MAX;


void Build(int nod, int lf, int rt)              //call with nod = 1; lft=1; rgt=N
{
    if (lf == rt)
    {
        SegTr[nod] = arr[lf];
        return;
    }
    int mid = (lf + rt)/2;

    Build(2*nod, lf, mid);
    Build(2*nod+1, mid + 1, rt);

    SegTr[nod] = min(SegTr[2*nod],SegTr[2*nod+1]);        //range min
    //SegTr[nod] = SegTr[2*nod] + SegTr[2*nod+1];      //range sum
}
int query(int nod, int lf, int rt, int qlf, int qrt)  //query left : qlf; query right: qrt
{
    if (qlf > rt || qrt < lf)                       // Non overlap;
        //return 0;                                       //range Sum
        return MAX;                                     //range min;

    if (qlf<=lf && rt<=qrt)                         //   both left & right falls under range;
        return SegTr[nod];

    int mid = (lf + rt)/2;
    int a = query(2*nod,lf,mid,qlf,qrt);
    int b = query(2*nod+1,mid+1,rt,qlf,qrt);
    return min(a,b);    //range min
    //return query(a+b);         //range sum
}


void update(int nod, int lf, int rt, int idx, int val)
{
    if (idx > rt || idx < lf)
        return;                                 //out of range
    if (lf == idx && rt == idx)                //found the node
    {
        SegTr[nod] = val;
        return;
    }
    int mid = (lf + rt)/2;

    update(2*nod, lf, mid, idx, val);
    update(2*nod+1, mid + 1, rt, idx, val);

    //SegTr[nod] = SegTr[2*nod] + SegTr[2*nod+1];          //range sum
    SegTr[nod] = min(SegTr[2*nod],SegTr[2*nod+1]);         //range min
}
int main()
{

    int  tst,csn=1,i,j,k,l,m,n,o,p;
    scanf("%d",&tst);
    while(tst--)
    {
        scanf("%d %d",&n,&p);
        for(i=1; i<=n; i++) scanf("%d",&arr[i]);
        Build(1,1,n);
        printf("Case %d:\n",csn++);
        while(p--)
        {
             scanf("%d %d",&k,&l);
             m=query(1,1,n,k,l);
             printf("%d\n",m);
        }
    }

    return 0;

}




long long arr[500005];
long long sum[500005];
long long lazy[500005];
long long v[500005];

void build(int now, int L, int R) {
  if (L == R) {
    sum[now] = arr[L];
    return;
  }
  int mid = (L + R) >> 1;
  int lft = now << 1, rt = lft | 1;
  build(lft, L, mid);
  build(rt, mid + 1, R);
  sum[now] = sum[lft] + sum[rt];
}

void push(int now, int L, int R) {
  if (lazy[now]) {
    sum[now] += (R - L + 1) * lazy[now];
    if (L != R) {
      lazy[(now) << 1] += lazy[now];
      lazy[(now << 1) | 1] += lazy[now];
    }
  }
  lazy[now] = 0;
}

void update(int now, int L, int R, int i, int j, ll val) {
  push(now, L, R);
  if (R < i || L > j) return;
  if (L >= i && R <= j) {
    lazy[now] += val;
    push(now, L, R);
    return;
  }
  int mid = (L + R) >> 1;
  int lft = now << 1, rt = lft | 1;
  update(lft, L, mid, i, j, val);
  update(rt, mid + 1, R, i, j, val);
  sum[now] = sum[lft] + sum[rt];
}

ll query(int now, int L, int R, int i, int j) {
  push(now, L, R);
  if (R < i || L > j) return 0;
  if (L >= i && R <= j) return sum[now];
  int mid = (L + R) >> 1;
  int lft = now << 1, rt = lft | 1;
  return query(lft, L, mid, i, j) + query(rt, mid + 1, R, i, j);
}

