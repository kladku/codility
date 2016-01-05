#include <iostream>
#include <vector>

int solution(std::vector<int>& A)
{
    std::vector<int> result(A.size());

    for (size_t i = 0; i<A.size(); ++i) {
        if (A[i]-1 < result.size() && !result[A[i]-1]) {
            result[A[i]-1] = 1;
        } else {
            return 0;
        }
    }

    return 1;
}


int main(int argc, char *argv[])
{
    std::vector<int> data = {1, 3, 2, 4, 5, 8, 6, 7};
    std::vector<int> data1 = {1000000000};

    std::cout << solution(data) << std::endl;
    std::cout << solution(data1) << std::endl;
}
;
