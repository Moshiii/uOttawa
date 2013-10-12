#include "stdafx.h"
#include <iostream>
#include "vector3.h"

namespace vctr{
	Vector3::Vector3(){
		x=y=z=0;
	}
	
	Vector3::Vector3(double a, double b, double c){
				x=a;
				y=b;
				z=c;
		}
	
	double norm(Vector3 vector){
			return sqrt(vector.x*vector.x + vector.y*vector.y + vector.z*vector.z);
		}
	
	void normalize( Vector3* vector){
			double temp = norm(*vector);
			vector->x /= temp;
			vector->y /= temp;
			vector->z /= temp;
		}
}
