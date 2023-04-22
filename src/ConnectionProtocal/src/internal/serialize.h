#pragma once
#include <connectionProtocal.h>
// #include <boost/serialization/serialization.hpp>
#include <cstring>
#include <log.h>
namespace CP {
struct PacketSerilizer_st
{
    std::string buf;
    int buf_start, buf_end = 0;
    int _shrink_size=4*1024;
    void send_buf(void *p, int sz)
    {
        write(p,sz);
    }

    PacketSerilizer_st operator <<(Packet const&p){
        write(&p.type,sizeof(p.type));
        write(&p.data_sz,sizeof(p.data_sz));
        write(p.data.get(),p.data_sz);
        return *this;
    }
    
    PacketSerilizer_st operator >>(Packet &p){
        read(&p.type,sizeof(p.type));
        read(&p.data_sz,sizeof(p.data_sz));
        p.data.reset(new uint8_t[p.data_sz]);
        read(p.data.get(),p.data_sz);
        return *this;
    }
    int&shrink_size(){
        return _shrink_size;
    }
    int buf_size(){return buf_start-buf_end;}
private:
    void write(const void *p,int sz){
        shrink();
        need(sz);
        std::memcpy(buf.data()+buf_end,p,sz);
        buf_end+=sz;
    }
    void read(void *p,int sz){
        LLASSERT(sz < buf_end-buf_start);
        std::memcpy(p,buf.data()+buf_start,sz);
        buf_start+=sz;
    }
    void shrink(){
        if(buf_start>shrink_size()){
            auto newSS=buf_start;
            std::memcpy(buf.data(),buf.data()+buf_start,buf_size());
            buf_end =buf_size();
            buf_start =0;
            shrink_size() = int(shrink_size()*1.3+0xfff)&0xfffff000;
        
        }
    }
    void need(int i)
    {
        if (buf.size() - buf_end < i)
        {
            auto newsz = (buf_end + i + 0xff) & 0xffffff00;
            buf.resize(newsz);
        }
    }
};
} // namespace CP
