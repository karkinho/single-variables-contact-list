#include "lib.h"

int count = 1;

int main( ) {
    /*
    ======================  
    main

    calls the functions that will make the tests.
    ======================
    */
    add();
    searchall();
    removeall();
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
