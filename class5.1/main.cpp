#include <gtest/gtest.h>
#include "MegaDataPool.h"

// Unit tests

TEST(MegaDataPoolTest, AcquireReleaseTest) {
    const int POOL_SIZE = 3;
    MegaDataPool pool(POOL_SIZE);

    // Acquire objects from the pool
    std::vector<MegaData*> objects;
    for (int i = 0; i < POOL_SIZE; ++i) {
        MegaData* obj = pool.acquire();
        ASSERT_TRUE(obj != nullptr);
        obj->reset(); // Reset object state
        objects.push_back(obj);
    }

    // Now all objects should be in use
    ASSERT_EQ(pool.usedSize(), POOL_SIZE);

    // Try to acquire more objects (should return nullptr as pool is empty)
    MegaData* extraObj = pool.acquire();
    ASSERT_TRUE(extraObj == nullptr);

    // Release all objects back to the pool
    for (auto obj : objects) {
        pool.release(obj);
    }
    objects.clear();

    // Check the used size after releasing objects
    ASSERT_EQ(pool.usedSize(), 0);

    // Acquire released objects again
    MegaData* newObj1 = pool.acquire();
    ASSERT_TRUE(newObj1 != nullptr);
    newObj1->reset(); // Reset object state
    MegaData* newObj2 = pool.acquire();
    ASSERT_TRUE(newObj2 != nullptr);
    newObj2->reset(); // Reset object state

    // Release all objects back to the pool
    pool.release(newObj1);
    pool.release(newObj2);

    // Check the used size after releasing all objects
    ASSERT_EQ(pool.usedSize(), 0);
}


TEST(MegaDataPoolTest, ResetTest) {
    const int POOL_SIZE = 2;
    MegaDataPool pool(POOL_SIZE);

    // Acquire objects from the pool
    MegaData* obj1 = pool.acquire();
    MegaData* obj2 = pool.acquire();

    // Modify objects
    obj1->reset();
    obj2->reset();

    // Release objects back to the pool
    pool.release(obj1);
    pool.release(obj2);

    // Acquire objects again
    MegaData* newObj1 = pool.acquire();
    MegaData* newObj2 = pool.acquire();

    // Check if objects are reset
    ASSERT_TRUE(newObj1 != nullptr);
    ASSERT_TRUE(newObj2 != nullptr);

    // Check if arrays are reset
    for (int i = 0; i < 1024; ++i) {
        ASSERT_FLOAT_EQ(newObj1->getSmallArray()[i], 42.0f);
    }
    for (int i = 0; i < 1024 * 1024; ++i) {
        ASSERT_DOUBLE_EQ(newObj2->getBigArray()[i], 42.0);
    }

    // Release objects back to the pool
    pool.release(newObj1);
    pool.release(newObj2);

    // Check the used size after releasing all objects
    ASSERT_EQ(pool.usedSize(), 0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
