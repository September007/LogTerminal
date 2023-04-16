#pragma once
#include "./symbols.h"
#include <fmt/format.h>

enum class LTLvl
{
    trace,
    debug,
    info,
    warn,
    error,
    critical,
    off,
    n_levels
};

LTU_API bool & LTU_OpenLogPos();

LTU_API void LTU_Log(LTLvl lvl, std::string msg);

#define POS_STR         fmt::format("{}:{}", __FILE__, __LINE__)
#define LTLOG(lvl, ...) LTU_Log(LTLvl::lvl, fmt::format("%s %s", fmt::format(__VA_ARGS__), LTU_OpenLogPos() ? POS_STR : ""))

#define LLASSERT(condi)                                                                                                                    \
    do                                                                                                                                     \
    {                                                                                                                                      \
        bool b = (condi);                                                                                                                  \
        if (!b)                                                                                                                            \
            LTLOG(error, "ASSERT failed [{}] {}", #condi, __func__);                                                                       \
    } while (0)
