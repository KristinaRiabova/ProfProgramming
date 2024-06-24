import java.util.ArrayList;
import java.util.List;

public class MegaDataPool {
    private List<MegaData> pool;
    private List<Boolean> available;
    private int poolSize;
    private int usedCount;

    public MegaDataPool(int size) {
        poolSize = size;
        usedCount = 0;
        pool = new ArrayList<>(size);
        available = new ArrayList<>(size);
        for (int i = 0; i < size; i++) {
            pool.add(new MegaData());
            available.add(true);
        }
    }

    public synchronized MegaData acquire() {
        for (int i = 0; i < poolSize; i++) {
            if (available.get(i)) {
                available.set(i, false);
                usedCount++;
                return pool.get(i);
            }
        }
        return null;
    }

    public synchronized void release(MegaData megadata) {
        int index = pool.indexOf(megadata);
        if (index != -1 && !available.get(index)) {
            available.set(index, true);
            usedCount--;
            megadata.reset();
        }
    }

    public int size() {
        return poolSize;
    }

    public int usedSize() {
        return usedCount;
    }
}
