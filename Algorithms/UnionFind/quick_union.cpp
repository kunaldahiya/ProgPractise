#include <iostream>
#include <fstream>
using namespace std;

/* Maintain a data array with parent as value
- find: in same set if root of both are same
- union: change root of first set as second 
*/

class QuickUnion{
    public:
        QuickUnion(int);
        ~QuickUnion();
        int num;
        void _union(int, int);
        bool _find(int, int);
        int _root(int);
        void display();
    private:
        int* data;
};

QuickUnion::~QuickUnion(){
    free(data);
}


QuickUnion::QuickUnion(int p){
    num = p;
    data = (int*) malloc(num*sizeof(int));
    for(int i=0; i<num; i++){
        data[i] = i;
    }
}

int QuickUnion::_root(int p){
    int temp = p;
    while(data[temp] != temp){
        temp = data[temp];
    }
    return temp;
}

void QuickUnion::display(){
    for(int i=0; i<num; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

bool QuickUnion::_find(int p, int q){
    bool status;
    if(_root(p) == _root(q)){
        status = true;
    }else{
        status = false;
    }
    return status;
}

void QuickUnion::_union(int p, int q){
    bool status = _find(p, q);
    if(!status){
        // cout << "In different tree: "<< p <<" " <<q<<endl;
        // cout << "Making " << p <<" as parent of " << q <<endl;
        data[_root(q)] = _root(p);
    }
}

int main(int argc, char * argv[]){
    int num_lines, src, dest;
    ifstream infile;
    infile.open("tinyUF.txt");

    if (!infile) {
        cout << "Unable to open file";
        exit(1);
    }
    infile >> num_lines;
    QuickUnion qu = QuickUnion(num_lines);
    for(int i=0; i<num_lines; i++){
        infile >> src >> dest;
        qu._union(src, dest);
        qu.display();
    }
    infile.close();
    return 0;
}
