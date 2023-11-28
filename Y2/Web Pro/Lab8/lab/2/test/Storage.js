function Alert(time, contents){
    this.time = time || "";
    this.contents = contents || "";
}

let alerts = [];

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
    document.getElementById("insert").appendChild(add_button);
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

function exportSchedule() {
    const dataStr = "data:text/json;charset=utf-8," + encodeURIComponent(JSON.stringify(alerts));
    const downloadAnchorNode = document.createElement('a');
    downloadAnchorNode.setAttribute("href", dataStr);
    downloadAnchorNode.setAttribute("download", "schedule.json");
    document.body.appendChild(downloadAnchorNode); // required for firefox
    downloadAnchorNode.click();
    downloadAnchorNode.remove();
}
document.getElementById("exportBtn").addEventListener("click", exportSchedule);


function importSchedule(event) {
    const file = event.target.files[0];
    if (file) {
        const reader = new FileReader();
        reader.onload = function (e) {
            const content = e.target.result;
            try {
                alerts = JSON.parse(content);
                gen_data();
            } catch (error) {
                alert("Error reading the file!");
            }
        };
        reader.readAsText(file);
    }
}

document.getElementById("importFile").addEventListener("change", importSchedule);
document.getElementById("importBtn").addEventListener("click", function () {
    document.getElementById("importFile").click();
});


function saveSchedule() {
    const selectedDate = document.getElementById("selectDate").value;
    if (selectedDate) {
        localStorage.setItem(selectedDate, JSON.stringify(alerts));
        alert("Schedule saved!");
    } else {
        alert("Please select a date!");
    }
}

document.getElementById("saveBtn").addEventListener("click", saveSchedule);


function loadScheduleForSelectedDate() {
    const selectedDate = document.getElementById("selectDate").value;
    const storedData = localStorage.getItem(selectedDate);

    if (storedData) {
        alerts = JSON.parse(storedData);
    } else {
        alerts = []; // Reset to an empty array
    }

    gen_data();
    // Then proceed with either viewing or editing
    console.log('Loading schedule for date:', selectedDate, 'Data:', storedData);

}


document.getElementById("selectDate").addEventListener("change", loadScheduleForSelectedDate);


document.getElementById("clearStorageBtn").addEventListener("click", function () {
    localStorage.clear();
    alert("Local storage cleared!");

    // Update the UI if necessary. For example:
    alerts = [];
});

document.addEventListener("DOMContentLoaded", gen_data);
