#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    font.load("helvetica-bold.ttf", 72, true, true, true);
    font.setLetterSpacing(0.83);
    
    //    debugImg.load("images/smpImgs/03_muriel_cooper_og.jpg");
    
    squareClr = ofColor(39, 23, 19);
    borderClr = ofColor(223,210,202);
    
    typeClr3 = ofColor(42, 15, 59); // purple
    typeClr2 = ofColor(0, 72, 23); // green
    typeClr1 = ofColor(229, 52, 31); // red
    
    // FBO to blend type
    fbo.allocate(800, 800, GL_RGBA);
    
    
    // useful if fbo is bigger than canvas
    float canvRatio = fbo.getWidth()/ofGetWidth();
    
    // y offset to account for line spacing
    float yOff = 6.375 * canvRatio;
    
    //    float alpha = ofMap(mouseX, 0, ofGetWidth(), 0, 255);
    float alpha = 255;
    
    // draw to fbo
    fbo.begin();
        ofEnableAlphaBlending();
        ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
        
        // purple text
        ofSetColor(typeClr3, alpha);
        ofPushMatrix();
        ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
        ofRotateDeg(180-45);
        font.drawStringAsShapes("MESSAGES", 326 * canvRatio-fbo.getWidth()/2, 556 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 579 * canvRatio-fbo.getWidth()/2, 462 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MESSAGES", -48 * canvRatio-fbo.getWidth()/2, 394 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 9 * canvRatio-fbo.getWidth()/2, 302 * canvRatio-fbo.getHeight()/2+yOff);
        ofPopMatrix();
        
        // green text
        ofSetColor(typeClr2, alpha);
        ofPushMatrix();
        ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
        ofRotateDeg(90-45);
        font.drawStringAsShapes("MESSAGES", 326 * canvRatio-fbo.getWidth()/2, 556 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 579 * canvRatio-fbo.getWidth()/2, 462 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MESSAGES", -48 * canvRatio-fbo.getWidth()/2, 394 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 9 * canvRatio-fbo.getWidth()/2, 302 * canvRatio-fbo.getHeight()/2+yOff);
        ofPopMatrix();
        
        // red text
        ofSetColor(typeClr1, alpha);
        ofPushMatrix();
        ofTranslate(fbo.getWidth()/2, fbo.getHeight()/2);
        ofRotateDeg(-45);
        font.drawStringAsShapes("MESSAGES", 326 * canvRatio - fbo.getWidth()/2, 556 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 579 * canvRatio - fbo.getWidth()/2, 462 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MESSAGES", -48 * canvRatio - fbo.getWidth()/2, 394 * canvRatio-fbo.getHeight()/2+yOff);
        font.drawStringAsShapes("MEANS", 9 * canvRatio - fbo.getWidth()/2, 302 * canvRatio-fbo.getHeight()/2+yOff);
        ofPopMatrix();
        
        ofDisableBlendMode();
    
    fbo.end();
    
    
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
    //    float lh = ofMap(mouseX, 0, ofGetWidth(), 0.0, 2.0);
    //    font.setLineHeight(lh);
    
    // back ground image for debug
    //    ofPushMatrix();
    //    ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
    //    ofRotateDeg(45);
    //
    //    debugImg.draw(-ofGetWidth()/2, -ofGetHeight()/2, ofGetWidth(), ofGetHeight());
    //    ofPopMatrix();
    
    // set bg color
    ofBackground(squareClr);
    
    // draw fbo
    ofPushMatrix();
        ofTranslate(ofGetWidth()/2, ofGetHeight()/2);
        fbo.draw(-ofGetWidth()/2,-ofGetHeight()/2);
    ofPopMatrix();
    
    // build frame
    ofSetColor(borderClr);
    float borderW = ofGetWidth() * (2.0/30.0);
    ofDrawRectangle(0, 0, ofGetWidth(), borderW);
    ofDrawRectangle(0, ofGetHeight()-borderW, ofGetWidth(), ofGetHeight());
    ofDrawRectangle(0, borderW, borderW, ofGetHeight()-borderW);
    ofDrawRectangle(ofGetWidth()-borderW, borderW, borderW, ofGetHeight()-borderW);
    
    
    // draw grid
    
    //    ofSetColor(0, 255, 0);
    //    ofNoFill();
    //
    //    float numRows = 10.0;
    //    float rectW = ofGetWidth()/numRows;
    //
    //
    //    // columns
    //    for (int i = 0; i < numRows; i++) {
    //        ofDrawRectangle(i*rectW, 0, rectW, ofGetHeight());
    //    }
    //
    //    // rows
    //    for (int i = 0; i < numRows; i++) {
    //        float rectW = ofGetWidth()/numRows;
    //        ofDrawRectangle(0, i*rectW, ofGetWidth(), rectW);
    //    }
    //
    
    // take a screenshot on run 
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
