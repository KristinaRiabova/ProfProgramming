**TASK. Football tournament**

We want to implement a simple program that will allow to handle football tournament with 4 teams.
1. Each team plays a match with each other.
2. Match between Team1 and Team2 should be tracked by a program with the following data for both Team1 and Team2: Team name, goals scored by Team, yellow cards shown to Team, red cards shown to Team and the top height reached by the ball after the kick of player from the Team.
3. Win is 3.14 points, draw is 2,71828 points, loose is -0.5 points.
The program should determine the ranking of the team after the tournament based on the following criteria list - in case of :
a. Sum of the points gained during tournament.
b. Bigger total sum of top heights during tournament(also known as "Хто вище б'є - той краще грає").
c. Delta between scored and missed goals.
d. Bigger total count of scored goals.
e. Less count of red cards.
f. Less count of yellow cards.
g. Random choice.

Use OOP and ranges library to implement console program that will prompt for 4 team names and then for results of 6 matches between them. As a result program should print the result table with a reference to the criteria based on which the place of the team was chosen(points, goals delta, goals scored, less red, less yellow, higher kicks, saint random).
