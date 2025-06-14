#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
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
    
    struct MenuItem {
        string nama;
        double harga;
        
        MenuItem() : harga(0.0) {}
        MenuItem(string n, double h) : nama(n), harga(h) {}
    };
    
    struct BookingInfo {
        string username;
        string kodeKomputer;
        string tanggal;
        string waktuMulai;
        string waktuSelesai;
        double biaya;
        
        
        BookingInfo() : biaya(0.0) {}
    };
    
struct Member {
    string username;
    string password;
    int poin;
    double saldo;
 
    Member() : poin(0), saldo(0.0) {}
};


void tambahPoin(const string& uname, int poin) {
    for (size_t i = 0; i < daftarMember.size(); i++) {
        if (daftarMember[i].username == uname) {
            daftarMember[i].poin += poin;
            simpanDataMember();
            break;
        }
    }
}

// Fungsi tukar poin
void tukarPoin() {
    cout << "\n===== TUKAR POIN =====\n";
    for (size_t i = 0; i < daftarMember.size(); i++) {
        if (daftarMember[i].username == username) {
            cout << "Poin Anda: " << daftarMember[i].poin << endl;
            if (daftarMember[i].poin >= 100) {
                cout << "Tukar 100 poin dengan diskon Rp 10.000? (y/n): ";
                char jawab;
                cin >> jawab;
                if (jawab == 'y' || jawab == 'Y') {
                    daftarMember[i].poin -= 100;
                    daftarMember[i].saldo += 10000;
                    simpanDataMember();
                    cout << "Berhasil tukar poin! Saldo bertambah Rp 10.000\n";
                }
            } else {
                cout << "Poin belum cukup untuk ditukar.\n";
            }
            return;
        }
    }
}
    
    int role;
    string username;
    string password;
    vector<Komputer> daftarKomputer;
    vector<MenuItem> daftarMenu;
    vector<BookingInfo> daftarBooking;
    vector<Member> daftarMember;
    string FILENAME;
    string MENU_FILENAME;
    string BOOKING_FILENAME;
    string kode;

