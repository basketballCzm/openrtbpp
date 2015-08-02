/* types.h
   Mathieu Stefani, 01 August 2015
   
   Helper types for OpenRTB
*/

#pragma once

#include <string>

namespace Types {

typedef std::string Id;

#define Type(type) type
#define Value(value) value
#define Alias(value, other) value = other

#define DefineEnum(EnumType, ...) \
    enum class EnumType { \
        Unknown = 0, \
        __VA_ARGS__ \
    }

template<typename T, T defValue = T::Unknown>
struct Enum {
    typedef typename std::underlying_type<T>::type type;

    type val;

    Enum(T val = defValue) : val(static_cast<type>(val)) { }
};

template<bool defValue = false>
struct Bool {
    bool val;

    Bool(bool val = defValue) : val(val) { }
};

template<int defValue = -1>
struct Integer {
    int val;

    Integer(int val = defValue) : val(val) { }
};

struct Float {
    float val;

    Float(float val = 0.0) : val(val) { }
};

} // namespace Types
