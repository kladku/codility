#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

int solution(std::vector<int>& A)
{
    std::set<int> m;

    for (auto i: A)
       if (i > 0)
           m.insert(i);

    if (m.empty() || *m.cbegin() > 1)
       return 1;

    auto it = std::adjacent_find(m.cbegin(), m.cend(), [](int left, int right) { return right - left > 1; });
    if (it != m.cend())
       return *it + 1;

    return *m.rbegin() + 1;

};


int main(int argc, char *argv[])
{
    std::vector<int> data = {1, 3, 6, 4, 1, 2};
    std::vector<int> data1 = {4, 1, -2};
    std::vector<int> data2 = {-1};
    std::vector<int> data3= {4, 5, 6, 2};
    std::vector<int> data4 = {-2147483648, 2147483647};
    std::vector<int> data5 = {4};

    std::cout << solution(data) << std::endl;
    std::cout << solution(data1) << std::endl;
    std::cout << solution(data2) << std::endl;
    std::cout << solution(data3) << std::endl;
    std::cout << solution(data4) << std::endl;
    std::cout << solution(data5) << std::endl;
}

