#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

class doll{
public:
    doll(){h=0;w=0;}
    doll(int nh,int nw){h=nh;w=nw;}
    bool operator < (doll other){
        return w==other.w? h>other.h:w<other.w;
    }
    int h,w;

};

int find_less_index(vector<int> temp,int t){
    int index=temp.size();
    for(int i=temp.size()-1;i>=0;i--)
        if(temp[i]>t)
            index=i;
    return index;

}

int main(){
    int caseNum;
    cin>>caseNum;

    while(caseNum--){
        int dollNum;
        cin>>dollNum;

        vector<doll> decreasing;
        vector<int> current;

        doll* ptr;

        for(int i=0;i<dollNum;i++){
            int h,w;
            cin>>w>>h;
            ptr = new doll(h,w);
            decreasing.push_back(*ptr);
        }

        sort(decreasing.begin(),decreasing.end());
        reverse(decreasing.begin(),decreasing.end());

        for(int i=0;i<dollNum;i++){
            int temp = find_less_index(current,decreasing[i].h);
            if(temp==current.size())
                current.push_back(decreasing[i].h);
            else
                current[temp]=decreasing[i].h;
        }


        cout<<current.size()<<endl;
    }

    return 0;
}
