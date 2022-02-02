#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

int cmp ( const void * a, const void * b ) {
    const int aa = *( int* ) a;
    const int bb = *( int* ) b;
    
    if ( aa < bb ) return -1;
    if ( aa > bb ) return 1;
    return 0;
}

void printArr ( int * arr, int size ) {
    for ( int i = 0; i < size; i++ )
        printf( "%d ", arr[i] );
    printf( "\n" );
}

void swap ( int * a, int * b ) {
    int c = *a;
    *a = *b;
    *b = c;
}

void permutations ( int * a, int size, int pos, ull * cnt ) {
    
    if ( pos == size - 1 ) {
        (*cnt)++;
        printArr ( a, size );
        return;
    }
    
    int last = a[pos];

    for ( int i = pos; i < size; i++ ) {
        if ( ( a[pos] == a[i] || a[i] == last ) && i != pos )
            continue;
        swap ( &a[pos], &a[i] );
        permutations ( a, size, pos + 1, cnt );
        swap ( &a[pos], &a[i] );
        last = a[i];
    }

}

int main ( void ) {

    ull cnt;

    int a[] = { 1, 1, 1, 1, 5 };
    cnt = 0;
    //qsort ( a, sizeof ( a ) / sizeof ( a[0] ), sizeof ( a[0] ), cmp );
    permutations ( a, sizeof ( a ) / sizeof ( a[0] ), 0, &cnt );
    return 0;
}