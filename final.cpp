#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

class Warnet {
    friend ostream &operator<<(ostream &out, const Warnet &warnet);
    friend istream &operator>>(istream &in, Warnet &warnet);

private:
    struct Komputer {
        string kode;
        string kategori; 
        string deskripsi;
        double hargaPerJam;
        bool tersedia;
        
        Komputer() : hargaPerJam(0.0), tersedia(true) {}
    };
    
    int role;
    string username;
    string password;
    vector<Komputer> daftarKomputer;
    string FILENAME;

public:
    Warnet() : role(0), FILENAME("komputer.txt") {}
    
    void tampilkanHeader() const {
        cout << "==============================================\n";
        cout << "              Warnet Suka Suka                \n";
        cout << "==============================================\n";
    }

    void prosesLogin() {
        cout << "\nSELAMAT DATANG DI WARNET SUKA-SUKA\n";
        cout << "Silahkan login terlebih dahulu:\n";
        cout << "Masukkan username: ";
        cin >> username;
        cout << "Masukkan password: ";
        cin >> password;

        if (username == "admin" && password == "1234") {
            role = 1; // admin
            cout << "\nLogin berhasil! Anda masuk sebagai ADMIN.\n";
        } else {
            role = 2; // member
            cout << "\nLogin berhasil! Anda masuk sebagai MEMBER.\n";
        }
    }
    
    void jalankanSistem() {
        muatDataKomputer();
        
        if (role == 1) {
            menuAdmin();
        } else {
            menuMember();
        }
    }

private:
    void menuAdmin() {
        int pilihan;
        do {
            cout << "\n========== MENU ADMIN ==========\n";
            cout << "1. Tambah Komputer\n";
            cout << "2. Lihat Daftar Komputer\n";
            cout << "3. Edit Komputer\n";
            cout << "4. Hapus Komputer\n";
            cout << "5. Keluar\n";
            cout << "Masukkan pilihan (1-5): ";
            cin >> pilihan;
            
            switch (pilihan) {
                case 1:
                    tambahKomputer();
                    break;
                case 2:
                    tampilkanDaftarKomputer();
                    break;
                case 3:
                    editKomputer();
                    break;
                case 4:
                    hapusKomputer();
                    break;
                case 5:
                    cout << "Terima kasih! Sampai jumpa.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 5);
    }

    void menuMember() {
        int pilihan;
        do {
            cout << "\n========== MENU MEMBER ==========\n";
            cout << "1. Lihat Komputer Tersedia\n";
            cout << "2. Sewa Komputer\n";
            cout << "3. Kembalikan Komputer\n";
            cout << "4. Keluar\n";
            cout << "Masukkan pilihan (1-4): ";
            cin >> pilihan;
            
            switch (pilihan) {
                case 1:
                    tampilkanKomputerTersedia();
                    break;
                case 2:
                    sewaKomputer();
                    break;
                case 3:
                    kembalikanKomputer();
                    break;
                case 4:
                    cout << "Terima kasih! Sampai jumpa.\n";
                    break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 4);
    }
    
    void tambahKomputer() {
        int jumlah;
        cout << "\nBerapa komputer yang ingin ditambahkan? ";
        cin >> jumlah;
        cin.ignore();
        
        for (int i = 0; i < jumlah; i++) {
            Komputer komputer;
            cout << "\n--- Komputer ke-" << (i + 1) << " ---\n";
            cout << "Kode Komputer: ";
            getline(cin, komputer.kode);
            cout << "Kategori (Gaming/Office/Internet): ";
            getline(cin, komputer.kategori);
            cout << "Deskripsi: ";
            getline(cin, komputer.deskripsi);
            cout << "Harga per jam (Rp): ";
            cin >> komputer.hargaPerJam;
            cin.ignore();
            
            komputer.tersedia = true;
            daftarKomputer.push_back(komputer);
            cout << "Komputer berhasil ditambahkan!\n";
        }
        
        simpanDataKomputer();
    }
    
    void tampilkanDaftarKomputer() {
        if (daftarKomputer.empty()) {
            cout << "\nTidak ada data komputer.\n";
            return;
        }
        
        cout << "\n" << string(80, '=') << "\n";
        cout << "|" << setw(10) << left << "Kode" 
             << "|" << setw(12) << left << "Kategori"
             << "|" << setw(25) << left << "Deskripsi"
             << "|" << setw(12) << left << "Harga/Jam"
             << "|" << setw(10) << left << "Status" << "|\n";
        cout << string(80, '=') << "\n";
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            const Komputer &komputer = daftarKomputer[i];
            cout << "|" << setw(10) << left << komputer.kode.substr(0, 9)
                 << "|" << setw(12) << left << komputer.kategori.substr(0, 11)
                 << "|" << setw(25) << left << komputer.deskripsi.substr(0, 24)
                 << "|Rp " << setw(9) << left << fixed << setprecision(0) << komputer.hargaPerJam
                 << "|" << setw(10) << left << (komputer.tersedia ? "Tersedia" : "Terpakai") << "|\n";
        }
        cout << string(80, '=') << "\n";
    }
    
    void tampilkanKomputerTersedia() {
        bool adaTersedia = false;
        
        cout << "\n========== KOMPUTER TERSEDIA ==========\n";
        cout << "|" << setw(10) << left << "Kode" 
             << "|" << setw(12) << left << "Kategori"
             << "|" << setw(25) << left << "Deskripsi"
             << "|" << setw(12) << left << "Harga/Jam" << "|\n";
        cout << string(65, '=') << "\n";
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            const Komputer &komputer = daftarKomputer[i];
            if (komputer.tersedia) {
                cout << "|" << setw(10) << left << komputer.kode.substr(0, 9)
                     << "|" << setw(12) << left << komputer.kategori.substr(0, 11)
                     << "|" << setw(25) << left << komputer.deskripsi.substr(0, 24)
                     << "|Rp " << setw(9) << left << fixed << setprecision(0) << komputer.hargaPerJam << "|\n";
                adaTersedia = true;
            }
        }
        
        if (!adaTersedia) {
            cout << "|" << setw(63) << "Tidak ada komputer tersedia" << "|\n";
        }
        cout << string(65, '=') << "\n";
    }
    
    void sewaKomputer() {
        string kode;
        cout << "\nMasukkan kode komputer yang ingin disewa: ";
        cin >> kode;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            Komputer &komputer = daftarKomputer[i];
            if (komputer.kode == kode) {
                if (komputer.tersedia) {
                    komputer.tersedia = false;
                    cout << "Komputer " << kode << " berhasil disewa!\n";
                    cout << "Tarif: Rp " << komputer.hargaPerJam << " per jam\n";
                    simpanDataKomputer();
                    return;
                } else {
                    cout << "Komputer " << kode << " sedang terpakai!\n";
                    return;
                }
            }
        }
        cout << "Komputer dengan kode " << kode << " tidak ditemukan!\n";
    }
    
