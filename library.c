#include <stdio.h>
#include <stdbool.h> // Include for the bool data type
#include <stdlib.h>

#define MAX 35

typedef struct
{
    int key;
} REG;

typedef struct
{
    REG LL[MAX];
    int nElem;
} LISTA;

void inicia(LISTA *L)
{
    L->nElem = 0;
}

void exibe(LISTA *L)
{
    int i;
    printf("Lista : ");
    for (i = 0; i < L->nElem; i++)
        printf("[%d]", L->LL[i].key);
    printf("\n\nQuantidade de elementos da lista %d\n", L->nElem);
}

int busca(LISTA *L, int K)
{
    int i = 0;
    while (i < L->nElem)
    {
        if (K == L->LL[i].key)
            return i;
        else
            i++;
    }
    return -1;
}

bool insere(LISTA *L, int K)
{
    int j;
    j = L->nElem;
    if (j == MAX)
        return false;
    for (; j > 0; j--)
    {
        if (K > L->LL[j - 1].key)
            break;
        else
            L->LL[j].key = L->LL[j - 1].key;
    }
    L->LL[j].key = K;
    L->nElem++;
    return true;
}

void exclui(LISTA *L, int j)
{
    int i;
    for (i = j; i < L->nElem - 1; i++)
        L->LL[i].key = L->LL[i + 1].key;
    L->nElem--;
}

int main()
{
    char opcao = '1';
    int val;
    LISTA LLinear;
    inicia(&LLinear);
    while (opcao != '0')
    {
        system("clear"); // Use "clear" to clear the terminal screen in Unix-like systems
        printf("==========>Menu<==========\n");
        printf("__________________________\n");
        printf("      1-->Inserir\n");
        printf("      2-->Buscar\n");
        printf("      3-->Exibir\n");
        printf("      4-->Excluir\n");
        printf("      5-->Inicializar\n");
        printf("      0-->Sair\n");
        printf("__________________________\n");
        printf("\nOpcao: ");
        scanf(" %c", &opcao);

        switch (opcao)
        {
            case '1':
            {
                printf("\nDigite o valor do elemento: ");
                scanf("%d", &val);

                if (insere(&LLinear, val) == false)
                    printf("Elemento nao pode ser inserido na lista\n");
                else
                    printf("Inserido com sucesso\n");

                printf("\n\n\nAperte qualquer tecla para continuar.\n");
                getchar(); // Use getchar() to wait for a key press
                break;
            }

            case '2':
            {
                int x;
                printf("\nDigite o valor procurado : ");
                scanf("%d", &val);
                x = busca(&LLinear, val);
                if (x == -1)
                    printf("Valor %d nao foi encontrado na lista\n", val);
                else
                    printf("O valor encontra-se na posicao %d\n", x);

                printf("\n\n\nAperte qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '3':
            {
                exibe(&LLinear);

                printf("\n\n\nAperte qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '4':
            {
                int x;
                printf("\nDigite o valor a ser excluido : ");
                scanf("%d", &val);
                x = busca(&LLinear, val);
                if (x == -1)
                    printf("Valor %d nao foi encontrado na lista\n", val);
                else
                {
                    exclui(&LLinear, x);
                    printf("Excluido com sucesso\n");
                }

                printf("\n\n\nAperte qualquer tecla para continuar.\n");
                getchar();
                break;
            }

            case '5':
            {
                inicia(&LLinear);
                printf("Lista zerada\n");

                printf("\n\n\nAperte qualquer tecla para continuar.\n");
                getchar();
                break;
            }
        }
    }
    return 0;
}