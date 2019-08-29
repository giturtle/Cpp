//(https://www.nowcoder.com/practice/70e00e490b454006976c1fdf47f155d9?tpId=8&&tqId=1101)


class LCA {
public:
    int getLCA(int a, int b) {
        while(a != b){
            if(a > b){
                a /= 2;
            }
            else{
                b /= 2;
            }
        }
        return a;
    }
};
