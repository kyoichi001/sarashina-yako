
#include "Renderer.h"
#include "DxLib.h"
#include "Primitive\Primitive.h"

namespace DxWrp {


	void InitBlend()noexcept {
	}

	void SetBlendModeAlpha(int Value)noexcept {
		DxWrp::SetDrawBlendMode(BLEND_ALPHA, Value);
	}

	void ResetBlendMode()noexcept {
		DxWrp::SetDrawBlendMode(0, 0);
	}

	void ResetBlendModeAdd()noexcept {
		DxWrp::SetDrawBlendMode(0, 0);
	}

	int LoadGraph(const char*  file)noexcept { return DxLib::LoadGraph(file); }
	int LoadDivGraph(const char* file, int AllNum, int XNum, int YNum, int XSize, int YSize, int* Hdl)noexcept { return  DxLib::LoadDivGraph(file, AllNum, XNum, YNum, XSize, YSize, Hdl); }
	void DeleteGraph(int handle)noexcept { DxLib::DeleteGraph(handle); }

	void SetDrawBlendMode(int State, int Value)noexcept { DxLib::SetDrawBlendMode(State, Value); }
	void SetDrawBright(int R, int G, int B) noexcept { DxLib::SetDrawBright(R, G, B); }

	void DrawGraph(int x, int y, int Hdl)noexcept { DxLib::DrawGraph(x, y, Hdl, TRUE); }
	void DrawGraph(const Point& P, int Hdl)noexcept { DxLib::DrawGraph(P.x, P.y, Hdl, TRUE); }
	void DrawRotaGraph(int x, int y, float ExRate, float Angle, int Hdl)noexcept { DrawRotaGraphFast(x, y, ExRate, Angle, Hdl, TRUE); }
	void DrawRotaGraph(const Point& P, float ExRate, float Angle, int Hdl)noexcept { DrawRotaGraphFast(P.x, P.y, ExRate, Angle, Hdl, TRUE); }
	void DrawModiGraph(const Point& begin, const Point& end, float width, int Hdl)noexcept {
		Vec2 l{ -(end.y - begin.y),end.x - begin.x };
		l.SetLength(width);
		const Point tl = begin - l, tr = begin + l ,bl = end - l , br = end + l ;
		DxLib::DrawModiGraph(tl.x, tl.y, tr.x, tr.y, br.x, br.y, bl.x, bl.y,  Hdl, TRUE);
	}

	void DrawCircle(int x, int y, int r, int color, bool fillflag, int Thickness)noexcept { DxLib::DrawCircle(x, y, r, color, fillflag, Thickness); }
	void DrawCircle(const Point& P, int r, int color, bool fillflag, int Thickness)noexcept { DxLib::DrawCircle(P.x, P.y, r, color, fillflag, Thickness); }
	void DrawLine(int x, int y, int x2, int y2, int color, int Thickness)noexcept { DxLib::DrawLine(x, y, x2, y2, color, Thickness); }
	void DrawLine(const Point& P1, const Point& P2, int color, int Thickness)noexcept { DxLib::DrawLine(P1.x, P1.y, P2.x, P2.y, color, Thickness); }
	void DrawBox(int x, int y, int x2, int y2, int color, bool fillflag)noexcept { DxLib::DrawBox(x, y, x2, y2, color, fillflag); }
	void DrawBox(const Point& P1, const Point& P2, int color, bool fillflag)noexcept { DxLib::DrawBox(P1.x, P1.y, P2.x, P2.y, color, fillflag); }
	void DrawBox(const Point& P1, int height, int width, int color, bool fillflag )noexcept{ DxLib::DrawBox(P1.x, P1.y, P1.x+width, P1.y+height, color, fillflag); }

	void DrawLoopPic(int Hdl, int X1, int Y1, int X2, int Y2, int XOfs,int YOfs, int XSize, int YSize)noexcept {
		int forX = (X2 - X1) / XSize;
		int forY = (Y2 - Y1) / YSize;
		for (int i = -1; i < forX + 1; ++i) {
			for (int j = -1; j < forY + 1; ++j) {
				DxWrp::DrawGraph(X1 + i* XSize + (XOfs % XSize), Y1 + j* YSize + (YOfs % YSize), Hdl);
			}
		}
		//DxLib::DrawTile(X1, Y1, X2, Y2, XSpeed, YSpeed, 1.0f, 0.0f, Handle, true);
	}

	void DrawStringToHandle(int X, int Y, const char* c, int Color, int Font, unsigned EdgeColor)noexcept { DxLib::DrawStringToHandle(X, Y, c, Color, Font, EdgeColor); }
	void DrawStringToHandle(const Point& P, const char* c, int Color, int Font, unsigned EdgeColor)noexcept { DxLib::DrawStringFToHandle(P.x, P.y, c, Color, Font, EdgeColor); }

	void DrawFormatString(int x, int y, int color, const char* c, int Param)noexcept { DxLib::DrawFormatString(x, y, color, c, Param); }
	void DrawFormatString(const Point& P, int color, const char* c, int Param)noexcept { DxLib::DrawFormatString(P.x, P.y, color, c, Param); }
	void DrawFormatString(int x, int y, int color, const char* c, float Param)noexcept { DxLib::DrawFormatString(x, y, color, c, Param); }
	void DrawFormatString(const Point& P, int color, const char* c, float Param)noexcept { DxLib::DrawFormatString(P.x, P.y, color, c, Param); }
	void DrawFormatStringToHandle(int x, int y, int color, int Font, const char* c, int Param)noexcept { DxLib::DrawFormatStringToHandle(x, y, color, Font, c, Param); }
	void DrawFormatStringToHandle(const Point& P, int color, int Font, const char* c, int Param)noexcept { DxLib::DrawFormatStringToHandle(P.x, P.y, color, Font, c, Param); }
	void DrawFormatStringToHandle(int x, int y, int color, int Font, const char* c, float Param)noexcept { DxLib::DrawFormatStringToHandle(x, y, color, Font, c, Param); }
	void DrawFormatStringToHandle(const Point& P, int color, int Font, const char* c, float Param)noexcept { DxLib::DrawFormatStringToHandle(P.x, P.y, color, Font, c, Param); }
	
	int GetDrawStringWidthToHandle(const char* string, int strlen, int font) { return DxLib::GetDrawStringWidthToHandle(string,strlen,font); }
	int GetFontSize(int font) {return  DxLib::GetFontSizeToHandle(font); }

	/*void DrawFormatStringToHandle(int x, int y, int color, int font, std::string str, ...){ DxLib::DrawFormatStringToHandle(x, y, color, font, str.c_str(), ...); }
	void DrawFormatStringToHandle(const Point& P, int color, int font, std::string str, ...){ DxLib::DrawFormatStringToHandle(P.x, P.y, color, font, str.c_str(), ...); }
	void DrawFormatString(const Point& P, int color, std::string str, ...){ DxLib::DrawFormatString(P.x, P.y, color, str.c_str(),...); }
	*/

	void CreateMaskScreen() { DxLib::CreateMaskScreen(); }
	void DeleteMaskScreen() { DxLib::DeleteMaskScreen(); }
	int LoadMask(const char* str) { return DxLib::LoadMask(str); }
	void DeleteMask(int Hdl) { DxLib::DeleteMask(Hdl); }
	void DrawMask(int x, int y, int Hdl, int TransMode) { DxLib::DrawMask(x, y, Hdl, TransMode); }
	void SetUseMaskScreenFlag(bool flag) { DxLib::SetUseMaskScreenFlag(flag); }

}