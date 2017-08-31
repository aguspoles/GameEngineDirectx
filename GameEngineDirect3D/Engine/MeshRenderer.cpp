#include "stdafx.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer() : _isVisible(true)
{
	_transform = new Transform();
	Add(_transform);
}

MeshRenderer::~MeshRenderer()
{
	delete _transform;
}

void MeshRenderer::Render()
{
	Material* mat = GetComponent<Material>();
	Model* model = GetComponent<Model>();
	if (mat)
	{
		auto tex = mat->GetComponent<Texture>();
		D3DXMATRIX* texMat = mat->GetTextureMatrix();
		tex->SetTexture(texMat);
		mat->SetBlend();
	}
	if (model)
	{
		//especificamos el formato del vertice
		GameSetUp::Device->SetFVF(CUSTOMFVF);
		GameSetUp::Device->SetTransform(D3DTS_WORLD, _transform->GetModelMatrix());
		//especificamos cual vb vamos a usar
		GameSetUp::Device->SetStreamSource(0, model->GetVertexBuffer(), 0, sizeof(Vertex));
		//especificamos q indices vamos  a usar
		GameSetUp::Device->SetIndices(model->GetIndexBuffer());
		//esto apga el culling de la placa 
		//_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		GameSetUp::Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
			(model->GetVertexes()).size(), 0, model->GetPrimitivesCount());
		//lo apago para que lo proximo que se dibuje no tenga blend necesariamente
		GameSetUp::Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
	}
}

bool MeshRenderer::IsVisible() const
{
	return _isVisible;
}
