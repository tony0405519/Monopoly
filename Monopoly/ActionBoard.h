﻿#pragma once

#include<iomanip>
#include<iostream>
#include<vector>
#include<string>


using namespace std;
class ActionBoard
{
public:
	ActionBoard();
	const int startX = 100;
	const int startY = 0;
	const int width = 28;
	const int length = 33;

	int getMenuOption();

	void printFrame(int xpos, int ypos, int xsize, int ysize, wstring title = L"");  // 印出actionBoard的框框
	void printFrame();
	void printMenu(int selectedIndex);
	
	void printStock();             // 印出股票版
	vector<int> printBuyStock();   // 印出股票購買介面
	vector<int> printSellStock();   // 印出股票賣出介面
	void printPlayerInfo();        // 印出玩家資訊
	void printChance(int index);	// 印出機會
	void printDestiny(int index);	// 印出命運
	int printWithdrawDeposit(bool isWithdraw);    // 印出存款提款介面

	// ===============================================
	// 骰子階段的動畫、提示視窗
	// ===============================================
	void stopRoundAnim(wstring = L"因暫停回合無法移動", wstring = L"輪到下一家"); // 無法移動提示
	int assignDiceNumber(); // 是否要用遙控骰子提示 // 0：不使用／1-6：使用
	void printAssignDiceWord(int cursorX, int cursorY, int mode, int diceNumber); // helper function
	void moneyInefficientAnim(int mode); // 現金不足提示
	bool buyOrNot(int landMode, wstring subTitle); // 購置/升級房產選單
	void printBuyOrNotWord(int cursorX, int cursorY, bool mode, int landMode, wstring subTitle); // helper function
	// ===============================================
	vector<int> sellRealEstate();
	
	~ActionBoard();

private:
	const vector<wstring>& getActionList();

	// ============================================
	// 玩家資訊的板子
	// ============================================
	void choosePlayerInfo(int infoMode, int playerId, int indexY, int lineHeight, int indexX); // 三選一的code
	void printPlayerInfoMain(int playerId, int indexY, int lineHeight); // 玩家一般資訊(含標頭、尾)
	void printPlayerInfoStock(int playerId, int indexY, int lineHeight, int indexX);// 玩家股票資訊(含標頭、尾)
	void printPlayerInfoHouse(int playerId, int indexY, int lineHeight, int indexX);// 玩家房產資訊(含標頭、尾)
	// ============================================
	// 付不起過路費後賣房產

	void printRealEstate(vector<int>, int, vector<bool>);
	// ============================================
	// 印出一種股票名稱及購買數量
	// ============================================
	void printBuyStockNumber(int stockId, int number, int x, int y, bool light);
	void printTotalStock(vector<int> & ref,int x, int y);
	// ============================================


	void headerTip(wstring); // 標頭
	void tailTip(wstring = L"←　Ｅｎｔｅｒ　→"); // 頁尾
	void pressEnterKeyToContinue();
	void pressAnyKeyToContinue();
};