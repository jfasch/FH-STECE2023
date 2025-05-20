#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v = {1,2,3,4,5};
    v.push_back(6);

    for (auto it=v.begin(); it!=v.end(); ++it)
        std::cout << *it << std::endl;

    return 0;
}
