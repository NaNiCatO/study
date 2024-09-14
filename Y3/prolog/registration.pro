% Students
student(john, 2, se).
student(mary, 2, se).
student(susan, 1, se).
student(david, 3, se).

% Courses
course(math101, 1, se).
course(cal102, 1, se).
course(cs102, 2, se).
course(art103, 2, se).
course(ai203, 3, se).
course(networks204, 3, se).

% Completed courses
completed(john, math101).
completed(john, cal102).
completed(mary, math101).
completed(david, cs102).

% Course prerequisites
requires(cs102, math101).
requires(cs102, cal102).
requires(ai203, cs102).

% Rules
can_enroll(Student, Course) :-
    student(Student, Year_of_study, Program),
    course(Course, Year_of_study, Program),
    \+ (requires(Course, Prerequisite), \+ completed(Student, Prerequisite)).

classmate(StudentA, StudentB) :-
    student(StudentA, Year_of_study, Study_Program),
    student(StudentB, Year_of_study, Study_Program),
    StudentA \= StudentB.
