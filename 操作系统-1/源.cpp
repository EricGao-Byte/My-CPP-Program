#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<string.h>
using namespace std;//ʹ��vs2019����,��֧��iostream.h,�ʼ��������

const int  MAXCOMMANDLEN = 50;//���������������Ϊ50

/////////////////////////////////////////////////////////////////////////////////////
//
//         PROCESS
//
/////////////////////////////////////////////////////////////////////////////////////


class Process//������
{
	friend class CPU;//����һ����CPU����Ԫ��,�������ɷ��ʽ����������
protected:
	static int init_ID;//��̬���������ID
	int ID;//����ID
	char runText[MAXCOMMANDLEN];//����ָ���ַ�����
	int IP;//����ָ��ָ��,�������ָ��ִ�е��ľ���λ��
	bool ISuseSource;//�˽����Ƿ�ʹ����Դ,true:ʹ����,false:δʹ��
	bool ISblocked;//�˽����Ƿ�������״̬,true:������,false:δ����
	int unitTime;//���̵�λ��cpuִ��ʱ��,Ĭ����1
	int blockTime;//����ʱ��
public:
	static void RandID();//�����������ID
	Process();//������Ĺ��캯��,���ڳ�ʼ��һ������
	int getID();//��ȡ����ID
	int getIP();//��ȡ����ָ��ָ��
	void setIP(int);//���ý���ָ��ָ��
	void Runed();//���н���,������
	int getUnittime();//��ȡ���̵�λִ��ʱ��
	int getBlcoktime();//��ȡ��������ʱ��
	void setBlocktime(int);//���ý�������ʱ��
	void setUnittime(int);//���õ�λִ�е�ʱ��
	char getResult(int);//��ȡ����ִ�еĽ��
	char* getRuntext();//��ȡ����ָ���ַ�������Ԫ�صĵ�ַ
	void setBlockstate(bool);//���ý�������״̬
	bool getBlockstate();//��ȡ��������״̬
	bool getISusesource();//��ȡ�����Ƿ�ʹ����Դ��״̬
	void setISusesource(bool);//���ý���ʹ����Դ��״̬
};

int Process::init_ID;

void Process::RandID()//������ɽ���ID
{
	srand((unsigned)time(NULL));
	init_ID = rand();//Ϊ�������ID�����ֵ
}


Process::Process()//������Ĺ��캯��
{
	ID = init_ID++;//���ý���IDΪ���ID,��ʹ���ID+1
	int commandLen;//���������
	IP = 0;

	cout << "Please input the text which process runed by CPU [#command#] :>\\ ";
	cin >> runText;//���������ַ�
	if ((commandLen = strlen(runText)) > MAXCOMMANDLEN)
		exit(0);//����������ȴ�����󳤶�,���˳�

	runText[commandLen] = '#';//���ý������������־
	runText[commandLen + 1] = '\0';//�����ַ���������־
	ISuseSource = false;//���ý���Ĭ����Դʹ��״̬Ϊ��ʹ��
	ISblocked = false;//���ý���Ĭ�����״̬Ϊ������
	unitTime = 1;//����Ĭ�Ͻ��̵�λ��cpuִ��ʱ��Ϊ1
	blockTime = 0;//����Ĭ�Ͻ�������ʱ��Ϊ0
}


void Process::Runed()//ִ�н���
{
	cout << getResult(IP++);//������̵�ִ�н��
}


int Process::getID()//�õ�����ID
{
	return ID;
}

int Process::getIP()//��ȡ����ID
{
	return IP;
}

void Process::setIP(int ip)//���ý���ָ��ָ��
{
	IP = ip;
}

bool Process::getISusesource()//��ȡ��Դʹ��״̬
{
	return ISuseSource;
}

void Process::setISusesource(bool s)//������Դ��ʹ��״̬
{
	ISuseSource = s;
}

char* Process::getRuntext()//��ȡ����ָ���ַ�������Ԫ�صĵ�ַ
{
	return runText;
}

