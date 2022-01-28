#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef unsigned long long ull;

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

    for ( int i = pos; i < size; i++ ) {
        swap ( &a[pos], &a[i] );
        permutations ( a, size, pos + 1, cnt );
        swap ( &a[pos], &a[i] );
    }

}

int main ( void ) {

    ull cnt;

    int a[] = { 1 };
    cnt = 0;
    permutations ( a, sizeof ( a ) / sizeof ( a[0] ), 0, &cnt );
    assert ( cnt == 1 );

    int b[] = { 1, 2 };
    cnt = 0;
    permutations ( b, sizeof ( b ) / sizeof ( b[0] ), 0, &cnt );
    assert ( cnt == 2 );

    int c[] = { 1, 2, 3 };
    cnt = 0;
    permutations ( c, sizeof ( c ) / sizeof ( c[0] ), 0, &cnt );
    assert ( cnt == 6 );

    int d[] = { 1, 2, 3, 4 };
    cnt = 0;
    permutations ( d, sizeof ( d ) / sizeof ( d[0] ), 0, &cnt );
    assert ( cnt == 24 );

    int e[] = { 1, 2, 3, 4, 5 };
    cnt = 0;
    permutations ( e, sizeof ( e ) / sizeof ( e[0] ), 0, &cnt );
    assert ( cnt == 120 );

    int f[] = { 1, 2, 3, 4, 5, 6 };
    cnt = 0;
    permutations ( f, sizeof ( f ) / sizeof ( f[0] ), 0, &cnt );
    assert ( cnt == 720 );

    int g[] = { 1, 2, 3, 4, 5, 6, 7 };
    cnt = 0;
    permutations ( g, sizeof ( g ) / sizeof ( g[0] ), 0, &cnt );
    assert ( cnt == 5040 );

    int h[] = { 1, 2, 3, 4, 5, 6, 7, 8 };
    cnt = 0;
    permutations ( h, sizeof ( h ) / sizeof ( h[0] ), 0, &cnt );
    assert ( cnt == 40320 );

    int i[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    cnt = 0;
    permutations ( i, sizeof ( i ) / sizeof ( i[0] ), 0, &cnt );
    assert ( cnt == 362880 );

    int j[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    cnt = 0;
    permutations ( j, sizeof ( j ) / sizeof ( j[0] ), 0, &cnt );
    assert ( cnt == 3628800 );

    int k[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };
    cnt = 0;
    permutations ( k, sizeof ( k ) / sizeof ( k[0] ), 0, &cnt );
    assert ( cnt == 39916800 );

    return 0;
}