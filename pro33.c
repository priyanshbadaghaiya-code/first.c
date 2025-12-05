//recursion code
#include<stdio.h>
int fact(int);
int main(){
    int n,ft;
    printf("N= ");
    scanf("%d",&n);
    ft=fact(n);
printf("Ans=%d\n",ft);

return 0;}
int fact(int t){
    if(t==0){
        return 1;
    }else{
        return (t*fact(t-1));
    }
}