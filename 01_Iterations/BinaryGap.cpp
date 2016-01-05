#include <algorithm>
#include <iostream>

int solution(int N)
{
    if (!N)
        return 0;

    int max = 0;
    int gap = 0;
    bool found = false;

    while (N) {

        if (N & 1) {
            if (!found)
                found = true;
            else
                max = std::max(max, gap);
            gap = 0;
        } else {
            ++gap;
        }

        N >>= 1;
    }

    return max;
}

int main(int argc, char *argv[])
{

    std::cout << solution(328) << std::endl;
    return 0;
}
