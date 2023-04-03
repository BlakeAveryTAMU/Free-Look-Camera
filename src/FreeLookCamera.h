#pragma  once
#ifndef FREE_LOOK_CAMERA_H
#define FREE_LOOK_CAMERA_H

#include <memory>

#define GLM_FORCE_RADIANS
#include <glm/glm.hpp>

class MatrixStack;

class FreeLookCamera
{
public:
	enum {
		ROTATE = 0,
		TRANSLATE,
		SCALE
	};

	FreeLookCamera();
	virtual ~FreeLookCamera();
	void setInitDistance(float z) { translations.z = z; }
	void setAspect(float a) { aspect = a; };
	void setRotationFactor(float f) { rfactor = f; };
	void setTranslationFactor(float f) { tfactor = f; };
	void setScaleFactor(float f) { sfactor = f; };
	void mouseClicked(float x, float y, bool shift, bool ctrl, bool alt);
	void mouseMoved(float x, float y);
	void keyPressed(unsigned int key);
	void updateFOV(unsigned int key);
	void applyProjectionMatrix(std::shared_ptr<MatrixStack> P) const;
	void applyViewMatrix(std::shared_ptr<MatrixStack> MV) const;
	void incPositionX(float inc);
	void incPositionZ(float inc);

	glm::vec3 getPosition() { return position; }
	float getYaw() { return yaw; }
	float getPitch() { return pitch; }
	float getFOV() { return fovy; }

private:
	float aspect;
	float fovy;
	float znear;
	float zfar;
	glm::vec2 rotations;
	glm::vec3 translations;
	glm::vec2 mousePrev;
	int state;
	float rfactor;
	float tfactor;
	float sfactor;

	glm::vec3 position;
	float yaw;
	float pitch;

};

#endif