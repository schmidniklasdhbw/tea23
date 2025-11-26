# Übungsaufgabe Nr. 5 – Einfach verkettete Liste & Mini-Vector (Dynamisches Array)

## Überblick

In dieser Übung implementieren Sie zwei grundlegende Datenstrukturen:

1. **Einfach verkettete Liste**
2. **Mini-Vector** (ein dynamisches Array ähnlich zu `std::vector`)

Beide Datenstrukturen erhalten eine **ähnliche API**, sodass Sie dieselben Operationen auf unterschiedliche Weise umsetzen.
Ziel ist es, den Unterschied zwischen **pointerbasierten** und **indexbasierten** Datenstrukturen zu verstehen.

Die fmt-Bibliothek wird für alle Konsolenausgaben verwendet.

---

## 1. Vorbereitung: Git-Branch anlegen

```sh
git fetch --all
git switch -c solution-005 upstream/exercise-005
git push --set-upstream origin solution-005
```

Alle Änderungen erfolgen im Verzeichnis:

```sh
exercise-005/
```

Projektstruktur:

```sh
exercise-005/
  CMakeLists.txt
  main.cpp
  list.cpp
  list.hpp
  vector.cpp
  vector.hpp
  ANSWER.md
```

---

## 2. Vorgabe: Datenstrukturen für die Liste

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;

typedef struct List {
    struct ListNode* pHead;
    struct ListNode* pTail;
    unsigned int size;
} List_t;
```

### Hinweis: Include-Guard in list.hpp

```cpp
#ifndef LIST_HPP
#define LIST_HPP

// Inhalt hier…

#endif // LIST_HPP
```

---

## 3. Aufgaben – Verkettete Liste

Sie implementieren folgende API:

```cpp
void list_init(List_t* list);
void list_clear(List_t* list);

ListNode_t* list_create_node(unsigned int value);
void list_delete_node(ListNode_t* node);

int list_push_back(List_t* list, unsigned int value);
int list_insert_after(List_t* list, ListNode_t* pos, unsigned int value);

int list_pop_front(List_t* list);
int list_erase_after(List_t* list, ListNode_t* pos);

void list_print(const List_t* list);
```

### Anforderungen

- Verwendung von **malloc/free** *oder* **new/delete** (aber konsistent bleiben!)
- Ausgabe ausschließlich über **fmt::print**
- Sonderfall *leere Liste* beachten
- `list_init()` MUSS benutzt werden → keine Direktmanipulation der Struktur im main()

---

## 4. Aufgaben – Mini-Vector (dynamisches Array)

Sie implementieren eine API, die formal der Liste ähnelt:

```cpp
typedef struct Vector {
    unsigned int* data;
    size_t size;
    size_t capacity;
} Vector_t;

void vector_init(Vector_t* vec);
void vector_clear(Vector_t* vec);

int vector_push_back(Vector_t* vec, unsigned int value);
int vector_get(const Vector_t* vec, size_t index, unsigned int* out);
void vector_print(const Vector_t* vec);
```

### Anforderungen

- Startkapazität z. B. `capacity = 4`
- Beim Einfügen:
  - Wenn `size >= capacity` → **Kapazität verdoppeln**
  - Array mit `malloc` oder `new[]` vergrößern und bestehende Werte kopieren
- Speicher wird am Ende mit `vector_clear()` freigegeben

### Beispiel zum Vergrößern des Arrays

```cpp
if (vec->size >= vec->capacity) {
    vec->capacity *= 2;
    unsigned int* newData = (unsigned int*)malloc(vec->capacity * sizeof(unsigned int));
    memcpy(newData, vec->data, vec->size * sizeof(unsigned int));
    free(vec->data);
    vec->data = newData;
}
```

---

## 5. Testprogramm in main.cpp

Ihr Testprogramm soll:

1. Eine Liste und einen Vector anlegen
2. Beide mit `*_init()` initialisieren
3. Werte 10, 20, 30, 40, 50 einfügen
4. Bei der Liste:
   - Element nach dem zweiten einfügen
   - Kopf löschen
5. Beim Vector:
   - Index 2 auslesen und ausgeben
6. Nach jeder Operation `list_print()` bzw. `vector_print()` aufrufen

---

## 6. Vergleich in ANSWER.md

Beantworten Sie:

- Vorteile der verketteten Liste
- Nachteile der Liste
- Vorteile des Mini-Vectors
- Nachteile des Mini-Vectors

### 6.1 Fazit

Wann nimmt man welche Struktur?

---

## 7. Optional

- Implementieren Sie `vector_insert_at()` analog zu `list_insert_after`
- Messen Sie mit `std::chrono` grob die Performance beider Strukturen beim Einfügen von 100.000 Elementen

---

## 8. Abgabe

Ihre Abgabe enthält:

- Branch `solution-005`
- Dateien:
  - `main.cpp`
  - `list.cpp`, `list.hpp`
  - `vector.cpp`, `vector.hpp`
  - `ANSWER.md`

---

## Anhang A – Wiederholung: Strukturen in C/C++

Dieser Anhang ergänzt die Übungsaufgabe Nr. 5 und bietet eine kompakte Wiederholung zu **Strukturen**, **Zeigern**, **Heap/Stack**, sowie Zugriffssyntax (`.` vs. `->`). Er ist speziell für Studierende gedacht, die noch Schwierigkeiten mit C/C++-Grundlagen haben.

---

### 1. Was ist eine Struktur?

Eine Struktur fasst mehrere Werte zu einem neuen Datentyp zusammen.

```cpp
struct Point {
    int x;
    int y;
};
```

Verwendung:

```cpp
Point p;
p.x = 3;
p.y = 7;
```

---

### 2. typedef für Strukturen

Durch `typedef` kann die Verwendung vereinfacht werden:

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;
```

