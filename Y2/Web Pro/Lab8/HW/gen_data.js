function Grading(grade) {
    switch (grade.toUpperCase()) {
        case "A":
            return 4.0;
        case "B+":
            return 3.5;
        case "B":
            return 3.0;
        case "C+":
            return 2.5;
        case "C":
            return 2.0;
        case "D+":
            return 1.5;
        case "D":
            return 1.0;
        case "F":
            return 0.0;
        default:
            return NaN; // Invalid grade
    }
}




document.addEventListener("DOMContentLoaded", function () {
    const fileInput = document.getElementById("fileInput");

    // Add an event listener to the file input
    fileInput.addEventListener("change", function (event) {
        const file = event.target.files[0];

        if (file) {
            const reader = new FileReader();

            reader.onload = function (e) {
                const content = e.target.result;
                const data = JSON.parse(content);

                // Populate the form fields with the data
                document.getElementById("student_name").value = data.student_name;
                document.getElementById("date_of_birth").value = data.date_of_birth;
                document.getElementById("student_id").value = data.student_id;
                document.getElementById("date_of_admission").value = data.date_of_admission;
                document.getElementById("date_of_graduation").value = data.date_of_graduation;
                document.getElementById("degree").value = data.degree;
                document.getElementById("major").value = data.major;

                // Handle credit data if needed
                // ...
                const output = document.getElementById("content_body");
                output.innerHTML = '';
                var num_semester = 0;
                var GPS = 0.0;
                var total_GPS = 0.0;
                for (const year in data.credit) {
                    const semesters = data.credit[year];
                    for (const semester in semesters) {
                        num_semester += 1;
                        const tr_sem = document.createElement("tr");
                        const td_sem = document.createElement("td");
                        td_sem.style.fontWeight = "bold";
                        td_sem.style.textDecoration = "underline";
                        td_sem.innerHTML = semester + year;
                        const td_empty1 = document.createElement("td");
                        const td_empty2 = document.createElement("td");

                        tr_sem.appendChild(td_sem);
                        tr_sem.appendChild(td_empty1);
                        tr_sem.appendChild(td_empty2);
                    
                        output.appendChild(tr_sem);

                        
                        var total_point = 0.0;
                        var total_credit = 0.0;
                        const contents = data.credit[year][semester];
                        for (const content of contents){
                            const tr = document.createElement("tr");
                            const td_name = document.createElement("td");
                            td_name.innerHTML = content.subject_id + ' ' +content.name;
                            td_name.style.textAlign = "left" ;
                            const td_credit = document.createElement("td");
                            td_credit.innerHTML = content.credit;
                            const td_grade = document.createElement("td");
                            td_grade.innerHTML = content.grade;
                            tr.appendChild(td_name);
                            tr.appendChild(td_credit);
                            tr.appendChild(td_grade);
                            output.appendChild(tr);

                            total_point += Grading(content.grade)*parseFloat(content.credit);
                            total_credit += parseFloat(content.credit);
                        }
                        
                        GPS = (total_point / total_credit);
                        total_GPS += GPS ;
                        const GPA = total_GPS / num_semester;
                        const tr_gp = document.createElement("tr");
                        const td_gp = document.createElement("td");
                        td_gp.innerHTML = "GPS: " + GPS.toFixed(2) + "\tGPA: " + GPA.toFixed(2);
                        td_gp.style.fontStyle = "italic" ;
                        const td_empty3 = document.createElement("td");
                        const td_empty4 = document.createElement("td");

                        tr_gp.appendChild(td_gp);
                        tr_gp.appendChild(td_empty3);
                        tr_gp.appendChild(td_empty4);
                        output.appendChild(tr_gp);
                    }

                    }

                alert("Transcript imported successfully.");
            };

            reader.readAsText(file);
        }
    });
});


