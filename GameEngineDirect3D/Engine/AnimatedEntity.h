#ifndef ANIMATEDENTITY_H
#define ANIMATEDENTITY_H
#include "MeshRenderer.h"
#include<map>
#include "Animation.h"

class ENGINE_API AnimatedEntity :
	public MeshRenderer
{
private:
	std::map<std::string, Animation*> _animations;
	Animation* _currentAnimation;
	float _fps;
public:
	AnimatedEntity();
	~AnimatedEntity();

	virtual void UpdateComposite() = 0;

	void AddAnimation(Animation* anim);
	void SetCurrentAnimation(std::string anim, float fps);
	Animation* GetCurrentAnimation();
};

#endif
