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

void AnimatedEntity::Play(std::string anim)
{
	if(_animations[anim])
		_animations[anim]->Play();
}

void AnimatedEntity::SetCurrentAnimation(std::string anim, float fps)
{
	if (_animations[anim])
	{
		_animations[anim]->SetSpeed(fps);
		_currentAnimation = _animations[anim];
	}
}

Animation * AnimatedEntity::GetCurrentAnimation()
{
	return _currentAnimation;
}
