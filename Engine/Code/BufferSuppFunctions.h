#ifndef BUFFER_MANAGER_FUNC
#define BUFFER_MANAGER_FUNC

#include "Globals.h"

#define CreateConstantBuffer(size) BufferManager::CreateBuffer(size, GL_UNIFORM_BUFFER, GL_STREAM_DRAW)
#define CreateStaticVertexBuffer(size) BufferManager::CreateBuffer(size, GL_ARRAY_BUFFER, GL_STATIC_DRAW)
#define CreateStaticIndexBuffer(size) BufferManager::CreateBuffer(size, GL_ELEMENT_ARRAY_BUFFER, GL_STATIC_DRAW)

#define PushData(buffer, data, size) BufferManager::PushAlignedData(buffer, data, size, 1)
#define PushUInt(buffer, value) { u32 v = value; BufferManager::PushAlignedData(buffer, &v, sizeof(v), 4); }
#define PushVec3(buffer, value) BufferManager::PushAlignedData(buffer, value_ptr(value), sizeof(value), sizeof(vec4))
#define PushVec4(buffer, value) BufferManager::PushAlignedData(buffer, value_ptr(value), sizeof(value), sizeof(vec4))
#define PushMat3(buffer, value) BufferManager::PushAlignedData(buffer, value_ptr(value), sizeof(value), sizeof(vec4))
#define PushMat4(buffer, value) BufferManager::PushAlignedData(buffer, value_ptr(value), sizeof(value), sizeof(vec4))

#define BINDING(b) b

namespace BufferManager
{

    bool IsPowerOf2(u32 value);

    u32 Align(u32 value, u32 alignment);

    Buffer CreateBuffer(u32 size, GLenum type, GLenum usage);

    void BindBuffer(const Buffer& buffer);

    void MapBuffer(Buffer& buffer, GLenum access);

    void UnmapBuffer(Buffer& buffer);

    void AlignHead(Buffer& buffer, u32 alignment);

    void PushAlignedData(Buffer& buffer, const void* data, u32 size, u32 alignment);

}

#endif // !BUFFER_MANAGER_FUNC

