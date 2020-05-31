#include<fstream>
#include<string>
#include<iostream>
using namespace std;


// 使用文件IO流用文本及二进制方式演示读写配置文件
struct ServerInfo //f服务器ip和端口号信息
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
	// 二进制读写  内存二进制是什么样，写到磁盘就是什么样 (缺点：文件打开以后是乱码)
	void WriteBin(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());//定义ofstream类（输出文件流类）对象ofs，打开磁盘文件“myserver.config”,只能向他写入数据，不能从中读取数据
		ofs.write((const char*)&info, sizeof(ServerInfo));//将ip与port信息写入磁盘文件myserver.config
	}
	void ReadBin(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());//定义ifstream类（输入文件流类）对象ifs，打开磁盘文件
		ifs.read((char*)&info, sizeof(ServerInfo)); //把磁盘文件内容读入到内存
	}

	// 文本读写  转成字符串写出去。（优点：写出去方便读了，缺点：比较麻烦） 
	/* 传统的写法，转字符串写出，读字符串再转成要的类型对象  这个过程序列化和反序列化，类似于linux网络编程里的socket套接字编程里的网络字节序和主机字节序转换问题
	void WriteText(const ServerInfo& info)
	{
	ofstream ofs(_configfile.c_str());//定义输出文件流类对象，打开文件
	ofs.write(info._ip, strlen(info._ip));//字符串类型直接写入
	ofs.put('\n');//调用成员函数put写入单个字符 这里是换行符
	string ipstr = to_string(info._port);//整型转字符串
	ofs.write(ipstr.c_str(), ipstr.size());
	}

	void ReadText(ServerInfo& info)//读回去
	{
	ifstream ifs(_configfile.c_str());
	ifs.getline(info._ip, 32);//调用成员函数getline读取一行
	char ipstr[10];
	ifs.getline(ipstr, 10);
	info._port = stoi(ipstr);//字符串转整型
	}*/
	//现代写法
	void WriteText(const ServerInfo& info)
	{
		ofstream ofs(_configfile.c_str());
		ofs << info._ip << endl;
		ofs << info._port << endl;   // 底层也是整形转成字符串写出的
	}

	void ReadText(ServerInfo& info)
	{
		ifstream ifs(_configfile.c_str());
		ifs >> info._ip;
		ifs >> info._port;          // 底层读入字符串转成整形
	}

private:
	std::string _configfile; // 配置文件
};
//int main()
//{
//	ServerInfo info;
//	strcpy(info._ip, "192.168.1.1");
//	info._port = 80;
//
//	//二进制读写
//	//ConfigManager cm;
//	//cm.WriteBin(info);//将serverinfo信息写入磁盘文件
//	//
//	//ServerInfo ret;
//	//cm.ReadBin(ret);//将磁盘文件内容读到内存变量中
//	//cout << ret._ip << endl;//打印信息
//	//cout << ret._port << endl;
//
//	//文本读写
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


//字符串io
#include<sstream>

int main()
{
	//int a = 1, b = 3;
	////cin >> a >> b;
	//printf("Add(%d, %d)等于%d\n", a, b, a + b);
	//cout << "Add(" << a << "," << b << ")" << "等于" << a + b << endl;//麻烦


	//// sprintf格式化输入到字符数组中，缺陷是万一序列化出的字符串太长，buff就越界了
	//char buff[128];
	//sprintf(buff, "Add(%d, %d)等于%d", a, b, a + b);

	//// stringstream流对象     优势：就是无论序列化出的字符串多长，都够用。  写起来没有上面那么方便直观。
	//stringstream ss;
	//ss << "Add(" << a <<","<< b << ")"<<"等于" << a + b;
	//string str = ss.str();
	//cout << str << endl;



	//

	////	序列化与反序列化
	//// 张三  18  1823123131
	//// 发送端
	//stringstream send; //建立输出字符串流对象
	//send << "张三" << " " << 18 << " " << "1823123131"<<endl;//将数据插进去
	//string str = send.str();

	//// 接收端
	//stringstream recv(str);//建立输入字符串流对象
	//string name;
	//int age;
	//string tel;
	//recv >> name >> age >> tel;//读入时和cin一样，以空格、换行符、tab键为界限

	//cout << name << "-" << age << "-" << tel << endl;



	//字符串流对象常用用法
	string tmp("hello world who am i");
	stringstream ss(tmp);
	string word;
	while (ss >> word)//正常从ss流读取数据，值为真，执行循环体
	{
		cout << word ;
	}
	return 0;
}
