#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    
    ofBackground(249,255);//249
    model.loadModel("anklehang.obj");
    mesh = model.getMesh(0);
    mesh.enableColors();
    
    // try out different mesh modes
//    mesh.setMode(OF_PRIMITIVE_TRIANGLE_FAN); // funky
//    mesh.setMode(OF_PRIMITIVE_LINES); // more normal
//    mesh.setMode(OF_PRIMITIVE_TRIANGLES); // most normal
//        mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP); // more normal
        mesh.setMode(OF_PRIMITIVE_LINES); // more normal
//    mesh.setMode(OF_PRIMITIVE_LINE_STRIP); // more normal
//    mesh.setMode(OF_PRIMITIVE_LINE_LOOP); // more normal
//    mesh.setMode(OF_PRIMITIVE_POINTS); // more normal
    
    
    // use two meshes for faster processing. still not sure why this works
    // see https://openframeworks.cc/ofBook/chapters/advanced_graphics.html
    
    mesh2 = mesh;
    mesh2.enableColors();

    int numVerts = mesh.getNumVertices();
    cout << numVerts << endl;

    // look into lighting
    light.setPosition(0, 0, 500);
    
    cameraOrbit = 185;
    cameraLat = 376;
    cam.setDistance(26);

        for (int i =0; i < mesh.getNumVertices(); i++) {
            // ofSetColor will set a solid color for the mesh
            // to color individual lines,
            // play with different color generation here
            // also, try out off white color pallette
            // https://www.color-hex.com/color-palette/23730
            mesh.getVertices()[i].x+=ofRandom(-.01,.01);
            ofColor c = ofColor::fromHsb(ofRandom(180.0, 255.0), 50.0, 255.0);

            mesh.addColor(ofColor(c));

            mesh2.getVertices()[i].x=mesh.getVertices()[i].x + ofRandom(-.01,.01);
            mesh2.addColor(ofColor(c));
        }
    
//    mesh.enableColors();
//    ofSetColor(255, 0, 0);
    

}

//--------------------------------------------------------------
void ofApp::update(){
//  cameraOrbit = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 360);
//    cameraLat = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 360.0);
  
//    cameraOrbit += ofGetLastFrameTime() * 20.; // 20 degrees per second;
    cam.orbitDeg(cameraOrbit, cameraLat, cam.getDistance(), {0., 0., 0.});
    
//    cout << cameraOrbit << ", " << cameraLat << endl;

    for (int i =0; i < mesh.getNumVertices(); i++) {
        
        // need to find more interesting movements, random is not good
        mesh.getVertices()[i].x+=ofRandom(-.01,.01);
//        mesh.addColor(ofColor(ofRandom(255)));

        mesh2.getVertices()[i].x=mesh.getVertices()[i].x + ofRandom(-.01,.01);
//        mesh2.setColor(i, ofColor(ofRandom(255)));

        
    }
//    mesh.getVertices()[1].x+=0.1;
//    mesh2.getVertices()[1].x=mesh.getVertices()[1].x + 0.1;
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofEnableDepthTest();
    light.enable();
    cam.begin();
    
//    float h = ofMap(ofGetMouseX(), 0, ofGetWidth(), 0, 255);
//    float s = ofMap(ofGetMouseY(), 0, ofGetHeight(), 0, 255);
//    cout << h << ", " << s << endl;
//    ofColor c = ofColor::fromHsb(h, s, 255);
//      ofColor c = ofColor::fromHsb(0, 0, 255);
    
    
//    ofSetColor(c);
//    ofSetColor(249,241,241); // off white pink
//    ofSetColor(232,199,208);
    
//    ofPushMatrix();
//    ofTranslate(0,0,0);
//    ofRotateDeg(180);
    
//    ofSetColor(128,210,210); // nice blue
//    ofSetColor(128,s,s);
//    ofSetColor(255,76,88);
//    ofSetColor(95,76,88);
//        ofColor(255,255);
//        mesh.draw();
    mesh2.draw();
//    mesh.drawFaces();
//    ofPopMatrix();
    
    cam.end();
    light.disable();
    ofDisableDepthTest();
    
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    ss.take();
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
