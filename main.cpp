#include<windows.h>
#include<bits/stdc++.h>
#include<GL/glut.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 7
#define MAX 7
int becount=0;
int bp1=0,bp2=0,bp3=0,bp4=0,bp5=0,bp6=0;
static int box=0;
int box1=0,box2=0,box3=0;
static int fillcount=0;
static int ay=0,sy=0;
int sl1=0,sl2=0,sl3=0,sl4=0,sl5=0,sl6=0,sl7=0;
int fp=0,sp=0,tp=0,ffp=0,fffp=0,ssp=0,ep=0,eep=0,twp=0,np=0,ftp=0;

int ay1=0,ay2=0,ay3=0,ay4=0,ay5=0,ay6=0,ay7=0,ay8=0,ay9=0;
int sy1=0,sy2=0,sy3=0,sy4=0,sy5=0,sy6=0,sy7=0,sy8=0,sy9=0,sy10=0,sy11=0,sy12=0;
int value = 0;
int window;
int menu_id;
static int itemno=0;


void *font =   GLUT_BITMAP_HELVETICA_18;
void *fonts[] =
{
  GLUT_BITMAP_9_BY_15,
  GLUT_BITMAP_TIMES_ROMAN_10,
  GLUT_BITMAP_TIMES_ROMAN_24
};

char defaultMessage[] = "Department of Computer Science And Engineering";
char *message = defaultMessage;



void output(int x, int y, char *str) // render string on screen for intro and home page
{
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(str);
  for (i = 0; i < len; i++)
    {
    glutBitmapCharacter(font, str[i]);
  }
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, h, 0);
    glMatrixMode(GL_MODELVIEW);

}

void display1(void) // main home page display(name ,title ,signature etc)
{
    glDisable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(1.0,1.0,1.0,0.0);
    glColor3f(1.0,0.0,0.0);
    output(120, 550, "N.M.A.M INSTITUTE OF TECHNOLOGY,NITTE");
    glColor3f(1.0,0.0,0.0);
    output(210, 500, "A MINI PROJECT ON");
    output(40, 470, "SIMULATION OF SCANELINE POLYGON FILLING ALGORITHM");
    glColor3f(0.0f, 0.0f, 1.0f);//Orange
    output(120, 400, "COURSE NAME : COMPUTER GRAPHICS");
    output(230, 350, "SECTION : C");
    output(210, 300, "SUBMITTED BY :-");
    output(150, 270, "S DHRUVA         4NM18CS152");
    output(150, 240, "SAMIT D MANVAR   4NM18CS152");
    glColor3f(0.0,0.0,1.0);
    output(180, 180, "UNDER THE GUIDANCE OF :-");
    output(230, 150, "MR PUNEETH RP");
    output(160, 130, "ASSISTANT PROFESSOR GRADE II");
    output(50, 100, "DEPARTMENT OF COMPUTER SCIENCE AND ENGINEERING");
    glEnd();
    glFlush();
    glutSwapBuffers();
    glutReshapeFunc(reshape);

}

void introduction(void)   //introduction page about the project(content)
{
  glDisable(GL_DEPTH_TEST);
  glClear(GL_COLOR_BUFFER_BIT);
  glClearColor(1.0,1.0,1.0,0.0);
  glColor3f(0.0,0.0,0.0);
  output(250, 550,"INTRODUCTION");
  glVertex2f(0.75, -0.75);
  glColor3f(0.0,0.0,0.0);
  output(270,500," OpenGL");
  glColor3f(  0.137255f, 0.556863f,0.419608f);
  output(10, 480," OpenGL is a cross-language, cross-platform application programming ");
  output(0, 460,"    interface for rendering 2D and 3D vector graphics. ");
  glColor3f(1.0,0.0,0.0);
  output(150,400," Scanline polygon filling algorithm");
  output(10,360," Scanline filling is basically filling up of polygons using horizontal lines");
  output(0,340,"  or scanlines.The purpose of the SLPF algorithm is to fill (color) the ");
  output(0,320,"  interior pixels of a polygon given only the vertices of the figure. ");

    glColor3f(0.0,0.0,1.0);
  output(250,280," Edge Table");
  output(0,240,"  It consists of several edge lists -> holds all of the edges that compose   ");
  output(10,220," the figure of the edges that compose the figure. ");
  glColor3f(0.0,0.0,1.0);
  output(230,180," Active Edge Table");
  output(0,140," It maintains the current edges being used to fill in the polygon edges");
  output(0,120,"  are pushed into the AL from the Edge Table when an edge’s");
  output(0,100," yMin is equal to the current scan line being processed.");
  glutSwapBuffers();
}




