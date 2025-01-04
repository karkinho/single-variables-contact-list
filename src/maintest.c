#include "lib.h"

void *pBuffer = NULL;

int main( ) {
    /*
    ======================  
    main

    Starts the data structure, the menu and clears the data structure when the pogramns ends; 
    ======================
    */
    reset();
    menu();
    clear();
    return 0;
}

void menu() {
    /*
    ======================  
    menu

    Prints the menu in the terminal and gets the input of the action the user wants to make and calls the respective function.
    ======================
    */
    while ( *( int *)( pBuffer + jumpAux ) != 5 ) {
        fgets( ( char * )( pBuffer + jumpBuff ) , 10 , stdin );
        *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
        sscanf( ( char * )( pBuffer + jumpBuff ) , "%d" , ( int *)( pBuffer + jumpAux) );

        switch ( *( int *)( pBuffer + jumpAux ) ) {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3: 
            search();
            break;     
        case 4:
            list();
            break;
        case 5:
            break;   
        default:
            break;
        }
    }
}

void pop() {
    /*
    ======================  
    pop

    Removes a entry in the data structure, recives a name from the user and removes the data tha has the same name, if there is no entry with that name nothing happens, in the test version if the data struct is empty or the entry is not found the program will exit mid execution.
    ======================
    */ 
    if ( empty( ) ) {
        printf( "----------------------------\n" );
        printf( "Agenda Vazia\n" );
        printf( "----------------------------\n" );
        exit( 0 );
        return;
    }
    fgets( ( char * )( pBuffer + jumpBuff ) , lenghtName + 1 , stdin );
    *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
    *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
    *( void *** )( pBuffer + jumpAux ) = ( void ** )( pBuffer + jumpHead );
    while ( *( void ** )( **( void *** )( pBuffer + jumpAux ) + jumpNext ) != NULL ) {
        if ( 0 == strncmp( ( char * )( pBuffer + jumpBuff ) , ( char * )( **( void *** )( pBuffer + jumpAux ) + jumpName ) , lenghtName )  ) {
            *( void ** )( pBuffer + jumpBuff ) = **( void *** )( pBuffer + jumpAux );
            **( void *** )( pBuffer + jumpAux ) = *( void **)( **( void *** )( pBuffer + jumpAux ) +    jumpNext );
            free( *( void ** )( pBuffer + jumpBuff ) );
            return;
        }
        *( void *** )( pBuffer + jumpAux ) = ( **( void *** )( pBuffer + jumpAux ) + jumpNext );
    }
    if ( 0 == strncmp( ( char * )( pBuffer + jumpBuff ) , ( char * )( **( void *** )( pBuffer + jumpAux ) + jumpName ) , lenghtName )  ) {
        *( void ** )( pBuffer + jumpBuff ) = **( void *** )( pBuffer + jumpAux );
        **( void *** )( pBuffer + jumpAux ) = *( void **)( **( void *** )( pBuffer + jumpAux ) + jumpNext );
        free( *( void ** )( pBuffer + jumpBuff ) );
        return;
    } else {
        printf( "\nA Pessoa Não Está Na Agenda\n" );
        exit( 0 );
    }
}

void search() {
    /*
    ======================  
    search

    Recives a name from the user and searchs the data structure for that name, if the name is found it prints all the information of that entry, if isnot found it prints that there is no entry with that name, in the test version if the data struct is empty or the entry is not find the program will exite.
    ======================
    */
    if ( empty( ))  {
        printf( "----------------------------\n" );
        printf( "Agenda Vazia\n" );
        printf( "----------------------------\n" );
        return;
    }
    fgets( ( char * )( pBuffer + jumpBuff ) , lenghtName + 1 , stdin );
    *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
    *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
    while ( *( void ** )( *( void ** )( pBuffer + jumpAux ) + jumpNext ) != NULL ) {
        if ( 0 == strncmp( ( char * )( pBuffer + jumpBuff ) , ( char * )( *( void ** )( pBuffer + jumpAux ) + jumpName ) , lenghtName ) ) {
            return;
        }
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( *( void ** )( pBuffer + jumpAux ) + jumpNext );
    }
    if ( 0 == strncmp( ( char * )( pBuffer + jumpBuff ) , ( char * )( *( void ** )( pBuffer + jumpAux ) + jumpName ) , lenghtName ) ) {
        return;
    } else {
        printf( "\nA Pessoa Não Está Na Agenda\n" );
    }
}

