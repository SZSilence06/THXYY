﻿#include "MathUtil.h"

using namespace THEngine;

namespace THEngine
{
	float ToAngle(float x, float y)
	{
		float angle;
		if (x == 0)
		{
			if (y > 0)
			{
				angle = 90;
			}
			else if (y < 0)
			{
				angle = -90;
			}
			else
			{
				angle = 0;
			}
		}
		else
		{
			angle = atan(y / x) * 180.0f / PI;
		}
		if (x < 0)
		{
			angle = angle + 180;
		}
		return angle;
	}

	float ToRad(float angle)
	{
		return angle * PI / 180.0f;
	}

	Vector2f Rotate2D(Vector2f pos, float angle)
	{
		Vector2f ret;
		float rad = ToRad(angle);

		ret.x = cos(rad) * pos.x - sin(rad) * pos.y;
		ret.y = sin(rad) * pos.x + cos(rad) * pos.y;

		return ret;
	}
}