#include "ctpl_stl.h"
#include <iostream>
#include <mutex>
#include <stdio.h>
#include <unistd.h>

using namespace std;

std::mutex mtx;

void cb(int index)
{

    //  std::lock_guard<std::mutex> guard(mtx);
    cout << "[" << index << "] hello, world" << endl;
    sleep(1);
}

int main(int argc, char *argv[])
{
    ctpl::thread_pool pool(4);
    int index = 0;
    while (true)
    {
        pool.push(std::bind(cb, index++));
        usleep(30);
    }

    //   sleep(1000);
}