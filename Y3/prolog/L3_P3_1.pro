% Base case: if the size is 0 or less, there are no steps.
drawTree(N, []) :- 
    N =< 10, !.

% Recursive case: generate the list of instructions for a tree of size S.
drawTree(S, L) :-
    S > 10,
    S1 is S / 2,                  % Decrease size for recursion
    drawTree(S1, L1),             % Recursive call for smaller tree

    % Construct the list of instructions
    L_init = [lt(90), fd(S), lt(30) | L1],     % Move forward and turn left
    append(L_init, [rt(60)], L2),      % Turn right
    append(L2, L1, L3),           % Append the instructions from recursion
    append(L3, [lt(30), backward(S)], L).  % Turn left and move backward 