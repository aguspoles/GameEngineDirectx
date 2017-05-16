#pragma once
#include "stdafx.h"
#include "..\Engine\Entity.h"

class Player : Entity
{
private:

public:
	Player();
	Player(LPDIRECT3DDEVICE9 dev, Model *m);
	~Player();


};

