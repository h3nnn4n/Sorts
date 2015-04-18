/*
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * Wrote on 25/03/2015 by Renan S. Silva
 *
 */

/*
 * This sample of code is intended to be a simple exercise for myself
 * and maybe serve as a help to someone.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_utils.h"

void heapSanity(int *a,int i,int n);
void print(int *a,int n);
void swap(int *a,int *b);
int left(int i);
int right(int i);
void heapify(int *a, int n, int i);
int heapExtract(int *a, int n);
void buildHeap(int *a,int n);
void heapSort(int *a,int n);
int isSane(int *a, int n);

int main(int argc, char *argv[]){
    int n=atoi(argv[1]);
    int *a=(int*)malloc(sizeof(int)*n);

    int i,j,m,flag;

    srand(time(NULL));

    if(argc > 2){
        int k = atoi(argv[2]);
        if(k == 1){
            a = vector_fill_almost_sorted(n);
        }else if(k == 2){
            a = vector_fill_few_unique(n);
        }else if(k == 3){
            a = vector_fill_reverse(n);
        }else if(k == 4){
            a = vector_fill_unique(n);
        }
    }else{
        a = vector_fill_unique(n);
    }

    time_t t=clock();

    heapSort(a,n);

    t=clock()-t;

    printf("%f %d\n", (double)t/CLOCKS_PER_SEC,n);

    return isSane(a,n);
}

// Checks if a heap is sane
void heapSanity(int *a,int i,int n){
    if( left(i) < n)
        if( a[i] >= a[left(i)] )
            heapSanity(a,left(i),n);
        else{
            int l=left(i);
            fprintf(stderr,"ERROR!! heap not sane %d %d\n", a[i], a[left(i)]);
        }

    if( right(i) < n )
        if( a[i] >= a[right(i)] )
            heapSanity(a,right(i),n);
        else{
            int r=right(i);
            fprintf(stderr,"ERROR!! heap not sane %d %d\n", a[i], a[right(i)]);
        }
}

// Returns the left children
int left(int i){
    return 2*i+1;
}

// Returns the right children
int right(int i){
    return 2*i+2;
}

// Swap 2 elements
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

// When called on a tree node it makes sure that this node has the heap property
void heapify(int *a, int n, int i){
    int l,r,bigger;
    l = left(i);
    r = right(i);

    if(l<n && a[l] > a[i]){
        bigger=l;
    }else{
        bigger=i;
    }

    if(r<n && a[r]>a[bigger]){
        bigger=r;
    }

    if(bigger!=i){
        swap(&a[i],&a[bigger]);
        heapify(a,n,bigger);
    }

}

// Returns the top element on the heap and calls heapify to maintain the structure
int heapExtract(int *a, int n){
    int bigger;

    bigger=a[0];
    a[0]=a[n-1];
    heapify(a,n-1,0);
    return bigger;
}

// Calls the heapify function on all tree nodes that isn't a leaf
void buildHeap(int *a,int n){
    int i;

    for(i=(n-1)/2;i>=0;i--){
        heapify(a,n,i);
    }
}

// The heap sort function
void heapSort(int *a,int n){
    int i;

    buildHeap(a,n);
    heapSanity(a,i,n);
    for(i=n-1;i>0;i--){
        swap(&a[0],&a[i]);
        heapify(a,i,0);
    }
}

// Simple print function for the data vector
void print(int *a,int n){
    int i;

    for(i=0;i<n;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}

// Checks if the algorithm is working, the time for this isn't counted into the answer
int isSane(int *a, int n){
    int flag=0,m;
    for(m=1;m<n;m++){
        if(a[m-1]>a[m]){
            int j;
            puts("");
            for(j=m-3;j<m+3;j++){
                printf("%d ",a[j]);
            }
            flag=1;
        }
    }
    if(flag){
        fprintf(stderr,"ERROR! Data not sorted!!!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
