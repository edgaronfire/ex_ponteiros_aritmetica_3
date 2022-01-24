/*-------------------------------------------------------------------------------------------------------------------------------------------------------------
	Título: Exercícios sobre aritmética de ponteiros aplicada em vetores

	Autor: Edgar Hideo Tamasiro
	Data: janeiro de 2022
	Versão: 1.0
	
-------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>

/* Constantes */
/*const*/
#define LEVELS 16

/* Macros */
/*#define*/

/* Declaração de variáveis globais */
char *ptr1, *ptr2,			/*dois ponteiros*/
	stack[LEVELS],			/*vetor que faz o papel da pilha*/
	stackData;				/*elemento que será lido e inserido*/
int	stackTop;				/*var. p/ informar o topo da pilha*/

/* Protótipo de funções */
void displayStack();
void push();
int pop();
void displayStackAddresses();

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Início da função principal */
main(int argc, char *argv[])
{
	int option;				/*p/ o menu de opções c/ switch-case*/
	stackTop = 0;	
	ptr1 = stack;			/*ambos os ponteiros recebem o endereço inicial do vetor*/
	ptr2 = stack;			/*ptr2 será fixo, terá valor do index0 e servirá como referência p/ efetuar a comparação de endereço c/ ptr1 que será variável*/
	printf("Demonstracao de aplicacao de aritmetica de ponteiros. Trabalhando com conceitos de pilha de dados com vetores (LIFO)\n");
	printf("Projeto de leitura de pilha de memoria com 16 posicoes de 1 Byte cada, e exibicao em formato hexadecimal\n\n");
	system("PAUSE");
	system("CLS");
	for( ; ; )				/*loop*/
		{
			printf("- - - M E N U - - -\n");
			printf("1 - mostrar pilha\n");
			printf("2 - inserir um dado\n");
			printf("3 - remover dado atual\n");
			printf("4 - sair\n\n");
			printf("---> ");
			scanf("%d", &option);
			switch(option)
				{
					case 1:
						putchar('\n');
						displayStack();
						break;
					case 2:
						push();
						break;
					case 3:
						pop();
						break;
					case 4:
						exit(0);
				}
			system("CLS");
		}
	system("PAUSE");					/*pausa execução*/
	return 0;						/*retorna 0, se main() for executada*/
} /* Fim da função principal */

/*-----------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* Desenvolvimento das funções */

/* --- Função para mostrar todo conteúdo da pilha --- */
void displayStack()
{
	register int i;
	if (ptr1 == ptr2)							/*comparação de endereços, se ptr1 estiver no endereço do index0 a pilha estará vazia*/
			printf("STACK_NULL\n");
	else										/*se não, irá mostrar os valores*/
		for(i=0; i<stackTop; i++)
				printf("Stack level %2d:   Endereco: %X   Valor: %X\n", i, &stack[i], stack[i]);
	/*printf("ptr1--: %X\n", ptr1);*/				/*DEBUG*/
	/*printf("stackTop: %d\n", stackTop);*/			/*DEBUG*/
	putchar('\n');
	system("PAUSE");
}

/* --- Função para inserir dados na pilha --- */
void push()
{
	register long timer;						/*variável para delay p/ ser possível visualizar a msg*/
	if (ptr1 == (ptr2 + LEVELS))				/*comparação de endereços, se ultrapassar o limite da pilha, indica o estouro e sai do programa*/
		{
			printf("STACK_OVERFLOW\n");
			system("PAUSE");
			exit(0);
		}
	else										/*se não, solicita um valor p/ add na pilha e imprime msg de adicionado*/
		{
			printf("Digite um dado (letras m/M, numeros, caracteres etc): ");
			scanf(" %c", &stackData);
			printf("Added\n");
		}

	for(timer = 0; timer < 1E8; timer++);		/*delay*/
	
	*ptr1 = stackData;							/*neste ponto, guarda o valor digitado no endereço atual da pilha*/
	ptr1++;										/*incrementa ptr1, p/ apontar p/ o próximo endereço*/
	stackTop++;									/*incrementa o topo*/
}

/* --- Função para remover dados da pilha --- */
int pop()
{
	register long timer;						/*variável de delay p/ ser possível visualizar a msg*/
	if (ptr1 == ptr2)							/*comparação de endereços, se ptr1 estiver no endereço do index0 a pilha estará vazia*/
		{
			printf("STACK_EMPTY\n");
			ptr1 = stack;						/*no caso de querer apagar logo que inicia o programa, volta ptr1 para o index0*/
		}
	else
		{
			printf("Removed\n");				/*se não, imprime msg de remoção*/
			ptr1--;								/*decrementa ptr1, retrocede um endereço da pilha*/
			stackTop--;							/*decrementa o topo*/
		}

	for(timer = 0; timer < 1E8; timer++);		/*delay*/

	/*printf("ptr1--: %X\n", ptr1);*/				/*DEBUG*/
	/*printf("stackTop: %d\n", stackTop);*/			/*DEBUG*/
	/*system("PAUSE");*/							/*DEBUG*/
	return *(ptr1 + 1);							/*retorna o conteúdo do endereço atual*/
}

/* --- Função para mostrar os endereços da pilha --- */
void displayStackAddresses()
{
	register int i;
	for(i = 0; i < LEVELS; i++)
		printf("Stack level %2d   Address: %X   Value: %c\n", i, &stack[i], stack[i]);
	putchar('\n');
	system("PAUSE");
}


/*-------------------------------------------------------------------------------

                                                              
                                       _                      
                                      / \                     
                                     |oo >                    
                                     _\=/_                    
                    ___         #   /  _  \   #               
                   /<> \         \\//|/.\|\\//                
                 _|_____|_        \/  \_/  \/                 
                | | === | |          |\ /|                    
                |_|  0  |_|          \_ _/                    
                 ||  0  ||           | | |                    
                 ||__*__||           | | |                    
                |* \___/ *|          []|[]                    
                /=\ /=\ /=\          | | |                    
________________[_]_[_]_[_]_________/_]_[_\_______________________________
                                                                                                                            
-------------------------------------------------------------------------------*/
/* final do programa  */

