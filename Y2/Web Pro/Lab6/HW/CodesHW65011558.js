var year = 2023 ;
var month = 1 ;

function totheleft(){
    if(month > 1){
        month -= 1; 
        gen_calendar();
    }
}

function totheright(){
    if(month < 12){
        month += 1;
        gen_calendar();
    }
}

function gen_calendar(){
    document.body.innerHTML = "";
    const table = document.createElement("table");
    const tr = document.createElement("tr");

    const button_l = document.createElement("button");
    button_l.innerHTML = "<";
    button_l.onclick = totheleft;
    var td = document.createElement("td");
    td.className = "t_b";
    td.appendChild(button_l);
    tr.appendChild(td);

    const lable_ca = document.createTextNode(month+"/"+year);
    var td = document.createElement("td");
    td.appendChild(lable_ca);
    td.colSpan = 5;
    tr.appendChild(td);
    
    const button_r = document.createElement("button");
    button_r.innerHTML = ">";
    button_r.onclick = totheright;
    var td = document.createElement("td");
    td.className = "t_b";
    td.appendChild(button_r);
    tr.appendChild(td);

    table.appendChild(tr);

    const tr_days = document.createElement("tr");
    const day = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"];
    for(var i = 0; i < 7; i++){
        const td = document.createElement("td");
        td.innerHTML = day[i];
        tr_days.appendChild(td);
    }
    table.appendChild(tr_days);

    const current_month = new Date(year + "-" + month );
    const format_day = (current_month.getDay()+6)%7;
    const find_total_days = new Date(year, month, 0);
    const totalDays = find_total_days.getDate();

    for(var i = 1 - format_day; i <= totalDays;){
        const tr = document.createElement("tr");
        for(var j = 0; j < 7; j++){
            const td = document.createElement("td");
            if(i>0 && i <= totalDays){
                td.innerHTML = i ;
            }
            tr.appendChild(td);
            i++;
        }
        table.appendChild(tr);
    }


    document.body.appendChild(table);
}

document.addEventListener("DOMContentLoaded", gen_calendar)