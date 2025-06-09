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
        cout << "|              Warnet Suka Suka              | \n";
        cout << "==============================================\n";
    }

    void prosesLogin() {
    	cout<<endl;
    	cout<<"==========================================\n";
        cout<<"|   SELAMAT DATANG DI WARNET SUKA-SUKA   |\n";
        cout<<"==========================================\n";
        cout<<" Silahkan login terlebih dahulu:\n";
        cout<<" Masukkan username: ";
        cin>> username;
        cout<<" Masukkan password: ";
        cin >> password;

        if (username == "admin" && password == "1234") {
            role = 1; // admin
            cout << "\nLogin berhasil! Anda masuk sebagai ADMIN.\n";
        } else {
            role = 2; // member
            cout << "\nLogin berhasil! Anda masuk sebagai MEMBER.\n";
        }
        cout<<endl;
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
            cout << "========== MENU ADMIN ============\n";
            cout << "| 1. Tambah Komputer             |\n";
            cout << "| 2. Lihat Daftar Komputer       |\n";
            cout << "| 3. Edit Komputer               |\n";
            cout << "| 4. Hapus Komputer              |\n";
            cout << "| 5. Lihat Pesanan makanan       |\n";
            cout << "| 6. Keluar                      |\n";
            cout << "==================================\n";
            cout << "Masukkan pilihan (1-6): ";
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
                   lihatPesanan();
                    break;
                case 6:
                	cout<<"Terimakasih sampai jumpa kembali!";
                	break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 6);
    }

    void menuMember() {
        int pilihan;
        do {
            cout<<"\n========== MENU MEMBER ==========\n";
            cout<<"| 1. Lihat Komputer Tersedia      |\n";
            cout<<"| 2. Sewa Komputer                |\n";
            cout<<"| 3. Kembalikan Komputer          |\n";
            cout<<"| 4. Menu Makanan                 |\n";
            cout<<"| 5. Keluar                       |\n";
            cout<<"===================================\n";
            cout << " Masukkan pilihan (1-5): ";
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
					menuMakanan();
                    break;
                case 5:
                	cout<<"Terima kasih! Sampai jumpa.\n";
                	break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 5);
    }
    
    void menuMakanan(){
    	int pilihan, jumlah;
    	float totalPerMenu, totalKeseluruhan;
    	const int jumlahMenu=10;
    	char konfirm, lanjut;
    	
    	string nama[jumlahMenu]={
			"indomie goreng", "indomie rebus", "indomie rendang", "nasi goreng", "Mie Ayam",
			"Es Teh", "Kopi Hitam", "Air putih", "Josua", "Kuku Bima"
		};
		
		float harga[jumlahMenu]={
			5000, 5000, 6000, 10000,
		 	10000, 2500, 3000, 2000, 4000, 5000 
			};
			
		cout<<endl;
		do{
    	cout<<"=========  MENU MAKANAN =========\n";
    	for (int i=0;i<jumlahMenu;i++){
    		cout<<i+1<<"."<<nama[i]<<" "<<"Rp."<<harga[i]<<endl;
		}
    	cout<<" "<<endl;
    	cout<<"Masukkan makanan yang ingin dibeli (1-10): ";
    	cin>>pilihan;
    	
    	if (pilihan<1 || pilihan>jumlahMenu){
    		cout<<"Makanan tidak ada";
    		return;
		}
		
		cout<<"Masukkan jumlah makanan yang ingin dipesan: ";
		cin>>jumlah;
		
		totalPerMenu=harga[pilihan-1]*jumlah;
		totalKeseluruhan+=totalPerMenu;
		
		cout<<"Anda memesan makanan/minuman "<<nama[pilihan-1]<<" sebanyak "<<jumlah<<endl;
		cout<<"Total : "<<totalPerMenu<<endl;
		
		cout<<"\nIngin memesan makanan lain? (y/n): ";
		cin>>lanjut;
		
	}while(lanjut=='y'||lanjut=='Y');
		if(totalKeseluruhan>0){
			cout<<endl;
			cout<<"Total yang harus dibayarkan: Rp."<<totalKeseluruhan<<endl;
			cout<<"Lanjut ke pembayaran? (y/n): ";
		cin>>konfirm;
		
		if (konfirm=='y'||konfirm=='Y'){
			cout<<"\npembayaran berhasil"<<endl;
			cout<<"silahkan menunggu makanan atau minumannya. Terimakasih"<<endl;
			
		ofstream file("pesanan.txt", ios::app);
			if (file.is_open()){
				file<<"Username: "<<username<<endl;
				 file<< "Total Pembayaran: Rp. "<<totalKeseluruhan<<endl;
        		 file<< "-----------------------------------------\n";
        	file.close();
		}
		}else{
			cout<<"Pesanan dibatalkan";
		}
		}
}

	void lihatPesanan(){
		ifstream file("pesanan.txt");
		if (!file){
			cout<<"belum ada data makanan";
			return;
		}
		
		cout << "\n========== DAFTAR PESANAN MAKANAN & MINUMAN ==========\n";
   		string line;
    	while (getline(file, line)) {
        cout << line << endl;
    }
    	cout << "========================================================\n";
    file.close();
		

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
