#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

struct landing //landing struct
{
	int id;
	int waiting_time=0;
	int fuel;
	landing*next;
};

struct takeoff //takeoff struct
{
	int id;
	int waiting_time=0;
	takeoff*next;
};

float ave_landing_time=0;
float airplane_landing=0;
float ave_takeoff_time=0;
float airplane_takeoff=0;
float ave_fuel=0;
int airplane_crash=0;
int emergency_airplane=0;

int randomfuel(int initial,int n);
int randomlanding(int initial,int n);
int randomtakeoff(int initial,int n);

bool isempty_landing (landing*head);
void add_first_landing(landing*&head,landing*&last,int id_num,int fuel_num,int maxfuel);
void add_landing(landing*&head,landing*&last,int id_num,int fuel_num,int maxfuel);
void sub_landing(landing*&head);
void em_landing(landing*&temp,int flag);

bool isempty_takeoff(takeoff*head);
void add_first_takeoff(takeoff*&head,takeoff*&last,int id_num);
void add_takeoff(takeoff*&head,takeoff*&last,int id_num);
void sub_takeoff(takeoff*&head);
int compare(takeoff*takeoffhead,landing*landinghead_1,landing*landinghead_2);
void check_runway(takeoff*takeoffhead);
void print_notyet(takeoff*takeoffhead);
void print_notlanding(landing*landinghead);
int main()
{
	landing*b1_head=NULL,*b1_last=NULL,*b4_head=NULL,*b4_last=NULL;
	landing*c2_head=NULL,*c2_last=NULL,*c5_head=NULL,*c5_last=NULL;
	landing*d3_head=NULL,*d3_last=NULL,*d6_head=NULL,*d6_last=NULL;
	takeoff*a_head=NULL,*a_last=NULL,*b_head=NULL,*b_last=NULL,*c_head=NULL,*c_last =NULL,*d_head=NULL,*d_last=NULL;

	int time,how_fuel,how_landing,how_takeoff;
	cout << "How many time unit do you want?" ;
	cin >> time;
	cout << "Max fuel = ";
	cin >> how_fuel;
	cout << "Max landing airplane going queue = ";
	cin >> how_landing;
	cout << "Max takeoff airplane going queue = ";
	cin >> how_takeoff;
	cout << endl << endl;

	int landingnum=1;
	int takeoffnum=0;
	int landing_runway=1;
	int takeoff_runway=1;
	int timetemp=0;

	while (timetemp<time)
	{
		int timeunit=timetemp+1;
		int pilottime=timetemp;
		int flag_a=0;

		cout << "This is "<<timeunit<<" unit."<<endl;

		check_runway(a_head);/*一開始把current指向和head相同的地方 開始用current更改*/
	    check_runway(b_head);
	    check_runway(c_head);
        check_runway(d_head);

		if (!isempty_landing(b1_head))
		{
			landing*current=b1_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!= NULL&&current->fuel==0)
				{
					flag_a++;
					em_landing(current,flag_a);
				}
			}
		}
		if (!isempty_landing(b4_head))
		{
			landing* current=b4_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!=NULL&&current->fuel==0)
				{
					flag_a++;
					em_landing(current,flag_a);
				}
			}
		}
		if (!isempty_landing(c2_head))
		{
			landing*current=c2_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!=NULL&&current->fuel == 0)
				{
					flag_a++;
					em_landing(current,flag_a);
				}
			}
		}
		if (!isempty_landing(c5_head))
		{
			landing*current=c5_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!=NULL&&current->fuel==0)
				{
					flag_a++;
					em_landing(current,flag_a);
				}
			}
		}
		if (!isempty_landing(d3_head))
		{
			landing*current=d3_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!=NULL&&current->fuel==0)
				{
					flag_a++;
					em_landing(current,flag_a);
				}
			}
		}
		if (!isempty_landing(d6_head))
		{
			landing* current=d6_head;
			while (current!=NULL)
			{
				current->fuel=current->fuel-1;
				current->waiting_time++;
				current=current->next;
				if (current!=NULL&&current->fuel==0)
				{
					flag_a++; 
					em_landing(current,flag_a);
				}
			}
		}

		int num_of_landing=randomlanding(pilottime+372,how_landing);
		int num_of_takeoff=randomtakeoff(pilottime+422,how_takeoff);

		if (landing_runway==7) 
		{
			landing_runway=1;
		}
		if (takeoff_runway==5)
		{
			takeoff_runway=1;
		}

		for (int i=0; i <num_of_landing;i++)
		{
			if (landing_runway==1)
			{
				add_landing(b1_head,b1_last,landingnum,pilottime+225,how_fuel);
				cout<<"-B landing queue-b1."<<endl;
				landingnum=landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 2)
			{
				add_landing(c2_head,c2_last,landingnum,pilottime+214,how_fuel);
				cout<<"-C landing queue-c2."<<endl;
				landingnum=landingnum+2;
				landing_runway++;
			}
			else if (landing_runway == 3)
			{	
				add_landing(d3_head, d3_last, landingnum,pilottime+114,how_fuel);
				cout << "-D landing queue-d3." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 4)
			{
				add_landing(b4_head, b4_last, landingnum,pilottime+305, how_fuel);
				cout << "-B landing queue-b4." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 5)
			{
				add_landing(c5_head, c5_last, landingnum,pilottime+562, how_fuel);
				cout << "-C landing queue-c5." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
			else if (landing_runway == 6)
			{
				add_landing(d6_head, d6_last, landingnum,pilottime+864,how_fuel);
				cout << "-D landing queue-d6." << endl;
				landingnum = landingnum + 2;
				landing_runway++;
			}
		}
		for (int i = 0; i < num_of_takeoff; i++)
		{
			if (takeoff_runway == 1)
			{
				add_takeoff(a_head, a_last, takeoffnum);
				cout << "enter the runway-A." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 2)
			{
				add_takeoff(b_head, b_last, takeoffnum);
				cout << "enter the runway-B." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 3)
			{
				add_takeoff(c_head, c_last, takeoffnum);
				cout << "enter the runway-C." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
			else if (takeoff_runway == 4)
			{
				add_takeoff(d_head, d_last, takeoffnum);
				cout << "enter the runway-D." << endl;
				takeoffnum = takeoffnum + 2;
				takeoff_runway++;
			}
		}
		
		cout << endl;

		if (a_head != NULL && flag_a == 0)
		{
			cout << "The plane id = " << a_head->id << " with waiting time = " << a_head->waiting_time << " takeoff from runway-A." << endl;
			a_head = a_head->next;
		}

		int b = compare(b_head, b1_head, b4_head);
		int c = compare(c_head, c2_head, c5_head);
		int d = compare(d_head, d3_head, d6_head);
		if (flag_a < 2)
		{
			switch (b)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(b_head);
				cout << "B." << endl;
				break;
			case 2:
				sub_landing(b1_head);
				cout << "B." << endl;
				break;
			case 3:
				sub_landing(b4_head);
				cout << "B." << endl;
				break;
			}
		}
		if (flag_a < 3)
		{
			switch (c)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(c_head);
				cout << "C." << endl;
				break;
			case 2:
				sub_landing(c2_head);
				cout << "C." << endl;
				break;
			case 3:
				sub_landing(c5_head);
				cout << "C." << endl;
				break;
			}
		}
		if (flag_a < 4)
		{
			switch (d)
			{
			case 0:
				break;
			case 1:
				sub_takeoff(d_head);
				cout << "D." << endl;
				break;
			case 2:
				sub_landing(d3_head);
				cout << "D." << endl;
				break;
			case 3:
				sub_landing(d6_head);
				cout << "D." << endl;
				break;
			}
		}

		cout << endl;
		timetemp++;
	}
	
	cout << "queue-a:" << endl;/*輸入的時間之後 列出還未離開跑道的飛機 */ 
    print_notyet(a_head);
	cout << "queue-b:" << endl;
    print_notyet(b_head);
	cout << "queue-c:" << endl;
	print_notyet(c_head);
	cout << "queue-d:" << endl;
	print_notyet(d_head);
	cout << endl;

	cout << "queue-B1:" << endl;
    print_notlanding(b1_head);
	cout << "queue-B4:" << endl;
	print_notlanding(b4_head);
	cout << "queue-C2:" << endl;
	print_notlanding(c2_head);
	cout << "queue-C5:" << endl;
	print_notlanding(c5_head);
	cout << "queue-D3:" << endl;
	print_notlanding(d3_head);
	cout << "queue-D6:" << endl;
	print_notlanding(d6_head);
	cout << endl;

	cout << "The average landing waiting time = " << ave_landing_time / airplane_landing << endl;
	cout << "The average takeoff waiting time = " << ave_takeoff_time / airplane_takeoff << endl;
	cout << "The average fuel saved = " << ave_fuel / airplane_landing << endl;
	cout << "Total airplane run out of fuel and landing in emergency = " << emergency_airplane<<endl;
	cout << "Total airplane broken without landing = " << airplane_crash<< endl;

	return 0;
	
}

