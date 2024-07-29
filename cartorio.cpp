#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsavel por cuidar das string

int registrar()
{
	printf("-~- REGISTRO DE NOMES -~- \n");
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	printf("Digite o CPF do usuário a ser cadastrado: ");
	scanf("%s", cpf);
	
	strcpy(arquivo, cpf); //responsavel por copiar o valor das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "W"); //cria o arquivo
	file = fopen(arquivo, "a"); //adiciona ao arquivo
	fprintf(file,cpf); //salva o valor da varíavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o nome do usuário a ser cadastrado (Não utilize espaços) : ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o sobrenome do usuário a ser cadastrado (Não utilize espaços) : ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file," - ");
	fclose(file);
	
	printf("Digite o cargo do usuário a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consultar()
{
	printf("-~- CONSULTAR NOMES -~- \n");
	
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF do usuário a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Não foi possivel localizar o pedido. \n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\n Essas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	printf("-~- DELETAR NOMES -~- \n");
	
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Esse CPF/usuário não existe no sistema. \n");
		system("pause");
	}	
		
	system("pause");
}



int main()
{
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	int opcao=0; //definindo variaveis
	int laco=1;
	char senhadigitada[10]="a";
	
	printf("-~- Cartório da EBAC -~- \n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	if (strcmp(senhadigitada, "admin") == 0)
	{
	
	    for(laco=1;laco=1;)
    	{
        
			system("cls");
		
		    printf("-~- Cartório da EBAC -~- \n\n"); //inicio do menu
		    printf("Escolha a opção: \n\n");
			
		    printf("~ 1 - Registrar Nomes\n");
		    printf("~ 2 - Consultar Nomes\n");
		    printf("~ 3 - Deletar Nomes\n\n"); 
		    printf("~ 4 - Sair\n\n");
		    printf("Opção: "); //fim do menu
		
		    scanf("%d", &opcao); //armazenando informações
		
		    system("cls");
		
		    switch(opcao)
		    { //inicio da seleção
		    	case 1:
		    	registrar();
				break;
				
				case 2:
			    consultar();
				break;
				
				case 3:
			    deletar();
				break;
				
				case 4:
				printf("Obrigado por utilizar o sistema.\n");
				return 0;
				break;
				
				default:
				printf("NÚMERO INVÁLIDO \n");
			    system("pause");
			    break;
			} //fim da seleção
	    }
	} 
	
	else
		printf("Senha incorreta!");
}