int ev1,ev2,ev3;
static int ch=0;
int outer2=0;
int outer5=0;
void *currentfont;
int row=-1;         //For linked list
int col=0;          //For linked list
int inc_y=-50;       //For linked list
int rear=-1;

class button //button class
{
	int x1,y1,x2,y2;
	int state;
	char str[10];

public:
	button()        //create box buttons
	{

	}
	button(int x11,int y11,int x22,int y22,char *str1)
	{
		x1=x11;
		y1=y11;
		x2=x22;
		y2=y22;
		state=1;
		strcpy(str,str1);

	}
	void draw();
	void togglestate();
	int insidebutton(int x,int y);
};
class stack  //stack class
{
   button s[size];
   int top;

public:
   stack()
   {
	   top=-1;
   }
   int stfull();
   button pop();
   void push(int item);
   int stempty();
   void displaystack();
};
stack st,st1;


class linkedList //linked list class for displaying intersecting edges
{
int matrix[30][30];
button que[MAX];
int front;

public:
linkedList()
{
	front=-1;
}

void displaylinkedList();
void insert_element(int ch);
void delete_element();
};

linkedList q;

void setFont(void *font)
{
	currentfont=font;
}
void drawstring(float x,float y,char *string)
{
	    char *c;
	glRasterPos2f(x,y);

	for(c=string;*c!='\0';c++)
	{	glColor3f(0.0,0.0,0.0);
		glutBitmapCharacter(currentfont,*c);
	}
}
void button::draw()
{

    if(box1==1)
    {
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,250);
    glVertex2f(193,300);
    glVertex2f(210,250);
    glVertex2f(210,300);
    glEnd();
    }
       if(box2==2)
    {
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,250);
    glVertex2f(273,300);
    glVertex2f(289,250);
    glVertex2f(289,300);
    glEnd();
    }
    if(box3==3)
    {
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,400);
    glVertex2f(193,450);
    glVertex2f(210,400);
    glVertex2f(210,450);
    glEnd();
    }

	setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
	glEnd();
	if(state==0)
	{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glEnd();
	}
	else if(state==1)
	{
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex2f(x1,y1);
		glVertex2f(x1,y2);
		glVertex2f(x1,y2);
		glVertex2f(x2,y2);
		glEnd();
	}
}
void button::togglestate(void)
{
	/*if(state==1)
		state=0;
	else if(state==0)
		state=1;*/
	state=(state==1)?0:1;
}
int button::insidebutton(int x,int y)
{
	if(x>x1&&x<x2&&y>y1&&y<y2)
		return 1;
	else return 0;
}
button btn1(100,50,175,100,"Push");
button btn2(200,50,275,100,"Pop");
button btn3(300,50,375,100,"Insert");
button btn4(400,50,475,100,"Delete");

int stack::stfull() {       // Stack functions start
   if (st.top >= size-1)
      return 1;
   else
      return 0;
}

void stack::push(int item)
{                      //push function to push y values for bucket edges
if(item==2)
   outer2=item;
if(item==5)
   outer5=item;
    row++;
    rear=-1;
    inc_y+=50;
    col=0;
	char str[10];
	if(item==0)
	snprintf(str, sizeof(str), "X", item);
    if(item==1)
    snprintf(str, sizeof(str), "%d---->", item);
    if(item==2)
    snprintf(str, sizeof(str), "X", item);
    if(item==3)
    snprintf(str, sizeof(str), "X", item);
    if(item==4)
    snprintf(str, sizeof(str), "%d---->", item);
    if(item==5)
    snprintf(str, sizeof(str), "X", item);
    if(item==6)


    snprintf(str, sizeof(str), "%d---->X", item);

    button btn(100,250+st.top*50,150,300+st.top*50,str);
    st.top++;
    st.s[st.top] = btn;

}

int stack::stempty() {
   if (st.top == -1)
      return 1;
   else
      return 0;
}

button stack::pop() {
   // row--;
   button item;
   item = st.s[st.top];
   st.top--;

   return (item);
}

void stack::displaystack() {
   int i;
   if (st.stempty())
   {
       //glColor3d(1,0,0);
      //drawstring(10,10,"Stack Is Empty!");
   }
   else {
      for (i = st.top; i >= 0; i--)
    	  st.s[i].draw();
   }

}

