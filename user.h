#ifndef USER_H
#define USER_H
#include<QString>
#include<QStringList>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QTextStream>



class User
{
public:
    User(QString UserName,QString UserID,QString Password);
    QString UserName;
    QString UserID;
    QString Password;
};

#endif // USER_H
