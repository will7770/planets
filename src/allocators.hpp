#pragma once

#include <memory>
#include <stdlib.h>
#include <cstring>


template <typename Type, int Size>
class SParray {
private:
    alignas(alignof(Type)) std::byte array[Size*sizeof(Type)];
    int capacity;
    int size;

    Type* get_ptr(int idx) {
        return reinterpret_cast<Type*>(&array[idx * sizeof(Type)]);
    }

public:
    SParray() {
        capacity = Size;
        size = 0;
    }

    Type& operator[](int idx) { return *get_ptr(idx); }

    Type* alloc() {
        if (size < capacity) {
            Type* addr = get_ptr(size);
            size++;
            return addr;
        }
        return nullptr;
    }

    void dealloc(int index) {
        if (index < size && index >= 0) {
            get_ptr(index)->~Type();

            if (index < size - 1) {
                new (get_ptr(index)) Type(std::move(*get_ptr(size - 1)));
                get_ptr(size - 1)->~Type();
            }
            size--;
        }
    }
};