//stack functions end
//linkedList function starts
void linkedList::insert_element(int ch)
{
  static int num=0;
  char str[10];

if(ch==0)
{
    snprintf(str, sizeof(str),"4 4 -1->");
  	ev1=1;
}
else if(ch==1)
 {
        snprintf(str, sizeof(str), "6 4 0->");
    	ev2=2;
 }
else
  {
   snprintf(str, sizeof(str), "6 2 1->");
   ev3=3;
}    //for(int i=0;i<=inc_y;i+=50)
     button btn(250+rear*80,200+inc_y,310+rear*80,250+inc_y,str);

  if(front==0 && rear==MAX-1)
    {
        //drawstring(10,10," linkedList OverFlow Occured");
        }
  else if(front==-1&&rear==-1)
  {
      front=rear=0;
      que[rear]=btn;

  }
  else if(rear==MAX-1 && front!=0)
  {
    rear=0;
    que[rear]=btn;
  }
  else
  {
      rear++;
      que[rear]=btn;
  }

}
void linkedList::displaylinkedList()
{
  /*  for(int i=0;i<5;i++)
{

    for(int j=0;j<5;j++)
    {
        matrix[i][j]=1;
    }
}*/
    int i;
    if(front==-1)
      drawstring(300,10," No elements to display in linkedList");
    else
    {
                             //     printf("\n The linkedList elements are:\n ");
      for(i=front;i<=rear;i++)
      {
        que[i].draw();

      }
    }

}
void edgevalue1()  //to display bucket edges values eg ab,cd etc
{
    glColor3d(1,0,0);
    drawstring(190,225,"CA");
}

void edgevalue2()         //to display bucket edges values
{
    glColor3d(1,0,0);
     drawstring(260,225,"CB");
}

void edgevalue3()   //to display bucket edges values
{
    glColor3d(1,0,0);
     drawstring(190,380,"AB");
}

void show(void)          // display the bucket edges values after y increment
{
    int   x1=170,y1=250,x2=230,y2=300;
    char str[10];
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,250);
    glVertex2f(193,300);
    glVertex2f(210,250);
    glVertex2f(210,300);
    glEnd();

  	snprintf(str, sizeof(str), "4 4 -1->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
	glEnd();

    x1=250,y1=250,x2=310,y2=300;
    snprintf(str, sizeof(str), "6 4 0 ");
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,250);
    glVertex2f(273,300);
    glVertex2f(289,250);
    glVertex2f(289,300);
    glEnd();
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);

	glEnd();




}

void show1(void)          // display the bucket edges values after y increment
{

    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,400);
    glVertex2f(193,450);
    glVertex2f(210,400);
    glVertex2f(210,450);
    glEnd();
    int   x1=170,y1=400,x2=230,y2=450;
    char str[10];
    snprintf(str, sizeof(str), "6 2 1");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}

void displaystacknlinkedList()
{
st.displaystack();
q.displaylinkedList();
}
void sidelines1()
{


}
void display()
{

    glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);
    drawstring(100,580," Y");
      glColor3f(1.0,1.0,0.0);
    drawstring(250,20,"Bucket Edge Table");
    glColor3f(1.0,1.0,0.0);
    drawstring(70,560," Coordinates");
    glColor3f(1.0,1.0,0.0);
    drawstring(200,560," Edges");
    btn1.draw();               // push y values
   // btn2.draw();
    btn3.draw();                // push edge values
   // btn4.draw();
    displaystacknlinkedList();
     if(box1==1)
         sidelines1();
    if(outer2==2)
        show();
    if(ev1==1)
        edgevalue1();
     if(ev2==2)
        edgevalue2();
    if(outer5==5)
        show1();
     if(ev3==3)
        edgevalue3();



    glFlush();

glutSwapBuffers();
//glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)    //mouse interaction to push and display edge tables

{
    static int itemno=0;
	y=600-y;
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{
	if(btn1.insidebutton(x,y))
	{
		btn1.togglestate();
		if(!st.stfull())         //push the values
		st.push(itemno++);

	}
/*	if(btn2.insidebutton(x,y))
		{
			btn2.togglestate();
			if(!st.stempty())
					st.pop();

		}*/
	if(btn3.insidebutton(x,y))
		{
			btn3.togglestate();           //insert the edge values
			q.insert_element(ch++);
			box++;

			if(box==1)
                box1=1;
            if(box==2)
                box2=2;
            if(box==3)
                box3=3;

		}
	/*if(btn4.insidebutton(x,y))
		{
			btn4.togglestate();
		//	q.delete_element();
		}*/
	if(btn==GLUT_LEFT_BUTTON && state == GLUT_UP)
	{
		if(btn1.insidebutton(x,y))
			{
				btn1.togglestate();
			}
    if(btn2.insidebutton(x,y))
					{
						btn2.togglestate();
					}
    if(btn3.insidebutton(x,y))
					{
						btn3.togglestate();
					}
    if(btn4.insidebutton(x,y))
					{
						btn4.togglestate();
					}
	}
	glutPostRedisplay();
}

if(btn==GLUT_MIDDLE_BUTTON && state == GLUT_DOWN)
	{
	fillcount++;
if(fillcount==1)
    fp=1;
    if(fillcount==2)
    sp=2;
      if(fillcount==4)
        sl2=4;
    if(fillcount==3)
    tp=3;
      if(fillcount==5)
    ffp=5;
      if(fillcount==6)
    fffp=6;
      if(fillcount==7)
    sl3=7;
         if(fillcount==8)
    ep=8;
      if(fillcount==9)
    np=9;
          if(fillcount==10)
    sl4=10;
          if(fillcount==11)
    eep=11;
          if(fillcount==12)
    twp=12;
          if(fillcount==13)
  sl5=13;
          if(fillcount==14)
  ftp=14;

   }



}

