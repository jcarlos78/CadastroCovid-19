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

        char nome[60];
        char cpf[9];
        char telefone[20];
        char rua[100];
        char numero[20];
        char bairro[60];
        char cidade[60];
        char estado[60];
        char cep[20];

        printf("Nome do paciente\n");
        scanf("%s",nome);
        printf("CPF\n");
        scanf("%s",cpf);
        printf("Telefone\n");
        scanf("%s",telefone);
        printf("Rua\n");
        scanf("%s",rua);
        printf("Numero\n");
        scanf("%s",numero);
        printf("Bairro\n");
        scanf("%s",bairro);
        printf("Cidade\n");
        scanf("%s",cidade);
        printf("Estado\n");
        scanf("%s",estado);
        printf("CEP\n");
        scanf("%s",cep);


    }else{
        printf("Usuario ou senha invalidos!");
    }

    return 0;
}
