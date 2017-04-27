#include "stdafx.h"
#include "Player.h"


Player::Player(LPDIRECT3DDEVICE9 dev)
{
	Vertex vertexes[] =
	{
		//rectangulo superior
		{ 100.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(50,50,0) },
		{ 540.0f, 0.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,100,0) },
		{ 100.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(50,0,100) },
		{ 540.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
		//rectangulo inferior
		{ 270.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,0,0) },
		{ 370.0f, 100.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,255,0) },
		{ 270.0f, 480.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(255,255,0) },
		{ 370.0f, 480.0f, 0.0f, 1.0f, D3DCOLOR_XRGB(0,0,255) },
	};

	WORD indexes[] =
	{
		0,3,2,0,1,3, 4,5,6,6,5,7
	};

	dev->CreateVertexBuffer(8 * sizeof(Vertex),
		D3DUSAGE_WRITEONLY,//el uso q le vamos a dar
		CUSTOMFVF,
		D3DPOOL_MANAGED,//lo subimos a vram
		&vb,
		NULL);

	
	dev->CreateIndexBuffer(
		12 * sizeof(WORD),
		D3DUSAGE_WRITEONLY,
		D3DFMT_INDEX16,
		D3DPOOL_MANAGED,
		&ib,
		NULL
		);

	VOID *data;
	vb->Lock(0, 0, &data, 0);
	memcpy(data, vertexes, 8 * sizeof(Vertex));
	vb->Unlock();

	ib->Lock(0, 0, &data, 0);
	memcpy(data, indexes, 12 * sizeof(WORD));
	ib->Unlock();
}


Player::~Player()
{
}

void Player::Render(LPDIRECT3DDEVICE9 dev) {
	dev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_ARGB(0, 50, 70, 100), 1.0f, 0);
	
	dev->BeginScene();

	dev->SetFVF(CUSTOMFVF);

	dev->SetStreamSource(0, vb, 0, sizeof(Vertex));

	dev->SetIndices(ib);

	dev->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 4);
	dev->EndScene();
	dev->Present(NULL, NULL, NULL, NULL);
}

void Player::Clean() {
	ib->Release();
	vb->Release();
}
