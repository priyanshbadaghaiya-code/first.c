#include<stdio.h>
struct Link
{
    int data;
    char nm[20];
};
struct Link obj[10];
int main()
{
    int i;
    for(int i=0;i<5;i++){
        printf("Name= ");
        scanf("%s",obj[i].nm);
        printf("data= ");
        scanf("%d",&obj[i].data);
    }
    for(int i=0;i<5;i++){
        printf("Name %s\tData= %d",obj[i].nm,obj[i].data);
    }
    return 0;
}