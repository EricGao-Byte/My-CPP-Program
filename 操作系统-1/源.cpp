#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
using namespace std;//使用vs2019调试,不支持iostream.h,故加这条语句

const int  MAXCOMMANDLEN = 50;//设置最大进程命令长度为50

/////////////////////////////////////////////////////////////////////////////////////
//
//         PROCESS
//
/////////////////////////////////////////////////////////////////////////////////////


class Process//进程类
{
	friend class CPU;//定义一个叫CPU的友元类,可以自由访问进程类的数据
protected:
	static int init_ID;//静态的随机进程ID
	int ID;//进程ID
	char runText[MAXCOMMANDLEN];//进程指令字符数组
	int IP;//进程指令指针,保存进程指令执行到的具体位置
	bool ISuseSource;//此进程是否使用资源,true:使用中,false:未使用
	bool ISblocked;//此进程是否处于阻塞状态,true:阻塞中,false:未阻塞
	int unitTime;//进程单位被cpu执行时间,默认是1
	int blockTime;//阻塞时间
public:
	static void RandID();//设置随机进程ID
	Process();//进程类的构造函数,用于初始化一个进程
	int getID();//获取进程ID
	int getIP();//获取进程指令指针
	void setIP(int);//设置进程指令指针
	void Runed();//运行进程,输出结果
	int getUnittime();//获取进程单位执行时间
	int getBlcoktime();//获取进程阻塞时间
	void setBlocktime(int);//设置进程阻塞时间
	void setUnittime(int);//设置单位执行的时间
	char getResult(int);//获取进程执行的结果
	char* getRuntext();//获取进程指令字符数组首元素的地址
	void setBlockstate(bool);//设置进程阻塞状态
	bool getBlockstate();//获取进程阻塞状态
	bool getISusesource();//获取进程是否使用资源的状态
	void setISusesource(bool);//设置进程使用资源的状态
};

int Process::init_ID;

void Process::RandID()//随机生成进程ID
{
	srand((unsigned)time(NULL));
	init_ID = rand();//为随机进程ID随机赋值
}


Process::Process()//进程类的构造函数
{
	ID = init_ID++;//设置进程ID为随机ID,并使随机ID+1
	int commandLen;//进程命令长度
	IP = 0;

	cout << "Please input the text which process runed by CPU [#command#] :>\\ ";
	cin >> runText;//读入命令字符
	if ((commandLen = strlen(runText)) > MAXCOMMANDLEN)
		exit(0);//若进程命令长度大于最大长度,则退出

	runText[commandLen] = '#';//设置进程命令结束标志
	runText[commandLen + 1] = '\0';//设置字符串结束标志
	ISuseSource = false;//设置进程默认资源使用状态为不使用
	ISblocked = false;//设置进程默认阻断状态为不阻塞
	unitTime = 1;//设置默认进程单位被cpu执行时间为1
	blockTime = 0;//设置默认进程阻塞时间为0
}


void Process::Runed()//执行进程
{
	cout << getResult(IP++);//输出进程的执行结果
}


int Process::getID()//得到进程ID
{
	return ID;
}

int Process::getIP()//获取进程ID
{
	return IP;
}

void Process::setIP(int ip)//设置进程指令指针
{
	IP = ip;
}

bool Process::getISusesource()//获取资源使用状态
{
	return ISuseSource;
}

void Process::setISusesource(bool s)//设置资源的使用状态
{
	ISuseSource = s;
}

char* Process::getRuntext()//获取进程指令字符数组首元素的地址
{
	return runText;
}

int Process::getUnittime()//获取进程单位执行时间
{
	return unitTime;
}


int Process::getBlcoktime()//获取进程阻塞时间
{
	return blockTime;
}

void Process::setBlocktime(int BT)//设置进程阻塞时间
{
	blockTime = BT;
}

void Process::setUnittime(int UT)//设置进程单位执行时间
{
	unitTime = UT;
}

void Process::setBlockstate(bool state)//设置进程阻塞状态
{
	ISblocked = state;
}

bool Process::getBlockstate()//获取进程的状态
{
	return ISblocked;
}

char Process::getResult(int k)//获取进程的执行结果
{
	return runText[k];
}

/////////////////////////////////////////////////////////////////////////////////////
//
//         SOURCE
//
/////////////////////////////////////////////////////////////////////////////////////

