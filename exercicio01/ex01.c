    #include <pthread.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <unistd.h>
     
    void *PrintHello(void *threadid){//função a ser executada quando uma thread for criada
      long id;
      id = (long)threadid;//conversão de void pra long
      printf("Thread %ld: Olá mundo!\n", id);
      pthread_exit(NULL); //finalização da thread
    }
     
    int threads(){
      pthread_t t1, t2,t3; //criando t1, t2 e t3 do tipo thread
      int create; //variável que recebe o retorno da função pthread_create()
      long num; //identificador da thread
      for (int i = 0; i < 1000; i++) {
      num = 1;
      printf("Main: criando a thread %ld\n", num);
      create = pthread_create(&t1, NULL, PrintHello, (void *)num); //criando thread 1
        
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


