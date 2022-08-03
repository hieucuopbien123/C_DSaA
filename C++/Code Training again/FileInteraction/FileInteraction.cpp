#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    //fopen_s, feof, fclose, getc => char[], FILE*
    cout << "1: " << endl;
	FILE* file;
	errno_t error = fopen_s(&file, "TextFile1.txt", "r");
	if (error != 0) {
		cout << "The file was not opened" << endl;
		return -1;
	}
    char content[100] = {};
    int index = 0;
    while (!feof(file)){
        content[index] = getc(file);
        index++;
    }
    cout << content << endl;
    
    fseek(file, 0, SEEK_SET);
    char content5[100] = {};
    while(fgets(content5, 100, file) != NULL){
        cout << content5;
    }
    fclose(file);

    //fputc, ftell, fseek, puts
    cout << "2: " << endl;
    FILE* file2;
    errno_t error2 = fopen_s(&file2, "TextFile1.txt", "w");
    if (error2 != 0) {
        cout << "The file was not opened" << endl;
        return -1;
    }
    fputs("Hello\n", file2);
    cout << ftell(file2) << endl;
    fputc('b', file2);
    fclose(file2);

    //fwrite
    cout << "3: " << endl;
    FILE* file10;
    errno_t error4 = fopen_s(&file10, "TextFile2.bin", "wb");
    if (error4 != 0) {
        cout << "The file was not opened" << endl;
        return -1;
    }
    char data[100] = { "Hello from fwrite" };
    fwrite(data, sizeof(char), sizeof(data), file10);
    fclose(file10);

    //fread
    cout << "4: " << endl;
    FILE* file11;
    errno_t error5 = fopen_s(&file11, "TextFile2.bin", "rb");
    if (error5 != 0) {
        cout << "The file was not opened" << endl;
        return -1;
    }
    char data2[100] = {};
    fread(data2, sizeof(char), sizeof(data2),file11 );
    cout << data2 << endl;
    fclose(file11);
    
    //fgetc
    cout << "5: " << endl;
    FILE* file3;
    errno_t error3 = fopen_s(&file3, "TextFile1.txt", "r");
    if (error3 != 0) {
        cout << "The file was not opened" << endl;
        return -1;
    }    
    char content2[100] = {};
    int index2 = 0;
    char c;
    while ((c = fgetc(file3)) != EOF) {
        content2[index2] = c;
        index2++;
    }
    cout << content2 << endl;
    fclose(file3);

    //ifstream, open, is_open, fail, tellg, tellp, put, seekp, seekg
    cout << "5: " << endl;
    fstream file4;
    file4.open("TextFile1.txt", ios::out);
    if (!file4.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    if (file4.fail()) {
        cout << "Cannot open file" << endl;
        return -1;
    }
    file4.put('m');
    file4.seekg(0, ios::end);
    file4.seekp(0, ios::beg);
    cout << file4.tellg() << " " << file4.tellp() << endl;
    file4.close();

    //get
    cout << "6: " << endl;
    fstream file5;
    file5.open("TextFile1.txt", ios::in);
    if (!file5.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    char temp1 = file5.get();
    cout << temp1 << endl;
    file5.close();

    //>>
    cout << "7: " << endl;
    fstream file6;
    file6.open("TextFile1.txt", ios::in);
    if (!file6.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    char temp2;
    while (file6 >> temp2){
        cout << temp2;
    }
    file6.close();

    //getline, eof
    cout << "8: " << endl;
    fstream file7;
    file7.open("TextFile1.txt", ios::in);
    if (!file7.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    char temp3[100]{};
    while (!file7.eof())
    {
        file7.getline(temp3, 100, EOF);
    }
    cout << endl << temp3 << endl;
    file7.close();

    //write
    cout << "9: " << endl;
    fstream file9;
    file9.open("TextFile2.bin", ios::out | ios::binary);
    if (!file9.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    file9.write("hello \n World", 100);
    file9.close();

    //read
    fstream file8;
    file8.open("TextFile2.bin", ios::in | ios::binary);
    if (!file8.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    char content4[100] = {};
    file8.read(content4, sizeof(content4));
    cout << content4 << endl;
    file8.close();

    //<<
    fstream file12;
    file12.open("TextFile1.txt", ios::app);
    if (!file12.is_open()) {
        cout << "File cannot open" << endl;
        return -1;
    }
    string str = "text";
    file12 << str;
    file12.close();

	return 0;
}