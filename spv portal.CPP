/*class 12 project on "Sardar patel Vidyalaya Website"
   By JHALAK & SHUBHAM */

#include<graphics.h>
#include<conio.h>
#include<stdlib.h>
#include<dos.h>
#include<stdio.h>
#include<string.h>
#include <fstream.h>
#include<iostream.h>
#include<iomanip.h>

int locker1=0,locker2=0;
char lock1[100],lock2[100];
void spvpage();
int info();
void history();
void facilities();
void activities();
void about();
void exit1();
void login();
int chakra();

union REGS in,out;
struct SREGS s;
int gs_no=0;
int lflag=0;

initmouse()
{
   in.x.ax=0;//reset mouse
   int86(0x33,&in,&out);
   return out.x.ax;
}
showmouse()
{
    in.x.ax=1;//show mouse pointer
   int86(0x33,&in,&out);
   return out.x.ax;
}
void hidemouseptr()
{
   in.x.ax = 2; // hide mouse pointer
   int86(0x33,&in,&out);
}
void mouseposi(int &xpos,int &ypos,int &click)
{
   in.x.ax=3; // get mouse position return bx (mouse button status register)
   int86(0x33,&in,&out);
   click=out.x.bx; // bx=1 left button, bx=2 right, bx=3 center, bx=0 no button pressed
   xpos=out.x.cx; // cx --> x co-ordinate
   ypos=out.x.dx;  //dx --> y co-ordinate
}
void setmouseposi(int &xpos,int &ypos)
{
   in.x.ax=4; // set mouse position return bx (mouse button status register)
   in.x.cx=xpos;
   in.x.dx=ypos;
   int86(0x33,&in,&out);
}

 void Beep(float f,int dur)   //generate sound
{
   sound(f);
   delay(dur);
   nosound();
 }

class candidate{
    public :
	int gs_no;
	int vote;
	char name[20];