int Process::getUnittime()//��ȡ���̵�λִ��ʱ��
{
	return unitTime;
}


int Process::getBlcoktime()//��ȡ��������ʱ��
{
	return blockTime;
}

void Process::setBlocktime(int BT)//���ý�������ʱ��
{
	blockTime = BT;
}

void Process::setUnittime(int UT)//���ý��̵�λִ��ʱ��
{
	unitTime = UT;
}

void Process::setBlockstate(bool state)//���ý�������״̬
{
	ISblocked = state;
}

bool Process::getBlockstate()//��ȡ���̵�״̬
{
	return ISblocked;
}

char Process::getResult(int k)//��ȡ���̵�ִ�н��
{
	return runText[k];
}

/////////////////////////////////////////////////////////////////////////////////////
//
//         SOURCE
//
/////////////////////////////////////////////////////////////////////////////////////

class Source//��Դ��
{
protected:
	int ID;//��ԴID
	bool state;//��Դռ�����true:δռ�� false:��ռ��
	int pro_ID;//ʹ����Դ�Ľ��̵�ID
	Process* pro;//ʹ����Դ�Ľ��̵�ָ��
	int time;//����ʹ����Դ��ʱ��
public:
	Source(int);//��Դ���캯��
	bool getState();//��ȡ��Դ��״̬
	void setState(bool);//������Դ��״̬
	void setTime(int);//���ý���ʹ����Դ��ʱ��
	void setPro(Process*);//����ʹ�ø���Դ�Ľ���
	int getID();//��ȡ��ԴID
	int getPorID();//��ȡʹ����Դ�Ľ���ID
	void setProID(int);//����ʹ����Դ�Ľ���ID
	void runned();//��Դ����
};

Source::Source(int id)//���̹��캯��
{
	ID = id;
	pro = NULL;
	state = true;
}

void Source::setProID(int id)//����ʹ�ø���Դ�Ľ���
{
	pro_ID = id;
}

void Source::setTime(int t)//���ý���ʹ����Դ��ʱ��
{
	time = t;
}

void Source::setState(bool s)//������Դ״̬
{
	state = s;
}

bool Source::getState()//������Դ��״̬
{
	return state;
}

void Source::setPro(Process* p)//����ʹ�ø���Դ�Ľ���
{
	pro = p;
}

