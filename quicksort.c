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

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sort_utils.h"

int partition(int *a, int l, int h);
void quickSort(int *a, int l, int h);
void print(int *a,int n);
void swap(int *a, int *b);
int isSane(int *a, int n);

int compareint (const void * a, const void * b)
{
    if ( *(int*)a <  *(int*)b ) return -1;
    if ( *(int*)a == *(int*)b ) return 0;
    if ( *(int*)a >  *(int*)b ) return 1;
}

int main(int argc, char *argv[]){
    int n = atoi(argv[1]);
    int *a = vector_fill_almost_sorted(n);

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

    //qsort(a, n, sizeof(int), compareint);
    quickSort(a,0,n-1);

    t=clock()-t;

    printf("%f %d\n", (double)t/CLOCKS_PER_SEC,n);

    return isSane(a,n);
}

int partition(int *a, int l, int h){
    int i, j;
    int pivot;

    // Middle element as pivot
    //j = l + (int)(h-l)/2;

    // Random element as pivot
    j = l + rand() % (h-l);

    pivot = a[j];
    swap(&a[j],&a[h]);

    // Last element as pivot
    //pivot = a[h];

    i=l;

    for(j=l;j<h;j++){
        if(a[j]<pivot){
            swap(&a[i++],&a[j]);
        }
    }

    swap(&a[i],&a[h]);
    return i;
}

void quickSort(int *a, int l, int h){
    if(l<h){
        int p = partition(a,l,h);
        quickSort(a,l,p-1);
        quickSort(a,p+1,h);
    }
}

// Swap 2 elements
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
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
            flag=1;
        }
    }
    if(flag){
        fprintf(stderr,"ERROR! Data not sorted!!!\n");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
