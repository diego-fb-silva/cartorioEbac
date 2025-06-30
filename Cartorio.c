#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��es de textos por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

//FILE *file;//chamando m�todo de cria��o de arquivos de texto

//in�cio das fun��es do CRUD
int cadastrar()//fun��o respons�vel por cadastrar os cliente no banco de dados
{
	setlocale(LC_ALL,"Portuguese");//Definindo qual idioma o app ir� usar (PT-BR)
	
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	
	char arquivo[100];
	
	//Ser�o usados qnd houver uma tela de login
	//char senha[6]; 
	//char email[100];
	
	//Pedindo ao cliente para digitar o CPF
	printf("Por gentileza informe seu CPF: ");
	scanf("%s",cpf);//%s => informa que a vari�vel refere-se a uma string
	
	/*O cadastro das informa��es dos clientes ser� feito em arquivos de texto.
	Para cada cadastro de cliente, ser� criado um arquivo novo.
	Cada arquivo ter� como label o CPF do cliente*/
	
	//Criando arquivo de "banco de dados" nomeado com o CPF do cliente
	strcpy(arquivo, cpf);//pegando o cpf do cliente para nomear seu arquivo no sistema
	
	FILE *file;//chamando m�todo de cria��o de arquivos de texto 
	file = fopen(arquivo, "w"); //criando o arquivo de "banco". O par�metro "w" serve para criar um novo arquivo
	fprintf(file,"CPF - ");
	fprintf(file,cpf); //salvando o valor do cpf no arquivo do "banco" 
	//fprintf(file,", ");// Inserir virgula para separar os dados no "banco"
	fclose(file); //fecha o arquivo
	
	//trecho para abrir o "banco" e inserir uma virgula para separar os dados salvos
	//exemplo: cpf,nome,sobrenome,cargo
	/*file = fopen(arquivo, "a");// parametro "a" serve para atualizar a informa��o do "banco"
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

int pesquisar()//Fun��o respons�vel por retornar na tela as informa��es do cliente de acordo com o CPF informado. 
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	char conteudo [300];//Variavel para armazenar o conte�do buscado nos arquivos de "banco"
	
	printf("Informe o CPF que deseja buscar: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");//Lendo dados do arquivo pesquisado a partir do par�mentro "CPF"
	
	if(file == NULL)//Validando se o CPF informado n�o existe no "banco"
	{
		printf("\n\nN�o h� registros cadastrados com o CPF informado. \n");
		fclose(file);
	} else {
		printf("\n--Dados do cliente--\n");
		
		while(fgets(conteudo,300,file) != NULL)//salvando na vari�vel "conteudo" os dados relacionados ao CPF buscado na base
		{
			printf("%s",conteudo);
		}
	}
	fclose(file);
	
	printf("\n\n");
	
	system("pause");
}

int deletar()//Fun��o respons�vel por remover da base os dados do cliente de acordo com o CPF informado
{
	setlocale(LC_ALL,"Portuguese");
	
	char cpf[40];
	
	printf("Informe o CPF que deseja remover dos registros: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("\nN�o h� registros cadastrados com o CPF informado! \n\n");
		fclose(file);
		system("pause");
	} else {
		printf("\nDados referente ao CPF ");
		printf(cpf);
		printf(" foram apagados com sucesso! \n\n");
		
		fclose(file);
		remove(cpf);//Fun��o respons�vel por deletar um arquivo de acordo com o par�metro passado. � necess�rio sempre fechar o arquivo "fclose(file);" antes de delet�-lo
		
		system("pause");
	}
}
//fim das fun��es do CRUD

int main()
{
	int opcao=0;//variavel para determinar a op��o escolhida pelo usuario
	int laco=1;
	
	for(laco=1;laco=1;)
	{
		system("cls");//limpando tela do prompt
	
		setlocale(LC_ALL,"Portuguese");
	
		//in�cio do menu
		printf("### -Cart�rio da EBAC- ###\n\n");
		printf("No menu abaixo, selecione a op��o desejada para o autoatendimento:\n\n");
		printf("\t1) - Cadastrar nome\n");
		printf("\t2) - Pesquisar nome\n");
		printf("\t3) - Remover nome\n");
		printf("\t4) - Sair do sistema\n");
		//fim do menu
	
		printf("\n\nOp��o:");
		scanf("%d",&opcao);
		// armazenando a op��o do menu que o usu�rio ir� seguir

		system("cls");
		//limpando tela do prompt
		
		//in�cio da sele��o no menu 
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
			printf("---Op��o indispon�vel!---\n\n");
			system("pause");
			break;	
		}//fim da sele��o no menu

	}
		
}