void clear() {
    /*
    ======================  
    clear

    Free's the data structure.
    ======================
    */
    if ( !empty() ) {
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
        while ( *( void ** )( *( void ** )( pBuffer + jumpAux ) + jumpNext ) != NULL ) {
            *( void ** )( pBuffer + jumpAux ) = *( void ** )( *( void ** )( pBuffer + jumpAux ) + jumpNext );
            free( *( void ** )( pBuffer + jumpHead ) );
            *( void ** )( pBuffer + jumpHead ) = *( void ** )( pBuffer + jumpAux );
        }
        free( *( void ** )( pBuffer + jumpAux ) );
    }
    *( void ** )( pBuffer + jumpHead ) = NULL;
    *( void ** )( pBuffer + jumpAux ) = NULL;
    free( pBuffer );
    pBuffer = NULL;
}

void push() {
    /*
    ======================  
    push

    Puts a new entry in the end of the data structure.
    ======================
    */
    if ( !empty() ) {
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
        while ( *( void ** )(( *( void ** )pBuffer ) + jumpNext ) != NULL ) {
            *( void ** )( pBuffer + jumpAux ) = *( void ** )( ( *( void ** )( pBuffer + jumpAux ) ) + jumpNext );
        }
        *( void ** )( (*( void ** )( pBuffer + jumpAux ) ) + jumpNext ) = malloc( sizePerson );
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( (*( void ** )( pBuffer + jumpAux ) ) + jumpNext );          
    } else { 
        *( void ** )( pBuffer + jumpHead ) = malloc( sizePerson ); 
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
    }
    if ( *( void ** )( pBuffer + jumpAux ) == NULL ){
        printf( "Memória Não Alocada\n" );
        exit(0);
    }
    fgets( ( char * )( pBuffer + jumpBuff ) , lenghtName + 1 , stdin );
    *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
    strncpy( ( char * )( ( *( void ** )( pBuffer + jumpAux ) ) + jumpName ) , ( char * )( pBuffer + jumpBuff ) , lenghtName );
    
    fgets( ( char * )( pBuffer + jumpBuff ) , 10 , stdin );
    *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
    sscanf( ( char * )( pBuffer + jumpBuff ) , "%d" , ( int *)( ( *( void **)( pBuffer + jumpAux) ) + jumpAge ) );
    
    fgets( ( char * )( pBuffer + jumpBuff ) , lenghtEmail + 1 , stdin );
    *( char * )( pBuffer + jumpBuff + strcspn( ( char * )( pBuffer + jumpBuff ) , "\n" ) ) = '\0';
    strncpy( ( char * )( *( void ** )( pBuffer + jumpAux ) + jumpEmail ) , ( char * )( pBuffer + jumpBuff ) , lenghtEmail );

    *( void ** )( ( *( void ** )( pBuffer + jumpAux ) ) + jumpNext ) = NULL;
}

void list() {
    /*
    ======================  
    list

    Prints all the entry's in the data structure.
    ======================
    */
    printf( "\n ");
    if ( !empty() ) {
        *( void ** )( pBuffer + jumpAux ) = *( void ** )( pBuffer + jumpHead );
        while ( *( void ** )(( *( void ** )( pBuffer + jumpAux ) ) + jumpNext ) != NULL ) {
            printf( "----------------------------\n" );
            printf( "Nome: %s\n" ,  ( char * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpName ) );
            printf( "Idade: %d\n" ,  *( int * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpAge ) );
            printf( "Email: %s\n" ,  ( char * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpEmail ) );
            *( void ** )( pBuffer + jumpAux ) = *( void ** )( ( *( void ** )( pBuffer + jumpAux ) ) + jumpNext );
        }
        printf( "----------------------------\n" );
        printf( "Nome: %s\n" ,  ( char * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpName ) );
        printf( "Idade: %d\n" ,  *( int * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpAge ) );
        printf( "Email: %s\n" ,  ( char * )(( *( void ** )( pBuffer + jumpAux ) ) + jumpEmail ) );
    } else {
        printf( "----------------------------\n" );
        printf( "Agenda Vazia\n" );
    }
    printf( "----------------------------\n" );
    printf( "\n" );
}

void reset() {
    /*
    ======================  
    reset

    Starts the data structure.
    ======================
    */
    pBuffer = malloc( sizeVariables );
    if ( pBuffer == NULL ) {
        printf( "Memória não alocada\n" );
        exit( 0 );
    }
    *( void ** )( pBuffer + jumpAux ) = NULL;
    *( void ** )( pBuffer + jumpHead ) = NULL;
}

bool empty() {
    /*
    ======================  
    empty

    returns true if the data structure is empty and false if it's not.
    ======================
    */
    if ( *( void ** )( pBuffer + jumpHead ) == NULL ) {
        return true;
    }
    return false;
}

