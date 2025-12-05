#include<stdio.h>
int main()
{
	int a[100],n,min,max;
	printf("Enter the size of array:");
	scanf("%d",&n);
	printf("Enter the value of Element:");
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	max=a[0];
	min=a[0];
	for(int i=0;i<n;i++){
		if(a[i]>max){
			max=a[i];
			
		}
		if(a[i]<min){
			min=a[i];
		}
	}
	printf("max=%d,min=%d",max,min);
	return 0;
}
