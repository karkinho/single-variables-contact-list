#include "lib.h"

int count = 1 , quantity = 0;

int main( int argc , char *argv[] ) {
    /*
    ======================  
    main

    calls the functions that will make the tests.
    ======================
    */
    if ( argc == 0 ) {
        exit( 0 );
    }
    
    sscanf( argv[1] , "%d" , & quantity );

    add();
    printf( "4\n" );
    searchall();
    removeall();
    printf( "4\n" );
    printf( "5\n" );
    return 0;
}

void add( ){
    /*
    ======================  
    add

    adds entry's to the data structure.
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "1\n" );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        printf( "%d\n" , count );
        count++;
    }
}

void searchall( ) {
    /*
    ======================  
    searchall

    searchs all entry's in the data structure
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "3\n" );
        printf( "%d\n" , count );
        count++;
    }
}

void removeall( ) {
    /*
    ======================  
    searchall

    removes all entry's in the data structure
    ======================
    */
    count = 1;
    while ( count <= quantity ) {
        printf( "2\n" );
        printf( "%d\n" , count );
        count++;
    }
}
