#include <cp_msg.h>
#include <mutex>
#include <unordered_map>
#include <log.h>

using namespace CP;

/* global but not exported */
std::mutex alloced_mem_tracer_m;
std::unordered_map<uint8_t*, int> alloced_mem_tracer;
CP_API void *CP_Alloc(int n)
{
    std::unique_lock<std::mutex> lg(alloced_mem_tracer_m);
    auto ret = new uint8_t[n];
    alloced_mem_tracer[ret] = n;
    return ret;
}


CP_API void CP_Free(void* mem) {
    if (!mem)
        return;

    std::unique_lock<std::mutex> lg(alloced_mem_tracer_m);
    auto p = alloced_mem_tracer.find(static_cast<uint8_t*>(mem));
    LLASSERT( p != alloced_mem_tracer.end());
}