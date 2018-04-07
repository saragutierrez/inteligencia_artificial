#include <stdio.h>
#include <stdlib.h>
#include "biblga.h"  //Usando direto no diretorio
#include <math.h>
//Par�metros:
/*extern struct gaopt {int maxpop;
                     int nger;
                     float pmut;
                     int nbits;
                     unsigned char *best;
                     int nbytes;
                     float *fit;
                     unsigned int *ind;
                     unsigned char *pop;
                     unsigned nshow;     };
*/
struct gaopt g = {500, //Tamanho da popoulacao
                  100, //Numero de geracoes //300
                  10,  //Percentual de mutacao
                  16,  //Numero de bits a otimizar
                  0,   //Ponteiro para a melhor solucao
                  0,   //Numero debyte (calcula automaticamente)
                  0,   //Nao usar
                  0,   //Nao usar
                  0,   //Ponteiro para a populacao
                  1    //Numero de solucoes mostradas a cada geracao (acumula na tela)
                   };
float func1 (unsigned char *p, int n); //Fun��o de fitness para o exemplo

int main(void) {
    int i;
    g = ga(g, func1);

    printf("Usando %d bytes.\n\n",g.nbytes);
    for (i=0; i<g.nbytes; i++)
        printf("%d ",g.best[i]);

    getchar();
    return 0;
}

//Escrever qualquer fun��o de fitness *p s�o os bytes a serem otimizados e n (autom�tico)
//o numero de bytes usados
float func1(unsigned char *p, int n) {
int j;
float x1, x2, err2, err;
unsigned int ix;
x1 = *(p+0);
x2 = *(p+1);

err = abs(abs( pow(x1,3) - pow(x2,2)) - 7052);
err2 = abs(abs(3*x1)+(7*x2)-392);
//return(1.0/(1+abs(abs(x2-x1)-11.)+ abs(abs(x3-x2)-13.)+abs(abs(x4-x3)-17. )));
return (1./(err+err2));
//return 1./(1+abs(x1+x2 - abs(x3-x4)));   //  Maximiza a soma dos bytes (o resultado deve ser 255 255 255 255
}

