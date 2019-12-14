#pragma once

#include "../types.h"
#include "coordinate.h"
#include "world_constants.h"
#include <array>

class ChunkManager;

struct Chunk {
  public:
    Chunk(ChunkManager *manager, const ChunkPosition &position);

    u8 qGetBlock(const BlockPosition &blockPosition) const;
    void qSetBlock(const BlockPosition &blockPosition, u8 block);

    u8 getBlock(const BlockPosition &blockPosition) const;

    const ChunkPosition &getPosition() const;

  private:
    std::array<u8, CHUNK_VOLUME> blocks{0};
    ChunkManager *mp_manager;
    ChunkPosition m_position;
};

class ChunkManager final {
  public:
    Chunk &addChunk(const ChunkPosition &chunk);

    u8 getBlock(const BlockPosition &blockPosition) const;
    void setBlock(const BlockPosition &blockPosition, u8 block);

    bool hasChunk(const ChunkPosition &chunk) const;
    bool hasNeighbours(const ChunkPosition &chunkPosition) const;

  private:
    ChunkPositionMap<Chunk> m_chunks;
};