#include <stdio.h>

#include "sort_utils.h"

int main(){
    int *a, i;

    puts("Nearly sorted");
    a = vector_fill_almost_sorted(20);
    for(i=0; i<20; i++){
        printf("%d ", a[i]);
    }

    puts("\n\nFew unique");
    a = vector_fill_few_unique(20);
    for(i=0; i<20; i++){
        printf("%d ", a[i]);
    }

    puts("\n\nReversed");
    a = vector_fill_reverse(20);
    for(i=0; i<20; i++){
        printf("%d ", a[i]);
    }

    puts("\n\nUnique");
    a = vector_fill_unique(20);
    for(i=0; i<20; i++){
        printf("%d ", a[i]);
    }

    puts("");
    return 0;
}
