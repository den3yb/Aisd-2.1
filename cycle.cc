#include "TreeSearch.cpp"
#include <iostream>
#include <time.h>
#include <fstream>


using namespace std;
using namespace spisok;

size_t lcg() {
    static size_t x = 0;
    x = (1021 * x + 24631) % 116640;
    return x;
}

int rand_in(int a, int b) {
    return a + rand() % (b - a);
}


int main() {
    clock_t start_creat, end_create, start_search, end_search, start_addel, end_addel;
    double time_creat, time_search, time_addel;
    double count = 1000;
    ofstream fout;
    fout.open("C:\\Proganiy\\Aisd 4\\Aisd-laba1\\tree_out.txt");
    cout << fout.is_open();
    fout << "hello";
    for (double member = 1000; member < 100001; member=member*10)
    {
        time_creat = 0, time_search = 0, time_addel = 0;
        for (int i = 0; i < count; i++) {
            tree t;
            start_creat = clock();
            for (int j = 0; j < member; j++) {
                t.inseart(lcg());
            }
            end_create = clock();
            time_creat += (double)(end_create - start_creat) / CLOCKS_PER_SEC;
            start_search = clock();
            for (int j = 0; j < member; j++) {
                t.contains(rand_in(0, member));
            }
            end_search = clock();
            time_search += (double)(end_search - start_search) / CLOCKS_PER_SEC;
            start_addel = clock();
            for (int j = 0; j < member; j++) {
                int temp = lcg();
                t.inseart(temp);
                t.erase(temp);
            }
            end_addel = clock();
            time_addel += (double)(end_addel - start_addel) / CLOCKS_PER_SEC;
        }
        if (fout.is_open()) fout << "For " << member << "\n" << "Creating time: " << time_creat / count << "\n";
        if (fout.is_open()) fout << "Searching time: " << time_search / count << "\n" << "Add & delete time: " << time_addel / count << "\n" << "\n";
        cout << "Writing for: " << member << "\n";
    }
    fout.close();
}