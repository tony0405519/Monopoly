﻿#include "Monopoly.h"

wstring Monopoly::musicFileName;
wstring Monopoly::gameMapFileName;
wstring Monopoly::settingFileName;
wstring Monopoly::gameRecordFileName;
GameWorld Monopoly::gameWorld;
FileReader Monopoly::fileReader;

Monopoly::Monopoly()
{
	srand(time(NULL));
	setCursorSize(false, 0);
	monopolyInit();
	GameWorld::getChanceList();
	GameWorld::getDestinyList();
}

Monopoly::~Monopoly()
{
}
void Monopoly::monopolyInit()
{
	musicFileName = L"";
	gameMapFileName = L"basemap.txt";
	settingFileName = L"";
	gameRecordFileName = L"";
	mode = 0;
}

// 主選單Loop
void Monopoly::monopolyLoop()
{
	system("CLS");
	/*mode = 0;
	monopolyInit();
	fileReader.readAndSetData();
	while (mode != 3)
	{
		if (mode == 0)
		{
			gameWorld.gameStart();
		}
		else if (mode == 1)
		{
			// Setting code
		}
		else if (mode == 2)
		{
			// Detail code
		}
	}*/
	
	// Step1 : 印初始動畫
	if (isFirstStart) {
		printArt();
	}
	// Step2 : 印選單
	wstring title = L"";
	printBoard(boardX, boardY);
	isFirstStart = false;
	// Step3 : 讓玩家選擇

	while (true) {
		if (_kbhit())
		{
			int ch = _getch();
			// 按下Enter鍵後
			if (ch == '\r')
			{
				setCursorSize(true, 0); // 歸還游標
				if (mode == 0)
				{
					// 玩家人數選單
					clearFrame();
					gameWorld.gameStart(/*playerAmount*/); // 進入遊戲，打算傳入遊玩人數
				}
				else if (mode == 1)
				{
					// Continue，進入選單(another loop)
					bool success = fileReader.getFilename("continue");
					if (success == false)
					{
						continue;
					}
					fileReader.readAndSetData();   // 讀取遊戲
					clearFrame();
					gameWorld.gameStart();
				}
				else if (mode == 2)
				{
					// Rule，規則畫面
				}
				else if (mode == 3) {
					// Setting，設定選單(another loop)
				}
				else if (mode == 4) {
					// Exit，break
					break;
				}
				clearFrame();
				printArt();
				printBoard(boardX, boardY);
			}
			// 按下方向鍵後
			else if (ch == 224)
			{
				ch = _getch();
				switch (ch)
				{
				case 72: // 上
					if (mode == 0) mode = 4;
					else mode--;
					break;
				case 80: // 下
					if (mode == 4) mode = 0;
					else mode++;
					break;
				};
				printWord(wordX, wordY, wordWidth, wordHeight); // 更新已選取選項位置
			}
		}
	}
}

void Monopoly::printFrame(int xpos, int ypos, int xsize, int ysize, wstring title) {
	setColor();
	wstring upper;
	wstring lower(xsize - 2, L'＝');
	wstring side(xsize - 2, L'　');
	lower = L"●" + lower;
	lower.push_back(L'●');
	side = L"∥" + side;
	side.push_back(L'∥');
	if (int(title.size()) != 0)
	{
		int leftspace = (xsize - int(title.size()) - 2) / 2;
		int rightspace = xsize - int(title.size()) - 2 - leftspace;
		upper = title;
		upper = wstring(leftspace, L'＝') + upper + wstring(rightspace, L'＝');
		upper.insert(0, 1, L'●');
		upper.push_back(L'●');
	}
	else
	{
		upper = lower;
	}

	for (int i = 0; i < ysize; i++)
	{
		setCursor(xpos, ypos + i);
		if (i == 0)
		{
			wcout << upper;
		}
		else if (i == ysize - 1)
		{
			wcout << lower;
		}
		else
		{
			wcout << side;
		}
	}
}