     public :
       void getgsdata();
       void dispgsdata();
       int voting()
       { return vote; }
       candidate()
       { gs_no=0;}
     };

  void candidate::getgsdata()
     {
		fflush(stdin);
		cout<<"Candidate Name : " ;
		gets(name);
		strupr(name);
		vote=0;
		gs_no++;
		fflush(stdin);
      }
      void candidate::dispgsdata()
     {           cout <<"\n " <<gs_no<< ": ";
	cout <<"\t "<<name
	     <<setw(10)<<"\tvote: " <<vote<<endl;
     }

 void history()
  {  char ans;
     closegraph();
     int gd=DETECT,gm,errorcode;
     initgraph(&gd,&gm,"..\\bgi");
     cleardevice();
     hidemouseptr();

setcolor(CYAN);
settextstyle(1,0,3);
outtextxy(120,8,"HISTORY OF SARDAR PATEL VIDYALAYA");
delay(1000);
settextstyle(SMALL_FONT,0,5);
delay(1000);
setcolor(YELLOW);
outtextxy(2,45,"The School is Inspired by the ideals of Sardar Patel.In 1958,the Gujarat Education");
delay(1000);
outtextxy(2,62,"Society established Sardar Patel Vidyalaya to meet the diverse educational needs");
delay(1000);
outtextxy(2,79,"of the Capital of independent India. What began with an objective to keep alive");
delay(1000);
outtextxy(2,96,"the best of Gujarati culture and heritage and yet strive for the modern and be");
delay(1000);
outtextxy(2,113,"progressive,now envelops the totality of Indian culture and heritage.Shri H.M Patel ");
delay(1000);
outtextxy(2,130,"as our founder president provided the leadership. Dr.Raghubhai Nayak as the first ");
delay(1000);
outtextxy(2,147,"Principal laid the foundation and his successor. Smt. Vibhaben Parthasarathi ");
delay(1000);
outtextxy(2,164,"cemented the value based child centric educational approach.");
delay(1000);
outtextxy(2,198,"Our Mission SPV stands for a strong value system based on a unique blend of tested");
delay(1000);
outtextxy(2,215,"traditions and modern educational trends. While children have firm roots in their ");
delay(1000);
outtextxy(2,232,"Indian identity they are also encouraged to grow wings which help them  ");
delay(1000);
outtextxy(2,250,"fly high globally......");
delay(1500);
line(1,405,600,405);
setcolor(LIGHTBLUE);
settextstyle(SMALL_FONT,0,6);
outtextxy(250,410,"press B to go back");
outtextxy(250,430,"press Enter to exit");
 ans=getch();
if(ans==13)
    exit1();
 else if (ans==98||ans==66)
  spvpage();
   else 
     exit1();
 }

   void activities()
  {  char ans;
     closegraph();
     int gd=DETECT,gm,errorcode;
     initgraph(&gd,&gm,"..\\bgi");
     cleardevice();
     settextstyle(TRIPLEX_FONT,0,3);

setcolor(MAGENTA);
outtextxy(200,3,"Activities at school");
delay(1000);
setcolor(6);
settextstyle(11,0,1);
outtextxy(50,44,"ACTIVITY WEEK :");
delay(300);
setcolor(WHITE);
settextstyle(2,0,5);
outtextxy(165,39," Time To Put Away The Books And The Bags ");
settextstyle(11,0,1);
setcolor(CYAN);
delay(1000);
outtextxy(10,60,"Every year Activity Week is held in SPV in which the school's four houses");
delay(1000);
outtextxy(10,74,"i.e.");
setcolor(RED);
outtextxy(43,74,"Shakti");
delay(300);
setcolor(LIGHTBLUE);
outtextxy(93,74,",Neeti,");
delay(300);
setcolor(YELLOW);
outtextxy(140,74," Jyoti ");
delay(300);
setcolor(CYAN);
outtextxy(183,74," and");
setcolor(GREEN);
outtextxy(223,74,"Pragati");
delay(300);
setcolor(CYAN);
outtextxy(278,74," compete. During the sports week,events like");
delay(1000);
outtextxy(10,88,"100 to 1500m race,shot put,javelin throw,discus throw, high jump, long jump");
delay(1000);
outtextxy(10,102,"and triple jump are held. Inter house basketball, football,volley ball");
delay(1000);
outtextxy(10,116,"and chess matches are also held. An inter-house sports quiz is also held.");
delay(1000);

setcolor(BROWN);
delay(1000);
settextstyle(11,0,1);
outtextxy(50,138,"NEIGHBOURHOOD PROJECT :");
delay(300);
setcolor(WHITE);
settextstyle(2,0,5);
outtextxy(235,133," Make differenece to the life of others ");
delay(1000);
settextstyle(11,0,1);
setcolor(CYAN);
delay(1000);
outtextxy(10,154,"This project is a concerted effort by the school especially for under");
delay(1000);
outtextxy(10,168,"priviledged children of neighbouring areas. Twice a week Student volunteers ");
delay(1000);
outtextxy(10,182,"of class XI spend time with these children. The program covers development of ");
delay(1000);
outtextxy(10,196,"basic skills such as making Diyas for Diwali,designing cards and calendars,");
delay(1000);
outtextxy(10,210,"theatre, workshops, coaching for games etc.");

setcolor(BROWN);
delay(1000);
settextstyle(11,0,1);
outtextxy(50,232,"C.A. Program :");
delay(300);
setcolor(WHITE);
settextstyle(2,0,5);
outtextxy(170,228,"Sensitization to the natural and cultural heritage ");
settextstyle(11,0,1);
setcolor(CYAN);
delay(1000);
outtextxy(10,246,"C.A. can mean different things to different people. It can stand for Cultural");
 delay(1000);
outtextxy(10,260,"activities, Current Affairs, Counselor Activity or Career Advice - as one sees");
delay(1000);
outtextxy(10,274,"its role.Actually,it is all rolled into one... and more.Its a weekly Programme");
delay(1000);
outtextxy(10,288,"where Children participate in folk dances, short plays, science programmes,");
delay(1000);
outtextxy(10,302,"quizzes and all the sections of a class put up a joint show.");

setcolor(BROWN);
delay(1000);
settextstyle(11,0,1);
outtextxy(50,324,"Students Executive : ");
delay(300);
setcolor(WHITE);
settextstyle(2,0,5);
outtextxy(215,320,"Democracy ");
settextstyle(11,0,1);
setcolor(CYAN);
delay(1000);
outtextxy(10,338,"At SPV, the school representatives are democratically elected. Each student");
delay(1000);
outtextxy(10,352,"experiences the voting process of secret ballot, getting the ink mark on ");
delay(1000);
outtextxy(10,366,"their fingers.The process begins with election of 6 Class Representatives");
delay(1000);
outtextxy(10,380,"each from class VIto XII. Class Representatives in turn elect the G.S.and the Deputy G.S. The ");
delay(1000);
outtextxy(10,394,"elected students would have to take care of their departments.");
delay(1000);

line(1,415,630,415);
setcolor(LIGHTBLUE);
settextstyle(SMALL_FONT,0,6);
outtextxy(250,420,"press B to go back");
outtextxy(250,440,"press Enter to exit");
 ans=getch();
if(ans==13)
    exit1();
 else if (ans==98||ans==66)
    spvpage();
 else  
    exit1();
  }

 void facilities()
  {  char ans;
     closegraph();
     hidemouseptr();
     int gd=DETECT,gm,errorcode;
     initgraph(&gd,&gm,"..\\bgi");
     cleardevice();

   settextstyle(1,0,3);
delay(100);
setcolor(BROWN);
outtextxy(240,0,"FACILITIES" );
delay(1000);
settextstyle(SMALL_FONT,0,6);
setcolor(3);
outtextxy(1,45,"SPORTS COMPLEX: ");
delay(1000);
settextstyle(SMALL_FONT,0,5);
setcolor(YELLOW);
delay(1000);
outtextxy(147,48,"The students can play various sports such as Cricket,basketball");
delay(1000);
outtextxy(1,63,"and volleyball on the school play ground. SPV also has an indoor sports complex.");
delay(1000);
outtextxy(1,77,"Here the students have the opportunities for training in different sports such as");
delay(1000);
outtextxy(1,92,"Chess,Carom,Table Tennis,Judo-karate and Gymnastics.The students can also learn ");
delay(1000);
outtextxy(1,106,"aerobics and Tae-kwon-do.");
settextstyle(SMALL_FONT,0,6);
setcolor(CYAN);
delay(1000);
outtextxy(1,132,"LIBRARY:");
delay(1000);
settextstyle(SMALL_FONT,0,5);
setcolor(YELLOW);
outtextxy(68,135," Sardar Patel Vidyalaya has a small but very effective Library. Surrounded");
delay(1000);
outtextxy(1,150,"by Ashoka trees,it has a modern look and is well lighted. The libraray is well");
delay(1000);
outtextxy(1,165,"stocked with a collection 20000 books,subscribes to 25 latest magazines of current");
delay(1000);
outtextxy(1,180,"affairs and 6 daily newspapers and fairly large collection of Reference books.");
delay(1000);
settextstyle(SMALL_FONT,0,6);
setcolor(3);
outtextxy(1,207,"CANTEEN:");
delay(1000);
settextstyle(SMALL_FONT,0,5);
setcolor(YELLOW);
outtextxy(74,209," Fixed, but daily varying meals for students in the Nursery and Class I");
delay(1000);
outtextxy(1,224,"are supplied by the school canteen. Older children can choose from freshly cooked");
delay(1000);
outtextxy(1,238,"variety of snacks like samosa, vada, dosa, idlis, burgers and noodles. The PTA");
delay(1000);
outtextxy(1,252,"sub-committee members check the quality of food from time to time. Aerated drinks");
delay(1000);
outtextxy(1,266,"are not permitted.");
delay(1000);
settextstyle(SMALL_FONT,0,6);
setcolor(CYAN);
outtextxy(1,292,"TRANSPORTATION:");
delay(1000);
settextstyle(SMALL_FONT,0,5);
setcolor(YELLOW);
outtextxy(155,294,"The School, in collaboration with the DTC, provides transport");
delay(1000);
outtextxy(1,309,"for children from designated stops to and from the school.Maximum areas of the city");
delay(1000);
outtextxy(0,324,"is covered through 22 bus routes. The safety of the children is utmost taken care ");
delay(1000);
outtextxy(0,338,"by the teachers and a lady care taker travelling in the bus.");
delay(1000);
settextstyle(SMALL_FONT,0,6);
setcolor(CYAN);
outtextxy(1,367,"MEDICAL CENTRE:");
delay(1000);
settextstyle(SMALL_FONT,0,5);
setcolor(YELLOW);
outtextxy(153,370,"Periodical check-up by medical specialists are organised and");
delay(1000);
outtextxy(0,385,"reports are sent to parents with suggestions. The Medical Centre also maintains");
delay(1000);
outtextxy(0,399,"medical report of each child.");
setcolor(LIGHTBLUE);
line(0,425,800,425);
settextstyle(SMALL_FONT,0,6);
outtextxy(230,430,"press B to go back");
outtextxy(230,447,"press Enter to exit");
ans=getch();
if(ans==13)
  exit1();
else if (ans==98||ans==66)
  spvpage();
else
    exit1();
}

   void about()//ABOUT US
  {
      char ans;
     hidemouseptr();
     cleardevice();
     closegraph();
     int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");
settextstyle(1,0,3);
setcolor(CYAN);
outtextxy(225,20,"ABOUT US");
delay(1000);
setcolor(YELLOW);
settextstyle(SMALL_FONT, HORIZ_DIR ,5);
outtextxy(10,60,"Sardar Patel Vidyalaya belongs to the Gujarat Education Society. The School was ");
delay(1000);
outtextxy(10,80,"established in the  year 1958. The school is also popularly known as SPV in Delhi.");
delay(1000);
outtextxy(10,100,"The school is affiliated to the CBSE Board, Delhi and imparts education from");
delay(1000);
outtextxy(10,120,"nursery to senior secondary classes. The principal is Mrs. Anuradha Joshi. ");
delay(1000);
outtextxy(10,140,"There are about 1500 students receiving education in the SPV. ");
delay(1000);
outtextxy(10,160,"Medium of Instruction is Hindi (till class 5), English (class 6 onwards)");
delay(1000);
outtextxy(10,180,"The school believes in inculcating in its students a strong value system based ");
delay(1000);
outtextxy(10,200,"on a unique blend of traditions and modernity.");
setcolor(LIGHTGREEN);
delay(1000);
settextstyle(SMALL_FONT, HORIZ_DIR ,5);
outtextxy(10,235,"Our Motto :\"Education is wealth\"");
delay(1500);
settextstyle(SMALL_FONT, HORIZ_DIR ,6);
setcolor(BROWN);
outtextxy(10,297,"Contact for more Details :");
delay(1000);
settextstyle(SMALL_FONT, HORIZ_DIR ,5);
setcolor(LIGHTBLUE);
outtextxy(10,320,"Sardar Patel Vidyalaya");
delay(1000);
outtextxy(10,335,"Lodi Estate");
delay(1000);
outtextxy(10,350,"New Delhi-110003");
delay(1000);
outtextxy(10,365,"Phone- (011) 24627344");
delay(1000);
outtextxy(10,380,"Email- spvdelhi@gmail.com");
delay(1000);
setcolor(MAGENTA);
line(0,403,800,403);
setcolor(GREEN);
settextstyle(SMALL_FONT,0,6);
outtextxy(220,410,"press B to go back");
outtextxy(220,430,"press Enter to exit");
delay(1000);
 ans=getch();
if(ans==13)
  exit1();
else if (ans==98||ans==66)
  spvpage();
else 
  exit1();
}

