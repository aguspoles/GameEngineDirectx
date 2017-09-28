#ifndef PLAYER_H
#define PLAYER_H
#include "AnimatedEntity.h"
#include "Enemy.h"
#include "Game.h"

class Player : public AnimatedEntity
{
private:
	Transform* _transform;
	Material* _material;
public:
	Player();
	~Player();

	void Init();
	void UpdateComposite();

	std::string GetType() const;
	void EnemyCollision(const std::vector<MeshRenderer*> &entities);

	void WaterEffect();
	void Effect();

};

#endif
