/****************************************************************************
**					           SAKARYA ÜNİVERSİTESİ
**			         BİLGİSAYAR VE BİLİŞİM BİLİMLERİ FAKÜLTESİ
**				          BİLGİSAYAR MÜHENDİSLİĞİ BÖLÜMÜ
**				           PROGRAMLAMAYA GİRİŞİ DERSİ
**
**				ÖDEV NUMARASI…...:1
**		        ÖĞRENCİ ADI......:MUHAMMED ALİ TOPRAK
**				ÖĞRENCİ NUMARASI.:B221210053
**				DERS GRUBU.......:1.ÖĞRETİM B
****************************************************************************/

#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

//Structlar ve değişkenler

struct Tarih {
    int gun=0;
    int ay=0;
    int yıl=0;

};

struct Ogrenci{
    string isim;
    string soyisim;
    int no;

    float kisasinav1;
    float kisasinav2;
    float odev1;
    float odev2;
    float proje;
    float vize;
    float final;
    Tarih tarih;
};


string arrIsim[30] = {  "Ahmet","Mehmet","Ali","Asım","Kasım","Enes","Mete","Adem","Muhammed","Alperen",
                        "Burak","Batu","Can","Cem","Orkun","Zehra","Hanne","Kübra","Necla","Ayşe",
                        "Fatma","Oya","Pelin","Ravza","Safiye","Seda","Sema","Türkan","Beyza","Betül"};

string arrSoyisim[30] = { "Demir","Çelik","Yıldız","Aslan","Korkmaz","Koç","Özgür","Öztürk","Toprak","Ateş",
                          "Kara","Çiftçi","Çevik","Yücel","Varol","Işık","Kaya","Hun","Yüksel","Kılıç",
                          "Bulut","Öz","Yılmaz","Çetin","Uzun","Sert","Aydın","Şahin","Köylü","Kaplan"};

Ogrenci arrOgrenci[100];

//fonksiyonlar

int rastgeleSayi(int min, int max){
    int output;
    output = min + (rand() % ( max- min + 1));
    return output;
}

void harf(){}

float kontrol( string notcesidi)
{
    float puan;
    do
    {
        cout << notcesidi << " notunu giriniz: "; cin >> puan;
        if (!(puan >= 0 && puan <= 100)) {
            cout << "Lütfen 0 ile 100 arasında değer giriniz!\n";
        }
    } while (!(puan >= 0 && puan <= 100));
    return puan;
}

double basarıNotu(int diziSira) {
    double yılIci = arrOgrenci[diziSira].vize * 50.0 / 100 + arrOgrenci[diziSira].kisasinav1 * 7.0 / 100 + arrOgrenci[diziSira].kisasinav2 * 7.0 / 100
                    + arrOgrenci[diziSira].odev1 * 10.0 / 100 + arrOgrenci[diziSira].odev2 * 10.0 / 100 + arrOgrenci[diziSira].proje * 16.0 / 100;

    return (yılIci * 55.0 / 100) + (arrOgrenci[diziSira].final*45.0/100);
}

