// https://yoppa.org/ma2_10/1739.html マウスドラッグ、マウスボタンプレス
// https://forum.openframeworks.cc/t/ofxcolorpicker-missing-argument-list/35497 GUI ColorPicker
// https://www.ei.tohoku.ac.jp/xkozima/lab/ofTutorial4.html 文字の縁どり

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(24);
    output.setName("Main");
    
    //バックグランドを透明色に設定
    ofBackground(0, 0);
    
    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    
    fontText.load("Lato-Regular.ttf", 50); // フォントのデータを指定する
    fontText.setLineHeight(24);       // 行間を指定する
    fontText.setLetterSpacing(1.0);   // 文字間を指定する
    
    // GUI
    gui.setup();
    gui.add(slider.setup("slider", 50, 0, 255));
    gui.add(color.set("color", ofColor(255, 255, 0)));
}

//--------------------------------------------------------------
void ofApp::update(){
    //現在時刻の取得
    int s = ofGetSeconds();
    int m = ofGetMinutes();
    int h = ofGetHours();
    int d = ofGetDay();
    int month = ofGetMonth();
    int y = ofGetYear();
    
    //文字で表示する
    ofSetColor(255, 255, 255);
    dateTime = ofToString(y, 0) + "/" + ofToString(month, 0) + "/" + ofToString(d, 0) + "  " + ofToString(h, 0) + ":" + paddingNumberToString(m) + ":" + paddingNumberToString(s);
}

//--------------------------------------------------------------
void ofApp::draw(){

    ofSetColor(color); // 文字色を指定
    fontText.drawString(dateTime, px, py); // 文字とポジションを指定して描画

    //ここで送信している
    output.publishScreen();
    
    gui.draw();
}

//--------------------------------------------------------------
void ofApp::exit(){

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
    px = x;
    py = y;
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    px = x;
    py = y;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseScrolled(int x, int y, float scrollX, float scrollY){

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

string ofApp::paddingNumberToString(int i){
    switch (i) {
        case 0:
            return "00";
        case 1:
            return "01";
        case 2:
            return "02";
        case 3:
            return "03";
        case 4:
            return "04";
        case 5:
            return "05";
        case 6:
            return "06";
        case 7:
            return "07";
        case 8:
            return "08";
        case 9:
            return "09";
        default:
            return ofToString(i, 0);
    }
}
