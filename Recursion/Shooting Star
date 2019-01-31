/* Stimulating the shooting route in a room. We know the boundary of the room, the starting point of the shooting object, and the 
   direction of shooting. When the object hits the boundary, it would reflect with 45 degree. Show the route of the shooting object. */
/* Input Format:
   The first line has three numbers, C, F and H, which respectively means the length of the ceiling, the length of the floor, and 
   the height between the ceilings and floors. The second line has a number S, which means the starting point of shooting object.
   (1 <= C, F <= 20 ; 2 <= H <= 20 ; 1 <= S <= H)
   The third line has a character 'u' or 'd'. It corresponds to the initial direction of shooting.
   (u: upper-right in 45 degree ; d: lower-right in 45 degree)
   Output Format: 
   Draw the map and the route of the shooting object.
   The route of shooting object is marked as '*', which appears until the object is out of boundaries.  */
/* Sample Input:
   5 7 3
   1
   d
   Sample Output:
   -----    *
   *   *   * 
    * * * *  
     *   *   
   -------   
*/

#include <stdio.h>

void route(int i, int j, char dir);
int max(int x, int y);
char map[25][50];
int C, F, H, S;
char init_dir;
int horiz_length = 0;

int main(void)
{
    scanf("%d%d%d", &C, &F, &H);
    scanf("%d", &S);
    while (getchar() != '\n');
    scanf("%c", &init_dir);
    for (int i = 0; i < 25; i++) {
        for (int j = 0; j < 50; j++)
            map[i][j] = ' ';
    }
    for (int j = 0; j < C; j++)
        map[0][j] = '-';
    for (int j = 0; j < F; j++)
        map[H + 1][j] = '-';
    route(S, 0, init_dir);
    for (int i = 0; i < H + 2; i++) {
        for (int j = 0; j < max(max(C, F), horiz_length); j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
    return 0;
}

void route(int i, int j, char dir)
{
    if (i < 0 || i >= H + 2)
        return;
    if (map[i][j - 1] == '-') {
        if (dir == 'u')
            route(i + 2, j, 'd');
        else if (dir == 'd')
            route(i - 2, j, 'u');
    }
    else {
        horiz_length++;
        if (dir == 'u') {
            map[i][j] = '*';
            route(i - 1, j + 1, 'u');
        }
        else if (dir == 'd') {
            map[i][j] = '*';
            route(i + 1, j + 1, 'd');
        }
    }
}

int max(int x, int y)
{
    return (x > y)? x : y;
}