void enYuksekNot(){
    double enYuksek;

    for (int i = 0; i<(sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {

        if (i == 0) {
            enYuksek = basarıNotu(i);
        }

        if (basarıNotu(i) > enYuksek)
            enYuksek = basarıNotu(i);

    }

    cout << enYuksek << endl;
}

void enDusukNot() {
    double enDusuk;
    for (int i = 0; i<(sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {

        if (i == 0) {
            enDusuk = basarıNotu(i);
        }

        if (basarıNotu(i) < enDusuk)
            enDusuk = basarıNotu(i);

    }

    cout << enDusuk << endl;
}

void sinifListesi() {
    system("cls");
    for (int i = 0; i<(sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {
        cout << i + 1 << ") " << arrOgrenci[i].isim << " " << arrOgrenci[i].soyisim << " " << arrOgrenci[i].no << endl;
        if (i == 19 || i == 39 || i == 59 || i == 79) {
            system("pause");
            system("cls");
        }

    }

}

double sinifOrt() {
    double toplam = 0;
    double ort = 0;
    for (int i = 0; i < (sizeof(arrOgrenci) / sizeof(Ogrenci));i++) {
        toplam += basarıNotu(i);
        }
    ort = toplam / (sizeof(arrOgrenci) / sizeof(Ogrenci));

    return ort;
}

double standartSapma(){
    long double farkToplamı = 0;
    double standartSapma;
    for (int i = 0; i < (sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {
        farkToplamı += (sinifOrt() - basarıNotu(i)) * (sinifOrt() - basarıNotu(i));

    }
    standartSapma = sqrtl((farkToplamı - 1) / ((sizeof(arrOgrenci) / sizeof(Ogrenci)) - 1));

    return  standartSapma;
}

void aralık() {

    double birinciDeger;
    double ikinciDeger;
    do{
        cout << "bir aralık belirtmek için 2 değer giriniz." << endl;
        cout << "1. değeri giriniz: " << endl;
        cin >> birinciDeger;
        cout << "2. değeri giriniz: " << endl;
        cin >> ikinciDeger;
        if (!(birinciDeger >= 0 && birinciDeger <= 100 && ikinciDeger>=0 && ikinciDeger <= 100))
        {
            cout << "Lütfen 0 ile 100 arasında değerler giriniz";
        }
    } while (!(birinciDeger >= 0 && birinciDeger <= 100 && ikinciDeger >= 0 && ikinciDeger <= 100));

    if (birinciDeger > ikinciDeger) {
        int tutucu;
        tutucu = ikinciDeger;
        ikinciDeger = birinciDeger;
        birinciDeger = tutucu;
    }
    for (int i = 0; i < (sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {
        if (basarıNotu(i) >= birinciDeger && basarıNotu(i) <= ikinciDeger) {
            cout <<i+1<<") "<< arrOgrenci[i].isim << " " << arrOgrenci[i].soyisim << " " << arrOgrenci[i].no << " " << basarıNotu(i) << endl;
        }

    }

}

void kucukAralık() {
    int aralik;
    do {
        cout << "başarı notu hangi değerin altında olan öğrencilerin gösterileceğini giriniz: ";
        cin >> aralik;
        if (aralik < 0 || aralik>100) {
            cout << "lütfen 0 ile 100 arasında değer giriniz";
            cin >> aralik;
        }
    } while (aralik < 0 || aralik>100);
    for (int i = 0; i < (sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {
        if (basarıNotu(i) <= aralik) {
            cout << arrOgrenci[i].isim << " " << arrOgrenci[i].soyisim << " " << basarıNotu(i) << endl;
        }
    }
}

void buyukAralık() {
    int aralik;
    do {
        cout << "başarı notu hangi değerin üstünde olan öğrencilerin gösterileceğini giriniz: ";
        cin >> aralik;
        if (aralik < 0 || aralik>100) {
            cout << "lütfen 0 ile 100 arasında değer giriniz";
            cin >> aralik;
        }
    } while (aralik < 0 || aralik>100);

    for (int i = 0; i < (sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {
        if (basarıNotu(i) >= aralik) {
            cout << arrOgrenci[i].isim << " " << arrOgrenci[i].soyisim << " " << basarıNotu(i) << endl;
        }
    }
}

int main()
{
    system("cls");
    srand(time(NULL));
    setlocale(LC_ALL, "Turkish");

    cout << "\t\t\t___________________________________________________________________________\n\n\n";
    cout << "\t\t\t                           HOŞGELDİNİZ                        \n\n\n";
    cout << "\t\t\t RASTGELE OLUŞTURMAK VE NOT VERMEK İÇİN 1'E BASIN\n\n";
    cout << "\t\t\t MANUEL OLARAK DEĞERLERİ GİRMEK İÇİN 2'YE BASIN\n\n";
    cout << "\t\t\t SINIF LİSTESİNE BAKMAK İÇİN 3'E BASIN\n\n";
    cout << "\t\t\t SINIFIN EN YÜKSEK BAŞARI NOTUNA BAKMAK İÇİN 4'E BASIN\n\n";
    cout << "\t\t\t SINIFIN EN DÜŞÜK BAŞARI NOTUNA BAKMAK İÇİN 5'E BASIN\n\n";
    cout << "\t\t\t SINIFIN ORTALAMA BAŞARI PUANINA BAKMAK İÇİN 6'YA BASIN\n\n";
    cout << "\t\t\t SINIFIN STANDART SAPMASINA BAKMAK İÇİN 7'YE BASIN\n\n";
    cout << "\t\t\t BAŞARI NOTU BELİRLİ BİR ARALIKTA OLANLARA BAKMAK İÇİN 8'E BASIN\n\n";
    cout << "\t\t\t BAŞARI NOTU BELİRLİ BİR DEĞERİN ALTINDA OLANLARA BAKMAK İÇİN 9'A BASIN\n\n";
    cout << "\t\t\t BAŞARI NOTU BELİRLİ BİR DEĞERİN ÜSTÜNDE OLAN ÖĞRENCİLERE BAKMAK İÇİN 10'A BASIN\n\n";
    cout << "\t\t\t ÇIKMAK İÇİN 11'E BASIN\n\n";
    int secim;
    cin >> secim;

    enum Menu1 { rastgele = 1, manuel, sinifListe, enYuksek, enDusuk, sinifOrtalama, sinifStdSapma ,aralik,aralikKucuk, aralikBuyuk, cikis };
    //Kullanıcının verilen değerler arasında seçim yapıp yapmadığını ve hangi seçimi yaptığını kontrol ediyor
    do {



        if (secim == Menu1::rastgele) {
            for (int i = 0; i< (sizeof(arrOgrenci) / sizeof(Ogrenci)); i++) {

                arrOgrenci[i].isim = arrIsim[rastgeleSayi(0, 29)];

                arrOgrenci[i].soyisim = arrSoyisim[rastgeleSayi(0, 29)];

                arrOgrenci[i].no = rastgeleSayi(1, 100);

                for (int i = 0; i < 10; i++) {
                    arrOgrenci[i].kisasinav1 = rastgeleSayi(0, 40);
                    arrOgrenci[i].kisasinav2 = rastgeleSayi(0, 40);
                    arrOgrenci[i].odev1 = rastgeleSayi(0, 40);
                    arrOgrenci[i].odev2 = rastgeleSayi(0, 40);
                    arrOgrenci[i].proje = rastgeleSayi(0, 40);
                    arrOgrenci[i].vize = rastgeleSayi(0, 40);
                    arrOgrenci[i].final = rastgeleSayi(0, 40);

                    arrOgrenci[i].tarih.gun = rastgeleSayi(0, 30);
                    arrOgrenci[i].tarih.ay = rastgeleSayi(0, 12);
                    arrOgrenci[i].tarih.yıl = rastgeleSayi(2022, 2022);
                }
                for (int i =10 ; i < 60; i++) {
                    arrOgrenci[i].kisasinav1 = rastgeleSayi(40, 70);
                    arrOgrenci[i].kisasinav2 = rastgeleSayi(40, 70);
                    arrOgrenci[i].odev1 = rastgeleSayi(40, 70);
                    arrOgrenci[i].odev2 = rastgeleSayi(40, 70);
                    arrOgrenci[i].proje = rastgeleSayi(40, 70);
                    arrOgrenci[i].vize = rastgeleSayi(40, 70);
                    arrOgrenci[i].final = rastgeleSayi(40, 70);

                    arrOgrenci[i].tarih.gun = rastgeleSayi(0, 30);
                    arrOgrenci[i].tarih.ay = rastgeleSayi(0, 12);
                    arrOgrenci[i].tarih.yıl = rastgeleSayi(2002, 2004);
                }
                for (int i = 60; i < 75; i++) {
                    arrOgrenci[i].kisasinav1 = rastgeleSayi(70, 80);
                    arrOgrenci[i].kisasinav2 = rastgeleSayi(70, 80);
                    arrOgrenci[i].odev1 = rastgeleSayi(70, 80);
                    arrOgrenci[i].odev2 = rastgeleSayi(70, 80);
                    arrOgrenci[i].proje = rastgeleSayi(70, 80);
                    arrOgrenci[i].vize = rastgeleSayi(70, 80);
                    arrOgrenci[i].final = rastgeleSayi(70, 80);

                    arrOgrenci[i].tarih.gun = rastgeleSayi(0, 30);
                    arrOgrenci[i].tarih.ay = rastgeleSayi(0, 12);
                    arrOgrenci[i].tarih.yıl = rastgeleSayi(2002, 2004);
                }
                for (int i = 60; i < 75; i++) {
                    arrOgrenci[i].kisasinav1 = rastgeleSayi(70, 80);
                    arrOgrenci[i].kisasinav2 = rastgeleSayi(70, 80);
                    arrOgrenci[i].odev1 = rastgeleSayi(70, 80);
                    arrOgrenci[i].odev2 = rastgeleSayi(70, 80);
                    arrOgrenci[i].proje = rastgeleSayi(70, 80);
                    arrOgrenci[i].vize = rastgeleSayi(70, 80);
                    arrOgrenci[i].final = rastgeleSayi(70, 80);

                    arrOgrenci[i].tarih.gun = rastgeleSayi(0, 30);
                    arrOgrenci[i].tarih.ay = rastgeleSayi(0, 12);
                    arrOgrenci[i].tarih.yıl = rastgeleSayi(2002, 2004);
                }
                for (int i = 75; i < 100; i++) {
                    arrOgrenci[i].kisasinav1 = rastgeleSayi(80, 100);
                    arrOgrenci[i].kisasinav2 = rastgeleSayi(80, 100);
                    arrOgrenci[i].odev1 = rastgeleSayi(80, 100);
                    arrOgrenci[i].odev2 = rastgeleSayi(80, 100);
                    arrOgrenci[i].proje = rastgeleSayi(80, 100);
                    arrOgrenci[i].vize = rastgeleSayi(80, 100);
                    arrOgrenci[i].final = rastgeleSayi(80, 100);

                    arrOgrenci[i].tarih.gun = rastgeleSayi(0, 30);
                    arrOgrenci[i].tarih.ay = rastgeleSayi(0, 12);
                    arrOgrenci[i].tarih.yıl = rastgeleSayi(2002, 2004);
                }
            }
            cout << "Rastgele atama başarılı" << endl;
            system("pause");
            main();
        }

        else if (secim == Menu1::manuel) {
            system("CLS");
            int ogrencisecimi;
            char yeni_ekle = 'y';

            do {
                cout << "hangi sıradaki öğrencinin bilgilerini gireceğinizi yazınız(1 ile 100 arasında): ";
                cin >> ogrencisecimi;

                while (ogrencisecimi > (sizeof(arrOgrenci) / sizeof(Ogrenci)) || ogrencisecimi < 1) {
                    cout << "Lütfen geçerli bir öğrenci seçiniz" << endl;
                    cin >> ogrencisecimi;
                }


                cout << ogrencisecimi << ". öğrencinin adını giriniz:  ";
                cin >> arrOgrenci[ogrencisecimi - 1].isim;

                cout << ogrencisecimi << ". öğrencinin soyadını giriniz:  ";
                cin >> arrOgrenci[ogrencisecimi - 1].soyisim;

                cout << ogrencisecimi << ". öğrencinin numarasını giriniz:  ";
                cin >> arrOgrenci[ogrencisecimi - 1].no;

                arrOgrenci[ogrencisecimi - 1].kisasinav1 = kontrol("1. kısa sınav");

                arrOgrenci[ogrencisecimi - 1].kisasinav2 = kontrol("2.kısa sınav");

                arrOgrenci[ogrencisecimi - 1].odev1 = kontrol("1.ödev");

                arrOgrenci[ogrencisecimi - 1].odev2 = kontrol("2.ödev");

                arrOgrenci[ogrencisecimi - 1].proje = kontrol("proje");

                arrOgrenci[ogrencisecimi - 1].vize = kontrol("vize");

                arrOgrenci[ogrencisecimi - 1].final = kontrol("final");

                cout << "başarılı" << endl;

                cout << "Yeni öğrenci eklemek/bilgilerini değiştirmek ister misiniz? 'E' veya 'H'\n";

                cin >> yeni_ekle;


            } while (yeni_ekle != 'H' && yeni_ekle != 'h');
            system("CLS");
            main();
        }

        else if(secim==Menu1::sinifListe){
            sinifListesi();
            system("pause");
            main();
        }

        else if (secim == Menu1::enYuksek){
            enYuksekNot();
            system("pause");
            main();
        }

        else if (secim == Menu1::enDusuk){
            enDusukNot();
            system("pause");
            main();
        }

        else if (secim == Menu1::sinifOrtalama){
            cout << sinifOrt() << endl;
            system("pause");
            main();
        }

        else if (secim == Menu1::sinifStdSapma){
           cout<< standartSapma();
           system("pause");
           main();
        }

        else if (secim == Menu1::aralik){
            aralık();
            system("pause");
            main();
        }

        else if (secim == Menu1::aralikKucuk) {
            kucukAralık();
            system("pause");
            main();
        }

        else if (secim == Menu1::aralikBuyuk) {
            buyukAralık();
            system("pause");
            main();
        }

        else if (secim == Menu1::cikis) {
            return 0;
        }

        else {
            cout << "\t\t\tlütfen geçerli bir değer girin" << endl;
            cout << "\t\t\t";
            cin >> secim;
        }
    } while (secim >0 && secim<=11);

    return 0;

}
