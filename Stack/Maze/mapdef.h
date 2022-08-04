#ifndef _MAP_DEF_
#define _MAP_DEF_

#define WIDTH 8
#define HEIGHT 8
#define X 0
#define Y 1
#define NUM_DIRECTIONS 4

// offset: x, y
static int DIRECTION_OFFSETS[NUM_DIRECTIONS][2] = {
		// �������� �̵�.
	{1, 0},			// ���������� �̵�.
	{0, 1},			// �Ʒ������� �̵�.
	{-1, 0},			// �������� �̵�.
	{0, -1}
};

enum PosStatus { NOT_VISIT = 0, WALL = 1 , VISIT = 2 , START = 3, END = 4, POPPED = 5};

typedef struct MapPositionType
{
	int x;				// ���� ��ġ x��ǥ.
	int y;				// ���� ��ġ y��ǥ.
	int direction;		// ���� ��ġ�� �̵� ����.
} MapPosition;

#endif