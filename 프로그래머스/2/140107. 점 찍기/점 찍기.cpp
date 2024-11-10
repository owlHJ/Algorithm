#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    long long dSquared = (long long)d * d;

    // x 위치에 따른 가능한 y 위치 계산
    for (long long x = 0; x <= d; x += k) {
        long long maxYSquared = dSquared - x * x;
        long long maxY = (long long)sqrt(maxYSquared);
        
        // 가능한 y 개수를 k 단위로 세기
        answer += (maxY / k) + 1;
    }
    
    return answer;
}