void init()            //initialization
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,600,0,600);
	//glMatrixMode(GL_MODELVIEW);
}

void idle()
{
	glutPostRedisplay();
}



// code to display a simple polygon triangle code starts here
float x1,x2,x3,x4,y1,y2,y3,y4;
int fillFlag=0;
void edgedetect(float x1,float y1,float x2,float y2,int *le,int *re)
{
float mx,x,temp;
int i;
if((y2-y1)<0)
{
temp=y1;y1=y2;y2=temp;
temp=x1;x1=x2;x2=temp;
}
if((y2-y1)!=0)
mx=(x2-x1)/(y2-y1);
else
mx=x2-x1;
x=x1;
for(i=y1;i<=y2;i++)
{
if(x<(float)le[i])
le[i]=(int)x;
if(x>(float)re[i])
re[i]=(int)x;
x+=mx;
}
}
void draw_pixel(int x,int y)
{
glColor3f(1.0,1.0,0.0);
glBegin(GL_POINTS);
glVertex2i(x,y);
glEnd();

}
void scanfill(float x1,float y1,float x2,float y2,float x3,float y3,float x4,float y4)
{
int le[500],re[500];
int i,y;
for(i=0;i<500;i++)
{
le[i]=500;
re[i]=0;
}
edgedetect(x1,y1,x2,y2,le,re);
edgedetect(x2,y2,x3,y3,le,re);
edgedetect(x3,y3,x1,y1,le,re);
//edgedetect(x4,y4,x1,y1,le,re);
for(y=0;y<500;y++)
{
for(i=(int)le[y];i<(int)re[y];i++)
draw_pixel(i,y);
}
}
void display3()
{
glDisable(GL_DEPTH_TEST);
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);

x1=250.0;y1=250.0;x2=140.0;y2=360.0;x3=250.0;y3=450.0;

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
//glVertex2f(x4,y4);
glEnd();
 glBegin(GL_LINE_LOOP);
 glColor3d(1,0,0);
 glVertex2f(50,550);
  glVertex2f(50,200);
 glEnd();

 glBegin(GL_LINE_LOOP);
 glVertex2f(50,200);
 glVertex2f(450,200);
 glEnd();



glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,360);
glVertex2f(60,360);//1st y point
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,320);
glVertex2f(60,320);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,280);
glVertex2f(60,280);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,240);
glVertex2f(60,240);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,400);
glVertex2f(60,400);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,450);
glVertex2f(60,450);
glEnd();

glColor3d(0,1,0);
output(45, 180,"0");
output(90, 160,"1");
output(140, 160,"2");
output(190, 160,"3");
output(240, 160,"4");
output(290, 160,"5");
output(340, 160,"6");

output(25, 240,"1");
output(25, 280,"2");
output(25, 320,"3");
output(25, 360,"4");
output(25, 400,"5");
output(25, 440,"6");
output(25, 550,"Y");
output(450, 165,"X");
glBegin(GL_LINES);
//glVertex2f()


glEnd();




glColor3f(1.0,0.0,0.0);
output(250, 460,"B");
glColor3f(0.0,1.0,0.0);
output(260, 440,"(4,6)");
glColor3f(1.0,0.0,0.0);

output(250, 230,"C");
glColor3f(0.0,1.0,0.0);
output(270, 240,"(4,1)");
glColor3f(1.0,0.0,0.0);

output(140, 330,"A");
glColor3f(0.0,1.0,0.0);
output(100, 350,"(2,4)");

glBegin(GL_LINES);
glColor3d(1,0,0);

glVertex2f(100,200);
glVertex2f(100,180);

glVertex2f(150,200);
glVertex2f(150,180);

