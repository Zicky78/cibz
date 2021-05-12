uniform sampler2D myTexture;
uniform bool invul;
uniform bool isBlk;
uniform bool isDdg;
varying vec4 texCoord;
//varying vec3 position;

void main()
{
	//gl_FragColor = texture2D(myTexture, texCoord).brga;
	if(invul && !(isBlk || isDdg))
		gl_FragColor = texture2D(myTexture, texCoord) * vec4(1.0, 0.0, 0.0, 0.8);
	else
		gl_FragColor = texture2D(myTexture, texCoord);

	//gl_FragColor = vec4(1.0, 0.0, 0.0, 0.5);
}