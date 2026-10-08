#include <windows.h>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<cmath>
#include<map>
#include<ctime>
#include<stdio.h>
#include<random>
#include<thread>
#include<vector>
#include<stdexcept>
#include <unistd.h>
#include<bits/stdc++.h>
#define CAMEL_change (WM_USER + 1)
using namespace std;
int timenumber(int a);
int xx=1,yy=1;

int n=1;
HWND w9,win36,wmain;
WNDCLASSEX wc1;
static HWND     hwndButton[1010][1010];
int a[1010][1010];
bool ab[1010][1010];
int cx,cy;
LRESULT CALLBACK w9cproc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam);
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM, LPARAM);
extern "C"
{
	int WINAPI MessageBoxTimeoutA(IN HWND hWnd,IN LPCSTR lpText,IN LPCSTR lpCaption,IN UINT uType,IN WORD wLanguageId,IN DWORD dwMilliseconds);
	int WINAPI MessageBoxTimeoutW(IN HWND hWnd,IN LPCWSTR lpText,IN LPCWSTR lpCaption,IN UINT uType,IN WORD wLanguageId,IN DWORD dwMilliseconds);
}
#ifdef UNICODE
#define MessageBoxTimeout MessageBoxTimeoutW
#else
#define MessageBoxTimeout MessageBoxTimeoutA
#endif
int t=0;
HWND w9c;
int p(int x,int y)
{
	if(a[x][y]==0||ab[x][y]==false)
	{
		
		cout<<x<<","<<y<<"为0";
		return 0;
	}
	for(int i=1;i<x;i++)
	{
		if(a[x][y]==a[i][y])
		{
			cout<<x<<","<<y<<"与"<<i<<","<<y<<"冲突";
			return 0;

		}
	}
	for(int i=1;i<y;i++)
	{
		if(a[x][y]==a[x][i])
		{
			cout<<x<<","<<y<<"与"<<x<<","<<i<<"冲突";
			return 0;
		}
	}



	for(int i=1;i<=9;i+=3)
	{
		for(int j=1;j<=9;j+=3)
		{
			if(x>=i&&x<i+3)
			{
				if(y>=j&&y<j+3)
				{
					for(int k=0;k<3;k++)
					{
						for(int w=0;w<3;w++)
						{
							if(a[i+k][j+w]==a[x][y]&&(i+k)!=x&&(j+w)!=y)
							{
								cout<<x<<","<<y<<"与"<<i+k<<","<<y+w<<"冲突";
								return 0;
							}
						}
					}
				}
			}
		}
	}
	return 1;

}
int set1(int x,int y)
{

	a[x][y]=0;
	int d=0;
	int e=1+rand();
	e+=t;
	if(e<=0)
	{
		e=0-e;
	}
	d=e%9+t;
	d%=9;
	d+=1;
	if(d<=0)
	{
		d=0-d;
	}
	if(d==0)
	{
		d++;
	}
	int t3=1;
b:
	bool t2=true;
	for(int i=x;i>=1;i--)
	{
		if(a[i][y]==d)
		{
			t2=false;
			MessageBoxTimeout(w9,"错误","Message",MB_OK|MB_ICONERROR,0,1);
			cout<<"列错误";
			goto a;
		}
	}
	for(int i=y;i>=1;i--)
	{
		if(a[x][i]==d)
		{
			MessageBoxTimeout(w9,"错误","Message",MB_OK|MB_ICONERROR,0,1);
			cout<<"行错误";
			t2=false;
			goto a;
		}
	}

	for(int i=1;i<=9;i+=3)
	{
		for(int j=1;j<=9;j+=3)
		{
			if(x>=i&&x<i+3)
			{
				if(y>=j&&y<j+3)
				{
					for(int k=0;k<3;k++)
					{
						for(int w=0;w<3;w++)
						{
							if(a[i+k][j+w]==d)
							{
								cout<<"9*9错误";
								MessageBoxTimeout(w9,"错误","Message",MB_OK|MB_ICONERROR,0,1);//这是必须存在的，目的是使Windows不将程序认定为未响应
								goto a;
							}
						}
					}
				}
			}
		}
	}

	goto c;
a:
	d+=1;
	if(d==10)
	{
		d=1;
	}
	t3++;
	if(t3==11)
	{
		return -1;
	}
	goto b;

c:
	a[x][y]=d;


	//下一项部分
	if(x<9)
	{
		int a2=set1(x+1,y);
		if(a2==-1)
		{
			//	MessageBox(NULL,"返回上一项","Message",MB_OK|MB_ICONERROR);
			goto a;
		}
	}
	else
	{
		if(y!=9)
		{
			int a2=set1(1,y+1);
			if(a2==-1)
			{
				goto a;
			}
		}
		else
		{
			return 0;
		}
	}


}