void exit1()
{
hidemouseptr();
closegraph();

int gd=DETECT,gm;
initgraph(&gd,&gm,"..\\bgi");

Beep(493.88,100);
Beep(261.63,100);
delay(500);//wait for some time before exiting
setcolor(MAGENTA);
   rectangle(0,5,630,400);
   rectangle(12,15,618,390);
   settextstyle(1,0,5);
   setcolor(LIGHTGREEN);
   outtextxy(180,60,"THANK YOU");
   settextstyle(1,0,3);
   setcolor(YELLOW);
   outtextxy(160,138,"Hope To See You Again !");
   settextstyle(1,0,1);
   setcolor(BLUE);
   outtextxy(220,270,"HAVE A NICE DAY !");
   delay(3000);
   closegraph();
   exit(0);
  }

 void admin()
{  clrscr();
   admmenu:
   while(1)
   {
   clrscr();
   textbackground(YELLOW);
   textcolor(BLUE);
   int ch=0,ch_s=0,ch_a=0;
   cout<<"\n\n\t\t\t*****Admin MENU *****";
   cout <<"\n\n ";
   cout << "\n \t\t\t 1. Vote menu";
   cout << "\n \t\t\t 2. Declare GS winner ";
   cout << "\n \t\t\t 3. Exit";
   cout << "\n\n";
   cout << "\t\t\tEnter Your Choice :=> ";
   fflush(stdin);
   ch=getch();
   switch(ch)
    {
      case '1':// ch ADMIN's VOTE sub menu
      while (1)
      {
	 int gno=0;
	 clrscr();
	 cout << "\n\n\t\t\t====== VOTE MENU  ======";
	 cout <<"\n\n ";
	 cout << "\n \t\t\t 1. Create NEW GS Data File ";
	 cout << "\n \t\t\t 2. Display GS Candidates Details";
	 cout << "\n \t\t\t 3. Return to Admin menu";
	 cout << "\n\t\t\t 4. Exit Program";
	 cout << "\n\n";
	 cout << "\t\t\t Select Your Choice :=> ";
	 fflush(stdin);
	 ch_a = getch();
	 switch(ch_a)
	    {
	     case '1' ://ch_a
		class candidate g;
		int gsno=0;
		char confirm='n';
		clrscr();
		cout <<"\n\n\tTHIS WILL OVERWRITE EXISTING GS File.";
		cout <<"\n\n\n\tAre you sure you want to make new entries for GS candidates? (Y/N)";
		cin >>confirm;

		if (confirm=='y' || confirm=='Y')
		{
		  fstream fgs;
		  fgs.open ("spvgs.dat",ios::out|ios::binary);
		  clrscr();
		  gotoxy(3,3);
		  puts("\nNew entry for S.P.V. G.S. candidate ");
		  cout <<"\n\nEnter number of GS candidate : ";
		  cin >>gsno;

		for (int i=0;i<gsno;i++)
		 {
		  g.getgsdata();
		  fgs.write((char*)&g,sizeof(g));
		 }
		 fgs.close();
		 }
		 break;

	    case '2' ://ch_a
		  class candidate gg;
		  fstream fgs1;
		  clrscr();
		  gotoxy(5,5);
		  cout <<"\n\nDISPLAY ALL GS CANDIDATES DETAILS...  \n";
		  fgs1.open ("spvgs.dat",ios::in|ios::binary);
		  fgs1.read((char*)&gg,sizeof(gg));
		  while (!fgs1.eof())
		    {
		      gg.dispgsdata();
		      fgs1.read((char*)&gg,sizeof(gg));
		    }
		   fgs1.close();
		   getch();
		   break;

	    case '3' : //ch_a
		  goto admmenu;
		  break;

	    case '4' :   //ch_a
		  exit1();
		  break;

	    default : //ch_a
		cout <<"\n\n\tWRONG CHOICE...";
		cout <<"\n\n\tPress a key...";
		getch();
		break;
	      } //swich ch_a over
      } //while loop of ch_a over

 case '2' : //ch choice
	class candidate gg;
	cout <<"\n\n\n\t\tWINNER of GS ELECTIONS --> ";
	fstream fgsm;
	fgsm.open ("spvgs.dat",ios::in|ios::out|ios::binary);
	while (!fgsm.eof())
	 {
	  fgsm.read((char*)&gg,sizeof(gg));
	  if(gg.voting()>locker1)
	    {
	      locker1=gg.voting();
	      strcpy(lock1,gg.name);
	     }
	  }
	 fgsm.close();
	 fgsm.open ("spvgs.dat",ios::in|ios::out|ios::binary);

	 while (!fgsm.eof())
	 {
	   fgsm.read((char*)&gg,sizeof(gg));
	   if(gg.voting()!=locker1)
	   {
	     if(gg.voting()>=locker2)
		{
		   locker2=gg.voting();
		   strcpy(lock2,gg.name);
		}
	     }
	   }
	 fgsm.close();
	 puts(lock1);
	 cout<<endl;
	 cout<<"\n\t\tDEPUTY GS IS  --> ";
	 puts(lock2);
	 char ans;
	 ans=getch();
	 if(ans==13)
	 goto admmenu;
	 break;

  case '3' ://ch MAIN MENU  case 3 EXIT
	 exit1();
	 break;

  default :   //ch MAIN MENU
	      cout <<"\n\tWRONG CHOICE.. ";
	      cout <<"\n\n\tPlease enter valid choice again  ";
	      getch();
	      break;
  }
 }
}

