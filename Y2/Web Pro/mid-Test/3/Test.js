function gen_table(){
    var date = ["Mon","Tue","Wed","Thu","Fri","Sat","Sun"]
    const table = document.createElement("table")
    table.border = "1px solid black"
    const th = document.createElement("th")
    th.colSpan = 7
    th.innerHTML = "August 2023"
    const tr = document.createElement("tr")
    tr.appendChild(th)
    table.appendChild(tr)

    const tr_date = document.createElement("tr")
    for(var i = 0; i<7; i++){
        const td_date = document.createElement("td")
        td_date.innerHTML = date[i]
        tr_date.appendChild(td_date)
    }
    table.appendChild(tr_date)

    var num_date = 31
    var current_date = 1
    for(var i = 1; current_date <= num_date;){
        const row_date = document.createElement("tr")
        for(var j = 0; j<7; j++){
            const col_date = document.createElement("td")
             if (current_date > num_date){
                break
            }else if(i != 1){ 
                col_date.innerHTML = current_date 
                current_date++
            } 
            row_date.appendChild(col_date)
            i++
        }
        table.appendChild(row_date)
    }
    
    
    
    
    document.body.appendChild(table)
}   
document.addEventListener("DOMContentLoaded", gen_table)