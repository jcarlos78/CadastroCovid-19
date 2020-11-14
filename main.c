#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct ficha_do_paciente {
    char nome[60];
    //TODO validar cpf
    char cpf[60];
    //TODO validar telefone
    char telefone[20];
    char rua[100];
    char numero[20];
    char bairro[60];
    char cidade[60];
    char estado[60];
    char cep[20];
    //DD/MM/AAAA
    char data_diagnostico[20];
    char data_nascimento[20];
    char email[20];
    //TODO comordidades separadas por virgula
    char comordidade[200]; //TODO possivelmente opcao de escolha
};


struct ficha_do_paciente preenche_ficha(void) {

    struct ficha_do_paciente paciente;

    fflush(stdin);

    //procurei muito uma forma melhor de pegar a data via input
    //TODO validar data
    printf("Data do diagnostico\n");
    printf("Usar formato dd\mm\aaaa\n");
    int d,m,y;
    fgets(paciente.data_diagnostico,sizeof(paciente.data_diagnostico), stdin);

    //Usar para pegar dia mes e ano da variavel
    //sscanf(paciente.data_diagnostico,"%d/%d/%d", &d, &m, &y);

    printf("Nome do paciente\n");
    fgets(paciente.nome,sizeof(paciente.nome),stdin);

    printf("Data de nascimento\n");
    fgets(paciente.data_nascimento, sizeof(paciente.data_nascimento),stdin);

    printf("Email\n");
    fgets(paciente.email,sizeof(paciente.email),stdin);

    printf("Telefone\n");
    fgets(paciente.telefone,sizeof(paciente.telefone),stdin);

    printf("CPF\n");
    fgets(paciente.cpf,sizeof(paciente.cpf),stdin);

    printf("Rua\n");
    fgets(paciente.rua,sizeof(paciente.rua),stdin);

    printf("Numero\n");
    fgets(paciente.numero,sizeof(paciente.numero),stdin);

    printf("Bairro\n");
    fgets(paciente.bairro,sizeof(paciente.bairro),stdin);

    printf("Cidade\n");
    fgets(paciente.cidade,sizeof(paciente.cidade),stdin);

    printf("Estado\n");
    fgets(paciente.estado,sizeof(paciente.estado),stdin);

    printf("CEP\n");
    fgets(paciente.cep,sizeof(paciente.cep),stdin);

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

        //Dar a opcao de verficiar os dados e optar por preencher novamente.
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
      printf ("name = %s\ntelefone = %s\n", inp.nome, inp.telefone);
    fclose (inf);

}

/*struct Student {
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
}*/


