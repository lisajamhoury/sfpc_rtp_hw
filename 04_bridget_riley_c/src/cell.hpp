//
//  cell.hpp
//  04_bridget_riley_c
//
//  Created by Lisa Jamhoury on 6/16/20.
//

#ifndef cell_hpp
#define cell_hpp

#include "ofMain.h"
#include <stdio.h>

class Cell {
    
public:
    void setup(float _x, float _y, float _w, float _h, float _xOff, bool _dS);
    
    void update(float _xOff);
    
    void draw();
    
    float x;
    float y;
    float w;
    float h;
    float xOff;
    
    ofVec2f v1;
    ofVec2f v2;
    ofVec2f v3;
    ofVec2f v4;
    ofVec2f v5;
    
    bool drawShape;
    Cell();
    
private:
    
    
    
    
    
};





#endif /* cell_hpp */
