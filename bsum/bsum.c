#include <stdio.h>
#include <stdlib.h>

#define N 2

void print_bin ( int * bin, int len ) {
    for ( int i = 0; i < len; i++ )
        printf ( "%d", bin[i] );
    printf ( "\n" );
}

int bsum ( int * bin, int len, int pos, 
            int next, int n, int sum ) {

    if ( pos == len ) {
        print_bin ( bin, len );
        return 1;
    }

    int cnt = 0;
    bin[pos] = next;

    if ( pos < ( len / 2 ) - 1 ) {
        cnt += bsum ( bin, len, pos + 1, 0, n, sum );
        cnt += bsum ( bin, len, pos + 1, 1, n, sum + 1 );
    } else {
        //If either one of these conditions is true, the rest will be filled with 0's or 1's
        if ( ! sum )
            cnt += bsum ( bin, len, pos + 1, 0, n, sum );
        else if ( n == sum )
             cnt +=bsum ( bin, len, pos + 1, 1, n, sum );
        //------------------------------------------------------------------------------------
        else {
            cnt += bsum ( bin, len, pos + 1, 0, n - 1, sum );
            cnt += bsum ( bin, len, pos + 1, 1, n - 1, sum - 1 );
        } 
    }

    return cnt;
}

int main ( void ) {

    int * bin = ( int* ) calloc ( N * 2, sizeof ( *bin ) );
    int cnt = 0;
   
    cnt += bsum ( bin, N * 2, 0, 0, N, 0 );
    cnt += bsum ( bin, N * 2, 0, 1, N, 1 );
    printf( " = %d\n", cnt );
   
    free ( bin );
    return 0;

}