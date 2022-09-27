#include "UnitTests.h"
#include <string>
#include <vector>
#include <iostream>
using std::string, std::vector, std::cout, std::endl;

void test_input(){
    vector<string> list = input_reader(" in out meme true   fizz buzz lol cat a c  d 1 2 3 4 5 6 7 8 9 0 10 L O L LOL   ");
    vector<string> result{"in", "out" ,"meme", "true" ,"fizz", "buzz", "lol", "cat", "a", "c", "d" ,"1" ,"2" ,"3" ,"4" ,"5" ,"6"
     ,"7" ,"8" ,"9" ,"0" ,"10" ,"L" ,"O" ,"L" ,"LOL"};
    decltype(result.begin()) iterator = result.begin();
    for(string &a : list){
        if (a != *iterator){
            cout << "input_reader : Fail!" << endl;
            return;
        }
        ++iterator;
    }
    vector<string> list2 = input_reader("    ");
    if (!list2.empty()){
        cout << "input_reader : Fail!" << endl;
        return;
    }
    cout << "input_reader : Sucess!" << endl;
}
