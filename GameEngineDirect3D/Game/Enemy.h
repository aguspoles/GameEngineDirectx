#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"
#include <vector>

class Enemy : public Entity
{
private:
	
public:
	Enemy();
	Enemy(LPDIRECT3DDEVICE9 dev);
	~Enemy();

	void Init();
	void Update();

	void Move();
	void Escape(std::vector<Entity*> entities);

	std::string GetType() const;

};

#endif