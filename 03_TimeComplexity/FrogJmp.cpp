#include <iostream>
#include <cmath>

int solution(int X, int Y, int D) 
{
    return std::ceil(double(Y-X)/D);
}


int main(int argc, char *argv[])
{
   std::cout << solution(10, 85, 30) << std::endl;
}
