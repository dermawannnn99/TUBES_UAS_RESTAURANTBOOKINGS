#include <iostream>  // Untuk input dan output
#include <string>    // Untuk string
#include <vector>    // Untuk penggunaan vector
#include <chrono>    // Untuk menggunakan waktu
#include <thread>    // Untuk menunda eksekusi

using namespace std;  // Menggunakan namespace std agar tidak perlu menulis std::

// Struktur untuk menyimpan data pesanan
struct Pesanan {
    string nama_makanan;  // Nama makanan
    int harga;            // Harga makanan
    int jumlah;           // Jumlah pesanan
};

// Fungsi untuk menghitung total harga dari semua pesanan
int hitungTotalHarga(vector<Pesanan>& pesanan) {
    int total = 0;  // Inisialisasi total harga
    for (const auto& p : pesanan) {  // Loop melalui semua item pesanan
        total += p.harga * p.jumlah;  // Menghitung total harga tiap item dan menjumlahkannya
    }
    return total;  // Mengembalikan total harga
}

// Fungsi untuk menghitung diskon berdasarkan total harga
float hitungDiskon(float total_harga) {
    if (total_harga > 100000) {  // Jika total harga lebih dari Rp 100.000
        return total_harga * 0.20;  // Diskon 20% dari total harga
    }
    return 0;  // Tidak ada diskon jika kurang dari atau sama dengan Rp 100.000
}

// Fungsi untuk menghitung kembalian dari uang yang dibayarkan
int hitungKembalian(int total, int bayar) {
    return bayar - total;  // Menghitung selisih antara uang bayar dan total harga
}

// Fungsi untuk menghitung PPN sebesar 1% dari total harga
int hitungPPN(int total_harga) {
    return total_harga * 0.01;  // PPN 1% dari total harga
}

// Fungsi untuk meminta pengguna memasukkan jumlah uang yang dibayarkan
int mintaUangBayar(int total_harga) {
    int uang_bayar;  // Variabel untuk menyimpan jumlah uang bayar
    do {  // Loop hingga pengguna memasukkan uang yang cukup
        cout << "Masukkan jumlah uang anda\t: Rp ";  // Meminta input jumlah uang bayar
        cin >> uang_bayar;  // Membaca input dari pengguna
        if (uang_bayar < total_harga) {  // Jika uang kurang dari total harga
            cout << "Uang yang dibayarkan kurang! Silakan coba lagi." << endl;  // Memberi peringatan
        }
    } while (uang_bayar < total_harga);  // Ulangi jika uang masih kurang
    return uang_bayar;  // Kembalikan jumlah uang yang valid
}

// Fungsi untuk memeriksa dan memberikan diskon jika kode voucher valid
float cekVoucher() {
    string kodeVoucher;  // Variabel untuk menyimpan input kode voucher
    string kodeValid = "DISKON5";  // Kode voucher yang valid
    float diskon = 0;  // Inisialisasi diskon

    while (true) {  // Loop tanpa batas percobaan
        cout << "==================================================================" << endl;
        cout << "|                                                                |" << endl;
        cout << "|                           PEMBAYARAN                           |" << endl;
        cout << "|          PERIKSA KEMBALI PESANAN DAN NOMINAL UANG ANDA         |" << endl;
        cout << "|                                                                |" << endl;
        cout << "|----------------------------------------------------------------|" << endl;
        cout << "Apakah Anda ingin memasukkan kode voucher? (y/n): ";  // Menanyakan apakah ingin menggunakan kode voucher
        char pilihan;  // Variabel untuk menyimpan pilihan pengguna
        cin >> pilihan;  // Membaca input pilihan
        cin.ignore();  // Membersihkan input buffer

        if (pilihan == 'y' || pilihan == 'Y') {  // Jika pengguna memilih 'y' atau 'Y'
            cout << "Masukkan kode voucher: ";  // Meminta input kode voucher
            getline(cin, kodeVoucher);  // Membaca kode voucher

            if (kodeVoucher == kodeValid) {  // Jika kode voucher valid
                cout << "Kode voucher valid! Diskon 5% diterapkan." << endl;  // Memberikan informasi diskon
                diskon = 0.05;  // Diskon 5%
                break;  // Keluar dari loop
            } else {  // Jika kode voucher tidak valid
                cout << "Kode voucher tidak valid." << endl;  // Memberi peringatan
            }
        } else {  // Jika pengguna tidak ingin menggunakan kode voucher
            break;  // Keluar dari loop
        }
    }

    return diskon;  // Mengembalikan nilai diskon
}

