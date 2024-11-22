    #include <iostream>
    #include <string>
    #include <vector>
    #include <chrono>  // Untuk sleep
    #include <thread>  // Untuk sleep

    using namespace std;

    struct Pesanan {
        string nama_makanan;
        int harga;
        int jumlah;
    };

    int hitungTotalHarga(vector<Pesanan>& pesanan) {
        int total = 0;
        for (const auto& p : pesanan) {
            total += p.harga * p.jumlah;
        }
        return total;
    }

    float hitungDiskon(float total_harga) {
        if (total_harga > 100000) {
            return total_harga * 0.20;
        }
        return 0;
    }

    int hitungKembalian(int total, int bayar) {
        return bayar - total;
    }

    int hitungPPN(int total_harga) {
        return total_harga * 0.01;
    }

    int mintaUangBayar(int total_harga) {
        int uang_bayar;
        do {
            cout << "Masukkan jumlah uang anda\t: Rp ";
            cin >> uang_bayar;
            if (uang_bayar < total_harga) {
                cout << "Uang yang dibayarkan kurang! Silakan coba lagi." << endl;
            }
        } while (uang_bayar < total_harga);
        return uang_bayar;
    }

    // Fungsi untuk memeriksa dan memberikan diskon jika kode voucher valid
    float cekVoucher() {
        string kodeVoucher;
        string kodeValid = "DISKON5";  // Kode voucher yang valid
        float diskon = 0;

        while (true) {  // Looping tanpa batas percobaan
            cout << "==================================================================" << endl;
            cout << "|                                                                |" << endl;
            cout << "|                           PEMBAYARAN                           |" << endl;
            cout << "|          PERIKSA KEMBALI PESANAN DAN NOMINAL UANG ANDA         |" << endl;
            cout << "|                                                                |" << endl;
            cout << "|----------------------------------------------------------------|" << endl;
            cout << "Apakah Anda ingin memasukkan kode voucher? (y/n): ";
            char pilihan;
            cin >> pilihan;
            cin.ignore();  // Membersihkan input buffer

            if (pilihan == 'y' || pilihan == 'Y') {
                cout << "Masukkan kode voucher: ";
                getline(cin, kodeVoucher);

                if (kodeVoucher == kodeValid) {
                    cout << "Kode voucher valid! Diskon 5% diterapkan." << endl;
                    diskon = 0.05;  // Diskon 5%
                    break;  // Keluar dari loop jika kode valid
                } else {
                    cout << "Kode voucher tidak valid." << endl;
                }
            } else {
                break;  // Keluar dari loop jika tidak ingin memasukkan voucher
            }
        }

        return diskon;
    }

    void tampilkanMenu(string menu_makanan[], int harga_makanan[], int jumlah_menu,
                       string menu_minuman[], int harga_minuman[], int jumlah_minuman) {
        system("CLS"); // Membersihkan layar
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
            system("CLS");
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
            cin.get(); // Menunggu tombol ENTER dari pengguna sebelum melanjutkan

            // Hitung mundur 5 detik
            for (int i = 5; i > 0; i--) {
                system("CLS");
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
            this_thread::sleep_for(chrono::seconds(1)); // Delay 1 detik
            }
        }

    int main() {
        string nama_customer;
        int jumlah_pesanan;
        vector<Pesanan> pesanan;

        const int jumlah_menu = 8;
        string menu_makanan[jumlah_menu] = {"Geprek Bakar Special", "Geprek Bakar BBQ",
                                            "Geprek Bakar Keju", "Geprek Bakar LadaHitam", "Ayam Bakar + Lalapan", "Ayam Serundeng+Lalapan",
                                            "Geprek Biasa+Lalapan", "Tambahan Nasi Putih"};
        int harga_makanan[jumlah_menu] = {25000, 12000, 10000, 15000, 15000, 10000, 7000, 5000};

        // Menu Minuman
        const int jumlah_minuman = 6;
        string menu_minuman[jumlah_minuman] = {"Es Teh Manis enak","Es Teh Hangat enak", "Es Teh Tawar enak", "Es Jeruk Peras enak", "Air Mineral enak", "Jus Mangga enakkk"};
        int harga_minuman[jumlah_minuman] = {5000,5000 ,3000, 5000, 3000, 12000};

        int pilihan;
        do {
            tampilkanTampilanAwal ();

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
                              getline(cin, nama_customer);

                if (nama_customer.empty()) {
                    cout << "Nama tidak boleh kosong! Silakan masukkan nama Anda." << endl;
                }
            } while (nama_customer.empty()); // Ulangi jika input nama kosong

            // Tampilkan promo setelah login
            system("CLS"); // Membersihkan layar
            cout << "| SELAMAT DATANG, " << nama_customer << "!" << endl;
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
                system("CLS");
                cout << "| SELAMAT DATANG, " << nama_customer << "!" << endl;
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
                cin >> pilihan;
                cin.ignore();

                switch (pilihan) {
                    case 1: { // Tampilkan Menu dan Pesan
                        tampilkanMenu(menu_makanan, harga_makanan, jumlah_menu, menu_minuman, harga_minuman, jumlah_minuman);

                        int jumlah;
                        cout << "| Masukkan jumlah pesanan: " << endl;
                        cout << "=> ";
                        cin >> jumlah;

                        for (int i = 0; i < jumlah; i++) {
                            int pilihan_item;
                            char jenis_item;
                            do {
                                cout << "--------------------------" << endl;
                                cout << "| Masukkan jenis pesanan (M untuk makanan / I untuk minuman): " << endl;
                                cout << "=> ";
                                cin >> jenis_item;

                                if (jenis_item == 'M' || jenis_item == 'm') {
                                    int pilihan_makanan;
                                    do {
                                        cout << "--------------------------" << endl;
                                        cout << "| Masukkan nomor makanan ke-" << i + 1 << ": " << endl;
                                        cout << "=> ";
                                        cin >> pilihan_makanan;
                                        if (pilihan_makanan < 1 || pilihan_makanan > jumlah_menu) {
                                            cout << "Pilihan tidak valid! Silakan pilih antara 1 sampai " << jumlah_menu << endl;
                                        }
                                    } while (pilihan_makanan < 1 || pilihan_makanan > jumlah_menu);

                                    Pesanan p;
                                    p.nama_makanan = menu_makanan[pilihan_makanan - 1];
                                    p.harga = harga_makanan[pilihan_makanan - 1];
                                    cout << "--------------------------" << endl;
                                    cout << "| Masukkan jumlah " << p.nama_makanan << ": " << endl;
                                    cout << "=> ";
                                    cin >> p.jumlah;
                                    pesanan.push_back(p);
                                    break;
                                } else if (jenis_item == 'I' || jenis_item == 'i') {
                                    int pilihan_minuman;
                                    do {
                                        cout << "--------------------------" << endl;
                                        cout << "| Masukkan nomor minuman ke-" << i + 1 << ": " << endl;
                                        cout << "=> ";
                                        cin >> pilihan_minuman;
                                        if (pilihan_minuman < 1 || pilihan_minuman > jumlah_minuman) {
                                            cout << "Pilihan tidak valid! Silakan pilih antara 1 sampai " << jumlah_minuman << endl;
                                        }
                                    } while (pilihan_minuman < 1 || pilihan_minuman > jumlah_minuman);

                                    Pesanan p;
                                    p.nama_makanan = menu_minuman[pilihan_minuman - 1];
                                    p.harga = harga_minuman[pilihan_minuman - 1];
                                    cout << "--------------------------" << endl;
                                    cout << "| Masukkan jumlah " << p.nama_makanan << ": " << endl;
                                    cout << "=> ";
                                    cin >> p.jumlah;
                                    pesanan.push_back(p);
                                    break;
                                } else {
                                    cout << "Pilihan tidak valid. Silakan pilih M atau I." << endl;
                                }
                            } while (jenis_item != 'M' && jenis_item != 'm' && jenis_item != 'I' && jenis_item != 'i');
                        }
                        // Pesan konfirmasi setelah semua makanan selesai diinput
                        cout << "Pesanan Anda telah berhasil ditambahkan. Tekan Enter untuk kembali ke halaman utama.";
                        cin.ignore(); // Menangkap newline setelah input jumlah pesanan terakhir
                        cin.get();    // Menunggu Enter dari pengguna
                        system("CLS"); // Membersihkan layar
                        break;
                    }
                    case 2: { // Lihat Pesanan
                        system("CLS"); // Membersihkan layar
                        if (pesanan.empty()) {
                                cout << "==================================================================" << endl;
                                cout << "|                                                                |" << endl;
                                cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl;
                                cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl;
                                cout << "|                                                                |" << endl;
                                cout << "|----------------------------------------------------------------|" << endl;
                        } else {
                            cout << "| DAFTAR PESANAN ANDA :\n";
                            cout << endl;
                            cout << "Nama Menu\t\tJumlah\tHarga" << endl;
                            cout << "---------------------------------" << endl;
                            for (const auto& p : pesanan) {
                                cout << p.nama_makanan << "\t" << " x " << p.jumlah << "\t" << " = Rp " << p.harga * p.jumlah << endl;
                            }
                        }
                        cout << endl;
                        cout << "Tekan Enter untuk kembali ke menu utama.";
                        cin.get();
                        break;
                    }
                    case 3: { // Hapus Pesanan
                        system("CLS"); // Membersihkan layar
                        if (pesanan.empty()) {
                                cout << "==================================================================" << endl;
                                cout << "|                                                                |" << endl;
                                cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl;
                                cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl;
                                cout << "|                                                                |" << endl;
                                cout << "|----------------------------------------------------------------|" << endl;
                        } else {
                            int index;
                            cout << "| DAFTAR PESANAN ANDA :\n";
                            cout << endl;
                            cout << "No.\tNama Menu\t\tJumlah" << endl;
                            cout << "---------------------------------------" << endl;
                            for (size_t i = 0; i < pesanan.size(); i++) {
                                cout << i + 1 << ".\t" << pesanan[i].nama_makanan << "\tx " << pesanan[i].jumlah << endl;
                            }
                            cout << endl;
                            cout << "| Masukkan nomor pesanan yang ingin dihapus: " << endl;
                            cout << "=> ";
                            cin >> index;
                            cin.ignore();

                            if (index > 0 && index <= pesanan.size()) {
                                pesanan.erase(pesanan.begin() + index - 1);
                                cout << "Pesanan berhasil dihapus." << endl;
                            } else {
                                cout << "Nomor pesanan tidak valid." << endl;
                            }
                        }
                        cout << "Tekan Enter untuk kembali ke menu utama.";
                        cin.get();
                        break;
                    }
                    case 4: { // Checkout
                        system("CLS"); // Membersihkan layar
                        if (pesanan.empty()) {
                            cout << "==================================================================" << endl;
                            cout << "|                                                                |" << endl;
                            cout << "|             ANDA BELUM MEMILIKI PESANAN APAPUN :(              |" << endl;
                            cout << "|   INGIN PESAN? KEMBALI KE HALAMAN UTAMA LALU PILIH PAGE N0. 1  |" << endl;
                            cout << "|                                                                |" << endl;
                            cout << "|----------------------------------------------------------------|" << endl;

                        } else {
                        int total_harga = hitungTotalHarga(pesanan);

                        // Hitung PPN sebelum diskon
                        int ppn = hitungPPN(total_harga);

                        // Terapkan diskon 20% jika total harga lebih dari 100.000
                        float diskon = hitungDiskon(total_harga);
                        total_harga -= diskon;

                        if (diskon > 0) {
                            cout << "Diskon 20% karena pembelian di atas Rp 100.000: Rp " << diskon << endl;
                        }

                        // Memanggil fungsi cekVoucher untuk mengecek kode voucher
                        float diskonVoucher = cekVoucher();  // Diskon 5% jika kode voucher valid
                        total_harga -= total_harga * diskonVoucher;

                        total_harga += ppn;  // Menambahkan PPN setelah diskon dan voucher

                        cout << endl;
                        cout << "Total Harga    : Rp " << hitungTotalHarga(pesanan) << endl;
                        cout << "PPN (1%)       : Rp " << ppn << endl;
                        cout << "Diskon         : Rp " << diskon << endl;
                        cout << "Diskon Voucher : Rp " << diskonVoucher << endl;

                        cout << "--------------------------------------------" << endl;
                        cout << "|    TOTAL YANG HARUS DIBAYAR: Rp " << total_harga << "    |" << endl;
                        cout << "--------------------------------------------" << endl;
                        cout << "Tekan Enter untuk melanjutkan pembayaran.";
                        cin.get();
                        system ("CLS");

                        // Input metode pembayaran menggunakan switch dengan validasi
                        string metode_bayar;
                        int metode_pilih;

                        do {
                            cout << "| TOTAL YANG HARUS DIBAYAR: Rp " << total_harga << endl;

                            cout << "============================================" << endl;
                            cout << "|                                          |" << endl;
                            cout << "|         PILIH METODE PEMBAYARAN          |" << endl;
                            cout << "| (1) Tunai                                |" << endl;
                            cout << "| (2) Transfer Bank                        |" << endl;
                            cout << "| (3) Kartu Kredit                         |" << endl;
                            cout << "|------------------------------------------|" << endl;

                            cout << "| Masukan nomor pilihan Metode Pembayaran: " << endl;
                            cout << "=> ";
                            cin >> metode_pilih;

                            switch (metode_pilih) {
                                case 1:
                                    metode_bayar = "Tunai";
                                    break;
                                case 2: {
                                    metode_bayar = "Transfer Bank";
                                    // Meminta pengguna memilih bank setelah memilih Transfer Bank
                                    string bank_pilihan;
                                    int bank_pilih;

                                    cout << "Pilihan Bank:\n";
                                    cout << "1. Bank Mandiri\n";
                                    cout << "2. Bank BCA\n";
                                    cout << "3. Bank BNI\n";
                                    do {
                                    cout << "| Masukan angka pilihan Bank (1-3) : " << endl;
                                    cout << "=> ";
                                    cin >> bank_pilih;
                                    switch (bank_pilih) {
                                        case 1: bank_pilihan = "Bank Mandiri"; break;
                                        case 2: bank_pilihan = "Bank BCA"; break;
                                        case 3: bank_pilihan = "Bank BNI"; break;
                                        default: cout << "Pilihan bank tidak valid." << endl; break;
                                    }
                                    }while (bank_pilih <1 || bank_pilih >3);
                                    break;
                                }
                                case 3: {
                                    metode_bayar = "Kartu Kredit";
                                    // Meminta nomor kartu kredit setelah memilih Kartu Kredit
                                    string nomor_kartu;
                                    cout << "| Masukkan nomor kartu kredit Anda: " << endl;
                                    cout << "=> ";
                                    cin >> nomor_kartu;
                                    // Validasi kartu kredit bisa dilakukan di sini jika diperlukan
                                    break;
                                }
                                default:
                                    cout << "Pilihan tidak valid, silakan pilih 1, 2, atau 3!" << endl;
                                    metode_bayar = ""; // Reset metode_bayar jika input salah
                                    break;
                            }
                        } while (metode_bayar == ""); // Loop hingga pilihan valid diterima

                        // Input jumlah uang yang dibayar
                        int uang_bayar = mintaUangBayar(total_harga);
                        int kembalian = hitungKembalian(total_harga, uang_bayar);

                        system("CLS");
                        // Menampilkan struk dengan metode pembayaran
                        cout << "      RESTO AYAM NUSANTARA CABANG UNSIKA     " << endl;
                        cout << "      Jl. Ronggo Waluyo, Telukjambe Timur    " << endl;
                        cout << "               0895 6170 46679               " << endl;
                        cout << "=============================================" << endl;
                        cout << "|              STRUK PEMBAYARAN             |" << endl;
                        cout << "=============================================" << endl;
                        cout << "Nama Customer    : " << nama_customer << endl;
                        cout << "Metode Pembayaran: " << metode_bayar << endl;
                        cout << "---------------------------------------------" << endl;
                        for (const auto& p : pesanan) {
                            cout << p.nama_makanan << " x" << p.jumlah << " = Rp " << p.harga * p.jumlah << endl;
                        }
                        cout << "---------------------------------------------" << endl;

                        if (diskon > 0) {
                            cout << "Diskon (20%)             : Rp " << diskon << endl;
                        }

                        cout << "PPN (1%)                 : Rp " << ppn << endl;
                        cout << "Total Harga              : Rp " << total_harga << endl;

                        // Jika pembayaran menggunakan transfer atau kartu kredit, tidak perlu ditampilkan nomor bank atau nomor kartu kredit
                        if (metode_bayar == "Tunai") {
                            cout << "Metode Pembayaran        : Tunai" << endl;
                        }

                        cout << "Uang Bayar               : Rp " << uang_bayar << endl;
                        cout << "Kembalian                : Rp " << kembalian << endl;
                        cout << "=============================================" << endl;
                        cout << "      terima kasih atas kunjungan nya:)      " << endl;
                        cout << "          k r i t i k  &  s a r a n          " << endl;
                        cout << "               bit/ly.AnusGacor              " << endl;
                        pesanan.clear(); // Bersihkan pesanan setelah checkout
                        cin.ignore();
                        }
                        cout << endl << endl;
                        cout << "| Tekan Enter untuk kembali ke menu utama.";
                        cin.get();
                        break;
                    }
                    case 5: { // Keluar
                        system("CLS"); // Membersihkan layar
                        cout << "Terima kasih telah berkunjung!" << endl;

                        // Menambahkan animasi mundur selama 2 detik
                        for (int i = 0; i < 5; i++) {
                            system("CLS"); // Membersihkan layar

                            cout << "=============================================" << endl;
                            cout << "|        TERIMAKASIH TELAH BERKUNJUNG       |" << endl;
                            cout << "=============================================" << endl;
                            cout << "Anda akan keluar dalam " << 5 - i << " detik..." << endl;
                            this_thread::sleep_for(chrono::seconds(1));
                        }

                        // Menunggu 5 detik sebelum kembali ke login
                        this_thread::sleep_for(chrono::seconds(5));

                        // Bersihkan layar kembali sebelum kembali ke login
                        system("CLS");
                        break;
                    }
                    default:
                        system("CLS"); // Membersihkan layar
                        cout << "Pilihan tidak valid. Silakan pilih lagi." << endl;
                        break;
                }
            } while (pilihan != 5); // Menjaga agar perulangan terus berjalan hingga pilihan keluar
        } while (true); // Perulangan untuk login
        return 0;
    }
