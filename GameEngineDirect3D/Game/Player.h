#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedEntity.h"
#include "Enemy.h"

class Player : public AnimatedEntity
{
private:

public:
	Player();
	Player(LPDIRECT3DDEVICE9 dev);
	~Player();

	void Init();
	void Update();

	std::string GetType() const;
	void EnemyCollision(const std::vector<Entity*> &entities);

	void WaterEffect();

};

#endif
