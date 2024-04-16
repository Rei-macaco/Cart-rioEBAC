#include <stdio.h> //biblioteca de comunicaçao com o isuário
#include <stdlib.h>//biblioteca de olocação de espaço em memòria
#include <locale.h>//biblioteca  de alocações de texto por regiâo
#include <string.h>// biblioteca responsalvel por cuidar das string
int registro()
{
    char arquivo[40];
	char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Cadastre seu cpf:");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); // responsavel por copiar os valores das string
	
	FILE*file; // criar o arquivo
	file = fopen (arquivo, "w");// criando o arquivo
	fprintf(file,"1 - CPF:");
	fprintf(file,cpf); // salvo o valor da variavel
	fclose(file); // fecho o arquivo
	
	file = fopen (arquivo, "a");
	fprintf(file,"\n2 - NOME:");
	fclose(file);
	
	printf("Cadastre seu Nome:");
	scanf("%s",nome);
	
	file = fopen (arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,"\n3 - SOBRENOME:");
	fclose(file);
	
	printf("Cadastre seu Sobrenome:");
	scanf("%s",sobrenome);
	
	file = fopen (arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,"\n4 - FUNÇÂO:");
	fclose(file);
	
	printf("Cadastre sua Função:");
	scanf("%s",cargo);
	
	file = fopen (arquivo ,"a");
	fprintf(file,cargo);
	fclose(file);
	
	file = fopen (arquivo, "a");
	fprintf(file,"\n");
	fclose(file);
	
	 system("pause");
}

int consultar()
{
    setlocale(LC_ALL, "portuguese"); // definindo a linguagem
    
    char cpf[40];
    char conteudo[200];
    
    printf("Buscas rápidas:");
    scanf("%s",cpf);
    
    FILE*file;
    file = fopen(cpf, "r");
    
    if(file==NULL)
    {
    	printf("Arquivo não encontrado!\n");
	}
	 printf("\nEssas são as informações do usuario:\n");
	 
    while(fgets(conteudo,200,file) !=NULL)    
    {
    	printf("%s",conteudo);
    	printf("\n");
    	
	}
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado:");	
	scanf("%s",cpf);
	
	remove(cpf); // so serve pra deletar
	
	FILE *file;
	file = fopen (cpf,"r");
	
	if(file == NULL) // informa que o arquivo não foi encontrado.
	{
		printf("\nO usuário não encontrado!\n\n");
		system("pause");
	}
	
	else
	{
		fclose(file);
		
	if (remove(cpf)==0) // remove cpf
	{
		printf("\nUsuário deletado com sucesso!\n\n");//informa que foi apagado
		system("pause");
	}
	else
	{
		printf("\nErro ao deletar o usuário!\n\n");
		system("pause");
	}
	}	
		
}

int main()
{   
    setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //definindo variáveis
	
	
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	 
	 system("cls");
	
	  
	 setlocale(LC_ALL, "Portuguese"); //definindo a linguagem
	 
	 printf("### Cartório da EBAC ###\n\n"); //inicio do menu
	 printf("\n começe por aqui:\n"); 
	 printf("\t1 - Registrar nomes\n");
	 printf("\t2 - Buscas rápidas\n");
	 printf("\t3 - Deletar nomes\n");
	 printf("\t4 - Sair do Programa!\n");
	 printf("Opção:"); //fim do menu
	
	 scanf("%d",&opcao); // armazenando a escolha do usuario
	
	system("cls");
	 
	 	switch(opcao)
	 {
	 	case 1:
		  registro(); 
		break;
		
		case 2:
		  consultar();
		break;
		
		case 3:
		  deletar();
    	break;
    	
    	case 4:
    		printf("Obrigado por utilizar o sistema!\n");
    	return 0;
		break;	
		
			
    	
    	
    	default:
    		printf("essa opção não esta diponivel!\n");
		system("pause"); 
		break;	
		
			
	 } 
	 
	}
}
