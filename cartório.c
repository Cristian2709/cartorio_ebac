#include <stdio.h> //biblioteca comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das strings

int registro() // função responsável por cadastrar usuário
{
	// inicio criação das variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	// final da criação das variáveis/string
	
	printf("Digite o CPF a ser cadastrado: ");  //coletando informação do usuário
	scanf("%s", cpf); // salva o dado do usuário dentro das variáveis\ %s armazena variável  string
	
	strcpy(arquivo, cpf); //responsável por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); //abre o arquivo com a função "w" que significa escrever
	fprintf(file, "CPF: "); 
	fprintf(file, cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	
	printf("\nDigite o nome a ser cadastrado: "); //coletando informação do usuário
	scanf("%s",nome); // salva o dado do usuário dentro das variáveis\ %s armazena variável  string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nNome: ");
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, nome);
	fclose(file); // fecha o arquivo
	
	
	printf("\nDigite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome); // // salva o dado do usuário dentro das variáveis\ %s armazena variável  string
	
	file = fopen(arquivo, "a"); //abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nSobrenome: ");
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, sobrenome);
	fclose(file); // fecha o arquivo
	
	printf("\nDigite o cargo a ser cadastrado: ");
	scanf("%s", cargo); // salva o dado do usuário dentro das variáveis\ %s armazena a variável string
	
	file = fopen(arquivo, "a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, "\nCargo: ");
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo,"a");//abre o arquivo e o "a" significa atualizar arquivo
	fprintf(file, cargo);
	fprintf(file, "\n");
	fclose(file); // fecha o arquivo
	
	printf("\nUsuário cadastrado com sucesso! \n");
	system("pause");
	
}
int consulta() // função responsável por consulta de dados
	{
	setlocale(LC_ALL, "portuguese"); // definindo a linguagem
	
	char cpf[40]; // cria a variável/string cpf
	char conteudo[200]; // cria a variável/string conteúdo
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf); // salva o dado do usuário dentro das variáveis\ %s armazena variável  string
	
	printf("Essas são as informações do usuário:\n\n");
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r");// abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	
	if(file == NULL) // se o arquivo for nulo, será  exibido a seguinte mensagem
	
	{
	printf("Não foi possível abrir o arquivo, não localizado!\n");
	}
	
	
	while(fgets(conteudo, 200, file) != NULL)// enquanto 
	{
	printf("%s", conteudo); // salva a string em arqu. conteúdo
	printf("\n");
	}
	
	system("pause");
	fclose(file); // fecha o arquivo
}

int deletar() //função responsável por deletar usuário
{
	char cpf[40]; // cria variáve/string cpf
	
	printf("digite o CPF do usuário a ser deletado: ");
	scanf("%s", cpf); // salva o dado do usuário dentro das variáveis\ %s armazena variável  string
	 
	
	FILE *file; // abrindo o arquivo
	file = fopen(cpf,"r");// abrindo o arquivo referente ao cpf e dando o comando "r" para leitura
	fclose(file);
	
	if(file == NULL) // se o arquivo for nulo exibe a mensagem
	{
	printf("Usuário não cadastrado!\n"); // mensagem exibida para arquivo válido
	system("pause");
	}
	else 
	{
	if (remove (cpf) == 0) // remove cpf
	{
	printf("Usuário deletado com sucesso!\n"); // mensagem exibida após remover o usuário
	system("pause");
	}
	}
}


int main() // função principal
{
   		int opcao=0; // definição de variável "opção"
		int laco=0; 
		
		for(laco=1;laco=1;) // retorna para o início do programa definido por tudo que está dentro do colchete
{
		
			system("cls"); // "cls" deleta a tela
			
			setlocale(LC_ALL, "portuguese");// definindo a linguagem
	
	printf("###cartório da EBAC###\n\n");//inicio do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - registrar nomes\n"); // primeira opção do menu
	printf("\t2 - consultar nomes\n"); // segunda opção do menu
	printf("\t3 - deletar nomes\n"); // terceira opção do menu  
	printf("\t4 - sair do sistema\n\n"); 	
	printf("opção:"); // fim do menu
    
	scanf("%d", &opcao);//armazenando a escolha do usuário \ %d armazena variável do tipo inteiro
    
    system("cls"); // "cls" limpa a tela a tela
	 	    
    switch(opcao) // inicio de seleção do menu
	 	{
	    	case 1:
	     		registro(); // chamada de funções
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
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
        } // fim da seleção
}
}
