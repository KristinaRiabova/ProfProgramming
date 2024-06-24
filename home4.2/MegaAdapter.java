public class MegaAdapter extends BaseMegaCalculator {
    private LegacyCalculator legacyCalculator;

    public MegaAdapter(LegacyCalculator legacyCalculator) {
        this.legacyCalculator = legacyCalculator;
    }

    @Override
    public double getPrice() {
        return legacyCalculator.calculatePricePart1() + legacyCalculator.calculatePricePart2();
    }

    @Override
    public double getMinimalValue() {
        return legacyCalculator.getOurTheMostAndMinimalValue();
    }

    @Override
    public String getReport() {
        return legacyCalculator.getSomeDocumentRepresentation();
    }
}
