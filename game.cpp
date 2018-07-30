#include "game.h"

//Seta a vida e o dano do personagem.
//Quando for inicializar o personagem com uma função isso estará dentro dessa função.
void returnLife (Tpersonagem* personagem, int life)
{
	personagem->lifeMAX = life;
	personagem->life = life;
}


//Namespace do programa.
#define n 10 //Nao esquecer de fazer o mapa de tamanho variavel e lido de um arquivo.
int main(int argc, char const *argv[])
{
	int tamBoard = n*n;
	char move;
	Tboard* board = new Tboard[sizeof(struct Tboard) + int(tamBoard)];
	Tpersonagem* player = &(board->player);
	Tpersonagem* enemy  = &(board->enemies[0]);
	board->constroiBoard(board);
	player->inserirPersonagem(player, 1, n + 1);
	enemy->inserirPersonagem(enemy, 2, n + 2);

	returnLife(player, 10);
	returnLife(enemy, 10);

	while (true)
	{
		board->imprimeBoard(board);
		cin >> move;
		board->movimentaPersonagem(board, player, move);
		if(board->encounter(player, enemy))
		 	board->battle(player, enemy);
	}
	return 0;
}