// Fungsi untuk menampilkan menu makanan dan minuman
void tampilkanMenu(string menu_makanan[], int harga_makanan[], int jumlah_menu,
                   string menu_minuman[], int harga_minuman[], int jumlah_minuman) {
    system("CLS");  // Membersihkan layar
    cout << "==========================================" << endl;
    cout << "|                                        |" << endl;
    cout << "|    BERIKUT MENU YANG KAMI TAWARKAN     |" << endl;
    cout << "|                                        |" << endl;
    cout << "==========================================" << endl;
    cout << "||MENU MAKANAN----------------------------" << endl;
    cout << "No.\tNama Menu\t\tHarga" << endl;

    // Menampilkan menu makanan
    for (int i = 0; i < jumlah_menu; i++) {
        cout << i + 1 << ".\t" << menu_makanan[i] << "\tRp " << harga_makanan[i] << endl;
    }

    // Menampilkan menu minuman
    cout << "||MENU MINUMAN----------------------------" << endl;
    for (int i = 0; i < jumlah_minuman; i++) {
        cout << i + 1 << ".\t" << menu_minuman[i] << "\tRp " << harga_minuman[i] << endl;
    }
    cout << "==========================================" << endl;
}

// Fungsi untuk menampilkan tampilan awal
void tampilkanTampilanAwal() {
    // Menampilkan header
    system("CLS");  // Membersihkan layar
    cout << "======================================================================" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                 >AYAM NUSANTARA, PILIHAN MAHASISWA<                |" << endl;
    cout << "|                          LOADING PAGE...                           |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                                                                    |" << endl;
    cout << "|                          @ayam.nusantara_                          |" << endl;
    cout << "|                 layanan kami : bit.ly/anus.enakkkk                 |" << endl;
    cout << "======================================================================" << endl;
    cout << endl;
    cout << "||Tekan ENTER untuk masuk" << endl;
    cin.get();  // Menunggu tombol ENTER dari pengguna sebelum melanjutkan

    // Hitung mundur 5 detik
    for (int i = 5; i > 0; i--) {
        system("CLS");  // Membersihkan layar
        cout << "======================================================================" << endl;
        cout << "|                                                                    |" << endl;
        cout << "|                 >AYAM NUSANTARA, PILIHAN MAHASISWA<                |" << endl;
        cout << "|                          LOADING PAGE...                           |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "|                                                                    |" << endl;
        cout << "|                          @ayam.nusantara_                          |" << endl;
        cout << "|                 layanan kami : bit.ly/anus.enakkkk                 |" << endl;
        cout << "======================================================================" << endl;
        cout << endl;
        cout << "| Anda akan masuk dalam " << i << " detik..." << endl;
        this_thread::sleep_for(chrono::seconds(1));  // Delay 1 detik
    }
}

