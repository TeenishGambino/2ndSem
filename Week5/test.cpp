#include<boost/thread.hpp>
#include<thread>
#include <iostream>    //std::cout std::endl
#include <thread>      //std::thread
#include <future>      //std::future std::promise
#include <utility>     //std::ref
#include <chrono>      //std::chrono::seconds


using namespace std;


void run_tests(){
    system("/home/baldish/Desktop/ADS/2ndSem/Week5/fib");
}
/*
int main(){
    boost::thread test_thread(&run_tests);

    if(test_thread.try_join_for(boost::chrono::seconds(1))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
*/

int main()
{
    boost::thread test_thread(&run_tests);

    if(test_thread.try_join_for(boost::chrono::seconds(1))){
        cout<<"Yes"<<endl;
    }
    else{
        cout<<"No"<<endl;
    }
}
