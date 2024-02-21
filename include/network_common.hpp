#pragma once

#include <vector>
#include <cstddef>

#include "network_common.hpp"

typedef std::vector<std::byte> byte_buffer;

uint64_t rand_uint64(void) {
  uint64_t r = 0;
  for (int i=0; i<64; i += 15 /*30*/) {
    r = r*((uint64_t)RAND_MAX + 1) + rand();
  }
  return r;
}

