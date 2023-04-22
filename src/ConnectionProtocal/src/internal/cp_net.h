#pragma once
#include <boost/asio.hpp>

#include <connectionProtocal.h>
namespace CP{

struct EP_Net_Desc{
    std::string ipaddr;
    int32_t port;
};

struct EndPoint_Net:EndPoint{
    EP_Net_Desc penpal_desc;
 
    /* return 0 if success */
     int Connect();
    /* return 0 if success */
     int Send(Packet const &pack);
    /* return 0 if success */
     int Receive(Packet &pack);
    /* return 0 if success */
     int EndConnect();
    /* return 0 if ok to Send Or Receive */
     int Status();

    static EndPoint *Try_Load(EndPoint_Desc desc);
};

}