glVertex2f(200,200);
glVertex2f(200,180);

glVertex2f(250,200);
glVertex2f(250,180);

glVertex2f(300,200);
glVertex2f(300,180);

glVertex2f(350,200);
glVertex2f(350,180);


glEnd();

if(fillFlag==1)
scanfill(x1,y1,x2,y2,x3,y3,x4,y4);
glFlush();
}

/*void init()
{
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,600.0,0.0,600.0);
}

*/
//end of polygon triangle filling
void activeybox1()
{
    int x1=100,y1=200,x2=150,y2=245;
    char str[10];
  glColor3d(0,1,0);
  output(50,220,"Y=1");
  	snprintf(str, sizeof(str), " X--->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}


void activebox1()
{
    int x1=170,y1=198,x2=230,y2=240;
    char str[10];


  	snprintf(str, sizeof(str), "4 4 -1->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,197);
    glVertex2f(193,240);
    glVertex2f(210,197);
    glVertex2f(210,240);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);

    glEnd();

}
void activebox2()
{

 char str[10];
   int x1=250,y1=198,x2=310,y2=240;

    snprintf(str, sizeof(str), "6 4 0");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
     glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,197);
    glVertex2f(273,240);
    glVertex2f(290,197);
    glVertex2f(290,240);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}
void activeybox2()
{
    int x1=100,y1=250,x2=150,y2=295;
    char str[10];
    glColor3d(0,1,0);
    output(50,260,"Y=2");

  	snprintf(str, sizeof(str), "X---->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();


}

void activebox3()
{
    int x1=170,y1=248,x2=245,y2=290;
    char str[10];


  	snprintf(str, sizeof(str),"4 3.3 -1");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,247);
    glVertex2f(193,290);
    glVertex2f(223,247);
    glVertex2f(223,290);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
}
void activebox4()
{

 char str[10];
   int x1=270,y1=248,x2=330,y2=290;

    snprintf(str, sizeof(str), "6 4 0");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(293,247);
    glVertex2f(293,290);
    glVertex2f(310,247);
    glVertex2f(310,290);

    glVertex2f(225,265);
    glVertex2f(270,265);

    glVertex2f(270,265);
    glVertex2f(260,275);

    glVertex2f(270,265);
    glVertex2f(260,255);

    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}
////////////////////////////////////////////////////////////////
void activeybox3()
{
    int x1=100,y1=300,x2=150,y2=345;
    char str[10];
  glColor3d(0,1,0);
  output(50,310,"Y=3");

  	snprintf(str, sizeof(str), "X---->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();



}
void activebox5()
{
    int x1=170,y1=298,x2=245,y2=340;
    char str[10];


  	snprintf(str, sizeof(str), "4 2.6 -1");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,297);
    glVertex2f(193,340);
    glVertex2f(223,297);
    glVertex2f(223,340);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
}
activebox6()
{

 char str[10];
   int x1=270,y1=298,x2=330,y2=340;

    snprintf(str, sizeof(str), "6 4 0");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(293,297);
    glVertex2f(293,340);
    glVertex2f(310,297);
    glVertex2f(310,340);


    glVertex2f(243,315);
    glVertex2f(270,315);

    glVertex2f(270,315);
    glVertex2f(255,325);

    glVertex2f(270,315);
    glVertex2f(255,300);




    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);



    glEnd();

}
//////////////////

