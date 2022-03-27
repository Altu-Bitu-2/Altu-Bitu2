#include <iostream>
#include <vector>

using namespace std;

//기숙사 바닥의 l(높이), w(넓이)를 구해서 리턴하는 함수
pair<int, int> length(int r, int b){
    int area = r + b;
    for(int i=area; i > 0; i--){
        // i : l(높이)의 값
        if(area % i != 0){
            //w가 정수가 아니라면 넘어감
            continue;
        }
        //w(넓이)는 타일의 총 개수에서 i를 뺀 정수
        int w = area / i;

        //빨간 타일이 테두리의 개수와 같으면 i, w쌍 리턴
        if (r==((i+w) *2 -4)){
            return make_pair(i, w);
        }
    }
}

// 가장자리는 빨간색, 가운데는 갈색으로 채운 타일
// r과 b가 주어졌을 때 방의 크기를 구하기
int main() {
    //입력
    int r, b;
    //r:빨간 타일 개수, b: 갈색 타일 개수

    cin >> r >> b;

    //연산
    pair<int, int> result = length(r, b);

    //출력
    cout << result.first << ' ' << result.second << '\n'; 
    return 0;
}