#ifdef BASE_MODEL

#if defined(VERTEX) ///////////////////////////////////////////////////

// TODO: Write your vertex shader here

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;
layout(location = 3) in vec3 aTangent;
layout(location = 4) in vec3 aBitangent;


out vec2 vTexCoord;

void main()
{
	vTexCoord = aTexCoord;

	float clippingScale = 5.0;

	gl_Position = vec4(aPosition, clippingScale);
	gl_Position = -gl_Position.z;
}

#elif defined(FRAGMENT) ///////////////////////////////////////////////

// TODO: Write your fragment shader here

in vec2 vTexCoord;
uniform sampler2D uTexture;
layout(location = 0) out vec4 oColor;

void main()
{
	oColor = texture(uTexture, vTexCoord);
}

#endif
#endif


// NOTE: You can write several shaders in the same file if you want as
// long as you embrace them within an #ifdef block (as you can see above).
// The third parameter of the LoadProgram function in engine.cpp allows
// chosing the shader you want to load by name.
