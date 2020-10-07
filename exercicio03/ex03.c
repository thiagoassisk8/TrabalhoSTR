#define _GNU_SOURCE
#include <stdlib.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <sched.h>
#include <stdio.h>
#include <stdbool.h>
#include <pthread.h>
#include <semaphore.h>


struct c {
	int saldo;
};


sem_t semaforoTransferencia;

int numeroTransferencias = 0;
typedef struct c conta;

conta from, to;
int valor;
bool inverteConta;
int transferenciasFinalizadas = 0;
//The child thread will execute this function
void* transferencia(void *arg){


	sem_wait(&semaforoTransferencia);

	numeroTransferencias++;
	printf("Iniciando transferencia: %d \n" , numeroTransferencias);


	inverteConta = rand() & 1;
	if(inverteConta == true){
		if (from.saldo >= valor){
			from.saldo -= valor;
			to.saldo += valor;
		}
	}else{
		if (to.saldo >= valor){
			to.saldo -= valor;
			from.saldo += valor;
		}	
	}
	printf("+------------------------------------+\n");
	printf("|Transferência concluída com sucesso!|\n");
	printf("\n Saldo de c1:    %d\n", from.saldo);
	printf("\n Saldo de c2:    %d\n", to.saldo);
	printf("+------------------------------------+\n");
	sem_post(&semaforoTransferencia);
}	

int main(){
	void* stack; 
	int i;

    pthread_t vetorThreads[100];
	sem_init(&semaforoTransferencia, 0 , 1);

	// Todas as contas começam com saldo 100
	from.saldo = 100;
	to.saldo = 100;
	valor = 10;

	for(i = 0; i < 100; i++){
		pthread_create(&vetorThreads[i], NULL, *transferencia, NULL);
	}

	printf("Todas as threads foram criadas\n\n\n\n");

	
	for(i = 0; i < 100; i++){
		pthread_join(vetorThreads[i], NULL);
		printf("Thread: %ld terminada!\n", vetorThreads[i]);
	}


	printf("Transferencias realizadas: %d\n", numeroTransferencias);

	return 0;
}











