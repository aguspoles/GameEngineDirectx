#ifndef FLOOR_H
#define FLOOR_H
#include "Entity.h"

class Floor :
	public Entity
{
public:
	Floor();
	Floor(LPDIRECT3DDEVICE9 dev);
	~Floor();

	void Init();
	void Update();

	std::string GetType() const;
};

#endif

