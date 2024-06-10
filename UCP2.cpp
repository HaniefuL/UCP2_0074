#include <iostream>
#include <vector>
using namespace std;

class karyawan;
class proyek{   //Asosiasi
    public:
        string nama;
        vector<karyawan*> daftar_karyawan;
        proyek(string pNama): nama(pNama) {
            cout << "Proyek \"" << nama << "\" ada\n";
        }
        ~proyek() {
            cout << "Proyek \"" << nama << "\" tidak ada\n";
        }

        void tambahKaryawan(karyawan*);
        void cetakKaryawan();
};

class karyawan {
    public:
        string nama;
        vector<proyek*> daftar_proyek;

        karyawan(string pNama): nama(pNama) {
            cout << "Karyawan \"" << nama << "\" ada\n";
        }
        ~karyawan() {
            cout << "Karyawan \"" << nama << "\" tidak ada\n";
        }

        void tambahProyek  (proyek*);
        void cetakProyek();
};

void proyek::tambahKaryawan(karyawan* pKaryawan) {
    daftar_karyawan.push_back(pKaryawan);
}

void proyek::cetakKaryawan() {
        cout << "Daftar karyawan yang menangani proyek \"" << this->nama << "\":\n";
    for (auto& a : daftar_karyawan) { 
        cout << a->nama << "\n";
    }
    cout << endl;
}

void karyawan::tambahProyek(proyek* pProyek) {
    daftar_proyek.push_back(pProyek);
}

void karyawan::cetakProyek() {
    cout << "Daftar proyek dari karyawan \"" << this->nama << "\":\n";
    for (auto& a : daftar_proyek) {
        cout << a->nama << "\n";
    }
    cout << endl;
}

int main() {
    karyawan* varKaryawan1 = new karyawan("Budi");
    karyawan* varKaryawan2 = new karyawan("Andi");
    karyawan* varKaryawan3 = new karyawan("Neo");
    proyek* varProyek1 = new proyek("Sistemin formasi");
    proyek* varProyek2 = new proyek("Keamanan");
    proyek* varProyek3 = new proyek("Algoritma");

    varKaryawan1->tambahProyek(varProyek1);
    varKaryawan1->tambahProyek(varProyek2);
    varKaryawan2->tambahProyek(varProyek1);
    varKaryawan3->tambahProyek(varProyek3);

    varProyek1->tambahKaryawan(varKaryawan1);
    varProyek2->tambahKaryawan(varKaryawan1);
    varProyek1->tambahKaryawan(varKaryawan2);
    varProyek3->tambahKaryawan(varKaryawan3);

    varKaryawan1->cetakProyek();
    varKaryawan2->cetakProyek();
    varKaryawan3->cetakProyek();
    varProyek1->cetakKaryawan();
    varProyek2->cetakKaryawan();
    varProyek3->cetakKaryawan();

    delete varProyek1;
    delete varProyek2;
    delete varProyek3;
    delete varKaryawan1;
    delete varKaryawan2;
    delete varKaryawan3;

    return 0;
}