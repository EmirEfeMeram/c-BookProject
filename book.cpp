#include "book.h"

Book::Book(QString BookName,QString AuthorName,QString ISBN,int PageNumber,int PublishYear,QStringList Keywords):BookName(BookName),AuthorName(AuthorName),ISBN(ISBN),PageNumbe(PageNumber),PublishYear(PublishYear),Keywords(Keywords)
{
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream stream(&file);
        stream << BookName <<","<< AuthorName <<","<< ISBN <<","<<PageNumber<<","<<PublishYear <<","<<"\r\n";
    }
    file.flush();
    file.close();
}
