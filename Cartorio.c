#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocações de textos por região
#include <string.h> //biblioteca responsável por cuidar das strings

//FILE *file;//chamando método de criação de arquivos de texto

//início das funções do CRUD
int cadastrar()//função responsável por cadastrar os cliente no banco de dados
{
	setlocale(LC_ALL,"Portuguese");//Definindo qual idioma o app irá usar (PT-BR)
	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	char arquivo[100];
	
	//Serão usados qnd houver uma tela de login
	//char senha[6]; 
	//char email[100];
	
	//Pedindo ao cliente para digitar o CPF
	printf("Por gentileza informe seu CPF: ");
	scanf("%s",cpf);//%s => informa que a variável refere-se a uma string
	
	/*O cadastro das informações dos clientes será feito em arquivos de texto.
	Para cada cadastro de cliente, será criado um arquivo novo.
	Cada arquivo terá como label o CPF do cliente*/
	
	//Criando arquivo de "banco de dados" nomeado com o CPF do cliente
	strcpy(arquivo, cpf);//pegando o cpf do cliente para nomear seu arquivo no sistema
	
	FILE *file;//chamando método de criação de arquivos de texto 
	file = fopen(arquivo, "w"); //criando o arquivo de "banco". O parâmetro "w" serve para criar um novo arquivo
	fprintf(file,"CPF - ");
	fprintf(file,cpf); //salvando o valor do cpf no arquivo do "banco" 
	//fprintf(file,", ");// Inserir virgula para separar os dados no "banco"
	fclose(file); //fecha o arquivo
	
	//trecho para abrir o "banco" e inserir uma virgula para separar os dados salvos
	//exemplo: cpf,nome,sobrenome,cargo
	/*file = fopen(arquivo, "a");// parametro "a" serve para atualizar a informação do "banco"
	fprintf(file,",");// Inserir virgula para separar os dados no "banco"
	fclose(file);*/
	
	//Solicitando o Nome do cliente
	printf("Insira seu primeiro Nome: ");
	scanf("%s",nome);
	//salvando o Nome do cliente
	file = fopen(arquivo, "a");
	fprintf(file,"\nNome - ");
	fprintf(file,nome);
	//fprintf(file,", ");
	fclose(file);
	
	//Solicitando o Sobrenome do cliente
	printf("Insira seu Sobrenome: ");
	scanf("%s",sobrenome);
	//salvando o Sobrenome do cliente
	file = fopen(arquivo, "a");
	fprintf(file,"\nSobrenome - ");
	fprintf(file,sobrenome);
	//fprintf(file,", ");
	fclose(file);
	
	//Solicitando o Cargo do cliente
	printf("Agora informe seu Cargo: ");
	scanf("%s",cargo);
	//salvando o Sobrenome do cliente
	file = fopen(arquivo, "a");
	fprintf(file,"\nCargo - ");
	fprintf(file,cargo);
	fclose(file);
	
	printf("\n\n");
	system("pause");
	
}

int pesquisar()//Função responsável por retornar na tela as informações do cliente de acordo com o CPF informado. 
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo [300];//Variavel para armazenar o conteúdo buscado nos arquivos de "banco"
	
	printf("Informe o CPF que deseja buscar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Lendo dados do arquivo pesquisado a partir do parâmentro "CPF"
	
	if(file == NULL)//Validando se o CPF informado não existe no "banco"
	{
		printf("\n\nNão há registros cadastrados com o CPF informado. \n");
		fclose(file);
	} else {
		printf("\n--Dados do cliente--\n");
		
		while(fgets(conteudo,300,file) != NULL)//salvando na variável "conteudo" os dados relacionados ao CPF buscado na base
		{
			printf("%s",conteudo);
		}
	}
	fclose(file);
	
	printf("\n\n");
	
	system("pause");
}

int deletar()//Função responsável por remover da base os dados do cliente de acordo com o CPF informado
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Informe o CPF que deseja remover dos registros: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nNão há registros cadastrados com o CPF informado! \n\n");
		fclose(file);
		system("pause");
	} else {
		printf("\nDados referente ao CPF ");
		printf(cpf);
		printf(" foram apagados com sucesso! \n\n");
		
		fclose(file);
		remove(cpf);//Função responsável por deletar um arquivo de acordo com o parâmetro passado. É necessário sempre fechar o arquivo "fclose(file);" antes de deletá-lo
		
		system("pause");
	}
}
//fim das funções do CRUD

int main()
{
	int opcao=0;//variavel para determinar a opção escolhida pelo usuario
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//limpando tela do prompt
	
		setlocale(LC_ALL,"Portuguese");
	
		//início do menu
		printf("### -Cartório da EBAC- ###\n\n");
		printf("No menu abaixo, selecione a opção desejada para o autoatendimento:\n\n");
		printf("\t1) - Cadastrar nome\n");
		printf("\t2) - Pesquisar nome\n");
		printf("\t3) - Remover nome\n");
		printf("\t4) - Sair do sistema\n");
		//fim do menu
	
		printf("\n\nOpção:");
		scanf("%d",&opcao);
		// armazenando a opção do menu que o usuário irá seguir

		system("cls");
		//limpando tela do prompt
		
		//início da seleção no menu 
		switch(opcao)
		{
			case 1:
			cadastrar();
			break;
			
			case 2:
			pesquisar();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar nosso sistema!\n");
			return 0;
			break;
			
			default:
			printf("---Opção indisponível!---\n\n");
			system("pause");
			break;	
		}//fim da seleção no menu

	}
		
}
