#include <iostream>
#include <math.h>
#include <string>
using namespace std;

class PengirimPesan{//base class
	protected://akses-specifier yang hanya boleh di akses oleh derived class
		string teks;//mendeklarasikan variabel
	public://akses-specifier yang di akses oleh siapa saja
		PengirimPesan(string teks){
			this->teks = teks;//untuk membedakan variabel dari teks
		}
	virtual char SetPengirimPesan() = 0;//virutal function
};

class KirimEmail : public PengirimPesan{//derived class
	private://akses-specifier yang hanya di akses di derived class
		string Email;//mendeklarasikan variabel
		string Subject;//mendeklarasikan variabel
	public://akses-specifier yang di akses oleh siapa saja
		KirimEmail (string Email, string Subject, string teks) :PengirimPesan(teks){//constraktor
			this->Email = Email;//untuk membedakan variabel dari Email
			this->Subject = Subject;//untuk membedakan variabel dari Subject
			this->teks = teks;//untuk membedakan variabel dari teks
		}
		char SetPengirimPesan(){//function SetPengirimPesan
			cout << "E-Mail	: "<<Email<<endl;//sebagai outputan di layar dan memanggil variabel
			cout << "Subject : "<<Subject<<endl;//sebagai outputan di layar dan memanggil variabel
			cout << "Pesan   : "<<teks<<endl;//sebagai outputan di layar dan memanggil variabel
            return 0;
		}

};

class BiayaKuliah{
protected:
	float SppVar, Pembangunan;
	int JmlSks ,SppTtp;
public:
	int SppTetap(){
		SppTtp;
		cout << "SPP Tetap = " ;cin >>SppTtp ;
		cout <<endl;
	}
	int SppVariabel(){
		JmlSks;
		SppVar;
		cout << "SPP Variabel per 1 SKS= ";cin >>SppVar;
		cout<<"Masukkan Jumlah Sks   = ";cin>>JmlSks;
		JmlSks = SppVar * JmlSks;
		cout << "Total                 = " << JmlSks << endl << endl;;
	}
	int BiayaPembangunan(){
		int Sisa;
		Pembangunan;
		cout << "Masukkan Jumlah Uang Pembangunan = ";cin >> Pembangunan;
		Sisa = Pembangunan / 2;
		cout << "Angsuran Selama 2 Semester       = "<< Sisa << endl<<endl;
		cout << "Total Pembayaran " <<SppTtp<<" + "<<JmlSks<<" + "<<Sisa<<endl;
	}
};

class Tampil{
public:
	void Output (int i){
		cout<< i << endl;
	}
};

class JmlPembayaran: public BiayaKuliah, public Tampil{
public:
	int hit (){
		return (SppVar + SppTtp + Pembangunan);
	}
};

bool Login();
void MainMenu();
void Tampilkan();

bool Login(){
	initiateLogin:
	string Username, Passwd;
	bool isLogin; 
	cout << "========LOGIN========" << endl;
	cout << "Username : "; cin >> Username;
	cout << "Password : "; cin >> Passwd;
	cout << "=====================" << endl;
	(Username == "17.11.1649" && Passwd == "rahasia") ? isLogin = true: isLogin = false;
	return isLogin;
}

void MainMenu(){
	system("cls");
	int choise;
	char validation;
	JmlPembayaran Totalbiaya;
	
	cout << "======================" << endl;
	cout << "1. Bayar Uang Kuliah\n" <<endl;
	cout << "Masukkan Pilihan = ";cin >> choise;
	switch(choise){
		case 1: Totalbiaya.SppTetap ();
				Totalbiaya.SppVariabel ();
				Totalbiaya.BiayaPembangunan ();
				cout << "Bayar Biaya Kuliah = ";
				Totalbiaya.Output(Totalbiaya.hit());
				cout << "Selesaikan Pembayaran [Y/T] = ";cin >> validation;
				if(validation == 'y' || validation == 'Y'){
        		cout<<endl;
				Tampilkan();
    			}else if(validation == 'T' || validation == 't'){
        		MainMenu();
    			}
				cout << endl;break;
		default:
		cout << "Pilihan Tidak Tersedia :)";break;
	}
	
}
void Tampilkan(){
	PengirimPesan *pesan = new KirimEmail("fadhilrahmat47@gmail.com","AMIKOM Yogyakarta","Terima Kasih telah menyelesaikan pembayaran");
	//isi function KirimSMS memberikan ke pointer pesan
	cout<<pesan->SetPengirimPesan()<<endl;//sebagai outputan di layar dan memanggil variabel
	delete pesan;//menghapus isi variabel pesan
}

int main(){

	initiate:
	if(Login()){
		MainMenu();
	}
	else
	{
		system("cls");
		cout << "Salah Username Atau Password" << endl;
		goto initiate;
	}
}

