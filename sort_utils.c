#ifndef _SORT_UTILS
#define _SORT_UTILS

#include <stdio.h>
#include <stdlib.h>

#include "sort_utils.h"

int* vector_fill_almost_sorted(int n){
    int *v = (int*)malloc(sizeof(int) * n);

    int i;

    for ( i = 0 ; i < n ; i++){
        v[i] = i;
    }

    for ( i = 0 ; i < n ; i++){
        int r = rand()%7-3;

        if (i + r >= 0 && i + r < n){
            vector_swap(&v[i], &v[i+r]);
        }
    }

    return v;
}

int* vector_fill_unique(int n){
    int *v = (int*)malloc(sizeof(int) * n);

    int i;

    for ( i = 0 ; i < n ; i++){
        v[i] = i;
    }

    for ( i = 0 ; i < n ; i++){
        vector_swap(&v[i],&v[rand()%n]);
    }

    return v;
}

int* vector_fill_reverse(int n){
    int *v = (int*)malloc(sizeof(int) * n);

    int i;

    for (i = 0 ; i < n ; i++){
        v[i] = n-i;
    }

    return v;
}

int* vector_fill_few_unique(int n){
    int *v = (int*)malloc(sizeof(int) * n);

    int i;

    for (i = 0 ; i < n ; i++){
        v[i] = rand()%3+1;
    }

    return v;
}

void vector_swap(int *a,int *b){
    int t;
    t=*a;
    *a=*b;
    *b=t;
}

#endif /* _SORT_UTILS */
