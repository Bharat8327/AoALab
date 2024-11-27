#include <stdio.h>

int stack[200];
int top = -1;

void push(int x, int *visit) {
    if (visit[x] == 0 ) { 
        visit[x] = 1;
        top++;
        stack[top] = x;
    }
}

int main() {
    int n; 
    scanf("%d", &n);

    int arr[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &arr[i][j]);
        }
    }

    int visit[n];
    for (int i = 0; i < n; i++) {
        visit[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] > 0) {
                push(j, visit);    
                for(int k=j;k<n;k++){
                    if(arr[i][k] > 0){
                        push(k,visit);
                    }
                }
                push(i, visit);
            }
            else if(j==n-1){
                push(i,visit);
            }
        }
    }
     
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}