#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 

#define ITERACOES 50000
int main(int argc, char **argv)
{
    double r, pi = 1;
    int i, j;
    int maiorParte, demaisPartes = 0;
    int mod;
    int num_proc = 3;
    int tarefas[num_proc * 2];
 
    mod = ITERACOES % num_proc;

    if(mod != 0){
        //nao é divisivel o primeiro pega a mior parte
        maiorParte = ((ITERACOES - mod) / num_proc) + mod;
        demaisPartes = (ITERACOES-mod)/ num_proc;
    } else {
        maiorParte = (ITERACOES/num_proc);
    }

    int inicio, fim, valorTarefa;
    for (i = 0 ; i < num_proc ; i++){
        if(demaisPartes == 0){
            valorTarefa = maiorParte;
        } else if(i == 0) {
            valorTarefa = maiorParte;
        } else {
            valorTarefa = demaisPartes;
        }
        if(i == 0){
            inicio = 0;
            fim = valorTarefa;
        } else {
            inicio = fim;
            fim += valorTarefa;
        }

        tarefas[i] = inicio;
        tarefas[i+1] = fim;
        
    }
    pi = 1;
    for(int k = 0 ; k < num_proc ; k++){
        printf("Processo : %d ---> ", k);
        printf("De %d Ate %d\n", tarefas[k], tarefas[k+1]);
        for (i = tarefas[k]; i < tarefas[k+1]; i++) {
            r = 2;
            for (j = i; j ; j--)
                r = 2 + sqrt(r);
            r = sqrt(r);
    //
            pi *= (r / 2);
        }
    }
    pi = 2 / pi;
       printf("PI teste = %1.20f\n", pi);
    return 0;
}
