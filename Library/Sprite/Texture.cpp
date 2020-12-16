
#include "Texture.h"
#include "DxLib.h"
#include "../../Library/Primitive/Primitive.h"

int Texture::Many = 0;

Texture::Texture(char* filename)noexcept { mHandle = LoadGraph(filename); }
Texture::Texture(int Handle)noexcept:mHandle(Handle){}
void Texture::set(int Handle) noexcept { mHandle = Handle; }
void Texture::load(char* filename)noexcept { mHandle = LoadGraph(filename); }

void Texture::draw(const Point& P)noexcept {
	DrawGraph(P.x, P.y, mHandle, TRUE);
}

void Texture::drawCenter(const Point& P)noexcept {
	int X, Y;
	GetGraphSize(mHandle, &X, &Y);
	DrawGraph(P.x+X, P.y+Y, mHandle, TRUE);
}

void Texture::draw(const Point& P, float ExRate, float Angle, bool turnflag )noexcept {
	DrawRotaGraphFast(P.x, P.y, ExRate, Angle, mHandle, TRUE, turnflag);
}

void Texture::filter(int FilterType, int value, int value2)noexcept {

}

int Texture::getXSize()noexcept {
	int X, Y;
	GetGraphSize(mHandle, &X, &Y);
	return X;
}

int Texture::getYSize()noexcept {
	int X, Y;
	GetGraphSize(mHandle, &X, &Y);
	return Y;
}

Point Texture::getSize()noexcept {
	int X, Y;
	GetGraphSize(mHandle, &X, &Y);
	return Point(X, Y);
}
