#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <iterator>
#include <math.h>
#include <ctime>
#include <sys/time.h>

using namespace std;

set<string> query;

int read_bitmap(){
    ifstream fin;
    string filename = "bitmap.txt";
    fin.open(filename.c_str());
    int vidnum,size;
    fin >> vidnum >> size;
    string term;
    unsigned long long tmp;
    unsigned long long *mask=(unsigned long long *) malloc (size*sizeof(unsigned long long));
    for (int i=0;i<size;i++){
        for (int j=0;j<64;j++){
            unsigned long long u = 1;
            u <<= j;
            mask[i]|=u;
        }
    }
    while (fin >> term){
        int flag=0;
        if (query.find(term)!=query.end())
            flag=1;
        for (int i=0;i<size;i++){
            fin>>tmp;
            if (flag)
                mask[i]&=tmp;
        }
    }
    fin.close();

    ofstream fout;
    fout.open("vidlist.txt");
    for (int i=0; i<=size; i++){
        for (int j=0; j<64;j++){
            if (i*64+j<vidnum){
                unsigned long long u = 1;
                u <<= j;
                if (mask[i] & u)
                    fout << i*64+j <<" ";
            }
        }
    }
    fout.close();
    return 0;
}

int main(int argc, char** argv){
    if (argc <=2){
        cout << "need at least 2 terms" << endl;
        exit(1);
    }

    for (int i=1; i<argc; i++){
        string term = argv[i];
        query.insert(term);
    }

    read_bitmap();
    return 0;
}
