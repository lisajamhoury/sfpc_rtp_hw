#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 600);
    
    guiShow = false;
    
    gui.setup();
    gui.add(powAmt.setup("pow amt", 1.45, 0.01, 10.0));
    
    rows = 34;
    columns = 13;
    
    float borderW = ofGetWidth() * 0.10;
    float innerW = ofGetWidth()- (borderW*2);
    
    float w = innerW / columns;
    float h = innerW / rows;
        
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
            float sinAmt = mouseX*0.01;
            float xOffset = ofMap(sin(i*sinAmt), -1,1,0,w);
            
            // create a new cell, add to array
            int arrayIndex1 = (columns*i)+j;
            
            Cell newCell1;
            newCell1.setup(x, y, w, h, xOffset, drawShape);
            cells[arrayIndex1] = newCell1;

//          int arrayIndex2 = (rows * columns) - arrayIndex1 - 1;
//          Cell newCell2;
//          newCell2.setup(x, ofGetHeight()-y-h, w, h, !drawShape);
//          cells[arrayIndex2] = newCell2;
            
        }
    }
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(255);
    
    
    
    
    
    //    cout << counter << endl;
    
    // can't use cells.size here?
    //442
    
    int cellsSize = 442;
    
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns; j++){
            
//            float yPct = ofMap(i, 0, rows, 0, 1);
//            yPct = powf(yPct, powAmt);
//            float x = ofMap(yPct, 0, 1, 0, s)
            
            int arrayIndex1 = (columns*i)+j;
            cells[arrayIndex1].update();
            cells[arrayIndex1].draw();
            
        }
    }
    
    //    for (int i = 0; i < cellsSize; i++) {
    
    
    
    //    }
    
    
    
    
    screenshot.run();
    
    if(guiShow){
        gui.draw();
    }
    
    
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
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

