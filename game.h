//Bibliotecas pradões de c++.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


//-------------------------------------------------------------------------------------------------//
//                                             NPCS & Player                                       //
//-------------------------------------------------------------------------------------------------//

struct TStatus
{
	int forca;        										//Força do jogador. Dano fisico dele.
	int destreza;     										//Agilidade do jogador. Define a esquiva e a acuracia dele.
	int constituicao;										//Ajuda a definir a vida do jogodar.
	int inteligencia;										//Inteligencia do jogador. Ajuda no dano das magias.
	int sabedoria;   									    //Ajuda em algumas magias e a ler textos.
	int carisma;      										//Adjuda em algumas magias e a convencer NPCs.
};

//Modificadores servem para algumas açoes especificas no jogo.
//Por exemplo, algumas açoes como o ataque sao influenciadas por certos modificadores.
struct TModficadores
{
	int forca;		
	int destreza;
	int constituicao;
	int inteligencia;
	int sabedoria;
	int carisma;
};

//Informaçoes necessárias para o jogador.
struct Tpersonagem
{
	
	int id;                                                 //Identificador.
	int level;												//Nivel do personagem.
	int exp;												//Quantidade de experiencia do personagem, ajuda a subir de nivel.

	int position;											//Posição dele no mapa.
	int deslocamento;										//O quanto ele pode se mover.

	int lifeMAX;											//Vida máxima do personagem.
	int life;												//Vida atual do personagem.
	int armadura;											//A armadura dele, ajuda a se defender/esquivar de ataques.
	int iniciativa;											//Ajuda a decidir a ordem das ações em batalha.

	char testeDeResistencia;								//Define o modificador que será usado para algum teste.

	TStatus        status;									//Os status do personagem: FOR, DEX, INT...
	TModficadores  modificador;								//Modificadores que serão usados em algumas funções.
	//TEquipamentos* equipamentos;
	//TGrimorio*     grimorio;

	public:
	void inserirPersonagem (Tpersonagem*, int, int);		//Função que "insere" o personagem no mundo(board).
	void retornaVida       (Tpersonagem*);					//Função que diz a vida restante do personagem(life - dano);
	void attack            (Tpersonagem*);					//Função que define o ataque básico do personagem.
	void danoSofrido       (Tpersonagem*, int);             //Função que dá dano no personagem.
	int  rolaDado          (int);							//Função que simula a rolagem de um dado.
	int  checaAcerto       (Tpersonagem*, Tpersonagem*);	//Função que chega se um personagem acertou ou não outro.
};

//-------------------------------------------------------------------------------------------------//
//                                             BOARD                                               //
//-------------------------------------------------------------------------------------------------//

//Struct que define o tabuleiro do jogo.
#define n 10
#define numEnemies 1
struct Tboard
{
	int tile[n*n];											//O mapa do jogo.
	Tpersonagem player;										//O player dentro do mapa.
	Tpersonagem enemies[numEnemies];						//Todos os inimigos do mapa.

public:
	void movimentaPersonagem (Tboard*, Tpersonagem*, char);	// 	
	void constroiBoard       (Tboard*);						//
	void imprimeBoard        (Tboard*);						//
	int  encounter           (Tpersonagem*, Tpersonagem*);	//
	void battle              (Tpersonagem*, Tpersonagem*);	//
};