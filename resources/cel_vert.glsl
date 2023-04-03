#version 120

uniform mat4 P;
uniform mat4 MV;
uniform mat4 MVit;

attribute vec4 aPos; // in object space
attribute vec3 aNor; // in object space

varying vec3 vPos; // camera space position
varying vec3 vNor; // camera space normal

void main()
{
	gl_Position = P * MV * aPos;
	vec4 temp = MV * aPos;
	vPos = temp.xyz;
	temp = MVit * vec4(aNor, 0.0);
	vNor = normalize(temp.xyz);
}