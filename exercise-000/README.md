# Übungsaufgabe: Zeiger in C++ mit `fmt`

## Notwendige git Kommandos

```sh
git status
git branch -a
git switch main
# create a new local branch based on the origin main
git switch -c solution-000 origin/main
# perform changes
git add exercise-000
git commit -m "feat: add exercise number two"
# push the changes to the cloud
git push -u origin solution-000
....
```

## Programm kompilieren und ausführen

Das Projekt verwendet CMake als Build-System. So kompilieren und starten Sie das Programm:

```sh
# Projekt kompilieren (NUR aus dem Hauptverzeichnis) alternativ über die GUI 
cmake --build build

# Programm ausführen
./build/bin/exercise-000
```

### Warum `./` vor dem Programmnamen?

In Linux/Unix-Systemen ist das aktuelle Verzeichnis (`.`) aus Sicherheitsgründen **nicht** automatisch im `PATH`. Deshalb müssen Sie explizit angeben, dass sich das Programm im aktuellen Pfad befindet:

- **`./`** bedeutet "aktuelles Verzeichnis"
- **`build/bin/exercise-000`** ist der relative Pfad zur ausführbaren Datei
- **Ohne `./`** würde Linux nur in den `PATH`-Verzeichnissen suchen (z.B. `/usr/bin`, `/bin`)

```sh
# ✅ Richtig - expliziter Pfad
./build/bin/exercise-000

# ❌ Falsch - Programm wird nicht gefunden
build/bin/exercise-000  # könnte funktionieren, aber ./ist expliziter

# ❌ Falsch - nur Programmname ohne Pfad
exercise-000  # "command not found"
```

> **Tipp:** Sie können auch den absoluten Pfad verwenden: `/workspaces/tea23/build/bin/exercise-000`

## Die `main`-Funktion: `argc` und `argv`

In Desktop-/Server-Programmen hat die `main`-Funktion oft Parameter für Kommandozeilenargumente:

```cpp
int main(int argc, char **argv)
```

### Was bedeuten `argc` und `argv`?

- **`argc`** (argument count): Anzahl der Kommandozeilenargumente (inklusive Programmname)
- **`argv`** (argument vector): Array von Zeigern auf die Argument-Strings

### Praktisches Beispiel

```sh
# Programm mit Argumenten aufrufen
./build/bin/exercise-000 --verbose debug.txt 42
```

In diesem Fall wäre:

```cpp
argc = 4                    // Anzahl der Argumente
argv[0] = "./build/bin/exercise-000"  // Programmname (immer das erste Argument)
argv[1] = "--verbose"       // Erstes echtes Argument
argv[2] = "debug.txt"       // Zweites Argument  
argv[3] = "42"              // Drittes Argument
argv[4] = nullptr           // Array-Ende-Markierung
```

### Mikrocontroller vs. Desktop

**Desktop/Server (`int main(int argc, char **argv)`):**

- Kommandozeilenargumente verfügbar
- Betriebssystem ruft `main` auf
- Program kann beendet werden (`return 0;`)

**Mikrocontroller (`int main(void)` oder Endlosschleife):**

```cpp
int main(void) {
    // Initialisierung
    while(1) {
        // Hauptprogramm läuft endlos
    }
    // return wird nie erreicht
}
```

- Keine Kommandozeile vorhanden
- Programm läuft endlos (kein Betriebssystem zum Zurückkehren)
- Oft auch `setup()` und `loop()` Funktionen (Arduino-Stil)

