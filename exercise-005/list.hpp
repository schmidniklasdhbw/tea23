#ifndef MY_FANCY_LINKED_LIST_H__
#define MY_FANCY_LINKED_LIST_H__

/**
 * @defgroup OpaquePointer Opaque Pointer Konzept
 * @{
 *
 * @brief Wir verwenden hier das Konzept der "undurchsichtigen" oder "opaken" Zeiger.
 *
 * Ein opaker Zeiger ist ein Zeiger auf eine Struktur, deren genaue Struktur dem Benutzer
 * nicht bekannt ist. Das hat mehrere Vorteile:
 *
 * 1. **Geheimnistuerei (Encapsulation)**: Der Benutzer sieht nicht, wie die Liste intern
 *    aufgebaut ist. Das macht es einfacher, die interne Implementierung später zu ändern.
 *
 * 2. **Sicherheit**: Der Benutzer kann die inneren Daten nicht direkt ändern oder beschädigen.
 *    Er muss die dafür vorgesehenen Funktionen verwenden.
 *
 * 3. **Wartbarkeit**: Wenn wir die interne Struktur ändern (z.B. eine andere Datenstruktur
 *    verwenden), müssen wir nur die .cpp-Datei ändern, nicht die Funktionen des Benutzers.
 *
 * Beispiel:
 * - Der Benutzer kann schreiben: List_t* myList = NewList();
 * - Aber er kann NICHT schreiben: myList->head->data = 5;
 *   (Das wäre nicht möglich, da die Struktur nicht bekannt ist)
 * - Stattdessen muss er: NewListNode(5); verwenden
 *
 * @}
 */
typedef struct ListNode ListNode_t;
typedef struct List List_t;

/**
 * @brief Erstellt einen neuen Knoten mit den übergebenen Daten
 * @param data Die Zahl, die im Knoten gespeichert werden soll
 * @return Zeiger auf den neu erstellten Knoten
 */
ListNode_t* NewListNode(unsigned int data);

/**
 * @brief Löscht einen Knoten aus dem Speicher
 * @param elem Der Knoten, der gelöscht werden soll
 */
void FreeListNode(ListNode_t* elem);

/**
 * @brief Erstellt eine neue leere verlinkte Liste
 * @return Zeiger auf die neu erstellte Liste
 */
List_t* NewList(void);

/**
 * @brief Löscht die gesamte Liste mit allen Knoten
 * @param list Die zu löschende Liste
 */
void FreeList(List_t* list);

/**
 * @brief Fügt einen Knoten am Anfang in die Liste ein
 * @param list Die Liste, in die eingefügt werden soll
 * @param elem Der Knoten, der eingefügt werden soll
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int InsertIntoLinkedList(List_t* list, ListNode_t* elem);

/**
 * @brief Fügt einen Knoten direkt nach einem bestimmten Knoten in die Liste ein
 * @param list Die Liste, in die eingefügt werden soll
 * @param node Der Knoten, nach dem eingefügt werden soll
 * @param elem Der neue Knoten, der eingefügt werden soll
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int InsertIntoLinkedListAfterNode(List_t* list, ListNode_t* node, ListNode_t* elem);

/**
 * @brief Entfernt einen Knoten aus der Liste
 * @param list Die Liste, aus der der Knoten entfernt werden soll
 * @param elem Der zu entfernende Knoten
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int RemoveFromList(List_t* list, ListNode_t* elem);

/**
 * @brief Gibt den nächsten Knoten nach einem bestimmten Knoten zurück
 * @param list Die Liste
 * @param elem Der aktuelle Knoten
 * @return Zeiger auf den nächsten Knoten, oder NULL wenn kein nächster Knoten existiert
 */
ListNode_t* GetNext(const List_t* list, ListNode_t* elem);

/**
 * @brief Liest die Zahl aus einem Knoten
 * @param node Der Knoten, aus dem die Daten gelesen werden sollen
 * @param data Zeiger auf eine Variable, in der die Zahl gespeichert wird
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int GetData(ListNode_t* node, unsigned int* data);

#endif