#ifndef MODEL_LOADING_FUNC
#define MODEL_LOADING_FUNC

#include <assimp/cimport.h>
#include <assimp/scene.h>
#include <assimp/postprocess.h>
#include "Globals.h"
#include <vector>

struct App;

namespace ModelLoader
{
    Image LoadImage(const char* filename);

    void FreeImage(Image image);

    GLuint CreateTexture2DFromImage(Image image);

    u32 LoadTexture2D(App* app, const char* filepath);

    void ProcessAssimpMesh(const aiScene* scene, aiMesh* mesh, Mesh* myMesh, u32 baseMeshMaterialIndex, std::vector<u32>& submeshMaterialIndices);

    void ProcessAssimpMaterial(App* app, aiMaterial* material, Material& myMaterial, String directory);

    void ProcessAssimpNode(const aiScene* scene, aiNode* node, Mesh* myMesh, u32 baseMeshMaterialIndex, std::vector<u32>& submeshMaterialIndices);

    u32 LoadModel(App* app, const char* filename);
}

#endif
