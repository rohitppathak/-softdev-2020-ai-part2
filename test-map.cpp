#include "map.h"
#include <iostream>
#include <stdlib.h>
#include "object.h"
#include "string.h"
#include "array.h"

void FAIL() { exit(1); }
void t_true(bool p) { if (!p) FAIL(); }
void t_false(bool p) { if (p) FAIL(); }

void testBasicSOMap () {
    SOMap* map = new SOMap();
    t_true(map->isEmpty());
    t_true(map->size() == 0);
    Object* a = new Object();
    Object* b = new Object();
    String* aKey = new String("a");
    String* bKey = new String("b");
    t_false(map->containsKey(aKey));
    t_false(map->containsKey(bKey));
    t_false(map->containsValue(a));
    t_false(map->containsValue(b));
    map->put(aKey, a);
    map->put(bKey, b);
    t_true(map->containsKey(aKey));
    t_true(map->containsKey(bKey));
    t_true(map->containsValue(a));
    t_true(map->containsValue(b));
    t_true(map->size() == 2);
    t_false(map->isEmpty());
    t_true(a->equals(map->get(aKey)));
    t_true(b->equals(map->get(bKey)));
    t_true(a->equals(map->remove(aKey)));
    t_true(map->size() == 1);
    t_true(a->equals(map->remove(bKey)));
    t_true(map->size() == 0);
    t_true(map->isEmpty());
    map->put(aKey, a);
    map->put(bKey, b);
    t_true(map->size() == 2);
    Object* newA = new Object();
    t_true(map->get(aKey)->equals(a));
    map->put(aKey, newA);
    t_true(map->size() == 2);
    t_true(map->get(aKey)->equals(newA));
    SOMap* map2 = new SOMap();
    Object* c = new Object();
    Object* d = new Object();
    String* cKey = new String("c");
    String* dKey = new String("d");
    map2.put(cKey, c);
    map2.put(dKey, d);
    t_false(map->equals(map2));
    map->putAll(map2);
    t_true(map->size() == 4);
    map2->putAll(map);
    t_true(map->equals(map2));
    Array* keys = map->keySet();
    t_true(keys->size() == 4);
    t_true(keys->index_of(aKey) < keys->size());
    t_true(keys->index_of(bKey) < keys->size());
    t_true(keys->index_of(cKey) < keys->size());
    t_true(keys->index_of(dKey) < keys->size());
    Array* values = map->values();
    t_true(values->size() == 4);
    t_true(values->index_of(a) < values->size());
    t_true(values->index_of(b) < values->size());
    t_true(values->index_of(c) < values->size());
    t_true(values->index_of(d) < values->size());
    map->clear();
    t_true(map->isEmpty());
}

void testBasicSSMap () {
    SSMap* map = new SSMap();
    t_true(map->isEmpty());
    t_true(map->size() == 0);
    String* a = new String("aValue");
    String* b = new String("bValue");
    String* aKey = new String("a");
    String* bKey = new String("b");
    t_false(map->containsKey(aKey));
    t_false(map->containsKey(bKey));
    t_false(map->containsValue(a));
    t_false(map->containsValue(b));
    map->put(aKey, a);
    map->put(bKey, b);
    t_true(map->containsKey(aKey));
    t_true(map->containsKey(bKey));
    t_true(map->containsValue(a));
    t_true(map->containsValue(b));
    t_true(map->size() == 2);
    t_false(map->isEmpty());
    t_true(a->equals(map->get(aKey)));
    t_true(b->equals(map->get(bKey)));
    t_true(a->equals(map->remove(aKey)));
    t_true(map->size == 1);
    t_true(a->equals(map->remove(bKey)));
    t_true(map->size == 0);
    t_true(map->isEmpty());
    map->put(aKey, a);
    map->put(bKey, b);
    t_true(map->size == 2);
    String* newA = new String("newAValue");
    t_true(map->get(aKey)->equals(a));
    map->put(aKey, newA);
    t_true(map->size == 2);
    t_true(map->get(aKey)->equals(newA));
    SSMap* map2 = new SSMap();
    String* c = new String("cValue");
    String* d = new String("dValue");
    String* cKey = new String("c");
    String* dKey = new String("d");
    map2.put(cKey, c);
    map2.put(dKey, d);
    t_false(map->equals(map2));
    map->putAll(map2);
    t_true(map->size() == 4);
    map2->putAll(map);
    t_true(map->equals(map2));
    Array* keys = map->keySet();
    t_true(keys->size() == 4);
    t_true(keys->index_of(aKey) < keys->size());
    t_true(keys->index_of(bKey) < keys->size());
    t_true(keys->index_of(cKey) < keys->size());
    t_true(keys->index_of(dKey) < keys->size());
    Array* values = map->values();
    t_true(values->size() == 4);
    t_true(values->index_of(a) < values->size());
    t_true(values->index_of(b) < values->size());
    t_true(values->index_of(c) < values->size());
    t_true(values->index_of(d) < values->size());
    map->clear();
    t_true(map->isEmpty());
}

void testErrors() {
    
}

int main() {
    testBasicSOMap();
    testBasicSSMap();
}
