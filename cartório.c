#include <stdio.h> //biblioteca comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das strings

int registro() // fun��o respons�vel por cadastrar usu�rio
{
	// inicio cria��o das vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da cria��o das vari�veis/string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informa��o do usu�rio
	scanf("%s", cpf); // salva o dado do usu�rio dentro das vari�veis\ %s armazena vari�vel  string
	
	strcpy(arquivo, cpf); //respons�vel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo com a fun��o "w" que significa escrever
	fprintf(file, "CPF: "); 
	fprintf(file, cpf); //salvo o valor da vari�vel
	fclose(file); //fecha o arquivo
	
	
	printf("\nDigite o nome a ser cadastrado: "); //coletando informa��o do usu�rio
	scanf("%s",nome); // salva o dado do usu�rio dentro das vari�veis\ %s armazena vari�vel  string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nNome: ");
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, nome);
	fclose(file); // fecha o arquivo
	
	
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); // // salva o dado do usu�rio dentro das vari�veis\ %s armazena vari�vel  string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nSobrenome: ");
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, sobrenome);
	fclose(file); // fecha o arquivo
	
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // salva o dado do usu�rio dentro das vari�veis\ %s armazena a vari�vel string
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nCargo: ");
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, cargo);
	fprintf(file, "\n");
	fclose(file); // fecha o arquivo
	
	printf("\nUsu�rio cadastrado com sucesso! \n");
	system("pause");
	
}
int consulta() // fun��o respons�vel por consulta de dados
	{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	char cpf[40]; // cria a vari�vel/string cpf
	char conteudo[200]; // cria a vari�vel/string conte�do
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // salva o dado do usu�rio dentro das vari�veis\ %s armazena vari�vel  string
	
	printf("Essas s�o as informa��es do usu�rio:\n\n");
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r");// abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	
	if(file == NULL) // se o arquivo for nulo, ser�  exibido a seguinte mensagem
	
	{
	printf("N�o foi poss�vel abrir o arquivo, n�o localizado!\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)// enquanto 
	{
	printf("%s", conteudo); // salva a string em arqu. conte�do
	printf("\n");
	}
	
	system("pause");
	fclose(file); // fecha o arquivo
}

int deletar() //fun��o respons�vel por deletar usu�rio
{
	char cpf[40]; // cria vari�ve/string cpf
	
	printf("digite o CPF do usu�rio a ser deletado: ");
	scanf("%s", cpf); // salva o dado do usu�rio dentro das vari�veis\ %s armazena vari�vel  string
	 
	
	FILE *file; // abrindo o arquivo
	file = fopen(cpf,"r");// abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	fclose(file);
	
	if(file == NULL) // se o arquivo for nulo exibe a mensagem
	{
	printf("Usu�rio n�o cadastrado!\n"); // mensagem exibida para arquivo v�lido
	system("pause");
	}
	else 
	{
	if (remove (cpf) == 0) // remove cpf
	{
	printf("Usu�rio deletado com sucesso!\n"); // mensagem exibida ap�s remover o usu�rio
	system("pause");
	}
	}
}


int main() // fun��o principal
{
   		int opcao=0; // defini��o de vari�vel "op��o"
		int laco=0; 
		
		for(laco=1;laco=1;) // retorna para o in�cio do programa definido por tudo que est� dentro do colchete
{
		
			system("cls"); // "cls" deleta a tela
			
			setlocale(LC_ALL, "portuguese");// definindo a linguagem
	
	printf("###cart�rio da EBAC###\n\n");//inicio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - registrar nomes\n"); // primeira op��o do menu
	printf("\t2 - consultar nomes\n"); // segunda op��o do menu
	printf("\t3 - deletar nomes\n"); // terceira op��o do menu  
	printf("\t4 - sair do sistema\n\n"); 	
	printf("op��o:"); // fim do menu
    
	scanf("%d", &opcao);//armazenando a escolha do usu�rio \ %d armazena vari�vel do tipo inteiro
    
    system("cls"); // "cls" limpa a tela a tela
	 	    
    switch(opcao) // inicio de sele��o do menu
	 	{
	    	case 1:
	     		registro(); // chamada de fun��es
		   		break;
	 	    		
	     	case 2:
			 	consulta();
				break;
				
			case 3:
				deletar();
				break;
			
			case 4:
				printf("sistema finalizado.\n");
				return 0;
				break;
					
				default:
				printf("Essa op��o n�o est� dispon�vel!\n");
				system("pause");
				break;
        } // fim da sele��o
}
}
