#include "book.h"

Book::Book()
{
}
void Book::sort(){
    file sortProcess;
    QList<QStringList> allBooks=sortProcess.readBookData();

    int idx=0;
    for (int ind=0;ind < allBooks[0].size();ind++) {
        int smallest=100000;
        QString oldbook;
        for(int i=ind;i<allBooks[0].size();i++){

            if (allBooks[4][i].toInt()<smallest){
                smallest=allBooks[4][i].toInt();
                oldbook=allBooks[0][i];
                idx=i;
            }
        }
        allBooks[4][idx]=allBooks[4][ind];
        allBooks[0][idx]=allBooks[0][ind];
        QString smallestString=QString::number(smallest);
        allBooks[4][ind]=smallestString;
        allBooks[0][ind]=oldbook;

    }
    for(int i =0;i<allBooks[0].size();i++){
        qDebug() << "Kitap: " << allBooks[0][i]  << "Yayim Yili: " << allBooks[4][i];

    }

}
void Book::deletingVoid(int idx,int lineidx,QString s){
    QFile file1("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    while (!file1.atEnd()) {
       QString line = file1.readLine();
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
void Book::deleteBook(){
    QFile file("/home/emir/Masaüstü/openCV-exps/denemekitap.txt");
    if(!file.open(QIODevice::ReadWrite)){
        qCritical() << file.errorString();
    }
    QStringList booknames;
    QString s;
    string deletingBookName;

    qDebug()<< "silinicek kitap ismini giriniz: ";
    cin >> deletingBookName;
    QString kitap = QString::fromUtf8(deletingBookName.c_str());
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

    int lineidx=0;
    deletingVoid(idx,lineidx,s);
    qDebug() << idx<< i <<booknames;

       lineidx++;

    }
void Book::displayBook(){
    file displayProcess;
    QList<QStringList> allBooks=displayProcess.readBookData();
    displayProcess.readBookData();

    for(int i=0;i<allBooks[0].size();i++){
        qDebug() <<"isim: "<<allBooks[0][i]<<"yazar: "<<allBooks[1][i]<< "ISBN numarası: "<< allBooks[2][i] << "sayfa sayısı: "<< allBooks[3][i]<<"yayım yılı: "<<allBooks[4][i]<<"anahtar kelimeler:"<<allBooks[5][i];
    }
}
void Book::makeBook(){
    string inputBookName;
    string inputAuthorName;
    string inputIsbnNum;
    int inputPageNum;
    int inputPublishYear;
    string inputKeyword1,inputKeyword2,inputKeyword3;

    qDebug()<< "kitap ismini giriniz: ";
    cin >> inputBookName;
    QString bookName = QString::fromUtf8(inputBookName.c_str());
    qDebug() <<"yazar ismini giriniz: ";
    cin >> inputAuthorName;
    QString authorName = QString::fromUtf8(inputAuthorName.c_str());
    qDebug() << "ISBN NO giriniz: ";
    cin >> inputIsbnNum;
    QString isbnNum = QString::fromUtf8(inputIsbnNum.c_str());

    qDebug() << "sayfa sayısııını giriniz: ";
    cin >> inputPageNum;

    qDebug() << "kitap yilini giriniz: ";
    cin >> inputPublishYear;

    qDebug() << " kitap ile alalkalı 3 tane anahtar kelime giriniz: ";
    cin >> inputKeyword1 >> inputKeyword2 >> inputKeyword3;
    QString Keyword1 = QString::fromUtf8(inputKeyword1.c_str());
    QString Keyword2 = QString::fromUtf8(inputKeyword2.c_str());
    QString Keyword3 = QString::fromUtf8(inputKeyword3.c_str());
    QString Keywords = Keyword1+"-"+Keyword2+"-"+Keyword3;

    file makeBookProcess;
    makeBookProcess.writeBookData(bookName,authorName,isbnNum,inputPageNum,inputPublishYear,Keywords);

    qDebug() << "Kitap Başarı ile Oluşturuldu";
}
void Book::libraryProgram(){
    string input;
    while(true){
        qDebug()<<"Kitap oluşturmak için 'a' giriniz \n Kitap silmek için 'd' giriniz \n Kitapları sıralamak için 's' giriniz\n Kitapları görmek için 'x' giriniz\n çıkış için 'q' giriniz ";
        cin >> input;
        if (input=="a"){
            makeBook();
            continue;
        }
        else if(input=="x"){
            displayBook();
            continue;
        }
        else if (input=="d") {
           deleteBook();
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
