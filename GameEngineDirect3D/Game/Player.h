#pragma once
#include "Entity.h"
#include "Enemy.h"

class Player : public Entity
{
private:

public:
	Player();
	~Player();

	void Update();
	void Move(D3DXVECTOR3 pos);
	void Scale(D3DXVECTOR3 sca);
	void Rotate(D3DXVECTOR3 sca);

	void EnemyCollision(Enemy e);

};

