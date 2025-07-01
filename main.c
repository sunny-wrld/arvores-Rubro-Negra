#include "arvore.h"

int main() {
    arvore minhaArvore;
    
    printf("Demonstracao da arvore\n\n");
    
    printf("1. Inicializando a arvore...\n");
    define(&minhaArvore);
    printf("Arvore esta vazia? %s\n\n", vazia(minhaArvore) ? "Sim" : "Nao");
    
    printf("2. Criando raiz com valor 10...\n");
    criaRaiz(&minhaArvore, 10);
    printf("Arvore esta vazia? %s\n\n", vazia(minhaArvore) ? "Sim" : "Nao");
    
    printf("3. Adicionando filhos da raiz (10)...\n");
    criarNodoEsq(minhaArvore, 5);
    criarNodoDir(minhaArvore, 15);
    printf("Arvore atual (In-Ordem): ");
    percorrerInOrdem(minhaArvore);
    printf("\n\n");
    
    printf("4. Adicionando mais nos...\n");
    if (adicionarEsqRaiz(minhaArvore, 5, 3)) {
        printf("No 3 adicionado a esquerda de 5\n");
    }
    if (adicionarDirRaiz(minhaArvore, 5, 7)) {
        printf("No 7 adicionado a direita de 5\n");
    }
    if (adicionarEsqRaiz(minhaArvore, 15, 12)) {
        printf("No 12 adicionado a esquerda de 15\n");
    }
    if (adicionarDirRaiz(minhaArvore, 15, 18)) {
        printf("No 18 adicionado a direita de 15\n");
    }
    printf("\n");
    
    printf("5. Percursos da arvore:\n");
    printf("In-Ordem ou ERD:   ");
    percorrerInOrdem(minhaArvore);
    printf("\n");
    
    printf("Pre-Ordem ou RED:  ");
    percorrerPreOrdem(minhaArvore);
    printf("\n");
    
    printf("Pos-Ordem ou EDR:  ");
    percorrerPosOrdem(minhaArvore);
    printf("\n\n");
    
    printf("6. Testando busca:\n");
    ptrNodo resultado = localiza(minhaArvore, 7);
    if (resultado != NULL) {
        printf("Elemento 7 encontrado! Valor: %d\n", resultado->info);
    } else {
        printf("Elemento 7 nao encontrado\n");
    }
    
    resultado = localiza(minhaArvore, 20);
    if (resultado != NULL) {
        printf("Elemento 20 encontrado! Valor: %d\n", resultado->info);
    } else {
        printf("Elemento 20 nao encontrado (correto!)\n");
    }
    printf("\n");

    printf("7. Altura da arvore: %d\n\n", altura(minhaArvore));
    
    printf("8. Tentando adicionar onde ja existe no...\n");
    if (!adicionarDirRaiz(minhaArvore, 5, 9)) {
        printf("Nao foi possivel adicionar no 9 a direita de 5 (ja existe no 7)\n");
    }
    if (!adicionarEsqRaiz(minhaArvore, 15, 11)) {
        printf("Nao foi possivel adicionar no 11 a esquerda de 15 (ja existe no 12)\n");
    }
    printf("\n");
    
    printf("9. Estrutura final da arvore:\n");
    printf("                10\n");
    printf("              /    \\\n");
    printf("             5      15\n");
    printf("           /  \\    /  \\\n");
    printf("          3    7  12  18\n\n");

    printf("9. Estrutura final da arvore com cores:\n");
    printf("                10 (preto)\n");
    printf("              /            \\\n");
    printf("         5 (vermelho)      15 (vermelho)\n");
    printf("         /        \\        /          \\\n");
    printf("    3 (preto)  7 (preto)  12 (preto)  18 (preto)\n\n");
    
    printf("Confirmacao (In-Ordem): ");
    percorrerInOrdem(minhaArvore);
    printf("\n");
    printf("Com cores: 3 (preto) 5 (vermelho) 7 (preto) 10 (preto) 12 (preto) 15 (vermelho) 18 (preto)\n\n");


    
    printf("Confirmacao (In-Ordem): ");
    percorrerInOrdem(minhaArvore);
    printf("\n\n");
    
    printf("10. Liberando memoria da arvore...\n");
    liberarArvore(&minhaArvore);
    printf("Arvore esta vazia? %s\n", vazia(minhaArvore) ? "Sim" : "Nao");
    
    return 0;
}