Ohne typedef müsste man schreiben:

```cpp
struct ListNode node;
```

Mit typedef genügt:

```cpp
ListNode_t node;
```

---

### 3. Stack vs. Heap

#### Stack-Allocation (automatisch)

```cpp
ListNode_t n;
n.data = 42;
```

- Lebensdauer begrenzt auf Funktionsblock
- sehr schnell
- feste Größe beim Kompilieren

#### Heap-Allocation (dynamisch)

```cpp
ListNode_t* n = (ListNode_t*)malloc(sizeof(ListNode_t));
n->data = 42;
```

- lebt weiter, auch nach Funktionsende
- muss **manuell** freigegeben werden
- flexibler Speicher

Dies ist wichtig für verkettete Listen:
**Die Knoten müssen auf dem Heap leben**, weil sie über Funktionsgrenzen hinweg bestehen.

---

### 4. Zugriff auf Strukturfelder

#### Direkt (Stack)

```cpp
n.data = 10;
```

#### Über Zeiger (Heap)

```cpp
n->data = 10;  // NICHT n.data
```

**Merksatz:**
*`.` für Werte – `->` für Zeiger.*

---

### 5. Selbstreferenzierende Strukturen

Listen nutzen Zeiger auf dieselbe Struktur:

```cpp
typedef struct ListNode {
    unsigned int data;
    struct ListNode* pNext;
} ListNode_t;
```

Ergebnis:

```
[10] → [20] → [30] → NULL
```

Ohne Pointer wären Listen nicht möglich.

---

### 6. Warum eine API verwenden? (`list_init(&list)`)

Man könnte direkt Felder setzen:

```cpp
List_t list;
list.pHead = nullptr;
list.pTail = nullptr;
list.size = 0;
```

Aber das ist fehleranfällig.

Eine API abstrahiert:

```cpp
list_init(&list);
```

**Vorteile:**

- nur *eine zentrale Stelle* für Initialisierung
- Fehlervermeidung (pTail vergessen?)
- leicht erweiterbar
- professionelle Softwarestruktur
- klarer Einstiegspunkt wie Konstruktoren in C++

---

### 7. Beispiel: Liste im Speicher

```cpp
List_t list;
list_init(&list);
list_push_back(&list, 10);
list_push_back(&list, 20);
```

Visualisierung:

```
List_t:
  pHead → Knoten(10) → Knoten(20) → NULL
  pTail → Knoten(20)
  size  = 2
```

Heap:

```
+-----------+      +-----------+
| data = 10 | ---> | data = 20 |
| pNext = --|      | pNext=NULL|
+-----------+      +-----------+
```

---

### 8. Häufige Fehler

| Fehler                         | Ursache                          | Lösung                         |
|-------------------------------|----------------------------------|--------------------------------|
| `node.data` vs. `node->data`  | Zeiger verwechselt               | `->` für Zeiger nutzen         |
| falsche sizeof-Angabe         | Anfängerfehler bei malloc        | `sizeof(ListNode_t)` verwenden |
| leere Liste nicht berücksichtigt | Vergessen in Funktionen         | frühzeitig prüfen (`nullptr`)  |
| Knoten auf Stack erzeugt      | Lebensdauer falsch verstanden    | immer Heap (`malloc/new`)      |
| fehlendes free/delete         | Speicherleck                     | in clear/Löschfunktionen einbauen |

---

### 9. Wichtigste Begriffe

- `struct`
- `typedef`
- Zeiger und `->`
- `malloc` / `free`
- Stack vs. Heap
- Include-Guard
- selbstreferenzierende Strukturen

---

Dieser Anhang soll sicherstellen, dass Sie die Übung auch dann erfolgreich bearbeiten können, wenn Ihre C/C++-Grundlagen noch nicht vollständig gefestigt sind.
