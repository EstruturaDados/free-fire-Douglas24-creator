#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Código da Ilha – Edição Free Fire
// Nível: Mestre
// Este programa simula o gerenciamento avançado de uma mochila com componentes coletados durante a fuga de uma ilha.
// Ele introduz ordenação com critérios e busca binária para otimizar a gestão dos recursos.
// Definições globais
#define MAX_ITENS 10

//Estrutua que reresenta cada item
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

void limparBufferEntrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// FUNÇÕES
void inserirItem(Item *mochila, int *numItens);
void removerItem(Item *mochila, int *numItens);
void listarItens(const Item *mochila, int numItens);
void buscarItem(const Item *mochila, int numItens);
void mostrarStatus(int numItens);

//Função principal 
int main () {
    Item mochila[MAX_ITENS];
    int numItens = 0;
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
        mostrarStatus(numItens);
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        limparBufferEntrada();

        switch (opcao) {
            case 1: inserirItem(mochila, &numItens);
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 2: removerItem(mochila, &numItens);
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 3: listarItens(mochila, numItens);
            printf("\npressione Enter para continuar...\n");
            getchar(); // pausa para o usuario ler a mensagem antes de voltar ao menu
            break;
            case 4: buscarItem(mochila, numItens);
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

//INSERINDO ITENS NA MOCHILA
void inserirItem(Item *mochila, int *numItens) {
    if (*numItens >= MAX_ITENS) {
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

    mochila[*numItens] = novo;
    (*numItens)++;

    printf("Item \"%s\" adicionado com sucesso\n", novo.nome);
    listarItens(mochila, *numItens); // mostrar itens após adicionar

}
//Função remover item da mochila
void removerItem(Item *mochila, int *numItens) {
    if (*numItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    char nome[30];
    printf("Digite o nome do item a remover: ");
    scanf(" %[^\n]", nome);
    limparBufferEntrada();

    int removido = -1;
    for (int i = 0; i < *numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            removido = i;
            break;
        }
    }

    if (removido == -1) {
    printf("Item \"%s\" não encontrado na mochila.\n", nome);
    return;
    }

    for (int i = removido; i < *numItens - 1; i++) {
    mochila[i] = mochila[i + 1];
    }
    (*numItens)--;

    printf("Item \"%s\" removido com sucesso!\n", nome);
    mostrarStatus(*numItens);
    listarItens(mochila, *numItens);

}
//Função para listar os itens da mochila
void listarItens(const Item *mochila, int numItens) {
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

void buscarItem(const Item *mochila, int numItens) {
    if (numItens == 0) {
        printf("A mochila está vazia!\n");
        return;
    }
    char nome[30];
    printf("\nDigite o nome do item a buscar: ");
    scanf(" %[^\n]", nome);

    for(int i = 0; i < numItens; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("\n Item encontrado!\n");
            printf("Nome: %s\nTipo %s\nQuantidade: %d\n",
                    mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        limparBufferEntrada();
        return;
        }
    }
    printf("Item \"%s\" não encontrado.\n", nome);
}

// Mostrar status da mochila
void mostrarStatus(int numItens) {
    printf("Mochila: %d/%d itens ocupados\n", numItens, MAX_ITENS);

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
