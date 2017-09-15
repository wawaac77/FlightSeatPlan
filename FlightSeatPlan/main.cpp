//
//  main.cpp
//  FlightSeatPlan
//
//  Created by Alice Jin on 15/9/2017.
//  Copyright © 2017 Alice Jin. All rights reserved.
//

#include <iostream>
using namespace std;

int amount = 35;
int seats[4][2] = {{3,2}, {3, 3}, {2, 4}, {3,4}};
int plan[100][100] = {0};


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    //int length = 0;
    int seatsSize = sizeof(seats)/sizeof(seats[0]);
    
    //**** calculate plan width ***//
    int width = 0;
    for (int i = 0; i < seatsSize; i++) {
        width += seats[i][0];
    }
    std::cout << "width " << width <<"\n";
    
    int height = 0;
    for (int i = 0; i < seatsSize; i++) {
        if (seats[i][1] > height) {
            height = seats[i][1];
        }
    }
    std::cout << "height " << height << "\n";
    
    
    //**** calculate 3 kind of seats's num ***//
    int aisle = 0;
    int window = 0;
    int middle = 0;
    
    window = seats[0][1] + seats[seatsSize - 1][1]; // calculate num of window seats
    //calculate aisle seats
    aisle = window;
    for (int i = 1; i < seatsSize - 1; i++) {
        aisle += seats[i][1]*2;
    }
    
    //calcualte middle seats
    middle = amount - window - aisle;
    
    std::cout << "aisle " << aisle << "\n";
    std::cout << "window " << window << "\n";
    std::cout << "middle " << middle << "\n";
    
    
    //********************** put window with -2, some aisle with -1 *********************//
    
    for (int i = 0; i < seats[0][1]; i++) {
        plan[i][0] = -2;
        plan[i][0 + seats[0][0] - 1] = -1; //aisle
        for (int k = 1; k < seats[0][0] - 1; k++) {
            plan[i][0 + k]= -3; // middle
        }

    }
    for (int i = 0; i< seats[seatsSize - 1][1]; i++) {
        plan[i][width - 1] = -2;
        plan[i][width -  seats[seatsSize-1][0]] = -1; //aisle
        for (int k = 1; k < seats[seatsSize-1][0] - 1; k++) {
            plan[i][width -  seats[seatsSize-1][0] + k] = -3; // middle
        }

    }
    
    std::cout << " ------------------ first -123 ------------ \n";
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width ; i++) {
        
            std::cout << " " << plan[j][i];
        }
        
        std::cout << "\n";
        
    }
    
    
    //********************** put aisle with - 1, middle with - 3 *********************//
    int x = seats[0][0]; // which row to start
    for (int i = 1; i < seatsSize - 1; i++) {
        for (int j = 0; j < seats[i][1]; j++) {
            plan[j][x] = -1;
            plan[j][x + seats[i][0] - 1] = -1;
            
            for (int k = 1; k < seats[i][0] - 1; k++) {
                plan[j][x + k] = -3; // middle
            }
        }
        x += seats[i][0];
    }
    std::cout << " ------------------ second -123 ------------ \n";
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width ; i++) {
            std::cout << " " << plan[j][i];
        }
        
        std::cout << "\n";
        
    }

    
    std::cout << " -------------------123 ------------ \n";
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width ; i++) {
            std::cout << " " << plan[j][i];
        }
        
        std::cout << "\n";
        
    }
    
    std::cout << " -------------------real plan ------------ \n";

    
    int aisleStart = 1;
    int windowStart = 1 + aisle;
    int middleStart = 1 + aisle + window;
    
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width ; i++) {
            if (plan[j][i] == -1) {
                plan[j][i] = aisleStart;
                aisleStart ++;
            } else if (plan[j][i] == -2) {
                plan[j][i] = windowStart;
                windowStart++;
            } else if (plan[j][i] == -3) {
                plan[j][i] = middleStart;
                middleStart ++;
            }
        }
    }
    //std::cout << "plan \n" << plan;
    for (int j = 0; j < height; j++) {
        for (int i = 0; i < width ; i++) {
            std::cout << " " << plan[j][i];
        }
        
        std::cout << "\n";

    }
    return 0;
}