**Lernziel:** Wiederholung und Festigung des Verständnisses von Zeigern in C/C++ sowie Einführung in die Verwendung der [`fmt`](https://fmt.dev/)-Bibliothek zur Ausgabe.

---

## Auffrischung: Include-Dateien und Header

Bevor wir mit den Zeigern beginnen, eine kurze Auffrischung zu einem wichtigen Grundkonzept:

### Was sind Include-Dateien?

Include-Dateien (Header) enthalten **Deklarationen** von Funktionen, Klassen und Konstanten, die wir in unserem Code verwenden möchten. Sie sagen dem Compiler, was verfügbar ist, aber nicht wie es implementiert ist.

```cpp
#include <iostream>     // Für std::cout, std::cin
#include <cstdlib>      // Für malloc, free
#include <fmt/format.h> // Für fmt::print, fmt::println
```

### Unterschied zwischen `<>` und `""`

#### Systemheader mit `<>`

```cpp
#include <iostream>     // Standard-Bibliothek
#include <vector>       // STL-Container
#include <fmt/format.h> // Externe Bibliothek (installiert)
```

- **Suchpfad**: Compiler sucht in System-/Bibliotheksverzeichnissen
- **Verwendung**: Standard-C++-Bibliothek, installierte externe Bibliotheken

#### Eigene Header mit `""`

```cpp
#include "config.h"     // Eigene Header-Datei
#include "myclass.h"    // Eigene Klassen
#include "../utils.h"   // Relative Pfade möglich
```

- **Suchpfad**: Compiler sucht zuerst im aktuellen Verzeichnis, dann in System-Verzeichnissen
- **Verwendung**: Selbst geschriebene Header-Dateien, projektspezifische Dateien

> **Faustregel**: `<>` für Standard- und externe Bibliotheken, `""` für eigene Dateien!

---

## Die `fmt`-Bibliothek: Eine moderne Alternative zu `printf`

Wenn Sie aus der C-Programmierung kommen, kennen Sie vermutlich `printf()` für die Ausgabe:

```c
printf("Wert: %d, Adresse: %p\n", x, &x);
```

Die `fmt`-Bibliothek ist eine moderne C++-Alternative, die **einfacher und sicherer** ist:

> **Python-Analogie:** Wenn Sie Python kennen, ist `fmt::print()` sehr ähnlich zu Pythons `print()` mit f-strings!

### Vorteile von `fmt::print()`

- **Typsicherheit**: Keine Formatierungsfehler durch falsche Platzhalter
- **Einfachere Syntax**: `{}` statt `%d`, `%p`, `%s` etc.
- **Automatische Typenerkennung**: Kein manuelles Angeben des Datentyps nötig
- **Bessere Lesbarkeit**: Modernere, intuitivere Syntax

### Vergleich C vs. fmt

```c
// C-Stil mit printf
printf("Name: %s, Alter: %d, Gehalt: %.2f\n", name, age, salary);
```

```cpp
// Modern mit fmt
fmt::print("Name: {}, Alter: {}, Gehalt: {:.2f}\n", name, age, salary);
```

```python
# Python f-string (sehr ähnlich!)
print(f"Name: {name}, Alter: {age}, Gehalt: {salary:.2f}")
```

### Praktisches Beispiel für diese Übung

```c
// C-Stil
int x = 42;
printf("Wert: %d, Adresse: %p\n", x, &x);
```

```cpp
// Mit fmt (wie Python!)
int x = 42;
fmt::print("Wert: {}, Adresse: {}\n", x, fmt::ptr(&x));
```

```python
# Python (konzeptionell ähnlich)
x = 42
print(f"Wert: {x}, Adresse: {id(x)}")  # id() zeigt Speicheradresse
```

### Wichtige `fmt`-Funktionen für diese Übung

- `fmt::print("Text")` - Einfache Textausgabe
- `fmt::print("Wert: {}\n", variable)` - Variable ausgeben  
- `fmt::println("Text")` - Textausgabe **mit automatischem Zeilenendezeichen**
- `fmt::println("Wert: {}", variable)` - Variable ausgeben mit automatischem `\n`
- `fmt::ptr(zeiger)` - Zeiger/Adresse formatiert ausgeben

> **Tipp:** `fmt::print` fügt **kein automatisches Zeilenendezeichen** hinzu - verwenden Sie `\n` am Ende!  
> **Noch besser:** Nutzen Sie `fmt::println` - dann brauchen Sie kein manuelles `\n`!

---

## Teil 0: Kommandozeilenparameter (`argc` und `argv`)

Bevor wir mit den eigentlichen Zeigern arbeiten, schauen wir uns die Parameter der `main`-Funktion an:

1. Geben Sie die Anzahl der Kommandozeilenargumente (`argc`) aus.
2. Geben Sie alle Kommandozeilenargumente (`argv[0]` bis `argv[argc-1]`) mit deren Adressen aus.
3. Testen Sie Ihr Programm mit verschiedenen Argumenten:

   ```sh
   # Ohne Argumente
   ./build/bin/exercise-000
   
   # Mit Argumenten
   ./build/bin/exercise-000 hallo welt 123
   ./build/bin/exercise-000 --verbose debug.txt
   ```

### Beispielausgabe:

```
Anzahl Argumente (argc): 4
argv[0] = "./build/bin/exercise-000" (Adresse: 0x7ffd12345678)
argv[1] = "hallo" (Adresse: 0x7ffd12345689)
argv[2] = "welt" (Adresse: 0x7ffd1234568f)
argv[3] = "123" (Adresse: 0x7ffd12345694)
```

> **Wichtig:** `argc` gibt die Gesamtanzahl an, aber Array-Indizes gehen von `0` bis `argc-1`!

---

## Teil 1: Zeiger-Grundlagen

1. Legen Sie eine `int`-Variable `x` mit dem Wert `10` an.
2. Deklarieren Sie einen Zeiger `p`, der auf `x` zeigt.
3. Geben Sie mit `fmt::print` den Wert von `x` und die Adresse von `x` aus.  
   → Tipp: Mit `fmt::ptr(&x)` können Sie eine Adresse im Pointer-Format ausgeben.
4. Geben Sie den Wert aus, auf den der Zeiger `p` zeigt, sowie die Adresse, die in `p` gespeichert ist.
5. Ändern Sie den Wert von `x` über den Zeiger `p` auf `42`.
6. Geben Sie erneut den Wert von `x` und den Wert aus, auf den `p` zeigt.

---

## Teil 2: Dynamische Speicherverwaltung

1. Deklarieren Sie einen Zeiger auf `double`.
2. Reservieren Sie mit `new` Speicher für genau einen `double`-Wert und initialisieren Sie ihn mit `3.1415`.
3. Geben Sie Wert und Adresse mit `fmt::print` aus.
4. Geben Sie den Speicher anschließend wieder mit `delete` frei.

> **Merke:** Jeder mit `new` reservierte Speicher muss mit `delete` wieder freigegeben werden, sonst entsteht ein **Memory Leak**.

### C vs. C++: Unterschiedliche Speicherverwaltung

Wenn Sie aus der C-Programmierung kommen, kennen Sie `malloc()` und `free()`. In C++ gibt es modernere Alternativen:

#### C-Stil (funktioniert auch in C++)

```c
#include <stdlib.h>
double* d = (double*)malloc(sizeof(double));  // Speicher reservieren
*d = 3.1415;                                  // Wert manuell zuweisen
printf("Wert: %.5f\n", *d);
free(d);                                      // Speicher freigeben
```

#### C++-Stil (empfohlen)

```cpp
double* d = new double(3.1415);   // Speicher reservieren UND initialisieren
fmt::println("Wert: {}", *d);    // Zugriff über Dereferenzierung
delete d;                         // Speicher freigeben
```

#### Hauptunterschiede:

- **`malloc`**: Nur Speicher reservieren, keine Initialisierung, Cast erforderlich
- **`new`**: Speicher reservieren UND initialisieren in einem Schritt
- **`free`**: Einfache Speicherfreigabe
- **`delete`**: Speicherfreigabe UND Destruktor-Aufruf (bei Objekten)

> **Wichtig:** Niemals `malloc` mit `delete` oder `new` mit `free` mischen!

### Beispiel (Ausschnitt)

```cpp
double* d = new double(3.1415);   // Speicher im Heap reservieren
fmt::println("Wert: {}", *d);    // Zugriff über Dereferenzierung  
fmt::println("Adresse: {}", fmt::ptr(d));

delete d;                         // Speicher wieder freigeben
```

---

## Teil 3: Funktionen mit Zeigern

Definieren Sie zwei Funktionen:

1. `void changeValueByParameter(int value)`  
   - Nimmt eine `int`-Variable als **Parameter** entgegen.  
   - Ändert den Wert innerhalb der Funktion (z. B. `value = 99;`).  
   - Geben Sie innerhalb der Funktion den neuen Wert aus.  
   - Beobachten Sie, ob sich die ursprüngliche Variable im Hauptprogramm verändert.

2. `void changeValueByPointer(int* ptr)`  
   - Nimmt einen Zeiger auf `int` als Parameter entgegen.  
   - Ändert den Wert, auf den der Zeiger zeigt (z. B. `*ptr = 77;`).  
   - Geben Sie innerhalb der Funktion den neuen Wert aus.  
   - Beobachten Sie die Auswirkungen auf die ursprüngliche Variable.

### Aufgabe

1. Deklarieren Sie eine `int`-Variable `y = 5;`.
2. Rufen Sie `changeValueByParameter(y);` auf und geben Sie **vor und nach dem Funktionsaufruf** den Wert von `y` aus.
3. Rufen Sie `changeValueByPointer(&y);` auf und geben Sie **vor und nach dem Funktionsaufruf** den Wert von `y` aus.

> **Hinweis:** So erkennen Sie den Unterschied zwischen Übergabe einer Variable als Parameter (keine Änderung der Originalvariable) und Übergabe eines Zeigers (die Originalvariable wird verändert).