public:
    Warnet() : role(0), FILENAME("komputer.txt"), MENU_FILENAME("menu.txt"), BOOKING_FILENAME("booking.txt") {}
    
    void tampilkanHeader() const {
        cout << "==============================================\n";
        cout << "|                                             | \n";
        cout << "|                                             | \n";
        cout << "|                                             | \n";
        cout << "|              WARNET SUKA SUKA               | \n";
        cout << "|                                             | \n";
        cout << "|                                             | \n";
        cout << "|                                             | \n";
        cout << "==============================================\n";
        cout<<"==============================================\n";
        cout<<"Jenis Jenis PC dan fasilitasnya\n";
        cout<<"==============================================\n";
        cout<<"PC Gamming";
        
    }
    
    void fasilitasYangDidapat() const {
    cout << "======================================================================\n";
    cout << "|                     WARNET SUKA SUKA - FASILITAS                   | \n";
    cout << "======================================================================\n";
    cout << "PC Gaming:\n";
    cout << " - Komputer Spek Tinggi (RAM 32GB, NVIDIA RTX 3080, Core i9)\n";
    cout << " - Monitor Gaming 165Hz, ukuran 27 inch\n";
    cout << " - Kursi Gaming Ergonomis\n";
    cout << " - Headset Gaming 7.1 Surround\n";
    cout << " - Mouse Gaming, RGB\n";
    cout << " - Keyboard Mechanical\n";
    cout << " - Free Snack & Drink\n";
    cout << " - Internet Super Cepat (500 Mbps)\n";
    cout << " - Daftar game tersedia:\n";
    cout << "   * Valorant\n";
    cout << "   * Dota 2\n";
    cout << "   * PUBG\n";
    cout << "   * Call of Duty Warzone\n";
    cout << "   * Fortnite\n";
    cout << "   * Apex Legends\n";
    cout << "   * CS:GO\n";
    cout << "   * Grand Theft Auto V\n";
    cout << "   * The Witcher 3\n";
    cout << "   * Red Dead Redemption 2\n";
    cout << " - Mousepad ukuran XL\n";
    cout << " - Audio Dolby Atmos\n";
    cout << " - Gaming Chair merk Secretlab\n";
    cout << " - Meja luas, muat 2 monitor\n";
    cout << " - Peripheral tambahan: controller, VR headset\n";
    cout << " - Air Conditioner\n";
    cout << " - Snack tersedia: Chitato, Oreo, Cheetos\n";
    cout << " - Minuman tersedia: Air mineral, Soda, Energi Drink\n";
    cout << " - Update game setiap minggu\n";
    cout << "======================================================================\n";
    cout << "PC Office:\n";
    cout << " - Komputer Standar (RAM 8GB, Core i5, Integrated Graphics)\n";
    cout << " - Monitor ukuran 23 inch\n";
    cout << " - Kursi Kantor Nyaman\n";
    cout << " - Mouse dan Keyboard Standar\n";
    cout << " - Speaker Stereo\n";
    cout << " - Microsoft Office 2021\n";
    cout << " - Photoshop CS6\n";
    cout << " - CorelDraw\n";
    cout << " - PDF Reader, File Manager\n";
    cout << " - Internet 100 Mbps\n";
     cout << " - Printer tersedia\n";
    cout << " - Scanner\n";
    cout << " - UPS backup\n";
    cout << " - Perangkat lunak bisnis (QuickBooks, Microsoft Project)\n";
    cout << " - Microsoft Outlook\n";
    cout << " - Photoshop, Illustrator, CorelDraw\n";
    cout << " - Desain Grafis, Pengolahan Dokumen\n";
    cout << " - Cocok untuk kerja, belajar, presentasi\n";
    cout << " - Lingkungan tenang, nyaman\n";
    cout << "======================================================================\n";
    cout << "PC Internet:\n";
    cout << " - Komputer Standar (RAM 4GB, Core i3)\n";
    cout << " - Monitor ukuran 20 inch\n";
    cout << " - Mouse dan keyboard biasa\n";
    cout << " - Speaker biasa\n";
    cout << " - Internet 50 Mbps\n";
    cout << " - Cocok untuk:\n";
    cout << "   * Nonton Youtube\n";
    cout << "   * Streaming Netflix\n";
    cout << "   * Sosmed (Instagram, TikTok, Facebook)\n";
    cout << "   * Browsing dan mencari informasi\n";
    cout << " - Cocok untuk mencari informasi\n";
    cout << " - Mengirim email, belajar online\n";
    cout << " - Streaming YouTube, Netflix, VIU\n";
    cout << " - Sosmed (Instagram, TikTok, Facebook)\n";
    cout << " - Diskusi Forum, Blog\n";
    cout << " - Pengunduhan dokumen\n";
    cout << " - Akses Wifi kencang\n";
    cout << " - Lingkungan nyaman\n";
    cout << " - Cocok untuk segala kalangan\n";
    cout << "======================================================================\n";
}


    void prosesLogin() {
        cout<<endl;

        cout<<"==========================================\n";
        cout<<"|                                        |\n";
        cout<<"|   SELAMAT DATANG DI WARNET SUKA-SUKA   |\n";
        cout<<"|                                        |\n";
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
        muatDataMenu();
        muatDataBooking();
        muatDataMember();
        
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
            cout << "| 5. Lihat Jumlah Komputer       |\n";
            cout << "| 6. Lihat Booking Komputer      |\n";
            cout << "| 7. Lihat Pesanan Makanan       |\n";
            cout << "| 8. Lihat Kritik & Saran        |\n";
            cout << "| 9. Keluar                      |\n";
            cout << "==================================\n";
            cout << "Masukkan pilihan (1-9): ";
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
                    lihatJumlahKomputer();
                    break;
                case 6:
                    lihatBooking();
                    break;
                case 7:
                    lihatPesanan();
                    break;
                case 8:
                    lihatKritikSaran();
                    break;
                case 9:
                    cout<<"Terimakasih sampai jumpa kembali!";
                    break;
                case 10:
                    menuMemberAdmin();
                    break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 9);
    }

    void menuMember() {
        int pilihan;
        do {
            cout<<"\n========== MENU MEMBER ==========\n";
            cout<<"| 1. Lihat Komputer Tersedia      |\n";
            cout<<"| 2. Sewa Komputer                |\n";
            cout<<"| 3. Kembalikan Komputer          |\n";
            cout<<"| 4. Booking Komputer             |\n";
            cout<<"| 5. Menu Makanan                 |\n";
            cout<<"| 6. Kritik & Saran               |\n";
            cout<<"| 7. Lihat Booking                |\n";
            cout<<"| 8. Tambah Waktu Komputer        |\n";
            cout<<"| 8. Lihat Fasilitas              |\n";
            cout<<"| 9. Keluar                       |\n";
            cout<<"===================================\n";
            cout << " Masukkan pilihan (1-10): ";
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
                    bookingKomputer();
                    break;
                case 5:
                    menuMakanan();
                    break;
                case 6:
                    inputKritikSaran();
                    break;
                case 7:
                    lihatBooking2();
                    break;
                case 8:
                    tambahWaktuKomputer();
                    break;
                case 9:
                    cout<<"Terimakasih sampai jumpa kembali!";
                    break;
                case 10:
                    topUpSaldo();
                    break;
                case 11:
                    tukarPoin();
                    break;
                case 12:
                    riwayatPribadi();
                    break;
                case 13:
                    ubahPassword();
                    break;
                default:
                    cout << "Pilihan tidak valid! Silakan coba lagi.\n";
            }
        } while (pilihan != 14);
    }
    
    void lihatJumlahKomputer() {
        int totalKomputer = daftarKomputer.size();
        int komputerTersedia = 0;
        int komputerTerpakai = 0;
        int gaming = 0, office = 0, internet = 0;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            if (daftarKomputer[i].tersedia) {
                komputerTersedia++;
            } else {
                komputerTerpakai++;
            }
            
            string kategori = daftarKomputer[i].kategori;
            for (size_t j = 0; j < kategori.length(); j++) {
                if (kategori[j] >= 'A' && kategori[j] <= 'Z') {
                    kategori[j] = kategori[j] + 32;
                }
            }
            
            if (kategori.find("gaming") != string::npos) {
                gaming++;
            } else if (kategori.find("office") != string::npos) {
                office++;
            } else if (kategori.find("internet") != string::npos) {
                internet++;
            }
        }
        
        cout << "\n============ STATISTIK KOMPUTER ============\n";
        cout << "| Total Komputer        : " << setw(3) << totalKomputer << " unit        |\n";
        cout << "| Komputer Tersedia     : " << setw(3) << komputerTersedia << " unit        |\n";
        cout << "| Komputer Terpakai     : " << setw(3) << komputerTerpakai << " unit        |\n";
        cout << "| ================================== |\n";
        cout << "| KATEGORI KOMPUTER:                 |\n";
        cout << "| - Gaming              : " << setw(3) << gaming << " unit        |\n";
        cout << "| - Office              : " << setw(3) << office << " unit        |\n";
        cout << "| - Internet            : " << setw(3) << internet << " unit        |\n";
        cout << "============================================\n";
        
        // Tampilkan jumlah booking
        cout << "\n============ STATISTIK BOOKING =============\n";
        cout << "| Total Booking Aktif   : " << setw(3) << daftarBooking.size() << " booking     |\n";
        cout << "============================================\n";
    }
    
    void bookingKomputer() {
        cin.ignore(); 
        
        if (daftarKomputer.empty()) {
            cout << "\nTidak ada komputer tersedia untuk booking.\n";
            return;
        }
        
        // Tampilkan komputer tersedia
        tampilkanKomputerTersedia();
        
        BookingInfo booking;
        booking.username = username;
        
        cout << "\n========== BOOKING KOMPUTER ==========\n";
        cout << "Masukkan kode komputer yang ingin dibooking: ";
        getline(cin, booking.kodeKomputer);
        
        // Cek apakah komputer ada dan tersedia
        bool komputerDitemukan = false;
        double hargaPerJam = 0.0;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            if (daftarKomputer[i].kode == booking.kodeKomputer) {
                komputerDitemukan = true;
                if (!daftarKomputer[i].tersedia) {
                    cout << "Komputer " << booking.kodeKomputer << " sedang terpakai!\n";
                    return;
                }
                hargaPerJam = daftarKomputer[i].hargaPerJam;
                break;
            }
        }
        
        if (!komputerDitemukan) {
            cout << "Komputer dengan kode " << booking.kodeKomputer << " tidak ditemukan!\n";
            return;
        }
        
        cout << "Masukkan tanggal (DD/MM/YYYY): ";
        getline(cin, booking.tanggal);
        cout << "Masukkan waktu mulai (HH:MM): ";
        getline(cin, booking.waktuMulai);
        cout << "Masukkan waktu selesai (HH:MM): ";
        getline(cin, booking.waktuSelesai);
        
        int jamMulai = (booking.waktuMulai[0] - '0') * 10 + (booking.waktuMulai[1] - '0');
        int menitMulai = (booking.waktuMulai[3] - '0') * 10 + (booking.waktuMulai[4] - '0');
        int jamSelesai = (booking.waktuSelesai[0] - '0') * 10 + (booking.waktuSelesai[1] - '0');
        int menitSelesai = (booking.waktuSelesai[3] - '0') * 10 + (booking.waktuSelesai[4] - '0');
        
        int totalMenitMulai = jamMulai * 60 + menitMulai;
        int totalMenitSelesai = jamSelesai * 60 + menitSelesai;
        
        if (totalMenitSelesai <= totalMenitMulai) {
            cout << "Waktu selesai harus lebih dari waktu mulai!\n";
            return;
        }

        int durasiMenit = totalMenitSelesai - totalMenitMulai;
        double durasiJam = (double)durasiMenit / 60.0;
        booking.biaya = durasiJam * hargaPerJam;
        
        cout << "\n========== KONFIRMASI BOOKING ==========\n";
        cout << "Komputer      : " << booking.kodeKomputer << "\n";
        cout << "Tanggal       : " << booking.tanggal << "\n";
        cout << "Waktu         : " << booking.waktuMulai << " - " << booking.waktuSelesai << "\n";
        cout << "Durasi        : " << fixed << setprecision(1) << durasiJam << " jam\n";
        cout << "Biaya         : Rp " << fixed << setprecision(0) << booking.biaya << "\n";
        cout << "========================================\n";
        
        char konfirm;
        cout << "Konfirmasi booking? (y/n): ";
        cin >> konfirm;
        
        if (konfirm == 'y' || konfirm == 'Y') {
            daftarBooking.push_back(booking);
            simpanDataBooking();
            cout << "Booking berhasil! Silakan datang sesuai jadwal.\n";
        } else {
            cout << "Booking dibatalkan.\n";
        }
    }
    
    void lihatBooking() {
        if (daftarBooking.empty()) {
            cout << "\n========== DAFTAR BOOKING KOMPUTER ==========\n";
            cout << "Belum ada data booking komputer.\n";
            cout << "=============================================\n";
            return;
        }
        
        cout << "\n========== DAFTAR BOOKING KOMPUTER ==========\n";
        cout << "|" << setw(12) << left << "Username"
             << "|" << setw(8) << left << "Kode PC"
             << "|" << setw(12) << left << "Tanggal"
             << "|" << setw(13) << left << "Waktu"
             << "|" << setw(10) << left << "Biaya" << "|\n";
        cout << string(70, '=') << "\n";
        
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            const BookingInfo &booking = daftarBooking[i];
            string waktu = booking.waktuMulai + "-" + booking.waktuSelesai;
            cout << "|" << setw(12) << left << booking.username.substr(0, 11)
                 << "|" << setw(8) << left << booking.kodeKomputer.substr(0, 7)
                 << "|" << setw(12) << left << booking.tanggal.substr(0, 11)
                 << "|" << setw(13) << left << waktu.substr(0, 12)
                 << "|Rp " << setw(7) << left << fixed << setprecision(0) << booking.biaya << "|\n";
        }
        cout << string(70, '=') << "\n";
        
        // Hitung total pendapatan dari booking
        double totalPendapatan = 0.0;
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            totalPendapatan += daftarBooking[i].biaya;
        }
        cout << "Total Pendapatan Booking: Rp " << fixed << setprecision(0) << totalPendapatan << "\n";
    }
    
    void simpanDataBooking() {
        ofstream file(BOOKING_FILENAME.c_str());
        if (file.is_open()) {
            for (size_t i = 0; i < daftarBooking.size(); i++) {
                const BookingInfo &booking = daftarBooking[i];
                file << booking.username << "|"
                     << booking.kodeKomputer << "|"
                     << booking.tanggal << "|"
                     << booking.waktuMulai << "|"
                     << booking.waktuSelesai << "|"
                     << booking.biaya << "\n";
            }
            file.close();
        } else {
            cout << "Gagal menyimpan data booking ke file!\n";
        }
    }
    
    void muatDataBooking() {
        ifstream file(BOOKING_FILENAME.c_str());
        if (file.is_open()) {
            string line;
            while (getline(file, line)) {
                if (line.empty()) continue;
                
                BookingInfo booking;
                size_t pos = 0;
                int field = 0;
                
                while ((pos = line.find("|")) != string::npos) {
                    string token = line.substr(0, pos);
                    switch (field) {
                        case 0: booking.username = token; break;
                        case 1: booking.kodeKomputer = token; break;
                        case 2: booking.tanggal = token; break;
                        case 3: booking.waktuMulai = token; break;
                        case 4: booking.waktuSelesai = token; break;
                    }
                    line.erase(0, pos + 1);
                    field++;
                }
                
                double biaya = 0.0;
                bool afterDecimal = false;
                double decimalPlace = 0.1;
                
                for (size_t j = 0; j < line.length(); j++) {
                    if (line[j] >= '0' && line[j] <= '9') {
                        if (!afterDecimal) {
                            biaya = biaya * 10 + (line[j] - '0');
                        } else {
                            biaya += (line[j] - '0') * decimalPlace;
                            decimalPlace /= 10;
                        }
                    } else if (line[j] == '.') {
                        afterDecimal = true;
                    }
                }
                booking.biaya = biaya;
                
                daftarBooking.push_back(booking);
            }
            file.close();
        }
    }
    
    void menuMakanan(){
        int pilihan;
        int jumlah;
        double totalPerMenu;
        double totalKeseluruhan = 0.0;
        char konfirm;
        char lanjut;
        vector<string> pesananList;
        
        if (daftarMenu.empty()) {
            cout << "Menu makanan tidak tersedia. Silakan hubungi admin.\n";
            return;
        }
        
        cout<<endl;
        do{
            cout<<"=========  MENU MAKANAN =========\n";
            for (size_t i = 0; i < daftarMenu.size(); i++){
                cout << (i+1) << ". " << daftarMenu[i].nama << " - Rp." << fixed << setprecision(0) << daftarMenu[i].harga << endl;
            }
            cout<<" "<<endl;
            cout<<"Masukkan makanan yang ingin dibeli (1-" << daftarMenu.size() << "): ";
            cin>>pilihan;
            
            if (pilihan < 1 || pilihan > (int)daftarMenu.size()){
                cout<<"Makanan tidak ada dalam menu!\n";
                continue;
            }
            
            cout<<"Masukkan jumlah makanan yang ingin dipesan: ";
            cin>>jumlah;
            
            if (jumlah <= 0) {
                cout << "Jumlah harus lebih dari 0!\n";
                continue;
            }
            
            totalPerMenu = daftarMenu[pilihan-1].harga * jumlah;
            totalKeseluruhan += totalPerMenu;
            
            stringstream ss;
            ss << daftarMenu[pilihan-1].nama << " x" << jumlah << " = Rp." << fixed << setprecision(0) << totalPerMenu;
            pesananList.push_back(ss.str());
            
            cout<<"Anda memesan " << daftarMenu[pilihan-1].nama << " sebanyak " << jumlah << endl;
            cout<<"Total untuk item ini: Rp." << fixed << setprecision(0) << totalPerMenu << endl;
            
            cout<<"\nIngin memesan makanan lain? (y/n): ";
            cin>>lanjut;
            
        }while(lanjut=='y'||lanjut=='Y');
        
        if(totalKeseluruhan > 0){
            cout<<endl;
            cout << "========== RINGKASAN PESANAN ==========\n";
            for (size_t i = 0; i < pesananList.size(); i++) {
                cout << "- " << pesananList[i] << endl;
            }
            cout << "=======================================\n";
            cout<<"Total yang harus dibayarkan: Rp."<< fixed << setprecision(0) << totalKeseluruhan<<endl;
            cout<<"Lanjut ke pembayaran? (y/n): ";
            cin>>konfirm;
            
            if (konfirm=='y'||konfirm=='Y'){
                cout<<"\nPembayaran berhasil!"<<endl;
                cout<<"Silahkan menunggu makanan atau minumannya. Terimakasih!"<<endl;
                
                ofstream file("pesanan.txt", ios::app);
                if (file.is_open()){
                    file << "================================\n";
                    file << "Username: " << username << endl;
                    file << "Detail Pesanan:\n";
                    for (size_t i = 0; i < pesananList.size(); i++) {
                        file << "- " << pesananList[i] << endl;
                    }
                    file << "Total Pembayaran: Rp." << fixed << setprecision(0) << totalKeseluruhan << endl;
                    file << "================================\n\n";
                    file.close();
                } else {
                    cout << "Gagal menyimpan pesanan ke file!\n";
                }
            }else{
                cout<<"Pesanan dibatalkan.\n";
            }
        }
    }

    void lihatPesanan(){
        ifstream file("pesanan.txt");
        if (!file.is_open()){
            cout << "\n========== DAFTAR PESANAN MAKANAN & MINUMAN ==========\n";
            cout << "Belum ada data pesanan makanan.\n";
            cout << "======================================================\n";
            return;
        }
        
        cout << "\n========== DAFTAR PESANAN MAKANAN & MINUMAN ==========\n";
        string line;
        bool adaData = false;
        while (getline(file, line)) {
            cout << line << endl;
            adaData = true;
        }
        
        if (!adaData) {
            cout << "Belum ada data pesanan makanan.\n";
        }
        
        cout << "======================================================\n";
        file.close();
    }
    
    void inputKritikSaran() {
        cin.ignore();
        string kritik;
        
        cout << "\n=========== KRITIK & SARAN ===========\n";
        cout << "Silakan berikan kritik dan saran Anda:\n";
        cout << "Ketik kritik/saran (akhiri dengan enter): ";
        getline(cin, kritik);
        
        if (kritik.empty()) {
            cout << "Kritik/saran tidak boleh kosong!\n";
            return;
        }
        
        ofstream file("kritik_saran.txt", ios::app);
        if (file.is_open()) {
            file << "================================\n";
            file << "Username: " << username << endl;
            file << "Kritik/Saran: " << kritik << endl;
            file << "================================\n\n";
            file.close();
            cout << "Terima kasih atas kritik dan saran Anda!\n";
        } else {
            cout << "Gagal menyimpan kritik dan saran!\n";
        }
    }
    
    void lihatKritikSaran() {
        ifstream file("kritik_saran.txt");
        if (!file.is_open()) {
            cout << "\n============= KRITIK & SARAN =============\n";
            cout << "Belum ada kritik dan saran dari member.\n";
            cout << "==========================================\n";
            return;
        }
        
        cout << "\n============= KRITIK & SARAN =============\n";
        string line;
        bool adaData = false;
        while (getline(file, line)) {
            cout << line << endl;
            adaData = true;
        }
        
        if (!adaData) {
            cout << "Belum ada kritik dan saran dari member.\n";
        }
        
        cout << "==========================================\n";
        file.close();
    }
    
    void muatDataMenu() {
        ifstream file(MENU_FILENAME.c_str());
        if (!file.is_open()) {
            buatMenuDefault();
            return;
        }
        
        daftarMenu.clear();
        string line;
        while (getline(file, line)) {
            if (line.empty()) continue;
            
            size_t pos = line.find("|");
            if (pos != string::npos) {
                string nama = line.substr(0, pos);
                string hargaStr = line.substr(pos + 1);
                
                double harga = 0.0;
                bool afterDecimal = false;
                double decimalPlace = 0.1;
                
                for (size_t i = 0; i < hargaStr.length(); i++) {
                    if (hargaStr[i] >= '0' && hargaStr[i] <= '9') {
                        if (!afterDecimal) {
                            harga = harga * 10 + (hargaStr[i] - '0');
                        } else {
                            harga += (hargaStr[i] - '0') * decimalPlace;
                            decimalPlace /= 10;
                        }
                    } else if (hargaStr[i] == '.') {
                        afterDecimal = true;
                    }
                }
                
                daftarMenu.push_back(MenuItem(nama, harga));
            }
        }
        file.close();
    }
    
    void buatMenuDefault() {
        ofstream file(MENU_FILENAME.c_str());
        if (file.is_open()) {
            file << "Indomie Goreng|5000\n";
            file << "Indomie Rebus|5000\n";
            file << "Indomie Rendang|6000\n";
            file << "Nasi Goreng|10000\n";
            file << "Mie Ayam|10000\n";
            file << "Es Teh|2500\n";
            file << "Kopi Hitam|3000\n";
            file << "Air Putih|2000\n";
            file << "Jus Jeruk|4000\n";
            file << "Kuku Bima|5000\n";
            file.close();
            
            muatDataMenu();
        }
    }
    
    void menuMakanann(){
        int pilihan;
        int jumlah;
        double totalPerMenu;
        double totalKeseluruhan = 0.0;
        char konfirm;
        char lanjut;
        vector<string> pesananList;
        
        if (daftarMenu.empty()) {
            cout << "Menu makanan tidak tersedia. Silakan hubungi admin.\n";
            return;
        }
        
        cout<<endl;
        do{
            cout<<"=========  MENU MAKANAN =========\n";
            for (size_t i = 0; i < daftarMenu.size(); i++){
                cout << (i+1) << ". " << daftarMenu[i].nama << " - Rp." << fixed << setprecision(0) << daftarMenu[i].harga << endl;
            }
            cout<<" "<<endl;
            cout<<"Masukkan makanan yang ingin dibeli (1-" << daftarMenu.size() << "): ";
            cin>>pilihan;
            
            if (pilihan < 1 || pilihan > (int)daftarMenu.size()){
                cout<<"Makanan tidak ada dalam menu!\n";
                continue;
            }
            
            cout<<"Masukkan jumlah makanan yang ingin dipesan: ";
            cin>>jumlah;
            
            if (jumlah <= 0) {
                cout << "Jumlah harus lebih dari 0!\n";
                continue;
            }
            
            totalPerMenu = daftarMenu[pilihan-1].harga * jumlah;
            totalKeseluruhan += totalPerMenu;
            
            stringstream ss;
            ss << daftarMenu[pilihan-1].nama << " x" << jumlah << " = Rp." << fixed << setprecision(0) << totalPerMenu;
            pesananList.push_back(ss.str());
            
            cout<<"Anda memesan " << daftarMenu[pilihan-1].nama << " sebanyak " << jumlah << endl;
            cout<<"Total untuk item ini: Rp." << fixed << setprecision(0) << totalPerMenu << endl;
            
            cout<<"\nIngin memesan makanan lain? (y/n): ";
            cin>>lanjut;
            
        }while(lanjut=='y'||lanjut=='Y');
        
        if(totalKeseluruhan > 0){
            cout<<endl;
            cout << "========== RINGKASAN PESANAN ==========\n";
            for (size_t i = 0; i < pesananList.size(); i++) {
                cout << "- " << pesananList[i] << endl;
            }
            cout << "=======================================\n";
            cout<<"Total yang harus dibayarkan: Rp."<< fixed << setprecision(0) << totalKeseluruhan<<endl;
            cout<<"Lanjut ke pembayaran? (y/n): ";
            cin>>konfirm;
            
            if (konfirm=='y'||konfirm=='Y'){
                cout<<"\nPembayaran berhasil!"<<endl;
                cout<<"Silahkan menunggu makanan atau minumannya. Terimakasih!"<<endl;
                
                ofstream file("pesanan.txt", ios::app);
                if (file.is_open()){
                    file << "================================\n";
                    file << "Username: " << username << endl;
                    file << "Detail Pesanan:\n";
                    for (size_t i = 0; i < pesananList.size(); i++) {
                        file << "- " << pesananList[i] << endl;
                    }
                    file << "Total Pembayaran: Rp." << fixed << setprecision(0) << totalKeseluruhan << endl;
                    file << "================================\n\n";
                    file.close();
                } else {
                    cout << "Gagal menyimpan pesanan ke file!\n";
                }
            }else{
                cout<<"Pesanan dibatalkan.\n";
            }
        }
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
                cin.ignore(); // Tambahkan ini!
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

    void riwayatTransaksi() {
        ifstream file("pesanan.txt");
        if (!file.is_open()) {
            cout << "\nBelum ada riwayat transaksi.\n";
            return;
        }
        
        cout << "\n========== RIWAYAT TRANSAKSI ==========\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void pencarianKomputer() {
        string kategori;
        cout << "\nMasukkan kategori komputer yang ingin dicari (Gaming/Office/Internet): ";
        cin >> kategori;
        
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            if (daftarKomputer[i].kategori == kategori) {
                cout << "Kode: " << daftarKomputer[i].kode 
                     << ", Deskripsi: " << daftarKomputer[i].deskripsi 
                     << ", Harga/Jam: Rp " << fixed << setprecision(0) << daftarKomputer[i].hargaPerJam 
                     << ", Status: " << (daftarKomputer[i].tersedia ? "Tersedia" : "Terpakai") << endl;
            }
        }
    }

    void pendapatanAdmin() {
        double totalPendapatan = 0.0;
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            totalPendapatan += daftarBooking[i].biaya;
        }
        cout << "\nTotal Pendapatan dari Booking: Rp " << fixed << setprecision(0) << totalPendapatan << endl;
    }

    void tambahWaktuKomputer() {
        string kode;
        cout << "\nMasukkan kode komputer yang ingin ditambahkan billing: ";
        cin >> kode;
        for (size_t i = 0; i < daftarKomputer.size(); i++) {
            if (daftarKomputer[i].kode == kode) {
                if (!daftarKomputer[i].tersedia) {
                    double biaya;
                    cout << "Masukkan biaya tambahan untuk komputer " << kode << ": Rp ";
                    cin >> biaya;
                    daftarKomputer[i].hargaPerJam += biaya;
                    cout << "Biaya tambahan berhasil ditambahkan!\n";
                    simpanDataKomputer();
                } else {
                    cout << "Komputer " << kode << " tidak sedang disewa!\n";
                }
                return;
            }
        }
        cout << "Komputer dengan kode " << kode << " tidak ditemukan!\n";
    }

    void lihatBooking2(){
        if (daftarBooking.empty()) {
            cout << "\nBelum ada booking komputer.\n";
            return;
        }
        
        cout << "\n========== DAFTAR BOOKING KOMPUTER ==========\n";
        cout << "|" << setw(12) << left << "Username"
             << "|" << setw(8) << left << "Kode PC"
             << "|" << setw(12) << left << "Tanggal"
             << "|" << setw(13) << left << "Waktu"
             << "|" << setw(10) << left << "Biaya" << "|\n";
        cout << string(70, '=') << "\n";
        
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            const BookingInfo &booking = daftarBooking[i];
            string waktu = booking.waktuMulai + "-" + booking.waktuSelesai;
            cout << "|" << setw(12) << left << booking.username.substr(0, 11)
                 << "|" << setw(8) << left << booking.kodeKomputer.substr(0, 7)
                 << "|" << setw(12) << left << booking.tanggal.substr(0, 11)
                 << "|" << setw(13) << left << waktu.substr(0, 12)
                 << "|Rp " << setw(7) << left << fixed << setprecision(0) 
                 << booking.biaya << "|\n";
            }
    }

    void riwayatPribadi() {
        cout << "\n===== RIWAYAT BOOKING ANDA =====\n";
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            if (daftarBooking[i].username == username) {
                cout << "- " << daftarBooking[i].kodeKomputer << " | "
                     << daftarBooking[i].tanggal << " | "
                     << daftarBooking[i].waktuMulai << "-" << daftarBooking[i].waktuSelesai
                     << " | Rp" << daftarBooking[i].biaya << endl;
            }
        }
    }

    void statistikHarian() {
        string tanggal;
        cout << "Masukkan tanggal (DD/MM/YYYY): ";
        cin >> tanggal;
        double total = 0;
        int count = 0;
        for (size_t i = 0; i < daftarBooking.size(); i++) {
            if (daftarBooking[i].tanggal == tanggal) {
                total += daftarBooking[i].biaya;
                count++;
            }
        }
        cout << "Total booking hari " << tanggal << ": " << count << " transaksi, Rp" << total << endl;
    }

    void ubahPassword() {
        string lama, baru;
        cout << "Masukkan password lama: ";
        cin >> lama;
        for (size_t i = 0; i < daftarMember.size(); i++) {
            if (daftarMember[i].username == username && daftarMember[i].password == lama) {
                cout << "Masukkan password baru: ";
                cin >> baru;
                daftarMember[i].password = baru;
                simpanDataMember();
                cout << "Password berhasil diubah!\n";
                return;
            }
        }
        cout << "Password lama salah!\n";
    }

    void topUpSaldo() {
    double jumlah;
    cout << "Masukkan jumlah top up: Rp ";
    cin >> jumlah;
    for (size_t i = 0; i < daftarMember.size(); i++) {
        if (daftarMember[i].username == username) {
            daftarMember[i].saldo += jumlah;
            simpanDataMember();
            cout << "Top up berhasil! Saldo Anda sekarang: Rp " << daftarMember[i].saldo << endl;
            return;
        }
    }
    cout << "User tidak ditemukan!\n";
}

