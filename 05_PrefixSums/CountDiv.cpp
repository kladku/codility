#include <vector>
#include <iostream>

int solution(int A, int B, int K)
{
    int result = (B / K) - (A / K);

    if (!(A%K))
        ++result;

    return result;
}

int main()
{
    std::vector<int> data = {6, 12, 2};

    std::cout << solution(6 , 11, 2) << std::endl;
    std::cout << solution(6 , 12, 2) << std::endl;
    std::cout << solution(7 , 12, 2) << std::endl;
    std::cout << solution(11 , 345, 17) << std::endl;
};
