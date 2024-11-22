#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(0));
    int controle = 0;
    unsigned char var_temp;
    unsigned char cod = 0;
    unsigned char pos;
    unsigned char masc = 0x01;

    while(controle != 3){
        puts("Posições ocupadas: ");

        for(int i = 0; i <= 7; i++){
            masc <<= (i);
            var_temp = cod;
            var_temp = var_temp & ~masc;
            if(var_temp < cod){
                printf("%d ", i+1);
            }
            var_temp = 0;
            masc = 0x01;
        }

        puts("\nPosição livres: ");

        for(int i = 0; i <= 7; i++){
            masc <<= (i);
            var_temp = cod;
            var_temp = var_temp & ~masc;
            if(var_temp == cod){
                printf("%d ", i+1);
            }
            var_temp = 0;
            masc = 0x01;
        }
        
        puts("\n");
        
        puts("1. Ocupar armário.");
        puts("2. Liberar armário.");
        puts("3. Sair.");
        printf("Sua escolha: ");
        scanf("%d", &controle);

        switch(controle){
            case 1:
                int numero_aleatorio = 1 + (rand() % 8);

                pos = numero_aleatorio;
                masc <<= (pos-1);
                cod = cod | masc;
                masc = 0x01;
    
                printf("Código atualizado: %hhu\n", cod);
                break;
            case 2:
                puts("Digite a posição que deseja desligar: ");
                scanf("%hhu", &pos);

                masc <<= (pos-1);
                cod = cod & ~masc;
                masc = 0x01;

                printf("Código atualizado: %hhu\n", cod);
                break;
            case 3:
                break;
            default:
                puts("Você não escolheu uma opção existente!!!");
                break;
        }
    }
    return 0;
}