void vote_student()
  {
    int gno;
    char ch3;
    class candidate gg;
    fstream fgsm1;
    clrscr();
    textbackground(YELLOW);
    textcolor(BLUE);
    cout << "\n\t\t====== CASTE YOUR VOTE  WISELY======\n";
    cout <<" \n\t\t\tLIST OF CANDIDATES \n";

	fgsm1.open ("spvgs.dat",ios::in|ios::binary);
	fgsm1.read((char*)&gg,sizeof(gg));
	int rec_count=0;
	while (!fgsm1.eof())
	{ rec_count++;
	  cout << "\n \t\t\t  " <<gg.gs_no <<".  ";
	  cout <<gg.name;
	  fgsm1.read((char*)&gg,sizeof(gg));
	 }
	  cout <<"\n\n\t Enter the Candidate number you want to VOTE for -->  ";
	  cin >>gno;
	  if (gno >rec_count || gno <=0)
	     { cout <<" \n\t Invalid vote...   Exitting ...... ";
	       getch();
	       exit1();
	     }
	fgsm1.close();
	fgsm1.open ("spvgs.dat",ios::in|ios::out|ios::binary);
	fgsm1.read((char*)&gg,sizeof(gg));
	while (!fgsm1.eof())
	 {  if (gg.gs_no==gno)
	    {
	     gg.vote++; // vote incremented of the desired candidate
	     fgsm1.seekp(fgsm1.tellg()-sizeof(gg));
	     fgsm1.write((char*)&gg,sizeof(gg));
	     break;
	     }
	    else
	     fgsm1.read((char*)&gg,sizeof(gg));
	  }
	fgsm1.close();
	cout <<"\n\n\n\t\t\tYOUR VOTING IS SUCCESSFUL .....";
	cout << "\n\n\n\n\n\n\t\t\t Press Enter to exit ";
	ch3=getch();
	if (ch3==13)
	  exit1();
	}

  void draw_info_panel()
{
   int left, top, c, color;
   left = 400;
   top = 190;

   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(GREEN);
   rectangle(left-4,top-5,left+104,top+150);
    delay(20);
    setcolor(BLUE);
   for( c = 1 ; c <= 5 ; c++ )
   {
      rectangle(left, top, left+100, top+25);
      top += 30;
      delay(20);
   }
   top=190;
   setcolor(BROWN);
   outtextxy(left+5,top,"History");
   delay(10);
   outtextxy(left+5,top+30,"Activities");
   delay(10);
   outtextxy(left+5,top+60,"Facilities");
   delay(10);
   outtextxy(left+5,top+90,"About Us");
   delay(10);
   outtextxy(left+5,top+120,"EXIT");
 }

