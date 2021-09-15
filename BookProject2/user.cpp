#include "user.h"

User::User()
{
}
void User::makeUser(){
    string Uname;
    string id;
    string Pass;
    qDebug()<< "üye ismini giriniz: ";
    cin >> Uname;
    QString username = QString::fromUtf8(Uname.c_str());
    qDebug() <<"üye id giriniz: ";
    cin >> id;
    QString idq = QString::fromUtf8(id.c_str());
    qDebug() << "Password Belirleyiniz: ";
    cin >> Pass;
    QString password = QString::fromUtf8(Pass.c_str());
    file fileWriteProcess;
    fileWriteProcess.writeUserData(username,idq,password);
    qDebug() << "Üyeliniğiniz Başarı ile tamamlandı";
}
void User::userLogIn(){
    string username;
    string password;

    qDebug() << "UserName:  \n";
    cin >> username ;
    QString usernameq = QString::fromUtf8(username.c_str());
    qDebug() << "Password:  \n";
    cin >> password;
    QString passwordq = QString::fromUtf8(password.c_str());
    file userLogInProcess;
    QList<QStringList> allUsers = userLogInProcess.readUserData();
    /*QFile file("/home/emir/Masaüstü/openCV-exps/deneme.txt");
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
    }*/
    int i=0;
    for(i=0; i<allUsers[0].size(); i++){

       if(usernameq==allUsers[0][i] && passwordq==allUsers[1][i]){
           Book book;
           qDebug() << "Başarı ile giriş yapıldı";
           book.libraryProgram();

           break;
       }
    }
   string answer;
   qDebug() << "yanlış şifre veya password \n üyelik açmak istermsiiniz? yes/no";
   cin >> answer;
   if(answer=="yes"){
       makeUser();
   }
}
