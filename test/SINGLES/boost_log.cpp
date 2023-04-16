
#include <boost/log/trivial.hpp>
#include <chrono>
int main()
{
    BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
    
    int i = 0;
    auto now = std::chrono::system_clock::now();
    while (1) {
        auto cnow = std::chrono::system_clock::now();
        auto dura = std::chrono::duration_cast<std::chrono::milliseconds>(cnow - now);
        if (dura.count() > 1000)
            break;
        //BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
        i++;
    }
    return 0;
}