#include <stdio.h>
#include <stdlib.h>

// Declaração das funções de estado para que possam ser chamadas em qualquer ordem.
void q0();
void q1();
void q2();
void q3();
void q4_final(); // Renomeado para clareza, pois é um estado final
void q5();
void q6();
void q7();
void q8();
void q9();
void qErro();

// Variáveis globais
char palavra[100];
int controle = 0; // Controla a posição atual na palavra
int tamanho = 0;  // Armazena o tamanho da palavra

void main(void)
{
	printf("\nImplementando o AFD da imagem\n");
	printf("----------------------------------\n");
	printf("Entre com uma palavra: ");
	scanf("%s", palavra);

	// Calcula o tamanho da palavra
	while(palavra[tamanho] != '\0')
	{
		tamanho++;	
	}	
	
	printf("\nPalavra lida: %s", palavra);
	printf("\nTamanho da Palavra: %d\n", tamanho);
	
	// Inicia o processo no estado inicial q0
	controle = 0;
	q0();
}

// Estado inicial
void q0()
{
	printf(" -> q0");
	if(controle < tamanho) // Verifica se ainda há caracteres para ler
	{
		if(palavra[controle] == 'f')
		{
			controle++;
			q1();
		}
		else if(palavra[controle] == 'c')
		{
			controle++;
			q8();
		}
		else
		{
			qErro(); // Caractere inválido
		}
	}
	else
	{
		qErro(); // A palavra terminou, mas q0 não é um estado final
	}
}

void q1()
{
	printf(" -> q1");
	if(controle < tamanho)
	{ 	
		if(palavra[controle] == 'o')
		{
			controle++;
			q3();
		}
		else if(palavra[controle] == 'l')
		{
			controle++;
			q2();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

void q2()
{	
	printf(" -> q2");
	if(controle < tamanho)
	{ 	
		if(palavra[controle] == 'o')
		{
			controle++;
			q5();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

void q3()
{
	printf(" -> q3");
	if(controle < tamanho)
	{
		if(palavra[controle] == 'r')
		{
			controle++;
			q4_final();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

// Estado Final q4
void q4_final()
{
	printf(" -> q4");
	if(controle < tamanho) // Se a palavra continuar, é um erro
	{ 	
		qErro();
	}
	else // Se a palavra terminou aqui, ela é aceita
	{
		printf("\n\n>> Palavra Aceita! <<\n");
	}
}

void q5()
{
	printf(" -> q5");
	if(controle < tamanho)
	{
		if(palavra[controle] == 'a')
		{
			controle++;
			q6();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

void q6()
{
	printf(" -> q6");
	if(controle < tamanho)
	{
		if(palavra[controle] == 't')
		{
			controle++;
			q7();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

// Estado "beco sem saída"
void q7()
{
    printf(" -> q7");
	// Não importa se a palavra terminou ou não, q7 não é final e não tem saída.
	// Qualquer coisa que chegue aqui resulta em erro.
	qErro();
}

void q8()
{
	printf(" -> q8");
	if(controle < tamanho)
	{
		if(palavra[controle] == 'h')
		{
			controle++;
			q9();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}

void q9()
{
	printf(" -> q9");
	if(controle < tamanho)
	{
		if(palavra[controle] == 'a')
		{
			controle++;
			q3();
		}
		else
		{
			qErro();
		}
	}
	else
	{
		qErro(); // Não é estado final
	}
}


// Função para estado de erro
void qErro()
{
	printf(" -> qErro");
	printf("\n\n>> Palavra Nao Aceita. <<\n");
}
