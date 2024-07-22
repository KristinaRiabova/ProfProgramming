import org.junit.jupiter.api.Test;
import static org.junit.jupiter.api.Assertions.*;

public class MegaDataPoolTest {

    @Test
    public void testAcquireRelease() {
        final int POOL_SIZE = 3;
        MegaDataPool pool = new MegaDataPool(POOL_SIZE);

       
        MegaData[] objects = new MegaData[POOL_SIZE];
        for (int i = 0; i < POOL_SIZE; i++) {
            objects[i] = pool.acquire();
            assertNotNull(objects[i]);
            objects[i].reset(); 
        }

       
        assertEquals(pool.usedSize(), POOL_SIZE);

       
        MegaData extraObj = pool.acquire();
        assertNull(extraObj);

       
        for (MegaData obj : objects) {
            pool.release(obj);
        }

        
        assertEquals(pool.usedSize(), 0);

        
        MegaData newObj1 = pool.acquire();
        assertNotNull(newObj1);
        newObj1.reset(); 
        MegaData newObj2 = pool.acquire();
        assertNotNull(newObj2);
        newObj2.reset(); 

       
        pool.release(newObj1);
        pool.release(newObj2);

       
        assertEquals(pool.usedSize(), 0);
    }

    @Test
    public void testReset() {
        final int POOL_SIZE = 2;
        MegaDataPool pool = new MegaDataPool(POOL_SIZE);

        
        MegaData obj1 = pool.acquire();
        MegaData obj2 = pool.acquire();

        
        obj1.reset();
        obj2.reset();

       
        pool.release(obj1);
        pool.release(obj2);

        
        MegaData newObj1 = pool.acquire();
        MegaData newObj2 = pool.acquire();

        
        assertNotNull(newObj1);
        assertNotNull(newObj2);

       
        for (float v : newObj1.getSmallArray()) {
            assertEquals(v, 42.0f);
        }
        for (double v : newObj2.getBigArray()) {
            assertEquals(v, 42.0);
        }

        
        pool.release(newObj1);
        pool.release(newObj2);

        
        assertEquals(pool.usedSize(), 0);
    }
}
