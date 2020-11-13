#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char usuario[30];
    char senha[30];

    struct ficha_do_pacient{
        char nome[60];
        char cpf[9];
        char telefone[20];
        char rua[100];
        char numero[20];
        char bairro[60];
        char cidade[60];
        char estado[60];
        char cep[20];
        //DD/MM/AAAA
        char data[8];
        //comordidades separadas por virgula
        char comordidade[200]; // possivelmente opcao de escolha
    } paciente;

    printf("Bem vindo ao sistema de cadastro para rastreamento covid-19.\n");

    printf("Usuario\n");
    scanf("%s",usuario);
    printf("Senha\n");
    scanf("%s",senha);

    if(strcmp(usuario,"jose.menezes")==0 && strcmp(senha,"senha123")==0){
        printf("Preencher dados do pasciente:\n");

        fflush(stdin);

        printf("Nome do paciente\n");
        fgets(paciente.nome,60,stdin);
        printf("CPF\n");
        fgets(paciente.cpf,9,stdin);
        printf("Telefone\n");
        fgets(paciente.telefone,20,stdin);
        printf("Rua\n");
        fgets(paciente.rua,100,stdin);
        printf("Numero\n");
        fgets(paciente.numero,20,stdin);
        printf("Bairro\n");
        fgets(paciente.bairro,60,stdin);
        printf("Cidade\n");
        fgets(paciente.cidade,60,stdin);
        printf("Estado\n");
        fgets(paciente.estado,60,stdin);
        printf("CEP\n");
        fgets(paciente.cep,8,stdin);


    }else{
        printf("Usuario ou senha invalidos!");
    }

    return 0;
}


/*void salvar_paciente(){

    FILE *arquivo;

    arquivo = fopen("pacientes.txt","");

    fclose(arquivo);

}*/
