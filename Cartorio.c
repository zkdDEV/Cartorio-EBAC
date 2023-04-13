#include <stdio.h>     //biblioteca de comunicação com o usuário
#include <stdlib.h>     //biblioteca de alocação de espaço de memória
#include <string.h>     //biblioteca responsável por cuidar da stings
#include <locale.h>     //biblioteca de alocações de texto por região

int criar() //função de registro de usuário
{
	//início criação de variáveis/string
	char arquivo[50];
	char cpf[50];
	char nome[50];
	char sobrenome[50];
	char cargo[50];
	//final de criação de variáveis/string
	
	printf("\t_~Digite abaixo o CPF a ser cadastrado~_\n\n"); //coletando informações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w");//cria o arquivo e o "w" significa escrever
	fprintf(file, cpf); //salva o valor da variável
	fclose(file); //fecho o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,", "); //pula uma linha no arquivo
	fclose(file); //fecha o arquivo
	
	printf("\t_~Digite abaixo o nome a ser cadastrado~_\n\n"); //coletando informação do usuário
	scanf("%s",nome);
	
	file = fopen(arquivo, "a"); //atualiza do arquivo
	fprintf(file,nome); //salva as letras da váriavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file," "); //dá um espaço no arquivo
	fclose(file); //fecha o arquivo
	
	printf("\t_~Digite abaixo o sobrenome a ser cadastrado~_\n"); //coletando informações do usuário
	scanf("%s",sobrenome); //ativando a string
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,sobrenome); //salva as letras da variável
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,", "); //cria uma "," no arquivo com espaço
	fclose(file); //fecha arquivo
	
	printf("\t_~Digite abaixo o cargo a ser cadastrado~_\n"); //coletando informações do usuário
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a"); //atualiza o arquivo
	fprintf(file,cargo); //salva as letras da variável
	fclose(file); //fecha o arquivo
	
	system("pause"); //avisa o Sistema Operacional para pausar
}



int consultar() //função de consulta sobre algum usuário
{
	
	setlocale(LC_ALL, "Portuguese"); //Avisa que os textos(printf) vão estar em português
	
	//início criação de variáveis/string
	char cpf[50];
	char conteudo[200];
	//final da criação de variáveis/string
	
	printf("\t_~Digite o CPF para consultar~_\n"); //coletando informações do usuário
	scanf("%s", cpf);

	FILE *file; //Avisa que deve entrar na biblioteca arquivos
	file = fopen(cpf, "r"); //Abrir aquivo e ler("r")
	
	//Início condição quando arquivo é nulo
	if(file == NULL)
	{
		printf("\tNão encontramos o arquivo!.\n");
	} 
	//fim de condição quando arquivo é nulo
	
	//Início condição quando arquivo não é nulo
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\t_~Essas são as informações do usuário~_\n\n");
		printf("%s", conteudo);
		printf("\n\n");
	}
	//fim de condição quando arquivo é não é nulo
	
	system("pause"); //avisa o Sistema Operacional para pausar
	
}


int excluir() //função de excluir algum usuário
{
	char cpf[50]; //variável/string
	
	printf("\t_~Exclua um usuário digitando o CPF dele abaixo~_\n\n"); //coletando informações do usuário
	scanf("%s", cpf);
	
	remove(cpf); //removendo registro
	
	FILE *file; //abrindo arquivo
	file = fopen(cpf, "r"); //lendo arquivo
	
	if(file == NULL)
	{
		printf("\tO usuário já não se encontra no sistema ou não existe!\n\n"); //coletando informações do usuário
		system("pause"); //avisa o Sistema Operacional para pausar
	}


}


int main() //função de início de programa
{
	int opcao=0; //armazenar a escolha do usuário
	int laco=1; //variável para loop de site
	
	for(laco=1;laco=1;) //loop do site
	{
		system("cls"); //excluir as mensagens anteriores
	
		setlocale(LC_ALL, "Portuguese");  //definir língua
		
		//Início do Menu
		printf("\t_~Registros da EBAC~_\n\n\n");
		printf("Digite o número de uma das opções abaixo:\n\n");
		printf("\t1 - Criar usuário\n");
		printf("\t2 - Consultar usuários\n");
		printf("\t3 - Excluir usuário\n\n");
		printf("\t4 - Sair do sistema\n\n");
		printf("Opção: "); 
		//Fim do Menu
	
		scanf("%d", &opcao); //Escanear a escolha o usuário e mandar ela para a variável
	
		system("cls"); //Limpando as mensagens anteriores
			
			
		switch(opcao) //início da seleção
		{
			case 1:
			criar(); //direcionar para função
			break;
				
			case 2:
			consultar(); //direcionar para função			
			break;
				
			case 3:
			excluir(); //direcionar para função
			break;
			
			case 4:
			printf("\t_~Obrigado por utilizar nosso sistema~_\n"); //Mensagem antes de saída de usuário
			return 0; //Sair do sistema
			break;
			
			default:
			printf("Esse número não está na lista!\n\n"); //caso coloque algum número diferente do que aparece nas escolhas do menu
			system("pause"); //avisa o Sistema Operacional para pausar
			break;
			
		} //fim da seleção
		

	} //fim do loop

}