int main() {
    string nama_customer; // Variabel untuk menyimpan nama customer
    int jumlah_pesanan; // Variabel untuk menyimpan jumlah pesanan
    vector<Pesanan> pesanan; // Vector untuk menyimpan daftar pesanan

    const int jumlah_menu = 8; // Konstanta jumlah menu makanan
    string menu_makanan[jumlah_menu] = {"Geprek Bakar Special", "Geprek Bakar BBQ",
                                        "Geprek Bakar Keju", "Geprek Bakar LadaHitam", "Ayam Bakar + Lalapan", "Ayam Serundeng+Lalapan",
                                        "Geprek Biasa+Lalapan", "Tambahan Nasi Putih"}; // Array untuk menyimpan nama-nama menu makanan
    int harga_makanan[jumlah_menu] = {25000, 12000, 10000, 15000, 15000, 10000, 7000, 5000}; // Array untuk menyimpan harga masing-masing menu makanan

    // Menu Minuman
    const int jumlah_minuman = 6; // Konstanta jumlah menu minuman
    string menu_minuman[jumlah_minuman] = {"Es Teh Manis enak","Es Teh Hangat enak", "Es Teh Tawar enak", "Es Jeruk Peras enak", "Air Mineral enak", "Jus Mangga enakkk"}; // Array untuk menyimpan nama-nama menu minuman
    int harga_minuman[jumlah_minuman] = {5000,5000 ,3000, 5000, 3000, 12000}; // Array untuk menyimpan harga masing-masing menu minuman

    int pilihan; // Variabel untuk menyimpan pilihan menu utama
    do {
        tampilkanTampilanAwal (); // Memanggil fungsi untuk menampilkan tampilan awal

        // Login
        do {
            system("CLS"); // Membersihkan layar
            cout << "==================================================================" << endl;
            cout << "|                                                                |" << endl;
            cout << "|              SELAMAT DATANG DI RESTO AYAM NUSANTARA            |" << endl;
            cout << "|                  KEPUASAN ANDA PRIORITAS KAMI                  |" << endl;
            cout << "|                                                                |" << endl;
            cout << "|----------------------------------------------------------------|" << endl;
            cout << "|  | Masukkan nama anda untuk login:                             |" << endl;
            cout << "     => ";
                              getline(cin, nama_customer); // Mengambil input nama customer

                if (nama_customer.empty()) { // Mengecek apakah input nama kosong
                    cout << "Nama tidak boleh kosong! Silakan masukkan nama Anda." << endl;
                }
            } while (nama_customer.empty()); // Ulangi jika input nama kosong

            // Tampilkan promo setelah login
            system("CLS"); // Membersihkan layar
            cout << "| SELAMAT DATANG, " << nama_customer << "!" << endl; // Menampilkan pesan selamat datang
            cout << endl;
            cout << "======================================================================" << endl;
            cout << "|                                                                    |" << endl;
            cout << "|                     PENAWARAN HANGAT MINGGU INI                    |" << endl;
            cout << "|                                                                    |" << endl;
            cout << "|        DAPATKAN DISKON 20%       |   DAPATKAN VOUCHER SPESIAL 5%   |" << endl;
            cout << "|   SETIAP PEMBELIAN DIATAS 100K   |     TANPA MINIMUM PEMBELIAN     |" << endl;
            cout << "|         SUPEER HEMATTT !         |         KODE : DISKON5          |" << endl;
            cout << "|                                                                    |" << endl;
            cout << "|                                                                    |" << endl;
            cout << "======================================================================" << endl;
            cout << endl;
            cout << "| Tekan Enter";
            cin.get();    // Menunggu Enter dari pengguna

            do {
                system("CLS"); // Membersihkan layar
                cout << "| SELAMAT DATANG, " << nama_customer << "!" << endl; // Menampilkan pesan selamat datang
                cout << "==================================================================" << endl;
                cout << "|                                                                |" << endl;
                cout << "|                      RESTO AYAM NUSANTARA                      |" << endl;
                cout << "|                          HALAMAN UTAMA                         |" << endl;
                cout << "|                                                                |" << endl;
                cout << "|----------------------------------------------------------------|" << endl;
                cout << "| 1. Memesan Menu Disini                                         |" << endl;
                cout << "| 2. Lihat Pesanan                                               |" << endl;
                cout << "| 3. Hapus Pesanan                                               |" << endl;
                cout << "| 4. Lakukan Pembayaran                                          |" << endl;
                cout << "| 5. Logout                                                      |" << endl;
                cout << "==================================================================" << endl;
                cout << endl;
                cout << "  | Pilih menu (1-5): ";
                cin >> pilihan; // Mengambil input pilihan menu utama
                cin.ignore(); // Membersihkan karakter newline di buffer

switch (pilihan) { // Memulai struktur kontrol untuk memproses pilihan pengguna
    case 1: { // Case 1: Tampilkan Menu dan Pesan
        tampilkanMenu(menu_makanan, harga_makanan, jumlah_menu, menu_minuman, harga_minuman, jumlah_minuman); // Memanggil fungsi untuk menampilkan menu makanan dan minuman

        int jumlah; // Variabel untuk menyimpan jumlah pesanan
        cout << "| Masukkan jumlah pesanan: " << endl; // Meminta input jumlah pesanan
        cout << "=> ";
        cin >> jumlah; // Membaca input jumlah pesanan dari pengguna

        for (int i = 0; i < jumlah; i++) { // Perulangan untuk setiap pesanan
            int pilihan_item; // Variabel untuk menyimpan pilihan item
            char jenis_item; // Variabel untuk menyimpan jenis item (M/I)
            do { // Perulangan untuk validasi input jenis item
                cout << "--------------------------" << endl; // Garis pembatas untuk memperjelas tampilan
                cout << "| Masukkan jenis pesanan (M untuk makanan / I untuk minuman): " << endl; // Meminta input jenis pesanan
                cout << "=> ";
                cin >> jenis_item; // Membaca input jenis pesanan

                if (jenis_item == 'M' || jenis_item == 'm') { // Kondisi jika pesanan adalah makanan
                    int pilihan_makanan; // Variabel untuk menyimpan pilihan makanan
                    do { // Perulangan untuk validasi input pilihan makanan
                        cout << "--------------------------" << endl; // Garis pembatas
                        cout << "| Masukkan nomor makanan ke-" << i + 1 << ": " << endl; // Meminta input nomor makanan
                        cout << "=> ";
                        cin >> pilihan_makanan; // Membaca input nomor makanan
                        if (pilihan_makanan < 1 || pilihan_makanan > jumlah_menu) { // Validasi jika nomor makanan tidak valid
                            cout << "Pilihan tidak valid! Silakan pilih antara 1 sampai " << jumlah_menu << endl; // Pesan error jika input tidak valid
                        }
                    } while (pilihan_makanan < 1 || pilihan_makanan > jumlah_menu); // Ulangi sampai input valid

                    Pesanan p; // Membuat objek Pesanan untuk menyimpan data pesanan
                    p.nama_makanan = menu_makanan[pilihan_makanan - 1]; // Mengisi nama makanan berdasarkan pilihan
                    p.harga = harga_makanan[pilihan_makanan - 1]; // Mengisi harga makanan berdasarkan pilihan
                    cout << "--------------------------" << endl; // Garis pembatas
                    cout << "| Masukkan jumlah " << p.nama_makanan << ": " << endl; // Meminta input jumlah makanan
                    cout << "=> ";
                    cin >> p.jumlah; // Membaca input jumlah makanan
                    pesanan.push_back(p); // Menambahkan objek pesanan ke dalam daftar pesanan
                    break; // Keluar dari kondisi makanan

                } else if (jenis_item == 'I' || jenis_item == 'i') { // Kondisi jika pesanan adalah minuman
                    int pilihan_minuman; // Variabel untuk menyimpan pilihan minuman
                    do { // Perulangan untuk validasi input pilihan minuman
                        cout << "--------------------------" << endl; // Garis pembatas
                        cout << "| Masukkan nomor minuman ke-" << i + 1 << ": " << endl; // Meminta input nomor minuman
                        cout << "=> ";
                        cin >> pilihan_minuman; // Membaca input nomor minuman
                        if (pilihan_minuman < 1 || pilihan_minuman > jumlah_minuman) { // Validasi jika nomor minuman tidak valid
                            cout << "Pilihan tidak valid! Silakan pilih antara 1 sampai " << jumlah_minuman << endl; // Pesan error jika input tidak valid
                        }
                    } while (pilihan_minuman < 1 || pilihan_minuman > jumlah_minuman); // Ulangi sampai input valid

                    Pesanan p; // Membuat objek Pesanan untuk menyimpan data pesanan
                    p.nama_makanan = menu_minuman[pilihan_minuman - 1]; // Mengisi nama minuman berdasarkan pilihan
                    p.harga = harga_minuman[pilihan_minuman - 1]; // Mengisi harga minuman berdasarkan pilihan
                    cout << "--------------------------" << endl; // Garis pembatas
                    cout << "| Masukkan jumlah " << p.nama_makanan << ": " << endl; // Meminta input jumlah minuman
                    cout << "=> ";
                    cin >> p.jumlah; // Membaca input jumlah minuman
                    pesanan.push_back(p); // Menambahkan objek pesanan ke dalam daftar pesanan
                    break; // Keluar dari kondisi minuman
                } else { // Kondisi jika input jenis item tidak valid
                    cout << "Pilihan tidak valid. Silakan pilih M atau I." << endl; // Pesan error jika input tidak valid
                }
            } while (jenis_item != 'M' && jenis_item != 'm' && jenis_item != 'I' && jenis_item != 'i'); // Ulangi sampai input valid
        }
        // Pesan konfirmasi setelah semua makanan selesai diinput
        cout << "Pesanan Anda telah berhasil ditambahkan. Tekan Enter untuk kembali ke halaman utama."; // Pesan konfirmasi
        cin.ignore(); // Menangkap newline setelah input jumlah pesanan terakhir
        cin.get();    // Menunggu Enter dari pengguna
        system("CLS"); // Membersihkan layar
        break; // Keluar dari case 1
    }
    case 2: { // case 2: Lihat Pesanan
        system("CLS"); // Membersihkan layar untuk tampilan yang lebih bersih
        if (pesanan.empty()) { // Mengecek apakah daftar pesanan kosong
            cout << "==================================================================" << endl; // Garis pembatas
            cout << "|                                                                |" << endl; // Tampil pesan jika pesanan kosong
            cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl; // Pesan jika tidak ada pesanan
            cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl; // Memberikan instruksi untuk kembali ke halaman utama
            cout << "|                                                                |" << endl; // Garis pembatas
            cout << "|----------------------------------------------------------------|" << endl; // Garis pembatas

        } else { // Jika pesanan tidak kosong
            cout << "| DAFTAR PESANAN ANDA :\n"; // Tampil daftar pesanan
            cout << endl; // Baris kosong untuk pemisah
            cout << "Nama Menu\t\tJumlah\tHarga" << endl; // Menampilkan header untuk nama menu, jumlah, dan harga
            cout << "---------------------------------" << endl; // Garis pembatas
            for (const auto& p : pesanan) { // Perulangan untuk menampilkan setiap pesanan
                cout << p.nama_makanan << "\t" << " x " << p.jumlah << "\t" << " = Rp " << p.harga * p.jumlah << endl; // Menampilkan nama, jumlah, dan total harga untuk setiap pesanan
            }
        }
        cout << endl; // Baris kosong untuk pemisah
        cout << "Tekan Enter untuk kembali ke menu utama."; // Instruksi untuk kembali ke menu utama
        cin.get(); // Menunggu input dari pengguna (tekan Enter)
        break; // Keluar dari case 2
    }
    case 3: { //case 3 : Hapus Pesanan
        system("CLS"); // Membersihkan layar
        if (pesanan.empty()) { // Mengecek jika tidak ada pesanan
            cout << "==================================================================" << endl; // Garis pembatas
            cout << "|                                                                |" << endl; // Pesan jika tidak ada pesanan
            cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl; // Pesan jika pesanan kosong
            cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl; // Instruksi untuk kembali ke menu utama
            cout << "|                                                                |" << endl; // Garis pembatas
            cout << "|----------------------------------------------------------------|" << endl; // Garis pembatas
        } else { // Jika ada pesanan
            int index;
            cout << "| DAFTAR PESANAN ANDA :\n"; // Menampilkan daftar pesanan
            cout << endl; // Baris kosong untuk pemisah
            cout << "No.\tNama Menu\t\tJumlah" << endl; // Menampilkan header untuk daftar pesanan
            cout << "---------------------------------------" << endl; // Garis pembatas
            for (size_t i = 0; i < pesanan.size(); i++) { // Perulangan untuk menampilkan setiap pesanan
                cout << i + 1 << ".\t" << pesanan[i].nama_makanan << "\tx " << pesanan[i].jumlah << endl; // Menampilkan nama dan jumlah pesanan
            }
            cout << endl; // Baris kosong untuk pemisah
            cout << "| Masukkan nomor pesanan yang ingin dihapus: " << endl; // Instruksi untuk memasukkan nomor pesanan yang ingin dihapus
            cout << "=> ";
            cin >> index; // Input nomor pesanan yang ingin dihapus
            cin.ignore(); // Mengabaikan karakter newline yang tertinggal

            if (index > 0 && index <= pesanan.size()) { // Memeriksa apakah nomor pesanan valid
                cout << "| Apakah Anda yakin ingin menghapus pesanan ini? (Y/N): "; // Menanyakan konfirmasi penghapusan
                char konfirmasi;
                cin >> konfirmasi;
                if (konfirmasi == 'Y' || konfirmasi == 'y') { // Jika pengguna yakin menghapus
                    pesanan.erase(pesanan.begin() + index - 1); // Menghapus pesanan dari daftar
                    cout << "Pesanan berhasil dihapus." << endl; // Menampilkan pesan berhasil
                } else { // Jika pengguna membatalkan penghapusan
                    cout << "Penghapusan pesanan dibatalkan." << endl;
                }
            } else {
                cout << "Nomor pesanan tidak valid." << endl; // Menampilkan pesan jika nomor pesanan tidak valid
            }
        }

        cout << "Tekan Enter untuk kembali ke menu utama."; // Instruksi untuk kembali ke menu utama
        cin.get(); // Menunggu input pengguna sebelum melanjutkan
        break; // Keluar dari case 3
    }
    case 4: { // Checkout
        system("CLS"); // Membersihkan layar
        if (pesanan.empty()) { // Mengecek apakah pesanan kosong
            cout << "==================================================================" << endl; // Garis pembatas
            cout << "|                                                                |" << endl; // Pesan jika tidak ada pesanan
            cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl; // Pesan jika pesanan kosong
            cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl; // Instruksi untuk kembali ke menu utama
            cout << "|                                                                |" << endl; // Garis pembatas
            cout << "|----------------------------------------------------------------|" << endl; // Garis pembatas
        } else { // Jika pesanan tidak kosong
            int total_harga = hitungTotalHarga(pesanan); // Menghitung total harga pesanan

            // Hitung PPN sebelum diskon
            int ppn = hitungPPN(total_harga); // Menghitung PPN (Pajak Pertambahan Nilai)

            // Terapkan diskon 20% jika total harga lebih dari 100.000
            float diskon = hitungDiskon(total_harga); // Menghitung diskon
            total_harga -= diskon; // Mengurangi total harga dengan diskon

            if (diskon > 0) { // Jika ada diskon
                cout << "Diskon 20% karena pembelian di atas Rp 100.000: Rp " << diskon << endl; // Menampilkan nilai diskon
            }

            // Memanggil fungsi cekVoucher untuk mengecek kode voucher
            float diskonVoucher = cekVoucher();  // Diskon 5% jika kode voucher valid
            total_harga -= total_harga * diskonVoucher; // Mengurangi total harga dengan diskon voucher

            total_harga += ppn;  // Menambahkan PPN setelah diskon dan voucher

            cout << endl;
            cout << "Total Harga    : Rp " << hitungTotalHarga(pesanan) << endl; // Menampilkan total harga
            cout << "PPN (1%)       : Rp " << ppn << endl; // Menampilkan PPN
            cout << "Diskon         : Rp " << diskon << endl; // Menampilkan diskon
            cout << "Diskon Voucher : Rp " << diskonVoucher << endl; // Menampilkan diskon voucher

            cout << "--------------------------------------------" << endl; // Garis pembatas
            cout << "|    TOTAL YANG HARUS DIBAYAR: Rp " << total_harga << "    |" << endl; // Menampilkan total yang harus dibayar
            cout << "--------------------------------------------" << endl; // Garis pembatas
            cout << "Tekan Enter untuk melanjutkan pembayaran."; // Instruksi untuk melanjutkan ke pembayaran
            cin.get(); // Menunggu input pengguna untuk melanjutkan
            system("CLS"); // Membersihkan layar

            // Input metode pembayaran menggunakan switch dengan validasi
            string metode_bayar; // Variabel untuk menyimpan metode pembayaran
            int metode_pilih; // Variabel untuk pilihan metode pembayaran

            do {
                cout << "| TOTAL YANG HARUS DIBAYAR: Rp " << total_harga << endl; // Menampilkan total yang harus dibayar

                cout << "============================================" << endl; // Garis pembatas
                cout << "|                                          |" << endl; // Spasi
                cout << "|         PILIH METODE PEMBAYARAN          |" << endl; // Pilihan metode pembayaran
                cout << "| (1) Tunai                                |" << endl; // Pilihan pembayaran Tunai
                cout << "| (2) Transfer Bank                        |" << endl; // Pilihan pembayaran Transfer Bank
                cout << "| (3) Kartu Kredit                         |" << endl; // Pilihan pembayaran Kartu Kredit
                cout << "|------------------------------------------|" << endl; // Garis pembatas

                cout << "| Masukan nomor pilihan Metode Pembayaran: " << endl; // Instruksi untuk memasukkan pilihan metode pembayaran
                cout << "=> ";
                cin >> metode_pilih; // Input pilihan metode pembayaran

                switch (metode_pilih) { // Pemilihan metode pembayaran berdasarkan input
                    case 1:
                        metode_bayar = "Tunai"; // Jika memilih Tunai
                        break;
                    case 2: {
                        metode_bayar = "Transfer Bank"; // Jika memilih Transfer Bank
                        // Meminta pengguna memilih bank setelah memilih Transfer Bank
                        string bank_pilihan; // Variabel untuk bank yang dipilih
                        int bank_pilih; // Variabel untuk input pilihan bank

                        cout << "Pilihan Bank:\n"; // Menampilkan pilihan bank
                        cout << "1. Bank Mandiri\n"; // Pilihan Bank Mandiri
                        cout << "2. Bank BCA\n"; // Pilihan Bank BCA
                        cout << "3. Bank BNI\n"; // Pilihan Bank BNI
                        do {
                            cout << "| Masukan angka pilihan Bank (1-3) : " << endl; // Instruksi untuk memilih bank
                            cout << "=> ";
                            cin >> bank_pilih; // Input pilihan bank
                            switch (bank_pilih) { // Menentukan bank berdasarkan input
                                case 1: bank_pilihan = "Bank Mandiri"; break; // Bank Mandiri
                                case 2: bank_pilihan = "Bank BCA"; break; // Bank BCA
                                case 3: bank_pilihan = "Bank BNI"; break; // Bank BNI
                                default: cout << "Pilihan bank tidak valid." << endl; break; // Pesan jika pilihan tidak valid
                            }
                        } while (bank_pilih < 1 || bank_pilih > 3); // Loop hingga pilihan bank valid
                        break;
                    }
                    case 3: {
                        metode_bayar = "Kartu Kredit"; // Jika memilih Kartu Kredit
                        // Meminta nomor kartu kredit setelah memilih Kartu Kredit
                        string nomor_kartu; // Variabel untuk nomor kartu kredit
                        cout << "| Masukkan nomor kartu kredit Anda: " << endl; // Instruksi untuk memasukkan nomor kartu kredit
                        cout << "=> ";
                        cin >> nomor_kartu; // Input nomor kartu kredit
                        // Validasi kartu kredit bisa dilakukan di sini jika diperlukan
                        break;
                    }
                    default:
                        cout << "Pilihan tidak valid, silakan pilih 1, 2, atau 3!" << endl; // Pesan jika pilihan tidak valid
                        metode_bayar = ""; // Reset metode_bayar jika input salah
                        break;
                }
            } while (metode_bayar == ""); // Loop hingga pilihan valid diterima

            // Input jumlah uang yang dibayar
            int uang_bayar = mintaUangBayar(total_harga); // Meminta jumlah uang yang dibayar
            int kembalian = hitungKembalian(total_harga, uang_bayar); // Menghitung kembalian

            system("CLS"); // Membersihkan layar
            // Menampilkan struk dengan metode pembayaran
            cout << "      RESTO AYAM NUSANTARA CABANG UNSIKA     " << endl; // Nama restoran
            cout << "      Jl. Ronggo Waluyo, Telukjambe Timur    " << endl; // Alamat restoran
            cout << "               0895 6170 46679               " << endl; // Nomor kontak
            cout << "=============================================" << endl; // Garis pembatas
            cout << "|              STRUK PEMBAYARAN             |" << endl; // Judul struk
            cout << "=============================================" << endl; // Garis pembatas
            cout << "Nama Customer    : " << nama_customer << endl; // Menampilkan nama customer
            cout << "Metode Pembayaran: " << metode_bayar << endl; // Menampilkan metode pembayaran
            cout << "---------------------------------------------" << endl; // Garis pembatas
            for (const auto& p : pesanan) { // Menampilkan detail pesanan
                cout << p.nama_makanan << " x" << p.jumlah << " = Rp " << p.harga * p.jumlah << endl;
            }
            cout << "---------------------------------------------" << endl; // Garis pembatas

            if (diskon > 0) { // Jika ada diskon
                cout << "Diskon (20%)             : Rp " << diskon << endl; // Menampilkan nilai diskon
            }

            cout << "PPN (1%)                 : Rp " << ppn << endl; // Menampilkan PPN
            cout << "Total Harga              : Rp " << total_harga << endl; // Menampilkan total harga

            // Jika pembayaran menggunakan transfer atau kartu kredit, tidak perlu ditampilkan nomor bank atau nomor kartu kredit
            if (metode_bayar == "Tunai") { // Jika pembayaran menggunakan tunai
                cout << "Metode Pembayaran        : Tunai" << endl; // Menampilkan metode pembayaran
            }

            cout << "Uang Bayar               : Rp " << uang_bayar << endl; // Menampilkan uang yang dibayar
            cout << "Kembalian                : Rp " << kembalian << endl; // Menampilkan kembalian
            cout << "=============================================" << endl; // Garis pembatas
            cout << "      terima kasih atas kunjungan nya:)      " << endl; // Pesan terima kasih
            cout << "          k r i t i k  &  s a r a n          " << endl; // Pesan kritik & saran
            cout << "               bit/ly.AnusGacor              " << endl; // Link kritik & saran
            pesanan.clear(); // Menghapus semua pesanan setelah checkout
            cin.ignore(); // Mengabaikan input sebelumnya
        }
        cout << endl << endl; // Baris kosong
        cout << "| Tekan Enter untuk kembali ke menu utama."; // Instruksi untuk kembali ke menu utama
        cin.get(); // Menunggu input pengguna untuk kembali
        break; // Keluar dari case 4
    }
    case 5: { //case 5 : Keluar
        system("CLS"); // Membersihkan layar
        cout << "Terima kasih telah berkunjung!" << endl; // Menampilkan pesan terima kasih

        // Menambahkan animasi mundur selama 5 detik
        for (int i = 0; i < 5; i++) { // Loop untuk animasi mundur
            system("CLS"); // Membersihkan layar

            cout << "=============================================" << endl; // Garis pembatas
            cout << "|        TERIMAKASIH TELAH BERKUNJUNG       |" << endl; // Pesan terima kasih
            cout << "=============================================" << endl; // Garis pembatas
            cout << "Anda akan keluar dalam " << 5 - i << " detik..." << endl; // Menampilkan waktu mundur
            this_thread::sleep_for(chrono::seconds(1)); // Menunggu 1 detik untuk animasi mundur
        }

        // Menunggu 5 detik sebelum kembali ke login
        this_thread::sleep_for(chrono::seconds(5)); // Menunggu 5 detik

        // Bersihkan layar kembali sebelum kembali ke login
        system("CLS"); // Membersihkan layar sebelum keluar
        break; // Keluar dari case 5
    }
    default:
        system("CLS"); // Membersihkan layar
        cout << "Pilihan tidak valid. Silakan pilih lagi." << endl; // Menampilkan pesan jika pilihan tidak valid
        break; // Keluar dari default case
    }
} while (pilihan != 5); // Menjaga agar perulangan terus berjalan hingga pilihan keluar
} while (true); // Perulangan untuk login
            return 0; // Mengakhiri program
            
}

