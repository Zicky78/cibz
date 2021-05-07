//uniform float scale;
varying vec4 texCoord;
//varying vec3 position;

void main()
{
	vec4 a = gl_Vertex;

	//a.x = a.x * scale;
	//a.y = a.y * scale;

	texCoord = gl_MultiTexCoord0;

	gl_Position = gl_ModelViewProjectionMatrix * a;
}