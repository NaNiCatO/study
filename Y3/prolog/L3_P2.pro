% Prime number check
isPrime(2) :- !.  % 2 is prime.
isPrime(N) :-
    N > 2,
    \+ hasFactor(N, 2).  % N is prime if no factors between 2 and sqrt(N).

% Check if N has a factor in the range [D, sqrt(N)].
hasFactor(N, D) :-
    D * D =< N,       % Stop if D^2 > N (no factors possible beyond sqrt(N)).
    N mod D =:= 0,    % N is divisible by D (hence not prime).
    !.
hasFactor(N, D) :-
    D * D =< N,       % Continue checking with D+1.
    D1 is D + 1,
    hasFactor(N, D1).
