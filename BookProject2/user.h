#ifndef USER_H
#define USER_H
#include <QCoreApplication>
#include<QObject>
#include<iostream>
#include<fstream>
#include<book.h>
#include<file.h>
#include<QDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QString>
#include <QDir>
#include<QTextStream>
#include<QList>
using namespace std;



class User
{
public:
    User();
    void makeUser();
    void userLogIn();

private:
    QString UserName;
    QString UserID;
    QString Password;
};

#endif // USER_H