int timenumber(int a)
{
//	tt1=1;
	while(1)
	{
		t+=1;
	}
	return 0;
}
LRESULT CALLBACK childproc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc;
	HWND hwnd, hwndDT,hwnd1;
	MSG msg;
	RECT rect;
	int dtWidth,dtHeight;
	thread t2(timenumber,1);// 创建线程，传递函数指针和参数
	//	t1.join();// 等待线程完成
	t2.detach();//独立线程
	memset(&wc,0,sizeof(wc));
	wc.cbSize		=sizeof(WNDCLASSEX);
	wc.lpfnWndProc	=WndProc;
	wc.hInstance	=hInstance;
	wc.hCursor		=LoadCursor(NULL, IDC_ARROW);

	wc.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName="WindowClass";
	wc.hIcon		=LoadIcon(NULL, IDI_APPLICATION);
	wc.hIconSm		=LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwndDT=GetDesktopWindow();//取桌面句柄
	GetWindowRect(hwndDT,&rect);//取桌面范围
	dtWidth=rect.right-rect.left;//桌面宽度
	dtHeight=rect.bottom-rect.top;//桌面高度

	hwnd=CreateWindowEx(WS_EX_CLIENTEDGE,wc.lpszClassName,
						  "c1a2m3e4l5",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
						  100,   /*窗体居中*/
						  100,
						  640,
						  480,
						  NULL,NULL,hInstance,NULL);
	MoveWindow(hwnd, 50,50, 640, 480, TRUE);
	ShowWindow(hwnd, nCmdShow);// 显示窗口
	UpdateWindow(hwnd);// 强制重绘窗口

	if(hwnd==NULL)
	{
		MessageBox(NULL, "Window Creation Failed!","Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	WNDCLASSEX wc1;
	memset(&wc1,0,sizeof(wc1));
	wc1.cbSize		=sizeof(WNDCLASSEX);
	wc1.lpfnWndProc	=childproc;
	wc1.hInstance	=hInstance;
	wc1.hCursor		=LoadCursor(NULL, IDC_ARROW);

	wc1.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wc1.lpszClassName="WindowClass1";
	wc1.hIcon		=LoadIcon(NULL, IDI_APPLICATION);
	wc1.hIconSm		=LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc1))
	{
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwndDT=GetDesktopWindow();//取桌面句柄
	GetWindowRect(hwndDT,&rect);//取桌面范围
	dtWidth=rect.right-rect.left;//桌面宽度
	dtHeight=rect.bottom-rect.top;//桌面高度


	hwnd1=CreateWindowEx(WS_EX_CLIENTEDGE,wc1.lpszClassName,
						   "数独9*9",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
						   0,
						   0,
						   0,
						   0,
						   hwnd,NULL,hInstance,NULL);

	ShowWindow(hwnd1, SW_HIDE);


	WNDCLASSEX wc2;
	memset(&wc2,0,sizeof(wc2));
	wc2.cbSize		=sizeof(WNDCLASSEX);
	wc2.lpfnWndProc	=w9cproc;
	wc2.hInstance	=hInstance;
	wc2.hCursor		=LoadCursor(NULL, IDC_ARROW);

	wc2.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);
	wc2.lpszClassName="WindowClass2";
	wc2.hIcon		=LoadIcon(NULL, IDI_APPLICATION);
	wc2.hIconSm		=LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc2))
	{
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}

	hwndDT=GetDesktopWindow();//取桌面句柄
	GetWindowRect(hwndDT,&rect);//取桌面范围
	dtWidth=rect.right-rect.left;//桌面宽度
	dtHeight=rect.bottom-rect.top;//桌面高度


	HWND hwnd2=CreateWindowEx(WS_EX_CLIENTEDGE,wc2.lpszClassName,
								"控制界面",WS_VISIBLE|WS_OVERLAPPEDWINDOW,
								0,
								0,
								0,
								0,
								hwnd,NULL,hInstance,NULL);

	ShowWindow(hwnd2, SW_HIDE);



	w9=hwnd1;
	wmain=hwnd;
	w9c=hwnd2;
	if(hwnd1==NULL)
	{
		MessageBox(NULL, "Window Creation Failed!","Error!", MB_ICONEXCLAMATION|MB_OK);
		return 0;
	}




	while(GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	HDC         	hdc;
	PAINTSTRUCT 	ps;
	RECT			rect;
	POINT			mouse;
	static int  	cxChar, cyChar;
	static int  	mX, mY;
	static HWND 	hwndButton1;
	static HWND 	hwndEditbox;
	static HWND     hwndButton2;
	static HWND     hwndButton3;
	HWND hwnd1;
	string			strXy;
	char			x[5], y[5];
	char			buff[4096]={0};
	const int		IDcmdButton1=1;
	const int		IDcmdButton2=3;
	const int		IDcmdButton3=4;
	const int		IDeditBox=2;

	cxChar=LOWORD(GetDialogBaseUnits());
	cyChar=HIWORD(GetDialogBaseUnits());

	switch (message)
	{

		case WM_CREATE:
		{

			hwndButton1=CreateWindow ( TEXT("button"), TEXT("9*9"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 cxChar * 2, cyChar * 15,
										 10 * cxChar, 2.5 * cyChar,
										 hwnd, (HMENU)IDcmdButton1, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton1)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton1,SW_SHOW);
			UpdateWindow(hwndButton1);
			/*
									hwndEditbox=CreateWindow( TEXT("edit"),NULL,
																WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
																cxChar * 5, cyChar * 0.5,
																30 * cxChar, 9.5 * cyChar,
																hwnd,(HMENU)IDeditBox,NULL,NULL);

									if (!hwndEditbox)
									{
										MessageBox(NULL,"创建文本框失败","Message",MB_OK|MB_ICONERROR);
									}

									ShowWindow(hwndEditbox,SW_SHOW);
									UpdateWindow(hwndEditbox);
						*/
			return 0 ;
		}
		/*
				case WM_PAINT:
				{
					hdc=BeginPaint (hwnd, &ps);
					SetRect(&rect, 10, 10, 300, 200);
					FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
					GetClientRect (hwnd, &rect);
					rect.left +=20;
					rect.top +=2;
					//SetTextColor(hdc, RGB(255,0,0));//可以用RGB三原色设置文本颜色
					DrawText(hdc, TEXT(" Hello, Dev-C++! "), -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
					EndPaint(hwnd, &ps);
					return 0;
				}
		*/
		case WM_SIZE:
		{

			//GetWindowRect(hwnd, &rect);
			//MoveWindow(hwndButton, (rect.right-rect.left)/2 - 15*cxChar ,\
			//(rect.bottom-rect.top)/2 - 1.25*cxChar, 30*cxChar, 2.5*cyChar, FALSE);
			return 0;
		}


		case WM_COMMAND:
		{

			//各控件的_click()事件
			switch (LOWORD(wParam))
			{
				case 0:
					PostQuitMessage(0);
					break;

				case IDcmdButton1:
					//	strXy=string(aaa(n));

					ShowWindow(w9,SW_SHOW );
					MoveWindow(w9, 50,50, 640, 480, TRUE);
					break;

				case IDcmdButton2:
					n+=1;
					break;

				case IDcmdButton3:
					n-=1;
					break;

				case IDeditBox:
					GetWindowText(hwndEditbox,buff,4096);
					break;
			}

			return 0;
		}
		case WM_LBUTTONDOWN: // WM_LBUTTONDOWN是鼠标左键按下的事件
		{

			GetCursorPos(&mouse);
			GetWindowRect(hwnd, &rect);
			mX=mouse.x-rect.left;
			mY=mouse.y-rect.top;
			itoa(mX,x,10);
			itoa(mY,y,10);
			//strXy=string(aaa(1));
			//	SetWindowText(hwndEditbox,strXy.c_str());
			//MessageBox(NULL, strXy.c_str(), "", MB_ICONASTERISK);
			return 0;
		}
		case WM_CLOSE:
		{

			if (IDYES==MessageBox(hwnd, "是否真的要退出？", "确认", MB_ICONQUESTION | MB_YESNO))
			{
				DestroyWindow(hwnd);//销毁窗口
				TerminateProcess(hwnd,0);
			}


			return 0;
		}
		//	case WM_DESTROY:
		//		ShellAbout(hwnd, "第一个窗口程序", "再见，期待您在评论区留言！", NULL);
		//		PostQuitMessage(0);
		//		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
LRESULT CALLBACK childproc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         	hdc;
	PAINTSTRUCT 	ps;
	RECT			rect;
	POINT			mouse;
	static int  	cxChar, cyChar;
	static int  	mX, mY;
	HWND 	hwndButton11;
	static HWND 	hwndEditbox;
	static HWND     hwndButton2;
	static HWND     hwndButton3;
	HWND hwnd1;
	string			strXy;
	char			x[5], y[5];
	char			buff[4096]={0};
	const int		IDcmdButton1=1;
	const int		IDcmdButton5=5;
	const int		IDcmdButton2=3;
	const int		IDcmdButton3=4;
	const int		IDeditBox=2;
	int d=0;
	cxChar=LOWORD(GetDialogBaseUnits());
	cyChar=HIWORD(GetDialogBaseUnits());
	/*
	HFONT setting=CreateFont(
	                  30,          // 字体高度
	                  15,           // 字体宽度
	                  0,           // 倾斜角度
	                  0,           // 基线角度
	                  FW_NORMAL,   // 字体粗细
	                  true,       // 是否加粗
	                  true,       // 是否斜体
	                  true,       // 是否下划线
	                  DEFAULT_CHARSET,
	                  OUT_OUTLINE_PRECIS,
	                  CLIP_DEFAULT_PRECIS,
	                  DEFAULT_QUALITY,
	                  DEFAULT_PITCH | FF_SWISS,
	                  "黑体"      // 字体名称
	              );
	       */
	switch (message)
	{

		case WM_CREATE:
		{


			hwndButton11=CreateWindow ( TEXT("button"), TEXT("开始"),
										  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										  50, 50,
										  50, 50,
										  hwnd, (HMENU)IDcmdButton1, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton11)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton11,SW_SHOW);
			UpdateWindow(hwndButton11);
			/*
									hwndEditbox=CreateWindow( TEXT("edit"),NULL,
																WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
																cxChar * 5, cyChar * 0.5,
																30 * cxChar, 9.5 * cyChar,
																hwnd,(HMENU)IDeditBox,NULL,NULL);

									if (!hwndEditbox)
									{
										MessageBox(NULL,"创建文本框失败","Message",MB_OK|MB_ICONERROR);
									}

									ShowWindow(hwndEditbox,SW_SHOW);
									UpdateWindow(hwndEditbox);
						*/
			goto dg;
		e:
			//ShowWindow(hwndButton1, SW_MINIMIZE);
			//MoveWindow(hwndButton11, 1000,1000,0,0,true);
			DestroyWindow(hwndButton11);
			hwndButton2=CreateWindow ( TEXT("button"), TEXT("验证"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 470, 50,
										 100, 50,
										 hwnd, (HMENU)IDcmdButton2, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton2)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton2,SW_SHOW);
			UpdateWindow(hwndButton2);
			for(int i=1;i<=9;i++)
			{
				for(int j=1;j<=9;j++)
				{
					hwndButton[i][j]=CreateWindow ( TEXT("button"), TEXT(" "),
													  WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
													  i * 40-30+(i+3-1)/3*10, j * 40-30+(j+3-1)/3*10,
													  40,40,
													  hwnd, (HMENU)IDcmdButton5, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

					if (!hwndButton[i][j])
					{
						MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);

					}

				}
			}
			//int d=0;
			set1(1,1);
			for(int i=1;i<=9;i++)
			{
				for(int j=1;j<=9;j++)
				{

					ab[i][j]=true;
					int d=0;
					int e=1+rand();
					e+=t;
					//		SendMessage(hwndButton[i][j], WM_SETFONT, (WPARAM)setting, TRUE);
					if(e<=0)
					{
						e=0-e;
					}
					d=e%9+t;
					d%=9;
					d+=1;
					if(d<=0)
					{
						d=0-d;
					}
					if(d==0)
					{
						d++;
					}

					string strXy=to_string(a[i][j]);

					if(d%3==0)
					{
						strXy=" ";
						ab[i][j]=false;
					}

					SetWindowText(hwndButton[i][j],strXy.c_str());
				}
			}
			goto eend;
		dg:
			return 0 ;
		}
		/*
				case WM_PAINT:
				{
					hdc=BeginPaint (hwnd, &ps);
					SetRect(&rect, 10, 10, 300, 200);
					FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
					GetClientRect (hwnd, &rect);
					rect.left +=20;
					rect.top +=2;
					//SetTextColor(hdc, RGB(255,0,0));//可以用RGB三原色设置文本颜色
					DrawText(hdc, TEXT(" Hello, Dev-C++! "), -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
					EndPaint(hwnd, &ps);
					return 0;
				}
		*/
		case WM_SIZE:
		{

			//GetWindowRect(hwnd, &rect);
			//MoveWindow(hwndButton, (rect.right-rect.left)/2 - 15*cxChar ,\
			//(rect.bottom-rect.top)/2 - 1.25*cxChar, 30*cxChar, 2.5*cyChar, FALSE);
			return 0;
		}


		case WM_COMMAND:
		{

			//各控件的_click()事件
			switch (LOWORD(wParam))
			{
				case 0:
					PostQuitMessage(0);
					break;

				case IDcmdButton1:
					//	strXy=string(aaa(n));
					//	SetWindowText(hwndEditbox,strXy.c_str());

					//SetWindowPos(hwndButton1, NULL,0, 0,0, 0, SWP_NOZORDER);


					//	ShowWindow(hwndButton2, SW_SHOW);
					goto e;
				eend:
					break;

				case IDcmdButton2:
					for(int i=1;i<=9;i++)
					{
						for(int j=1;j<=9;j++)
						{
							if(p(i,j)==0)
							{
								goto f;
							}
						}
					}
					MessageBox(NULL,"正确","Message",MB_OK|MB_ICONERROR);
					goto t;
				f:
					MessageBox(NULL,"失败","Message",MB_OK|MB_ICONERROR);
				t:
					break;

				case IDcmdButton3:
					n-=1;
					break;
				case IDcmdButton5:
				{
					ShowWindow(w9c,SW_SHOW );
					MoveWindow(w9c, 50,50, 640, 480, TRUE);
					break;
				}
				case IDeditBox:
					GetWindowText(hwndEditbox,buff,4096);
					break;
			}

			return 0;
		}
		case WM_LBUTTONDOWN: // WM_LBUTTONDOWN是鼠标左键按下的事件
		{

			GetCursorPos(&mouse);
			GetWindowRect(hwnd, &rect);
			mX=mouse.x-rect.left;
			mY=mouse.y-rect.top;
			itoa(mX,x,10);
			itoa(mY,y,10);
			//strXy=string(aaa(1));
			//	SetWindowText(hwndEditbox,strXy.c_str());
			//MessageBox(NULL, strXy.c_str(), "", MB_ICONASTERISK);
			return 0;
		}
		case CAMEL_change:
		{
			string strXy=to_string(a[xx][yy]);
			SetWindowText(hwndButton[xx][yy],strXy.c_str());
			return 0;
		}
		case WM_CLOSE:
		{
			/*
						if (IDYES==MessageBox(hwnd, "是否真的要退出？", "确认", MB_ICONQUESTION | MB_YESNO))
						{
							DestroyWindow(hwnd);//销毁窗口
							//	ShowWindow(w9, SW_HIDE);
						}
			*/
			ShowWindow(w9, SW_HIDE);
			return 0;
		}
		//	case WM_DESTROY:
		//		ShellAbout(hwnd, "第一个窗口程序", "再见，期待您在评论区留言！", NULL);
		//		PostQuitMessage(0);
		//		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
string xy="";

LRESULT CALLBACK w9cproc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC         	hdc;
	PAINTSTRUCT 	ps;
	RECT			rect;
	POINT			mouse;
	static int  	cxChar, cyChar;
	static int  	mX, mY;
	static HWND 	hwndButton1;
	static HWND 	hwndEditbox;
	static HWND 	hwndEditbox1;
	static HWND     hwndButton2;
	static HWND     hwndButton3;
	static HWND     hwndButton4;
	static HWND     hwndButton5;
	static HWND     hwndButton6;
	static HWND     hwndButton7;
	HWND hwnd1;
	string			strXy;

	char			x[5], y[5];
	char			buff[4096]={0};
	const int		IDcmdButton1=1;
	const int		IDcmdButton5=5;
	const int		IDcmdButton2=3;
	const int		IDcmdButton3=4;
	const int		IDcmdButton4=6;
	const int		IDcmdButton6=8;
	const int		IDcmdButton7=9;
	const int		IDeditBox=2;
	const int		IDeditBox1=7;
	int d=0;
	cxChar=LOWORD(GetDialogBaseUnits());
	cyChar=HIWORD(GetDialogBaseUnits());
	switch (message)
	{

		case WM_CREATE:
		{

/*
			hwndButton5=CreateWindow ( TEXT("button"), TEXT("确认"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 0, 0,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton5, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton5)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton5,SW_SHOW);
			UpdateWindow(hwndButton5);
			*/
			hwndButton1=CreateWindow ( TEXT("button"), TEXT("左移"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 60, 60,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton1, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton1)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton1,SW_SHOW);
			UpdateWindow(hwndButton1);
			hwndButton2=CreateWindow ( TEXT("button"), TEXT("右移"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 180, 60,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton2, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton2)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton2,SW_SHOW);
			UpdateWindow(hwndButton2);

			hwndButton3=CreateWindow ( TEXT("button"), TEXT("上移"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 120, 0,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton3, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton3)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton3,SW_SHOW);
			UpdateWindow(hwndButton3);
			hwndButton4=CreateWindow ( TEXT("button"), TEXT("下移"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 120, 120,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton4, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton4)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton4,SW_SHOW);
			UpdateWindow(hwndButton4);
			hwndEditbox=CreateWindow( TEXT("edit"),NULL,
										WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
										120, 60,
										50, 50,
										hwnd,(HMENU)IDeditBox,NULL,NULL);

			if (!hwndEditbox)
			{
				MessageBox(NULL,"创建文本框失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndEditbox,SW_SHOW);
			UpdateWindow(hwndEditbox);
			
			hwndButton6=CreateWindow ( TEXT("button"), TEXT("上一项"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 250, 0,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton6, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton6)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton6,SW_SHOW);
			UpdateWindow(hwndButton6);
			hwndEditbox1=CreateWindow( TEXT("edit"),NULL,
										WS_CHILD | WS_VISIBLE | WS_BORDER | ES_MULTILINE,
										250, 60,
										50, 50,
										hwnd,(HMENU)IDeditBox1,NULL,NULL);

			if (!hwndEditbox1)
			{
				MessageBox(NULL,"创建文本框失败","Message",MB_OK|MB_ICONERROR);
			}
			ShowWindow(hwndEditbox,SW_SHOW);
			UpdateWindow(hwndEditbox);
			hwndButton7=CreateWindow ( TEXT("button"), TEXT("下一项"),
										 WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
										 250, 120,
										 50, 50,
										 hwnd, (HMENU)IDcmdButton7, ((LPCREATESTRUCT) lParam)->hInstance, NULL);

			if (!hwndButton7)
			{
				MessageBox(NULL,"创建按钮失败","Message",MB_OK|MB_ICONERROR);
			}

			ShowWindow(hwndButton7,SW_SHOW);
			UpdateWindow(hwndButton7);
			xy="(1,1)";
			SetWindowText(hwndEditbox,xy.c_str());
			return 0;
		}
		/*
				case WM_PAINT:
				{
					hdc=BeginPaint (hwnd, &ps);
					SetRect(&rect, 10, 10, 300, 200);
					FrameRect(hdc, &rect, (HBRUSH)GetStockObject(BLACK_BRUSH));
					GetClientRect (hwnd, &rect);
					rect.left +=20;
					rect.top +=2;
					//SetTextColor(hdc, RGB(255,0,0));//可以用RGB三原色设置文本颜色
					DrawText(hdc, TEXT(" Hello, Dev-C++! "), -1, &rect, DT_SINGLELINE | DT_TOP | DT_LEFT);
					EndPaint(hwnd, &ps);
					return 0;
				}
		*/
		case WM_SIZE:
		{

			//GetWindowRect(hwnd, &rect);
			//MoveWindow(hwndButton, (rect.right-rect.left)/2 - 15*cxChar ,\
			//(rect.bottom-rect.top)/2 - 1.25*cxChar, 30*cxChar, 2.5*cyChar, FALSE);
			return 0;
		}


		case WM_COMMAND:
		{

			//各控件的_click()事件
			switch (LOWORD(wParam))
			{
				case 0:
				{

					PostQuitMessage(0);
					break;
				}

				case IDcmdButton1:
				{

					xx--;
					if(xx==0)
					{
						xx=9;


					}
					xy="("+to_string(xx)+","+to_string(yy)+")";
					SetWindowText(hwndEditbox,xy.c_str());
					break;
				}
				case IDcmdButton2:
				{
					xx++;
					if(xx==10)
					{
						xx=1;
					}
					xy="("+to_string(xx)+","+to_string(yy)+")";
					SetWindowText(hwndEditbox,xy.c_str());
					break;
				}
				case IDcmdButton3:
				{
					yy--;
					if(yy==0)
					{
						yy=9;
					}
					xy="("+to_string(xx)+","+to_string(yy)+")";
					SetWindowText(hwndEditbox,xy.c_str());
					break;
				}
				case IDcmdButton4:
				{
					yy++;
					if(yy==10)
					{
						yy=1;
					}
					xy="("+to_string(xx)+","+to_string(yy)+")";
					SetWindowText(hwndEditbox,xy.c_str());
					break;
				}
				case IDcmdButton7:
				{
					if(ab[xx][yy]==true)
					{
						MessageBox(NULL,"这是题目，不可修改","Message",MB_OK|MB_ICONERROR);
						break; 
					}
					a[xx][yy]++;
					if(a[xx][yy]==10)
					{
						a[xx][yy]=1;
					}
					xy=to_string(a[xx][yy]);
					SetWindowText(hwndEditbox1,xy.c_str());
					SendMessage(w9,CAMEL_change,0,0);
					break;
				} 
				case IDcmdButton6:
				{
					if(ab[xx][yy]==true)
					{
						MessageBox(NULL,"这是题目，不可修改","Message",MB_OK|MB_ICONERROR);
						break; 
					}
					a[xx][yy]--;
					if(a[xx][yy]==0)
					{
						a[xx][yy]=9;
					
					}
					xy=to_string(a[xx][yy]);
					SetWindowText(hwndEditbox1,xy.c_str());
					
					SendMessage(w9,CAMEL_change,0,0);	
					break;
				}
			}

			return 0;
		}
		case WM_LBUTTONDOWN: // WM_LBUTTONDOWN是鼠标左键按下的事件
		{


			return 0;
		}
		case WM_CLOSE:
		{

			return 0;
		}
		//	case WM_DESTROY:
		//		ShellAbout(hwnd, "第一个窗口程序", "再见，期待您在评论区留言！", NULL);
		//		PostQuitMessage(0);
		//		return 0;
	}

	return DefWindowProc(hwnd, message, wParam, lParam);
}