void login()
{  char uname[20];
   char pass[10];
   int cont=0;
   int left, top, c, color;
   left = 300;
   top = 250;

   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   setcolor(BLUE);
   rectangle(left,top,left+220,top+85);

   setcolor(GREEN);
   settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
   outtextxy(left+90,top-20,"Login");

   setfillstyle(1,4);
   bar(left+15,top+20,left+65,top+40);
   settextstyle(SMALL_FONT,HORIZ_DIR,5);
   setcolor(BLUE);
   outtextxy(left+20,top+21,"GUEST");

   bar(left+80,top+20,left+140,top+40);
   outtextxy(left+83,top+21,"STUDENT");

   bar(left+155,top+20,left+205,top+40);
    outtextxy(left+160,top+21,"ADMIN");

   setcolor(BLUE);
   gotoxy(60,25);
   initmouse();
   while (cont==0)
   { int x1,y1,cl;
   showmouse();
   mouseposi(x1,y1,cl);//get mouse position to see which login clicked
if (cl==1)
{
 setcolor(2);
 int left=300;int top=250;
 if (x1>=left+15 && x1<=left+65 && y1>=top+20&&y1<=top+40)
 {
  lflag=1;
  outtextxy(315,280,"GUEST");
  spvpage();
  //info();
  }
 if (x1>=left+80 && x1<=left+140 && y1>=top+20&&y1<=top+40)
 {
  top += 60;
  again1:
  setcolor(2);
  outtextxy(left+20,top,"Password");
  bar(left+90, top, left+115, top+20);
  setmouseposi(left+90,top);
  setcolor(BLACK);
  for(int i=0,off=0;i<3;i++)
  {
  pass[i]=getch();
  outtextxy(left+90+off,top,"*");
  off+=7;
  }
  pass[i]='\0';
  setcolor(2);
  if(strcmp(pass,"spv")==0)
   {
    outtextxy(left+20,top+55,"Successful login");
    delay(1500);
    closegraph();
    clrscr();
    textbackground(YELLOW);
    textcolor(BLUE);
    vote_student();
    }
else
  {
   outtextxy(left+20,top+35,"WRONG!! Re-enter password ");
   goto again1;
   }
  }

  if (x1>=left+155 && x1<=left+205 && y1>=top+20&&y1<=top+40)
  {
  top += 60;
  again2:
  setcolor(2);
  outtextxy(left+20,top,"Password");
  bar(left+90, top, left+160, top+20);
  setmouseposi(left+90,top);
  setcolor(BLACK);
  for(int i=0,off=0;i<9;i++)
  { pass[i]=getch();
    outtextxy(left+90+off,top,"*");
    off+=7;
  }
  pass[i]='\0';
  setcolor(2);
  if(strcmp(pass,"vidyalaya")==0)
  {
    outtextxy(left+20,top+55,"Successful login");
    delay(1500);
    closegraph();
    clrscr();
    textbackground(YELLOW);
    textcolor(BLUE);
    admin();
 }
else
 {
  outtextxy(left+20,top+35,"WRONG!! Re-enter password ");
  goto again2;
  }
  }
 }
 }
getch();
}

