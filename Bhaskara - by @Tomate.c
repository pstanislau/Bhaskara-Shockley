/**
**=========================================================================================
**
** PROGRAMA PARA FAZER BHASKARA PARA O CADERNO DE CAMPO DO MOTTA
** by @Tomate
**
**=========================================================================================
*/

/*
**=========================================================================================
** Considera��es do c�digo:
**
** O programa tem duas op��es:
** - Tu podes informar s� os valores anteriores a bhaskara, no caso, 'a', 'b' e 'c' e
** ele vai resolver tranquilamente.
** - Ou tu pode pedir pro programa fazer tudo desde a equa��o de Shockley, informando
** Rs, Idss e Vgs_off para ele.
**
** O programa n�o trabalha com nota��o cient�fica, tu vai ter que fazer as convers�es por
** ti pr�prio dai :(
**
**=========================================================================================
*/



/* Prot�tipos */

/* Includes */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>
#include <math.h>
#include <string.h>

void main(void)
{
	/* Configura��es prim�rias */
	setlocale(LC_ALL,"portuguese");		// Habilita caracteres da l�ngua portuguesa
	srand(time(NULL));					// Habilita a gera��o de n�meros rand�micos

	float a 		= 0,
		  b 		= 0,
		  c 		= 0,
		  aux_a 	= 0,
		  aux_b 	= 0,
		  aux_c 	= 0,
		  rs   		= 0,
		  idss 		= 0,
		  vgs_off 	= 0,
		  vgg       = 0,
		  aux_1 	= 0,
		  aux_2 	= 0;
	int   opcao 	= 0,
		  cnt 		= 0;
	char ch_cntrl;
	float resultado[2] = {0};

	do {
		system("cls");
		puts("Op��es Dispon�veis: ");
		puts("1. C�lculo a partir da Bhaskara ");
		puts("2. C�lculo a partir da Eq. de Shockley ");
		printf("Digite a op��o desejada: ");
		scanf("%d",&opcao);
	} while (opcao < 1 || opcao > 2 );


	while( ch_cntrl != 27 )
	{
		start_sw:
		switch(opcao)
		{
			case 1:
				system("cls");
				if(cnt >= 1)
				{
					printf("Deseja trocar de op��o? \n");
					printf(" 1 -> Sim!   2 -> N�o! \n");
					scanf("%d",&opcao);
					if(opcao == 1 && cnt == 1)
						opcao = 2;
					else if (opcao == 2)
						opcao = 1;
					cnt = 0;
					goto start_sw;
				}
				/* Recebendo os valores de a,b,c */
				printf("Digite o valor de a: ");
				scanf("%f",&a);
				printf("Digite o valor de b: ");
				scanf("%f",&b);
				printf("Digite o valor de c: ");
				scanf("%f",&c);
				/* Recebendo os valores de a,b,c */

				shock:

				aux_a = a;
				aux_b = b * (-1);	// Inverte o sinal de 'b'
				aux_c = c;

				printf("          ____________________________________________ \n");
				printf("%.2f +- \\| (%.2f)� -4 . %.2f . %.6f \n",aux_b,b,a,c);
				printf("------------------------------------------------------ \n");
				printf("             2 . %.2f \n",a);

				aux_a = 2 * a;
				aux_b = pow(b,2);
				aux_c = (-4) * a * c;
				b = b * (-1);

				printf("          __________________________ \n");
				printf("%.2f +- \\| %.2f + (%.2f) \n",b,aux_b,aux_c);
				printf("------------------------------------ \n");
				printf("      %.2f \n",aux_a);

				aux_c = aux_b + aux_c;

				printf("          _____________ \n");
				printf("%.2f +- \\| %.2f \n",b,aux_c);
				printf("----------------------- \n");
				printf("      %.2f \n\n",aux_a);

				aux_c = sqrt(aux_c);

				printf("%.2f +- %.2f \n",b,aux_c);
				printf("------------------ \n");
				printf("   %.2f \n\n",aux_a);

					/* IDQ LINHA */
				puts(" *IDQ': \n");

				printf("%.2f + %.2f \n",b,aux_c);
				printf("------------------ \n");
				printf("   %.2f \n\n",aux_a);

				aux_b = b + aux_c;

				printf("%.2f \n",aux_b);
				printf("--------- \n");
				printf("%.2f \n\n",aux_a);

				resultado[0] = aux_b / aux_a;
				printf("IDQ' = %.6f \n\n",resultado[0]);
					/* IDQ LINHA */

					/* IDQ DUAS LINHAS */
				puts(" *IDQ'': \n");

				printf("%.2f - %.2f \n",b,aux_c);
				printf("------------------ \n");
				printf("   %.2f \n\n",aux_a);

				aux_b = b - aux_c;

				printf("%.2f \n",aux_b);
				printf("--------- \n");
				printf("%.2f \n\n",aux_a);

				resultado[1] = aux_b / aux_a;
				printf("IDQ'' = %.6f",resultado[1]);
					/* IDQ DUAS LINHAS */

				cnt = 1;
				printf("\n\nAperte qualquer tecla para refazer a Bhaskara \n");
				printf(" **ESC encerra o programa:  ");
				ch_cntrl = getch();
				break;

			case 2:		// A partir da eq de Shockley
				system("cls");
				if(cnt >= 1)
				{
					printf("Deseja trocar de op��o? \n");
					printf(" 1 -> Sim!   2 -> N�o! \n");
					scanf("%d",&opcao);
					cnt = 0;
					goto start_sw;
				}
				printf("Digite o valor de Rs: ");
				scanf("%f",&rs);
				printf("Digite o valor de Idss: ");
				scanf("%f",&idss);
				printf("Digite o valor de Vgg: ");
				scanf("%f",&vgg);
				printf("Digite o valor de Vgs_off: ");
				scanf("%f",&vgs_off);



				printf("\nIDQ = %.3f . (1 - (%.2f - %.2f.IDQ)� \n",idss,vgg,rs);
				printf("                 ---------------------\n");
				printf("                      -%.2f \n\n",vgs_off);

				aux_1 = (rs / vgs_off)*-1;
				vgg = (vgg/vgs_off);
				vgg +=1;

				printf("IDQ = %.3f . (%.2f + %.2f.IDQ)� \n\n",idss,vgg,aux_1);

				aux_2 = pow(aux_1,2);
				aux_1 = 2 * aux_1 * vgg;

				printf("IDQ = %.3f . (1%.2f + %.2f.IDQ + %.2f.IDQ�) \n\n",idss,vgg,aux_1,aux_2 );

				a = aux_2 * idss;
				b = aux_1 * idss;
				c = idss*(vgg*vgg);

				printf("IDQ = %.2f.IDQ� + %.2f.IDQ + %.3f \n\n",a,b,c);

				b = b - 1;

				printf("%.2f.IDQ� + %.2f.IDQ + %.3f = 0 \n\n",a,b,c);

				cnt = 2;
				goto shock;
				break;
		}
	}
}

