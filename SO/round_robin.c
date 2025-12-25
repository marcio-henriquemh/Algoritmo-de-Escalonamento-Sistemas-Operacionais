
    #include<stdio.h>
    #include<stdlib.h>
    #define MAX 2

    // Algoritmo de escalonamento Round Robin
    // Discente: Márcio Henrique Matos de Freitas
    // Estudo sobre Projeto e Análise de Algoritmos
    // Referência: Sistemas Operacionais - tanembaum
    // Função principal

    int main(){

    int vetor_processos[MAX];
    int j,i;
    int quantum=20;
    int tempo_processo[MAX];
    
for (int i = 0; i < MAX; i++){
    for ( j = 0; j < MAX; j++){

    printf("Informe o conteudo do processo:");
    scanf("%d",&vetor_processos[i]);
    printf("Informe o tempo gasto no processo");
    scanf("%d",&tempo_processo[j]);

}
    }


//criando a fila de processos
printf("Fila de processos:\n");
for ( i = 0; i < MAX; i++){
    printf("Processo %d com tempo de %d\n", vetor_processos[i], tempo_processo[i]);
}  
printf("\n");

// tempo em quantum
for ( j = 0; j < MAX; j++){

if (quantum<tempo_processo[j])
{
    //voltar para o final da fila
    printf("O processo %d voltou para o final da fila\n", vetor_processos[j]);
    tempo_processo[j]=tempo_processo[j]-quantum;
    printf("Tempo restante do processo %d é de %d\n", vetor_processos[j], tempo_processo[j]);

}

}
