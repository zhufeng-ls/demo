#include "ThreadPool.h"
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
    usleep(50);
}

int main(int argc, char *argv[])
{
    ThreadPool pool(4);
    int index = 0;
    while (index < 100)
    {
        pool.enqueue(cb, index++);
        usleep(30);
    }

    //  sleep(1000);
}