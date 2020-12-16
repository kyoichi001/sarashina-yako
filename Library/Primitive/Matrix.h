#pragma once

#include "Primitive.h"

class Mat2x3 {
	float
		_11, _12, _13,
		_21, _22, _23;
public:
	Mat2x3();
	Mat2x3(float _11_, float _12_, float _13_, float _21_, float _22_, float _23_);

	Point operator *(const Point& P)const {
		return {
			P.x*_11 + P.y*_12 + _13,
			P.x*_21 + P.y*_22 + _23,
		};
	}
	Vec2 operator *(const Vec2& P)const {
		return {
			P.x*_11 + P.y*_12 + _13,
			P.x*_21 + P.y*_22 + _23,
		};
	}
	Mat2x3 operator *(float t)const {
		return {
			t*_11 , t*_12,t* _13,
			t*_21,t*_22 ,t*_23,
		};
	}
	Mat2x3 operator /(float t)const {
		return {
			t/_11 , t/_12,t/ _13,
			t/_21,t/_22 ,t/_23,
		};
	}
	Mat2x3 operator *=(float t) { *this = *this*t; }
	Mat2x3 operator /=(float t) { *this = *this/t; }

	static Mat2x3 Rotate(float angle);
	static Mat2x3 Extend(float x, float y){
		return {
			x,0.0f,0.0f,
			0.0f,y,0.0f
		};
	}
	static Mat2x3 Extend(float r) {
		return {
			r,0.0f,0.0f,
			0.0f,r,0.0f
		};
	}
	static Mat2x3 Translate(float x, float y) {
		return {
			1.0f,0.0f,x,
			0.0f,1.0f,y
		};
	}

};

class Mat3x4 {
	float
		_11, _12, _13, _14,
		_21, _22, _23, _24,
		_31, _32, _33, _34;
public:
	Mat3x4(float _11_, float _12_, float _13_, float _21_, float _22_, float _23_);
	static Mat3x4 Rotate(float angle);

	Point operator *(const Point& P) {
		return {
			P.x*_11 + P.y*_12 + _13,
			P.x*_21 + P.y*_22 + _23,
		};
	}

};