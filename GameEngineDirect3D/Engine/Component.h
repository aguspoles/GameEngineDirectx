#pragma once

class ENGINE_API Component
{
	class Composite* parent;
protected:
	float x;
	float y;

public:

	Component();
	~Component();

	virtual void Update();
	virtual void Render();
	void Move(float, float);
	void SetParent(Composite* parent);
	Composite* GetParent();
};