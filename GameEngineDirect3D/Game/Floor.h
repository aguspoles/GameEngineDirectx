#ifndef FLOOR_H
#define FLOOR_H
#include "MeshRenderer.h"

class Floor :
	public MeshRenderer
{
private:
	Transform* _transform;
	Material* _material;
public:
	Floor();
	~Floor();

	void Init();
	void UpdateComposite();

	std::string GetType() const;
};

#endif

