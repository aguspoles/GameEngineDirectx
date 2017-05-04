#pragma once
class Enemy
{
private:
	int locationX;
	int locationY;
	bool flag = true;
public:
	Enemy();
	~Enemy();


	Enemy(int x, int y);

	void Movement();

	int GetLocationX();
	int GetLocationY();
	void SetLocationX(int x);
	void SetLocationY(int y);
};