void menuMemberAdmin() {
    int pilih;
    do {
        cout << "\n==== MANAJEMEN MEMBER ====\n";
        cout << "1. Lihat Daftar Member\n";
        cout << "2. Tambah Member\n";
        cout << "3. Edit Member\n";
        cout << "4. Hapus Member\n";
        cout << "5. Kembali\n";
        cout << "Pilih: "; cin >> pilih;
        switch (pilih) {
            case 1: tampilkanDaftarMember(); break;
            case 2: tambahMember(); break;
            case 3: editMember(); break;
            case 4: hapusMember(); break;
        }
    } while (pilih != 5);
}

void tampilkanDaftarMember() {
    cout << "\n===== DAFTAR MEMBER =====\n";
    for (size_t i = 0; i < daftarMember.size(); i++) {
        cout << i+1 << ". " << daftarMember[i].username
             << " | Poin: " << daftarMember[i].poin
             << " | Saldo: Rp" << daftarMember[i].saldo << endl;
    }
}

void tambahMember() {
    Member m;
    cout << "Username: "; cin >> m.username;
    cout << "Password: "; cin >> m.password;
    m.poin = 0; m.saldo = 0;
    daftarMember.push_back(m);
    simpanDataMember();
    cout << "Member berhasil ditambahkan!\n";
}

