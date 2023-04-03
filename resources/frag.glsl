#version 120

uniform vec3 lightColor1;
uniform vec3 lightPos1;
uniform vec3 ka;
uniform vec3 kd;
uniform vec3 ks;
uniform float s;

uniform sampler2D texture0;
varying vec2 vTex0;

varying vec3 vPos; // camera space position
varying vec3 vNor; // camera space normal



void main()
{

	//cd1: 
	vec3 lightDir1 = lightPos1 - vPos;
	lightDir1 = normalize(lightDir1);
	float lambertian1 = max(0.0, dot(lightDir1, normalize(vNor)));

	//cs1:
	vec3 eyeVector = normalize(-1 * vPos);
	vec3 halfDir1 = normalize(lightDir1 + eyeVector);
	float specular1 = pow(max(0.0, dot(halfDir1, normalize(vNor))), s);

	vec3 cd1 = kd * lambertian1;
	vec3 cs1 = ks * specular1;


	vec3 color1 = lightColor1 * (ka + cd1 + cs1);

	vec3 kd_tex = texture2D(texture0, vTex0).rgb;
	vec4 color2 = vec4(kd_tex, 1.0);
	
	gl_FragColor = vec4(color1, 1.0) + color2;
	
	
}
