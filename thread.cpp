#include <QCoreApplication>
#include <iostream>
#include<QList>
#include<QDebug>
#include<QMutex>
#include<thread>
using namespace std;

int buffer[10];
int counter = 0;
 QMutex mutex;


void producer(){
    while(true){
        int product = rand() % 100;

        mutex.lock();
        buffer[counter] = product;
        counter++;
        cout << "Thread ID: "<<this_thread::get_id()<<endl;
        mutex.unlock();

    }

}

void consumer(){
    while (true) {
        int consuming;

        mutex.lock();
        consuming = buffer[counter-1] * 2;
        counter--;
        cout << "Consume Thread ID: "<<this_thread::get_id()<<endl;
        qDebug() << "Consumer sayisi: "<< consuming;
        mutex.unlock();
    }

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    thread producer_thread(producer);
    thread consumer_thread(consumer);

//    producer_thread.join();
//    consumer_thread.join();

    producer_thread.detach();
    consumer_thread.detach();

    return a.exec();
}
