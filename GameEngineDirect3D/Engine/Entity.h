#ifndef ENTITY_H
#define ENTITY_H
#include "Game.h"
#include "Transform.h"
#include "Material.h"

class ENGINE_API Entity 
{
private:
	Material* _material;
	LPDIRECT3DDEVICE9 _dev;
	Transform _transform;
	bool _isVisible;
	
public:
	Entity();
	Entity(LPDIRECT3DDEVICE9 dev);
    ~Entity();

	virtual void Update() = 0;
	void Render();

	Material* GetMaterial();
	void SetMaterial(Material* m);

	void SetDevice(LPDIRECT3DDEVICE9 dev);
	LPDIRECT3DDEVICE9 GetDevice();

	Transform GetTransform();

	void SetChildModel(Entity* child);

	void SetPosition(float x, float y, float z);

	void MoveForward();
	void MoveRight();
	void MoveLeft();

	float GetForward();
	float GetUp();
	float GetRight();

	bool IsVisible() const;
	virtual std::string GetType() const=0;

};

#endif

