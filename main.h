#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
//Ŀ�� ����ü

#define START 8
#define END 10
#define TRUE 1
#define FALSE 0

#define RIGHT 68
#define LEFT 65
#define UP 87
#define DOWN 83
#define ENTER 13
typedef struct Num
{
	int x, y;
	int Value;
}num;

typedef struct CursorPosition
{
	int x, y;
}CursorPos;
//�޴�ȭ�� ���
int PrintMenu();
//Ŀ�� ����
void ClearCursor();
//ȭ�� �̵�
void gotoxy(int x, int y);
//�޴�ȭ�� ���ϰ�
int Value;
//���� �Ѱ�����
void GameMaster();
//���� ������Ʈ
num NumberObject[4][4];
//���� ������Ʈ �ʱ�ȭ
void InitGameObject();
//������Ʈ ��ġ���� �⺻�� 
int PosX = 4, PosY = 2;
//������Ʈ ���
void PrintObject();
//���� ������Ʈ
void Update();
//������ ��ü�̵�
void RightMove();
//���� ��ü�̵�
void LeftMove();
//�Ʒ��� ��ü�̵�
void DownMove();
//���� ��ü�̵�
void UpMove();
//��������
void CreateObject();
//������ ����
int movingpoint = TRUE;
//����
int point = 0;