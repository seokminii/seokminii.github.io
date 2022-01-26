window.onload = function Check_the_value(){
    var target = new Array(15);
    
    Reset_Screen();
    
    for(i=1; i<15; i++){
        target[i] = document.getElementById(i).innerHTML;
        if(target[i] == 1){
            document.getElementById("t" + i).style.backgroundColor = "red";
        }
    }
    for(i=1; i<15; i++){
        document.getElementById("et" + i).style.display = "block";
    }
}

// 전역변수-1
var save_value_0 = 1;
var save_value_1 = 1;
var time_time = 650;
var time_limit = 10000;

var target_color_basic = "#D9CDBF";
var target_color_click = "#F2522E";

function Play_the_game(){
    var play_button = document.getElementById('a2');
    //alert(target_color_basic);
    document.getElementById("board").innerHTML = "0";
    //game_setting
    play_button.disabled = "disabled";
    Reset_Screen();

    //main logic
    var start_game = setInterval(() => { 
        document.getElementById("t"+save_value_1).style.backgroundColor=target_color_basic;//============================
        document.getElementById(save_value_1).innerHTML = "0";
        save_value_0 = getRandom();
        document.getElementById("t"+save_value_0).style.backgroundColor="orange";
        document.getElementById(save_value_0).innerHTML = "1";

        if(document.getElementById("t"+save_value_0).onclick == true){
            alert("asdjkfadklfhadk");
            //document.getElementById("t"+save_value_0).style.backgroundColor="black";
        }

        save_value_1 = save_value_0;
    }, time_time);

    //main logic end
    setTimeout(() => {
        Reset_Screen();
        clearInterval(start_game); alert("stop");
        play_button.disabled = false;
    }, time_limit);

    Timer();  
}
//----------------------------------------------------------------------------------
function Reset_Screen(){
    for(i=1; i<15; i++){
        document.getElementById("t" + i).style.backgroundColor = target_color_basic;//================================
    }
}
function getRandom(){
    var a1, a2, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12, a13, a14;
    var save_value = 0;

    //난이도1 : 속도 time_time = 700
    save_value = Math.floor(Math.random() * 5) + 1; //3 => 14

    //난이도3 : 속도 time_time = 600
    //save_value = Math.floor(Math.random() * 14) + 1;
    //return save_value;
    
    //난이도 1
    /*
    
    */
    switch (save_value){
        case 1 : return 1;  
        case 2 : return 2;
        case 3 : return 3;
        case 4 : return 6;
        case 5 : return 7;
    }
}
function Check_target(){
    if(document.getElementById("a1").innerHTML == "0"){
        for(i=1; i<15; i++){
            document.getElementById("t" + i).style.backgroundColor = "gray";
            document.getElementById("a1").innerHTML = "1";
        }
    }else {
        for(i=1; i<15; i++){
            document.getElementById("t" + i).style.backgroundColor = target_color_basic;//===================================
            document.getElementById("a1").innerHTML = "0";
        }
    }
}
function Timer(){
    var time = 10;          // <= timer time
    var min = "";
    var sec = "";
    time--;
    var game_timer = setInterval(function() {
        min = parseInt(time/60);
        sec = time%60;
        if(min <= 0){
            min = 0;
        }
        document.getElementById("timer").innerHTML = min + " min " + sec + " sec ";
        time--;
        if(time < 0){
            clearInterval(game_timer);
            document.getElementById("timer").innerHTML = "time out!!!";
        }
    }, 1000);
}
//전역변수 - 2 <== click_all에 만 해당

function Click_All(get_id){
    var save_learder_value;
    var temp_2;
    var target_id = document.getElementById(get_id);

    document.getElementById(get_id).disabled = "disabled";

    if(target_id.style.backgroundColor=="orange"){
        
        target_id.disabled = "disabled";
        target_id.style.backgroundColor="black";
        
        //leader borad
        save_learder_value = parseInt(document.getElementById("board").innerHTML);
        save_learder_value += 1000;
        document.getElementById("board").innerHTML = save_learder_value;

        //document.getElementById(temp_2).style.display = "block";
        //document.getElementById("e"+get_id).style.display = "none";
        document.getElementById("e"+get_id).innerHTML = save_learder_value;
        temp_2 = "e" + get_id;
        temp_reset();

        temp = get_id;       
    }  
    setTimeout(() => {
        target_id.disabled = false;
    }, time_time - 100);

}

function temp_reset(){
    for(i=1; i<15; i++){
        document.getElementById("et" + i).innerHTML = " ";
    }
}