#include <stdio.h>
#include <stdbool.h>
#define Max 5

typedef struct
{
    int chave;
} REGISTRO;
typedef struct
{
    int NElemento;
    REGISTRO A[Max];
} LISTASQ;
bool anexar(LISTASQ *L, int ch);
void exibir(LISTASQ *L);
int tamanho(LISTASQ *l);
int BuscaBinaria(LISTASQ *L, int ch);
bool excluir(LISTASQ *l, int ch);
int busca(LISTASQ *l, int ch);
int main()
{
    LISTASQ L;
    inicializar(&L);
    printf("%s\n", anexar(&L, 2) ? "true" : "false");
    printf("%s\n", anexar(&L, 10) ? "true" : "false");

    printf("Qtd: %d\n", tamanho(&L));
    exibir(&L);
    printf("%s\n", excluir(&L, 2) ? "true" : "false");
    exibir(&L);
    return 0;
}
void inicializar(LISTASQ *L)
{
    L->NElemento = 0;
}
bool anexar(LISTASQ *L, int ch)
{
    if (L->NElemento == Max)
        return false;
    L->A[L->NElemento].chave = ch;
    L->NElemento++;
    return true;
}
void exibir(LISTASQ *L)
{
    for (int i = 0; i < L->NElemento; i++)
    {
        printf("chaves: %d\n", L->A[i].chave);
    }
}
int tamanho(LISTASQ *l)
{
    return l->NElemento;
}
int BuscaBinaria(LISTASQ *L, int ch)
{
    int ultimo = L->NElemento - 1;
    int primeiro = 0;
    while (primeiro <= ultimo)
    {
        int meio = (primeiro + ultimo) / 2;
        if (L->A[meio].chave == ch)
            return meio;
        if (L->A[meio].chave < ch)
        {
            ultimo = meio - 1;
        }
        else
        {
            primeiro = meio + 1;
        }
        return -1;
    }
}
int busca(LISTASQ *l, int ch)
{

    for (int i = 0; i < l->NElemento; i++)
    {
        if (l->A[i].chave == ch)
            return i;
        if (l->A[i].chave > ch)
            return -1;
    }
    return -1;
}
bool excluir(LISTASQ *l, int ch)
{
    int pos;
    if (l->NElemento > 2)
    {
        pos = BuscaBinaria(l, ch);
    }
    else
    {
        pos = busca(l, ch);
    }
    if (pos == -1)
        return false;
    for (int i = pos; i < l->NElemento; i++)
    {
        l->A[i].chave = l->A[i + 1].chave;
    }
    l->NElemento--;
    return true;
}