#ifndef USER_H
#define USER_H
#include <QCoreApplication>
#include<QObject>
#include<iostream>
#include<fstream>
#include<book.h>
#include<QDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QString>
#include <QDir>
#include<QTextStream>
#include<QList>
#include<book.h>
using namespace std;



class User
{
public:
    User();
    void uyeOlustur();
    void uyeGiris();

private:
    QString UserName;
    QString UserID;
    QString Password;
};

#endif // USER_H
