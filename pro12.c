#include<stdio.h>
int main(){
    int a[3][3],b[3][3],sum=0,c[3][3];
    printf("Enter the first matrix element:");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the Second matrix element:");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            scanf("%d",&b[i][j]);
        }
    }
     for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){sum=0;
            for(int k=0;k<3;k++){
                sum+=a[i][j]*b[i][j];
            }
        c[i][j]=sum;
        printf("%d ",c[i][j]);
        }
        printf("\n");
     }
}