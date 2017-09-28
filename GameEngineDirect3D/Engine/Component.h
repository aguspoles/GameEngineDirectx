#pragma once

class ENGINE_API Component
{
	class Composite* parent;
private:
	D3DXMATRIX _modelMatrix;
protected:
	float x;
	float y;

public:

	Component();
	~Component();

	virtual void Update();
	virtual void Render();
	virtual void Render(D3DXMATRIX modelMatrix);
	void Move(float, float);
	void SetParent(Composite* parent);
	Composite* GetParent();
	void SetModelMatrix(D3DXMATRIX modelMatrix);
};