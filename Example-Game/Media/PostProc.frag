uniform sampler2D sampler;
uniform vec2 texelSize;
void main()
{
	vec3 col = texture2D(sampler, gl_TexCoord[0].st).rgb;
	for(int x = -3; x < 4; x++)
	{
		for(int y = -3; y < 4; y++)
		{
			col += texture2D(sampler, gl_TexCoord[0].st + vec2(x * texelSize.x, y * texelSize.y)).rgb;
		}
	}
	col /= 37;
	gl_FragColor = vec4(texture2D(sampler, gl_TexCoord[0].st).rgb + col * 0.75, 1);
}