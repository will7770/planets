#include <stdlib.h>
#include <cstring>


class SParray {
private:
    int blocksize;
    int length;
    int size;
    void* array;

void init_array() {
    array = std::malloc(blocksize * length);
}
void free_array() {
    std::free(array);
    array = nullptr;
}
public:
    SParray(int blocksize, int length) {
        blocksize = blocksize;
        length = length;
    }

    void* alloc() {
        if (size < length) {
            void* addr = (char*)array + size;
            size++;
            return addr;
        }
        return nullptr;
    }

    void dealloc(int index) {
        if (index < size) {
            std::memmove((char*)array+index-1, (char*)array+size-1, blocksize);
        }
        size--;
    }
};