    void kembalikanKomputer() {
        string kode;
        cout << "\nMasukkan kode komputer yang ingin dikembalikan: ";
        cin >> kode;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            Komputer &komputer = daftarKomputer[i];
            if (komputer.kode == kode) {
                if (!komputer.tersedia) {
                    komputer.tersedia = true;
                    cout << "Komputer " << kode << " berhasil dikembalikan!\n";
                    simpanDataKomputer();
                    return;
                } else {
                    cout << "Komputer " << kode << " tidak sedang disewa!\n";
                    return;
                }
            }
        }
        cout << "Komputer dengan kode " << kode << " tidak ditemukan!\n";
    }
    
    void editKomputer() {
        string kode;
        cout << "\nMasukkan kode komputer yang ingin diedit: ";
        cin >> kode;
        cin.ignore();
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            Komputer &komputer = daftarKomputer[i];
            if (komputer.kode == kode) {
                cout << "\n--- Edit Komputer " << kode << " ---\n";
                cout << "Kategori baru (saat ini: " << komputer.kategori << "): ";
                getline(cin, komputer.kategori);
                cout << "Deskripsi baru (saat ini: " << komputer.deskripsi << "): ";
                getline(cin, komputer.deskripsi);
                cout << "Harga per jam baru (saat ini: Rp " << komputer.hargaPerJam << "): ";
                cin >> komputer.hargaPerJam;
                
                cout << "Data komputer berhasil diupdate!\n";
                simpanDataKomputer();
                return;
            }
        }
        cout << "Komputer dengan kode " << kode << " tidak ditemukan!\n";
    }
    
    void hapusKomputer() {
        string kode;
        cout << "\nMasukkan kode komputer yang ingin dihapus: ";
        cin >> kode;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            if (daftarKomputer[i].kode == kode) {
                daftarKomputer.erase(daftarKomputer.begin() + i);
                cout << "Komputer " << kode << " berhasil dihapus!\n";
                simpanDataKomputer();
                return;
            }
        }
        cout << "Komputer dengan kode " << kode << " tidak ditemukan!\n";
    }
    
    void simpanDataKomputer() {
        ofstream file(FILENAME.c_str());
        if (file.is_open()) {
            for (size_t i = 0; i < daftarKomputer.size(); i++) {
                const Komputer &komputer = daftarKomputer[i];
                file << komputer.kode << "|"
                     << komputer.kategori << "|"
                     << komputer.deskripsi << "|"
                     << komputer.hargaPerJam << "|"
                     << (komputer.tersedia ? "1" : "0") << "\n";
            }
            file.close();
        } else {
            cout << "Gagal menyimpan data ke file!\n";
        }
    }
    
    void muatDataKomputer() {
        ifstream file(FILENAME.c_str());
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                Komputer komputer;
                size_t pos = 0;
                int field = 0;
                
                while ((pos = line.find("|")) != string::npos) {
                    string token = line.substr(0, pos);
                    switch (field) {
                        case 0: komputer.kode = token; break;
                        case 1: komputer.kategori = token; break;
                        case 2: komputer.deskripsi = token; break;
                        case 3: {
                            
                            double harga = 0.0;
                            for (size_t j = 0; j < token.length(); j++) {
                                if (token[j] >= '0' && token[j] <= '9') {
                                    if (harga == 0.0) harga = token[j] - '0';
                                    else harga = harga * 10 + (token[j] - '0');
                                }
                            }
                            komputer.hargaPerJam = harga;
                            break;
                        }
                    }
                    line.erase(0, pos + 1);
                    field++;
                }
                
         
                komputer.tersedia = (line == "1");
                daftarKomputer.push_back(komputer);
            }
            file.close();
        }
    }
};


ostream &operator<<(ostream &out, const Warnet &warnet) {
    warnet.tampilkanHeader();
    return out;
}

istream &operator>>(istream &in, Warnet &warnet) {
    warnet.prosesLogin();
    warnet.jalankanSistem();
    return in;
}

int main() {
    Warnet warnet;
    cout << warnet;  
    cin >> warnet;   
    return 0;
}
