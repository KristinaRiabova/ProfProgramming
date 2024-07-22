import java.util.*;

class Team {
    private String name;
    private int goalsScored;
    private int yellowCards;
    private int redCards;
    private double topHeight;

    public Team(String name) {
        this.name = name;
        this.goalsScored = 0;
        this.yellowCards = 0;
        this.redCards = 0;
        this.topHeight = 0.0;
    }

    public String getName() {
        return name;
    }

    public int getGoalsScored() {
        return goalsScored;
    }

    public int getYellowCards() {
        return yellowCards;
    }

    public int getRedCards() {
        return redCards;
    }

    public double getTopHeight() {
        return topHeight;
    }

    public void scoreGoal(int goals) {
        this.goalsScored += goals;
    }

    public void receiveYellowCard() {
        this.yellowCards++;
    }

    public void receiveRedCard() {
        this.redCards++;
    }

    public void setTopHeight(double height) {
        this.topHeight = Math.max(this.topHeight, height);
    }
}

class Match {
    private Team team1;
    private Team team2;
    private int goalsTeam1;
    private int goalsTeam2;
    private double topHeightTeam1;
    private double topHeightTeam2;

    public Match(Team team1, Team team2) {
        this.team1 = team1;
        this.team2 = team2;
        this.goalsTeam1 = 0;
        this.goalsTeam2 = 0;
        this.topHeightTeam1 = 0.0;
        this.topHeightTeam2 = 0.0;
    }

    public void playMatch() {
        Random rand = new Random();

        this.goalsTeam1 = rand.nextInt(5);
        this.goalsTeam2 = rand.nextInt(5);

        this.topHeightTeam1 = rand.nextDouble() * 3;
        this.topHeightTeam2 = rand.nextDouble() * 3;

        team1.scoreGoal(goalsTeam1);
        team2.scoreGoal(goalsTeam2);
        team1.setTopHeight(topHeightTeam1);
        team2.setTopHeight(topHeightTeam2);
    }

    public int getGoalsTeam1() {
        return goalsTeam1;
    }

    public int getGoalsTeam2() {
        return goalsTeam2;
    }

    public double getTopHeightTeam1() {
        return topHeightTeam1;
    }

    public double getTopHeightTeam2() {
        return topHeightTeam2;
    }

    public Team getTeam1() {
        return team1;
    }

    public Team getTeam2() {
        return team2;
    }
}

class Tournament {
    private List<Team> teams;
    private List<Match> matches;
    private Map<String, Double> points;
    private Map<String, Integer> goalsDelta;
    private Map<String, Integer> goalsScored;
    private Map<String, Integer> redCards;
    private Map<String, Integer> yellowCards;
    private Map<String, Double> topHeights;

    public Tournament(List<String> teamNames) {
        this.teams = new ArrayList<>();
        this.matches = new ArrayList<>();
        this.points = new HashMap<>();
        this.goalsDelta = new HashMap<>();
        this.goalsScored = new HashMap<>();
        this.redCards = new HashMap<>();
        this.yellowCards = new HashMap<>();
        this.topHeights = new HashMap<>();

        for (String name : teamNames) {
            Team team = new Team(name);
            teams.add(team);
            points.put(name, 0.0);
            goalsDelta.put(name, 0);
            goalsScored.put(name, 0);
            redCards.put(name, 0);
            yellowCards.put(name, 0);
            topHeights.put(name, 0.0);
        }

        for (int i = 0; i < teams.size(); i++) {
            for (int j = i + 1; j < teams.size(); j++) {
                matches.add(new Match(teams.get(i), teams.get(j)));
            }
        }
    }

    public void playTournament() {
        for (Match match : matches) {
            match.playMatch();
            updateStatistics(match);
        }

        calculatePoints();
    }

