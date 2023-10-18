#include<bits/stdc++.h>
using namespace std;

//Có 8 trạng thái
//1: Đổ đầy bình 1
//2: Đổ đầy bình 2
//3: Đổ hết nước của bình 1
//4: Đổ hết nước của bình 2
//5: Đổ nước từ bình 2 sang bình 1 => x+y>a =>(x,y)->(a,x+y-a)
//                                 => x+y<=a => (x,y)->(x+y,0)
//6: Đổ nước từ bình 1 sang bình 2 => x+y>b =>(x,y)->(x+y-b,b) 0,z-b
//                                 => x+y<=b => (x,y) -> (0,x+y)
//Duyệt các trạng thái bằng BFS
//Số lần ít nhất đong được nước chính là khi duyệt hết một trạng thái hay là độ cao của cây BFS
int BFS(int a,int b,int c){
    queue<pair<int,int>> Q;//Hàng đợi để lưu trạng thái
    map<pair<int,int>,int> M;//map để đếm số lần để đến trạng thái đó
    M[{0,0}] = 1;
    Q.push({0,0});
    while(!Q.empty()){
        int x = Q.front().first, y = Q.front().second, z = x+y;Q.pop();
        pair<int,int> Next[] = {{a,y},{x,b},{x,0},{0,y},{max(0,z-b),min(x+y,b)},{min(z,a),max(0,z-a)}};
        for(auto v : Next){
            if(!M[v]){
                M[v]=M[{x,y}]+1;
                Q.push(v);
                if(v.first==c||v.second==c) return M[v]-1;
            }
        }
    }
    return -1;
}   
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    cout << BFS(a,b,c);
}