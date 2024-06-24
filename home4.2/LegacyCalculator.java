public class LegacyCalculator {
    private double megaDelta;
    private double megaMultiplier;
    private static final double STRANGE_VAL1 = 6.0;
    private static final double STRANGE_VAL2 = 13.0;

    public LegacyCalculator(double megaDelta, double megaMultiplier) {
        this.megaDelta = megaDelta;
        this.megaMultiplier = megaMultiplier;
    }

    public double calculatePricePart1() {
        return STRANGE_VAL1 - megaDelta;
    }

    public double calculatePricePart2() {
        return STRANGE_VAL2 * megaMultiplier + 1 - megaDelta;
    }

    public double getOurTheMostAndMinimalValue() {
        return megaDelta * megaMultiplier;
    }

    public String getSomeDocumentRepresentation() {
        return "The man " + (STRANGE_VAL1 - megaDelta) + " who sold the " + (megaMultiplier * STRANGE_VAL2) + " world";
    }
}
