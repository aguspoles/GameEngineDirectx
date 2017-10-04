#ifndef FLOOR_H
#define FLOOR_H
#include "Tile.h"

class Floor :
	public Tile
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

