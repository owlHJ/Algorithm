#include <string>
#include <vector>
#include <numeric> // std::gcd
#include <iostream>
using namespace std;

// 최대 공약수 (GCD)를 구하는 함수
int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

// 배열의 최대 공약수를 구하는 함수
int gcdArray(const vector<int>& arr) {
    return accumulate(arr.begin(), arr.end(), arr[0], [](int a, int b) { return gcd(a, b); }); // 배열의 누적 GCD 계산
}

// 특정 숫자가 배열의 모든 원소를 나눌 수 있는지 확인
bool dividesAll(int divisor, const vector<int>& arr) {
    for (int val : arr) {
        if (val % divisor != 0) return false; // 나눌 수 없는 경우
    }
    return true;
}

// 특정 숫자가 배열의 원소 중 하나라도 나눌 수 있는지 확인
bool dividesAny(int divisor, const vector<int>& arr) {
    for (int val : arr) {
        if (val % divisor == 0) return true; // 나눌 수 있는 경우
    }
    return false;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int gcdA = gcdArray(arrayA); // 철수 카드 최대 공약수
    int gcdB = gcdArray(arrayB); // 영희 카드 최대 공약수

    int resultA = (dividesAll(gcdA, arrayA) && !dividesAny(gcdA, arrayB)) ? gcdA : 0;
    int resultB = (dividesAll(gcdB, arrayB) && !dividesAny(gcdB, arrayA)) ? gcdB : 0;

    return max(resultA, resultB); // 조건에 만족하는 최대값 반환
}