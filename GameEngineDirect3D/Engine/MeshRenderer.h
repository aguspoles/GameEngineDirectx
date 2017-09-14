#ifndef ENTITY_H
#define ENTITY_H
#include "Transform.h"
#include "Material.h"
#include "Model.h"
#include "Composite.h"
#include "GameSetUp.h"


class ENGINE_API MeshRenderer : public Composite
{
private:
	Transform* _transform;
	bool _isVisible;
public:
	MeshRenderer();
    ~MeshRenderer();

	virtual void Init() = 0;
	virtual void UpdateComposite() = 0;
	void Render();
	void Render(D3DXMATRIX modelMatrix);

	bool IsVisible() const;
	virtual std::string GetType() const=0;

};

#endif

