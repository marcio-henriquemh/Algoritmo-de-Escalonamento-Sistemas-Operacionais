
    #include<stdio.h>
    #include<stdlib.h>
    #define MAX 2

    // Algoritmo de escalonamento Round Robin
    // Discente: Márcio Henrique Matos de Freitas
    // Estudo sobre Projeto e Análise de Algoritmos
    // Referência: Sistemas Operacionais - tanembaum
    // Função principal

   typedef struct processo {
       int id;
       int tempo_execucao;
       int tempo_restante;
   } Processo;


   void criando_a_fila(Processo fila[], int n) {
       for(int i = 0; i < n; i++) {
           fila[i].id = i + 1;
           printf("Informe o tempo de execucao do processo %d: ", fila[i].id);
           scanf("%d", &fila[i].tempo_execucao);
           fila[i].tempo_restante = fila[i].tempo_execucao;
       }
   }

void verificando_fila_vazia(Processo fila[], int n) {
    for(int i = 0; i < n; i++) {
        if(fila[i].tempo_restante > 0) {
            return;
        }
    }
    printf("Todos os processos foram concluídos.\n");
    exit(0);
}

   int main() {
       Processo fila[MAX];
       int quantum;

       criando_a_fila(fila, MAX);

       printf("Informe o valor do quantum: ");
       scanf("%d", &quantum);

       while(1) {
           verificando_fila_vazia(fila, MAX);
           for(int i = 0; i < MAX; i++) {
               if(fila[i].tempo_restante > 0) {
                   if(fila[i].tempo_restante > quantum) {
                       fila[i].tempo_restante -= quantum;
                       printf("Processo %d executado por %d unidades de tempo. Tempo restante: %d\n", fila[i].id, quantum, fila[i].tempo_restante);
                   } else {
                       printf("Processo %d executado por %d unidades de tempo. Processo concluído.\n", fila[i].id, fila[i].tempo_restante);
                       fila[i].tempo_restante = 0;
                   }
               }
           }
       }

       return 0;
   }    