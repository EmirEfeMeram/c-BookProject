#ifndef BOOK_H
#define BOOK_H
#include<QString>
#include<QStringList>
#include<iostream>
#include<fstream>
#include<QFile>
#include<QTextStream>



class Book
{
public:
    Book(QString BookName,QString AuthorName,QString ISBN,int PageNumber,int PublishYear,QStringList Keywords);
    QString BookName;
    QString AuthorName;
    QString ISBN;
    int PageNumbe;
    int PublishYear;
    QStringList Keywords;
};

#endif // BOOK_H
