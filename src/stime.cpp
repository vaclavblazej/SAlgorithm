#include <iostream>
#include <chrono>

using namespace std;

template<typename TimeT = std::chrono::microseconds>
struct measure {
    template<typename F, typename ...Args>
    static typename TimeT::rep execution(F&& func, Args&&... args) {
        auto start = std::chrono::system_clock::now();
        forward<decltype(func)>(func)(forward<Args>(args)...);
        auto duration = chrono::duration_cast< TimeT> 
                            (chrono::system_clock::now() - start);
        return duration.count();
    }

    template<typename F, typename ...Args>
    static auto duration(F&& func, Args&&... args) {
        auto start = std::chrono::system_clock::now();
        std::forward<decltype(func)>(func)(std::forward<Args>(args)...);
        return std::chrono::duration_cast<TimeT>(std::chrono::system_clock::now()-start);
    }
};
