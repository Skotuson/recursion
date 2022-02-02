#include <stdio.h>
#include <stdlib.h>

#define N 2

void print_bin ( int * bin, int len ) {
    for ( int i = 0; i < len; i++ )
        printf ( "%d", bin[i] );
    printf ( "\n" );
}

void bsum ( int * bin, int k, int pos, int n ) {
    
}

int main ( void ) {

    int * bin = ( int* ) calloc ( N * 2, sizeof ( *bin ) );
    bsum ( bin, N * 2, 0, N );
    free ( bin );
    return 0;

}