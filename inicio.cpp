#include <iostream>
#include <iomanip>
#include <fstream>

#include "game.h"

//Define as bordas do mapa, ou seja, os limites do mapa.
void constroiBordas (Tboard* board)
{
	int i, j;
	for (i = 0, j = (n - 1)*n; i < n; i++, j++)
	{
		board->tile[i] = 9;
		board->tile[j] = 9;
	}
	for (i = n, j = n - 1; i < n*n; i+= n, j+= n)
	{
		board->tile[i] = 9;
		board->tile[j] = 9;
	}
}

//Constrói o mapa propriamente dito.
//Alterar a função para que leia um arquivo de entrada .txt e gere o mapa.
void Tboard::constroiBoard (Tboard* board)
{
	for (int i = 0; i < n*n; i++)
		board->tile[i] = 0;
	constroiBordas(board);
}

//Imprime o mapa com todos os jogadores, inimigos...
void Tboard::imprimeBoard (Tboard* board)
{
	int i;
	board->tile[board->player.position] = board->player.id;
	for (i = 0; i < numEnemies; i++)
		board->tile[enemies[i].position] = board->enemies[i].id;
	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			cout << board->tile[i*n + j] << " ";
		cout << endl;
	}
}

//Função que "insere" o personagem no mapa.
void Tpersonagem::inserirPersonagem (Tpersonagem* personagem, int id, int position)
{
	personagem->id       = id;
	personagem->position = position;
}