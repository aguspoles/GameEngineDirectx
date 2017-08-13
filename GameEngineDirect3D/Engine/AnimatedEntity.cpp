#include "stdafx.h"
#include "AnimatedEntity.h"


AnimatedEntity::AnimatedEntity()
{
}


AnimatedEntity::~AnimatedEntity()
{
}

void AnimatedEntity::AddAnimation(Animation * anim)
{
	_animations.push_back(anim);
}

void AnimatedEntity::SetCurrentAnimation(Animation * anim)
{
	_currentAnimation = anim;
}

Animation * AnimatedEntity::GetCurrentAnimation()
{
	return _currentAnimation;
}
