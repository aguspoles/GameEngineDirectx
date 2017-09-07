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
	Material* material = GetComponent<Material>();
	Model* model = GetComponent<Model>();
	if (model)
	{
		//especificamos el formato del vertice
		GameSetUp::Device->SetFVF(CUSTOMFVF);
		//especificamos cual vb vamos a usar
		GameSetUp::Device->SetStreamSource(0, model->GetVertexBuffer(), 0, sizeof(Vertex));
		//especificamos q indices vamos  a usar
		GameSetUp::Device->SetIndices(model->GetIndexBuffer());
		//esto apga el culling de la placa 
		//_dev->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		if (material)
		{
			Texture* texture = material->GetComponent<Texture>();
			D3DXMATRIX* texMatrix = material->GetTextureMatrix();
			texture->SetTexture(texMatrix);
			material->SetBlend();

			if (material->GetShadderEffect())
			{
				UINT passes;
				material->GetShadderEffect()->Begin(&passes, 0);
				material->GetShadderEffect()->BeginPass(0);
				GameSetUp::Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
					(model->GetVertexes()).size(), 0, model->GetPrimitivesCount());
				material->GetShadderEffect()->EndPass();
				material->GetShadderEffect()->End();
			}
			else
			{
				GameSetUp::Device->SetTransform(D3DTS_WORLD, _transform->GetModelMatrix());
				GameSetUp::Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
					(model->GetVertexes()).size(), 0, model->GetPrimitivesCount());
			}

            //lo apago para que lo proximo que se dibuje no tenga blend necesariamente
			GameSetUp::Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		}
	}
}

bool MeshRenderer::IsVisible() const
{
	return _isVisible;
}
