#include <iostream>
#include <vector>

int solution(std::vector<int> &A)
{
    std::vector<int> sums(A.size());

    int result = 0;

    double min_avr = (A[0] + A[1]) / 2.0;

    for (size_t i = 2; i < A.size(); ++i) {
        double avr2 = (A[i-1] + A[i]) / 2.0;
        double avr3 = (A[i-2] + A[i-1] + A[i]) / 3.0;
        if (avr2 < min_avr) {
            result = i - 1;
            min_avr = avr2;
        }
        if (avr3 < min_avr) {
            result = i - 2;
            min_avr = avr3;
        }

    }

    return result;
}

int main()
{
    std::vector<int> data = {4, 2, 2, 5, 1, 5, 8};
    std::cout << solution(data) << std::endl;
};
