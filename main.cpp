#include <QCoreApplication>
#include<QObject>
#include<iostream>
#include<fstream>
#include<book.h>
#include<user.h>
#include<QDebug>
#include <QObject>
#include <QVector>
#include <QFile>
#include <QString>
#include <QDir>
#include<QTextStream>
using namespace std;
void displayKitap(){
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       qDebug() <<"isim: "<<data[0]<<"yazar: "<<data[1]<< "ISBN numarası: "<< data[2] << "sayfa sayısı: "<< data[3]<<"yayım yılı: "<<data[4];

    }

}
void kitapOlustur(){
    string kitapisim;
    string yazarisim;
    string ISBN;
    int sayfa;
    int yil;
    string keyword1,keyword2,keyword3;

    qDebug()<< "kitap ismini giriniz: ";
    cin >> kitapisim;
    QString kitap = QString::fromUtf8(kitapisim.c_str());
    qDebug() <<"yazar ismini giriniz: ";
    cin >> yazarisim;
    QString yazar = QString::fromUtf8(yazarisim.c_str());
    qDebug() << "ISBN NO giriniz: ";
    cin >> ISBN;
    QString isbn = QString::fromUtf8(ISBN.c_str());

    qDebug() << "sayfa sayısııını giriniz: ";
    cin >> sayfa;

    qDebug() << "kitap yilini giriniz: ";
    cin >> yil;

    qDebug() << " kitap ile alalkalı 3 tane anahtar kelime giriniz: ";
    cin >> keyword1 >> keyword2 >> keyword3;
    QString Keyword1 = QString::fromUtf8(keyword1.c_str());
    QString Keyword2 = QString::fromUtf8(keyword2.c_str());
    QString Keyword3 = QString::fromUtf8(keyword3.c_str());
    QStringList Keywords = {Keyword1,Keyword2,Keyword3};

    Book book1(kitap,yazar,isbn,sayfa,yil,Keywords);
    qDebug() << "Kitap Başarı ile Oluşturuldu";
}
void uyeOlustur(){

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
    User user(username,idq,password);
    qDebug() << "Üyeliniğiniz Başarı ile tamamlandı";
}
void library(){

    string input;
    while(true){
        qDebug()<<"Kitap oluşturmak için 'a' giriniz \n Kitap silmek için 'd' giriniz \n Kitapları sıralamak için 's' giriniz\n Kitapları görmek için 'x' giriniz\n çıkış için 'q' giriniz ";
        cin >> input;
        if (input=="a"){
            kitapOlustur();
            continue;
        }
        else if(input=="x"){
            displayKitap();
            continue;
        }
        else if(input=="q"){
            QCoreApplication::quit();
            break;
        }
        else {
            qDebug() << "lütfen geçerli bir işaret giriniz";
        }

    }
}
void uyeGiris(){
    string username;
    string password;

    qDebug() << "UserName:  \n";
    cin >> username ;
    QString usernameq = QString::fromUtf8(username.c_str());
    qDebug() << "Password:  \n";
    cin >> password;
    QString passwordq = QString::fromUtf8(password.c_str());
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
    int i=0;
    for(i=0; i<usernames.size(); i++){

       if(usernameq==usernames[i] && passwordq==passwords[i]){
           qDebug() << "Başarı ile giriş yapıldı";
           library();
           break;
       }
    }
   string answer;
   qDebug() << "yanlış şifre veya password \n üyelik açmak istermsiiniz? yes/no";
   cin >> answer;
   if(answer=="yes"){
       uyeOlustur();
   }

   }



QString writeFile(QString filename){
    QFile file(filename);
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream stream(&file);
        for(int i=0;i<5;i++){
            stream <<QString::number(i) <<"Hello world \r\n";
        }
        QString data = stream.readAll();
        while (!stream.atEnd()) {
           QString line = stream.readLine();
           qDebug() << "read output - " << line;
         }
        return  data;
    }


    file.close();

}

QStringList readFile(QString filename){
    QFile file(filename);
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    //QTextStream stream(&file);
    //QString data = stream.readAll();
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       qDebug() << data[0];
    }
}
int main(int argc, char *argv[])
{

    //Book book1("GoT","g rr martin","ISBN2021",900,2011,{"dragon","john snow","stark","joffrey"});
    //Book book2("LOTR","tolkien","ISBN2000",706,1997,{"gandalf","yüzük","ork"});
    //Book book3("3 silahsorler","alexandre dumas","ISBN3654",103,1784,{"atos","portos","aramis"});
    string username;
    string password;
//    readFile("/home/emir/Masaüstü/openCV-exps/deneme.txt");
    //QString str = QString::fromUtf8(selam.c_str());
    while (true) {
        uyeGiris();


        }
    QCoreApplication a(argc, argv);

    return a.exec();
    }


/*QFile f(...);
if (f.open(QIODevice::WriteOnly | QIODevice::Append)) {
 while (!file.atEnd()) {
    QByteArray line = file.readLine();
    qDebug() << "read output - " << line;
  }
}*/
