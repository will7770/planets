#pragma once

#include <vector>
#include <memory>
#include <stdlib.h>
#include <cstring>


template <typename Type, int Size>
class SParray {
private:
    std::vector<Type> array;

public:
    SParray() {
        array = std::vector<Type>();
        array.reserve(Size-array.size());
    }

    Type& operator[](int idx) { return array[idx]; }

    Type* alloc() {
        if (array.size() > array.capacity()) {
            Type* addr = &array[length];
            length++;
            return addr;
        }
        return nullptr;
    }

    void dealloc(int index) {
        if (index < array.size()) {
            array[index] = std::move(array[array.size()-1]);
        }
        length--;
    }
};