#include <stdlib.h>
#include <string.h>

class Foo
{
public:
    Foo() : _size(0), _mem(nullptr) {}
    Foo(size_t size)
    : _size(size), 
      _mem(malloc(size)) {}

    Foo(const Foo&) = delete;

    // Foo(const Foo& f)
    // : _size(f._size),
    //   _mem(malloc(_size))
    // {
    //     memcpy(_mem, f._mem, _size);
    // }

    ~Foo()
    {
        free(_mem);
    }

    Foo& operator=(const Foo& f) = delete;

    // Foo& operator=(const Foo& f)
    // {
    //     if (_mem)
    //         free(_mem);
    //     _mem = nullptr;
    //     _size = f._size;
    //     if (_size > 0) {
    //         _mem = malloc(_size);
    //         memcpy(_mem, f._mem, _size);
    //     }
    //     return *this;
    // }

private:
    size_t _size;
    void* _mem;
};

int main()
{
    Foo f(1000);
    // Foo g = f;

    // Foo xyz;
    // xyz = f;

    return 0;
}
