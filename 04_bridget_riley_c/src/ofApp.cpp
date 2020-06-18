#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 600);
    ofEnableAntiAliasing();
    guiShow = false;
    
    gui.setup();
    gui.add(powAmt.setup("pow amt", 1.45, 0.01, 10.0));
    gui.add(sinAmt.setup("sin amt", 0.25, -5.0, 5.0)); // 0.17
    gui.add(wAmt.setup("w amt", 0.725, 0.0, 5.0));
        
    rows = 34;
    columns = 13;
    
    float borderW = ofGetWidth() * 0.10;
    float innerW = ofGetWidth()- (borderW*2);
    
    w = innerW / columns;
    h = innerW / rows;
        
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            
            int rowIndex = i;
            
            // count backward for second half of grid
            if (i >= rows/2) {
                cout << "back" << endl;
                rowIndex = rows-i-1;
            }
            
            // calculate x, y, h of cell
            float yPct = ofMap(rowIndex, 0, rows/2, 0, 1);
            yPct = powf(yPct, powAmt);
            
            float yPct2 = ofMap(rowIndex+1, 0, rows/2, 0, 1);
            yPct2 = powf(yPct2, powAmt);
            
            float y = ofMap(yPct, 0, 1, borderW, ofGetHeight()/2);
            float y2 = ofMap(yPct2, 0, 1, borderW, ofGetHeight()/2);
            
            float x = ofMap(j, 0, columns, borderW, innerW+borderW);
            float h = y2-y;
            
            // // mirror the rectangles on second half of grid
            if (i >= rows/2) {
                float shapeH = y2-y;
                y = ofGetHeight()/2 + (ofGetHeight()/2-y2);
                y2 = y + shapeH;
            }
            
            // draw every other triangle
            bool drawShape;
            if ((j + i) % 2 == 0){
                drawShape = false;
            } else {
                drawShape = true;
            }
            
            // calculate x position of top of triangle
            float sinAmt = 0.03;
            float xOffset = ofMap(sin(i*sinAmt), -1,1,0,w);
            
            // create a new cell, add to array
            int arrayIndex1 = (columns*i)+j;
            
            Cell newCell1;
            newCell1.setup(x, y, w, h, xOffset, drawShape);
            cells[arrayIndex1] = newCell1;

            
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(255);
        
   
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){

            cout << wAmt << endl;
            float xOffset = ofMap(sin(i*sinAmt), -1,1,0,w*wAmt);
            
            int arrayIndex1 = (columns*i)+j;
            cells[arrayIndex1].update(xOffset);
            cells[arrayIndex1].draw();
            
        }
    }
      
    
    screenshot.run();
    
    if(guiShow){
        gui.draw();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
        if (key == OF_KEY_RETURN) {
            screenshot.take();
        std::cout << "return pressed" << endl;
    }
    
    if(key == 'h'){
        guiShow = !guiShow;
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

