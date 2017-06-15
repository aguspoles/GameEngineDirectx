#ifndef ENEMY_H
#define ENEMY_H
#include "Entity.h"

class Enemy : public Entity
{
private:
	
public:
	Enemy();
	Enemy(LPDIRECT3DDEVICE9 dev);
	~Enemy();

	void Init();
	void Update();

	std::string GetType() const;

};

#endif