#include <vector>
#include <algorithm>
#include <iostream>

int solution(std::vector<int> &A)
{
    int result = 0;
    int count = 0;

    for (auto it = A.rbegin(); it != A.rend(); ++it) {
        if (*it == 1) {
            ++count;
        } else {
            result += count;
            if (result > 1000000000)
                return -1;
        }
    }

    return result;
}

int main()
{
    std::vector<int> data = {0, 1, 0, 1, 1};
    std::vector<int> data1 = {0, 1, 0, 1, 1, 0, 1};
    std::vector<int> data2 = {0};
    std::vector<int> data3 = {1};
    std::vector<int> data4 = {1, 0};
    std::vector<int> data5 = {0, 1};
    std::cout << solution(data) << std::endl;
    std::cout << solution(data1) << std::endl;
    std::cout << solution(data2) << std::endl;
    std::cout << solution(data3) << std::endl;
    std::cout << solution(data4) << std::endl;
    std::cout << solution(data5) << std::endl;
};
