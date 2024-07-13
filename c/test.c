#include<stdio.h>
#include<stdlib.h>
int main(){
	int n = 5;
	int temp[6] = {4,10,3,12,20,7};
	int table_arr[10][10]  = {0};
	int k_table[10][10] = {0};
	int store[10],store1[10]; 
	int l,i,j,k,t,k_store, min_k, opt_k,m;
    for(l=2;l<=n;l++){
    	for(j=l,i=1;j<=n;j++,i++){
    		t = 0; 
    		min_k = 9999;
    		for(k=i;k<j;k++){
    			m = table_arr[i][k] + table_arr[k+1][j] + (temp[i-1]*temp[k]*temp[j]);
    			if(min_k>m){
    				min_k = m;
    				opt_k = k;
				}
    			
			}
			table_arr[i][j] = min_k;
			
			k_table[i][j] = opt_k;
		}
	}
	printf("Maximum Number of multiplication : %d\n",table_arr[1][n]);
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",table_arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			printf("%d ",k_table[i][j]);
		}
		printf("\n");
	}
	
}
<<<<<<< HEAD
=======
//check
//check
>>>>>>> a0048304cdcb9eda24f1e94446ae8eea256a4098
