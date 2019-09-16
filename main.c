#include "main.h"

void InitGameObject()
{
	//������Ʈ �� �ʱ�ȭ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			NumberObject[i][j].Value = 0;
		}
	}
	//������Ʈ ��ġ�� �ʱ�ȭ
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			NumberObject[i][j].x = PosX;
			NumberObject[i][j].y = PosY;
			PosX += 4;
		}
		PosX = 4;
		PosY += 2;
	}
}

void gotoxy(int x, int y)
{
	COORD pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void ClearCursor()
{
	CONSOLE_CURSOR_INFO cursorInfo = { 0, };
	cursorInfo.dwSize = 1;
	cursorInfo.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

int PrintMenu()
{
	//Ŀ����ġ �ʱ�ȭ
	CursorPos cursor;
	cursor.x = 8;
	cursor.y = 8;
	//Ŀ�� ����
	ClearCursor();

	//�޴�ȭ�� �̹��� ���
	gotoxy(10,6);
	printf("2 0 4 8 ����");
	gotoxy(10,8);
	printf("���ӽ����ϱ�");
	gotoxy(10,10);
	printf("���������ϱ�");


	//�޴� ����
	while (TRUE) {
		if (_kbhit())
		{
			char Input = _getch();

			if (Input == UP && cursor.y >8)
			{
				gotoxy(cursor.x, cursor.y);
				printf("  ");
				cursor.y -= 2;
			}
			if(Input == DOWN && cursor.y < 10)
			{
				gotoxy(cursor.x, cursor.y);
				printf("  ");
				cursor.y += 2;
			}
			if (Input == ENTER)
			{
				return cursor.y;
			}
			else
			{
				continue;
			}
		}
		gotoxy(cursor.x, cursor.y);
		printf("��");
	}

}

void PrintObject()
{
	gotoxy(30, 30);
	printf("���� : %d",point);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
		{
			gotoxy(NumberObject[i][j].x, NumberObject[i][j].y);
			printf("%d",NumberObject[i][j].Value);
		}
	}
}

void RightMove()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (NumberObject[i][j].Value == NumberObject[i][j + 1].Value)
			{
				NumberObject[i][j + 1].Value += NumberObject[i][j].Value;
				point += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (NumberObject[i][j + 1].Value == 0)
			{
				NumberObject[i][j + 1].Value += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

	
}

void LeftMove()
{
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (NumberObject[i][j].Value == NumberObject[i][j-1].Value)
			{
				NumberObject[i][j-1].Value += NumberObject[i][j].Value;
				point += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 3; j > 0; j--)
		{
			if (NumberObject[i][j-1].Value == 0)
			{
				NumberObject[i][j-1].Value += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}
	
}

void DownMove()
{
	
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (NumberObject[i][j].Value == NumberObject[i + 1][j].Value)
			{
				NumberObject[i + 1][j].Value += NumberObject[i][j].Value;
				point += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (NumberObject[i + 1][j].Value == 0)
			{
				NumberObject[i + 1][j].Value += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}
	
}

void UpMove()
{
	
	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (NumberObject[i][j].Value == NumberObject[i - 1][j].Value)
			{
				NumberObject[i - 1][j].Value += NumberObject[i][j].Value;
				point += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

	for (int i = 3; i > 0; i--)
	{
		for (int j = 0; j < 4; j++)
		{
			if (NumberObject[i - 1][j].Value == 0)
			{
				NumberObject[i - 1][j].Value += NumberObject[i][j].Value;
				NumberObject[i][j].Value = 0;
				movingpoint = TRUE;
			}
		}
	}

}

void CreateObject()
{
	while (TRUE)
	{
		int x = rand() % 3;
		int y = rand() % 3;

		if (NumberObject[y][x].Value == 0)
		{
			NumberObject[y][x].Value = 2;
			break;
		}
		 
	}
}

void Update()
{
	movingpoint = FALSE;

	char Input = _getch();
	switch (Input)
	{
	case RIGHT:
		RightMove();
		break;
	case LEFT:
		LeftMove();
		break;
	case UP:
		UpMove();
		break;
	case DOWN:
		DownMove();
		break;
	}
	if (movingpoint == TRUE) {
		CreateObject();
	}

}

void GameMaster() {
	//������Ʈ �ʱ�ȭ
	system("cls");
	InitGameObject();
	PrintObject();
	while (TRUE) {
		if (_kbhit) {
			Update();
			system("cls");
			PrintObject();
		}
	}
}

int main()
{
	srand(time(NULL));
	//�޴�ȭ�� ���
	if (Value = PrintMenu() == START)
	GameMaster();
	
	exit(-1);
}