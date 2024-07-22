import java.util.Scanner;

public class MusicPlayerFSM {
    enum State {
        INTRO, STARMAN, SHOW_MUST_GO_ON, LET_IT_BE, IN_THE_END
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        State currentState = State.INTRO;
        
        while (true) {
            System.out.println("Current song: " + getSong(currentState));
            System.out.print("Enter command (sad, fun, silly, dangerous): ");
            String command = scanner.nextLine().trim().toLowerCase();

            State nextState = getNextState(currentState, command);
            if (nextState == State.IN_THE_END) {
                System.out.println("Current song: " + getSong(nextState));
                System.out.println("Program terminating.");
                break;
            }

            currentState = nextState;
        }

        scanner.close();
    }

    private static String getSong(State state) {
        switch (state) {
            case INTRO: return "Intro";
            case STARMAN: return "Starman";
            case SHOW_MUST_GO_ON: return "Show must go on";
            case LET_IT_BE: return "Let it be";
            case IN_THE_END: return "But in the end, it doesn't even matter";
            default: throw new IllegalStateException("Unexpected state: " + state);
        }
    }

    private static State getNextState(State currentState, String command) {
        switch (currentState) {
            case INTRO:
                if ("dangerous".equals(command)) return State.LET_IT_BE;
                if ("fun".equals(command)) return State.STARMAN;
                if ("sad".equals(command)) return State.IN_THE_END;
                return State.INTRO;

            case STARMAN:
                if ("silly".equals(command)) return State.INTRO;
                if ("dangerous".equals(command)) return State.SHOW_MUST_GO_ON;
                if ("fun".equals(command)) return State.IN_THE_END;
                return State.STARMAN;

            case SHOW_MUST_GO_ON:
                if ("sad".equals(command)) return State.LET_IT_BE;
                if ("fun".equals(command)) return State.STARMAN;
                return State.SHOW_MUST_GO_ON;

            case LET_IT_BE:
                if ("dangerous".equals(command)) return State.INTRO;
                if ("silly".equals(command)) return State.SHOW_MUST_GO_ON;
                return State.LET_IT_BE;

            case IN_THE_END:
                return State.IN_THE_END;

            default:
                throw new IllegalStateException("Unexpected state: " + currentState);
        }
    }
}
