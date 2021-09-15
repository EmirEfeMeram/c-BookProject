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
using namespace std;


class Book
{
public:
    Book();
    void sort();
    void kitapsil(int idx,int lineidx,QString s);
    void deleteKitap();
    void displayKitap();
    void kitapOlustur();
    void library();

private:
    QString BookName;
    QString AuthorName;
    QString ISBN;
    int PageNumbe;
    int PublishYear;
    QStringList Keywords;
};

#endif // BOOK_H
