#include <QCoreApplication>
#include<QObject>
#include<iostream>
#include<fstream>
#include<book.h>
#include<user.h>
#include<QDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QString>
#include <QDir>
#include<QTextStream>
#include<QList>
using namespace std;


int main(int argc, char *argv[])
{

    Book book1;
    //Book book2("LOTR","tolkien","ISBN2000",706,1997,{"gandalf","yüzük","ork"});
    //Book book3("3 silahsorler","alexandre dumas","ISBN3654",103,1784,{"atos","portos","aramis"});
    User user;
    string username;
    string password;
//    readFile("/home/emir/Masaüstü/openCV-exps/deneme.txt");
    //QString str = QString::fromUtf8(selam.c_str());
    while (true) {
        user.uyeGiris();


        }
    QCoreApplication a(argc, argv);

    return a.exec();
    }



