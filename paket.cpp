#include<iostream>
#include<conio.h>
#include<windows.h>

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}


using namespace std;
struct paket
{
    char jenis_brg[30];
    int berat;
    char kota[30];
};

struct paket kirim[100];

/*******************************************/
void bersihlayar()
{
    for(int a=0;a<80;a++)
    {
        for(int b=0;b<=24;b++)
        {
            gotoxy(a,b);cout<<" ";
        }
    }
}

void tambahdata(int x)
{
    gotoxy(40,1);cout<<"Inputkan Jenis Barang    :";
    cin>>kirim[x].jenis_brg;
    gotoxy(40,2);cout<<"Inputkan Berat           :";
    cin>>kirim[x].berat;
    gotoxy(40,3);cout<<"Inputkan Kota Tujuan     :";
    cin>>kirim[x].kota;
}

void tampildata(int x)
{
    gotoxy(20,10);cout<<"Daftar Kiriman Paket"<<endl;
    int b = 0;
    for(int a=1; a<x; a++)
    {
        gotoxy(20,b = 11+a);
        cout<<a<<". ";
        cout<<kirim[a].jenis_brg<<" ";
        cout<<kirim[a].berat<<" kg ";
        cout<<kirim[a].kota<<endl;
    }
    int c = b + 3;
    gotoxy(20,c);
    cout<<"Press Any Key...";
    getch();
    /*harus Ijin --> #include<conio.h>*/
}

void hapusdata(int x)
{
    gotoxy(20,12);cout<<"Data Terakhir yang anda Hapus Adalah :"<<endl;
    gotoxy(20,13);cout<<kirim[x].jenis_brg<<" ";
    cout<<kirim[x].berat<<" Kg ";
    cout<<kirim[x].kota<<endl<<endl;

    gotoxy(20,15);cout<<"Press Any Key...";
    getch();


}

int main()
{
    int pilih;
    int datake=1;
    do
    {
        bersihlayar();
        gotoxy(5,1);cout<<"MENU UTAMA";
        gotoxy(5,2);cout<<"1. Tambah Data";
        gotoxy(5,3);cout<<"2. Hapus Data Terakhir"<<endl;
        gotoxy(5,4);cout<<"3. Tampil Data"<<endl;
        gotoxy(5,5);cout<<"9. Keluar"<<endl;

        gotoxy(3,7);cout<<"Pilihan Anda [1-9] : ";
        cin>>pilih;
        if(pilih==1)
            { /*Menambah data baru diletakan di DATAKE*/
                tambahdata(datake);
                datake++;
            }
        if(pilih==2)
            { /*Menghapus Data Terakhir (DATAKE-1*/
                hapusdata(datake-1);
                datake--;
            }
        if(pilih==3) /*Menampilkan Data mulai
                        data ke-1 hingga DATAKE*/
            tampildata(datake);

    }
    while(pilih!=9);
    return 0;
}
