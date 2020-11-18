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

typedef struct grupo_de_risco {
    char cep[20];
    int idade;
};

struct ficha_do_paciente preenche_ficha(void) {

    struct ficha_do_paciente paciente;

    fflush(stdin);

    //procurei muito uma forma melhor de pegar a data via input
    //TODO validar data
    printf("Data do diagnostico\n");
    printf("Usar formato dd/mm/aaaa\n");
    fgets(paciente.data_diagnostico,sizeof(paciente.data_diagnostico), stdin);

    printf("Nome do paciente\n");
    fgets(paciente.nome,sizeof(paciente.nome),stdin);

    printf("Data de nascimento\n");
    printf("Usar formato dd/mm/aaaa\n");
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
    printf("########################################\n");
    printf("Bem vindo ao sistema de cadastro para rastreamento covid-19.\n");
    printf("########################################\n");
    printf("Usuario\n");
    fgets(usuario,30,stdin);
    //limpar final da string
    usuario[strcspn(usuario,"\n")] = 0;
    printf("Senha\n");
    fgets(senha,30,stdin);
    //limpar final da string
    senha[strcspn(senha,"\n")] = 0;
    printf("########################################\n");
    //if(1){
    if(strcmp(usuario,"jose.menezes")==0 && strcmp(senha,"senha123")==0){

        printf("Preencher dados do pasciente:\n");
        printf("########################################\n");
        //Dar a opcao de verficiar os dados e optar por preencher novamente.
        struct ficha_do_paciente paciente = preenche_ficha();

        //SALVAR cadastro do paciente
        salvar_paciente(paciente);

        int d_nascimento,m_nascimento,a_nascimento;
        //Usar para pegar dia mes e ano da variavel
        sscanf(paciente.data_nascimento,"%d/%d/%d", &d_nascimento, &m_nascimento, &a_nascimento);

        int idade_do_paciente = idade(d_nascimento,m_nascimento,a_nascimento);

        ler_paciente();

        //Aramazenando grupo de risco
        if(idade_do_paciente>65 && strlen(paciente.comordidade) !=0 ){
            struct grupo_de_risco paciente_grupo_de_risco = {paciente.cep,idade_do_paciente};
            salvar_grupo_de_risco(paciente_grupo_de_risco);
        }


    }else{
        printf("Usuario ou senha invalidos!\n");
    }
    printf("########################################\n");
    return 0;
}


void salvar_paciente(struct ficha_do_paciente paciente) {

       FILE *of;

       of= fopen ("pacientes.txt", "w");
       if (of == NULL) {
          fprintf(stderr, "\nErro acessando dados\n");
          exit (1);
       }

       fwrite (&paciente, sizeof(struct ficha_do_paciente), 1, of);

       if(fwrite != 0)
          printf("Dados de paciente armazenados com sucesso !\n");
       else
          printf("Erro armazenando dados !\n");
       fclose (of);

}

void salvar_grupo_de_risco(struct ficha_do_paciente paciente) {

       FILE *of;

       of= fopen ("grupo_de_risco.txt", "w");
       if (of == NULL) {
          fprintf(stderr, "\nErro acessando dados\n");
          exit (1);
       }

       fwrite (&paciente, sizeof(struct ficha_do_paciente), 1, of);

       if(fwrite != 0)
          printf("Dados de grupo de risco armazenados com sucesso !\n");
       else
          printf("Erro armazenando dados !\n");
       fclose (of);

}

void ler_paciente(void) {

    FILE *inf;
    struct ficha_do_paciente inp;
    inf = fopen ("pacientes.txt", "r");
    if (inf == NULL) {
      fprintf(stderr, "\nErro acessando dados\n");
      exit (1);
    }
    while(fread(&inp, sizeof(struct ficha_do_paciente), 1, inf))
      printf("########################################\n");
      printf (
        "Dt Diagnostico = %s"
        "name = %s"
        "Emai = %s"
        "Dt Nascimento = %s"
        "CPF = %s"
        "Telefone = %s"
        "Rua = %s"
        "Numero = %s"
        "Bairro = %s"
        "Cidade = %s"
        "Estado = %s"
        "CEP = %s"
        "Comordidades = %s",
        inp.data_diagnostico,
        inp.nome,
        inp.email,
        inp.data_nascimento,
        inp.cpf,
        inp.telefone,
        inp.rua,
        inp.numero,
        inp.bairro,
        inp.cidade,
        inp.estado,
        inp.cep,
        inp.comordidade);
    printf("########################################\n");

    fclose (inf);

}

int idade(int dia_nascimento, int mes_nascimento, int ano_nascimento) {

    time_t hoje;
    time(&hoje);
    struct tm *local = localtime(&hoje);
    int dia_atual = local->tm_mday;
    int mes_atual = local->tm_mon +1;
    int ano_atual = local->tm_year + 1900;

   int month[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
   if (dia_nascimento > dia_atual) {
      dia_atual = dia_atual + month[mes_nascimento - 1];
      mes_atual = mes_atual - 1;
   }
   if (mes_nascimento > mes_atual) {
      ano_atual = ano_atual - 1;
      mes_atual = mes_atual + 12;
   }

   int idade = ano_atual - ano_nascimento;
   return idade;
}


