#ifndef FILE_H
#define FILE_H
#include <QCoreApplication>
#include<QObject>
#include<iostream>
#include<fstream>
#include<QDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QString>
#include <QDir>
#include<QTextStream>
#include<QList>

class file
{
public:
    file();
    QList<QStringList> readUserData();
    void writeUserData(QString username,QString idq,QString password);
    QList<QStringList> readBookData();
    void writeBookData(QString bookName,QString authorName,QString isbnNum,int pageNum,int publishYear,QString keywords);
};

#endif // FILE_H
