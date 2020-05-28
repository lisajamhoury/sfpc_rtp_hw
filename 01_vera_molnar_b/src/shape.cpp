//
//  shape.cpp
//  01_vera_molnar_b
//
//  Created by Lisa Jamhoury on 5/26/20.
//

#include "shape.hpp"
#include "ofMain.h"
#include "ofApp.h"
#include <iostream>

Shape::Shape() {
}

void Shape::setup(float _x, float _y, float _w, float _h, string _side, bool _ctr, ofVec4f _pVerts, float _rXOff, float _rYOff, float _rHOff) {
    x = _x;
    y = _y;
    
    w = _w;
    h = _h;
    
    side = _side;
    clr = setColor();
    
    center = _ctr;
    prevVerts = _pVerts;
    
    rXOff = _rXOff;
    rYOff = _rYOff;
    rHOff = _rHOff;
    
    createVerts();
    
}

ofColor Shape::setColor() {
    ofColor leftClr(184,18,24);
    ofColor rightClr(59,6,9);
    
    // If X is on left
    if (side == "L") {
        return ofColor(leftClr);
    } else {
        return ofColor(rightClr);
    }
}

void Shape::createVerts() {
    float defaultRXOffset = rXOff; // 4.9 rXOff
    float yOffThresh = rYOff; // rYOff 0.32
    float rHOffset = ofRandom(rHOff); // 0.10 rHOff;


//    std::cout << rYOff << rXOff << endl;
//    std::cout << rXOff << ", " << rYOff << ", " << rHOff << endl;

    
    float rXOffsetMin;
    float rXOffsetMax;
    
    if (center == true) {
        float rightMost = 0;
        
        if (prevVerts.x > prevVerts.z) {
            rightMost = prevVerts.x;
        } else {
            rightMost = prevVerts.z;
        }
        
        rXOffsetMin = x - rightMost * 1.01;
        rXOffsetMax = defaultRXOffset;

        
    } else {
        rXOffsetMin = defaultRXOffset;
        rXOffsetMax = defaultRXOffset;
    }
    
    // random Y offset changes Y location randomly
    float rYOffset;
    
    //Threshold for Y variance
    //float yOffThresh = ofMap(mouseX, 0, width, 0.0, 0.5);
    
//    std::cout << rYOff << endl;
    
    
    //std::cout << yOffThresh << endl;
    // random H offset changes height of shape randomly
    
    // If X is on left
    if (side == "L") {
        rYOffset = ofRandom(0.0, yOffThresh*h);
    } else {
        rYOffset = ofRandom(yOffThresh*h, 2*yOffThresh*h);
    }

    v1 = ofVec2f(x+ofRandom(-rXOffsetMin,rXOffsetMax), y-rYOffset);
    v2 = ofVec2f(x+ofRandom(-rXOffsetMin,rXOffsetMax)+w, y-rYOffset);
    v3 = ofVec2f(x+ofRandom(-rXOffsetMin,rXOffsetMax)+w, y-rYOffset-rHOffset+h);
    v4 = ofVec2f(x+ofRandom(-rXOffsetMin,rXOffsetMax), y-rYOffset-rHOffset+h);

}

ofVec4f Shape::getVerts() {
    
    return ofVec4f(v2.x, v2.y, v3.x, v3.y);
    
}


void Shape::update(){
    
}

void Shape::draw(){
    
    // remove this?
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    ofSetColor(clr);
    
    ofBeginShape();
    
    ofVertex(v1);
    ofVertex(v2);
    ofVertex(v3);
    ofVertex(v4);
    
    ofEndShape(true);
}

