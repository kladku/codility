#include <iostream>
#include <vector>
#include <algorithm>

int solution(std::vector<int> &A)
{
    using point = std::pair<int64_t, int64_t>;
    std::vector<point> points;
    points.reserve(A.size());

    auto comp = [](const point& left, const point& right) { return left.first < right.first; };

    for (auto it = A.cbegin(), end = A.cend(), begin = A.cbegin(); it != end; ++it) {
        const point& p = {std::distance(begin, it) - *it, std::distance(begin, it) + *it};
        points.insert(std::upper_bound(points.begin(), points.end(), p, comp), p);
    }

    int result = 0;

    for (auto it = points.cbegin(), end = points.cend(); it != end; ++it) {
        result += std::distance(std::next(it), std::upper_bound(it, end, point((*it).second, 0), comp));
        if (result > 10000000)
            return -1;
    }

    return result; 
}

int main(int argc, char *argv[])
{
    std::vector<int> v1 = {1, 5, 2, 1, 4, 0};
    std::cout << solution(v1) << std::endl;
    std::vector<int> v2 = {1, 2147483647, 0};
    std::cout << solution(v2) << std::endl;
    return 0;
}
