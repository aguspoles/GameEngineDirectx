#pragma once
#include "Entity.h"
#include<map>
#include "Animation.h"

class ENGINE_API AnimatedEntity :
	public Entity
{
private:
	std::map<std::string, Animation*> _animations;
	Animation* _currentAnimation;
	float _fps;
public:
	AnimatedEntity();
	~AnimatedEntity();

	void AddAnimation(Animation* anim);
	void SetCurrentAnimation(std::string anim, float fps);
	Animation* GetCurrentAnimation();
};

