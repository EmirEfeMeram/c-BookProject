#include "book.h"

Book::Book()
{
}
void Book::sort(){
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    QList<int> years={};
    QStringList names;
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       names.append(data[0]);
       years.append(data[4].toInt());
    }

    int idx=0;
    for (int ind=0;ind < names.size();ind++) {
        int smallest=100000;
        QString eskikitap;
        for(int i=ind;i<names.size();i++){

            if (years[i]<smallest){
                smallest=years[i];
                eskikitap=names[i];
                idx=i;
            }
        }
        years[idx]=years[ind];
        names[idx]=names[ind];
        years[ind]=smallest;
        names[ind]=eskikitap;

    }
    for(int i =0;i<names.size();i++){
        qDebug() << "Kitap: " << names[i]  << "Yayim Yili: " << years[i];

    }

}
void Book::kitapsil(int idx,int lineidx,QString s){
    QFile file1("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    while (!file1.atEnd()) {
       QString line = file1.readLine();
       qDebug() <<line;
       if(idx==lineidx){
           if(!line.contains("DELETE")){
                s.append(line + "\n");
                qDebug() << "Kitap Başarı ile Silindi";
           }
           else {
               qDebug() << "Böyle Bir Kitap Yok";
           }
       }
       file1.close();
 }
}
void Book::deleteKitap(){
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    QStringList booknames;
    QString s;
    string silkitap;

    qDebug()<< "silinicek kitap ismini giriniz: ";
    cin >> silkitap;
    QString kitap = QString::fromUtf8(silkitap.c_str());
    while (!file.atEnd()) {
       QString line = file.readLine();
       QStringList data;
       data = line.split(",");
       booknames.append(data[0]);}
    file.close();
    int i=0;
    int idx=0;
    for(i=0; i<booknames.size(); i++){

       if(kitap==booknames[i]){
           idx=i;
       }
    }
    qDebug() << idx<< i <<booknames;
    int lineidx=0;
    kitapsil(idx,lineidx,s);

       lineidx++;

    }
void Book::displayKitap(){
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
void Book::kitapOlustur(){
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
    QString Keywords = Keyword1+","+Keyword2+","+Keyword3;


    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(file.open(QIODevice::ReadWrite | QIODevice::Append)){
        QTextStream stream(&file);
        stream << kitap <<","<< yazar <<","<< isbn <<","<<sayfa<<","<<yil <<","<<Keywords <<","<<"\r\n";
    }
    file.flush();
    file.close();
    qDebug() << "Kitap Başarı ile Oluşturuldu";
}
void Book::library(){
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
        else if (input=="d") {
            deleteKitap();
            continue;

        }
        else if (input=="s") {
            sort();

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
