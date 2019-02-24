#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#include <conio.c>

int x = 0,escolha_jogo = 1,i,i2 = 0,i3 = 0,i4,vetor_sort[30],vetor_player[30],k = 0,tamanho_vetor,jo = 0,tempo,contador,aux;
char tec[1];

typedef struct score		//estrutura para salvar os dados do jogador(nome e pontuacao)
{
	char nome[20];
	int pontuacao;
}Scores;

Scores lista_scores_facil[5];		
Scores lista_scores_medio[5];
Scores lista_scores_dificil[5];
Scores lista_scores_auxiliar[5];
Scores lista_novo_auxiliar[1];

void pedir_dados_novo()		//pede os dados do jogador(nome) e adiciona o mesmo e sua pontuacao feita no arquivo
{
	fflush(stdin);
	gotoxy(27,15);
	printf("digite seu nome:");
	gets(lista_novo_auxiliar[0].nome);
	lista_novo_auxiliar[0].pontuacao = i2;
}

void printar_lista_facil()		//mostra o nome dos jogadores e das pontuacoes feitas por eles no nivel facil
{
	int posicao_tela = 6;
	for(i = 0;i < 5;i++)
	{
		gotoxy(4,posicao_tela);printf("%s",lista_scores_facil[i].nome);
		gotoxy(22,posicao_tela);printf("%d",lista_scores_facil[i].pontuacao);
		posicao_tela++;
	}
}

void printar_lista_medio()		//mostra o nome dos jogadores e das pontuacoes feitas por eles no nivel medio
{
	int posicao_tela = 6;
	for(i = 0;i < 5;i++)
	{
		gotoxy(26,posicao_tela);printf("%s",lista_scores_medio[i].nome);
		gotoxy(46,posicao_tela);printf("%d",lista_scores_medio[i].pontuacao);
		posicao_tela++;
	}
}

void printar_lista_dificil()		//mostra o nome dos jogadores e das pontuacoes feitas por eles no nivel dificil
{
	int posicao_tela = 6;
	for(i = 0;i < 5;i++)
	{
		gotoxy(50,posicao_tela);printf("%s",lista_scores_dificil[i].nome);
		gotoxy(74,posicao_tela);printf("%d",lista_scores_dificil[i].pontuacao);
		posicao_tela++;
	}
}

