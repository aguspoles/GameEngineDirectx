#pragma once
#include "Entity.h"
#include "Animation.h"

class ENGINE_API AnimatedEntity :
	public Entity
{
private:
	std::vector<Animation*> _animations;
	Animation* _currentAnimation;
public:
	AnimatedEntity();
	~AnimatedEntity();

	void AddAnimation(Animation* anim);
	void SetCurrentAnimation(Animation* anim);
	Animation* GetCurrentAnimation();
};

