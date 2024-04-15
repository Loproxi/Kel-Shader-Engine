#ifdef RENDER_TO_FB

#if defined(VERTEX) ///////////////////////////////////////////////////

layout(location = 0) in vec3 aPosition;
layout(location = 1) in vec3 aNormal;
layout(location = 2) in vec2 aTexCoord;

struct Light
{
	uint type;
	vec3 color;
	vec3 direction;
	vec3 position;
};

layout(binding = 0,std140) uniform GlobalParams
{
	vec3 uCameraPosition;
	uint uLightCount;
	Light uLight[16];
};

layout(binding = 1, std140) uniform LocalParams
{
	mat4 uWorldMatrix;
	mat4 uWorldViewProjectionMatrix;
};

out vec2 vTexCoord;
out vec3 vPosition; // in worldspace
out vec3 vNormal;  // in worldspace
out vec3 vViewDir;

void main()
{
	vTexCoord = aTexCoord;

	vPosition = vec3(uWorldMatrix * vec4(aPosition,1.0));
	vNormal = vec3(uWorldMatrix * vec4(aNormal,0.0));
	vViewDir = uCameraPosition - vPosition;
	float clippingScale = 1.0;

	gl_Position = uWorldViewProjectionMatrix * vec4(aPosition, clippingScale);
}

#elif defined(FRAGMENT) ///////////////////////////////////////////////

struct Light
{
	uint type;
	vec3 color;
	vec3 direction;
	vec3 position;
};

layout(binding = 0,std140) uniform GlobalParams
{
	vec3 uCameraPosition;
	uint uLightCount;
	Light uLight[16];
};

in vec2 vTexCoord;
in vec3 vPosition; // in worldspace
in vec3 vNormal;  // in worldspace
in vec3 vViewDir;

uniform sampler2D uTexture;

layout(location = 0) out vec4 oAlbedo;
layout(location = 1) out vec4 oNormals;
layout(location = 2) out vec4 oPosition;
layout(location = 3) out vec4 oViewDir;


void main()
{

	oAlbedo = texture(uTexture,vTexCoord);
	oNormals = vec4(vNormal,1.0);
	oPosition = vec4(vPosition,1.0);
	oViewDir = vec4(vViewDir,1.0);
}

#endif
#endif