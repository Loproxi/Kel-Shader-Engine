#ifndef GLOBALS
#define GLOBALS

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <string>
#include <vector>

#pragma warning(disable : 4267) // conversion from X to Y, possible loss of data

typedef char                   i8;
typedef short                  i16;
typedef int                    i32;
typedef long long int          i64;
typedef unsigned char          u8;
typedef unsigned short         u16;
typedef unsigned int           u32;
typedef unsigned long long int u64;
typedef float                  f32;
typedef double                 f64;

typedef glm::vec2  vec2;
typedef glm::vec3  vec3;
typedef glm::vec4  vec4;
typedef glm::ivec2 ivec2;
typedef glm::ivec3 ivec3;
typedef glm::ivec4 ivec4;

enum MouseButton {
    LEFT,
    RIGHT,
    MOUSE_BUTTON_COUNT
};

enum Key {
    K_SPACE,
    K_0, K_1, K_2, K_3, K_4, K_5, K_6, K_7, K_8, K_9,
    K_A, K_B, K_C, K_D, K_E, K_F, K_G, K_H, K_I, K_J, K_K, K_L, K_M,
    K_N, K_O, K_P, K_Q, K_R, K_S, K_T, K_U, K_V, K_W, K_X, K_Y, K_Z,
    K_ENTER, K_ESCAPE,
    KEY_COUNT
};

enum ButtonState {
    BUTTON_IDLE,
    BUTTON_PRESS,
    BUTTON_PRESSED,
    BUTTON_RELEASE
};

struct Input {
    glm::vec2   mousePos;
    glm::vec2   mouseDelta;
    ButtonState mouseButtons[MOUSE_BUTTON_COUNT];
    ButtonState keys[KEY_COUNT];
};

struct VertexBufferAttribute
{
    u8 location;
    u8 componentCount;
    u8 offset;
};

struct VertexBufferLayout
{
    std::vector<VertexBufferAttribute> attributes;
    u8 stride;
};

struct VertexShaderAttribute
{
    u8 location;
    u8 componentCount;
};

struct VertexShaderLayout
{
    std::vector<VertexShaderAttribute> attributes;
};

struct VAO
{
    GLuint handle;
    GLuint programHandle;
};

struct SubMesh
{
    VertexBufferLayout vertexBufferLayout;
    std::vector<float> vertices;
    std::vector<u32> indices;
    u32 vertexOffset;
    u32 indexOffset;

    std::vector<VAO> vaos;
};

struct Mesh
{
    std::vector<SubMesh>    submeshes;
    GLuint                  vertexBufferHandle;
    GLuint                  indexBufferHandle;
};

struct Image
{
    void* pixels;
    ivec2 size;
    i32   nchannels;
    i32   stride;
};

struct Texture
{
    GLuint      handle;
    std::string filepath;
};

struct Program
{
    GLuint             handle;
    std::string        filepath;
    std::string        programName;
    u64                lastWriteTimestamp; // What is this for?
    VertexShaderLayout shaderLayout;
};

struct Model
{
    u32 meshIdx;
    std::vector<u32> materialIdx;
};

enum Mode
{
    Mode_Forward,
    Mode_Deferred,
    Mode_Depth,
    Mode_Normals,
    Mode_Count
};

struct VertexV3V2
{
    glm::vec3 pos;
    glm::vec2 uv;
};

struct String
{
    char* str;
    u32   len;
};

struct Material
{
    std::string     name;
    vec3            albedo;
    vec3            emissive;
    f32             smoothness;
    u32             albedoTextureIdx;
    u32             emissiveTextureIdx;
    u32             specularTextureIdx;
    u32             normalsTextureIdx;
    u32             bumpTextureIdx;
};

struct Buffer {
    GLsizei size;
    GLenum type;
    GLuint handle;
    u8* data;
    u32 head;
};

struct Entity 
{
    glm::mat4 worldMatrix;
    u32 modelIndex;
    u32 localParamsOffset;
    u32 localParamsSize;
};

enum LightType 
{
    LightType_Directional,
    LightType_Point
};

struct Light
{
    LightType type;
    vec3 color;
    vec3 direction;
    vec3 position;
    int visualRef;
    //afegir rango per la llum
};

struct FrameBuffer
{
    std::vector<GLuint> colorAttachment;
    GLuint fbHandle;
    GLuint depthHandle;
};

#define ILOG(...)                 \
{                                 \
char logBuffer[1024] = {};        \
sprintf(logBuffer, __VA_ARGS__);  \
LogString(logBuffer);             \
}

#define ELOG(...) ILOG(__VA_ARGS__)

#define ARRAY_COUNT(array) (sizeof(array)/sizeof(array[0]))

#define ASSERT(condition, message) assert((condition) && message)

#define KB(count) (1024*(count))
#define MB(count) (1024*KB(count))
#define GB(count) (1024*MB(count))

#define PI  3.14159265359f
#define TAU 6.28318530718f

#endif // !GLOBALS

