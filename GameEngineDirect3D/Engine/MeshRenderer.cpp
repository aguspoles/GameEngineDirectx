#include "stdafx.h"
#include "MeshRenderer.h"

//recursive model matrix
D3DXMATRIX MeshRenderer::ModelMatrix(D3DXMATRIX childModelMatrix)
{
	if (GetParent())
	{
		D3DXMATRIX parentMatrix = *(GetParent()->GetComponent<Transform>()->GetModelMatrix());
		D3DXMATRIX newModelMatrix = parentMatrix * childModelMatrix;
		ModelMatrix(newModelMatrix);
	}
	else return childModelMatrix;
}

MeshRenderer::MeshRenderer() : _isVisible(true)
{
	_transform = new Transform();
	Add(_transform);
}

MeshRenderer::~MeshRenderer()
{
	delete _transform;
}

void MeshRenderer::RenderComposite()
{
	Composite* parent = GetParent();
	if (parent)
	{
		RenderComposite(*(parent->GetComponent<Transform>()->GetModelMatrix()));
	}
}

void MeshRenderer::RenderComposite(D3DXMATRIX parentModelMatrix)
{
	_transform->SetModelMatrix(parentModelMatrix * *_transform->GetModelMatrix());
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
		GameSetUp::Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
		GameSetUp::Device->SetRenderState(D3DRS_ZWRITEENABLE, true);
		GameSetUp::Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
		if (material)
		{

			Texture* texture = material->GetComponent<Texture>();
			D3DXMATRIX* texMatrix = material->GetTextureMatrix();
			texture->SetTexture(texMatrix);
			material->SetBlend();

			if (material->GetShadderEffect())
			{
				D3DXMATRIX mvp = *_transform->GetModelMatrix() * GameSetUp::GetCamera()->GetViewMatrix() * GameSetUp::GetCamera()->GetProjectMatrix();
				material->GetShadderEffect()->SetMatrix("mvp", &mvp);
				material->GetShadderEffect()->SetVector("_Color", &D3DXVECTOR4(1, 0.5f, 0.5f, 0));
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
