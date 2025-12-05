#include<stdio.h>
#include<stdlib.h>

void merge_sort(float *, int, int, int);
void merge_pass(float *, int, int);

void merge_sort(float list[], int top, int n, int bottom){
    float temp[1000];
    int f = top;
    int s = n + 1;
    int t = top;
    int upper;

    while(f <= n && s <= bottom){
        if(list[f] <= list[s]){
            temp[t] = list[f];
            f++;
        }else{
            temp[t] = list[s];
            s++;
        }
        t++;
    }

    while(f <= n){
        temp[t] = list[f];
        f++;
        t++;
    }

    while(s <= bottom){
        temp[t] = list[s];
        s++;
        t++;
    }

    for(upper = top; upper <= bottom; upper++){
        list[upper] = temp[upper];
    }
}

void merge_pass(float append[], int m, int n){
    if(m < n){
        int mid = (m + n) / 2;
        merge_pass(append, m, mid);
        merge_pass(append, mid + 1, n);
        merge_sort(append, m, mid, n);
    }
}

int main(){
    float list[1000];
    int i, n;

    printf("\n Input the number of element in the list:");
    scanf("%d", &n);

    for(i = 0; i < n; i++){
        list[i] = (float)(rand() % 100);
    }

    printf("\n Entered list as follow:\n");
    for(i = 0; i < n; i++){
        printf("%d ", (int)list[i]);
    }

    merge_pass(list, 0, n - 1);

    printf("\nMerge sorted list is as follows:\n");
    for(i = 0; i < n; i++){
        printf("%d ", (int)list[i]);
    }

    return 0;
}
