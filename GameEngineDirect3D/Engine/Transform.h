#ifndef TRANSFORM_H
#define TRANSFORM_H

class ENGINE_API Transform
{
public:
	D3DXVECTOR3 position;
	D3DXVECTOR3 rotation;
	D3DXVECTOR3 scale;
	Transform();
	~Transform();
};

#endif