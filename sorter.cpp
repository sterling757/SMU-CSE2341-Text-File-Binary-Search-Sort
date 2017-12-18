#include "sorter.h"
#include <chrono>

Sorter::Sorter() : alg(){

}

void Sorter::sort(){
    cout << "Sorting..." << endl;
    std::chrono::high_resolution_clock::time_point t1 = std::chrono::high_resolution_clock::now();
    alg.sortLength(s_ptr, 0, totalWords);
    std::chrono::high_resolution_clock::time_point t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << duration << " milliseconds" << endl;

    t1 = std::chrono::high_resolution_clock::now();
    alg.sortString(s_ptr, 0, totalWords);
    t2 = std::chrono::high_resolution_clock::now();
    duration = std::chrono::duration_cast<std::chrono::milliseconds>( t2 - t1 ).count();
    std::cout << duration << " milliseconds" << endl;
}

void Sorter::readInput(char* input_file){

    ifstream inFile(input_file);
    ifstream inFile2(input_file);

    //checks if dictFile isnt opening
    if (!inFile){
        cerr << input_file << "HOUSTON WE HAVE A PROBLEM!!" << endl;
        return;
    }

    char c = ' ';
    totalWords = 0;
    while(inFile.get(c)){ // whileloop to get line count (aka size of dictionary)
        if(c == '\n'){
            totalWords++;
        }
    }
    inFile.close();
    s_ptr = new dsString*[totalWords];

    dsString line;
    int i = 0;
    char buffer[80] ={0};

    //while the file isnt at the end
    while(!inFile2.eof() && i < totalWords){
        inFile2 >> buffer;
        s_ptr[i] = new dsString(buffer);
        i++;
    }

    inFile2.close();
}

void Sorter::writeOutput(char* output_file){
    ofstream outFile(output_file);

    if (!outFile)
        cout << output_file << " COULD NOT BE OPENED" << endl;

    for(int i = 0; i < totalWords; i++){
        outFile << *(s_ptr[i]) << '\n';
    }

    outFile << endl;
    outFile.close();
}


Sorter::~Sorter(){
    for(int i = 0; i < totalWords; i++){
        delete s_ptr[i];
    }
    delete[] s_ptr;
}
