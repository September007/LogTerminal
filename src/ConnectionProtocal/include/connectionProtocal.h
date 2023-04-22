#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <string_view>
#include "./cp_symbol.h"
#include "./cp_msg.h"
namespace CP {

/*************************************************************/
/****** Packet ******/

/* to keep alive: send Alive */
enum class PackType : int8_t
{
    None,
    Alive,
    Data,
    ConnSig_CNT
};
// in milliseconds. this is just recommendation
#define AliveExpiredTime 1000


struct Packet{
    PackType type;
    int data_sz=0;
    // may hold releaser inside
    std::shared_ptr<uint8_t> data;
};



/****************************************************************************/
//****** Connection /******/

/* todo: Following EndPoint is under constructing */
enum class EndPoint_Type{
    None,
    Embeded,
    SameMachine,
    Lan,
    Wan,
    EndPoint_Type_NUM
};

struct EndPoint_Desc
{
    std::string desc;
    EndPoint_Type type=EndPoint_Type::None;
};

struct EndPoint
{
    EndPoint_Desc penpal; // pen friend

    EndPoint(EndPoint_Desc _penpal)
        : penpal(_penpal){}
        
    virtual ~EndPoint() {}
    /* return 0 if success */
    virtual int Connect() = 0;
    /* return 0 if success */
    virtual int Send(Packet const &pack) = 0;
    /* return 0 if success */
    virtual int Receive(Packet &pack) = 0;
    /* return 0 if success */
    virtual int EndConnect() = 0;
    /* return 0 if ok to Send Or Receive */
    virtual int Status() = 0;
    
    /// @brief create EndPoint Connector
    /// @param _desc desc for actually endpoint_type.
    /// @return return Non-Null if success 
    /// @note  caller is responded to release
    CP_API static EndPoint * Create(EndPoint_Desc _desc);
};

} // namespace CP