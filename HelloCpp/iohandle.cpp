#include <fstream>
#include <iostream>
#include "exceptionhandle.cpp"
using namespace std;
int main11()
{

    char data[100];

    // ��дģʽ���ļ�
    ofstream outfile;
    outfile.open("afile.dat");

    cout << "Writing to the file" << endl;
    cout << "Enter your name: ";
    cin.getline(data, 100);

    // ���ļ�д���û����������
    outfile << data << endl;

    cout << "Enter your age: ";
    cin >> data;
    cin.ignore();//???

    // �ٴ����ļ�д���û����������
    outfile << data << endl;

    // �رմ򿪵��ļ�
    outfile.close();

    // �Զ�ģʽ���ļ�
    ifstream infile;
    infile.open("afile.dat");

    cout << "Reading from the file" << endl;
    infile >> data;

    // ����Ļ��д������
    cout << data << endl;

    // �ٴδ��ļ���ȡ���ݣ�����ʾ��
    infile >> data;
    cout << data << endl;

    // �رմ򿪵��ļ�
    infile.close();

    //test();
    return 0;
}