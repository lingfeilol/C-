#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// ʹ���ļ�IO�����ı��������Ʒ�ʽ��ʾ��д�����ļ�
struct ServerInfo //f������ip�Ͷ˿ں���Ϣ
{
	char _ip[32];
	int _port;
};


struct ConfigManager
{
public:
	ConfigManager(const char* configfile = "myserver.config")
		:_configfile(configfile)
		{}
	// �����ƶ�д  �ڴ��������ʲô����д�����̾���ʲô�� (ȱ�㣺�ļ����Ժ�������)
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());//����ofstream�ࣨ����ļ����ࣩ����ofs���򿪴����ļ���myserver.config��,ֻ������д�����ݣ����ܴ��ж�ȡ����
		ofs.write((const char*)&info, sizeof(ServerInfo));//��ip��port��Ϣд������ļ�myserver.config
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());//����ifstream�ࣨ�����ļ����ࣩ����ifs���򿪴����ļ�
		ifs.read((char*)&info, sizeof(ServerInfo)); //�Ѵ����ļ����ݶ��뵽�ڴ�
	}

	// �ı���д  ת���ַ���д��ȥ�����ŵ㣺д��ȥ������ˣ�ȱ�㣺�Ƚ��鷳�� 
	/* ��ͳ��д����ת�ַ���д�������ַ�����ת��Ҫ�����Ͷ���  ����������л��ͷ����л���������linux���������socket�׽��ֱ����������ֽ���������ֽ���ת������
	void WriteText(const ServerInfo& info)
	{
	ofstream ofs(_configfile.c_str());//��������ļ�������󣬴��ļ�
	ofs.write(info._ip, strlen(info._ip));//�ַ�������ֱ��д��
	ofs.put('\n');//���ó�Ա����putд�뵥���ַ� �����ǻ��з�
	string ipstr = to_string(info._port);//����ת�ַ���
	ofs.write(ipstr.c_str(), ipstr.size());
	}

	void ReadText(ServerInfo& info)//����ȥ
	{
	ifstream ifs(_configfile.c_str());
	ifs.getline(info._ip, 32);//���ó�Ա����getline��ȡһ��
	char ipstr[10];
	ifs.getline(ipstr, 10);
	info._port = stoi(ipstr);//�ַ���ת����
	}*/
	//�ִ�д��
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());
		ofs << info._ip << endl;
		ofs << info._port << endl;   // �ײ�Ҳ������ת���ַ���д����
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());
		ifs >> info._ip;
		ifs >> info._port;          // �ײ�����ַ���ת������
	}

private:
	std::string _configfile; // �����ļ�
};
//int main()
//{
//	ServerInfo info;
//	strcpy(info._ip, "192.168.1.1");
//	info._port = 80;
//
//	//�����ƶ�д
//	//ConfigManager cm;
//	//cm.WriteBin(info);//��serverinfo��Ϣд������ļ�
//	//
//	//ServerInfo ret;
//	//cm.ReadBin(ret);//�������ļ����ݶ����ڴ������
//	//cout << ret._ip << endl;//��ӡ��Ϣ
//	//cout << ret._port << endl;
//
//	//�ı���д
//	ConfigManager cm;
//	cm.WriteText(info);
//	
//	ServerInfo ret;
//	cm.ReadText(ret);
//	cout << ret._ip << endl;
//	cout << ret._port << endl;
//
//	return 0;
//}


//�ַ���io
#include<sstream>

int main()
{
	//int a = 1, b = 3;
	////cin >> a >> b;
	//printf("Add(%d, %d)����%d\n", a, b, a + b);
	//cout << "Add(" << a << "," << b << ")" << "����" << a + b << endl;//�鷳


	//// sprintf��ʽ�����뵽�ַ������У�ȱ������һ���л������ַ���̫����buff��Խ����
	//char buff[128];
	//sprintf(buff, "Add(%d, %d)����%d", a, b, a + b);

	//// stringstream������     ���ƣ������������л������ַ����೤�������á�  д����û��������ô����ֱ�ۡ�
	//stringstream ss;
	//ss << "Add(" << a <<","<< b << ")"<<"����" << a + b;
	//string str = ss.str();
	//cout << str << endl;



	//

	////	���л��뷴���л�
	//// ����  18  1823123131
	//// ���Ͷ�
	//stringstream send; //��������ַ���������
	//send << "����" << " " << 18 << " " << "1823123131"<<endl;//�����ݲ��ȥ
	//string str = send.str();

	//// ���ն�
	//stringstream recv(str);//���������ַ���������
	//string name;
	//int age;
	//string tel;
	//recv >> name >> age >> tel;//����ʱ��cinһ�����Կո񡢻��з���tab��Ϊ����

	//cout << name << "-" << age << "-" << tel << endl;



	//�ַ������������÷�
	string tmp("hello world who am i");
	stringstream ss(tmp);
	string word;
	while (ss >> word)//������ss����ȡ���ݣ�ֵΪ�棬ִ��ѭ����
	{
		cout << word ;
	}
	return 0;
}
