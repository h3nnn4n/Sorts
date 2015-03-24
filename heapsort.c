#include <stdio.h>
#include <stdlib.h>

void print(int *a,int n);

int left(int i){
    return 2*i+1;
}

int right(int i){
    return 2*i+2;
}

void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

void heapify(int *a, int n, int i){
    int e,d,maior;
    e = left(i);
    d = right(i);

    if(e<n && a[e] > a[i]){
        maior=e;
    }else{
        maior=i;
    }

    if(d<n && a[d]>a[maior]){
        maior=d;
    }

    if(maior!=i){
        swap(&a[i],&a[maior]);
        heapify(a,n,maior);
    }
}

int heapExtract(int *a, int n){
    int maior;

    maior=a[0];
    a[0]=a[n-1];
    heapify(a,n-1,0);
    return maior;
}

void buildHeap(int *a,int n){
    int i;

    for(i=(n-1)/2-1;i<=0;i--){
        heapify(a,n,i);
    }
}

void heapSort(int *a,int n){
    int i;

    buildHeap(a,n);
    //print(a,n);
    for(i=n-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

#define max 10
void print(int *a,int n){
    int i;

    for(i=0;i<max;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}


int main(){
    int a[max];

    int i,j,m,flag;

    srand(10);

    for(j=0;j<10;j++){
        for(i=0;i<max;i++){
            a[i]=rand()%max;
        }

        heapSort(a,max);
        flag=0;
        for(m=1;m<max;m++){
            if(a[m-1]>a[m]){
                flag=1;
            }
        }
        if(flag){
            //continue;
        }
        print(a,max);
    }

    return EXIT_SUCCESS;
}
