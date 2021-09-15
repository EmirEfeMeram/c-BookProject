#include "file.h"

file::file()
{

}

QList<QStringList> file::readBookData(){
    QStringList names;
    QStringList authors;
    QStringList ISBNnums;
    QStringList pagenums;
    QStringList publishyears;
    QStringList keywords;
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       names.append(data[0]);
       authors.append(data[1]);
       ISBNnums.append(data[2]);
       pagenums.append(data[3]);
       publishyears.append(data[4]);
       keywords.append(data[5]);
    }
    QList<QStringList> allBooks={names,authors,ISBNnums,pagenums,publishyears,keywords};
    file.flush();
    file.close();

    return allBooks;

}
void file::writeBookData(QString bookName,QString authorName,QString isbnNum,int pageNum,int publishYear,QString keywords){
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream stream(&file);
        stream << bookName <<","<< authorName <<","<< isbnNum <<","<<pageNum<<","<<publishYear <<","<<keywords <<","<<"\r\n";
    }
    file.flush();
    file.close();
}

QList<QStringList> file::readUserData(){
    QFile file("/home/emir/Masaüstü/openCV-exps/deneme.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    QStringList usernames;
    QStringList passwords;
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       usernames.append(data[0]);
       passwords.append(data[2]);
    }
    QList<QStringList> allUsers={usernames,passwords};
    file.flush();
    file.close();
    return allUsers;
}
void file::writeUserData(QString username,QString idq,QString password){
    QFile file("/home/emir/Masaüstü/openCV-exps/deneme.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        file.flush();
        QTextStream stream(&file);
        stream << username <<","<< idq <<","<< password <<","<<"\r\n";
    }
    file.flush();
    file.close();
}