int info()
 {
   int x,y,cl;
   int cont=0;
   settextstyle(SANS_SERIF_FONT,HORIZ_DIR,1);
   draw_info_panel();
   while (cont==0)
 {
int x1,y1,cl;
  gotoxy(60,25);
  setcolor(RED);
showmouse();
//changecursor(cursor);
settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
mouseposi(x1,y1,cl);
if (cl==1)
{ setcolor(2);
 int left=400;int top=190;
if (x1>=left && x1<=left+100 && y1>=top&&y1<=top+25)
      history();
if (x1>=left && x1<=left+100 && y1>=top+30&&y1<=top+30+25)
     activities();
if (x1>=left && x1<=left+100 && y1>=top+60&&y1<=top+60+25)
    facilities();
if (x1>=left && x1<=left+100 && y1>=top+90&&y1<=top+90+25)
   about();
if (x1>=left && x1<=left+100 && y1>=top+120&&y1<=top+120+25)
  exit1();
    }
  }
return 0;
}


int chakra()
{
   int i=0,Y=38,status_m,xx,yy;
    float f;
   setcolor(BROWN);
   for(i=20;i<30;i++)
   {
   arc(50,240+Y,270,90,i); // innermost arc
   delay(20);
   }
Beep(293.66,200);

for(i=40;i<43;i++)
{
arc(50,240+Y,270,90,i);
delay(20);
}
Beep(293.66,100);

for(i=55;i<58;i++)
{
arc(50,240+Y,270,90,i);
delay(30);
}

//circles for the inner ring
arc(51,191+Y,270,90,3);
delay(20);
circle(67,194+Y,3);
delay(20);
circle(83,203+Y,3);
delay(20);
circle(94,220+Y,3);
delay(20);
circle(98,240+Y,3);
delay(20);
circle(94,259+Y,3);
delay(20);
circle(83,277+Y,3);
delay(10);
circle(67,286+Y,3);
delay(10);
arc(51,288+Y,270,90,3);
Beep(293.66,100);

setcolor(RED);
//set 1
circle(79,167+Y,3);
circle(79,167+Y,7);
delay(10);
Beep(293.66,100);

//set 2
circle(119,210+Y,3);
circle(119,210+Y,7);
delay(10);
Beep(329.66,100);

//set 3
circle(123,275+Y,3);
circle(123,275+Y,7);
delay(10);
Beep(349.23,100);

//set 4
circle(76,316+Y,3);
circle(76,316+Y,7);
delay(10);

Beep(391.00,100);
setcolor(YELLOW); 
//set1
arc(45,185+Y,0,48,28);  //design in chakra- small arc
arc(110,193+Y,128,180,28);
delay(30);
arc(1,111+Y,320,358,80);
arc(165,135+Y,166,207,80);
delay(30);

Beep(293.66,100);

//set2 chakra design -small arc
arc(104,248+Y,50,90,28);
arc(82,195+Y,320,0,28);
arc(184,278+Y,96,140,80);
arc(129,116+Y,256,300,80);
delay(30);

Beep(329.63,100);

//set3 chakra design
arc(108,233+Y,265,310,28);  //design in chakra- small arc
arc(89,293+Y,10,65,28);
arc(116,343+Y,36,90,55);
arc(187,220+Y,210,256,72);
delay(30);

Beep(349.23,100);

//set4 chakra design
arc(40,295+Y,315,0,28);  //design in chakra- small arc
arc(99,280+Y,205,250,28);
arc(11,358+Y,352,40,65);
arc(169,332+Y,162,203,83);
Beep(440.00,100);

setcolor(BLUE);
line(50,110+Y,50,183+Y);
line(51,110+Y,51,183+Y);//thicker line
delay(30);
line(93,205+Y,133,141+Y);
line(94,205+Y,134,141+Y);//thicker line
delay(30);
line(107,240+Y,180,240+Y);
line(109,241+Y,181,241+Y); //thicker line
delay(30);
line(89,281+Y,135,338+Y);
line(90,281+Y,136,338+Y); //thicker line
delay(30);
line(50,298+Y,50,372+Y);
line(51,298+Y,51,372+Y); //thicker line

setcolor(BROWN);
for(i=130;i<133;i++)
{
arc(50,240+Y,270,90,i);
delay(30);
}
Beep(493.88,100);

arc(50,240+Y,270,90,145);
delay(30);
arc(50,240+Y,270,90,146);
arc(50,240+Y,270,90,147);
delay(30);
arc(50,240+Y,270,90,163);
arc(50,240+Y,270,90,164);
arc(50,240+Y,270,90,165);
delay(30);
for(i=172;i<178;i++)//make thicker
{
arc(50,240+Y,270,90,i);
delay(20);
}
Beep(329.63,100);

//circles in the outer ring
circle(55,85+Y,7);
circle(103,94+Y,7);
delay(20);
circle(144,116+Y,7);
delay(30);
circle(175,149+Y,7);
delay(30);
circle(197,190+Y,7);
delay(30);
circle(205,240+Y,7);//middle
circle(197,290+Y,7);//downwards
circle(175,334+Y,7);
circle(144,363+Y,7);
circle(103,385+Y,7);
delay(30);
circle(54,396+Y,7);
delay(30);
Beep(349.23,100);
setcolor(LIGHTGRAY); 
//arc on the outermost ring- thicker
for(i=10;i<13;i++)
{
arc(192,133+Y,305,122,i);
delay(40);
}

for(i=10;i<13;i++)
{
arc(228,240+Y,270,90,i);
delay(20);
}
for(i=10;i<13;i++)
{
arc(110,72+Y,335,159,i);
delay(30);
}
for(i=10;i<13;i++)
{
arc(193,346+Y,225,55,i);
delay(30);
}
for(i=10;i<13;i++)
{
arc(110,408+Y,195,30,i);
delay(30);
}
Beep(493.88,100);  //chakra design complete
return 0;
   }

