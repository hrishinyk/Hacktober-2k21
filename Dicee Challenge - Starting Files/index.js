var randomNumber1 = Math.random()*6+1;
randomNumber1=Math.floor(randomNumber1);
var randomNumber2 = Math.random()*6+1;
randomNumber2=Math.floor(randomNumber2);
document.querySelector("img.img1").setAttribute("src","images/dice"+randomNumber1+".png");
document.querySelector("img.img2").setAttribute("src","images/dice"+randomNumber2+".png");

if(randomNumber1>randomNumber2){
    document.querySelector("h1").innerHTML= "Player 1 wins!";
}
else if(randomNumber1===randomNumber2){
    document.querySelector("h1").innerHTML= "Draw";
}
else{
    document.querySelector("h1").innerHTML= "Player 2 wins!";
}
