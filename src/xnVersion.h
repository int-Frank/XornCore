#ifndef XNVERSION_H
#define XNVERSION_H

#include <stdint.h>
#include <string>

//---------------------------------------------
// Version
//---------------------------------------------
#define VERSION_MAJOR 1
#define VERSION_MINOR 0
#define VERSION_PATCH 1

//---------------------------------------------
// As a single integer
//---------------------------------------------
#define HELPER(x) x
#define VERSION_AS_UINT uint32_t((HELPER(VERSION_MAJOR) ## ul << 20) | (HELPER(VERSION_MINOR) ## ul << 10) | (HELPER(VERSION_PATCH) ## ul))

//---------------------------------------------
// As a string
//---------------------------------------------
#define QUOTE(str) #str
#define EXPAND_AND_QUOTE(major, minor, rev) QUOTE(major) "." QUOTE(minor) "." QUOTE(rev)
#define VERSION_AS_STRING EXPAND_AND_QUOTE(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH)

//---------------------------------------------
// Get version components from integer
//---------------------------------------------
#define GET_VERSION_MAJOR(v) uint32_t((v >> 20ul) & 0x3FFul)
#define GET_VERSION_MINOR(v) uint32_t((v >> 10ul) & 0x3FFul)
#define GET_VERSION_PATCH(v) uint32_t(v & 0x3FFul)

//---------------------------------------------
// Version number to string
//---------------------------------------------

namespace xn
{
  std::string VersionNumberToString(uint32_t version);
}

#endif