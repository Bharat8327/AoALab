#include <stdio.h>

int max(int a, int b) { return (a > b) ? a : b; }
int knapSack(int W, int wt[], int val[], int n)
{
    int dp[n+1][W+1];
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=W;j++){
            if(i==0 || j == 0){
                dp[i][j]=0;
            }
            else if(wt[i-1]<=j){
                dp[i][j] = max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else{
                dp[i][j] = dp[i-1][j];
            }
        }
    }
    for(int i=0;i<n+1;i++){
        for(int j = 0; j< W+1;j++){
            printf("%d ", dp[i][j]);
        }
        printf("\n");
    }
    return dp[n][W];
}

int main()
{
    int W;
    int n;
    printf("Enter the weight of knapsack: ");
    scanf("%d",&W);
    printf("Enter the number of items: ");
    scanf("%d",&n);
    int value[n];
    int weight[n];

    printf("Enter the weight of items: \n");
    for(int i=0;i<n;i++){
    scanf("%d",&weight[i]);
    }

    printf("Enter the values of items: \n");
    for(int i=0;i<n;i++){
    scanf("%d",&value[i]);
    }
    printf("%d", knapSack(W, weight, value, n));
    return 0;
}
