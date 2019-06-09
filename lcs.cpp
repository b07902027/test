#include <cstdio>
#include <string>
#define MAXN 10001
char A[MAXN], B[MAXN];

std::string lcs(int N, int M){
    if (!N || !M){
        std::string ans("");
        return ans;
    }
    if (A[N - 1] == B[M - 1]){
        std::string ans = lcs(N - 1, M - 1);
        ans.push_back(A[N - 1]);
        return ans;
    }else{
        std::string ansA, ansB;
        ansA = lcs(N - 1, M);
        ansB = lcs(N, M - 1);
        if (ansA.length() > ansB.length()){
            return ansA;
        }else{
            return ansB;
        }
    }
}

int main(){
    int T, N, M;
    scanf("%d",&T);
    while(T--){
        scanf("%d%d",&N,&M);
        scanf("%s%s",A,B);
        std::string ans = lcs(N, M);
        if (ans.empty()){
            printf("*\n");
        }else{
            int l = ans.length();
            for (int i = 0; i < l; i++){
                printf("%c",ans[i]);
            }
            printf("\n");
        }
    }
}