void Source::runned()//��Դ����
{
	if (time > 0)//���̻�����Դʹ��ʱ��
	{
		cout << "( Source :" << ID << ")";
		time--;
	}
	if (time <= 0)//����û����Դʹ��ʱ��
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

typedef struct Block//�������нṹ��
{
	Process* p_BlockProcess;//�������Ľ��̶���
	int index;//�������Ľ����پ��������е�����λ��
}Block;

class CPU
{
protected:
	Process* p_Process;//���̶���
	Process** pp_Process;//���̾�������
	Block* blockQueue;//������������
	Source* p_Source;//��Դָ��
	int numOfprocess;//���̵�����
	int numOfblock;//�������Ľ��̵�����
	int PC;//���������
	int allTime;//cpu���е���ʱ��
public:
	CPU(int);
	void Run();//��cpu���г���
	bool _IC(Process&);//������IC������ָ���
	void useSource(Process&);//����������Դ
	void blockProcess(Process&);//��������
	void releaseBlockPro();//�ͷ������Ľ���
	int getAlltime();//��ȡ�������е���ʱ��
	void displayPro();//��ʾ���̵Ļ�����Ϣ:id,ָ�������ʱ��
	void blockTimeADD();//Ϊ����ʱ���1
};

CPU::CPU(int num)
{
	p_Source = new Source(379857);//����һ��ID��Ϊ379857����Դ
	numOfprocess = num;//������
	numOfblock = 0;//�����Ľ�����
	allTime = 0;//����Ĭ�Ͻ���������ʱ��Ϊ0
	p_Process = new Process[numOfprocess];
	pp_Process = new Process * [numOfprocess];
	blockQueue = new Block[numOfprocess];
	for (int i = 0; i < numOfprocess; i++)
	{
		pp_Process[i] = &p_Process[i];//��һ����ά��������Ž���ָ������ͷָ��
		blockQueue->p_BlockProcess = NULL;//������������Ϊ��
		blockQueue->index = -1;
	}
}

int CPU::getAlltime()//��ȡ�������е���ʱ��
{
	return allTime;
}

void CPU::displayPro()//��ʾ���̵Ļ�����Ϣ:id,ָ�������ʱ��
{
	for (int i = 0; i < numOfprocess; i++)
	{
		cout << "\tProcess ID : " << p_Process[i].getID() << endl;
		cout << "   text of runned :" << p_Process[i].getRuntext() << endl;
	}
}

void CPU::Run()//��cpu���г���
{
	int numPro = numOfprocess;

	do
	{
		for (int num = 0; num < numOfprocess; num++)
		{
			if (!pp_Process[num])//��ָ��Ϊ��,˵���ý��̲��ھ���������
				continue;

			for (int t = 0; t < p_Process[num].getUnittime(); t++)
			{
				PC = p_Process[num].getIP();
				if (_IC(p_Process[num]))//�жϽ��̵�״̬,��Ϊtrue�����
				{
					if (t == 0)
						cout << "the process [" << p_Process[num].getID() << "] runed : ";
					if (!p_Process[num].getISusesource())//����ý���δ�����й�,�����run���н���
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
	if (resultRunned == '#')//��Ϊ#��,���������
		return false;
	else
	{
		if (resultRunned == '$')//������Դָ��
		{
			PC++;
			p.setIP(PC);
			resultRunned = p.getResult(PC);
			if (resultRunned >= '1' && resultRunned <= '9')
			{//��Դ����1-9�žͽ���
				if (p_Source->getState())
				{//����Դδ��ʹ����ʹ����Դ
					useSource(p);
					cout << "The process " << p.getID() << " take up the source!" << endl;
				}
				else
				{//��֮����Դ�ѱ�ʹ������������
					blockProcess(p);
					cout << "The process " << p.getID() << " is blocked !" << endl;
					return false;

				}
			}
			else
			{//����﷨����
				cout << "The process [" << p.getID() << "] runned fail ! It has been stopped!" << endl;
				return false;
			}
		}

	}
	return true;
}

void CPU::blockTimeADD()//Ϊ����ʱ���1
{
	for (int i = 0; i < numOfblock; i++)
	{
		int BT = blockQueue[i].p_BlockProcess->getBlcoktime();
		blockQueue[i].p_BlockProcess->setBlocktime(++BT);
	}
}

void CPU::useSource(Process& p)//����������Դ
{
	p.setISusesource(true);
	p_Source->setState(false);
	p_Source->setProID(p.getID());
	p_Source->setTime(p.getResult(PC) - '0');
	p_Source->setPro(&p);

}

void CPU::blockProcess(Process& p)
{
	//�������̵�����
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
	//ʾ����������������ʱ����ĵ�һ������
	pp_Process[blockQueue[0].index] = blockQueue[0].p_BlockProcess;
	blockQueue[0].index = -1;
	blockQueue[0].p_BlockProcess->setBlockstate(false);
	blockQueue[0].p_BlockProcess->setUnittime(
		blockQueue[0].p_BlockProcess->getBlcoktime());
	blockQueue[0].p_BlockProcess->setBlockstate(0);
	blockQueue[0].p_BlockProcess = NULL;
	numOfblock--;


	for (int i = 0; i < numOfblock; i++)
	{//����������������ǰ��һ��λ��
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
			throw(num);//�׳�����Ϊnum���쳣
	}
	catch (int)//����num�쳣
	{
		cout << "You input the numbers of process is error !" << endl;
		exit(1);
	}

	Process::RandID();//Ϊ��һ�������������ID,����Ľ���˳���1
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


