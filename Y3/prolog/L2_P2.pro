child(mary, john).
child(lisa, mary).
child(kevin, lisa).

descendant(X, Y) :- child(X, Y).
descendant(X, Z) :- child(X, Y), descendant(Y, Z).