void activeybox4()
{
    int x1=100,y1=350,x2=150,y2=395;
    char str[10];
  glColor3d(0,1,0);
  output(50,370,"Y=4");

  	snprintf(str, sizeof(str), "X---->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();



}
void activebox7()
{
    int x1=170,y1=348,x2=230,y2=390;
    char str[10];


  	snprintf(str, sizeof(str), "6 2 1  ->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,347);
    glVertex2f(193,390);
    glVertex2f(210,347);
    glVertex2f(210,390);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
}
void activebox8()
{
   char str[10];
   int x1=250,y1=348,x2=310,y2=390;

   snprintf(str, sizeof(str), "6 4 0");
   setFont(GLUT_BITMAP_HELVETICA_18);
   glColor3f(1.0,1.0,1.0);
   drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,347);
    glVertex2f(273,390);
    glVertex2f(290,347);
    glVertex2f(290,390);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}

void activeybox5()
{
    int x1=100,y1=400,x2=150,y2=440;
    char str[10];
        glColor3d(0,1,0);
  output(50,420,"Y=5");

  	snprintf(str, sizeof(str), "X---->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();



}

void activebox9()
{
    int x1=170,y1=398,x2=230,y2=440;
    char str[10];


  	snprintf(str, sizeof(str), "6 3 1  ->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,397);
    glVertex2f(193,440);
    glVertex2f(210,397);
    glVertex2f(210,440);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
}

void activebox10()
{

   char str[10];
   int x1=250,y1=398,x2=310,y2=440;

   snprintf(str, sizeof(str), "6 4 0");
   setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
       glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,397);
    glVertex2f(273,440);
    glVertex2f(290,397);
    glVertex2f(290,440);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}

void activeybox6()
{
    int x1=100,y1=450,x2=150,y2=495;
    char str[10];
    glColor3d(0,1,0);
    output(50,470,"Y=6");

  	snprintf(str, sizeof(str), "X---->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();



}
void activebox11()
{
    int x1=170,y1=448,x2=230,y2=490;
    char str[10];


  	snprintf(str, sizeof(str), "6 3 1  ->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
          glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(193,447);
    glVertex2f(193,490);
    glVertex2f(210,447);
    glVertex2f(210,490);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
}
void activebox12()
{

 char str[10];
   int x1=250,y1=448,x2=310,y2=490;

    snprintf(str, sizeof(str), "6 4 0");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(273,447);
    glVertex2f(273,490);
    glVertex2f(290,447);
    glVertex2f(290,490);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

}
void scanline()
{
glDisable(GL_DEPTH_TEST);
glClearColor(0.0,0.0,0.0,0.0);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);

x1=250.0;y1=250.0;x2=140.0;y2=360.0;x3=250.0;y3=450.0;

glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 1.0);
glBegin(GL_LINE_LOOP);
glVertex2f(x1,y1);
glVertex2f(x2,y2);
glVertex2f(x3,y3);
//glVertex2f(x4,y4);
glEnd();
 glBegin(GL_LINE_LOOP);
 glColor3d(1,0,0);
 glVertex2f(50,550);
  glVertex2f(50,200);
 glEnd();

 glBegin(GL_LINE_LOOP);
 glVertex2f(50,200);
 glVertex2f(450,200);
 glEnd();

//scanlineszssss
glBegin(GL_LINES);
glVertex2f(100,200);
glVertex2f(100,180);

glVertex2f(150,200);
glVertex2f(150,180);

glVertex2f(200,200);
glVertex2f(200,180);

glVertex2f(250,200);
glVertex2f(250,180);

glVertex2f(300,200);
glVertex2f(300,180);

glVertex2f(350,200);
glVertex2f(350,180);

glColor3d(1,1,0);
if(sl2==4)
{


glVertex2f(215,285);
glVertex2f(250,285);
}
if(sl3==7)
{
glVertex2f(180,320);
glVertex2f(250,320);
}
if(sl4==10)
{


glVertex2f(140,360);
glVertex2f(250,360);
}
if(sl5==13)
{


glVertex2f(190,400);
glVertex2f(250,400);
}

glEnd();


glPointSize(5);
glBegin(GL_POINTS);
glColor3d(1,1,0);
if(fp==1){

glVertex2f(250,250);//1stleftright


}
if(sp==2)
glVertex2f(215,285);//2ndleft
if(tp==3)
glVertex2f(250,285);//2ndright
if(ffp==5)
glVertex2f(180,320);//3rdleft
if(fffp==6)
glVertex2f(250,320);//3rd right
if(ep==8)
glVertex2f(140,360);//4thleft
if(np==9)
glVertex2f(250,360);//4thright
if(eep==11)
glVertex2f(190,400);//5thleft
if(twp==12)
glVertex2f(250,400);//5thrighy
if(ftp==14)
glVertex2f(250,450);//6thleftrighy
glEnd();


glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,360);
glVertex2f(60,360);//1st y point
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,320);
glVertex2f(60,320);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,280);
glVertex2f(60,280);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,240);
glVertex2f(60,240);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,400);
glVertex2f(60,400);
glEnd();

glBegin(GL_LINE_LOOP);
glColor3d(1,0,0);
glVertex2f(40,450);
glVertex2f(60,450);
glEnd();

glColor3d(0,1,0);
output(45, 180,"0");
output(90, 160,"1");
output(140, 160,"2");
output(190, 160,"3");
output(240, 160,"4");
output(290, 160,"5");
output(340, 160,"6");

output(25, 240,"1");
output(25, 280,"2");
output(25, 320,"3");
output(25, 360,"4");
output(25, 400,"5");
output(25, 440,"6");
output(25, 550,"Y");
output(450, 165,"X");
glBegin(GL_LINES);
//glVertex2f()


glEnd();