void Monopoly::printBoard(int xpos, int ypos) {
	setCursorSize(false, 0);
	setColor(9, 0);
	for (int i = 0; i < boardHeight; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < boardWidth; j++) {
			if (i == 0 || i == boardHeight - 1 || i % 6 == 0) // 上
			{
				if (j == 0) wcout << L"●";// 左上角
				else if (j == boardWidth - 1) wcout << L"●";// 右上角
				else wcout << L"＝";// 上方
			}
			else// 中
			{
				if (j == 0 || j == boardWidth - 1) wcout << L"∥";// 中間
				else wcout << L"　"; // 
			}
		}
	}
	setColor();
	wordX = boardX + 2; // 減邊框
	wordY = boardY + 1; // 減邊框
	wordWidth = boardWidth - 2; // 減邊框長度
	wordHeight = (boardHeight - (modeAmount + 1)) / modeAmount; // 算出單格長度
	printWord(wordX, wordY, wordWidth, wordHeight);
}

// 印出主選單選項
void Monopoly::printWord(int xpos, int ypos, int width, int height) {
	
	setColor();

	
	if (mode == 0) setColor(0, 15);
	else setColor();
	for (int i = 0; i < height; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < width; j++) {
			wcout << L"　";
		}
	}
	Monopoly::setCursor(xpos + 12, ypos + 2);
	wcout << L"開始遊戲";



	
	if (mode == 1) Monopoly::setColor(0, 15);
	else setColor();
	ypos += 6;
	for (int i = 0; i < height; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < width; j++) {
			wcout << L"　";
		}
	}
	ypos -= 6;
	Monopoly::setCursor(xpos + 12, ypos + 8);
	wcout << L"繼續遊戲";

	
	if (mode == 2) setColor(0, 15);
	else setColor();
	ypos += 12;
	for (int i = 0; i < height; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < width; j++) {
			wcout << L"　";
		}
	}
	ypos -= 12;
	Monopoly::setCursor(xpos + 12, ypos + 14);
	wcout << L"規則說明";

	
	if (mode == 3) setColor(0, 15);
	else setColor();
	ypos += 18;
	for (int i = 0; i < height; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < width; j++) {
			wcout << L"　";
		}
	}
	ypos -= 18;
	Monopoly::setCursor(xpos + 12, ypos + 20);
	wcout << L"遊戲設定";

	
	if (mode == 4) setColor(0, 15);
	else setColor();
	ypos += 24;
	for (int i = 0; i < height; i++) {
		setCursor(xpos, ypos + i);
		for (int j = 0; j < width; j++) {
			wcout << L"　";
		}
	}
	ypos -= 24;
	Monopoly::setCursor(xpos + 12, ypos + 26);
	wcout << L"離開遊戲";

	setColor();

}

// 印出開頭背景
void Monopoly::printArt() {
	fstream inputMonopoly("art/monopoly.txt", ios::in);
	fstream inputMoney("art/fadatsai.txt", ios::in);
	setCursorSize(false, 0);

	string line;
	int yPos = 3;

	setColor(6, 0);
	while (getline(inputMonopoly, line)) {
		setCursor(3, yPos);
		cout << line << endl;
		yPos++;
	}


	yPos = 3;
	setColor(6, 0);
	while (getline(inputMoney, line)) {
		setCursor(3, yPos);
		cout << line << endl;
		yPos++;
	}

	inputMonopoly.close();
	inputMoney.close();
	setColor();
}

// 印出開頭背景，有特效
void Monopoly::printArtSleep() {
	fstream inputMonopoly("art/monopoly.txt", ios::in);
	fstream inputMoney("art/fadatsai.txt", ios::in);
	setCursorSize(false, 0);

	string line;
	int yPos = 3;

	setColor(6, 0);
	while (getline(inputMonopoly, line)) {
		setCursor(3, yPos);
		cout << line << endl;
		yPos++;
		Sleep(100);
	}


	yPos = 3;
	setColor(6, 0);
	while (getline(inputMoney, line)) {
		setCursor(3, yPos);
		cout << line << endl;
		yPos++;
		Sleep(100);
	}

	inputMonopoly.close();
	inputMoney.close();
	setColor();
}

// 清空畫面
void Monopoly::clearFrame() {
	setColor();
	for (int i = 0; i < 49; i++) {
		setCursor(0, i);
		for (int j = 0; j < 188; j++) {
			wcout << L"　";
		}
	}

}


// Console介面的helper function

// 設定顏色
void Monopoly::setColor(int f, int b)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}

// 設定座標
void Monopoly::setCursor(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// 取得目前游標位置
void Monopoly::getCursor(int &x, int &y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	x = csbi.dwCursorPosition.X;
	y = csbi.dwCursorPosition.Y;
}

// 設定座標visible
void Monopoly::setCursorSize(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}