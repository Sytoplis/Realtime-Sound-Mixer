#include "TypeIdSystem.h"

//INCLUDE ALL ID TYPES
#include "storage/Assets/AudioAsset.h"
#include "storage/Assets/SingleAudioAsset.h"
#include "storage/Scene.h"
//END ID TYPES


#include <iostream>
#include <type_traits>
template<class T>
constexpr bool is_void = std::is_same<T, void>::value;

template<size_t i>
static void* TryCreateOj(size_t id) {
    if (id != i) return nullptr;
    if constexpr (!is_void<typename IDType<i>::T>) {//this gets evaluated at compile time
        std::cout << "return type" << std::endl;
        return new typename IDType<i>::T();
    }
    else {
        std::cout << "type of id " << i << " was not defined" << std::endl;
        return nullptr;
    }
}


//--- COMPILE TIME LOOP ---
//Source: https://stackoverflow.com/questions/15275023/clang-force-loop-unroll-for-specific-loop

template<size_t N, size_t I>
class repeat_t
{
public:
    repeat_t() {}
    void* operator()(size_t id)
    {
        void* ptr = TryCreateOj<I>(id);
        if (ptr != nullptr)
            return ptr;
        return repeat_t<N, I + 1>()(id);
    }
};

template<size_t N>
class repeat_t<N, N>
{
public:
    repeat_t() {}
    void* operator()(size_t id) { return nullptr; }
};

template<size_t N>
repeat_t<N, 0> repeat()
{
    return repeat_t<N, 0>();
}
    

void* CreateOjFromId(size_t id) {
    return repeat<ID_COUNT>()(id);
}