void welcomepage()
 {
int gd=DETECT,gm,errorcode;
closegraph();
initgraph(&gd,&gm,"..\\bgi");
/* read result of initialization */
errorcode = graphresult();
if (errorcode != grOk)  /* an error occurred */
{
  printf("Graphics error: %s\n", grapherrormsg(errorcode));
  printf("Press any key to halt:");
  getch();
  exit(1); /* terminate with an error code */
 }
 initmouse();
 hidemouseptr();

setcolor(CYAN);
int maxx=getmaxx();
for (int xx=maxx;xx>150;xx--)
   {  settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
      outtextxy(xx,1,"Sardar Patel Vidyalaya");
      delay(4);
      cleardevice();
    }
setcolor(YELLOW);
outtextxy(xx,1,"Sardar Patel Vidyalaya");
setcolor(CYAN);
rectangle(0,3,635,475);
rectangle(5,7,630,470);

settextstyle(TRIPLEX_FONT,HORIZ_DIR,3 );
setcolor(LIGHTMAGENTA);
int x=220, y=120;
outtextxy(x,y,"Welcomes YOU ");

struct time t;
gettime(&t);
settextstyle(4,0,3);
setcolor(YELLOW);
delay(5);
outtextxy(x+20,y+150,"Wishing YOU ");
if (t.ti_hour>12)   //t.ti_hour,t.ti_min,t.ti_sec
   outtextxy(x-40,y+190,"A Very Good Afternoon ");
else
   outtextxy(x+20,y+190,"Good Morning");

settextstyle(SMALL_FONT,HORIZ_DIR,5);
setcolor(LIGHTGREEN);
outtextxy(x+195,y+300,"PROJECT PRESENTED BY :");
outtextxy(x+205,y+320,"JHALAK & SHUBHAM ");
delay(3000);
cleardevice();
 }

void spvpage()
{
  int maxx=getmaxx();
  int i,xx=maxx;

  closegraph();
  int gd=DETECT,gm;
  initgraph(&gd,&gm,"..\\bgi");
  initmouse();
  if ( initmouse() == 0 )
  {
    closegraph( ) ;
    restorecrtmode( ) ;
    printf ( "\nMouse driver not loaded" ) ;
    exit (1) ;
   }

hidemouseptr();
setcolor(YELLOW);
rectangle(2,10,635,475);
rectangle(30,85,600,470);

settextstyle(GOTHIC_FONT,HORIZ_DIR,5);
outtextxy(150,1,"Sardar Patel Vidyalaya");
settextstyle(5,0,3);
setcolor(LIGHTGREEN);
outtextxy(180,47,"Its a different school of thought");
for(i=0;i<2000;i++) //putpixel randomely
 {   delay(1);
     putpixel(random(630),random(470),random(15));
  }
chakra();
if (lflag==1)
    info();
 }

 void main()
   {
     int i=0,x,y,xx;
     clrscr();
     welcomepage();
     spvpage();
     login();
     getch();
     closegraph();
     }
