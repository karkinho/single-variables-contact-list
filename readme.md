# Single Variable Contact List || Lista De Contatos De Variável Única

The objective of this project is to create a contact list that uses a single variable, a void pointer.

### PT-BR

O objetivo deste projeto é criar uma lista de contatos onde o programa usa apenas uma única variável, sendo um ponteiro void.

## Project Details || Detalhes Do Projeto

To store the data of the contact list, a linked list without a head is used, inserting at the end and allowing removal from any position in the list.

### PT-BR

Para armazenar as informações da lista de contatos, foi utilizada uma lista encadeada sem cabeça, a inserção sempre será feita no final da lista e pode-se remover de qualquer posição da lista.

### Memory space in the void pointer

Space of sizeof(void \*_): Used as the auxiliary pointer of the program.
Space of sizeof(void _): Used as the head of the linked list.
Space of sizeof(sizeof(char) - (lengthEmail + 1)): Space used for reading stdin and, in the remove operation, is also used as a void \* to keep the address of the entry to be freed.

#### PT-BR

Organização de memória a partir do ponteiro void
Espaço de sizeof(void \*_): Utilizado como ponteiro auxiliar do programa.
Espaço de sizeof(void _): Utilizado como a cabeça da lista encadeada.
Espaço de sizeof(sizeof(char) - (lengthEmail + 1)): Espaço utilizado para leitura do stdin e, na operação de remoção, será utilizado também como um ponteiro void para guardar o endereço da entrada a ser desalocada.

### Entry's in the data structure || Entradas na estrutura de dados

Each entry in the data structure consists of a name, age, email, and a pointer to the next entry, in this order. Data is stored in an array, and pointer casts are used to access and modify the information.

#### PT-BR

Cada entrada na estrutura de dados contém nome, idade, e-mail e um ponteiro next, nesta exata ordem. As informações são armazenadas em um vetor e acessadas através de casts para leitura e escrita.

## main.c

C file that contains all the functions of the contact list.

### PT-BR

Arquivo C que contém todas as funções da lista de contatos.

## lib.h

Contains all the declarations of the functions of all C files of the project, and also contains defines that help to write the program, with information on where in memory the variables are located and their sizes.

### PT-BR

Contém todas as declarações de funções de todos os arquivos do projeto, além de defines que são utilizados para facilitar a escrita do programa, com informações sobre onde na memória estão localizadas as variáveis e seus tamanhos.

## maintest.c & test.c

maintest is the main file with suppressed printfs for better readability in the terminal during testing and added exits in case any tests fail.

test is a file that creates the test entries that will be processed by maintest via bash input redirection. It takes an integer value in the arguments, which defines how many times it will generate entries for the contact list.

### PT-BR

maintest.c é o arquivo principal com algumas modificações. Grande parte dos printf foram removidos para facilitar a visualização no terminal, e foram adicionadas saídas do programa para caso alguma falha ocorra.

test.c é um arquivo que cria as entradas de teste que serão captadas pelo maintest através de redirecionamento de entrada no bash. Ele recebe um número inteiro nos argumentos, que define quantas vezes ele criará entradas para o teste.

## How To Execute || Como Executar

All the execution and compiling commands are inside the Makefile. The key commands are:

make: Compiles the program and runs it.
make test: Compiles and runs the tests.
make val: Compiles and runs the tests using valgrind.

### PT-BR

Todos os comandos de execução estão dentro do Makefile, sendo os principais:

make: Compila o programa e o executa.
make test: Compila o programa e executa os testes.
make val: Compila e executa os testes usando o valgrind
