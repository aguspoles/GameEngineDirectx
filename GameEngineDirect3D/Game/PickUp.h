#ifndef PICKUP_H
#define PICKUP_H
#include "Entity.h"

class PickUp :
	public Entity
{
private:
	int _direction = 1;
public:
	PickUp();
	PickUp(LPDIRECT3DDEVICE9 dev);
	~PickUp();

	void Init();
	void Update();

	void Move();

	std::string GetType() const;
};

#endif