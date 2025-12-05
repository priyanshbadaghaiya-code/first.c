//delete an element
#include<stdio.h>
int main(){
    int a[100],n,index;
    printf("Enter the size of aarray:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
   
    printf("Enter the index no. to be dlete element:");
    scanf("%d",&index);
    if(index<0||index>n){
        printf("please enter valid index no\n");
    }else{

    }
    for(int i=n;i>=index;i++){
        a[i]=a[i+1];
    }
    n--;
    for(int i=index;i<n-1;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}