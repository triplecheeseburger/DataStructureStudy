#include "maparraystack.h"
#include "mapdef.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

void printMap(char map[HEIGHT][WIDTH]) {
	printf("====map start====\n");
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			switch (map[h][w]) {
				case NOT_VISIT:
					printf("."); break;
				case WALL:
					printf("X"); break;
				case VISIT:
					printf("O"); break;
				case START:
					printf("S"); break;
				case END:
					printf("E"); break;
				case POPPED:
					printf("P"); break;
				default:
					printf("something wrong");
			}
			printf(" ");
		}
		printf("\n");
	}
	printf("=====map end=====\n");
}

void printDirection(int direction) {
	printf("moved ");
	switch (direction) {
		case 0:
			printf("right"); break;
		case 1:
			printf("down"); break;
		case 2:
			printf("left"); break;
		case 3:
			printf("up"); break;
		default:
			printf("something wrong");
	}
	printf(", ");
}

bool checkCurrentDirection(char map[HEIGHT][WIDTH], MapPosition *curPos)
{
	int nextX = curPos->x + DIRECTION_OFFSETS[curPos->direction][X];
	int nextY = curPos->y + DIRECTION_OFFSETS[curPos->direction][Y];
	if (nextX >= WIDTH || nextX < 0)
		return (FALSE);
	if (nextY >= HEIGHT || nextY < 0)
		return (FALSE);
	if (map[nextY][nextX] == NOT_VISIT || map[nextX][nextY] == END) {
		return (TRUE);
	}
	return (FALSE);
}

bool noWhereTogo(MapPosition *mp)
{
	return (mp->direction == 4);
}

void visit(char map[8][8], int x, int y) {
	map[y][x] = VISIT;
}

void goNextStep(char map[HEIGHT][WIDTH], ArrayStack *mazeRunner)
{
	MapPosition *curPos = &peekAS(mazeRunner)->mp;

	int nextX = curPos->x + DIRECTION_OFFSETS[curPos->direction][X];
	int nextY = curPos->y + DIRECTION_OFFSETS[curPos->direction][Y];
	pushAS(mazeRunner, nextX, nextY);
	visit(map, nextX, nextY);
	printDirection(curPos->direction);
	printf("current position: (%d, %d)\n", nextX, nextY);
}

bool reachEndPoint(StackNode* curPos, MapPosition endPoint) {
	if (curPos == NULL) {
		printf("NO EXIT\n\n");
		return (TRUE);
	}
	MapPosition currentPosition = curPos->mp;
	if (currentPosition.x == endPoint.x && currentPosition.y == endPoint.y) {
		return (TRUE);
	}
	return (FALSE);
}

void findPath(char map[HEIGHT][WIDTH]) {
	printMap(map);
	ArrayStack* mazeRunner = createArrayStack(HEIGHT * WIDTH);
	MapPosition endPoint = {0};
	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			if (map[h][w] == START) {
				pushAS(mazeRunner, w, h);
				visit(map, w, h);
			}
		}
	}

	for (int h = 0; h < HEIGHT; h++) {
		for (int w = 0; w < WIDTH; w++) {
			if (map[h][w] == END) {
				endPoint.x = w;
				endPoint.y = h;
			}
		}
	}

	// 진행 방향 순서 = 오른쪽, 아래, 왼쪽, 위
	while (!reachEndPoint(peekAS(mazeRunner), endPoint)) {
		MapPosition* mp;
		mp = &peekAS(mazeRunner)->mp;
		if (noWhereTogo(mp)) {
			StackNode* popped = popAS(mazeRunner);
			map[popped->mp.y][popped->mp.x] = POPPED;
			printf("\nPOPPED\n");
		}
		else if (!checkCurrentDirection(map, mp)) {
			mp->direction++;
			printf("\nturned\n\n");
		}
		if (checkCurrentDirection(map, mp)) {
			goNextStep(map, mazeRunner);
			printMap(map);
		}
	}
	printMap(map);
	deleteArrayStack(mazeRunner);
}


int main(void) {
	char map0[HEIGHT][WIDTH] = { // given map
			{START, 0, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1},
			{1, 1, 1, 0, 1, 1, 1, 1},
			{1, 1, 1, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 1, 1},
			{1, 0 ,0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, END}
	};

	char map1[HEIGHT][WIDTH] = { //NOEXIT
			{START, 0, 1, 1, 1, 1, 1, 1},
			{1, 0, 0, 1, 0, 0, 0, 1},
			{1, 1, 1, 0, 1, 1, 1, 1},
			{1, 1, 1, 0, 1, 1, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 1, 1, 1, 1},
			{1, 0 ,0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, END}
	};

	char map2[HEIGHT][WIDTH] = { //new map
			{3, 0, 1, 1, 1, 1, 1, 1},
			{1, 0, 1, 0, 0, 0, 0, 1},
			{1, 0, 0, 0, 1, 0, 1, 1},
			{1, 1, 1, 0, 1, 0, 1, 1},
			{1, 0, 0, 0, 0, 0, 0, 1},
			{1, 0, 1, 1, 0, 1, 1, 1},
			{1, 0 ,0, 0, 0, 0, 0, 0},
			{1, 1, 1, 1, 1, 1, 1, 4}
	};

	findPath(map0);
	findPath(map1);
	findPath(map2);
}
