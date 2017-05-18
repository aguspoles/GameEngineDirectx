#pragma once
#include "Entity.h"

class Enemy : public Entity
{
private:
	
public:
	Enemy();
	~Enemy();

	Transform GetTransform();

	void Update();

	void Move(D3DXVECTOR3 pos);
	void Scale(D3DXVECTOR3 sca);
	void Rotate(D3DXVECTOR3 sca);
};

