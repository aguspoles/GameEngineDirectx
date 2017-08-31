#ifndef ENEMY_H
#define ENEMY_H
#include "MeshRenderer.h"
#include <vector>
#include "Game.h"

class Enemy : public MeshRenderer
{
private:
	Transform* _transform;
	Material* _material;
public:
	Enemy();
	~Enemy();

	void Init();
	void UpdateComposite();

	void Move();
	void Escape(std::vector<MeshRenderer*> entities);

	std::string GetType() const;

};

#endif