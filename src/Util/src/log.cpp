#include <log.h>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>
#include <spdlog/sinks/rotating_file_sink.h>

static std::shared_ptr<spdlog::logger> logger = []
{
    auto logger = spdlog::create<spdlog::sinks::stdout_color_sink_mt>("LT");
    auto rsink = std::make_shared<spdlog::sinks::rotating_file_sink_mt>("log/LT.log", 4 * 1024 * 1024, 10);
    logger->sinks().push_back(rsink);
    return logger;
}();
static bool ifOpen = true;

LTU_API  std::shared_ptr<spdlog::logger> LTLog_Logger(){
    return logger;
}


LTU_API bool & LTU_OpenLogPos(){
    return ifOpen;
}

LTU_API void LTU_Log(LTLvl lvl,std::string msg){
    logger->log(spdlog::level::level_enum(int(lvl)), msg);
}