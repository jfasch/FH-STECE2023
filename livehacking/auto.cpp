#include <vector>
#include <iostream>

int main()
{
    // int v[] = {1, 2, 3, 4, 5, 6};
    // const int* begin = &v[0];
    // const int* end = &v[6];

    std::vector<int> v = {1,2,3,4,5};
    v.push_back(6);

    auto begin = v.begin();
    auto end = v.end();

    while (begin < end) {
        std::cout << *begin << std::endl;
        begin++;
    }

    auto my_func = [](int i){
        std::cout << i << std::endl;
    };
    my_func(42);

    return 0;
}
