function Alert(time, contents){
    this.time = time || "";
    this.contents = contents || "";
}

const alerts = [
    new Alert("09:00","Wake up"),
    new Alert("11:05","Lunch time"),
    new Alert("15:30","Take a break")
];

let alertsToShow;
var i;
function gen_data() {
    alerts.sort(function(a, b) {
        let timeA = a.time;
        let timeB = b.time;
        if (timeA < timeB) {
            return -1;
        }
        if (timeA > timeB) {
            return 1;
        }
        return 0;
    });

    const button = document.getElementById("action");
    button.innerHTML = "Edit";
    button.removeEventListener("click", edit_mode);
    button.addEventListener("click", edit_mode);

    const output = document.getElementById("timer");
    output.innerHTML = "";

    const tr = document.createElement("tr");
    const th_time = document.createElement("th");
    th_time.innerHTML = "Time";
    const th_content = document.createElement("th");
    th_content.innerHTML = "Alert Word";
    tr.appendChild(th_time);
    tr.appendChild(th_content);
    output.appendChild(tr);
    if(alerts.length != 0){
        for (i = 0; i < alerts.length; i++) {
            const member = alerts[i];
            const row = document.createElement("tr");
            const time = document.createElement("td");
            time.innerHTML = member.time;
            const content = document.createElement("td");
            content.innerHTML = member.contents;
            row.appendChild(time);
            row.appendChild(content);
            output.appendChild(row);
        }
    }
}



let hours = 8;
let minutes = 50;
let seconds = 0;
// Function to update the timer display
function updateTimer() {

    // Increment seconds by 1 (1000 times faster)
    seconds+=1;

    // Update minutes and reset seconds if necessary
    if (seconds >= 60) {
        minutes++;
        seconds = 0;
    }

    // Update hours and reset minutes if necessary
    if (minutes >= 60) {
        if((hours+1) == 24){
            hours = 0;
        } else{
            hours++;
        }
        minutes = 0;
    }

    // Format the time as HH:MM:SS
    const formattedTime = 
        String(hours).padStart(2, '0') + ':' +
        String(minutes).padStart(2, '0'); // Remove seconds from formattedTime

    // Display the formatted time
    document.getElementById('current').textContent = "Current Time (1000x faster): " + formattedTime;
    
    if(alerts.length > 0 ){
        for(let j = 0 ; j < alerts.length;j++){
            if(formattedTime == alerts[j].time && alertsToShow != alerts[j].time){
                alert(alerts[j].contents);
                alertsToShow = formattedTime;
            }
        }
    }
}
setInterval(updateTimer, 1);


function done_mode() {
    document.getElementById("adder").remove();
    const button = document.getElementById("action");
    button.innerHTML = "Edit";
    button.removeEventListener("click", done_mode);
    button.addEventListener("click", edit_mode);

    if(alerts.length > 0){
        for (i = 0; i < alerts.length; i++) {
            alerts[i].time = document.getElementById("time"+i).value;
            alerts[i].contents = document.getElementById("content"+i).value;
        }
    }
    // Call gen_data to regenerate the table with the updated alerts
    gen_data();
}



function edit_mode() {
    const button = document.getElementById("action");
    button.innerHTML = "Done";
    button.removeEventListener("click", edit_mode);
    button.addEventListener("click", done_mode);

    const output = document.getElementById("timer");
    output.innerHTML = "";

    for (i = 0; i < alerts.length; i++) {
        const member = alerts[i];
        const row = document.createElement("tr");
        row.id = "row"+i;

        const time = document.createElement("td");
        const input_time = document.createElement("input");
        input_time.type = "time";
        input_time.value = member.time;
        input_time.id = "time"+i;
        time.appendChild(input_time);

        const content = document.createElement("td");
        const input_content = document.createElement("input");
        input_content.type = "text";
        input_content.value = member.contents;
        input_content.id = "content"+i;
        content.appendChild(input_content);

        const remove_button = document.createElement("td");
        const re_button = document.createElement("button");
        re_button.innerHTML = "remove";
        re_button.id = i;
        re_button.addEventListener("click", remove_alert);
        remove_button.appendChild(re_button);


        row.appendChild(time);
        row.appendChild(content);
        row.appendChild(remove_button);
        output.appendChild(row);
    
    }
    const add_button = document.createElement("button");
    add_button.innerHTML = "ADD";
    add_button.id = "adder";
    add_button.addEventListener("click", add_alert);
    document.body.appendChild(add_button);
}

function add_alert(){
    alerts.push(new Alert);
    // document.getElementById("adder").remove();
    // edit_mode();
    const output = document.getElementById("timer");
    
    const row = document.createElement("tr");
    row.id = "row"+i;
    const time = document.createElement("td");
    const input_time = document.createElement("input");
    input_time.type = "time";
    input_time.id = "time"+i;
    time.appendChild(input_time);

    const content = document.createElement("td");
    const input_content = document.createElement("input");
    input_content.type = "text";
    input_content.id = "content"+i;
    content.appendChild(input_content);

    const remove_button = document.createElement("td");
    const re_button = document.createElement("button");
    re_button.innerHTML = "remove";
    re_button.id = i;
    re_button.addEventListener("click", remove_alert);
    remove_button.appendChild(re_button);

    row.appendChild(time);
    row.appendChild(content);
    row.appendChild(remove_button);
    output.appendChild(row);
    i++;    
}

function remove_alert(){
    var buttonId = this.id;
    alerts.splice(parseInt(buttonId),1);
    document.getElementById("adder").remove();
    edit_mode();
}

document.addEventListener("DOMContentLoaded", gen_data);
document.addEventListener("DOMContentLoaded", updateTimer);
