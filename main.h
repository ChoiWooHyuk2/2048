#pragma once
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <time.h>
//커서 구조체

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
//메뉴화면 출력
int PrintMenu();
//커서 제거
void ClearCursor();
//화면 이동
void gotoxy(int x, int y);
//메뉴화면 리턴값
int Value;
//게임 총관리자
void GameMaster();
//게임 오브젝트
num NumberObject[4][4];
//게임 오브젝트 초기화
void InitGameObject();
//오브젝트 위치설정 기본값 
int PosX = 4, PosY = 2;
//오브젝트 출력
void PrintObject();
//정보 업데이트
void Update();
//오른쪽 전체이동
void RightMove();
//왼쪽 전체이동
void LeftMove();
//아래쪽 전체이동
void DownMove();
//위쪽 전체이동
void UpMove();
//랜던생성
void CreateObject();
//움직임 여부
int movingpoint = TRUE;
//점수
int point = 0;