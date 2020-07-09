// Copyright (c) 2019 ml5
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

/* ===
ml5 Example
PoseNet example using p5.js
=== */

let video;
let poseNet;
let poses = [];

let walk = false;
let rightEye = { x: 0, y: 0 };
let oldEye = { x: 0, y: 0 };
let walkStarted = false;
let walkers = [];
const rectSize = 5;

function setup() {
  createCanvas(640, 480);
  video = createCapture(VIDEO);
  video.size(width, height);

  // Create a new poseNet method with a single detection
  poseNet = ml5.poseNet(video, modelReady);
  // This sets up an event that fills the global variable "poses"
  // with an array every time new poses are detected
  poseNet.on("pose", function (results) {
    poses = results;
  });
  // Hide the video element, and just show the canvas
  video.hide();
}

function modelReady() {
  select("#status").html("Model Loaded");
}

function mousePressed() {
  console.log(JSON.stringify(poses));
}

function draw() {
  // tint(255, 10, 10);
  // filter(GRAY);
  image(video, 0, 0, width, height);
  strokeWeight(2);

  // For one pose only (use a for loop for multiple poses!)
  if (poses.length > 0) {
    let pose = poses[0].pose;

    // // Create a pink ellipse for the nose
    // fill(213, 0, 143);
    // let nose = pose['nose'];
    // ellipse(nose.x, nose.y, 20, 20);

    // Create a pink ellipse for the nose
    // fill(213, 0, 143);
    rightEye = pose["rightEye"];
    // ellipse(rightEye.x, rightEye.y, 20, 20);

    if (!walk) walk = true;
  }

  let d = dist(oldEye.x, oldEye.y, rightEye.x, rightEye.y);

  if (d > 25) {
    let newWalker = new Walker(rightEye);

    walkers.push(newWalker);
    oldEye = rightEye;
  }

  if (walk) {
    for (let i = 0; i < walkers.length; i++) {
      walkers[i].walk();
      walkers[i].run();
    }
  }
}

class Walker {
  constructor(_startPos) {
    console.log("new walker");
    this.startPos = _startPos;
    this.positions = [];
    this.x = this.startPos.x;
    this.y = this.startPos.y;

    this.positions.push(this.startPos);
  }

  walk() {
    const r = floor(random(4));
    switch (r) {
      case 0:
        this.x = this.x + rectSize;
        break;
      case 1:
        this.x = this.x - rectSize;
        break;
      case 2:
        this.y = this.y + rectSize;
        break;
      case 3:
        this.y = this.y - rectSize;
        break;
    }
    let newPos = { x: this.x, y: this.y };
    this.positions.push(newPos);
  }

  run() {
    stroke(255, 50);
    fill(25, 50);
    for (let i = 0; i < this.positions.length; i++) {
      // console.log("drawing at ", this.positions[i].x, this.positions[i].y);
      rect(this.positions[i].x, this.positions[i].y, rectSize, rectSize);
    }
  }
}
