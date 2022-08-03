#include "log.h"
#include <windows.h>

#include <iostream>
#include <fstream>


//using namespace std;
//void write_text_to_log_file( const std::string &text )
//{
//    std::ofstream log_file(
//        "log_file.txt", std::ios_base::out | std::ios_base::app );
//    log_file << text;
//    std::cout << endl;
//}
int main()
{
    SetConsoleOutputCP(65001);//chỉ cho output là unicode, input thì éo.Chỉ dùng cho ghi log
    
    LOG("this is a simple hế lố");
    LOG_W("this is a Warning tag");
    LOG_I("\
        this is a info log");
    LOG_D("this is a debug tag");
    LOG_E("this is a error tag");
    /*write_text_to_log_file("Hom nayy toi bion\n fdadhfldf \
     ");*/

    return 0;
}