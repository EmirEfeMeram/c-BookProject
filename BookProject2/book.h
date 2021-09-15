#ifndef BOOK_H
#define BOOK_H
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
#include<file.h>
using namespace std;


class Book
{
public:
    Book();
    void sort();
    void deletingVoid(int idx,int lineidx,QString s);
    void deleteBook();
    void displayBook();
    void makeBook();
    void libraryProgram();

private:
    QString BookName;
    QString AuthorName;
    QString ISBN;
    int PageNumbe;
    int PublishYear;
    QStringList Keywords;
};

#endif // BOOK_H
