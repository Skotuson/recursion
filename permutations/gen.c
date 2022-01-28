#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 11

typedef unsigned long long ull;

ull fact ( int n ) {
    if ( n > MAX || !n )
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

}

int main ( void ) {
    
    srand ( time ( NULL ) );
    
    ull r = 0;
    char arr = 'a';
    for ( int i = 0; i < MAX; i++ ) {
        printf("int %c[] = ", arr );
        generateUnique ( i + 1, &r );
        printf ( "cnt = 0;\n" );
        printf ( "permutations ( %c, sizeof ( %c ) / sizeof ( %c[0] ), 0, &cnt );\n", arr, arr, arr );
        printf( "assert ( cnt == %llu );\n\n", r );
        arr++;
    }

}