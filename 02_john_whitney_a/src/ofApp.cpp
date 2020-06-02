#include "ofApp.h"
#include "wLine.hpp"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    
    imageTaken = true;
    
    baseImg.load("images/smpImgs/img2.png");

    gui.setup(); // most of the time you don't need a name
    gui.add(smCRad.setup("Sm Radius", 22.0, 0, ofGetWidth()));
    gui.add(smCX.setup("Small X", 538.0, 0, ofGetWidth()));
    gui.add(smCY.setup("Small Y", 223.0, 0, ofGetHeight())); //218
    gui.add(lgCRad.setup("Lg Radius", 200.0, 0, ofGetWidth()));
    gui.add(lgCX.setup("Lg X", 363.0, 0, ofGetWidth()));
    gui.add(lgCY.setup("Lg Y", 223.0, 0, ofGetHeight())); //228
    gui.add(numLines.setup("Num Lines", 60, 20, 200));
    gui.add(lineW.setup("Line W", 3.0, 2.0, 10.0)); // hardcoded in class
    
    bHide = false;
    
    timer = 0.0;
    state = 1;
    
    // create lines
    
    float angleOffset = TWO_PI/(numLines * 2);
    
    for (int i = 0; i < numLines; i++) {
        
        float angle = TWO_PI/numLines * i + angleOffset ;
        ofColor clr;
        int group;
        
        
        if (i < numLines/2) {
            
            // pink
            clr = ofColor(213, 150, 154);
            group = 1;

        } else {
            
            // white
            clr = ofColor(223, 215, 197);
            group = 2;

        }
        
        // starting position
        // point on small circle
        float xorig1 = smCX;
        float yorig1 = smCY;
        float radius1 = smCRad;
        float angle1 = angle;
        float x1 = xorig1 + radius1 * cos(angle1);
        float y1 = yorig1 + radius1 * sin(angle1);

        // point on large circle
        float xorig2 = lgCX;
        float yorig2 = lgCY;
        float radius2 = lgCRad;
        float angle2 = angle;
        float x2 = xorig2 + radius2 * cos(angle2);
        float y2 = yorig2 + radius2 * sin(angle2);
        
        
        WLine line;
        line.setup(xorig1,yorig1, xorig2, yorig2, x1, y1, x2, y2, radius1, radius2, angle, clr, group);
        
        if (i < numLines/2) {
            lines1[i] = line;

        } else {
            int index = i - numLines/2;
            lines2[index] = line;
        }
        

    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (ofGetFrameNum() - timer == 180.0) {
        timer = ofGetFrameNum();
                
        if (state == 3) {
//            state = 0;
        } else {
            state++;
        }

        for (int i = 0; i < numLines/2; i++) {
            lines1[i].updateState(state);
            lines2[i].updateState(state);
        }
        
    }
    
    for (int i = 0; i < numLines/2; i++) {
        lines1[i].update();
        
    }

    for (int i = 0; i < numLines/2; i++) {
        
        lines2[i].update();
    }

    
    
    if (!imageTaken) {
        ofImage image;
        takeScreenShot();
        imageTaken = true;
    }
    
    if(!bHide){
        gui.draw();
    }
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofBackground(4,18,26);
//    baseImg.draw(0,0, ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < numLines/2; i++) {
        lines1[i].draw();
     
    }
    
    for (int i = 0; i < numLines/2; i++) {
     
        lines2[i].draw();
    }
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == OF_KEY_RETURN) {
        takeScreenShot();
        std::cout << "return pressed" << endl;
    }
    
    if (key == OF_KEY_RIGHT) {
        state++;

        for (int i = 0; i < numLines/2; i++) {
            lines1[i].updateState(state);
            lines2[i].updateState(state);
        }
    }
    
    if (key == OF_KEY_LEFT) {
        timer = ofGetFrameNum();

        state = 0;
        for (int i = 0; i < numLines/2; i++) {
            lines1[i].updateState(state);
            lines2[i].updateState(state);
        }
//        state =  1;
        
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}

void ofApp::takeScreenShot() {
    ofImage image;
    image.grabScreen(0,0,ofGetWidth(),ofGetHeight());
    string str = "images/devImgs/devImg";
    str += ofToString(ofGetTimestampString()) + ".jpg";
    image.saveImage(str);
    std::cout << "ss taken" << endl;
}
