let port; 
let connectBtn;
let filteredData1 = 0;
let filteredData2 = 0;
let val = 0;
let myVal = 0;


function setup() {
  createCanvas(windowHeight,windowWidth);
  //background("white");
  port = createSerial();

  connectBtn = createButton('Connect to Arduino');
  connectBtn.position(20, 20);
  connectBtn.mousePressed(connectBtnClick);

}

function draw() {
  background("white");
 
  let filteredData1 = port.readUntil("\n"); //read each line
  let filteredData2 = port.readUntil("\n"); 

  if (filteredData1.length > 0) {
   val = filteredData1; 
   // Update circle size with new value
   textSize(40);
   fill("#C70039");
   text(val, 20, 100);
  }

  stroke("#C70039");
  noFill();
  circle(400, 400, val);

   if (filteredData2.length > 0) {
    myVal = filteredData2; 
    // Update circle size with new value
    textSize(40);
    fill("blue");
    text(myVal, 20, 150); 
   }
   stroke("blue");
   noFill();
   circle(400,400,myVal);
  
   console.log(filteredData1);
   console.log(filteredData2);
 }

function connectBtnClick() {
  if (!port.opened()) {
    port.open('Arduino', 9600);
  } else {
    port.close();
  }
}