#ifndef PICKUP_H
#define PICKUP_H
#include "MeshRenderer.h"
#include "Game.h"

class PickUp :
	public MeshRenderer
{
private:
	Transform* _transform;
	Material* _material;
	int _direction = 1;
public:
	PickUp();
	~PickUp();

	void Init();
	void UpdateComposite();

	void Move();

	std::string GetType() const;
};

#endif