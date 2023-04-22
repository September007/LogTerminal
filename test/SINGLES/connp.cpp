#include <connectionProtocal.h>
#include </home/lull/code/LogTerminal/src/ConnectionProtocal/src/internal/serialize.h>
#include <cstring>
#include <memory>
#include <log.h>
using namespace CP;

int main(){
    auto data =std::shared_ptr<uint8_t>( new uint8_t[10]{1,2});
    Packet p{PackType::Data,10,data};
    
    PacketSerilizer_st s;
    s<<p;
    Packet recov;
    s>>recov;

    return 0;
    
}