#version 120

varying vec3 vPos; // camera space position
varying vec3 vNor; // camera space normal

void main(){

	vec3 eyeVector = normalize(-1 * vPos);
	float mag = dot(normalize(vNor), eyeVector);

	vec3 color;

	if (mag < 0.3){
		
		color = vec3(0.0, 0.0, 0.0);

	}
	else {
	
		color = vec3(1.0, 1.0, 1.0);
	
	}

	gl_FragColor = vec4(color, 1.0);
}