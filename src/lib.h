#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// declarations from main.c

#define lenghtName 10 // reads 2 less than it's size, lenght of name can't be less than 10, because it's used as size to a buffer that reads ints.
#define lenghtEmail 40 // lenght of email needs to be higher or equal to the lenght of name and  bigger than sizeof( void * );
#define lenghtBuff lenghtEmail + 1
#define sizePerson sizeof( int ) + sizeof( char ) * ( lenghtName + lenghtEmail ) + sizeof( void * )
#define sizeVariables sizeof( void ** ) + sizeof( void * ) + sizeof( char ) * lenghtBuff
#define jumpAux 0
#define jumpHead sizeof( void ** )
#define jumpBuff sizeof( void ** ) + sizeof( void * )
#define jumpAge 0
#define jumpName sizeof( int )
#define jumpEmail sizeof( int ) + sizeof( char ) * lenghtName
#define jumpNext sizeof( int ) + sizeof( char ) * ( lenghtEmail + lenghtName )

void pop(); 
void push();   
void reset(); 
void list();  
void search(); 
void clear(); 
bool empty(); 
void menu(); 

// declarations from tests.c

void add();
void searchall();
void removeall();

