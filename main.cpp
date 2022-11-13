#include <iostream>
#include <fstream>
#include <regex>

int main() {
    // filestream variable file
    std::fstream file;
    std::string word, t, q, filename;
    std::string alice= "";

    // filename of the file
    filename = "../alice.txt";

    // opening file
    file.open(filename.c_str());

    // extracting words from the file
    while (file >> word)
    {
        std::transform(word.begin(),word.end(),word.begin(),::tolower);
        alice = alice + "\\s" + word;
    }

    std::fstream instructions;
    instructions.open("../stoerung0.txt");
   std::string build;
    while (instructions >> word) {
        if(word != "_" ){
            build = build  + word + "\\s" ;
        }
        else{
            build = build + "[a-z,!.]+\\s";
        }
    }
    std::cout << build;
    std::regex find(build);
    std::smatch m;
    std::regex_search(alice,m,find);
    std::cout<< m.size();
    std::cout<<"String that matches the pattern:"<<std::endl;
    for (auto x : m)
        std::cout << x << " ";
    return 0;
}

