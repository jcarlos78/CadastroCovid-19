#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char usuario[30];
    char senha[30];

    printf("Bem vindo ao sistema de cadastro para rastreamento covid-19.\n");

    printf("Usuario\n");
    scanf("%s",usuario);
    printf("Senha\n");
    scanf("%s",senha);

    if(strcmp(usuario,"jose.menezes")==0 && strcmp(senha,"senha123")==0){
        printf("Preencher dados do pasciente:\n");



    }else{
        printf("Usuario ou senha invalidos!");
    }

    return 0;
}
