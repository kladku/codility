#include <vector>
#include <iostream>
#include <numeric>

int solution(std::vector<int> &A) 
{
    int expected_sum = (1 + A.size() + 1)*(A.size() + 1)/2;
    int sum = std::accumulate(A.cbegin(), A.cend(), 0);
    return expected_sum - sum;
}


int main(int argc, char *argv[])
{
   std::vector<int> data = { 2, 3, 1, 5};

   std::cout << solution(data) << std::endl;
}
