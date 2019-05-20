#pragma once
#include "Player.h"
#include"Bank.h"
struct RealEstate;
class GameWorld
{
public:
	GameWorld();
	~GameWorld();
	void gmaeStart();


	static vector<Player> playerList;
	static Bank bank;               // PlayerId = -1
	static vector<RealEstate> gameMap;
	static int playerState;         // �ثe�ۨ���Ӫ��a
	int round;                      // �ĴX�^�X
	// StockDepartment   Stock

};

struct RealEstate
{
	RealEstate()
	{
		playerPosition = "0000";  // �H0/1�r����ܪ��a�O�_�b���a
		ownerId = -1;             // ���@�O�Ȧ檺
		level = 0;
	}
	int type;          // ���� 1�a��, -1 ���|
	int position;      // 0~27
	int ownerId;       // Player1
	wstring name;      // �a���W��
	int buyCost;       // �g�a����
	vector<int> tolls; // �L���O(�@�ߵ��{��)
	int level;         // �������� 0 ~ 3
	string playerPosition;
	int mortgageRealEstate()
	{
		ownerId = -1;
		level = 0;
		double rate = 0.75;
		int returnVal = buyCost;
		for (int i = 0; i < level; i++)
		{
			returnVal += buyCost * rate;
			rate += 0.25;
		}
		return returnVal * 0.8;
	}
};