#ifndef MY_FANCY_VECTOR_H__
#define MY_FANCY_VECTOR_H__

/**
 * @defgroup OpaquePointer Opaque Pointer Konzept
 * @{
 *
 * @brief Wir verwenden hier das Konzept der "undurchsichtigen" oder "opaken" Zeiger.
 *
 * Ein opaker Zeiger ist ein Zeiger auf eine Struktur, deren genaue Struktur dem Benutzer
 * nicht bekannt ist. Das hat mehrere Vorteile:
 *
 * 1. **Geheimnistuerei (Encapsulation)**: Der Benutzer sieht nicht, wie der Vektor intern
 *    aufgebaut ist. Das macht es einfacher, die interne Implementierung später zu ändern.
 *
 * 2. **Sicherheit**: Der Benutzer kann die inneren Daten nicht direkt ändern oder beschädigen.
 *    Er muss die dafür vorgesehenen Funktionen verwenden.
 *
 * 3. **Wartbarkeit**: Wenn wir die interne Struktur ändern (z.B. eine andere Datenstruktur
 *    verwenden), müssen wir nur die .cpp-Datei ändern, nicht die Funktionen des Benutzers.
 *
 * Beispiel:
 * - Der Benutzer kann schreiben: Vector_t* myVec = NewVector();
 * - Aber er kann NICHT schreiben: myVec->data[0] = 5;
 *   (Das wäre nicht möglich, da die Struktur nicht bekannt ist)
 * - Stattdessen muss er: vector_push_back(myVec, 5); verwenden
 *
 * @}
 */
typedef struct Vector Vector_t;

/**
 * @brief Erstellt einen neuen leeren Vektor
 * @return Zeiger auf den neu erstellten Vektor, oder NULL bei Fehler
 */
Vector_t* NewVector(void);

/**
 * @brief Initialisiert einen Vektor mit Standardwerten
 * @param vec Der zu initialisierende Vektor
 */
void vector_init(Vector_t* vec);

/**
 * @brief Leert einen Vektor und gibt seinen Speicher frei
 * @param vec Der zu leerenden Vektor
 */
/**
 * @brief Leert den Vektor (setzt Größe auf 0), behält aber den internen Puffer
 *
 * Diese Funktion setzt lediglich die logische Größe des Vektors auf 0. Der
 * bereits allozierte interne Puffer und die Kapazität bleiben erhalten, so
 * dass nachfolgende Einfügungen ohne zusätzliche Reallokationen erfolgen
 * können. Verwende `vector_free()` um den internen Puffer und die Struktur
 * vollständig freizugeben.
 *
 * @param vec Der zu leerende Vektor (darf NULL sein)
 */
void vector_clear(Vector_t* vec);

/**
 * @brief Gibt den Vektor und seinen internen Speicher vollständig frei
 *
 * Nach Aufruf von `vector_free(vec)` ist `vec` nicht mehr gültig und darf
 * nicht weiter verwendet werden.
 *
 * @param vec Der Vektor, der freigegeben werden soll
 */
void vector_free(Vector_t* vec);

/**
 * @brief Fügt einen Wert am Ende des Vektors ein
 * @param vec Der Vektor, in den eingefügt werden soll
 * @param value Der einzufügende Wert
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int vector_push_back(Vector_t* vec, unsigned int value);

/**
 * @brief Reserviert mindestens `min_capacity` Elemente im Vektor
 *
 * Diese Funktion sorgt dafür, dass der Vektor über ausreichend Kapazität
 * verfügt, um `min_capacity` Elemente zu speichern. Sie ist nützlich, um
 * mehrfache Reallokationen zu vermeiden, wenn vorhersehbar viele Elemente
 * eingefügt werden.
 *
 * @param vec Der Vektor, dessen Kapazität angepasst werden soll
 * @param min_capacity Minimale gewünschte Kapazität (Anzahl Elemente)
 * @return 0 bei Erfolg, -1 bei Fehler (z.B. Speicherallokation fehlgeschlagen)
 */
int vector_reserve(Vector_t* vec, unsigned int min_capacity);
/**
 * @brief Liest einen Wert an einem bestimmten Index aus dem Vektor
 * @param vec Der Vektor, aus dem gelesen werden soll
 * @param index Der Index des gewünschten Wertes
 * @param outValue Zeiger auf eine Variable, in der der Wert gespeichert wird
 * @return 0 bei Erfolg, -1 bei Fehler
 */
int vector_get(const Vector_t* vec, unsigned int index, unsigned int* outValue);

/**
 * @brief Gibt den Inhalt des Vektors auf der Konsole aus
 * @param vec Der Vektor, der ausgegeben werden soll
 */
void vector_print(const Vector_t* vec);

#endif // MY_FANCY_VECTOR_H__