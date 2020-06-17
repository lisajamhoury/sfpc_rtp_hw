//
//  cell.cpp
//  04_bridget_riley_c
//
//  Created by Lisa Jamhoury on 6/16/20.
//

#include "cell.hpp"

Cell::Cell()  {
    
}

void Cell::setup(float _x, float _y, float _w, float _h, float _xOff, bool _dS) {
    
    x = _x;
    y = _y;
    w = _w;
    h = _h;
    
    v1 = ofVec2f(x,y);
    v2 = ofVec2f(x+w, y);
    v3 = ofVec2f(x+w, y+h);
    v4 = ofVec2f(x, y+h);
    v5 = ofVec2f();
    
    

    drawShape = _dS;

    xOff = _xOff;
    v5.x += xOff;
    v5.y = y;
    
}

void Cell::update() {
    
//    float distance = v1.distance(v2);
//    v5.x = x + (distance/2);
//    v5.x += xOff;
//    v5.y = y;
        
//    float borderW = ofGetWidth() * 0.10;
//    float innerW = ofGetWidth()- (borderW*2);
//    float

    
    
}

void Cell::draw() {
    ofSetColor(0);

    if (drawShape) {
        ofBeginShape();
        
        ofVertex(v5);
        ofVertex(v3);
        ofVertex(v4);
        
        ofEndShape(true);
    }
    

    
}
