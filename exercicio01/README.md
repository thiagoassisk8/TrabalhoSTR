# Exercício 1 - Processos

## Descrição

O primeiro exercicio visa nos ensinar na prática o que é um processo. Logo de cara nos mostrando o início de um script em C, nele como podemos ver abaixo 
temos uma função main() somente com uma variavel inteira declarada igual a zero
~~~c
#include <stdio.h>
int main(){
    int i = 0;
}
~~~
Em seguida o exercício pede para que criemos um programa que execute uma tarefa na maquina que consuma o máximo de processador possível

## Resolução


~~~c
  #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
     
    void *PrintHello(void *threadid){
      long id;
      id = (long)threadid;//conversão de void pra long
      printf("Thread %ld: Olá mundo!\n", id);
      pthread_exit(NULL); 
    }
     
    int threads(){
      pthread_t t1, t2,t3; 
      int create; 
      long num; 
      for (int i = 0; i < 1000; i++) {
      num = 1;
      printf("Main: criando a thread %ld\n", num);
      create = pthread_create(&t1, NULL, PrintHello, (void *)num); 
        
      num = 2;
      printf("Main: criando a thread %ld\n", num);
      create = pthread_create(&t1, NULL, PrintHello, (void *)
      num); //criando thread 2

      num = 3;
      printf("Main: criando a thread %ld\n", num);
      create = pthread_create(&t1, NULL, PrintHello, (void *)
      num); //criando thread 2        
             
    
  }
           
    }

    int main(void){
    for (int i = 0; i < 1000; i++) {
        threads();

        printf("%d \n processo número", i);
    }

    return 0;
}

~~~


