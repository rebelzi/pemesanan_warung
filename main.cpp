#include <iostream>
#include <string>
using namespace std;

string member[5] = {"Brian", "Dio", "Fikri", "Gerry", "Hafiz"};
string menuMakanan[10][2] = {
    {"Nasi Goreng", "15000"},
    {"Mie Goreng", "12000"},
    {"Ayam Goreng", "10000"},
    {"Ayam Bakar", "15000"},
    {"Ayam Sayur", "12000"},
    {"Soto\t", "10000"},
    {"Sop\t", "15000"},
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
    cout << "Masukkan Nama Pemesan: ";
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

void printListMenuMakanan() {

    // clear screen
    printf(
        "\033[2J"
        "\033[1;1H" );
    // list column width by 2 columns
    int columnWidth = 2;
    //print menu makanan dan harga
    cout << "Menu Makanan: " << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ". " << menuMakanan[i][0] << "\t : " << "Rp." <<menuMakanan[i][1]<< ",00";
        if (columnWidth > 0) {
            cout << "\t\t";
            columnWidth--;
        }else if (columnWidth == 0) {
            cout << endl << endl;
            columnWidth=2;
        }
    }

    cout << endl << endl;
};

void printListMenuMinuman() {
    // clear screen
    printf(
        "\033[2J"
        "\033[1;1H" );
    int columnWidth=2;
    // print menu minuman
    cout << "Menu Minuman: " << endl;
    cout << endl;
    for (int i = 0; i < 10; i++) {
        cout << i+1 << ". " << menuMinuman[i][0] << "\t : " << "Rp." <<menuMinuman[i][1]<< ",00";
        if (columnWidth > 0) {
            cout << "\t";
            columnWidth--;
        }else if (columnWidth == 0) {
            cout << endl << endl;
            columnWidth=2;
        }
    }

    cout << endl << endl;
};

//membuat diskon 30% bagi yang terdaftar member
int diskon(int harga) {
    cout << "Anda mendapatkan diskon 30%" << endl;
    cout << "Diskon: Rp." << harga << ",00" << " - " << "Rp." << ((30 * harga)/100) << ",00" << endl;
    int hargaDiskon = harga - ((30 * harga)/100);
    return hargaDiskon;

}

int main() {
    string LakukanPemesanan;
    string namaPemesan;
    bool member;

    home:
    cout << "Lakukan Pemesanan? (Y/T) : ";
    cin >> LakukanPemesanan;
    if (LakukanPemesanan ==  "Y") {
        namaPemesan = pemesan();
        member = isMember(namaPemesan);
        printListMenuMakanan();
    }  else if (LakukanPemesanan == "T"){
        cout << "Tidak Jadi Pesan" << endl;
    } else {
        cout << "Inputan Salah" << endl;
        goto home;
    }

    cout << "Masukkan Jumlah Makanan yang mau dipesan: ";
    int jumlahMakanan;
    cin >> jumlahMakanan;

    int pesananMakanan[jumlahMakanan];

    for (int i = 0; i < jumlahMakanan; i++) {
        cout << "Masukkan Nomor Menu Makanan ke-" << i+1 << ": ";
        int nomorMenu;
        cin >> nomorMenu;
        pesananMakanan[i] = nomorMenu;
    }

    // pemesanan minuman
    printListMenuMinuman();
    cout << "Masukkan Jumlah Minuman yang mau dipesan: ";
    int jumlahMinuman;
    cin >> jumlahMinuman;

    int pesananMinuman[jumlahMinuman];

    for (int i = 0; i < jumlahMinuman; i++) {
        cout << "Masukkan Nomor Menu Minuman ke-" << i+1 << ": ";
        int nomorMenu;
        cin >> nomorMenu;
        pesananMinuman[i] = nomorMenu;
    }

    // clear screen
    printf(
        "\033[2J"
        "\033[1;1H" );
    cout << "Makanan yang dipesan: " << endl;
    for (int i = 0; i < jumlahMakanan; i++) {
        cout << "\t -" << menuMakanan[pesananMakanan[i]-1][0] << endl;
    }
    cout << "Minuman yang dipesan: " << endl;
    for (int i = 0; i < jumlahMinuman; i++) {
        cout << "\t -" << menuMinuman[pesananMinuman[i]-1][0] << endl;
        // cout << "Harga: " << menuMinuman[pesananMinuman[i]-1][1] + menuMakanan[pesananMakanan[i]-1][1] << endl;
    }
    //menghitung total harga minuman dan makanan
    cout << "Nama Pemesan: " << namaPemesan << endl;
    cout << "Status Member: " << (member ? "Member" : "Non Member") << endl;
    int totalHargaMakanan = 0;
    int totalHargaMinuman = 0;
    for (int i = 0; i < jumlahMakanan; i++) {
        totalHargaMakanan += stoi(menuMakanan[pesananMakanan[i]-1][1]);
    }
    for (int i = 0; i < jumlahMinuman; i++) {
        totalHargaMinuman += stoi(menuMinuman[pesananMinuman[i]-1][1]);
    }

    int totalHarga = totalHargaMakanan + totalHargaMinuman;

    if (member) {
        totalHarga = diskon(totalHarga);
    }

    cout << "Total Harga: Rp." << totalHarga << ",00" << endl;

    cout << "apakah ingin mengulang program? (Y/T) : ";
    string ulang;
    cin >> ulang;
    if (ulang == "Y") {
        goto home;
    } else {
        cout << "Terima Kasih" << endl;
    }
}
