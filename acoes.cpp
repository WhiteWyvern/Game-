#include "game.h"


//Verifica se o jogador não está tentando se mover para um lugar indevido.
int movimentoInvalido (Tboard* board, Tpersonagem* personagem)
{
	if (board->tile[board->player.position] == 9)
		return 1;
	return 0;
}

//Função que movimenta o personagem pelo mapa.
void Tboard::movimentaPersonagem (Tboard* board, Tpersonagem* personagem, char movimento)
{
	board->tile[board->player.position] = 0;
	switch (movimento)
	{
		case 'W':
		case 'w':
			personagem->position -= n;
			if(movimentoInvalido(board, personagem))
			{
				cout << "Não sai do mapa!" << endl;
				personagem->position += n;
			}
		break;

		case  'A':
		case  'a':
			personagem->position--;
			if(movimentoInvalido(board, personagem))
			{
				cout << "Não sai do mapa!" << endl;
				personagem->position++;
			}
		break;

		case 'S':
		case 's':
			personagem->position += n;
			if(movimentoInvalido(board, personagem))
			{
				cout << "Não sai do mapa!" << endl;
				personagem->position -= n;
			}
		break;

		case 'D':
		case 'd':
			personagem->position++;
			if(movimentoInvalido(board, personagem))
			{
				cout << "Não sai do mapa!" << endl;
				personagem->position--;
			}
		break;

		default:
			cout << "Movimento inválido" << endl;
	}
}

//Função que define o encontro do personagem com alguma coisa (um inimigo, por exemplo).
int Tboard::encounter (Tpersonagem* player, Tpersonagem* enemy)
{
	if (player->position == enemy->position)
	{
		//cout << "luta" << endl;
		return 1;
	}
	return 0;
}

//Função que diz a vida dos jogares.
void Tpersonagem::retornaVida (Tpersonagem* player)
{
	if (player->id == 1)
		cout << "Sua vida é: " << (player->life - player->dano) << endl;
	else
		cout << "A vida do inimigo é: " << (player->life - player->dano) << endl;
}

//Simula a rolagem de um dado.
int Tpersonagem::rolaDado (int typeDado)
{
	int dado;
	if ((typeDado == 4)  || (typeDado == 6) || (typeDado == 8) || (typeDado == 10) ||
		(typeDado == 12) ||  (typeDado == 20))
	{
		dado = rand() % typeDado;
		dado++;
		cout << "O resultado do dado é: " << dado << endl;
		return (dado);
	}
	else
	{
		cout << "Tipo de dado inexistente" << endl;
		return (0);
	}
}