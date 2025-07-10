/*
 * Funcionalidades:
 * 1. Cadastrar pessoas (codigo, nome, idade)
 * 2. Listar todas as pessoas cadastradas
 * 3. Editar cadastros existentes
 * 4. Excluir cadastros com confirma??o
 */

#include <stdio.h>  // Biblioteca padr?o para entrada e sa?da (ex: printf, scanf)

#define MAX 100  // Define o n?mero m?ximo de cadastros permitidos

// Estrutura que representa uma pessoa número, nome e posição
struct Pessoa {
    int numero;
    char nome[50];  // String de at? 49 caracteres + 1 para o caractere '\0' de finaliza??o
    int posicao;
};

// Vetor que armazena at? 28 pessoas
struct Pessoa pessoas[MAX];
// Vari?vel que armazena quantas pessoas j? foram cadastradas
int qtd = 0;

// Fun??o que cadastra uma nova pessoa
void cadastrar() {
    // Verifica se o limite de cadastros foi atingido
    if (qtd >= MAX) {
        printf("\nLimite de pessoas atingido (%d cadastros)!\n", MAX);
        return; // Encerra a fun??o
    }

    printf("\n--- NOVO CADASTRO ---\n");

    // Pede os dados da pessoa: número, nome e posição
    printf("Número: ");
    scanf("%d", &pessoas[qtd].numero);
    while(getchar() != '\n'); // Limpa o "lixo" do buffer do teclado

    printf("Nome: ");
    scanf(" %49[^\n]", pessoas[qtd].nome); // L? at? 49 caracteres com espa?os

    printf("Posição: ");
    scanf("%d", &pessoas[qtd].posicao);

    // Aumenta o n?mero de pessoas cadastradas
    qtd++;

    printf("\nCadastro realizado com sucesso!\n");
}

// Fun??o que busca uma pessoa pelo número informado
int buscarPorNumero(int numero) {
    int i;
    for (i = 0; i < qtd; i++) {
        if (pessoas[i].numero == numero) {
            return i; // Retorna o ?ndice da pessoa no vetor
        }
    }
    return -1; // Retorna -1 se n?o encontrou
}

// Fun??o que edita os dados de uma pessoa
void editar() {
    int numero, index;

    printf("\n--- EDITAR CADASTRO ---\n");
    printf("Digite o número da pessoa: ");
    scanf("%d", &numero);

    // Procura a pessoa com o número digitado
    index = buscarPorNumero(numero);

    // Se n?o encontrar, avisa e retorna
    if (index == -1) {
        printf("\nPessoa nao encontrada!\n");
        return;
    }

    // Mostra os dados atuais
    printf("\nEDITANDO CADASTRO:\n");
    printf("Numero: %d\n", pessoas[index].numero);
    printf("Nome atual: %s\n", pessoas[index].nome);
    printf("Posicao: %d\n\n", pessoas[index].posicao);

    // Pede os novos dados
    printf("Novo nome: ");
    scanf(" %49[^\n]", pessoas[index].nome);

    printf("Nova idade: ");
    scanf("%d", &pessoas[index].numero);

    printf("\nCadastro atualizado com sucesso!\n");
}

// Fun??o que exclui uma pessoa do sistema
void excluir() {
    int Numero, index;
    char confirmacao;

    printf("\n--- EXCLUIR CADASTRO ---\n");
    printf("Digite o Número da pessoa: ");
    scanf("%d", &Numero);

    index = buscarPorNumero(Numero);

    if (index == -1) {
        printf("\nPessoa nao encontrada!\n");
        return;
    }

    // Mostra os dados da pessoa e pede confirma??o
    printf("\nCONFIRMAR EXCLUSAO:\n");
    printf("numero: %d\n", pessoas[index].numero);
    printf("Nome: %s\n", pessoas[index].nome);
    printf("Posicao: %d\n", pessoas[index].posicao);

    printf("\nTem certeza que deseja excluir? (s/n): ");
    scanf(" %c", &confirmacao);

    // Se confirmar, remove a pessoa do vetor e ajusta a quantidade
    if (confirmacao == 's' || confirmacao == 'S') {
        int i;
        for (i = index; i < qtd - 1; i++) {
            pessoas[i] = pessoas[i + 1]; // Desloca os dados para "tapar o buraco"
        }
        qtd--; // Diminui a quantidade total
        printf("\nCadastro excluido com sucesso!\n");
    } else {
        printf("\nOperacao cancelada.\n");
    }
}

// Fun??o que lista todas as pessoas cadastradas
void listar() {
    printf("\n--- PESSOAS CADASTRADAS ---\n");
    printf("Total: %d\n\n", qtd);

    if (qtd == 0) {
        printf("Nenhuma pessoa cadastrada.\n");
        return;
    }

    // Cabe?alho da tabela
    printf("NUMERO  NOME%-42s POSIÇÃO\n", "");
    printf("--------------------------------------------------\n");

    // Mostra os dados de cada pessoa
    int i;
    for (i = 0; i < qtd; i++) {
        printf("%-8d%-45s%d\n",
               pessoas[i].numero,
               pessoas[i].nome,
               pessoas[i].posicao);
    }
}

// Fun??o principal (ponto de entrada do programa)
int main() {
    int op;

    printf("\n----------------------------------------");
    printf("\n    SISTEMA DE CADASTRO DE JOGADORES DE HANDEBOL");
    printf("\n----------------------------------------\n");

    // Loop principal do menu
    do {
        printf("\n----------- MENU PRINCIPAL -----------\n");
        printf("1. Cadastrar nova pessoa\n");
        printf("2. Listar todas as pessoas\n");
        printf("3. Editar cadastro existente\n");
        printf("4. Excluir cadastro\n");
        printf("0. Sair do sistema\n");
        printf("--------------------------------------\n");
        printf("Opcao: ");
        scanf("%d", &op);
        while(getchar() != '\n'); // Limpa o buffer do teclado

        // Executa a op??o escolhida
        switch (op) {
            case 1: cadastrar(); break;
            case 2: listar(); break;
            case 3: editar(); break;
            case 4: excluir(); break;
            case 0: printf("\nEncerrando sistema...\n"); break;
            default: printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (op != 0); // Repete at? o usu?rio escolher sair

    printf("\nObrigado por utilizar o sistema!\n");
    return 0; // Finaliza o programa
}