void editMember() {
    string uname;
    cout << "Masukkan username member yang ingin diedit: ";
    cin >> uname;
    for (size_t i = 0; i < daftarMember.size(); i++) {
        if (daftarMember[i].username == uname) {
            cout << "Password baru: "; cin >> daftarMember[i].password;
            cout << "Saldo baru: "; cin >> daftarMember[i].saldo;
            simpanDataMember();
            cout << "Data member berhasil diupdate!\n";
            return;
        }
    }
    cout << "Member tidak ditemukan!\n";
}

void hapusMember() {
    string uname;
    cout << "Masukkan username member yang ingin dihapus: ";
    cin >> uname;
    for (size_t i = 0; i < daftarMember.size(); i++) {
        if (daftarMember[i].username == uname) {
            daftarMember.erase(daftarMember.begin() + i);
            simpanDataMember();
            cout << "Member berhasil dihapus!\n";
            return;
        }
    }
    cout << "Member tidak ditemukan!\n";
}

void simpanDataMember() {
    ofstream file("member.txt");
    for (size_t i = 0; i < daftarMember.size(); i++) {
        file << daftarMember[i].username << "|"
             << daftarMember[i].password << "|"
             << daftarMember[i].poin << "|"
             << daftarMember[i].saldo << "\n";
    }
    file.close();
}

void muatDataMember() {
    daftarMember.clear();
    ifstream file("member.txt");
    string line;
    while (getline(file, line)) {
        Member m;
        stringstream ss(line);
        string temp;
        
        getline(ss, m.username, '|');
        getline(ss, m.password, '|');

      
        getline(ss, temp, '|');
        stringstream(temp) >> m.poin;

    
        getline(ss, temp, '|');
        stringstream(temp) >> m.saldo;

        daftarMember.push_back(m);
    }
    file.close();
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
    //ewe ayam
}