void ordenador_facil()		//coloca as pontuacoes do nivel facil em ordem(da maior para a menor)
{
	aux = 0;
	int b, n;
	for(b = 4;b >= 0;b--)
	{
		if(lista_novo_auxiliar[0].pontuacao > lista_scores_facil[b].pontuacao)
		{
			lista_scores_auxiliar[aux] = lista_scores_facil[b];
			aux++;
		}
		else
		{		
			lista_scores_facil[b+1] = lista_novo_auxiliar[0];
			for(n = b+2; n <= 4; n++)
			{
				lista_scores_facil[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
		if (b == 0 && lista_novo_auxiliar[0].pontuacao > lista_scores_facil[b].pontuacao)
		{
			lista_scores_facil[0] = lista_novo_auxiliar[0];
			for(n = 1; n <= 4; n++)
			{
				lista_scores_facil[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
	}	
}

void ordenador_medio()		//coloca as pontuacoes do nivel medio em ordem(da maior para a menor)
{
	aux = 0;
	int b, n;
	for(b = 4;b >= 0;b--)
	{
		if(lista_novo_auxiliar[0].pontuacao > lista_scores_medio[b].pontuacao)
		{
			lista_scores_auxiliar[aux] = lista_scores_medio[b];
			aux++;
		}
		else
		{		
			lista_scores_medio[b+1] = lista_novo_auxiliar[0];
			for(n = b+2; n <= 4; n++)
			{
				lista_scores_medio[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
		if (b == 0 && lista_novo_auxiliar[0].pontuacao > lista_scores_facil[b].pontuacao)
		{
			lista_scores_medio[0] = lista_novo_auxiliar[0];;
			for(n = 1; n <= 4; n++)
			{
				lista_scores_medio[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
	}	
}

void ordenador_dificil()		//coloca as pontuacoes do nivel dificil em ordem(da maior para a menor)
{
	aux = 0;
	int b, n;
	for(b = 4;b >= 0;b--)
	{
		if(lista_novo_auxiliar[0].pontuacao > lista_scores_dificil[b].pontuacao)
		{
			lista_scores_auxiliar[aux] = lista_scores_dificil[b];
			aux++;
		}
		else
		{		
			lista_scores_dificil[b+1] = lista_novo_auxiliar[0];
			for(n = b+2; n <= 4; n++)
			{
				lista_scores_dificil[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
		if (b == 0 && lista_novo_auxiliar[0].pontuacao > lista_scores_dificil[b].pontuacao)
		{
			lista_scores_dificil[0] = lista_novo_auxiliar[0];	
			for(n = 1; n <= 4; n++)
			{
				lista_scores_dificil[n] = lista_scores_auxiliar[aux-1];
				aux--;
			}
			b = -1;
		}
	}	
}

void gravar_em_arquivo_facil()		//grava as informacoes digitadas pelo usuario no arquivo relacionado ao nivel facil
{
	FILE *fp;
	if ((fp=fopen ("pontacao_facil.txt","w")) != NULL)
	{
		for(int i = 0; i < 5; i++) 
		{
			fprintf(fp, "%s %d\n", lista_scores_facil[i].nome, lista_scores_facil[i].pontuacao);
		}
	}
	fclose(fp);
}

void gravar_em_arquivo_medio()		//grava as informacoes digitadas pelo usuario no arquivo relacionado ao nivel medio
{
	FILE *fp;
	if ((fp = fopen ("pontacao_medio.txt","w")) != NULL) 
	{
		for(int i = 0; i < 5; i++) 
		{
			fprintf(fp, "%s %d\n", lista_scores_medio[i].nome, lista_scores_medio[i].pontuacao);
		}
	}
	fclose(fp);
}

void gravar_em_arquivo_dificil()		//grava as informacoes digitadas pelo usuario no arquivo relacionado ao nivel dificil
{
	FILE *fp;
	if ((fp = fopen ("pontacao_dificil.txt","w")) != NULL) 
	{
		for(int i = 0; i < 5; i++) 
		{
			fprintf(fp, "%s %d\n", lista_scores_dificil[i].nome, lista_scores_dificil[i].pontuacao);
		}
	}
	fclose(fp);
}

void leitor_de_arquivo_facil()		//le as informacoes que estao dentro do arquivo do nivel facil
{
	FILE *fp;
	if ((fp = fopen ("pontacao_facil.txt","r")) != NULL) 
	{
		for(contador = 0;contador < 5;contador++)
		{
			fscanf(fp,"%s %i\n", &lista_scores_facil[contador].nome, &lista_scores_facil[contador].pontuacao);
		}
		fclose(fp);
	}
	else
	{
		printf("deu meda");
	}
}

void leitor_de_arquivo_medio()		//le as informacoes que estao dentro do arquivo do nivel medio
{
	FILE *fp;
	if ((fp=fopen ("pontacao_medio.txt","r")) != NULL) 
	{
		for(contador = 0;contador < 5;contador++)
		{
			fscanf(fp,"%s %i\n", &lista_scores_medio[contador].nome, &lista_scores_medio[contador].pontuacao);
		}
	fclose(fp);
	}
	else
	{
		printf("deu meda");
	}
}

void leitor_de_arquivo_dificil()		//le as informacoes que estao dentro do arquivo do nivel dificil
{
	FILE *fp;
	if ((fp=fopen ("pontacao_dificil.txt","r")) != NULL) 
	{
		for(contador = 0;contador < 5;contador++)
		{
			fscanf(fp,"%s %i\n", &lista_scores_dificil[contador].nome, &lista_scores_dificil[contador].pontuacao);
		}
	fclose(fp);
	}
	else
	{
		printf("deu meda");
	}
}

void tela_pontuacao()		
{
	gotoxy(35,3);printf("PONTUACOES");
	gotoxy(12,5);printf("FACIL");
	gotoxy(36,5);printf("MEDIO");
	gotoxy(60,5);printf("DIFICIL");
}

int sorteio()	//faz o sorteio dos numeros e os coloca dentro do vetor_sotr que sera utilizado para tocar para o usuario imitar(tocar de novo).
{ 
	int num_sort;
	srand(time(NULL));
	num_sort = rand() % 4+1;
	vetor_sort[i2] = num_sort;
	i2++;
}
 
void tela_logo()	
{
	 gotoxy(15,6);printf(" ######   ######## ##    ## #### ##     ##  ######	\n"); 
	 gotoxy(15,7);printf("##    ##  ##       ###   ##  ##  ##     ## ##    ## \n");
	 gotoxy(15,8);printf("##        ##       ####  ##  ##  ##     ## ##       \n");
	 gotoxy(15,9);printf("##   #### ######   ## ## ##  ##  ##     ##  ######  \n");
	gotoxy(15,10);printf("##    ##  ##       ##  ####  ##  ##     ##       ## \n");
	gotoxy(15,11);printf("##    ##  ##       ##   ###  ##  ##     ## ##    ## \n");
 	gotoxy(15,12);printf(" ######   ######## ##    ## ####  #######   ######  \n");   
	 
	                                                                                                      
}

void tela_espera()		//tela que exibe uma mensagem de carregamento para "preparar" o usuario para o jogo
{
	int contador = 0;
	system("cls");
	gotoxy(36,12);printf("aguarde");
	
	for(contador = 0;contador < 3;contador++)
	{
		Sleep(1000);
		printf(".");	
	}
	system("cls");
}

void sair()		//tela que exibe uma mensagem de carregamento para "preparar" o usuario para o jogo
{
	int contador = 0;
	system("cls");
	gotoxy(36,12);printf("Obrigado por jogar!");
	gotoxy(36,14);printf("Desenvolvido por:");
	gotoxy(36,15);printf("Icaro Mateus Eloi");
	gotoxy(36,16);printf("Jhon Wilker Sousa");
	
	
}

void tela_opcao()		//mostra as opcoes de novo jogo e de acesso as pontuacoes para o usuario
{
	gotoxy(34,15);printf("1 - Novo Jogo");
	gotoxy(34,16);printf("2 - Pontuacoes");
	gotoxy(34,17);printf("0 - Sair");
	
	gotoxy(33,18);printf("digite a opcao:");

}

void tela_opcao_nivel()		//mostra os niveis de dificuldade que esstao disponiveis para o jogo
{
	gotoxy(34,15);printf("1 - Facil");
	gotoxy(34,16);printf("2 - Medio");
	gotoxy(34,17);printf("3 - Dificil");
	gotoxy(34,18);printf("0 - Voltar");
	
	gotoxy(33,19);printf("digite a opcao:");

}

void limpa_tela_opcao()		//apaga somente partes da tela ja predefinidas para que aparecam novas opcoes no lugar
{
	gotoxy(34,15);printf("                         ");
	gotoxy(30,16);printf("                                       ");
	gotoxy(34,17);printf("                                       ");
	gotoxy(33,18);printf("                                       ");
	gotoxy(33,19);printf("                                       ");
}

void azul()		// mostra o quadrado azul usando gotoxy no lugar correto.
{
	for(i = 1;i < 8;i++)
	{
		textbackground(BLUE);
		gotoxy(32,1+i);
		printf("                ");	
	}	
}

void amarelo()		// mostra o quadrado amarelo usando gotoxy no lugar correto.
{
	for(i = 1;i < 8;i++)
	{
		textbackground(YELLOW);
		gotoxy(16,8+i);
		printf("                ");	
    }
}

void verde()	// mostra o quadrado verde usando gotoxy no lugar correto.
{
	for(i = 1;i < 8;i++)
	{
		textbackground(GREEN);
		gotoxy(48,8+i);
		printf("                ");	
    }
}

void vermelho()		// mostra o quadrado vermelho usando gotoxy no lugar correto.
{
	for(i = 1;i < 8;i++)
	{
		textbackground(RED);
		gotoxy(32,15+i);
		printf("                ");	
    }
}

void azul_apagado()			//funcao para indicar que a cor azul "apagou"
{
	for(i = 1;i < 8;i++)
	{
		textbackground(BLACK);
		gotoxy(32,1+i);
		printf("                ");	
	}
	//Mi
	Beep(493.63,tempo);
	Sleep(tempo);
	azul();
}

void amarelo_apagado()		//funcao para indicar que a cor amarelo "apagou"
{
	for(i = 1;i < 8;i++)
	{
		textbackground(BLACK);
		gotoxy(16,8+i);
		printf("                ");	
	}
	//Si
	Beep(392.63,tempo);
	Sleep(tempo);
	amarelo();
}

void verde_apagado()		//funcao para indicar que a cor verde "apagou"
{
	for(i = 1;i < 8;i++)
	{
		textbackground(BLACK);
		gotoxy(48,8+i);
		printf("                ");	
	}
	//Sol
	Beep(329.63,tempo);
	Sleep(tempo);
	verde();
}

void vermelho_apagado()			//funcao para indicar que a cor vermelho "apagou"
{
	
	for(i = 1;i < 8;i++)
	{
		textbackground(BLACK);
		gotoxy(32,15+i);
		printf("                ");	
	}
	//Dó
	Beep(261.63,tempo);
	Sleep(tempo);
	vermelho();
}

void mostrar_cores()		//funcao que mostra somente as cores na tela inicial no jogo
{
	azul();
	amarelo();
	verde();
	vermelho();
}

void setas()		//mostra as setas no jogo para auxiliar o usuario a jogar 
{
	textbackground(BLACK);	

	//azul
	gotoxy(40,9);
	printf("%c",30);
	gotoxy(40,10);
	printf("1");
	
	//vermelho
	gotoxy(40,15);
	printf("%c",31);
	gotoxy(40,14);
	printf("4");
	
	//amarelo
	gotoxy(32,12);
	printf("%c2",17);
	
	//verde
	gotoxy(46,12);
	printf("3%c",16);
}

void mostra_jogadas_restantes()		//mostra a quantidade de jogadas/nivel para ajudar o usuario
{
	textbackground(BLACK);
	gotoxy(40,12);
	printf("%d",i2);
}

void tocar_vetor_completo()		//pega o vetor_sort e de acordo com cada item faz a cor piscar utilizando a funcao (cor) apagado.
{ 
	for(i4 = 0;i4 < i2;i4++)
	{
		if(vetor_sort[i4] == 4)
		{
			vermelho_apagado();
			Sleep(50);
		}else if(vetor_sort[i4] == 1)
		{
			azul_apagado();
			Sleep(50);
		}else if(vetor_sort[i4] == 2)
		{
			amarelo_apagado();
			Sleep(50);
		}else if(vetor_sort[i4] == 3)
		{
			verde_apagado();
			Sleep(50);	
		}
	}
}	

int comparacao_vetores()	//compara os valoes digitados pelo usuario e os ja 'salvos' para verificar se a sequencia que o usuario digitou esta correta ou nao
{
	int ind;
	for(ind = 0;ind < i2;ind++)
	{
		if(vetor_player[ind] == vetor_sort[ind])
		{
			
		}
		else
		{
			k++;
		}
	}	
}

void jogada_player()		//funcao que permite que o jogador digite a sequencia visualizada por ele
{
	for(jo = 0;jo < i2;jo++)
	{
		textbackground(BLACK);
		gotoxy(56+jo,19);
		tec[0] = getche(); //getche recebe valores do teclado sem necessicdade de apertar o enter.
		vetor_player[jo] = atoi(tec); //atoi converter o char em int 1(char) em 1(int)
									
		if(vetor_player[jo] == 4)
		{
			vermelho_apagado();
			textbackground(BLACK);
		}else if(vetor_player[jo] == 1)
		{
			azul_apagado();
			textbackground(BLACK);					//só pra dizer quem foi apertado,e piscar o memsmo.
		}else if(vetor_player[jo] == 2)
		{
			amarelo_apagado();
			textbackground(BLACK);
		}else if(vetor_player[jo] == 3)
		{
			verde_apagado();
			textbackground(BLACK);
		}
	}
}

void jogabilidade_facil()		//conjunto de funcoes que serao utilizdas no nivel facil
{
	mostrar_cores();
	setas();
	sorteio();
	Sleep(tempo);
	mostra_jogadas_restantes();
	tocar_vetor_completo();
	gotoxy(56,18);
	textbackground(BLACK);
	printf("SUA VEZ:");
	gotoxy(56,19);
	Sleep(50);
	jogada_player();
	Sleep(1000);
	gotoxy(56,18);printf("                  ");
	gotoxy(56,19);printf("                  ");
}

void jogabilidade_medio()		//conjunto de funcoes que serao utilizdas no nivel medio
{
	mostrar_cores();
	setas();
	sorteio();
	Sleep(tempo);
	mostra_jogadas_restantes();
	tocar_vetor_completo();
	gotoxy(56,18);
	textbackground(BLACK);
	printf("SUA VEZ:");
	gotoxy(56,19);
	Sleep(50);
	jogada_player();
	Sleep(1000);
	gotoxy(56,18);printf("                  ");
	gotoxy(56,19);printf("                  ");
}

void jogabilidade_dificil()				//conjunto de funcoes que serao utilizdas no nivel dificil
{
	mostrar_cores();
	setas();
	sorteio();
	Sleep(800);
	sorteio();
	Sleep(tempo);
	tocar_vetor_completo();
	gotoxy(56,18);
	textbackground(BLACK);
	printf("SUA VEZ:");
	gotoxy(56,19);
	Sleep(50);
	jogada_player();
	Sleep(1000);
	gotoxy(56,18);printf("                  ");
	gotoxy(56,19);printf("                  ");
}

void facil()		//mostra uma mensagem de erro(caso nao acerte a sequencia) ou de acerto caso acerte todas as sequencias dos niveis disponiveis na modalidade de jogo facil
{
		tempo=1000;
		while(k == 0 && i2<15)
		{
			jogabilidade_facil();
			comparacao_vetores();//aqui k vai mudar ou nao na comparacao se errar k=1,se acertar continua 0 e se acertar ate o for terminar msg de 
		}
		if(k==0){
			system("cls");
			gotoxy(33,11);printf("PARABEEEENNNSSSS!!");
			 gotoxy(30,13);printf("Dificuldade Conquistada!");
			leitor_de_arquivo_facil();
			pedir_dados_novo();	//AQUI FUNCAO PEDIR NOME DO JOGADOR, COLETAR I2 E SALVAR NO SCORE
			ordenador_facil();
			gravar_em_arquivo_facil();
			
		}else{
			system("cls");
			gotoxy(15,12);printf("ERRRRRRRRRRRRRRRRRRRROUUUUUUUUUUUUUUUUUUUUUUUUU\n");
			leitor_de_arquivo_facil();
			pedir_dados_novo();
			ordenador_facil();
			gravar_em_arquivo_facil();
			
		}
		
}
	
void medio()		//mostra uma mensagem de erro(caso nao acerte a sequencia) ou de acerto caso acerte todas as sequencias dos niveis disponiveis na modalidade de jogo medio
{
		tempo=400;
		while(k == 0 && i2<30)
		{
			jogabilidade_medio();
			comparacao_vetores();//aqui k vai mudar ou nao na comparacao se errar k=1,se acertar continua 0 e se acertar ate o for terminar msg de 
		}
		if(k==0){
			system("cls");
			gotoxy(33,11);printf("PARABEEEENNNSSSS!!");
	 		gotoxy(30,13);printf("Dificuldade Conquistada!");
			leitor_de_arquivo_medio();
			pedir_dados_novo();
			ordenador_medio();
			gravar_em_arquivo_medio();
			
		}else{
			system("cls");
			gotoxy(15,12);printf("ERRRRRRRRRRRRRRRRRRRROUUUUUUUUUUUUUUUUUUUUUUUUU\n");
			leitor_de_arquivo_medio();
			pedir_dados_novo();
			ordenador_medio();
			gravar_em_arquivo_medio();
			
		}
}
	
void dificil()			//mostra uma mensagem de erro(caso nao acerte a sequencia) ou de acerto caso acerte todas as sequencias dos niveis disponiveis na modalidade de jogo dificil
{
		tempo=200;
		while(k == 0 && i2<40)
		{
			jogabilidade_dificil();
			comparacao_vetores();//aqui k vai mudar ou nao na comparacao se errar k=1,se acertar continua 0 e se acertar ate o for terminar msg de 
		}
		if(k==0){
			system("cls");
			gotoxy(33,11);printf("PARABEEEENNNSSSS!!");
	 		gotoxy(30,13);printf("Dificuldade Conquistada!");
			leitor_de_arquivo_dificil();
			pedir_dados_novo();
			ordenador_dificil();
			gravar_em_arquivo_dificil();
		}else{
			system("cls");
			gotoxy(15,12);printf("ERRRRRRRRRRRRRRRRRRRROUUUUUUUUUUUUUUUUUUUUUUUUU\n");
			leitor_de_arquivo_dificil();
			pedir_dados_novo();
			ordenador_dificil();
			gravar_em_arquivo_dificil();
		}	
}

menu_nivel()
{
	int escolha_nivel=1;
	k=0;
	system("cls");
        	tela_logo();
        	tela_opcao_nivel();
        	scanf("%d", &escolha_nivel);
					switch(escolha_nivel) 
					{
				        case 1:
				        	i2=0;
				        	tela_espera();
				            facil();
							menu_nivel();
				            break;
				
				        case 2:
				            i2=0;
				            tela_espera();
				            medio();
				            menu_nivel();
				            break;
				
				        case 3:
				            i2=0;
				            tela_espera();
				            dificil();
				            menu_nivel();
				            break;
				
				        case 0:
				        	limpa_tela_opcao();	
				            break;
				
				        default:
				        	limpa_tela_opcao();
				    		gotoxy(30,16);printf("Digite uma opcao valida!\n");
				    		Sleep(1000);
				    		limpa_tela_opcao();
				    }
	
	
}

main()
{	
	tela_logo();
	tela_opcao();
	scanf("%d", &escolha_jogo);
	switch(escolha_jogo) 
	{
        case 1:
        	menu_nivel();
			main();	
			break;
		 
        case 2:
        	system("cls");
        	printf("\n");
        	tela_pontuacao();
        	printf("\n");
        	leitor_de_arquivo_facil();
        	leitor_de_arquivo_medio();
        	leitor_de_arquivo_dificil();
        	printf("\n");
			printar_lista_facil();
			printf("\n");
			printar_lista_medio();
			printf("\n");
			printar_lista_dificil();
			printf("\n");
			printf("\n");
			printf("\n");
			printf("\n");
			printf("                Pressione qualquer tecla para voltar ao MENU:");
			getche();
			system("cls");
			main();
			break;
		 
        case 0:
            tela_espera();
            sair();
            break;

        default:
        	limpa_tela_opcao();
    		gotoxy(30,16);printf("Digite uma opcao valida!\n");
    		Sleep(1000);
    		limpa_tela_opcao();
            main();
    }
}

