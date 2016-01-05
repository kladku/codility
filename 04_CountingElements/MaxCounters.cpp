#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> solution(int N, std::vector<int> &A)
{
    std::vector<int> counters(N);

    int max = 0;
    int adjust = 0;

    std::for_each(A.cbegin(), A.cend(), [&](const int &a) {
        if (a <= N) {
            counters[a-1] = std::max(counters[a-1], adjust) + 1;
            max = std::max(max, counters[a-1]);
        } else {
            adjust = max; 
        }
    });

    std::for_each(counters.begin(), counters.end(), [&adjust](int &c) { 
        c = std::max(c, adjust);  
    });

    return counters;
}

int main()
{
    std::vector<int> data = {3, 4, 4, 6, 1, 4, 4};

    std::vector<int> result = solution(5, data);

    for (const auto& i : result)
        std::cout << i << " ";
    std::cout << "\n";
}
