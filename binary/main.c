#include <stdio.h>
#include <stdlib.h>

#define LEN 3

void printBinary ( int * a, int len ) {
    for ( int i = 0; i < len; i++ )
        printf( "%d", a[i] );
    printf( "\n" );
}

void binary ( int * a, int k, int pos ) {
    
}

int main ( void ) {
    int * a = ( int* ) calloc ( LEN, sizeof ( *a ) );
    binary ( a, LEN, 0 );
    free ( a );
    return 0;
}