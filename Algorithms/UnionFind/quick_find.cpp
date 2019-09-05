#include <iostream>
#include <fstream>
using namespace std;

/*Maintain a array with value as set id
- find: if values are same i.e. same id of set
- union: change value of one set if they are in different set
*/

class QuickFind{
    public:
        QuickFind(int);
        ~QuickFind();
        int num;
        void _union(int, int);
        bool _find(int, int);
        void display();
    private:
        int* data;
};

QuickFind::~QuickFind(){
    free(data);
}

QuickFind::QuickFind(int p){
    num = p;
    data = (int*) malloc(num*sizeof(int));
    for(int i=0; i<num; i++){
        data[i] = i;
    }
}

void QuickFind::display(){
    for(int i=0; i<num; i++){
        cout << data[i] << " ";
    }
    cout << endl;
}

bool QuickFind::_find(int p, int q){
    bool status;
    if(data[p] == data[q]){
        status = true;
    }else{
        status = false;
    }
    return status;
}

void QuickFind::_union(int p, int q){
    bool status = QuickFind::_find(p, q);
    int src, dest;
    src = data[p];
    dest = data[q];
    if(!status){
        for(int i=0; i<num; i++){
            if(data[i]==src){
                data[i] = dest;
            }
        }
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
    QuickFind qf = QuickFind(num_lines);
    for(int i=0; i<num_lines; i++){
        infile >> src >> dest;
        qf._union(src, dest);
        qf.display();
    }
    infile.close();
    return 0;
}
