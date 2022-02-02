#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void printBinary ( int * a, int len ) {

    for ( int i = 0; i < len; i++ )
        printf( "%d", a[i] );
    printf( "\n" );

}

void binary ( int * a, int k, int pos, int p ) {
    
    if ( pos == k ) {
        printBinary ( a, k );
        return;
    }

    a[pos] = p;
    if ( ! p )
        binary ( a, k, pos + 1, p );
    binary ( a, k, pos + 1, ! p );

}

int main ( void ) {

    int * a = ( int* ) calloc ( LEN, sizeof ( *a ) );
    binary ( a, LEN, 0, 0 );
    binary ( a, LEN, 0, 1 );
    free ( a );
    return 0;

}