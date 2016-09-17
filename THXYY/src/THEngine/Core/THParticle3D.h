#ifndef THPARTICLE3D_H
#define THPARTICLE3D_H

#include "../Common/THCommon.h"
#include "THRenderObject.h"
#include "../Asset/THTexture.h"

namespace THEngine
{
	class Particle3D : public RenderObject
	{
	protected:
		Texture* texture;
		Rect texRect;
		Vector2f pivot = Vector2f(0.5f, 0.5f);

		bool flipX = false;
		bool flipY = false;

		Vector3f direction = Vector3f(0, 0, 0);
		Vector3f rotatingAxis = Vector3f(0, 0, 1);
		float rotatingSpeed = 0.0f;
		float speed = 0.0f;

		int life = 200;

	public:
		Particle3D();
		virtual ~Particle3D();

		virtual void Update() override;

		virtual void Draw() override;

		virtual void SendToRenderQueue() override;

		void RotateByAxis(Vector3f axis, float degree);

		inline void SetTexture(Texture* texture)
		{
			this->texture = texture;
		}
		inline void SetTexRect(Rect rect) { this->texRect = rect; }
		inline Rect GetTexRect() { return texRect; }

		inline void SetPivot(Vector2f pivot) { this->pivot = pivot; }

		inline void SetFlipX(bool flipX) { this->flipX = flipX; }
		inline void SetFlipY(bool flipY) { this->flipY = flipY; }

		inline void SetDirection(Vector3f direction) { this->direction = direction.Normalize(); }
		inline Vector3f GetDirection() { return direction; }

		inline void SetSpeed(float speed) { this->speed = speed; }
		inline float GetSpeed() { return speed; }

		inline void SetRotatingAxis(Vector3f rotatingAxis) { this->rotatingAxis = rotatingAxis; }
		inline Vector3f GetRotatingAxis() { return rotatingAxis; }

		inline void SetRotatingSpeed(float rotatingSpeed) { this->rotatingSpeed = rotatingSpeed; }
		inline float GetRotatingSpeed() { return rotatingSpeed; }

		inline void SetLife(int life) { this->life = life; }
		inline int GetLife() { return life; }

		friend class Particle3DRenderer;
	};
}

#endif