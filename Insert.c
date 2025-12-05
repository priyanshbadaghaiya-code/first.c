//To insert New number
#include<stdio.h>
int main(){
    int a[100],n,data,index;
    printf("Enter the size of aarray:");
    scanf("%d",&n);
    printf("Enter the elements of array:");
    for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
    }
    printf("Enter the new element:");
    scanf("%d",&data);
    printf("Enter the index no. to be insert new element:");
    scanf("%d",&index);
    if(index<0||index>n){
        printf("please enter valid index no\n");
    }else{
        for(int i=n;i>=index;i--){
            a[i]=a[i-1];
        }
        a[index]=data;
        n++;

    }
    for(int i=0;i<n;i++){
        printf("%d ",a[i]);
    }
    
    return 0;
}