#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

// Estruturas

typedef struct {
    char nome[50];
    char contato[50];
} Cliente;

typedef struct {
    char nome[50];
    int disponibilidade;
} Tecnico;

typedef struct {
    int id;
    char descricao[100];
    int clienteId;
    int tecnicoId;
    char status[20];
    char atualizacao[100];
} Chamado;

typedef struct {
    char nome[50];
    int quantidade;
} Peca;

// VariÃ¡veis globais
Cliente clientes[100];
Tecnico tecnicos[10];
Chamado chamados[100];
Peca estoque[50];
int numClientes = 0, numTecnicos = 0, numChamados = 0, numEstoque = 0;

// ProtÃ³tipos
void inicializarDados();
void salvarDados();
void carregarDados();
void registrarCliente();
void registrarTecnico();
void registrarChamado();
void atribuirTecnico();
void atualizarChamado();
void finalizarChamado();
void registrarPeca();
void atualizarEstoque();
void gerarRelatorio();

// ImplementaÃ§Ãµes
void inicializarDados() {
    numClientes = numTecnicos = numChamados = numEstoque = 0;
}

void salvarDados() {
    FILE *fc = fopen("clientes.bin", "wb");
    FILE *ft = fopen("tecnicos.bin", "wb");
    FILE *fch = fopen("chamados.bin", "wb");
    FILE *fe = fopen("estoque.bin", "wb");
    if (fc && ft && fch && fe) {
        fwrite(&numClientes, sizeof(int), 1, fc);
        fwrite(clientes, sizeof(Cliente), numClientes, fc);
        fclose(fc);

        fwrite(&numTecnicos, sizeof(int), 1, ft);
        fwrite(tecnicos, sizeof(Tecnico), numTecnicos, ft);
        fclose(ft);

        fwrite(&numChamados, sizeof(int), 1, fch);
        fwrite(chamados, sizeof(Chamado), numChamados, fch);
        fclose(fch);

        fwrite(&numEstoque, sizeof(int), 1, fe);
        fwrite(estoque, sizeof(Peca), numEstoque, fe);
        fclose(fe);
    }
}

void carregarDados() {
    FILE *fc = fopen("clientes.bin", "rb");
    FILE *ft = fopen("tecnicos.bin", "rb");
    FILE *fch = fopen("chamados.bin", "rb");
    FILE *fe = fopen("estoque.bin", "rb");
    if (fc && ft && fch && fe) {
        fread(&numClientes, sizeof(int), 1, fc);
        fread(clientes, sizeof(Cliente), numClientes, fc);
        fclose(fc);

        fread(&numTecnicos, sizeof(int), 1, ft);
        fread(tecnicos, sizeof(Tecnico), numTecnicos, ft);
        fclose(ft);

        fread(&numChamados, sizeof(int), 1, fch);
        fread(chamados, sizeof(Chamado), numChamados, fch);
        fclose(fch);

        fread(&numEstoque, sizeof(int), 1, fe);
        fread(estoque, sizeof(Peca), numEstoque, fe);
        fclose(fe);
    }
}

void registrarCliente() {
    if (numClientes >= 100) return;
    getchar();
    printf("Nome: "); fgets(clientes[numClientes].nome, 50, stdin);
    strtok(clientes[numClientes].nome, "\n");
    printf("Contato: "); fgets(clientes[numClientes].contato, 50, stdin);
    strtok(clientes[numClientes].contato, "\n");
    numClientes++;
    printf("Cliente cadastrado.\n");
}

void registrarTecnico() {
    if (numTecnicos >= 10) return;
    getchar();
    printf("Nome: "); fgets(tecnicos[numTecnicos].nome, 50, stdin);
    strtok(tecnicos[numTecnicos].nome, "\n");
    tecnicos[numTecnicos].disponibilidade = 1;
    numTecnicos++;
    printf("técnico cadastrado.\n");
}

void registrarChamado() {
    if (numChamados >= 100) return;
    int clienteId;
    printf("ID do cliente (1 a %d): ", numClientes); scanf("%d", &clienteId);
    getchar();
    printf("Descrição: ");
    fgets(chamados[numChamados].descricao, 100, stdin);
    strtok(chamados[numChamados].descricao, "\n");
    chamados[numChamados].id = numChamados + 1;
    chamados[numChamados].clienteId = clienteId;
    chamados[numChamados].tecnicoId = -1;
    strcpy(chamados[numChamados].status, "Aberto");
    strcpy(chamados[numChamados].atualizacao, "");
    numChamados++;
    printf("Chamado registrado.\n");
}

