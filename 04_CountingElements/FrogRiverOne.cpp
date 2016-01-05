#include <iostream>
#include <vector>

int solution(int X, std::vector<int>& A)
{
    std::vector<int> leaves(X);
    int no_of_elem_in_leaves = 0;

    for (size_t i = 0; i < A.size(); ++i) {
        int index = A[i] - 1;
        if (index < leaves.size()) {
            if (!leaves[index]) {
                leaves[index] = 1;
                ++no_of_elem_in_leaves;
            }
        }

        if (no_of_elem_in_leaves == leaves.size())
            return i;
    }

    return -1;
}


int main(int argc, char *argv[])
{
    std::vector<int> data = {1, 3, 1, 4, 2, 3, 5, 4};

    std::cout << solution(5, data) << std::endl;
}
;
