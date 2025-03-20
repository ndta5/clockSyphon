// https://yoppa.org/ma2_10/1739.html マウスドラッグ、マウスボタンプレス
// https://forum.openframeworks.cc/t/ofxcolorpicker-missing-argument-list/35497 GUI ColorPicker
// https://www.ei.tohoku.ac.jp/xkozima/lab/ofTutorial4.html 文字の縁どり

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    ofSetFrameRate(24);
    output.setName("clockSyphon");
    
    //バックグランドを透明色に設定
    ofBackground(0, 0);
    
    // https://forum.openframeworks.cc/t/set-window-title/6470/3 ウィンドウにタイトルを表示
    ofSetWindowTitle("clockSyphon");

    // Fonts
    ofTrueTypeFont::setGlobalDpi(72);
    
    fontText.load("Lato-Regular.ttf", 50); // フォントのデータを指定する
    fontText.setLineHeight(24);       // 行間を指定する
    fontText.setLetterSpacing(1.0);   // 文字間を指定する
    
    // GUI
    gui.setup();
    gui.add(fontSizeSlider.setup("Font size", 50, 10, 255));
    gui.add(subSecToggle.setup("Show sub sec", true));
    gui.add(weekToggle.setup("Show week", true));
    gui.add(color.set("color", ofColor(255, 255, 0)));
}

std::string get_time_string(bool subSec, bool week) {
    // 現在時刻を取得
    auto now = std::chrono::system_clock::now();
    auto time = std::chrono::system_clock::to_time_t(now);
    std::tm local_time = *std::localtime(&time);

    // 1/100秒を取得
    auto centiseconds = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()).count() % 1000 / 10;

    // stringstreamで文字列を構築
    std::stringstream ss;
    // 曜日を表示するか選択
    if (week == true) {
        ss << std::put_time(&local_time, "%Y/%m/%d(%a)");
    }else{
        ss << std::put_time(&local_time, "%Y/%m/%d");
    }
    ss << std::put_time(&local_time, " %H:%M:%S");
    // 1/100秒を表示するか選択
    if (subSec == true) {
        ss << "." << std::setfill('0') << std::setw(2) << centiseconds;
    }

    return ss.str();
}

//--------------------------------------------------------------
void ofApp::update(){

    dateTime = get_time_string(subSecToggle, weekToggle);
    
    if(fontSize != fontSizeSlider){
        fontSize = fontSizeSlider;
        fontText.load("Lato-Regular.ttf", fontSize);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    ofSetColor(50, 50, 50);
    for (int y = -3; y < 3; y++) {
        for (int x = -3; x < 3; x++) {
            fontText.drawString(dateTime, px + x, py + y );
        }
    }
    ofSetColor(color);
    fontText.drawString(dateTime, px, py);

    //ここでSyphon送信
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
