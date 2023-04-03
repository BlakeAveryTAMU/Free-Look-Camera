#ifndef LIGHT_H
#define LIGHT_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Light {

private:

	glm::vec3 position;
	glm::vec3 color;

public:

	Light() {
		position = glm::vec3();
		color = glm::vec3();
	}

	void setPosition(glm::vec3 p) {
		position = p;
	}
	void setColor(glm::vec3 c) {
		color = c;
	}

	glm::vec3 getPosition() { return position; }
	glm::vec3 getColor() { return color; }

	void translatePosition_X(float t) {
		position[0] += t;
	}

	void translatePosition_Y(float t) {
		position[1] += t;
	}

};


#endif