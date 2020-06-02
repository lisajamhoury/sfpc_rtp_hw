//
//  wLine.cpp
//  02_john_whitney_a
//
//  Created by Lisa Jamhoury on 5/31/20.
//

#include "wLine.hpp"


WLine::WLine() {
}

void WLine::setup(float _xO1, float _yO1, float _xO2, float _yO2, float _x1, float _y1, float _x2, float _y2, float _rad1, float _rad2, float _angle, ofColor _clr, int _group) {
    
    x1Start = _xO1;
    y1Start = _yO1;
    x2Start = _xO2;
    y2Start = _yO2;
    
    rad1Start = _rad1;
    rad2Start = _rad2;
    
    angleStart = _angle;

    xO1 = _xO1;
    yO1 = _yO1;
    xO2 = _xO2;
    yO2 = _yO2;
    
    x1 = _x1;
    y1 = _y1;
    x2 = _x2;
    y2 = _y2;
    
    rad1 = _rad1;
    rad2 = _rad2;
    
    angle1 = _angle;
    angle2 = _angle;
    
    clr = _clr;
    group = _group;
    
    state = 1;
    
    pathAngle = 0;
}

void WLine::updateState(int _state){
    state = _state;
}

void WLine::update(){
    if (state == 0) {

        xO1 = x1Start;
        yO1 = y1Start;
        xO2 = x2Start;
        yO2 = y2Start;
       
       rad1 = rad1Start;
       rad2 = rad2Start;
       
       angle1 = angleStart;
       angle2 = angleStart;
        
        // point on small circle
        x1 = xO1 + rad1 * cos(angle1);
        y1 = yO1 + rad1 * sin(angle1);

        // point on large circle
        
        x2 = xO2 + rad2 * cos(angle2);
        y2 = yO2 + rad2 * sin(angle2);
        
        state = 1;
           
    }
    
    if (state == 1) {

        // change in radius 89
        // over 3 seconds at 60 fps -- 180
        float radChange = 89.0/180.0;
        float x1Change = -310.0/180.0;
        float x2Change = -43.0/180.0;
        float angleChange = PI/180.0;
        
        float xOSmPath = 383.0;
        float yOSmPath = 223.0;
        float radSmPath = 155.0;
                
        rad1 += radChange;
        rad2 -= radChange;

        // center of circle x
        // moves to left
        xO1 += x1Change;
        xO2 += x2Change;

        
        // group 1 starts at bottom
        if (group == 1) {
//            yO1 += 1;
            angle1 += angleChange;
            angle2 -= angleChange;
            pathAngle+=angleChange;
//            clr = ofColor(0,255,0);

        } else {
//            yO1 -= 1;
            angle1 -= angleChange;
            angle2 += angleChange;
            pathAngle-=angleChange;

        }

        xO1 = xOSmPath + radSmPath * cos(pathAngle);
        yO1 = yOSmPath + radSmPath * sin(pathAngle);
        

        // point on small circle
        x1 = xO1 + rad1 * cos(angle1);
        y1 = yO1 + rad1 * sin(angle1);

        // point on large circle
        
        x2 = xO2 + rad2 * cos(angle2);
        y2 = yO2 + rad2 * sin(angle2);
        
    }
}

void WLine::draw(){
    
    ofSetColor(clr);
    ofSetLineWidth(3.0);
    
//
    ofDrawCircle(x1, y1, 1.0);
//
//    ofSetColor(0,255,0);
//    ofSetLineWidth(1.0);
//    ofDrawLine(0, yO1, ofGetWidth(), yO1);
    ofDrawCircle(x2, y2, 1.0);
    ofDrawLine(x1, y1, x2, y2);
    
}
