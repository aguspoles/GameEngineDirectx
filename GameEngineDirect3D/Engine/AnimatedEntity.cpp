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
	_animations[anim->GetName()] = anim;
}

void AnimatedEntity::SetCurrentAnimation(std::string anim, float fps)
{
	_animations[anim]->SetSpeed(fps);
	_currentAnimation = _animations[anim];
}

Animation * AnimatedEntity::GetCurrentAnimation()
{
	return _currentAnimation;
}
