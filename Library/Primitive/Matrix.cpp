
#include "Matrix.h"
#include <cmath>

Mat2x3::Mat2x3() :_11(0.0f), _12(0.0f), _13(0.0f),_21(0.0f), _22(0.0f), _23(0.0f) {}
Mat2x3::Mat2x3(float _11_, float _12_, float _13_, float _21_, float _22_, float _23_)
:_11(_11_), _12(_12_), _13(_13_),
_21(_21_), _22(_22_), _23(_23_){}

Mat2x3 Mat2x3::Rotate(float angle) {
	const float s = sin(angle);
	const float c = cos(angle);
	return {
		c,s,0.0f,
		-s,c,0.0f
	};
}
