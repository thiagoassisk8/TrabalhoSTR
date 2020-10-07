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

Para que uma tarefa consuma o máximo possivel de um processador, o melhor a se fazer para cosneguir isso seria colocar essa tarefa dentro de um loop. Iremos aproveitar o inicio do script mostrado ali em cima

Para isso, um *loop* utilizando a estrutura *for* foi utilizado. O *loop* só tem a função de contar até 1 milhão e mostrar o número no console.

~~~c
for (int i = 0; i < 1000000; i++) {
    printf("%d\n", i);
}
~~~

Ao colocar um *loop* para contar até 1 milhão, o processador é consumido o máximo possível.
