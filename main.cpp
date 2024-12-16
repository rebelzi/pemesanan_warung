#include <iostream>
#include <stdlib.h>
using namespace std;

string member[5] = {"Brian", "Dio", "Fikri", "Gerry", "Hafiz"};
string menuMakanan[10][2] = {
    {"Nasi Goreng", "15000"},
    {"Mie Goreng", "12000"},
    {"Ayam Goreng", "10000"},
    {"Ayam Bakar", "15000"},
    {"Ayam Sayur", "12000"},
    {"Soto", "10000"},
    {"Sop", "15000"},
    {"Bakso", "12000"},
    {"Mie Rebus", "10000"},
    {"Mie Kuah", "15000"}
};

string menuMinuman[10][2] = {
    {"Es Teh", "3000"},
    {"Es Jeruk", "4000"},
    {"Es Campur", "5000"},
    {"Es Teler", "6000"},
    {"Es Doger", "7000"},
    {"Es Degan", "8000"},
    {"Es Kelapa", "9000"},
    {"Es Cincau", "10000"},
    {"Es Kacang", "11000"},
    {"Es Pisang", "12000"}
};

string pemesan() {
    string nama;
    cout << "Masukkan Nama Anda: ";
    cin >> nama;
    return nama;
}

bool isMember(string member) {
    for (int i = 0; i < 5; i++) {
        if (member == ::member[i]) {
            return true;
        }
    }
    return false;

}

void printListMenu() {
    system("clear");
    cout << "Menu Makanan: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ". " << menuMakanan[i][0] << " - " << menuMakanan[i][1] << endl;
    }
    cout << "Menu Minuman: " << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ". " << menuMinuman[i][0] << " - " << menuMinuman[i][1] << endl;
    }
} 
int main() {
    string LakukanPemesanan;
    string namaPemesan;
    bool member;

    home:
    cout << "Lakukan Pemesanan? (Y/T)" << endl;
    cin >> LakukanPemesanan;
    if (LakukanPemesanan ==  "Y") {
        namaPemesan = pemesan();
        member = isMember(namaPemesan);
        printListMenu();
    }  else if (LakukanPemesanan == "T"){
        cout << "Tidak Jadi Pesan" << endl;
    } else {
        cout << "Inputan Salah" << endl;
        goto home;
    }


    cout << "Nama Pemesan: " << namaPemesan << endl;
    cout << "Status Member: " << member << endl;
}