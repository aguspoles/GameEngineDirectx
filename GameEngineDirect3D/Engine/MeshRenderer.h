#ifndef ENTITY_H
#define ENTITY_H
#include "Transform.h"
#include "Material.h"
#include "Model.h"
#include "Composite.h"
#include "GameSetUp.h"
#include "Camera.h"
#include "Light.h"

class ENGINE_API MeshRenderer : public Composite
{
private:
	Transform* _transform;//lo tiene composite
	Material* _material;
	Model* _model;
	bool _isVisible;
public:
	MeshRenderer();
    ~MeshRenderer();

	virtual void Init() = 0;
	virtual void UpdateComposite() = 0;
	void RenderComposite() override;

	void SetModel(Model* model);
	bool IsVisible() const;
	virtual std::string GetType() const=0;

};

#endif

