#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), -1); // 기본값 -1로 초기화
    stack<int> s; // 인덱스를 저장하는 스택

    for (int i = 0; i < numbers.size(); ++i) {
        // 현재 숫자가 스택 상단에 저장된 인덱스의 값보다 클 경우 처리
        while (!s.empty() && numbers[s.top()] < numbers[i]) {
            answer[s.top()] = numbers[i];
            s.pop();
        }
        // 현재 인덱스를 스택에 추가
        s.push(i);
    }

    return answer;
}
