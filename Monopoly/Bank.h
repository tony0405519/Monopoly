#pragma once
#include<string>
#include<vector>
#include"Player.h"
#include<algorithm>
using namespace std;
struct Stock;
struct StockRecord;
class Bank
{
public:
	Bank();
	~Bank();
	static vector<Stock> stockList;                   // 股票列表
	static vector<vector<StockRecord>> stockOwnerList;// 玩家持有股票

	int computePlayerStockAsset(Player & p1);        // 計算玩家股票資產
	int computePlayerAsset(Player & p1);             // 計算玩家總資產
	static void stockUpate();                         // 更新股票單價
	int buyStock(Player & player, vector<int>);   // vector存股票購買數量
	int soldStock(Player & player, vector<int>);
	
	double getInterestRate() { return interestRate; }
	double getLandingRate() { return landingRate; }

	void bankruptStock(int playerState); // 破產時，將股票清空

private:
	static void initialStock();			//用於初始化股票資訊
	double interestRate;
	double landingRate;
};

struct Stock                 // 存股票資料
{
	int stockId;
	int currentDollars;
	int previousDollars;
	wstring name;
};
struct StockRecord           // 存玩家所持有股票與對映張數
{
	int player_id;
	int stockId;
	int number;
};
//(1.0 +- rand() % 100 / 1000.0) * currentDollars;
	
