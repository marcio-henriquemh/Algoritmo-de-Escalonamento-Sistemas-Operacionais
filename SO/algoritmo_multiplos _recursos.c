#include<stdio.h>


//Dados do sistema


/*

matriz de recusos


Recursos existentes (E)

| Recurso | Quantidade |     
| ------- | ---------- |    
| R1      | 2          |    
| R2      | 2          |      


Recuros disponiveis
A = (R1=0, R2=1)
/

Matriz de alocação (C)

| Processo | R1 | R2 |
| -------- | -- | -- |
| P1       | 1  | 0  |
| P2       | 1  | 1  |
| P3       | 0  | 0  |


Matriz de requisição (R)

| Processo | R1 | R2 |
| -------- | -- | -- |
| P1       | 0  | 1  |
| P2       | 1  | 0  |
| P3       | 1  | 1  |


Regra R_i<A

*/
#include <stdio.h>
#include <stdbool.h>

// Função para verificar deadlock
void verificar_deadlock(int linha, int coluna, int alocacao[linha][coluna], int disponivel[coluna], int requisicao[linha][coluna]) {
    int trabalho[coluna];
    bool finalizado[linha];
    
    // Inicialização
    for (int j = 0; j < coluna; j++) trabalho[j] = disponivel[j];
    for (int i = 0; i < linha; i++) finalizado[i] = false;

    int cont = 0;
    while (cont < linha) {
        bool encontrou = false;
        for (int i = 0; i < linha; i++) {
            if (!finalizado[i]) {
                int j;
                // Regra R_i <= A (Trabalho)
                for (j = 0; j < coluna; j++) {
                    if (requisicao[i][j] > trabalho[j]) break;
                }

                // Se todos os recursos necessários estao ok
                if (j == coluna) {
                    for (int k = 0; k < coluna; k++)
                        trabalho[k] += alocacao[i][k];
                    finalizado[i] = true;
                    encontrou = true;
                    cont++;
                    printf("Processo P%d executou e liberou recursos.\n", i + 1);
                }
            }
        }
        if (!encontrou) break; // Deadlock detectado ou fim do processo
    }

    bool deadlock = false;
    for (int i = 0; i < linha; i++) {
        if (!finalizado[i]) {
            printf("Deadlock detectado! Processo P%d esta travado.\n", i + 1);
            deadlock = true;
        }
    }
    if (!deadlock) printf("\nSistema seguro: Nenhum deadlock encontrado.\n");
}

int main() {
    int coluna, linha, opcao;

    // Precisamos definir o tamanho antes de declarar as matrizes
    printf("Informe a quantidade de processos (linhas): ");
    scanf("%d", &linha);
    printf("Informe a quantidade de tipos de recursos (colunas): ");
    scanf("%d", &coluna);

    int matriz_alocacao[linha][coluna];
    int recurso_disponivel[coluna]; // Tamanho deve ser 'coluna' (tipos de recurso)
    int matriz_de_requisicoes[linha][coluna];

    do {
        printf("\n--- MENU ---\n");
        printf("1 - Informar Matriz de Alocacao\n");
        printf("2 - Informar Recursos Disponiveis\n");
        printf("3 - Informar Matriz de Requisicoes\n");
        printf("4 - Verificar Deadlock\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1:
                for(int i = 0; i < linha; i++) {
                    for(int j = 0; j < coluna; j++) {
                        printf("P%d - Recurso R%d: ", i + 1, j + 1);
                        scanf("%d", &matriz_alocacao[i][j]);
                    }
                }
                break;

            case 2:
                for(int j = 0; j < coluna; j++) {
                    printf("Recurso R%d disponivel: ", j + 1);
                    scanf("%d", &recurso_disponivel[j]);
                }
                break;

            case 3:
                for(int i = 0; i < linha; i++) {
                    for(int j = 0; j < coluna; j++) {
                        printf("Requisicao P%d - Recurso R%d: ", i + 1, j + 1);
                        scanf("%d", &matriz_de_requisicoes[i][j]);
                    }
                }
                break;

            case 4:
                verificar_deadlock(linha, coluna, matriz_alocacao, recurso_disponivel, matriz_de_requisicoes);
                break;

            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 0);

    return 0;
}