glColor3f(1.0,0.0,0.0);
output(250, 460,"B");
glColor3f(0.0,1.0,0.0);

glColor3f(1.0,0.0,0.0);

output(250, 230,"C");
glColor3f(0.0,1.0,0.0);
if(fp==1)
output(270, 240,"(4,1)");
glColor3f(1.0,0.0,0.0);

output(140, 330,"A");
glColor3f(0.0,1.0,0.0);

if(sp==2)
output(160, 270,"(3.3,2)");
if(tp==3)
output(260, 280,"(4,2)");
if(ffp==5)
output(120, 310,"(2.6,3)");
if(fffp==6)
output(260, 320,"(4,3)");
if(ep==8)
output(100, 350,"(2,4)");
if(np==9)
output(260, 350,"(4,4)");
if(eep==11)
output(150, 400,"(3,5)");
if(twp==12)
output(260, 400,"(4,5)");
if(ftp==14)
output(260, 440,"(4,6)");

glutSwapBuffers();
}


void activated()
{
    glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
    glColor3f( 1.0, 0.0,0.0);

    output(100,520,"Y");
    output(60,500,"Coordinates");
    output(220,520,"Active Edges ");
    output(160, 140, "PRESS P TO PUSH THE Y VALUES");
    output(140, 120, "PRESS I TO INSERT THE ACTIVE EDGES");
    glColor3d(0,1,0);
    output(200, 50,  "ACTIVE EDGE TABLE");

    if(ay1==1)
    {
    activeybox1();
    }
    if(sy1==1)
    {
    activebox1();
    }
     if(sy2==2)
    {
    activebox2();
    glColor3d(1,0,0);
    output(350, 220, "FIRST PAIR (4,1),(4,1)");
    }
    if(ay2==2)
    {
    activeybox2();
    }
    if(sy3==3)
    {
    activebox3();

    }
     if(sy4==4)
    {
    activebox4();
      glColor3d(1,0,0);
    output(350, 260, "SECOND PAIR (3.3,2),(4,2)");
    }
    if(ay3==3)
    {
    activeybox3();
    }
    if(sy5==5)
    {
    activebox5();
    }
     if(sy6==6)
    {
    activebox6();
      glColor3d(1,0,0);
    output(350, 320, "THIRD PAIR (2.6,3),(4,3)");
    }
       if(ay4==4)
    {
    activeybox4();
    }
    if(sy7==7)
    {
    activebox7();
    }
     if(sy8==8)
    {
    activebox8();
      glColor3d(1,0,0);
    output(350, 360, "FOURTH PAIR (2,4),(4,4)");
    }
    if(ay5==5)
    {
    activeybox5();
    }
    if(sy9==9)
    {
    activebox9();
    }
    if(sy10==10)
    {
    activebox10();
      glColor3d(1,0,0);
    output(350, 420, "FIFTH PAIR (3,5),(4,5)");
    }
     if(ay6==6)
    {
    activeybox6();
    }
    if(sy11==11)
    {
    activebox11();
    }
    if(sy12==12)
    {
    activebox12();
      glColor3d(1,0,0);
    output(350, 460, "SIXTH PAIR (4,6),(4,6)");
    }

  glFlush();
  glutSwapBuffers();
}

void thankyou()
{
    glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glColor3d(1,0,0);
    output(250,350 , "THANK YOU");
    glutSwapBuffers();
}


void keyboard(unsigned char key,int x,int y)
{
if(key=='p' || key=='P')
{

    ay++;
    if(ay==1)
        ay1=1;
    if(ay==2)
        ay2=2;
    if(ay==3)
        ay3=3;
    if(ay==4)
        ay4=4;
    if(ay==5)
        ay5=5;
    if(ay==6)
        ay6=6;
}
if(key=='i' || key=='I')
{

   sy++;
   if(sy==1)
    sy1=1;
   if(sy==2)
    sy2=2;
   if(sy==3)
    sy3=3;
   if(sy==4)
    sy4=4;
     if(sy==5)
    sy5=5;
     if(sy==6)
    sy6=6;
     if(sy==7)
    sy7=7;
     if(sy==8)
    sy8=8;
     if(sy==9)
    sy9=9;
     if(sy==10)
    sy10=10;
     if(sy==11)
    sy11=11;
     if(sy==12)
    sy12=12;
}

}

