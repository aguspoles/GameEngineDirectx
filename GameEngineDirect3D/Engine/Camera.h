#ifndef CAMERA_H
#define CAMERA_H
#include "Component.h"
#include "GameSetUp.h"

class ENGINE_API Camera : public Component
{
private:
	D3DXMATRIX _viewMatrix;
	D3DXMATRIX _projectMatrix;
public:
	Camera();
	~Camera();

	D3DXMATRIX SetViewMatrix(D3DXVECTOR3 eye, D3DXVECTOR3 at, D3DXVECTOR3 up);
	void SetPerspective(FLOAT angle, FLOAT aspectRatio, FLOAT zMin, FLOAT zMax);
	D3DXMATRIX GetProjectMatrix();
	D3DXMATRIX GetViewMatrix();
	void SetRenderView();
};

#endif