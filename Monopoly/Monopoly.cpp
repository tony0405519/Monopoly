#include "Monopoly.h"

wstring Monopoly::musicFileName = L"";
wstring Monopoly::gameMapFileName = L"";
wstring Monopoly::settingFileName = L"";
wstring Monopoly::gameRecordFileName = L"";

Monopoly::Monopoly()
{
	monopolyInit();
}

Monopoly::~Monopoly()
{
}
void Monopoly::monopolyInit()
{
}




















// static function
// �]�w�y��
void Monopoly::setCursor(int x, int y)
{
	COORD point;
	point.X = x; point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

// �]�w�C��
void Monopoly::setColor(int f, int b)
{
	unsigned short ForeColor = f + 16 * b;
	HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hCon, ForeColor);
}

// ���o�ثe��Ц�m
void Monopoly::getCursor(int &x, int &y)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	x = csbi.dwCursorPosition.X;
	y = csbi.dwCursorPosition.Y;
}

// �]�w�y��visible
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