//
// engine.h: This file contains the types and functions relative to the engine.
//

#pragma once

#include "platform.h"
#include "BufferSuppFunctions.h"
#include "ModelLoadingFunctions.h"
#include "Globals.h"

const VertexV3V2 vertices[] = {
    {glm::vec3(-1.0,-1.0,0.0), glm::vec2(0.0,0.0)},
    {glm::vec3(1.0,-1.0,0.0), glm::vec2(1.0,0.0)},
    {glm::vec3(1.0,1.0,0.0), glm::vec2(1.0,1.0)},
    {glm::vec3(-1.0,1.0,0.0), glm::vec2(0.0,1.0)},
};

const u16 indices[] =
{
    0,1,2,
    0,2,3
};

struct App
{

    void UpdateEntityBuffer();

    void HandleCameraInput(vec3& yCam);

    void ConfigureFrameBuffer(FrameBuffer& aConfigFB);

    void CreateDepthAttachment(GLuint& depthAttachmentHandle);

    void CreateColorAttachment(GLuint& colorAttachmentHandle);

    void RenderGeometry(const Program& aBindedProgram);

    const GLuint CreateTexture(const bool isFloatingPoint = false);

    void AddPointLight(u32 modelIndex,vec3 position, vec3 color);

    void AddDirectionalLight(u32 modelIndex,vec3 position, vec3 direction, vec3 color);

    // Loop
    f32  deltaTime;
    bool isRunning;

    // Input
    Input input;

    // Graphics
    char gpuName[64];
    char openGlVersion[64];

    ivec2 displaySize;

    std::vector<Texture>    textures;
    std::vector<Material>   materials;
    std::vector<Mesh>       meshes;
    std::vector<Model>      models;
    std::vector<Program>    programs;

    // program indices
    u32 renderToBackBufferShader = 0;
    u32 renderToFrameBufferShader = 0;
    u32 framebufferToQuadShader = 0;

    u32 patricioModel = 0;
    GLuint texturedMeshProgram_uTexture;
    
    // texture indices
    u32 diceTexIdx;
    u32 whiteTexIdx;
    u32 blackTexIdx;
    u32 normalTexIdx;
    u32 magentaTexIdx;

    // Mode
    Mode mode;

    // Embedded geometry (in-editor simple meshes such as
    // a screen filling quad, a cube, a sphere...)
    GLuint embeddedVertices;
    GLuint embeddedElements;

    // Location of the texture uniform in the textured quad shader
    GLuint programUniformTexture;

    // VAO object to link our screen filling quad with our textured quad shader
    GLuint vao;

    std::string openglDebugInfo;

    GLint maxUniformBufferSize;
    GLint uniformBlockAlignment; //Alignment between uniform BLOCKS!!!!
    Buffer localUniformBuffer;
    std::vector<Entity> entities;
    std::vector<Light> lights;

    GLuint globalParamsOffset;
    GLuint globalParamsSize;

    FrameBuffer deferredFrameBuffer;

    vec3 camFront = vec3(0.0f, 0.0f, -1.0f);
    vec3 cameraPosition = vec3(0.0, 0.0, 0.0);
    float yaw = -90.0f;
    float pitch = -90.0f;

    bool firstMouseEnter = true;
    bool useDepth = false;
    bool useNormal = false;

};

void Init(App* app);

void Gui(App* app);

void Update(App* app);

void Render(App* app);


