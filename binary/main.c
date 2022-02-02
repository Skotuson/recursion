#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void printBinary ( int * a, int len ) {

    for ( int i = 0; i < len; i++ )
        printf( "%d", a[i] );
    printf( "\n" );

}

void binary ( int * a, int k, int pos, int p ) {
    
    a[pos] = p;

    if ( pos == k - 1 ) {
        printBinary ( a, k );
        return;
    }

    binary ( a, k, pos + 1, 0 );
    if ( ! p )
        binary ( a, k, pos + 1, 1 );

}

int main ( void ) {

    int * a = ( int* ) calloc ( LEN, sizeof ( *a ) );
    binary ( a, LEN, 0, 0 );
    binary ( a, LEN, 0, 1 );
    free ( a );
    return 0;

}