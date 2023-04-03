#define _USE_MATH_DEFINES
#include <cmath> 
#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/vector_angle.hpp>
#include "FreeLookCamera.h"
#include "MatrixStack.h"

FreeLookCamera::FreeLookCamera() :
	aspect(1.0f),
	fovy((float)(45.0 * M_PI / 180.0)),
	znear(0.1f),
	zfar(1000.0f),
	rotations(0.0, 0.0),
	translations(0.0f, 0.0f, -5.0f),
	rfactor(0.01f),
	tfactor(0.01f),
	sfactor(0.005f),
	position(glm::vec3(0, 0.1, 0)),
	yaw(0.0f),
	pitch(0.0f)
{
}

FreeLookCamera::~FreeLookCamera()
{
}

void FreeLookCamera::mouseClicked(float x, float y, bool shift, bool ctrl, bool alt)
{	
	//std::cout << "Mouse Clicked" << std::endl;
	mousePrev.x = x;
	mousePrev.y = y;
	
}

void FreeLookCamera::mouseMoved(float x, float y)
{	
	//std::cout << "Mouse Moved" << std::endl;
	glm::vec2 mouseCurr(x, y);
	glm::vec2 dv = mouseCurr - mousePrev;
	

	rotations.x += rfactor * dv.x;
	yaw = -1 * rotations.x;

	rotations.y += rfactor * dv.y;

	(rotations.y < -60 * (float)M_PI / 180.0) ? rotations.y = -60 * (float)M_PI / 180.0 : pitch = -1 * rotations.y;
	(rotations.y > 60 * (float)M_PI / 180.0) ? rotations.y = 60.0 * (float)M_PI / 180.0 : pitch = -1 * rotations.y;


	mousePrev = mouseCurr;
}

void FreeLookCamera::keyPressed(unsigned int key) {

	glm::vec3 forward = glm::vec3(sin(yaw), 0, cos(yaw));

	glm::vec3 rightDirection = glm::cross(forward, { 0, 1, 0 });
	glm::vec3 leftDirection = glm::vec3(-1 * rightDirection.x, -1 * rightDirection.y, -1 * rightDirection.z);

	switch (key)
	{
		case 'w':
			position += forward * tfactor;
			break;
		case 'a':
			position += leftDirection * tfactor;
			break;
		case 's':
			position -= forward * tfactor;
			break;
		case 'd':
			position += rightDirection * tfactor;
			break;
	}
}

void FreeLookCamera::updateFOV(unsigned int key) {

	switch (key) {

		case 'z':
			fovy -= 0.1f;
			break;
		case 'Z':
			fovy += 0.1f;
			break;	
	}
	if (fovy > 114 * M_PI / 180.0) {
		fovy = 114 * M_PI / 180.0;
	}
	if (fovy < 4 * M_PI / 180.0) {
		fovy = 4 * M_PI / 180.0;
	}

}


void FreeLookCamera::applyProjectionMatrix(std::shared_ptr<MatrixStack> P) const
{
	// Modify provided MatrixStack
	P->multMatrix(glm::perspective(fovy, aspect, znear, zfar));
}

void FreeLookCamera::applyViewMatrix(std::shared_ptr<MatrixStack> MV) const
{	
						// vec3 = (sin(yaw), 0, cos(yaw))
	glm::vec3 forward = glm::vec3(sin(yaw), pitch, cos(yaw));

	glm::mat4 LA = glm::lookAt(position, position + forward, { 0, 1, 0 });
	MV->multMatrix(LA);
	MV->translate(translations);
}


void FreeLookCamera::incPositionX(float inc) { position[0] += inc; }
void FreeLookCamera::incPositionZ(float inc) { position[2] += inc; }
