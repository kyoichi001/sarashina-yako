#pragma once

class Point;
class Circle;
class Rect;

#define BLEND_NONE 0
#define BLEND_ALPHA 1
#define BLEND_ADD 2
#define BLEND_SUB 3
#define BLEND_MUL 4

#define MASKTRANS_WHITE							(0)				// マスク画像の白い部分を透過色とする
#define MASKTRANS_BLACK							(1)				// マスク画像の黒い部分を透過色とする
#define MASKTRANS_NONE							(2) 			// 透過色なし

namespace DxWrp {

	void InitBlend()noexcept;
	void SetBlendModeAlpha(int Value)noexcept;
	void ResetBlendMode()noexcept;
	void ResetBlendModeAdd()noexcept;

	int LoadGraph(const char* file)noexcept;
	int LoadDivGraph(const char* file, int AllNum, int XNum, int YNum, int XSize, int YSize, int* Hdl)noexcept;

	void DeleteGraph(int handle)noexcept;

	void SetDrawBlendMode(int State, int Value)noexcept;
	void SetDrawBright(int R, int G, int B)noexcept;

	void DrawGraph(int x, int y, int Hdl)noexcept;
	void DrawGraph(const Point& P, int Hdl)noexcept;
	void DrawRotaGraph(int x, int y, float ExRate, float Angle, int Hdl)noexcept;
	void DrawRotaGraph(const Point& P, float ExRate, float Angle, int Hdl)noexcept;

	void DrawModiGraph(const Point& begin, const Point& end, float width, int Hdl)noexcept;

	void DrawCircle(int x, int y, int r, int color, bool fillflag = true, int Thickness = 1)noexcept;
	void DrawCircle(const Point& P, int r, int color, bool fillflag = true, int Thickness = 1)noexcept;
	void DrawLine(int x, int y, int x2, int y2, int color, int Thickness = 1)noexcept;
	void DrawLine(const Point& P1, const Point& P2, int color, int Thickness = 1)noexcept;
	void DrawBox(int x, int y, int x2, int y2, int color, bool fillflag = true)noexcept;
	void DrawBox(const Point& P1, const Point& P2, int color, bool fillflag = true)noexcept;
	void DrawBox(const Point& P1,int height,int width, int color, bool fillflag = true)noexcept;

	//画像をループさせる
	//TimeとXSpeed,YSpeedに応じて画像が動く
	void DrawLoopPic(int Hdl, int X1, int Y1, int X2, int Y2, int XOfs, int YOfs,int XSize,int YSize)noexcept;

	void DrawStringToHandle(int X, int Y, const char* c, int Color, int Font, unsigned EdgeColor = 0)noexcept;
	void DrawStringToHandle(const Point& P, const char* c, int Color, int Font, unsigned EdgeColor = 0)noexcept;
	void DrawFormatString(int x, int y, int color, const char* c, int Param)noexcept;
	void DrawFormatString(const Point& P, int color, const char* c, int Param)noexcept;
	void DrawFormatString(int x, int y, int color, const char* c, float Param)noexcept;
	void DrawFormatString(const Point& P, int color, const char* c, float Param)noexcept;
	void DrawFormatStringToHandle(int x, int y, int color, int Font, const char* c, int Param)noexcept;
	void DrawFormatStringToHandle(const Point& P, int color, int Font, const char* c, int Param)noexcept;
	void DrawFormatStringToHandle(int x, int y, int color, int Font, const char* c, float Param)noexcept;
	void DrawFormatStringToHandle(const Point& P, int color, int Font, const char* c, float Param)noexcept;

	int GetDrawStringWidthToHandle(const char* string, int strlen, int font);
	int GetFontSize(int font);

	void CreateMaskScreen();
	void DeleteMaskScreen();
	int LoadMask(const char* str);
	void DeleteMask(int Hdl);
	void DrawMask(int x, int y, int Hdl, int TransMode= MASKTRANS_WHITE);
	void SetUseMaskScreenFlag(bool flag);

}