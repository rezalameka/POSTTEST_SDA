#include <iostream>
#include <string>
using namespace std;

#define JUMLAH_AWAL 7   // dari NIM ...107 -> 07
#define POSISI_SISIP 8  // digit terakhir 7 + 1 = 8

struct Node {
    string namaItem;
    int jumlah;
    string tipe;
    Node* next;

    Node(string n, string t) {
        namaItem = n;
        tipe = t;
        jumlah = JUMLAH_AWAL;
        next = nullptr;
    }
};

Node* head = nullptr;

// Tambah item di akhir
void tambahItem(const string& namaItem, const string& tipe) {
    Node* baru = new Node(namaItem, tipe);

    if (head == nullptr) {
        head = baru;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = baru;
    }
    cout << "Item '" << namaItem << "' berhasil ditambahkan dengan jumlah " << JUMLAH_AWAL << "!\n";
}

// Sisip item di posisi khusus
void sisipItem(const string& namaItem, const string& tipe) {
    Node* baru = new Node(namaItem, tipe);

    if (head == nullptr || POSISI_SISIP == 1) {
        baru->next = head;
        head = baru;
        return;
    }

    Node* temp = head;
    int count = 1;

    while (temp != nullptr && count < POSISI_SISIP - 1) {
        temp = temp->next;
        count++;
    }

    if (temp == nullptr) {
        cout << "Posisi sisip melebihi jumlah node, item ditaruh di akhir.\n";
        tambahItem(namaItem, tipe);
    } else {
        baru->next = temp->next;
        temp->next = baru;
    }

    cout << "Item '" << namaItem << "' berhasil disisipkan di posisi " << POSISI_SISIP << " dengan jumlah " << JUMLAH_AWAL << "!\n";
}

// Hapus item terakhir
void hapusItemTerakhir() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    if (head->next == nullptr) {
        cout << "Item '" << head->namaItem << "' dihapus dari inventory.\n";
        delete head;
        head = nullptr;
        return;
    }

    Node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }

    cout << "Item '" << temp->next->namaItem << "' dihapus dari inventory.\n";
    delete temp->next;
    temp->next = nullptr;
}

// Gunakan item (jumlah berkurang 1, hapus kalau jumlah 0)
void gunakanItem(const string& namaItem) {
    Node* temp = head;
    Node* prev = nullptr;

    while (temp != nullptr) {
        if (temp->namaItem == namaItem) {
            temp->jumlah--;
            cout << "Item '" << temp->namaItem << "' digunakan! Sisa jumlah = " << temp->jumlah << "\n";

            if (temp->jumlah == 0) {
                cout << "Jumlah habis, item '" << temp->namaItem << "' dihapus dari inventory.\n";
                if (prev == nullptr) {
                    head = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
            }
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    cout << "Item '" << namaItem << "' tidak ditemukan di inventory!\n";
}

// Tampilkan inventory
void tampilkanInventory() {
    if (head == nullptr) {
        cout << "Inventory kosong!\n";
        return;
    }

    cout << "\n=== INVENTORY ===\n";
    Node* temp = head;
    int i = 1;
    while (temp != nullptr) {
        cout << i << ". " << temp->namaItem << " (" << temp->tipe << ") - Jumlah: " << temp->jumlah << "\n";
        temp = temp->next;
        i++;
    }
    cout << "=================\n";
}

int main() {
    int pilihan;
    string namaItem, tipe;

    do {
        cout << "\n+------------------------------------------------+\n";
        cout << "|          GAME INVENTORY MANAGEMENT             |\n";
        cout << "|            [ Reza Alameka - 2301107 ]          |\n";
        cout << "+------------------------------------------------+\n";
        cout << "| 1. Tambah Item Baru                            |\n";
        cout << "| 2. Sisipkan Item                               |\n";
        cout << "| 3. Hapus Item Terakhir                         |\n";
        cout << "| 4. Gunakan Item                                |\n";
        cout << "| 5. Tampilkan Inventory                         |\n";
        cout << "| 0. Keluar                                      |\n";
        cout << "+------------------------------------------------+\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        switch (pilihan) {
            case 1:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                tambahItem(namaItem, tipe);
                break;
            case 2:
                cout << "Masukkan nama item: ";
                getline(cin, namaItem);
                cout << "Masukkan tipe item: ";
                getline(cin, tipe);
                sisipItem(namaItem, tipe);
                break;
            case 3:
                hapusItemTerakhir();
                break;
            case 4:
                cout << "Masukkan nama item yang ingin digunakan: ";
                getline(cin, namaItem);
                gunakanItem(namaItem);
                break;
            case 5:
                tampilkanInventory();
                break;
            case 0:
                cout << "Keluar dari program...\n";
                break;
            default:
                cout << "Pilihan tidak valid!\n";
        }
    } while (pilihan != 0);

    return 0;
}
