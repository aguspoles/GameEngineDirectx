#ifndef CAMERA_H
#define CAMERA_H

class ENGINE_API Camera
{
private:
	D3DXMATRIX _viewMatrix;
	D3DXMATRIX _projectMatrix;
public:
	Camera();
	~Camera();

	D3DXMATRIX GetViewMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot);
	void SetPerspective(FLOAT angle, FLOAT aspectRatio, FLOAT zMin, FLOAT zMax);
	D3DXMATRIX GetProjectMatrix();
	void SetRenderView(LPDIRECT3DDEVICE9 dev);
};

#endif