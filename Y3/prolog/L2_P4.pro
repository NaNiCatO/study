% Base case: no more matches, return empty list of points.
calculate_points([], []).

% Recursive case: process each match.
calculate_points([match(Team1, Team2, Score1, Score2) | RestMatches], TeamsWithPoints) :-
    calculate_points(RestMatches, TempPoints),
    update_points(Team1, Score1, Score2, TempPoints, UpdatedPoints1),
    update_points(Team2, Score2, Score1, UpdatedPoints1, TeamsWithPoints).

% Helper predicate to update points for each team.
update_points(Team, Score1, Score2, PointsList, UpdatedPointsList) :-
    % Determine the points based on match outcome.
    ( Score1 > Score2 -> Points = 3;
      Score1 < Score2 -> Points = 0;
      Score1 =:= Score2 -> Points = 1 ),
    % Update the team's points in the list.
    ( select([Team, OldPoints], PointsList, Rest) ->
        NewPoints is OldPoints + Points,
        UpdatedPointsList = [[Team, NewPoints] | Rest];
        UpdatedPointsList = [[Team, Points] | PointsList]
    ).


sort_teams(TeamsWithPoints, SortedTeams) :-
    sort(2, @>=, TeamsWithPoints, SortedTeams).


main(SortedTeams) :-
    matches(Matches),
    calculate_points(Matches, TeamsWithPoints),
    sort_teams(TeamsWithPoints, SortedTeams).


matches([match('TeamA', 'TeamB', 2, 1), 
         match('TeamC', 'TeamD', 1, 1), 
         match('TeamA', 'TeamC', 0, 2), 
         match('TeamB', 'TeamD', 3, 3)]).
