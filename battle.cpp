#include "game.h"

//Função que verifica se o seu attack acertou ou não o inimigo.
//Pode ser usada para o inimigo, também, só mudando o paremetro na hora de chamar ela.
int Tpersonagem::checaAcerto(Tpersonagem* player, Tpersonagem* enemy)
{
	int dado, acerto;
	dado   = player->rolaDado(20);

	//Falta arrumar o cauculo do acerto.
	acerto = dado;
	if (acerto >= enemy->armadura)
		return 1;
	return 0;
}

//Função que define um ataque basico.
//Pode ser usada tanto para o personagem quanto para os inimigos.
void Tpersonagem::attack(Tpersonagem* personagem)
{
	int dado, dano;
	dado = personagem->rolaDado(20);

	//Falta arrumar o cauculo do dano.
	dano = dado;
	cout << "seu dano foi de: " << dano << endl;
}

void Tpersonagem::danoSofrido(Tpersonagem* personagem, int dano)
{
	int i;
	i = 3;
}

//Função que simula uma batalha entre um jogador e um inimigo.
//Lembrar que um jogador pode estar em batalhas com mais de 1 inimigo.
//Entretando é só chamar a função novamente mudando os parametros.
void Tboard::battle(Tpersonagem* player, Tpersonagem* enemy)
{
	int i;
	char acao;
	while ( ((player->life > 0) || (enemy->life) > 0))
	{
		//ImprimeFicha.
		player->retornaVida(player);
		enemy->retornaVida(enemy);
		cout << "Aperte a para atacar: " << endl;
		cin  >> acao;
		switch (acao)
		{
			case 'A':
			case 'a':
				if(player->checaAcerto(player, enemy))
					player->attack(player);
			break;
		};
	}
}