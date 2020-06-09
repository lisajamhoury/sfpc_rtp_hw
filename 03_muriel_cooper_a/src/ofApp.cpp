#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("helvetica-bold.ttf", 72, true, true, true);
    font.setLetterSpacing(0.83);
    debugImg.load("images/smpImgs/03_muriel_cooper_og.jpg");

    squareClr = ofColor(39, 23, 19);
    borderClr = ofColor(223,210,202);
    typeClr3 = ofColor(54, 20, 65); // purple
    typeClr2 = ofColor(1, 74, 24); // green
    typeClr1 = ofColor(205, 43, 22); // red


}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    float amt = ofMap(mouseX, 0, ofGetWidth(), 0.7, 1.0);
    //    float numRows = ofMap(mouseX, 0, ofGetWidth(), 1.0, 20.0);
    //    float ls = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
//    float yOff = ofMap(mouseX, 0, ofGetWidth(), 0, 300.0);
    
    float lh = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
    font.setLineHeight(lh);

    ofBackground(squareClr);
//    ofBackground(255);
    

    
//    ofTranslate(300,300);
    
    // back ground image
//    ofPushMatrix();
//    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
//    ofRotateDeg(45);
//
//    debugImg.draw(-ofGetWidth()/2, -ofGetHeight()/2, ofGetWidth(), ofGetHeight());
//    ofPopMatrix();
    
    
    // create grid
    
    ofSetColor(0, 255, 0);
    ofNoFill();
    
    float numRows = 10.0;
    float rectW = ofGetWidth()/numRows;

    
    // columns
    for (int i = 0; i < numRows; i++) {
        ofDrawRectangle(i*rectW, 0, rectW, ofGetHeight());
    }
    
    // rows
    for (int i = 0; i < numRows; i++) {
        float rectW = ofGetWidth()/numRows;
        ofDrawRectangle(0, i*rectW, ofGetWidth(), rectW);
    }
    
    
    float yOff = 6.375;
//    float trans = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    float trans = 255;
    
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofSetColor(typeClr3, trans);
    
    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(180);
    font.drawString("MESSAGES", 326-ofGetWidth()/2, 556-ofGetHeight()/2+yOff);
    font.drawString("MEANS", 579-ofGetWidth()/2, 462-ofGetHeight()/2+yOff);
    
    font.drawString("MESSAGES", -38-ofGetWidth()/2, 394-ofGetHeight()/2+yOff);
    font.drawString("MEANS", 19-ofGetWidth()/2, 302-ofGetHeight()/2+yOff);
    ofPopMatrix();
    
    ofSetColor(typeClr2, trans);

    ofPushMatrix();
    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    ofRotateDeg(90);
    font.drawString("MESSAGES", 326-ofGetWidth()/2, 556-ofGetHeight()/2+yOff);
    font.drawString("MEANS", 579-ofGetWidth()/2, 462-ofGetHeight()/2+yOff);

    font.drawString("MESSAGES", -38-ofGetWidth()/2, 394-ofGetHeight()/2+yOff);
    font.drawString("MEANS", 19-ofGetWidth()/2, 302-ofGetHeight()/2+yOff);
    ofPopMatrix();
    
    ofSetColor(typeClr1, trans);
//    font.drawString("MESSAGES", 4.0* rectW, 7.0*rectW);
    font.drawString("MESSAGES", 326, 556+yOff);
    font.drawString("MEANS", 579, 462+yOff);
    ofFill();

    font.drawString("MESSAGES", -38, 394+yOff);
    font.drawString("MEANS", 19, 302+yOff);

    ofDisableBlendMode();


    


//    cout << mouseX << ", " << mouseY << endl;
    
    
//    vector < ofPath > paths = font.getStringAsPoints("MESSAGES");

//    for (int i = 0; i < paths.size(); i++){
//        paths[i].setPolyWindingMode(OF_POLY_WINDING_ODD);
//        vector < ofPolyline > lines = paths[i].getOutline();
//        for (int j = 0; j < lines.size(); j++){
//
//            lines[j].setClosed(true);
//            lines[j] = lines[j].getResampledBySpacing(3);
//
//            for (int k = 0; k < lines[j].size(); k++){
//                lines[j][k].x += mouseX * sin(lines[j][k].y * 0.04 + ofGetElapsedTimef() + i);
//            }
//
//            lines[j].draw();
//
//        }
//        paths[i].close();
//        paths[i].simplify();
//        paths[i].draw();
//    }
//
    
    
    // build frame
     ofSetColor(borderClr);
     float borderW = ofGetWidth() * (2.0/30.0);
     ofDrawRectangle(0, 0, ofGetWidth(), borderW);
     ofDrawRectangle(0, ofGetHeight()-borderW, ofGetWidth(), ofGetHeight());
     ofDrawRectangle(0, borderW, borderW, ofGetHeight()-borderW);
     ofDrawRectangle(ofGetWidth()-borderW, borderW, borderW, ofGetHeight()-borderW);

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
