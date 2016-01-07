#include <iostream>
#include <algorithm>

template<typename It>
bool check_if_fits(It it, It end, int K, int max_sum)
{
    int counts = 0;
    int sum = 0;
    for (;it != end; ++it) {
        if (sum + *it > max_sum) {
            ++counts;
            sum = *it;
        } else {
            sum += *it;
        }

        if (counts >= K)
            return false;
    }

    return true;
}

int solution(int K, int M, std::vector<int>& A)
{
    int lower_bound = *std::max_element(std::begin(A), std::end(A));
    int upper_bound = std::accumulate(std::begin(A), std::end(A), 0);

    while (lower_bound <= upper_bound) {
        int mid = (upper_bound + lower_bound) / 2;
        if (check_if_fits(std::begin(A), std::end(A), K, mid)) {
            upper_bound = mid - 1;
        } else {
            lower_bound = mid + 1;
        }
    }

    return lower_bound;
}

int main(int argc, char *argv[])
{
    std::vector<int> v = {2, 1, 5, 1, 2, 2, 2};
    std::cout << solution(3, 5, v) << std::endl;
    return 0;
}