    public void printResults() {
        List<Team> sortedTeams = new ArrayList<>(teams);
        sortedTeams.sort((t1, t2) -> {
            if (points.get(t1.getName()) != points.get(t2.getName())) {
                return Double.compare(points.get(t2.getName()), points.get(t1.getName()));
            } else if (!goalsDelta.get(t1.getName()).equals(goalsDelta.get(t2.getName()))) {
                return Integer.compare(goalsDelta.get(t2.getName()), goalsDelta.get(t1.getName()));
            } else if (!goalsScored.get(t1.getName()).equals(goalsScored.get(t2.getName()))) {
                return Integer.compare(goalsScored.get(t2.getName()), goalsScored.get(t1.getName()));
            } else if (!redCards.get(t1.getName()).equals(redCards.get(t2.getName()))) {
                return Integer.compare(redCards.get(t1.getName()), redCards.get(t2.getName()));
            } else if (!yellowCards.get(t1.getName()).equals(yellowCards.get(t2.getName()))) {
                return Integer.compare(yellowCards.get(t1.getName()), yellowCards.get(t2.getName()));
            } else {
                return Double.compare(topHeights.get(t2.getName()), topHeights.get(t1.getName()));
            }
        });

        sortedTeams.removeIf(team -> team.getName().equalsIgnoreCase("russia"));
        sortedTeams.add(new Team("russia"));

        System.out.println("Final Tournament Results:");
        System.out.println("| Team Name | Points | Goals Delta | Goals Scored | Red Cards | Yellow Cards | Top Heights |");

        for (Team team : sortedTeams) {
            System.out.printf("| %s | %.2f | %d | %d | %d | %d | %.2f |\n",
                    team.getName(), points.get(team.getName()), goalsDelta.get(team.getName()),
                    goalsScored.get(team.getName()), redCards.get(team.getName()), yellowCards.get(team.getName()),
                    topHeights.get(team.getName()));
        }
    }

    private void updateStatistics(Match match) {
        Team team1 = match.getTeam1();
        Team team2 = match.getTeam2();

        goalsScored.put(team1.getName(), goalsScored.get(team1.getName()) + match.getGoalsTeam1());
        goalsScored.put(team2.getName(), goalsScored.get(team2.getName()) + match.getGoalsTeam2());

        goalsDelta.put(team1.getName(), goalsDelta.get(team1.getName()) + (match.getGoalsTeam1() - match.getGoalsTeam2()));
        goalsDelta.put(team2.getName(), goalsDelta.get(team2.getName()) + (match.getGoalsTeam2() - match.getGoalsTeam1()));

        redCards.put(team1.getName(), redCards.get(team1.getName()) + team1.getRedCards());
        redCards.put(team2.getName(), redCards.get(team2.getName()) + team2.getRedCards());

        yellowCards.put(team1.getName(), yellowCards.get(team1.getName()) + team1.getYellowCards());
        yellowCards.put(team2.getName(), yellowCards.get(team2.getName()) + team2.getYellowCards());

        topHeights.put(team1.getName(), topHeights.get(team1.getName()) + match.getTopHeightTeam1());
        topHeights.put(team2.getName(), topHeights.get(team2.getName()) + match.getTopHeightTeam2());
    }

    private void calculatePoints() {
        for (Team team : teams) {
            points.put(team.getName(), calculateTeamPoints(team));
        }
    }

    private double calculateTeamPoints(Team team) {
        return pointsForWinLossDraw(goalsDelta.get(team.getName())) +
                goalsScored.get(team.getName()) +
                (redCards.get(team.getName()) * -1) +
                (yellowCards.get(team.getName()) * -1) +
                topHeights.get(team.getName());
    }

    private double pointsForWinLossDraw(int deltaGoals) {
        if (deltaGoals > 0) {
            return 3.14; 
        } else if (deltaGoals == 0) {
            return 2.71828; 
        } else {
            return -0.5; 
        }
    }

    public static void main(String[] args) {
        Random rand = new Random();
        rand.setSeed(System.currentTimeMillis());

        List<String> teamNames = Arrays.asList("Team1", "Team2", "Team3", "russia");
        Tournament tournament = new Tournament(teamNames);

        tournament.playTournament();
        tournament.printResults();
    }
}