void introduction2()
{
    glEnable(GL_DEPTH_TEST);
	glClearColor(0.0,0.0,0.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glColor3d(1,0,0);
	output(250, 550,"Global Edge Table");
	glColor3d(1,1,0);
    output(10, 520,"Edges are bucket sorted in the Global Edge Table according to their");
    output(10, 500,"minimum Y");
    glColor3d(0,0,1);
    output(240, 460,"TEMPLATE");
    int   x1=170,y1=448,x2=230,y2=490;
    char str[10];
    glColor3d(1,0,0);
	output(230, 240,"Active Edge Table");
	glColor3d(1,1,0);
    output(10, 200,"Active edges are sorted according to increasing X.Template is ");
    output(5, 180," same as that of global edge table. It maintains the information ");
    output(5, 160," of the edges that are active to particular scanline");


    glBegin(GL_LINES);
    glColor3d(1,0,0);
    glVertex2f(280,365);
    glVertex2f(280,300);

    glVertex2f(200,375);
    glVertex2f(255,375);


    glVertex2f(330,375);
    glVertex2f(380,375);

    glVertex2f(300,375);
    glVertex2f(340,410);
    glEnd();
    glColor3d(0,1,0);
    output(270, 280,"Xmin");
    output(150, 375,"Ymax");

    output(350, 410,"slope(1/m)");
    output(390, 370,"Link");
    x1=250,y1=358,x2=310,y2=400;
    snprintf(str, sizeof(str), "6 4 0--> ");
        glColor3d(1,1,1);
    glBegin(GL_LINES);
    glVertex2f(275,358);
    glVertex2f(275,400);
    glVertex2f(290,358);
    glVertex2f(290,400);
    glEnd();
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
	glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();


    x1=250,y1=60,x2=310,y2=110;


  	snprintf(str, sizeof(str), "4 4 -1->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);
    glBegin(GL_LINES);
    glColor3d(1,1,1);
    glVertex2f(275,60);
    glVertex2f(275,110);
    glVertex2f(290,60);
    glVertex2f(290,110);
    glEnd();
    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();

    x1=180,y1=60,x2=220,y2=110;


  	snprintf(str, sizeof(str), " X--->");
    setFont(GLUT_BITMAP_HELVETICA_18);
	glColor3f(1.0,1.0,1.0);
    drawstring(x1+10,y1+10,str);

    glColor3f(0.2,0.2,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(x1,y1);
	glVertex2f(x2,y1);
	glVertex2f(x2,y2);
	glVertex2f(x1,y2);
    glEnd();
    glColor3d(0,1,0);
    output(40,70,"AET Pointer");

    glBegin(GL_LINES);
    glVertex2f(150,80);
    glVertex2f(180,80);

    glEnd();

    glBegin(GL_LINES);


    glVertex2f(300,30);
    glVertex2f(300,60);

     glVertex2f(260,30);
    glVertex2f(260,60);

     glVertex2f(280,130);
    glVertex2f(280,100);

    glEnd();
      output(240,20,"ymax");
        output(300,20,"slope");
          output(330,70,"link");
                output(275,130,"x");
    glFlush();
    glutSwapBuffers();

}
void fillMenu(int option)    //menu interaction
{
if(option==8)
fillFlag=1;

if(option==9)
fillFlag=2;
display3();

if(option==1)
glutDisplayFunc(display1);

if(option==2)
glutDisplayFunc(introduction);

if(option==3)
glutDisplayFunc(display3);

if(option==4)
glutDisplayFunc(display);

if(option==7)
glutDisplayFunc(activated);

if(option==10)
glutDisplayFunc(scanline);

if(option==11)
glutDisplayFunc(thankyou);

if(option==12)
glutDisplayFunc(introduction2);

if(option==0)
exit(0);
}

void createMenu(void)
{
    menu_id = glutCreateMenu(fillMenu);
    glutAddMenuEntry("HOME PAGE", 1);
    glutAddMenuEntry("INTRODUCTION1",2);
    glutAddMenuEntry("INTRODUCTION2",12);
    glutAddMenuEntry("SCANELINE_POLYGON",3);
    glutAddMenuEntry("Fill Polygon",8);
    glutAddMenuEntry("Empty Polygon",9);
    glutAddMenuEntry("BUCKET EDGE TABLE", 4);
    glutAddMenuEntry("ACTIVE EDGE TABLE", 7);
    glutAddMenuEntry("SCANLINES ", 10);
    glutAddMenuEntry("THANK YOU ", 11);
    glutAddMenuEntry("EXIT", 0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}
int main(int argc, char* argv[])
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(600,600);
glutInitWindowPosition(500,100);
glutCreateWindow("Scan-line polygon filling Algorithm");
init();
glutDisplayFunc(display1);
glutKeyboardFunc(keyboard);
glutMouseFunc(mouse);
glutIdleFunc(idle);
createMenu();
glutMainLoop();
}
