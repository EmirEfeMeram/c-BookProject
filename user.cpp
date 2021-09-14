#include "user.h"

User::User(QString UserName,QString UserID,QString Password):UserName(UserName),UserID(UserID),Password(Password)
{
    QFile file("/home/emir/Masaüstü/openCV-exps/deneme.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        file.flush();
        QTextStream stream(&file);
        stream << UserName <<","<< UserID <<","<< Password<<","<<"\r\n";
    }
    file.flush();
    file.close();
}
