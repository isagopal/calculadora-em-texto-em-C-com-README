#include <stdio.h>
#include <stdlib.h>

char outra_operacao(){ 
    char resposta;
    while (1) {
        printf("Deseja realizar outra operacao? (s/n): ");
        scanf(" %c", &resposta);

        if (resposta == 's' || resposta == 'S') {
            return 's';
        } else if (resposta == 'n' || resposta == 'N') {
            printf("Obrigado por usar a calculadora! Ate a proxima.\n");
            return 'n';
        } else {
            printf("Resposta invalida. Digite 's' para sim ou 'n' para nao.\n");
        }
    }
}

int menu() {
    int opcao;

    do {
        printf("===============================\n\tCalculadora Simples\n===============================\n");
        printf("Selecione uma operacao:\n");
        printf("1. Adicao\n2. Subtracao\n3. Multiplicacao\n4. Divisao\n5. Sair\n");
        printf("Opcao: ");

        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            while(getchar() != '\n');
            opcao = -1;
        } else if (opcao < 1 || opcao > 5) {
            printf("Opcao invalida. Digite um numero de 1 a 5.\n");
        }
    } while (opcao < 1 || opcao > 5);

    switch(opcao) {
        case 1: {
            float a, b;
            printf("Digite o primeiro numero: ");
            scanf("%f", &a);
            printf("Digite o segundo numero: ");
            scanf("%f", &b);
            printf("Resultado: %.2f + %.2f = %.2f\n", a, b, a+b);
            break;
        }
        case 2: {
            float c, d;
            printf("Digite o primeiro numero: ");
            scanf("%f", &c);
            printf("Digite o segundo numero: ");
            scanf("%f", &d);
            printf("Resultado: %.2f - %.2f = %.2f\n", c, d, c-d);
            break;
        }
        case 3: {
            float e, f;
            printf("Digite o primeiro numero: ");
            scanf("%f", &e);
            printf("Digite o segundo numero: ");
            scanf("%f", &f);
            printf("Resultado: %.2f * %.2f = %.2f\n", e, f, e*f);
            break;
        }
        case 4: {
            float g, h;
            printf("Digite o primeiro numero: ");
            scanf("%f", &g);
            printf("Digite o segundo numero: ");
            scanf("%f", &h);
            if (h == 0.0f) {
                printf("Erro: Divisao por zero nao e permitida.\n");
            } else {
                printf("Resultado: %.2f / %.2f = %.2f\n", g, h, g/h);
            }
            break;
        }
        case 5:
            printf("Obrigado por usar a calculadora! Ate a proxima.\n");
            exit(0);
        default: 
            printf("Opcao invalida. Digite um numero de 1 a 5.\n");
    }
    return opcao;
}

int main() {
    char continuar = 's';
    while (continuar == 's' || continuar == 'S') {
        menu();
        continuar = outra_operacao();
    }
    return 0;
}