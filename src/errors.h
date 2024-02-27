#pragma once
#include <cstdint>

#define NODE_ERRORS_MACRO(X) \
    X(ID_COLLITION) \
    X(ERROR_)

#define NETWORK_ERRORS_MACRO(X) \
    X(NODE_ID_COLLITION) \
    X(NODE_NOT_FOUND) \
    X(NODE_ALREADY_EXISTS) \
    X(NODE_NOT_CONNECTED) \
    X(NODE_ALREADY_CONNECTED) \
    X(NODE_NOT_REMOVED) \
    X(NODE_ALREADY_REMOVED) \
    X(NODE_NOT_DISCONNECTED) \
    X(NODE_ALREADY_DISCONNECTED) \


#define GENERATE_ENUM(ENUM) ENUM,
#define GENERATE_STRING(STRING) #STRING,

// errors enums
// @{
enum NODE_ERRORS_e : uint16_t
{
    NODE_ERRORS_MACRO(GENERATE_ENUM)
};

enum NETWORK_ERRORS_e : uint16_t
{
    NETWORK_ERRORS_MACRO(GENERATE_ENUM)
};
// @}

// errors strings
// @{
constexpr const char* NODE_ERRORS_STR[] = {
    NODE_ERRORS_MACRO(GENERATE_STRING)
};

constexpr const char* NETWORK_ERRORS_STR[] = {
    NETWORK_ERRORS_MACRO(GENERATE_STRING)
};
// @}




