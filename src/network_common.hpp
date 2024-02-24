#pragma once

#include <vector>
#include <cstddef>

#include "network_common.hpp"
#include <memory>
#include <cassert>


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
enum NODE_ERRORS : class uint32_t
{
  ERROR_ID_COLLITION = 0x00000001,
};



