#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int iStart = 0, iEnd = 0;
    int iSum = sequence[0];
    int n = sequence.size();

    while (iEnd < n) {
        if (iSum == k) {
            if (answer.empty() || (iEnd - iStart) < (answer[1] - answer[0])) {
                answer = {iStart, iEnd};
            }
        }

        // 합이 k보다 크거나 끝에 도달한 경우 iStart 이동
        if (iSum >= k) {
            iSum -= sequence[iStart];
            ++iStart;
        }
        // 합이 k보다 작을 때 iEnd를 증가
        else {
            ++iEnd;
            if (iEnd < n) {
                iSum += sequence[iEnd];
            }
        }
    }
    
    return answer;
}
