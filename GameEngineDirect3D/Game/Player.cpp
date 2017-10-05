#include "stdafx.h"
#include "Player.h"


Player::Player()
{
	_transform = GetComponent<Transform>(); 
	_transform->SetPosition(0, 0, 8);
}


Player::~Player()
{
}


void Player::UpdateComposite()
{
	static float num = 0;
	num += 0.01f;
	//WaterEffect();
	//MoveBackWard();
	Effect();
	Play("Run");
	//_transform->RotateMesh(D3DXVECTOR3(0, num, 0));
	if (Input::KeyPressed("MOVE_RIGHT"))
	{
		_transform->MoveRight(1 * Game::DeltaTime());
	}
	if (Input::KeyPressed("MOVE_LEFT"))
	{ 
		//GetCurrentAnimation()->Play();
		_transform->MoveLeft(1 * Game::DeltaTime());
	}
}

void Player::EnemyCollision(const std::vector<MeshRenderer*> &entities)
{

}

void Player::WaterEffect()
{
	if (_material)
	{
		static float num = 0;
		_material->RotateTexture(D3DXVECTOR3(0, 0, num));
		_material->Offset(D3DXVECTOR2(num, num));
		num += 0.01;
	}
}

void Player::Effect()
{
	static bool up = true, down = false;
	static float num = 0.5f;
	if (up)
	{
		if (num <= 0.8f)
			num += 0.01f;
		else
		{
			up = false;
			down = true;
		}
	}
	else if (down) {
		if (num >= 0.3f)
			num -= 0.01f;
		else {
			up = true;
			down = false;
		}
	}
	_material->GetShadderEffect()->SetFloat("num", num);
}

void Player::Init()
{
	_material = GetComponent<Material>();
	LPD3DXEFFECT shadder = _material->GetShadderEffect();
	shadder->SetVector("_Color", &D3DXVECTOR4(1.0f, 0.8f, 0, 0));
	//_material->AddBlending();
	//_material->AlphaBlending();
	//_material->MultiBlending();
}

std::string Player::GetType() const
{
	return "Player";
}