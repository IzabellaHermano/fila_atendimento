#include "lista.h"

int main()
{

    t_lista fila;
    inicia_lista(&fila);

    int opcao, senha = 1, senha_vip = 100;

    while (1)
    {
        printf("\n--- FILA DE ATENDIMENTO ---\n");
        printf("1 - Emitir senha\n");
        printf("2 - Emitir senha VIP\n");
        printf("3 - Chamar proximo\n");
        printf("4 - Ver fila atual\n");
        printf("5 - Sair\n");
        printf("Digite uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1)
        {
            if (senha > 99)
            {
                printf("Limite de senhas comuns atingido!\n");
            }
            else
            {
                insere_fim(senha, &fila);
                printf("Senha %d emitida!\n", senha);
                senha++;
            }
        }
        else if (opcao == 2)
        {
            insere_inicio(senha_vip, &fila);
            printf("Senha VIP %d emitida!\n", senha_vip);
            senha_vip++;
        }
        else if (opcao == 3)
        {
            if (lista_vazia(&fila) == 1)
            {
                printf("Nao tem ninguem na fila!\n");
            }
            else
            {
                int atendido = remove_inicio(&fila);
                printf("Chamando senha: %d\n", atendido);
            }
        }
        else if (opcao == 4)
        {
            exibe_lista(&fila);
        }
        else if (opcao == 5)
        {
            printf("Saindo...\n");
            break;
        }
        else
        {
            printf("Opcao invalida!\n");
        }
    }

    return 0;
}