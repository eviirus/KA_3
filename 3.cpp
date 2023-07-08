#include <iostream>
#include <vector>

using namespace std;

//Desimtainio skaiciaus konvertavimas i sesioliktaini
void Input_to_hex(int Input, vector<char> &Hex)
{
	vector<char> temp;
	while (Input != 0) {
		int a = 0;
		a = Input % 16;
		if (a < 10) {
			temp.push_back(a + 48);
		}
		else {
			temp.push_back(a + 55);
		}
		Input = Input / 16;
	}
	for (int i = temp.size() - 1; i >= 0; i--) {
		Hex.push_back(temp[i]);
	}
}

//Unikodo isvedimas
void Unicode(vector<char> Hex)
{
	cout << "UNICODE: " << "U+";
	if (Hex.size() < 4) {
		int a = 4 - Hex.size()+1;
		for (int i = 1; i < a; i++) {
			cout << "0";
		}
		for (int i = 0; i < Hex.size(); i++) {
			cout << Hex[i];
		}
	}
	else {
		for (int i = 0; i < Hex.size(); i++) {
			cout << Hex[i];
		}
	}
	cout << endl;
}

//UTF-8/CHAR
void UTF_and_CHAR(int Input, vector<char>&Hex_UTF)
{
	char utf8[4]{};
	int i = 0;
	if (Input >= 0 && Input <= 127) {
		utf8[i++] = Input;
	}
	else if (Input >= 128 && Input <= 2047) {
		utf8[i++] = 0xC0 | (Input >> 6);
		utf8[i++] = 0x80 | (Input & 0x3F);
	}
	else if (Input >= 2048 && Input <= 65535) {
		utf8[i++] = 0xE0 | (Input >> 12);
		utf8[i++] = 0x80 | ((Input >> 6) & 0x3F);
		utf8[i++] = 0x80 | (Input & 0x3F);
	}
	else if (Input >= 65536 && Input <= 1114111) {
		utf8[i++] = 0xF0 | (Input >> 18);
		utf8[i++] = 0x80 | ((Input >> 12) & 0x3F);
		utf8[i++] = 0x80 | ((Input >> 6) & 0x3F);
		utf8[i++] = 0x80 | (Input & 0x3F);
	}

	cout << "UTF-8: ";
	for (int j = 0; j < i; j++) {
		cout << hex << uppercase << (int)(unsigned char)utf8[j] << " ";
	}
	cout << "\n";
	cout << "CHAR: ";
	for (int j = 0; j < i; j++) {
		cout << utf8[j];
	}
}
int main()
{
	int Input;
	vector<char> Hex; vector<char> Hex_UTF;

	//---Skaitymas---//
	cout << "Iveskite desitmtaini skaiciu: "; cin >> Input;

	//---Funkcijos---//
	Input_to_hex(Input, Hex);
	Unicode(Hex);
	UTF_and_CHAR(Input, Hex_UTF);	

	return 0;
}