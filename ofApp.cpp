#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openFrameworks");

	ofBackground(39);
	ofSetColor(239);
	ofEnableDepthTest();
	ofSetLineWidth(1);
}

//--------------------------------------------------------------
void ofApp::update() {


}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateX(90);
	
	auto radius = 250;

	ofNoFill();
	ofSetColor(239);
	ofBeginShape();
	for (float theta_deg = 0; theta_deg < 180; theta_deg += 0.1) {

		auto phi_deg = ofMap(ofNoise(theta_deg * 0.015 + ofGetFrameNum() * 0.03), 0, 1, -360 * 5, 360 * 5);

		auto location = glm::vec3(
			radius * sin(theta_deg * DEG_TO_RAD) * cos(phi_deg * DEG_TO_RAD),
			radius * sin(theta_deg * DEG_TO_RAD) * sin(phi_deg * DEG_TO_RAD),
			radius * cos(theta_deg * DEG_TO_RAD));

		ofVertex(location);
	}
	ofEndShape();

	ofFill();
	ofSetColor(39);
	//ofDrawSphere(248);

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}