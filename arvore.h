#include <stdlib.h>
#include <stdio.h>

// Definindo o tipo elemento
typedef int elemento;

// Função de comparação
int comparaelementos(elemento a, elemento b) {
    return (a - b);
}

typedef struct nodo *ptrNodo;
struct nodo {
              elemento info;
              ptrNodo 	esq;
              ptrNodo   dir;
         };

typedef ptrNodo arvore;


void define(arvore *t) {
      *t = NULL;
}

void criaRaiz(arvore *t, elemento item) {
   arvore no;
   no = (ptrNodo)malloc(sizeof(struct nodo));
   if (no == NULL) {
      printf("Erro: falha na alocacao de memoria\n");
      return;
   }
   no->esq = NULL;
   no->dir = NULL;
   no->info = item;
   *t = no;
}

int vazia (arvore t) {
   return (t==NULL);
}

void criarNodoDir(arvore t, elemento item) {
	arvore  no;
	if (t == NULL) {
		printf("Erro: arvore nao pode ser NULL\n");
		return;
	}
	no = (ptrNodo)malloc(sizeof(struct nodo));
	if (no == NULL) {
		printf("Erro: falha na alocacao de memoria\n");
		return;
	}
        no->esq = NULL;
        no->dir = NULL;
        no->info = item;
        t->dir = no;
}

void criarNodoEsq(arvore t, elemento item) {
	arvore  no;
	if (t == NULL) {
		printf("Erro: arvore nao pode ser NULL\n");
		return;
	}
	no = (ptrNodo)malloc(sizeof(struct nodo));
	if (no == NULL) {
		printf("Erro: falha na alocacao de memoria\n");
		return;
	}
        no->esq = NULL;
        no->dir = NULL;
        no->info = item;
        t->esq = no;
}

ptrNodo localiza(arvore t, elemento item) {
   ptrNodo locesq, locdir;
   
   // Verificacao se a arvore e vazia
   if (t == NULL) {
      return NULL;
   }
   
   locesq = NULL;
   locdir = NULL;
   if (comparaelementos(t->info,item) != 0) {
      if (t->esq != NULL)
         locesq = localiza(t->esq,item);
      if (locesq == NULL) {
         if (t->dir != NULL)
            locdir = localiza(t->dir,item);
         if (locdir == NULL)
            return NULL;
         else
            return locdir;
      }
      else
         return locesq;
   } else
      return t;
}

int adicionarDirRaiz(arvore t, elemento item_raiz, elemento item) {
   arvore raiz, no;
   raiz = localiza(t,item_raiz);
   if (raiz!=NULL) {
      if (raiz->dir!=NULL)
         return 0;
      else {
         no = (ptrNodo)malloc(sizeof(struct nodo));
         if (no == NULL) {
            printf("Erro: falha na alocacao de memoria\n");
            return 0;
         }
         no->esq = NULL;
         no->dir = NULL;
         no->info = item;
         raiz->dir = no;
         return 1;
      }
   }
   return 0; // Retorna 0 se a raiz nao foi encontrada
}

int adicionarEsqRaiz(arvore t, elemento item_raiz, elemento item) {
   arvore raiz, no;
   raiz = localiza(t,item_raiz);
   if (raiz!=NULL) {
      if (raiz->esq!=NULL)
         return 0;
      else {
         no = (ptrNodo)malloc(sizeof(struct nodo));
         if (no == NULL) {
            printf("Erro: falha na alocacao de memoria\n");
            return 0;
         }
         no->esq = NULL;
         no->dir = NULL;
         no->info = item;
         raiz->esq = no;
         return 1;
      }
   }
   return 0; // Retorna 0 se a raiz nao foi encontrada
}

// Funcao para percorrer a arvore em ordem
void percorrerInOrdem(arvore t) {
    if (t != NULL) {
        percorrerInOrdem(t->esq);
        printf("%d ", t->info);
        percorrerInOrdem(t->dir);
    }
}

// Funcao para percorrer a arvore em pre-ordem
void percorrerPreOrdem(arvore t) {
    if (t != NULL) {
        printf("%d ", t->info);
        percorrerPreOrdem(t->esq);
        percorrerPreOrdem(t->dir);
    }
}

// Funcao para percorrer a arvore em pos-ordem
void percorrerPosOrdem(arvore t) {
    if (t != NULL) {
        percorrerPosOrdem(t->esq);
        percorrerPosOrdem(t->dir);
        printf("%d ", t->info);
    }
}

// Funcoes de percurso com nomenclatura ERD, RED, EDR
void percursoERD(arvore t) {
    if (t != NULL) {
        percursoERD(t->esq);    // Esquerda
        printf("%d ", t->info);  // Raiz
        percursoERD(t->dir);    // Direita
    }
}

void percursoRED(arvore t) {
    if (t != NULL) {
        printf("%d ", t->info);  // Raiz
        percursoRED(t->esq);    // Esquerda
        percursoRED(t->dir);    // Direita
    }
}

void percursoEDR(arvore t) {
    if (t != NULL) {
        percursoEDR(t->esq);    // Esquerda
        percursoEDR(t->dir);    // Direita
        printf("%d ", t->info);  // Raiz
    }
}

// Funcao para calcular a altura da arvore
int altura(arvore t) {
    if (t == NULL) {
        return 0;
    }
    
    int alturaEsq = altura(t->esq);
    int alturaDir = altura(t->dir);
    
    return 1 + (alturaEsq > alturaDir ? alturaEsq : alturaDir);
}

// Funcao para liberar toda a memoria da arvore
void liberarArvore(arvore *t) {
    if (*t != NULL) {
        liberarArvore(&((*t)->esq));
        liberarArvore(&((*t)->dir));
        free(*t);
        *t = NULL;
    }
}