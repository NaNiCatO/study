% Adding Facts
male(john).
male(oliver).
male(ali).
male(james).
male(jack).
male(harry).

female(helen).
female(sophie).
female(mary).
female(sue).

parent(john, mary).
parent(john, sue).
parent(helen, mary).
parent(helen, sue).
parent(oliver, james).
parent(sophie, james).
parent(mary, jack).
parent(ali, jack).
parent(sue, harry).
parent(james, harry).

mother(X, Y) :- female(X), parent(X, Y).
father(X, Y) :- male(X), parent(X, Y).
granfather(X, Y) :- father(X, Z), parent(Z, Y).
granmother(X, Y) :- mother(X, Z), parent(Z, Y).

sister(X, Y) :- female(X), parent(Z, X), parent(Z, Y), X \= Y.
brother(X, Y) :- male(X), parent(Z, X), parent(Z, Y), X \= Y.
sibling(X, Y) :- parent(Z, X), parent(Z, Y), X \= Y.
uncle(X, Y) :- male(X), sibling(X, Z), parent(Z, Y).
aunt(X, Y) :- female(X), sibling(X, Z), parent(Z, Y).

%sister(X, mary), parent(Y, mary).
%parent(_, X).
%sister(X, _).