#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

int solution(std::vector<int> &A)
{
    std::vector<int> sums(A.size());
    std::partial_sum(std::begin(A), std::end(A), std::begin(sums));

    int result = std::numeric_limits<int>::max();

    for (auto it = std::next(sums.begin()), end = std::end(sums); it != end; ++it)
        result = std::min(std::abs(*std::prev(it)*2 - sums.back()), result);

    return result;
}

int main(int argc, char *argv[])
{
    std::vector<int> v = { 3, 1, 2, 4, 3 };

    std::cout << solution(v) << std::endl;

    return 0;
}
