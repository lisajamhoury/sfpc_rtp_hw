#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetWindowShape(600, 600);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    ofBackground(0);
    
    //    for (int i = 0; i < 50; i++){
    //
    //        // we love #s between 0-1
    //
    //        float pct = ofMap(i, 0, 49, 0, 1);
    //        pct = powf(pct, mouseX * 0.01);
    //        float x = ofMap(pct, 0, 1, 50, 750);
    //        ofDrawCircle(x,400, 3);
    //
    //    }
    
    
    float borderW = ofGetWidth() * 0.10;
    float rows = 34;
    float columns = 13;
    float innerW = ofGetWidth()- (borderW*2);
    float w = innerW / columns;
    float h = innerW / rows;
    
    cout << mouseX << endl;

    
      for (int i = 0; i < rows/2; i++){
            for (int j = 0; j < columns; j++){
                       
                float yPct = ofMap(i, 0, rows/2, 0, 1);
                yPct = powf(yPct, mouseX * 0.01);
                
                float yPct2 = ofMap(i+1, 0, rows/2, 0, 1);
                yPct2 = powf(yPct2, mouseX * 0.01);
                
                float y = ofMap(yPct, 0, 1, borderW, ofGetHeight()/2);
                float y2 = ofMap(yPct2, 0, 1, borderW, ofGetHeight()/2);
                
                float x = ofMap(j, 0, columns, borderW, innerW+borderW);
                
                float h = y2-y;
                
                if ((j + i) % 2 == 0){
                    ofSetColor(255);
                } else {
                    ofSetColor(0);
                }

                ofDrawRectangle(x, y, w, y2-y);
                ofDrawRectangle(x, ofGetHeight()-y-h, w, h);
                
//
//
//                if (i >= rows / 2) {
//                    ofDrawRectangle(x, ofGetHeight()-y-h, w, h);
//    //
//    //            if (i <= rows / 2) {
//                } else {
//                    ofDrawRectangle(x, y, w, y2-y);
//                }
                
                
                
            }
        }
    
    screenshot.run();
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
