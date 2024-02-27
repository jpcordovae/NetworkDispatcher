#pragma once

#include <vector>
#include <cstddef>

#include "network_common.hpp"
#include <memory>
#include <cassert>


#define MACRO_ENUMS_TO_STRINGS(ENUM) case ENUM: return #ENUM

typedef std::vector<std::byte> data_buffer;
typedef std::shared_ptr<data_buffer> data_buffer_ptr;

/// @brief  calculate the minimum number of chunks of a specific size
///         required to contain all the data of the oringinal buffer.
/// @param buffer_size 
/// @param chunk_size 
/// @return size_t, number of chunks
size_t memory_chunks(const size_t buffer_size, const size_t chunk_size)
{
    assert(chunk_size!=0);
    if ( buffer_size % chunk_size ==0 )
    {
        return buffer_size/chunk_size;
    }

    return buffer_size/chunk_size + 1;

}

/// @brief calculates a 64b random value 
/// @return uint64_t, random value
uint64_t rand_uint64(void) {
  uint64_t r = 0;
  for (int i=0; i<64; i += 15 /*30*/) {
    r = r*((uint64_t)RAND_MAX + 1) + rand();
  }
  return r;
}

/// @brief 
enum NODE_ERRORS : uint16_t
{
  ERROR_ID_COLLITION = 0x00000001,
};

enum NETWORK_ERRORS : uint16_t
{ 
  ERROR_NODE_NOT_FOUND = 0x00000001,
  ERROR_NODE_ALREADY_EXISTS = 0x00000002,
  ERROR_NODE_NOT_CONNECTED = 0x00000004,
  ERROR_NODE_ALREADY_CONNECTED = 0x00000008,
  ERROR_NODE_NOT_CREATED = 0x00000010,
  ERROR_NODE_ALREADY_CREATED = 0x00000020,
  ERROR_NODE_NOT_REMOVED = 0x00000040,
  ERROR_NODE_ALREADY_REMOVED = 0x00000080,
  ERROR_NODE_NOT_DISCONNECTED = 0x00000100,
  ERROR_NODE_ALREADY_DISCONNECTED = 0x00000200,
  ERROR_NODE_NOT_CONNECTED_TO_NETWORK = 0x00000400,
  ERROR_NODE_ALREADY_CONNECTED_TO_NETWORK = 0x00000800,

};