void atribuirTecnico() {
    int chamadoId, tecnicoId;
    printf("ID do chamado: "); scanf("%d", &chamadoId);
    printf("ID do técnico: "); scanf("%d", &tecnicoId);
    if (chamadoId > 0 && chamadoId <= numChamados && tecnicoId > 0 && tecnicoId <= numTecnicos) {
        chamados[chamadoId - 1].tecnicoId = tecnicoId;
        tecnicos[tecnicoId - 1].disponibilidade = 0;
        strcpy(chamados[chamadoId - 1].status, "Em andamento");
        printf("Técnico atribuído.\n");
    }
}

void atualizarChamado() {
    int chamadoId;
    printf("ID do chamado: "); scanf("%d", &chamadoId);
    getchar();
    if (chamadoId > 0 && chamadoId <= numChamados) {
        printf("Atualização: ");
        fgets(chamados[chamadoId - 1].atualizacao, 100, stdin);
        strtok(chamados[chamadoId - 1].atualizacao, "\n");
        printf("Chamado atualizado.\n");
    }
}

void finalizarChamado() {
    int chamadoId;
    printf("ID do chamado: "); scanf("%d", &chamadoId);
    if (chamadoId > 0 && chamadoId <= numChamados) {
        strcpy(chamados[chamadoId - 1].status, "Finalizado");
        tecnicos[chamados[chamadoId - 1].tecnicoId - 1].disponibilidade = 1;
        printf("Chamado finalizado.\n");
    }
}

void registrarPeca() {
    if (numEstoque >= 50) return;
    getchar();
    printf("Nome da peça: "); fgets(estoque[numEstoque].nome, 50, stdin);
    strtok(estoque[numEstoque].nome, "\n");
    printf("Quantidade: "); scanf("%d", &estoque[numEstoque].quantidade);
    numEstoque++;
    printf("Peça registrada.\n");
}

void atualizarEstoque() {
    char nome[50]; int quantidade;
    getchar();
    printf("Nome da peça: "); fgets(nome, 50, stdin);
    strtok(nome, "\n");
    printf("Quantidade a adicionar/remover: "); scanf("%d", &quantidade);
    for (int i = 0; i < numEstoque; i++) {
        if (strcmp(estoque[i].nome, nome) == 0) {
            estoque[i].quantidade += quantidade;
            printf("Estoque atualizado.\n");
            return;
        }
    }
    printf("Peça não encontrada.\n");
}

void gerarRelatorio() {
    printf("\n--- Relatório de Chamados ---\n");
    for (int i = 0; i < numChamados; i++) {
        printf("ID: %d\n", chamados[i].id);
        printf("Descrição: %s\n", chamados[i].descricao);
        printf("Cliente: %s\n", clientes[chamados[i].clienteId - 1].nome);
        if (chamados[i].tecnicoId != -1)
            printf("Técnico: %s\n", tecnicos[chamados[i].tecnicoId - 1].nome);
        printf("Status: %s\n", chamados[i].status);
        printf("Atualização: %s\n\n", chamados[i].atualizacao);
    }
}

void mostrarEstoque(){
    printf("\n--- Estoque de Peças ---\n");
    for (int i = 0; i < numEstoque; i++) {
        printf("Peça: %s, Quantidade: %d\n", estoque[i].nome, estoque[i].quantidade);
    }
};
int main() {
    setlocale(LC_ALL, "pt_BR.UTF-8");
    
    int opcao;
    inicializarDados();
    carregarDados();
    do {
        printf("\n--- Menu Principal ---\n");
        printf("1. Registrar Cliente\n");
        printf("2. Registrar Técnico\n");
        printf("3. Registrar Chamado\n");
        printf("4. Atribuir Técnico\n");
        printf("5. Atualizar Chamado\n");
        printf("6. Finalizar Chamado\n");
        printf("7. Registrar Peça\n");
        printf("8. Atualizar Estoque\n");
        printf("9. Mostrar Estoque\n");
        printf("10. Gerar Relatório\n");
        printf("0. Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: registrarCliente(); salvarDados(); break;
            case 2: registrarTecnico(); salvarDados(); break;
            case 3: registrarChamado(); salvarDados(); break;
            case 4: atribuirTecnico(); salvarDados(); break;
            case 5: atualizarChamado(); salvarDados(); break;
            case 6: finalizarChamado(); salvarDados(); break;
            case 7: registrarPeca(); salvarDados(); break;
            case 8: atualizarEstoque(); salvarDados(); break;
            case 9: mostrarEstoque(); salvarDados(); break;
            case 10: gerarRelatorio(); break;
            case 0: printf("Saindo...\n"); break;
            default: printf("OpÃ§Ã£o invÃ¡lida.\n");
        }
    } while (opcao != 0);
    return 0;
}