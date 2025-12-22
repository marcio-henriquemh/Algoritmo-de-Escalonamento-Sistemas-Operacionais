
#include<stdio.h>
#include<stdlib.h>

#define MAX_PROCESSES 5

typedef struct first_come_first_served
{
    int elementos[MAX_PROCESSES];
    int inicio,fim;
    int tempo_medio_espera;
}first_come_first_served;

//inicializar a fila 
void inicializarFila(first_come_first_served *fila){
    fila->inicio = 0;
    fila->fim = -1;
}

//verificar se a fila esta vazia

int fila_vazia(first_come_first_served *fila){
    
    return fila->fim < fila->inicio;
}

//verificar se esta cheia

int fila_cheia(first_come_first_served *fila){

    return fila->fim == MAX_PROCESSES-1;
}

//inserir na fila

int inserir_fila(first_come_first_served *fila){
    int valor;
    printf("Digite o valor a ser inserido na fila: ");
    scanf("%d",&valor);
    printf("tempo do processo %d inserido na fila",valor);
    if (fila_cheia(fila))
    {
        printf("fila esta cheia");
        return -1;
    }else{
        fila->fim++;
        fila->elementos[fila->fim] = valor;
        return 0;
    }
}

    //remover
int remover_fila(first_come_first_served *fila){
    int valor_removido;
    if (fila_vazia(fila))
    {
        printf("fila esta vazia");
        return -1;
    }else{
        valor_removido = fila->elementos[fila->inicio];
        fila->inicio++;
        return valor_removido;
    }
    
}
//calcular tempo de espera medio
int calcular_tempo_espera(first_come_first_served *fila){
    int tempo_espera = 0;
    int tempo_total = 0;
    for (int i = fila->inicio; i <= fila->fim; i++)
    {
        tempo_espera += tempo_total;
        tempo_total += fila->elementos[i];
    }
    fila->tempo_medio_espera = tempo_espera / (fila->fim - fila->inicio + 1);
    return fila->tempo_medio_espera;
}

int main(){
    first_come_first_served fila;
    inicializarFila(&fila);
    int opcao;
    do
    {
        printf("\n1 - Inserir processo na fila\n");
        printf("2 - Remover processo da fila\n");
        printf("3 - Calcular tempo medio de espera\n");
        printf("4 - Sair\n");
        printf("Digite a opcao: ");
        scanf("%d",&opcao);
        switch (opcao)
        {
        case 1:
            inserir_fila(&fila);
            break;
        case 2:
            printf("Processo removido: %d\n",remover_fila(&fila));
            break;
        case 3:
            printf("Tempo medio de espera: %d\n",calcular_tempo_espera(&fila));
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    } while (opcao != 4);
    
    return 0;
}