void check_runway(takeoff *takeoffhead)
{
	 if (!isempty_takeoff(takeoffhead))
		{
			takeoff*current=takeoffhead;
			while (current!=NULL)
			{
				current->waiting_time++;
				current=current->next;
			}
		}
}
void print_notyet(takeoff*takeoffhead)
{
	while (takeoffhead!= NULL)
	{
		cout << "id = "<<takeoffhead->id << " " << "waiting time = " <<takeoffhead->waiting_time << endl;
		takeoffhead=takeoffhead->next;
	}
}
void print_notlanding(landing*landinghead)
{
	while (landinghead!= NULL)
	{
		cout << "id = " <<landinghead->id << " " << "fuel = " <<landinghead->fuel << " " << "waiting time = " <<landinghead->waiting_time << endl;
		landinghead=landinghead->next;
	}
}
int randomfuel(int initial, int n)
{
	srand(initial);
	int x = rand() % n + 1;
	return x;
}
int randomlanding(int initial, int n)
{
	srand(initial);
	int x = rand() % n;
	return x;
}
int randomtakeoff(int initial, int n)
{
	srand(initial);
	int x = rand() % n;
	return x;
}

bool isempty_landing(landing* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void add_first_landing(landing*& head, landing*& last, int id_num, int fuel_num, int maxfuel)
{
	landing* temp = new landing;
	temp->id = id_num;
	cout << "The plane id = " << temp->id << " ,";
	temp->fuel = randomfuel(fuel_num, maxfuel);
	cout << "and its fuel = " << temp->fuel << " ,enter the runway-";/*用new取址再取值*/
	temp->next = NULL;
	head = temp;
	last = temp;
}
void add_landing(landing*& head, landing*& last, int id_num, int fuel_num, int maxfuel)
{
	if (isempty_landing(head))
	{
		add_first_landing(head, last, id_num, fuel_num, maxfuel);
	}
	else
	{
		landing *temp = new landing;
		temp->id = id_num;
		cout << "The plane id = " << temp->id << " ,";
		temp->fuel = randomfuel(fuel_num, maxfuel);
		cout << "and its fuel = " << temp->fuel << " ,enter the runway-";
		temp->next = NULL;
		last->next = temp;   /*正方形下方的小長方形 再用下一行把兩個方塊接起來*/
		last = temp;         /*把linked list接起來*/
	}
}
void sub_landing(landing*& head)
{
	cout << "The plane id = " << head->id << " with fuel = " << head->fuel <<" with waitingtime = "<<head->waiting_time<< " landing at runway-";
	ave_fuel = ave_fuel + head->fuel;    /*head中的剩油量*/
	ave_landing_time = ave_landing_time + head->waiting_time;
	airplane_landing++;
	head = head->next;
}
void em_landing(landing*& temp, int flag)
{
	if (flag == 1)      /*在第一跑道降落*/
	{
		cout << "The plane id = " << temp->id << " is running out of fuel ,with waitingtime = " << temp->waiting_time << " ,landing at runway-A." << endl;
		ave_landing_time = ave_landing_time + temp->waiting_time;
		emergency_airplane++;
		temp = temp->next;
	}
	else if (flag == 2)
	{
		cout << "The plane id = " << temp->id << " is running out of fuel ,with waitingtime = " << temp->waiting_time << " ,landing at runway-B." << endl;
		ave_landing_time = ave_landing_time + temp->waiting_time;
		emergency_airplane++;
		temp = temp->next;
	}
	else if (flag == 3)
	{
		cout << "The plane id = " << temp->id << " is running out of fuel ,with waitingtime = " << temp->waiting_time << " ,landing at runway-C." << endl;
		ave_landing_time = ave_landing_time + temp->waiting_time;
		emergency_airplane++;
		temp = temp->next;
	}
	else if (flag == 4)
	{
		cout << "The plane id = " << temp->id << " is running out of fuel ,with waitingtime = " << temp->waiting_time << " ,landing at runway-D." << endl;
		ave_landing_time = ave_landing_time + temp->waiting_time;
		emergency_airplane++;
		temp = temp->next;
	}
	else
	{
		airplane_crash++;
		temp = temp->next;
	}
}

bool isempty_takeoff(takeoff* head)
{
	if (head == NULL)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void add_first_takeoff(takeoff*& head, takeoff*& last, int idnum)
{
	takeoff*   temp = new takeoff;
	temp->id = idnum;
	cout << "The plane id = " << temp->id << " ,";
	temp->next = NULL;
	head = temp;
	last = temp;
}
void add_takeoff(takeoff*& head, takeoff*& last, int idnum)
{
	if (isempty_takeoff(head))
	{
		add_first_takeoff(head, last, idnum);
	}
	else
	{
		takeoff* temp = new takeoff;
		temp->id = idnum;
		cout << "The plane id = " << temp->id << " ,";
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}
void sub_takeoff(takeoff*& head)
{
	cout << "The plane id = " << head->id<<" with waiting time = "<<head->waiting_time << " toakeoff from runway-";
	ave_takeoff_time = ave_takeoff_time + head->waiting_time;
	airplane_takeoff++;
	head = head->next;
}

int compare(takeoff* takeoffhead, landing* landinghead_1, landing* landinghead_2)    /*透過比較數字 數字小的先執行*/ 
{
	if(takeoffhead != NULL && landinghead_1 != NULL && landinghead_2 != NULL)
	{
		if (takeoffhead->id < landinghead_1->id && takeoffhead->id < landinghead_2->id)
		{
			return 1;
		}
		else if (landinghead_1->id < takeoffhead->id && landinghead_1->id < landinghead_2->id)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead == NULL && landinghead_1 != NULL && landinghead_2 != NULL)
	{
		if (landinghead_1->id < landinghead_2->id)
		{
			return 2;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 == NULL && landinghead_2 != NULL)
	{
		if (takeoffhead->id < landinghead_2->id)
		{
			return 1;
		}
		else
		{
			return 3;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 != NULL && landinghead_2 == NULL)
	{
		if (landinghead_1->id < takeoffhead->id)
		{
			return 2;
		}
		else
		{
			return 1;
		}
	}
	else if (takeoffhead != NULL && landinghead_1 == NULL && landinghead_2 == NULL)
	{
		return 1;
	}
	else if (takeoffhead == NULL && landinghead_1 != NULL && landinghead_2 == NULL)
	{
		return 2;
	}
	else if (takeoffhead == NULL && landinghead_1 == NULL && landinghead_2 != NULL)
	{
		return 3;
	}
	else
	{
		return 0;
	}
}