class Source//资源类
{
protected:
	int ID;//资源ID
	bool state;//资源占有情况true:未占有 false:已占有
	int pro_ID;//使用资源的进程的ID
	Process* pro;//使用资源的进程的指针
	int time;//进程使用资源的时间
public:
	Source(int);//资源构造函数
	bool getState();//获取资源的状态
	void setState(bool);//设置资源的状态
	void setTime(int);//设置进程使用资源的时间
	void setPro(Process*);//设置使用该资源的进程
	int getID();//获取资源ID
	int getPorID();//获取使用资源的进程ID
	void setProID(int);//设置使用资源的进程ID
	void runned();//资源调用
};

Source::Source(int id)//进程构造函数
{
	ID = id;
	pro = NULL;
	state = true;
}

void Source::setProID(int id)//设置使用该资源的进程
{
	pro_ID = id;
}

void Source::setTime(int t)//设置进程使用资源的时间
{
	time = t;
}

void Source::setState(bool s)//设置资源状态
{
	state = s;
}

bool Source::getState()//设置资源的状态
{
	return state;
}

void Source::setPro(Process* p)//设置使用该资源的进程
{
	pro = p;
}

void Source::runned()//资源调用
{
	if (time > 0)//进程还有资源使用时间
	{
		cout << "( Source :" << ID << ")";
		time--;
	}
	if (time <= 0)//进程没有资源使用时间
	{
		pro->setISusesource(false);
		int ip = pro->getIP();
		pro->setIP(++ip);
		Source::setState(true);
		cout << endl << "The process " << pro->getID() << " relase the source!" << endl;
		pro = NULL;
	}
}

/////////////////////////////////////////////////////////////////////////////////////
//
//         CPU
//
/////////////////////////////////////////////////////////////////////////////////////

typedef struct Block//阻塞队列结构体
{
	Process* p_BlockProcess;//被阻塞的进程队列
	int index;//被阻塞的进程再就绪队列中的索引位置
}Block;

class CPU
{
protected:
	Process* p_Process;//进程队列
	Process** pp_Process;//进程就绪队列
	Block* blockQueue;//进程阻塞队列
	Source* p_Source;//资源指针
	int numOfprocess;//进程的数量
	int numOfblock;//被阻塞的进程的数量
	int PC;//程序计数器
	int allTime;//cpu运行的总时间
public:
	CPU(int);
	void Run();//用cpu运行程序
	bool _IC(Process&);//用虚拟IC来进行指令翻译
	void useSource(Process&);//进程申请资源
	void blockProcess(Process&);//阻塞进程
	void releaseBlockPro();//释放阻塞的进程
	int getAlltime();//获取进程运行的总时间
	void displayPro();//显示进程的基本信息:id,指令和运行时间
	void blockTimeADD();//为阻塞时间加1
};

CPU::CPU(int num)
{
	p_Source = new Source(379857);//创建一个ID号为379857的资源
	numOfprocess = num;//进程数
	numOfblock = 0;//阻塞的进程数
	allTime = 0;//设置默认进程运行总时间为0
	p_Process = new Process[numOfprocess];
	pp_Process = new Process * [numOfprocess];
	blockQueue = new Block[numOfprocess];
	for (int i = 0; i < numOfprocess; i++)
	{
		pp_Process[i] = &p_Process[i];//用一个二维数组来存放进程指针数组头指针
		blockQueue->p_BlockProcess = NULL;//设置阻塞队列为空
		blockQueue->index = -1;
	}
}

int CPU::getAlltime()//获取进程运行的总时间
{
	return allTime;
}

void CPU::displayPro()//显示进程的基本信息:id,指令和运行时间
{
	for (int i = 0; i < numOfprocess; i++)
	{
		cout << "\tProcess ID : " << p_Process[i].getID() << endl;
		cout << "   text of runned :" << p_Process[i].getRuntext() << endl;
	}
}

void CPU::Run()//用cpu运行程序
{
	int numPro = numOfprocess;

	do
	{
		for (int num = 0; num < numOfprocess; num++)
		{
			if (!pp_Process[num])//若指针为空,说明该进程不在就绪队列中
				continue;

			for (int t = 0; t < p_Process[num].getUnittime(); t++)
			{
				PC = p_Process[num].getIP();
				if (_IC(p_Process[num]))//判断进程的状态,若为true则进入
				{
					if (t == 0)
						cout << "the process [" << p_Process[num].getID() << "] runed : ";
					if (!p_Process[num].getISusesource())//如果该进程未被运行过,则调用run运行进程
					{
						p_Process[num].Runed();
					}
					else
					{
						p_Source->runned();
						if (p_Source->getState() && numOfblock > 0)
						{
							releaseBlockPro();
						}
					}
				}
				else
				{
					if (!p_Process[num].getBlockstate())
					{
						numPro--;
						pp_Process[num] = NULL;
						continue;
					}
					break;
				}
				allTime++;
				if (numOfblock > 0)
					blockTimeADD();
			}//end for t...
			if (p_Process[num].getUnittime())
				p_Process[num].setUnittime(1);
			cout << endl;
		}//end for num...

	} while (numPro);
}

