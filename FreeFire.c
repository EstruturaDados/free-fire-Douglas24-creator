#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
// Definições globais
#define MAX_ITENS 10
#define MAX_NOME 30
#define MAX_TIPO 20

//Estrutua que reresenta cada item
typedef struct {
    char nome[MAX_NOME];
    char tipo[MAX_TIPO];
    int quantidade;
} Item;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
// vetor que representa a mochila
Item mochila[MAX_ITENS];
int numItens = 0; // contador de itens

// FUNÇÕES
//status da mochila
void mostrarstatus() {
    printf("\n[Mochila: %d/%d itens ocupados]\n", numItens, MAX_ITENS);
}

//INSERINDO ITENS NA MOCHILA
void inserirItem() {
    if (numItens >= MAX_ITENS) {
        printf("A mochila está cheia! Remova item se quiser adicionar outro.\n");
        return;
    }

    Item novo;
    printf("\n=== Cadastro de item ===\n");
    printf("Nome do item: ");
    scanf(" %[^\n]", novo.nome);
    printf("Tipo: (ex:arma, municao, cura, etc...) ");
    scanf(" %[^\n]", novo.tipo);
    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    limparBufferEntrada();

    mochila[numItens++] = novo;
    printf("Item \"%s\" adicionado com sucesso", novo.nome);
    mostrarstatus();

}
//Função remover item da mochila
void removerItem() {
    if (numItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    char retirado[MAX_NOME];
    printf("\nDigite o nome do item a remover: ");
    scanf(" %[^\n]", retirado);
    limparBufferEntrada();

    int pos = -1;
    for (int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, retirado) == 0) {
            pos = i;
            break;
        }
    }

    if (pos == -1) {
    printf("Item \"%s\" não encontrado na mochila.\n", retirado);
    return;
    }

    for (int i = pos; i < numItens - 1; i++) {
    mochila[i] = mochila[i + 1];
    }
    numItens--;

    printf("Item \"%s\" removido com sucesso!\n", retirado);
    mostrarstatus();

}
//Função para listar os itens da mochila
void listarItens() {
    if (numItens == 0) {
        printf("A mochila está vazia\n");
        return;
    }
    printf("\n=== Itens na mochila (%d/%d) ===\n", numItens, MAX_ITENS);
    printf("%-20s %-15s %-10s\n", "Nome", "Tipo", "Quantidade");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < numItens; i++) {
        printf("%-20s %-15s %-10d\n",
            mochila[i].nome,
            mochila[i].tipo,
            mochila[i].quantidade);
    
    }
}

void buscarItem() {
    if (numItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    char retirada[MAX_NOME];
    printf("\nDigite o nome do item a buscar: ");
    scanf(" %[^\n]", retirada);

    for(int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, retirada) == 0) {
            printf("\n Item encontrado!\n");
            printf("Nome: %s\nTipo %s\nQuantidade: %d\n",
                    mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        limparBufferEntrada();
        return;
        }
    }
    printf("Item \"%s\" não encontrado.\n", retirada);
}

//Função principal 
int main () {
    int opcao;
    do {
        printf("====================================================\n");
        printf("\n   MOCHILA DE SOBREVIVÊNCIA - código da ilha    \n");
        printf("====================================================\n");
        printf("1. Adicionar Item.\n");
        printf("2. Remover Item.\n");
        printf("3. Lista de Itens\n");
        printf("4. Buscar Item\n");
        printf("0. Sair\n");
        mostrarstatus();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: inserirItem();
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 2: removerItem();
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 3: listarItens();
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 4: buscarItem();
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 0: printf("Saindo do programa...\n");
            break;
            default: printf("Oção inválida! Tente novamente.\n");
        }
        
    } while (opcao != 0);

    return 0;
}
    


// Struct Item:
// Representa um componente com nome, tipo, quantidade e prioridade (1 a 5).
// A prioridade indica a importância do item na montagem do plano de fuga.

// Enum CriterioOrdenacao:
// Define os critérios possíveis para a ordenação dos itens (nome, tipo ou prioridade).

// Vetor mochila:
// Armazena até 10 itens coletados.
// Variáveis de controle: numItens (quantidade atual), comparacoes (análise de desempenho), ordenadaPorNome (para controle da busca binária).

// limparTela():
// Simula a limpeza da tela imprimindo várias linhas em branco.

// exibirMenu():
// Apresenta o menu principal ao jogador, com destaque para status da ordenação.

// inserirItem():
// Adiciona um novo componente à mochila se houver espaço.
// Solicita nome, tipo, quantidade e prioridade.
// Após inserir, marca a mochila como "não ordenada por nome".

// removerItem():
// Permite remover um componente da mochila pelo nome.
// Se encontrado, reorganiza o vetor para preencher a lacuna.

// listarItens():
// Exibe uma tabela formatada com todos os componentes presentes na mochila.

// menuDeOrdenacao():
// Permite ao jogador escolher como deseja ordenar os itens.
// Utiliza a função insertionSort() com o critério selecionado.
// Exibe a quantidade de comparações feitas (análise de desempenho).

// insertionSort():
// Implementação do algoritmo de ordenação por inserção.
// Funciona com diferentes critérios de ordenação:
// - Por nome (ordem alfabética)
// - Por tipo (ordem alfabética)
// - Por prioridade (da mais alta para a mais baixa)

// buscaBinariaPorNome():
// Realiza busca binária por nome, desde que a mochila esteja ordenada por nome.
// Se encontrar, exibe os dados do item buscado.
// Caso contrário, informa que não encontrou o item.
