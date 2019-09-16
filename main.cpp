#include <bits/stdc++.h>

using namespace std;

bool outOfWorld(int, int, int, int, int, const int*, const int*);

int main() {

    int xRectangularWorld, yRectangularWorld;
    cin >> xRectangularWorld >> yRectangularWorld;

    vector< vector<bool> > scent(yRectangularWorld + 1, vector<bool> (xRectangularWorld + 1, false));

    char directions[] = {'N', 'E', 'S', 'W'};
    int xOrientationChange[] = {0, 1, 0, -1};
    int yOrientationChange[] = {1, 0, -1, 0};

    int xCoordinate, yCoordinate;
    char startDirection;
    std::string instructions;

    while (cin >> xCoordinate >> yCoordinate >> startDirection >> instructions) {

        int direction = 0;

        for (int i = 0; i < 4; ++i) {
            if (startDirection == directions[i]) {
                direction = i;
            }
        }

        bool died = false;

        for (char instruction : instructions) {

            if (instruction == 'R')
                direction = (direction + 1) % 4;

            else if (instruction == 'L')
                direction = (direction + 3) % 4;

            else {

                if (outOfWorld(xCoordinate, yCoordinate, xRectangularWorld, yRectangularWorld,
                               direction, xOrientationChange, yOrientationChange)) {
                    if (!scent[yCoordinate][xCoordinate]) {
                        died = true;
                        scent[yCoordinate][xCoordinate] = died;
                        break;
                    }
                }

                else {
                    xCoordinate += xOrientationChange[direction];
                    yCoordinate += yOrientationChange[direction];
                }
            }

        }
        if (died) {
            cout << xCoordinate << ' ' << yCoordinate << ' ' << directions[direction] << " LOST" << '\n';
        } else{
            cout << xCoordinate << ' ' << yCoordinate << ' ' << directions[direction] << endl;
        }


    }

    return 0;
}

bool outOfWorld(int xCoordinate, int yCoordinate, int xRectangularWorld, int yRectangularWorld,
                int direction, const int* xOrientationChange, const int* yOrientationChange){

    return xCoordinate + xOrientationChange[direction] == -1 ||
           xCoordinate + xOrientationChange[direction] == xRectangularWorld + 1 ||
           yCoordinate + yOrientationChange[direction] == -1 ||
           yCoordinate + yOrientationChange[direction] == yRectangularWorld + 1;
}