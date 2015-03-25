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

void print(int *a,int n);
void swap(int *a, int *b);
int isSane(int *a, int n);
void insertionsort(int *a,int n);

int main(int argc, char *argv[]){
    int n=atoi(argv[1]);
    int *a=(int*)malloc(sizeof(int)*n);

    int i,j,m,flag;

    srand(time(NULL));

    for(i=0;i<n;i++){
        a[i]=rand()%n;
    }

    time_t t=clock();

    insertionsort(a,n);

    t=clock()-t;

    printf("%f %d\n", (double)t/CLOCKS_PER_SEC,n);

    return isSane(a,n);
}

// Insertion sort algorithm
void insertionsort(int *a, int n){
    int i,j,t;
    for(i=1;i<n;i++){
        t=a[i];
        for(j=i-1;j>=0 && a[j]>t;j--){
            a[j+1]=a[j];
        }
        a[j+1]=t;
    }
}

// Swap 2 elements
void swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
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

// Simple print function for the data vector
void print(int *a,int n){
    int i;

    for(i=0;i<n;i++){
        printf("%3d ",a[i]);
    }
    printf("\n");
}
