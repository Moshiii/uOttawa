#pragma once
#include "stdafx.h"

namespace vctr{
	struct Vector3
	{
		double x,y,z;
		Vector3();
		Vector3(double a, double b, double c);
	};
		
	double norm(Vector3 vector);
		
	void normalize( Vector3* vector);
}
