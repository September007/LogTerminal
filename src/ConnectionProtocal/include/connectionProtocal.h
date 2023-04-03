#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>

#include <symbols.h>
#ifdef CONNECTION_PROTOCAL_EXPORT
#    define CP_API API_DESC_EXPORT
#else
#    define CP_API API_DESC_IMPORT
#endif
namespace CP {

enum class MetaType : int8_t
{
    None,
    Connection,
    Message,
    Control,
    MetaType_CNT
};

/* connection */

/* to build a connection: Start->Start_Resp->Start_Resp */
/* to keep alive: send Alive */
/* to kill connection: End->End_Resp */
enum class ConnSig : int8_t
{
    None,
    Start,
    Start_Resp,
    Alive,
    End,
    End_Resp,
    ConnSig_CNT
};

// in milliseconds. this is just recommendation
#define AliveExpiredTime 1000

/* Message */

enum class MsgSig : int8_t
{
    None,
    Text,
    Image,
    Append, /* append last */
    MsgSig_CNT
};

/* control */

enum class ContrlSig : int8_t
{
    None,
    ContlSig_CNT
};

/*************************************************************/
/* Packet */

struct Packet_Spec
{
    MetaType meta;
    union
    {
        ConnSig conn;
        MsgSig msg;
        ContrlSig ctrl;
    } detail_type;
};

struct PacketData
{
    std::shared_ptr<uint8_t[]> data;
    int size;
    auto TakeInt(int bytes)
    {
        int64_t ret = 0;
        for (int i = bytes - 1; i >= 0; --i)
            ret = (ret << 8) + data.get()[i];
        return ret;
    }
    auto TakeStringView()
    {
        return std::string_view((char *)data.get(), size);
    }
    auto TakeString()
    {
        return std::string((char *)data.get(), size);
    }
};

struct Packet
{
    Packet_Spec spec; // what is this packet
    PacketData data;
};

/****************************************************************************/
/* Connection */

struct EndPoint_Desc
{
    std::string desc;
};

/* return 0 if success */
CP_API struct CP_EndPoint
{
    EndPoint_Desc penpal; // pen friend
    CP_EndPoint(EndPoint_Desc _penpal)
        : penpal(_penpal){};
    virtual ~CP_EndPoint() {}
    /* return 0 if success */
    virtual int Connect() = 0;
    /* return 0 if success */
    virtual int Send(Packet const &pack) = 0;
    /* return 0 if success */
    virtual int Receive(Packet &pack) = 0;
    /* return 0 if success */
    virtual int EndConnect() = 0;
};

CP_API struct CP_BST_
} // namespace CP