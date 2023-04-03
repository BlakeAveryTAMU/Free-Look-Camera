#ifndef MATERIAL_H
#define MATERIAL_H

#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Material {

private:

	glm::vec3 ambient;
	glm::vec3 diffuse;
	glm::vec3 specular;
	float shiny;


public:

	Material() {
		ambient = glm::vec3();
		diffuse = glm::vec3();
		specular = glm::vec3();
		shiny = 0.0;
	}

	void setAmbient(glm::vec3 amb) {
		ambient = amb;
	}
	void setDiffuse(glm::vec3 diff) {
		diffuse = diff;
	}
	void setSpecular(glm::vec3 spec) {
		specular = spec;
	}
	void setShiny(float s) {
		shiny = s;
	}

	glm::vec3 getAmbient() { return ambient; }
	glm::vec3 getDiffuse() { return diffuse; }
	glm::vec3 getSpecular() { return specular; }
	float getShiny() { return shiny; }
};



#endif