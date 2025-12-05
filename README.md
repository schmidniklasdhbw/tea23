# Mikrocomputertechnik 3

Begleitprojekt für Mikrocomputertechnik 3 im Kurs tea23 an der DHBW Ravensburg Campus Friedrichshafen

**WICHTIG** Bitte verwenden sie zur Entwicklung die vorgefertigten Umgebungen.

## Synchronisation des eignen Forks

Es wird davon ausgegangen, dass Sie einen Fork angelegt haben und von diesen geklont haben. Damit entspricht Ihr Fork der Bezeichnung ``origin``. Siehe hierzu auch die [Hinweise in der ersten Übungsaufgabe](exercise-001#upstream-hinzuf%C3%BCgen).

Um die aktuellen Änderungen in die lokale Kopie des ``tea23`` Repository zu übertragen sollten Sie zunächst ein ``git fetch`` durchführen

```sh
git fetch upstream
```

Nun checken wir die lokale Kopie des zu synchronisierenden Branches aus, in unserem Fall der ``main`` Branch. Dieser Schritt kann entfallen falls wir bereits schon auf dem ``main`` Branch sind. Das können Sie mit ``git branch -a`` prüfen.

```sh
git checkout main
```

Der Befehl ``git pull`` aktualisiert nun den lokalen Branch.

```sh
git pull upstream main
```

Sollte es hierbei zu einem Konflikt kommen haben Sie eventuell versehentlich lokale commits auf Ihrem ``main`` Branch durchgeführt. Das sollten Sie tunlichst vermeiden.

Im Erfolgsfall müssen jetzt nur noch die Daten in Ihren Fork gepusht werden:

```sh
git push origin main
```

## Übungsaufgaben

- [Übungsaufgabe Nr. 000](exercise-000/README.md)

## Allgemeine Hinweise

Die Größen der Speichersegemente können Sie sich mit dem Programm `size` anzeigen lassen:

```sh
size -A -x ./build/bin/exercise-004 
./build/bin/exercise-004  :
section                  size      addr
.interp                  0x1c     0x318
.note.gnu.property       0x20     0x338
.note.gnu.build-id       0x24     0x358
.note.ABI-tag            0x20     0x37c
.gnu.hash                0x50     0x3a0
.dynsym                0x10b0     0x3f0
.dynstr                0x2363    0x14a0
.gnu.version            0x164    0x3804
.gnu.version_r          0x100    0x3968
.rela.dyn              0x1cf8    0x3a68
.rela.plt               0xd68    0x5760
.init                    0x17    0x7000
.plt                    0x900    0x7020
.plt.got                 0x18    0x7920
.text                 0x49d72    0x7940
.fini                     0x9   0x516b4
.rodata                0x1d03   0x52000
.eh_frame_hdr          0x4c5c   0x53d04
.eh_frame             0x13cec   0x58960
.gcc_except_table      0x2ee4   0x6c64c
.init_array              0x10   0x70370
.fini_array               0x8   0x70380
.data.rel.ro            0x9c0   0x70388
.dynamic                0x220   0x70d48
.got                     0x80   0x70f68
.got.plt                0x490   0x70fe8
.data                    0x50   0x71478
.bss                    0x490   0x714c8
.comment                 0x50       0x0
.debug_info           0x46575       0x0
.debug_abbrev           0xf73       0x0
.debug_line           0x27b1f       0x0
.debug_str            0x9e6b7       0x0
.debug_addr            0x5ab8       0x0
.debug_line_str         0x7f2       0x0
.debug_loclists         0xaf2       0x0
.debug_rnglists        0x308e       0x0
.debug_str_offsets     0x8490       0x0
Total                0x18ed30
```

## Hilfreiche Links

- [Markdown Cheat Sheet](https://guides.github.com/pdfs/markdown-cheatsheet-online.pdf)
- [Git Cheat Sheet](https://about.gitlab.com/images/press/git-cheat-sheet.pdf)
