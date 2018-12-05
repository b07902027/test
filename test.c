#include <stdio.h>
#include <string.h>
int r,c,limit;
int r_sum[8],c_sum[8];
char die[17] = {0};
int goal[8][8];
int tem_r = 0, tem_c = 0;


int recursion(int index){
	int r_now = index / c;
	int c_now = index % c;
	if (index == limit){
		int tem_sum = 0;
		for (int i = 0; i < c; i++)
			tem_sum += goal[r - 1][i];
		if (tem_sum != r_sum[r - 1])
			return 0;
		tem_sum = 0;
		for (int i = 0; i < r; i++)
			tem_sum += goal[i][c - 1];
		if (tem_sum != c_sum[c - 1])
			return 0;
		for (int i = 0; i < r; i++){
			for (int j = 0; j < c; j++)
				printf("%d ",goal[i][j]);
			printf("\n");
		}
		return 1;
	}
	else if(r_now == r - 1 && c_now != 0){
		int tem_sum = 0;
		for (int i = 0; i < r; i++)
			tem_sum += goal[i][c_now - 1];
		if (tem_sum != c_sum[c_now - 1])
			return 0;
	}
	else if(c_now == c - 1 && r_now != 0){
		int tem_sum = 0;
		for (int i = 0; i < c; i++)
			tem_sum += goal[r_now - 1][i];
		if (tem_sum != r_sum[r_now - 1])
			return 0;
	}
	for (int i = 1; i <= limit; i++){
		if (die[i] == 0){
			die[i] = 1;
			

			goal[r_now][c_now] = i;
			if (recursion(index + 1))
				return 1;
			die[i] = 0;
		}
	}
	return 0;
}

int main(){
	while(scanf("%d%d",&r,&c) != EOF){
		for (int i = 0; i < r; i++)
			scanf("%d",&r_sum[i]);
		for (int i = 0; i < c; i++)
			scanf("%d",&c_sum[i]);
		limit = r * c;
		memset(die,0,17);
		if (!recursion(0)){
			printf("no solution\n");
		}
	}
}