bool CPU::_IC(Process& p)
{

	char resultRunned;

	resultRunned = p.getResult(PC);
	if (resultRunned == '#')//若为#号,则命令结束
		return false;
	else
	{
		if (resultRunned == '$')//申请资源指令
		{
			PC++;
			p.setIP(PC);
			resultRunned = p.getResult(PC);
			if (resultRunned >= '1' && resultRunned <= '9')
			{//资源号是1-9号就进入
				if (p_Source->getState())
				{//若资源未被使用则使用资源
					useSource(p);
					cout << "The process " << p.getID() << " take up the source!" << endl;
				}
				else
				{//反之若资源已被使用则阻塞进程
					blockProcess(p);
					cout << "The process " << p.getID() << " is blocked !" << endl;
					return false;

				}
			}
			else
			{//检查语法错误
				cout << "The process [" << p.getID() << "] runned fail ! It has been stopped!" << endl;
				return false;
			}
		}

	}
	return true;
}

void CPU::blockTimeADD()//为阻塞时间加1
{
	for (int i = 0; i < numOfblock; i++)
	{
		int BT = blockQueue[i].p_BlockProcess->getBlcoktime();
		blockQueue[i].p_BlockProcess->setBlocktime(++BT);
	}
}

void CPU::useSource(Process& p)//进程申请资源
{
	p.setISusesource(true);
	p_Source->setState(false);
	p_Source->setProID(p.getID());
	p_Source->setTime(p.getResult(PC) - '0');
	p_Source->setPro(&p);

}

void CPU::blockProcess(Process& p)
{
	//阻塞进程的设置
	int tempIndex = numOfprocess - (Process::init_ID - p.getID());
	blockQueue[numOfblock].p_BlockProcess = &p;
	blockQueue[numOfblock].index = tempIndex;
	numOfblock++;
	int ip = p.getIP();
	p.setIP(--ip);
	p.setBlockstate(true);
	p.setBlocktime(1);
	p.setUnittime(0);
	pp_Process[tempIndex] = NULL;

}

void CPU::releaseBlockPro()
{
	//示范阻塞队列中阻塞时间最长的第一个进程
	pp_Process[blockQueue[0].index] = blockQueue[0].p_BlockProcess;
	blockQueue[0].index = -1;
	blockQueue[0].p_BlockProcess->setBlockstate(false);
	blockQueue[0].p_BlockProcess->setUnittime(
		blockQueue[0].p_BlockProcess->getBlcoktime());
	blockQueue[0].p_BlockProcess->setBlockstate(0);
	blockQueue[0].p_BlockProcess = NULL;
	numOfblock--;


	for (int i = 0; i < numOfblock; i++)
	{//阻塞队列数组整体前移一个位置
		blockQueue[i] = blockQueue[i + 1];
	}
}


/////////////////////////////////////////////////////////////////////////////////////
//
//        The main progress
//
/////////////////////////////////////////////////////////////////////////////////////


void main()
{
	int num;
	cout << "\t********************************************************" << endl
		<< endl;
	cout << "\t             The virtual CPU    the process runned           " << endl
		<< endl;
	cout << "\t*******************************************************" << endl
		<< endl;

	cout << "initialize the information of processes " << endl;

	cout << "Please input the number of process [#command#] >\\ ";

	try
	{
		cin >> num;
		if (num <= 0)
			throw(num);//抛出代号为num的异常
	}
	catch (int)//捕获num异常
	{
		cout << "You input the numbers of process is error !" << endl;
		exit(1);
	}

	Process::RandID();//为第一个进程生成随机ID,后面的进程顺序加1
	CPU virtualCPU(num);

	cout << "Pocesses runed by CPU " << endl;
	virtualCPU.Run();

	cout << "Processes runned over ! " << endl;
	cout << "\t********************************************************" << endl
		<< endl;
	cout << "\t The time which processes runned by CPU : " << virtualCPU.getAlltime() << endl
		<< endl;
	virtualCPU.displayPro();
	cout << "\t*******************************************************" << endl
		<< endl;
}


