#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct ficha_do_paciente {
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
};


struct ficha_do_paciente preenche_ficha(void) {

    struct ficha_do_paciente paciente;

    fflush(stdin);

    printf("Nome do paciente\n");
    fgets(paciente.nome,60,stdin);

    fflush(stdin);

    printf("CPF\n");
    fgets(paciente.cpf,9,stdin);

    fflush(stdin);

    printf("Telefone\n");
    fgets(paciente.telefone,20,stdin);

    fflush(stdin);

    printf("Rua\n");
    fgets(paciente.rua,100,stdin);

    fflush(stdin);

    printf("Numero\n");
    fgets(paciente.numero,20,stdin);

    fflush(stdin);

    printf("Bairro\n");
    fgets(paciente.bairro,60,stdin);

    fflush(stdin);

    printf("Cidade\n");
    fgets(paciente.cidade,60,stdin);

    fflush(stdin);

    printf("Estado\n");
    fgets(paciente.estado,60,stdin);

    fflush(stdin);

    printf("CEP\n");
    fgets(paciente.cep,8,stdin);

    fflush(stdin);

    return paciente;

}

int main() {
    char usuario[30];
    char senha[30];

    printf("Bem vindo ao sistema de cadastro para rastreamento covid-19.\n");

    printf("Usuario\n");
    fgets(usuario,30,stdin);
    //limpar final da string
    usuario[strcspn(usuario,"\n")] = 0;
    printf("Senha\n");
    fgets(senha,30,stdin);
    //limpar final da string
    senha[strcspn(senha,"\n")] = 0;

    if(strcmp(usuario,"jose.menezes")==0 && strcmp(senha,"senha123")==0){

        printf("Preencher dados do pasciente:\n");

        struct ficha_do_paciente paciente = preenche_ficha();

        salvar_paciente(paciente);

        ler_paciente();

    }else{
        printf("Usuario ou senha invalidos!");
    }

    return 0;
}



void salvar_paciente(struct ficha_do_paciente paciente) {

       FILE *of;

       of= fopen ("pacientes.txt", "w");
       if (of == NULL) {
          fprintf(stderr, "\nError to open the file\n");
          exit (1);
       }
       struct ficha_do_paciente inp1 = {"jose", "Ram"};
       //struct Student inp2 = {2, "Shyam"};
       fwrite (&paciente, sizeof(struct ficha_do_paciente), 1, of);

       if(fwrite != 0)
          printf("Contents to file written successfully !\n");
       else
          printf("Error writing file !\n");
       fclose (of);

}

void ler_paciente(void) {

    FILE *inf;
    struct ficha_do_paciente inp;
    inf = fopen ("pacientes.txt", "r");
    if (inf == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
    }
    while(fread(&inp, sizeof(struct ficha_do_paciente), 1, inf))
      printf ("name = %s\n", inp.nome);
    fclose (inf);

}

struct Student {
   int roll_no;
   char name[20];
};


int main2 () {
   FILE *of;
   of= fopen ("c1.txt", "w");
   if (of == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   struct Student inp1 = {1, "Ram"};
   struct Student inp2 = {2, "Shyam"};
   fwrite (&inp1, sizeof(struct Student), 1, of);
   fwrite (&inp2, sizeof(struct Student), 1, of);
   if(fwrite != 0)
      printf("Contents to file written successfully !\n");
   else
      printf("Error writing file !\n");
   fclose (of);
   FILE *inf;
   struct Student inp;
   inf = fopen ("c1.txt", "r");
   if (inf == NULL) {
      fprintf(stderr, "\nError to open the file\n");
      exit (1);
   }
   while(fread(&inp, sizeof(struct Student), 1, inf))
      printf ("roll_no = %d name = %s\n", inp.roll_no, inp.name);
   fclose (inf);
}


