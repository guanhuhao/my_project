#pragma once
int tanchishe(char name[]);                                          //贪吃蛇入口
DWORD WINAPI body(LPVOID lpParameter);                    //控制身体的线程
DWORD WINAPI direction(LPVOID lpParameter);            //控制方向的线程
DWORD WINAPI ball(LPVOID lpParameter);                   //控制球生成的线程
void HideCursor(int a);                                   //隐藏/显示光标
