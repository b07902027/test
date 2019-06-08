//#include <cstdio>
#include <iostream>
#include <vector>
#define MAXN 10001
typedef struct{
    bool test;
    char c;
    short l;
}Data;
char A[MAXN], B[MAXN];
std::string ans;

Data lcs(int N, int M){
    Data d;
    if (!N || !M){
        d.l = d.test = 0;
        printf("%d %d, return d l = %d, test = %d, c = %c\n",N,M, d.l, d.test, d.c);
        return d;
    }
    if (A[N - 1] == B[M - 1]){
        d.test = 1;
        d.c = A[N - 1];
        Data ansd = lcs(N - 1, M - 1);
        d.l = ansd.l + 1;
        if (ansd.test){
            ans.push_back(ansd.c);
        }
        printf("%d %d, return d l = %d, test = %d, c = %c\n",N,M, d.l, d.test, d.c);
        return d;
    }else{
        d.test = 0;
        Data ansA, ansB;
        ansA = lcs(N - 1, M);
        ansB = lcs(N, M - 1);
        if (ansA.l > ansB.l){
            d.l = ansA.l;
            if (ansA.test){
                ans.push_back(ansA.c);
            }
        }else{
            d.l = ansB.l;
            if (ansB.test){
                ans.push_back(ansB.c);
            }
        }
        printf("%d %d, return d l = %d, test = %d, c = %c\n",N,M, d.l, d.test, d.c);
        return d;
    }
}

int main(){
    int T, N, M;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        scanf("%s%s",A,B);
        ans.clear();
        Data d = lcs(N, M);
        if (d.test){
            ans.push_back(d.c);
        }
        std::cout << ans;
    }
}
