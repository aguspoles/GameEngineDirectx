#include "stdafx.h"
#include "MeshRenderer.h"

MeshRenderer::MeshRenderer() : _isVisible(true)
{
	_transform = GetComponent<Transform>();
}

MeshRenderer::~MeshRenderer()
{
}

void MeshRenderer::RenderComposite()
{
	_material = GetComponent<Material>();
	if (_model)
	{
		//especificamos el formato del vertice
		GameSetUp::Device->SetFVF(CUSTOMFVF);
		//especificamos cual vb vamos a usar
		GameSetUp::Device->SetStreamSource(0, _model->GetVertexBuffer(), 0, sizeof(Vertex));
		//especificamos q indices vamos  a usar
		GameSetUp::Device->SetIndices(_model->GetIndexBuffer());
		//esto apga el culling de la placa 
		//GameSetUp::Device->SetRenderState(D3DRS_CULLMODE, D3DCULL_NONE);
		GameSetUp::Device->SetRenderState(D3DRS_ZENABLE, D3DZB_TRUE);
		GameSetUp::Device->SetRenderState(D3DRS_ZWRITEENABLE, true);
		GameSetUp::Device->SetRenderState(D3DRS_ZFUNC, D3DCMP_LESS);
		if (_material)
		{
			Texture* texture = _material->GetTexture();
			D3DXMATRIX* texMatrix = _material->GetTextureMatrix();
			texture->SetTexture(texMatrix);
			_material->SetBlend();

	        D3DXMATRIX* modelMatrix = _transform->GetModelMatrix();
	        D3DXMATRIX* rot = _transform->GetRotateMeshMatrix();
			LPD3DXEFFECT shadder = _material->GetShadderEffect();
			if (shadder)
			{
				D3DXMATRIX mvp = *modelMatrix * 
					Camera::Instance()->GetViewMatrix() * 
					Camera::Instance()->GetProjectMatrix();
				shadder->SetMatrix("mvp", &mvp);
				shadder->SetMatrix("rotMat", rot);
				shadder->SetMatrix("texMatrix", texMatrix);
				shadder->SetTexture("tex", texture->GetTexture());
				shadder->SetVector("lightDir", &Light::GetLightDirection());
				shadder->SetVector("lightCol", &Light::GetLightColor());
				shadder->SetVector("ambientCol", &Light::GetLightAmbientColor());
				UINT passes;
				shadder->Begin(&passes, 0);
				shadder->BeginPass(0);
				GameSetUp::Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
					(_model->GetVertexes()).size(), 0, _model->GetPrimitivesCount());
				shadder->EndPass();
				shadder->End();
			}
			else
			{
				GameSetUp::Device->SetTransform(D3DTS_WORLD, modelMatrix);
				GameSetUp::Device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0,
					(_model->GetVertexes()).size(), 0, _model->GetPrimitivesCount());
			}
			//lo apago para que lo proximo que se dibuje no tenga blend necesariamente
			GameSetUp::Device->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
		}
	}
}

void MeshRenderer::SetModel(Model * model)
{
	_model = model;
}

bool MeshRenderer::IsVisible() const
{
	return _isVisible;
}
