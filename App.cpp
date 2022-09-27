#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "UnitTests.h"
#include <filesystem>

using std::cout, std::cin, std::endl, std::string, std::vector, std::filesystem::recursive_directory_iterator,
std::fstream;

typedef void (*p_to_func)(string);
void introduction();

vector<string> input_reader(string test = "false");
void interpret(vector<string> );
void list();
void read(string);
void write(string);
void reintroduction();
/*
void open(string);
void create(string);

*/
int main(int argc, char *argv[]){
    bool run = true;
    if (argc > 1 && *argv[1] == 'd'){
        test_input();
    } else {
    introduction();
    vector<string> arguments = input_reader();
    interpret(arguments);
    
    }
    /*while (true){
        vector<string> arguments = input_reader();
        p_to_func p =interpret(arguments);
        (*p)();
        reintroduction();
    }*/
}
void introduction(){
    cout << "Hi, this is a bookkeeping aplication for libraries." << endl;
    cout << "Please, use one of the following commands for the required action:" << endl;
    cout << "list - lists all books available." << endl;
    cout << "read (book) - reads a book." << endl;
    cout << "write (file name) - writes a new file (or overwrites) as a .txt" << endl;
}

void reintroduction(){
    cout << endl << "Your input was not formatted correctly, please try again or type exit to leave." << endl;
}

vector<string> input_reader(string test){
    string in;
    vector<decltype(in.begin())> options_iters;
    if (test != "false"){
        in = test;
    } else {
        getline(cin, in);
    }
    bool flag = true;
    //Finding beginning of parameters and putting iterators on them
    for (int i = 0; i < in.length(); ++i){
        if (flag && in[i] != ' '){
            options_iters.push_back((in.begin() + i));
            flag = false;
        } else if (!flag && in[i] == ' '){
            flag = true;
        }
    }
    //iterating the iterators to get all arguments
    vector <string> output;
    for (decltype(in.begin()) iterator: options_iters){
        string constructor;
        while(iterator != in.end() && *iterator != ' '){
            constructor.push_back(*iterator);
            ++iterator;
        }
        output.push_back(constructor);
    }
    return output;
} 

void interpret(vector<string> arguments){
    int length = arguments.size();
    if (length == 0){
        cout << "No commands where given!" << endl;
        return;
    } else if (arguments[0] == "list") {
        if (length == 1){
            list();
            return;
        } else {
            cout << "list takes no arguments" << endl;
            return;
        }
    } else if (arguments[0] == "read"){
        if (length == 2){
            read(arguments[1]);
            return;
        } else if (length == 1){
            cout << "read needs an argument (name of file)" << endl;
            return;
        } else if (length > 2){
            cout << "too many arguments were given, read takes 1" << endl;
            return;
        }
    } else if (arguments[0] == "write"){
        if (length == 2){
            write(arguments[1]);
        } else if (length == 1){
            cout << "write needs the name of the file" << endl;
        } else if (length > 2){
            cout << "write only takes one argument" << endl;
        }
    }
    /*if (!arguments.empty() && arguments[0] == "list"){
        list();
    } else reintroduction();*/
}

//Functions that go on interpret

void list(){
    cout << endl;
    for (const auto& dir_entry : recursive_directory_iterator("Files")){
        string book = dir_entry.path().string();
        int l = book.length();
        book.erase(l - 4, 4); //Takes away .txt
        book.erase(0, 6); //Takes away Files/
        cout << book << endl;
}
}

void read(string file_text){
    if (file_text.length() < 4 || (file_text.substr(file_text.length() - 4, file_text.length()) != ".txt")){
        file_text = file_text + ".txt";
    }
    string path = "Files/" + file_text;
    fstream file (path);
    string output;
    while (getline(file, output)){
        cout << output << endl;
    }
    file.close();
}

void write(string file_text){
    if (file_text.length() < 4 || (file_text.substr(file_text.length() - 4, file_text.length()) != ".txt")){
        file_text = file_text + ".txt";
    }
    string path = "Files/" + file_text;
    fstream file (path, fstream::out);
    string input;
    while (getline(cin, input)){
        if (input == "END"){
            break;
        }
        file << input << endl;
    }
    file.close();
}

