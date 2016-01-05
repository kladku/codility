#include <vector>
#include <algorithm>
#include <iostream>
#include <iterator>

template<typename T>
std::ostream& operator<<(std::ostream &os, const std::vector<T> &v)
{
    os << "vector = { ";
    if (!v.empty()) {
        std::copy(v.cbegin(), std::prev(v.cend()), std::ostream_iterator<T>(os, ", "));
        os << v.back();
    }
    os << " }";
    return os;
}

int nucleotid_to_int(const char nucleotid)
{
    switch (nucleotid) {
        default:
        case 'A': return 0;
        case 'C': return 1;
        case 'G': return 2;
        case 'T': return 3;
    }
}

std::vector<int> solution(std::string &S, std::vector<int> &P, std::vector<int> &Q)
{
    auto positions = std::vector<std::vector<int>>(S.size(), std::vector<int>(4, -1));

    positions.front()[nucleotid_to_int(S.front())] = 0;

    for (auto it = std::next(S.cbegin()), end = S.cend(); it !=end; ++it) {
        int idx = std::distance(S.cbegin(), it);
        positions[idx] = positions[idx-1];
        positions[idx][nucleotid_to_int(*it)] = idx;
    }

    std::vector<int> result(P.size());

    for (size_t i = 0; i < P.size(); ++i) {
        auto check = positions[Q[i]];
        result[i]  = std::distance(check.cbegin(), std::find_if(check.cbegin(), check.cend(), [&](int c) { return c >= P[i]; } )) + 1;
    }

    return result;
}

int main()
{
    std::vector<int> P = {2, 5, 0};
    std::vector<int> Q = {4, 5, 6};
    std::string S = "CAGCCTA";
    std::cout << solution(S, P, Q) << std::endl;
    S = "AC";
    P = { 0, 0, 1 };
    Q = { 0, 1, 1 };
    std::cout << solution(S, P, Q) << std::endl;
};
