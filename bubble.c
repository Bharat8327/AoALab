#include<stdio.h>
#include<stdlib.h>
int main(){
    int n;
     scanf("%d",&n);
     int arr[n];
    for(int i=0;i<n;i++){
         scanf("%d",&arr[i]);
    }
    int counter=1;
    while(counter<n ){
        for(int i=0;i<n-counter;i++){
            if (arr[i]>arr[i+1])
            {
              int temp=arr[i];
              arr[i]=arr[i+1];
              arr[i+1]=temp;
            }
            
        }
        counter ++;
    }
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}