#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int equalStacks(vector<int> h1, vector<int> h2, vector<int> h3) {    
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;

    for (int i = 0; i < h1.size(); i++) {
        s1+=h1[i];
    }

    for (int i = 0; i < h2.size(); i++) {
        s2+=h2[i];
    }

    for (int i = 0; i < h3.size(); i++) {
        s3+=h3[i];
    }
    while (s1 > 0 && s2 > 0 && s3 > 0) {
        if (s1 == s2 && s2 == s3) {
            printf("Found value = ");
            return s1;
        }
        
        if (s2 > s1) {
            s2 -= h2[0];
            h2.erase(h2.begin());
            printf("--h2 s1 = %d\ts2 = %d\t s3 = %d\n", s1, s2, s3);
        }

        if (s3 > s1) {
            s3-=h3[0];
            h3.erase(h3.begin());
            printf("--h3 s1 = %d\ts2 = %d\t s3 = %d\n", s1, s2, s3);
        }

        if (s1 > s2 || s1 > s3) {
            s1-=h1[0];
            h1.erase(h1.begin());
            printf("--h1 s1 = %d\ts2 = %d\t s3 = %d\n", s1, s2, s3);
        }
    }

    return 0;
}

int main() {
    ifstream file("test2.txt");
    int n1;
    int n2;
    int n3;

    file >> n1 >> n2 >> n3;
    printf("get n1 n2 n3 success...\n");
    vector<int> h1, h2, h3;
    
    for (int i = 0; i < n1; i++) {
        int a;
        file >> a;
        h1.push_back(a);
    }
    printf("get h1 success...\n");
    
    for (int i = 0; i < n2; i++) {
        int a;
        file >> a;
        h2.push_back(a);
    }
    printf("get h2 success...\n");

    for (int i = 0; i < n3; i++) {
        int a;
        file >> a;
        h3.push_back(a);
    }
    printf("get h3 success...\n");
    
    cout<<equalStacks(h1, h2, h3)<<"\n";
    return 0;
}


