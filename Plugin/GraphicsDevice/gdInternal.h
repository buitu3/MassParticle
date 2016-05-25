#pragma  once

#ifndef gdLog
    #define gdLog(...)
#endif

#ifdef _WIN32
    #define gdSupportD3D9
    #define gdSupportD3D11
    //#define gdSupportD3D12
    #define gdSupportOpenGL
    //#define gdSupportVulkan
#else
    #define gdSupportOpenGL
#endif

// i.e:
//  roundup<16>(31) : 32
//  roundup<16>(32) : 32
//  roundup<16>(33) : 48
template<int N, class IntType>
inline IntType roundup(IntType v)
{
    return v + (N - v % N);
}

// i.e: 
//  ceildiv(31, 16) : 2
//  ceildiv(32, 16) : 2
//  ceildiv(33, 16) : 3
template<class IntType>
inline IntType ceildiv(IntType a, IntType b)
{
    return a / b + (a%b == 0 ? 0 : 1);
}

#include "GraphicsDevice.h"