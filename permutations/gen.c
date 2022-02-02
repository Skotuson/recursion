#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TEST_MAX 50
#define ARR_MAX 11

typedef unsigned long long ull;

ull fact ( int n ) {
    if ( !n )
        return 1;
    return n * fact ( n - 1 );
}

void generateUnique ( int cnt, ull * perm ) {
    printf("{ ");
    for ( int i = 0; i < cnt; i++ ) {
        if ( i ) 
            printf( ", " );
        printf( "%d", i + 1 );
    }
    printf(" };\n");
    *perm = fact ( cnt );
}

void generateAll ( int cnt, ull * perm ) {
    ull div = 1, dup = 0;
    int n = 0;
    printf("{ ");
    for ( int i = 0; i < cnt; i++ ) {
        if ( !dup-- ) {
            dup = rand() % ( cnt - i );
            n = i + 1;
            div *= fact ( dup + 1 );
        }
        if ( i ) 
            printf( ", " );
        printf( "%d", n );
    }
    printf(" };\n");
    *perm = fact ( cnt );
    if ( div )
        *perm /= div;
}

int main ( void ) {
    
    srand ( time ( NULL ) );
    
    ull r = 0;
    int arr = 0;
    for ( int i = 0; i < TEST_MAX; i++ ) {
        printf("int arr%d[] = ", arr );
        generateAll ( rand() % ARR_MAX + 1, &r );
        printf ( "cnt = 0;\n" );
        printf ( "permutations ( arr%d, sizeof ( arr%d ) / sizeof ( arr%d[0] ), 0, &cnt );\n", arr, arr, arr );
        printf( "assert ( cnt == %llu );\n\n", r );
        arr++;
    }

}