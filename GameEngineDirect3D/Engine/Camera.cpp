#include "stdafx.h"
#include "Camera.h"


Camera::Camera()
{
}


Camera::~Camera()
{
}

D3DXMATRIX Camera::GetViewMatrix(D3DXVECTOR3 pos, D3DXVECTOR3 rot)
{
	D3DXVECTOR3 eye(0, 0, 0);
	D3DXVECTOR3 at(0, 0, 1);
	D3DXVECTOR3 up(0, 1, 0);
	D3DXMatrixLookAtLH(&_viewMatrix, &eye, &at, &up);
	//D3DXMATRIX a;
	//D3DXMatrixIdentity(&a);
	//a._41 = -pos.x;
	//a._42 = -pos.y;
	//a._43 = -pos.z;
	//D3DXMATRIX b;
	//D3DXMatrixIdentity(&b);
	//b._11 = cos(-rot.z);
	//b._12 = sin(-rot.z);
	//b._21 = -sin(-rot.z);
	//b._22 = cos(-rot.z);
	//_viewMatrix = a * b;
	return _viewMatrix;
}

void Camera::SetPerspective(FLOAT angle, FLOAT aspectRatio, FLOAT zMin, FLOAT zMax)
{
	D3DXMatrixPerspectiveFovLH(
		&_projectMatrix,
		D3DXToRadian(angle), //El angulo de apertura de la camara
		aspectRatio, //El ancho de la pantalla dividido el alto (relación de aspecto)
		zMin, //La distancia minima del objeto para verse
		zMax); //La distancia maxima del objeto para verse
}

D3DXMATRIX Camera::GetProjectMatrix()
{
	return _projectMatrix;
}

void Camera::SetRenderView(LPDIRECT3DDEVICE9 dev)
{
	dev->SetTransform(D3DTS_VIEW, &_viewMatrix);
	dev->SetTransform(D3DTS_PROJECTION, &_projectMatrix);
}
